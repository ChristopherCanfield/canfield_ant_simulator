#include "Button.hpp"

// Christopher D. Canfield
// October 2013
// Button.cpp

using cdc::Button;
using cdc::GuiEventManager;



Button::Button(GuiEventManager& manager) :
	guiManager(manager)
{
	guiManager.addDirectClickListener(*this);
	guiManager.addMouseMoveListener(*this);
	guiManager.addDirectMouseMoveListener(*this);
}


Button::~Button()
{
	guiManager.removeDirectClickListener(*this);
	guiManager.removeMouseMoveListener(*this);
	guiManager.removeDirectMouseMoveListener(*this);
}

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