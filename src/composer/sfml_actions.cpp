
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Vector2.hpp>

#include "sfml_actions.h"

/** Main window. */
sf::RenderWindow* main_window;

/** Simple Circle. */
sf::CircleShape* my_circle;
sf::Text* my_text;
/** Some Text. */
sf::Font* my_font;
sf::Vector2i* mouse_position;
/** Vector with circles. */
std::vector<sf::CircleShape*> my_vector;

bool isMouseButtonPressed = false;

int sfml_actions_init_window()
{
	main_window = new sf::RenderWindow( sf::VideoMode( { 1280, 720 } ), "SFML works!" );
	
	/* Create circle element */
	mouse_position = new sf::Vector2i(0,0);
	my_circle = new sf::CircleShape( 20.0f );
	my_circle->setFillColor( sf::Color::Green );

	/* create text element */
	my_font = new sf::Font("assets/fonts/ThaloriaRegular/Thaloria_Regular.ttf");
	my_text = new sf::Text(*my_font, "Hello World!\n""THALORIA\n""thaloria\n""°ÄÖÜß@€", 123);
	my_text->setPosition(sf::Vector2f(70,10));

	return 0;
}

bool sfml_actions_is_window_open()
{
	return main_window->isOpen();
}

int sfml_actions_draw_screen()
{
	main_window->clear();
	main_window->draw( *my_circle );
	main_window->draw( *my_text );
	/* draw circle vector */
	for (auto new_circle : my_vector) {
		main_window->draw(*new_circle);
	}
	main_window->display();
	return 0;
}

int sfml_actions_check_events() {
	while ( const std::optional event = main_window->pollEvent() )
	{
		if ( event->is<sf::Event::Closed>() )
		{
			main_window->close();
		}
		if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
		{
			if (mouseButtonPressed->button == sf::Mouse::Button::Left)
			{
				isMouseButtonPressed = true;
			}
		}
	}
	return 0;
}

int sfml_actions_update_mouse_position()
{
	*mouse_position = sf::Mouse::getPosition(*main_window);
	my_circle->setPosition(sf::Vector2f(mouse_position->x-20, mouse_position->y-20));
	return 0;
}

bool sfml_actions_has_click_event()
{
	return isMouseButtonPressed;
}

int sfml_actions_drop_circle()
{
	int radius = 15;
	isMouseButtonPressed = false;
	sf::Vector2i* mouse_position_now = new sf::Vector2i(sf::Mouse::getPosition(*main_window));
	sf::CircleShape* new_circle = new sf::CircleShape((float)radius);
	new_circle->setPosition(sf::Vector2f(mouse_position_now->x-radius, mouse_position_now->y-radius));
	new_circle->setFillColor( sf::Color::Yellow );
	my_vector.push_back(new_circle);
	if(my_vector.size()>10)
	{
		my_vector.erase(my_vector.begin());
	}
	return 0;
}
