#include "Button.hpp"

#include <Poco/UUIDGenerator.h>

#include <iostream>
#include <cassert>

// Christopher D. Canfield
// October 2013
// Button.cpp

using cdc::Button;
using cdc::GuiEventManager;
using cdc::ObservableVector2;

using std::cout;
using std::endl;


Button::Button(GuiEventManager& manager) :
	guiManager(manager),
	currentImage(nullptr)
{
	Poco::UUIDGenerator& generator = Poco::UUIDGenerator::defaultGenerator();
	id = generator.createRandom();

	guiManager.addDirectClickListener(*this);
	guiManager.addMouseMoveListener(*this);
	guiManager.addDirectMouseMoveListener(*this);

	position.addObserver(*this);
}

Button::Button(Button&& other) :
	hoverTimer(other.hoverTimer),
	clickTimer(other.clickTimer),
	guiManager(other.guiManager),
	defaultImage(nullptr),
	currentImage(nullptr)
{
	if (other.defaultImage)
	{
		this->defaultImage = std::move(other.defaultImage);
		this->currentImage = this->defaultImage.get();
	}

	if (other.onClickImage)
	{
		this->onClickImage = std::move(other.onClickImage);
	}

	if (other.onHoverImage)
	{
		this->onHoverImage = std::move(other.onHoverImage);
	}
}

Button& Button::operator=(Button&& other)
{
	if (this != &other)
	{
		this->currentImage = nullptr;
	
		if (defaultImage != nullptr)
		{
			this->defaultImage = std::move(other.defaultImage);
			this->currentImage = this->defaultImage.get();
		}

		if (onClickImage != nullptr)
		{
			this->onClickImage = std::move(other.onClickImage);
		}

		if (onHoverImage != nullptr)
		{
			this->onHoverImage = std::move(other.onHoverImage);
		}
	}
	return *this;
}

Button::~Button()
{
	guiManager.removeDirectClickListener(*this);
	guiManager.removeMouseMoveListener(*this);
	guiManager.removeDirectMouseMoveListener(*this);
}

sf::FloatRect Button::getBoundingBox() const
{
	// TODO: put a debug assertion here to ensure that the current image is not null.
	assert(currentImage != nullptr);

	return currentImage->getGlobalBounds();
}

Poco::UUID Button::getObserverId() const
{
	return id;
}

void Button::setRotation(float rotation)
{
	currentImage->setRotation(rotation);
	if (defaultImage)
	{
		defaultImage->setRotation(rotation);
	}
	if (onClickImage)
	{
		onClickImage->setRotation(rotation);
	}
	if (onHoverImage)
	{
		onHoverImage->setRotation(rotation);
	}
}

float Button::getRotation() const
{
	if (currentImage)
	{
		return currentImage->getRotation();
	}
	return 0;
}

void Button::setOriginToCenter()
{
	currentImage->setOrigin(defaultImage->getGlobalBounds().width / 1.9f, defaultImage->getGlobalBounds().height / 1.9f);
	if (defaultImage)
	{
		defaultImage->setOrigin(defaultImage->getGlobalBounds().width / 1.9f, defaultImage->getGlobalBounds().height / 1.9f);
	}
	if (onClickImage)
	{
		onClickImage->setOrigin(onClickImage->getGlobalBounds().width / 1.9f, onClickImage->getGlobalBounds().height / 1.9f);
	}
	if (onHoverImage)
	{
		onHoverImage->setOrigin(onHoverImage->getGlobalBounds().width / 1.9f, onHoverImage->getGlobalBounds().height / 1.9f);
	}
}

void Button::onDirectGuiEvent(const sf::Event& e)
{
	// Did the mouse click on the button?
	if (e.type == sf::Event::MouseButtonReleased)
	{
		if (onClickImage != nullptr && onClickImage.get() != currentImage)
		{
			currentImage = onClickImage.get();
			clickTimer.restart();
			cout << "Button: onDirectGuiEvent: currentImage = onClickImage.get();" << endl;
		}
	}
	// Is the mouse hovering over the button?
	else if (e.type == sf::Event::MouseMoved && onHoverImage != nullptr && 
			currentImage != onHoverImage.get() && 
			// Don't replace the onClickImage with the onHoverImage.
			currentImage != onClickImage.get())
	{
		currentImage = onHoverImage.get();
		hoverTimer.restart();
		cout << "Button: onDirectGuiEvent: currentImage = onHoverImage.get()" << endl;
	}
}

void Button::onGuiEvent(const sf::Event& e)
{
	if (e.type == sf::Event::MouseMoved && currentImage != defaultImage.get())
	{
		if ((hoverTimerExpired() && currentImage == onHoverImage.get()) ||
			(clickTimerExpired() && currentImage == onClickImage.get()))
		{
			currentImage = defaultImage.get();
			cout << "Button: onGuiEvent: currentImage = defaultImage.get()" << endl;
		}
	}
}


//////// Protected Methods ////////

void Button::setDefaultImage(std::unique_ptr<sf::Sprite> image)
{
	defaultImage = std::move(image);
	currentImage = defaultImage.get();
}

// Sets the image used when the button is clicked. If no image is set, the 
// the default image will be used.
void Button::setOnClickImage(std::unique_ptr<sf::Sprite> image)
{
	if (currentImage == onClickImage.get())
	{
		currentImage = defaultImage.get();
	}

	onClickImage = std::move(image);
}
	
// Sets the image used when the mouse hovers over the button. If no image is
// set, the default image will be used.
void Button::setOnHoverImage(std::unique_ptr<sf::Sprite> image)
{
	if (currentImage == onHoverImage.get())
	{
		currentImage = defaultImage.get();
	}

	onHoverImage = std::move(image);
}

void Button::setCurrentImage(sf::Sprite& sprite)
{
	if (currentImage != nullptr)
	{
		sprite.setPosition(currentImage->getPosition());
		sprite.setRotation(currentImage->getRotation());
	}

	currentImage = &sprite;
}

void Button::switchToDefaultImage(sf::Vector2f position, float rotation)
{
	if (defaultImage != nullptr)
	{
		currentImage = defaultImage.get();
		currentImage->setPosition(position);
		currentImage->setRotation(rotation);
	}
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (currentImage != nullptr)
	{
		target.draw(*currentImage, states);
	}
}


//////// Private Methods ////////

bool Button::hoverTimerExpired() const
{
	const sf::Time maxHoverImageTime = sf::milliseconds(200);

	return (currentImage != nullptr &&
			currentImage == onHoverImage.get() &&
			hoverTimer.getElapsedTime().asMilliseconds() > maxHoverImageTime.asMilliseconds());
}

bool Button::clickTimerExpired() const
{
	const sf::Time maxClickImageTime = sf::milliseconds(300);

	return (currentImage != nullptr &&
			currentImage == onClickImage.get() &&
			clickTimer.getElapsedTime().asMilliseconds() > maxClickImageTime.asMilliseconds());
}

void Button::update(sf::Vector2f& observable)
{
	if (defaultImage)
	{
		defaultImage->setPosition(observable);
	}
	if (onClickImage)
	{
		onClickImage->setPosition(observable);
	}
	if (onHoverImage)
	{
		onHoverImage->setPosition(observable);
	}
}