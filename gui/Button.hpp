#pragma once

// Christopher D. Canfield
// October 2013
// Button.hpp

#include "GuiEventManager.hpp"
#include "GuiEventObserver.hpp"
#include "DirectGuiEventObserver.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>


// Abstract class for a clickable button.
class Button : 
	public DirectGuiEventObserver, public GuiEventObserver
{
public:
	Button(GuiEventManager& manager, std::unique_ptr<sf::Sprite> defaultImage);
	virtual ~Button();

	virtual void onGuiEvent(const sf::Event& e) override = 0;

protected:
	// Sets the image used when the button is clicked. If no image is set, the 
	// the default image will be used.
	void setOnClickImage(std::unique_ptr<sf::Sprite> image);
	
	// Sets the image used when the mouse hovers over the button. If no image is
	// set, the default image will be used.
	void setOnHoverImage(std::unique_ptr<sf::Sprite> image);

private:
	// Reference to the GuiEventManager.
	GuiEventManager& guiManager;

	// Pointer to the button's current image.
	sf::Sprite* currentImage;
	
	// The button's default image.
	std::unique_ptr<sf::Sprite> defaultImage;
	// The image used when the button is clicked.
	std::unique_ptr<sf::Sprite> onClickImage;
	// The image used when the cursor hovers over the button.
	std::unique_ptr<sf::Sprite> onHoverImage;
};

