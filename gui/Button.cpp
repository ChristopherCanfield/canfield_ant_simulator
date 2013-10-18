#include "Button.hpp"

// Christopher D. Canfield
// October 2013
// Button.cpp

Button::Button(GuiEventManager& manager, std::unique_ptr<sf::Sprite> defaultImage) :
	guiManager(manager), defaultImage(std::move(defaultImage))
{
	guiManager.addDirectClickListener(*this);
	guiManager.addMouseMoveListener(*this);
	guiManager.addDirectMouseMoveListener(*this);
}


Button::~Button()
{
	guiManager.removeDirectClickListener(*this);
	guiManager.removeMouseMoveListener(*this);
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