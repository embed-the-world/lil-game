#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Start main window.
 * 
 * @return int 0 on completion.
 */
int sfml_actions_init_window();

/**
 * @brief Check if sfml window is open.
 */
bool sfml_actions_is_window_open();

/**
 * @brief Check for sfml events.
 * 
 * @return int always 0.
 */
int sfml_actions_check_events();

/**
 * @brief Draw screen elements.
 * 
 * @return int always 0.
 */
int sfml_actions_draw_screen();

/**
 * @brief Update mouse position vector.
 * 
 * @return int always 0.
 */
int sfml_actions_update_mouse_position();

/**
 * @brief check if left click happened.
 * 
 * @return true Left mouse button was activated since last update.
 * @return false Left mouse button was not activated.
 */
bool sfml_actions_has_click_event();

/**
 * @brief Draw circle at mouse position.
 * 
 * After 10 circles are present, the first one gets deleted when next circle is drawn.
 * 
 * @return int Always 0.
 */
int sfml_actions_drop_circle(int pos_x, int pos_y);

/**
 * @brief Get window pointer.
 */
int sfml_actions_get_window(sf::RenderWindow* out_main_window);

int sfml_actions_close_window();

int sfml_menu_init_elements();
int sfml_menu_draw_menu_big();
int sfml_menu_draw_menu_small();

int sfml_actions_process_click();

bool sfml_menu_is_coord_on_button_mid(int pos_x, int pos_y);
bool sfml_menu_is_coord_on_button_bot(int pos_x, int pos_y);
bool sfml_menu_is_coord_on_button_top(int pos_x, int pos_y);
bool sfml_menu_is_coord_on_small_menu(int pos_x, int pos_y);

