#pragma once

// Christopher D. Canfield
// October 2013
// Button.hpp

#include "GuiEventManager.hpp"
#include "GuiEventObserver.hpp"
#include "DirectGuiEventObserver.hpp"
#include "GuiWidget.hpp"
#include "../util/Observable.hpp"
#include "../util/ObservableVector2.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>

#include <boost/noncopyable.hpp>

#include <vector>
#include <memory>
#include <stdexcept>


namespace cdc 
{
	// Abstract class for a clickable button.
	class Button : 
			private boost::noncopyable,
			public GuiWidget,
			public DirectGuiEventObserver, 
			public GuiEventObserver,
			public Observer<sf::Vector2f>
	{
	public:
		explicit Button(GuiEventManager& manager);
		Button(Button&& other);
		Button& Button::operator=(Button&& other);
		virtual ~Button();

		virtual sf::FloatRect getBoundingBox() const override;

		void setRotation(float rotation);

		virtual void onGuiEvent(const sf::Event& e) override;

		virtual void onDirectGuiEvent(const sf::Event& e) override;

		virtual void update(sf::Vector2f& observable) override;

	protected:
		// Sets the default image for the button.
		void setDefaultImage(std::unique_ptr<sf::Sprite> image);

		// Sets the image used when the button is clicked. If no image is set, the 
		// the default image will be used.
		void setOnClickImage(std::unique_ptr<sf::Sprite> image);
	
		// Sets the image used when the mouse hovers over the button. If no image is
		// set, the default image will be used.
		void setOnHoverImage(std::unique_ptr<sf::Sprite> image);

		// Draws the button.
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		sf::Texture defaultTexture;
		sf::Texture onClickTexture;
		sf::Texture onHoverTexture;

	private:
		Button(const Button&);
		Button& operator=(const Button& other);

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

		sf::Clock hoverTimer;
		sf::Clock clickTimer;

		// Whether the timer for the onHoverImage has has expired or not.
		bool hoverTimerExpired() const;
		// Whether the timer for the onClickImage has expired or not.
		bool clickTimerExpired() const;
	};
}