#include "Button.hpp"

#include <iostream>

// Christopher D. Canfield
// October 2013
// Button.cpp

using cdc::Button;
using cdc::GuiEventManager;
using cdc::ObservableVector2;

using std::cout;
using std::endl;



Button::Button(GuiEventManager& manager) :
	guiManager(manager)
{
	guiManager.addDirectClickListener(*this);
	guiManager.addMouseMoveListener(*this);
	guiManager.addDirectMouseMoveListener(*this);

	position.addObserver(*this);
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

	if (currentImage != nullptr)
	{
		return currentImage->getGlobalBounds();
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


void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*currentImage, states);
}


//////// Private Methods ////////

bool Button::hoverTimerExpired() const
{
	const sf::Time max_hover_image_time = sf::milliseconds(200);

	return (currentImage != nullptr &&
			currentImage == onHoverImage.get() &&
			hoverTimer.getElapsedTime().asMilliseconds() > max_hover_image_time.asMilliseconds());
}

bool Button::clickTimerExpired() const
{
	const sf::Time max_click_image_time = sf::milliseconds(300);

	return (currentImage != nullptr &&
			currentImage == onClickImage.get() &&
			clickTimer.getElapsedTime().asMilliseconds() > max_click_image_time.asMilliseconds());
}

void Button::update(sf::Vector2f& observable)
{
	defaultImage->setPosition(observable);
	if (onClickImage != nullptr)
	{
		onClickImage->setPosition(observable);
	}
	if (onHoverImage != nullptr)
	{
		onHoverImage->setPosition(observable);
	}
}