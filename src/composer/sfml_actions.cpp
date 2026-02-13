
#include <vector>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System/Export.hpp>
#include <SFML/System/Vector2.hpp>

#include "sfml_actions.h"
#include "mainmenu_main.h"

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

/* Assets */
sf::Texture* texture_main_character;
sf::Texture* texture_goalpost;
sf::Sprite* sprite_main_character;
sf::Sprite* sprite_goalpost;

bool isMouseButtonPressed = false;

int sfml_actions_init_level_assets()
{
	texture_main_character = new sf::Texture("assets/beautiful_art/main_character.png");
	sprite_main_character = new sf::Sprite(*texture_main_character);
	sprite_main_character->setPosition({10.0f, 200.0f});

	texture_goalpost = new sf::Texture("assets/beautiful_art/goalpost.png");
	sprite_goalpost = new sf::Sprite(*texture_goalpost);
	sprite_goalpost->setPosition({900, 400});

	return 0;
}

bool sfml_actions_is_victory()
{
	double box_distance = 0.0f;

	sf::Vector2f box1 = sprite_main_character->getPosition();
	sf::Vector2f box2 = sprite_goalpost->getPosition();

	box_distance = std::sqrt(
		(((float)box1.x - (float)box2.x) * ((float)box1.x - (float)box2.x))	+
		(((float)box1.y - (float)box2.y) * ((float)box1.y - (float)box2.y))
	);

	//std::cout << box_distance << "\n";
	if(box_distance < 145.0f)
	{
		return true;
	}

	return false;
}


int sfml_actions_draw_level_assets()
{
	main_window->draw(*sprite_goalpost);
	main_window->draw(*sprite_main_character);
	return 0;
}

int sfml_actions_move_player(double mov_x, double mov_y)
{
	sprite_main_character->move({mov_x, mov_y});
	return 0;
}

int sfml_actions_init_window()
{
	main_window = new sf::RenderWindow( sf::VideoMode( { 1280, 720 } ), "SFML works!" );
	
	/* Create circle element */
	mouse_position = new sf::Vector2i(0,0);
	my_circle = new sf::CircleShape( 20.0f );
	my_circle->setFillColor( sf::Color::Green );

	/* create text element */
	my_font = new sf::Font("src/fonts/Roboto-Regular.ttf");
	my_text = new sf::Text(*my_font, "Hello World!\n""Font: Roboto", 80);
	my_text->setPosition(sf::Vector2f(70,10));

	return 0;
}

sf::Text* text_victory;
int sfml_actions_load_victory_text()
{
	text_victory = new sf::Text(*my_font, "VICTORY!", 150);
	text_victory->setFillColor(sf::Color::Yellow);
	text_victory->setPosition({133, 244});
	return 0;
}

int sfml_actions_draw_victory_text()
{
	main_window->draw(*text_victory);
	return 0;
}

bool sfml_actions_is_window_open()
{
	return main_window->isOpen();
}

int sfml_actions_draw_screen()
{
	main_window->clear();
	main_window->draw( *my_text );
	/* draw circle vector */
	for (auto new_circle : my_vector) {
		main_window->draw(*new_circle);
	}

	/* draw mouse pointer*/
	main_window->draw( *my_circle );

	return 0;
}

int sfml_action_show_scene()
{
	/* show everything */
	main_window->display();
	return 0;
}

bool is_move_right_active = false;
bool sfml_actions_is_move_right_active()
{
	bool ret_val = is_move_right_active;
	is_move_right_active = false;
	return ret_val;
}

bool is_move_left_active = false;
bool sfml_actions_is_move_left_active()
{
	bool ret_val = is_move_left_active;
	is_move_left_active = false;
	return ret_val;
}

bool is_move_up_active = false;
bool sfml_actions_is_move_up_active()
{
	bool ret_val = is_move_up_active;
	is_move_up_active = false;
	return ret_val;
}

bool is_move_down_active = false;
bool sfml_actions_is_move_down_active()
{
	bool ret_val = is_move_down_active;
	is_move_down_active = false;
	return ret_val;
}

int sfml_actions_check_events() {
	while ( const std::optional event = main_window->pollEvent() )
	{
		if ( event->is<sf::Event::Closed>() )
		{
			sfml_actions_close_window();
		}
		if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
		{
			if (mouseButtonPressed->button == sf::Mouse::Button::Left)
			{
				isMouseButtonPressed = true;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			is_move_up_active = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			is_move_left_active = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			is_move_down_active = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			is_move_right_active = true;
	}
	return 0;
}

int sfml_actions_close_window()
{
	main_window->close();
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

int sfml_actions_process_click()
{
	sf::Vector2i* mouse_position_now = new sf::Vector2i(sf::Mouse::getPosition(*main_window));

	sfml_actions_drop_circle(mouse_position_now->x, mouse_position_now->y);
	mainmenu_process_click(mouse_position_now->x, mouse_position_now->y);

	isMouseButtonPressed = false;
	return 0;
}

int sfml_actions_drop_circle(int pos_x, int pos_y)
{
	int radius = 15;
	sf::CircleShape* new_circle = new sf::CircleShape((float)radius);
	new_circle->setPosition(sf::Vector2f(pos_x-radius, pos_y-radius));
	new_circle->setFillColor( sf::Color::Blue );
	my_vector.push_back(new_circle);
	if(my_vector.size()>10)
	{
		my_vector.erase(my_vector.begin());
	}
	return 0;
}

int sfml_actions_get_window(sf::RenderWindow* out_main_window)
{
	if(NULL == out_main_window)
	{
		return -1;
	}
	out_main_window = main_window;
	return 0;
}


/** ------------------ menu -------------------- */
sf::RectangleShape* button_top;
sf::RectangleShape* button_mid;
sf::RectangleShape* button_bot;
sf::RectangleShape* button_menu_small;
sf::Text* text_button_top;
sf::Text* text_button_mid;
sf::Text* text_button_bot;
sf::Text* text_button_menu_small;

int sfml_menu_init_elements()
{
	int font_size = 50;

	button_top = new sf::RectangleShape({400.0f, 50.0f});
	button_mid = new sf::RectangleShape({390.0f, 50.0f});
	button_bot = new sf::RectangleShape({380.0f, 50.0f});
	button_menu_small = new sf::RectangleShape({100.0f, 20.0f});

	button_top->setFillColor(sf::Color::Red);
	button_mid->setFillColor(sf::Color::Yellow);
	button_bot->setFillColor(sf::Color::Green);
	button_menu_small->setFillColor(sf::Color::Red);

	button_top->setOutlineColor(sf::Color::Magenta);
	button_mid->setOutlineColor(sf::Color::Magenta);
	button_bot->setOutlineColor(sf::Color::Magenta);
	button_menu_small->setOutlineColor(sf::Color::Red);

	button_top->setOutlineThickness(5.0f);
	button_mid->setOutlineThickness(5.0f);
	button_bot->setOutlineThickness(5.0f);
	button_menu_small->setOutlineThickness(5.0f);

	button_top->setPosition({450.0f, 170.0f});
	button_mid->setPosition({450.0f, 300.0f});
	button_bot->setPosition({450.0f, 430.0f});
	button_menu_small->setPosition({900.0f, 20.0f});

	text_button_top = new sf::Text(*my_font, "Start", font_size);
	text_button_top->setFillColor(sf::Color::Blue);
	text_button_top->setPosition({470.0f, 160.0f});

	text_button_mid = new sf::Text(*my_font, "option (WIP)", font_size);
	text_button_mid->setFillColor(sf::Color::Blue);
	text_button_mid->setPosition({470.0f, 290.0f});

	text_button_bot = new sf::Text(*my_font, "Quit", font_size);
	text_button_bot->setFillColor(sf::Color::Blue);
	text_button_bot->setPosition({470.0f, 420.0f});

	text_button_menu_small = new sf::Text(*my_font, "Menu", 25);
	text_button_menu_small->setFillColor(sf::Color::Blue);
	text_button_menu_small->setPosition({920.0f, 15.0f});

	return 0;
}

int sfml_menu_draw_menu_big()
{
	/* Draw elements. */
	main_window->draw(*button_top);
	main_window->draw(*button_mid);
	main_window->draw(*button_bot);
	main_window->draw(*text_button_top);
	main_window->draw(*text_button_mid);
	main_window->draw(*text_button_bot);
	return 0;
}

int sfml_menu_draw_menu_small()
{
	/* Draw elements. */
	main_window->draw(*button_menu_small);
	main_window->draw(*text_button_menu_small);
	return 0;
}

bool sfml_menu_is_coord_on_small_menu(int pos_x, int pos_y)
{
	sf::Vector2f pointToCheck(pos_x, pos_y);
	sf::FloatRect bounds_button = button_menu_small->getGlobalBounds();
	if(bounds_button.contains(pointToCheck))
	{
		return true;
	}
	return false;
}

bool sfml_menu_is_coord_on_button_top(int pos_x, int pos_y)
{
	sf::Vector2f pointToCheck(pos_x, pos_y);
	sf::FloatRect bounds_button = button_top->getGlobalBounds();
	if(bounds_button.contains(pointToCheck))
	{
		return true;
	}
	return false;
}

bool sfml_menu_is_coord_on_button_mid(int pos_x, int pos_y)
{
	sf::Vector2f pointToCheck(pos_x, pos_y);
	sf::FloatRect bounds_button_mid = button_mid->getGlobalBounds();
	if(bounds_button_mid.contains(pointToCheck))
	{
		return true;
	}
	return false;
}
bool sfml_menu_is_coord_on_button_bot(int pos_x, int pos_y)
{
	sf::Vector2f pointToCheck(pos_x, pos_y);
	sf::FloatRect bounds_button = button_bot->getGlobalBounds();
	if(bounds_button.contains(pointToCheck))
	{
		return true;
	}
	return false;
}
