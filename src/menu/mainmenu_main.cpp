
#include <iostream>

#include "first_level_main.h"
#include "mainmenu_main.h"
#include "sfml_actions.h"

enum mainmenu_state_machine {
	MAINMENU_INIT = 0,
	MAINMENU_OFF,
	MAINMENU_ON,
	MAINMENU_SMALL,
} mainmenu_state = MAINMENU_INIT;

int mainmenu_process()
{
	//sfml_menu_draw_menu
	switch(mainmenu_state) {
	case MAINMENU_INIT:
		sfml_menu_init_elements();
		mainmenu_state = MAINMENU_ON;
		//std::cout << "hiho\n";
		break;
	case MAINMENU_OFF:
		break;
	case MAINMENU_ON:
		break;
	case MAINMENU_SMALL:
		break;
	default:
		break;
	}

	return 0;
}

int mainmenu_draw_menu()
{
	switch(mainmenu_state) {
	case MAINMENU_INIT:
		break;
	case MAINMENU_OFF:
		break;
	case MAINMENU_ON:
		sfml_menu_draw_menu_big();
		break;
	case MAINMENU_SMALL:
		sfml_menu_draw_menu_small();
		break;
	default:
		break;
	}

	return 0;
}

int mainmenu_process_click(int pos_x, int pos_y)
{
	switch(mainmenu_state) {
	case MAINMENU_INIT:
		break;
	case MAINMENU_OFF:
		break;
	case MAINMENU_ON:
		if(sfml_menu_is_coord_on_button_mid(pos_x, pos_y))
		{
			mainmenu_state = MAINMENU_SMALL;
		}
		if(sfml_menu_is_coord_on_button_bot(pos_x, pos_y))
		{
			sfml_actions_close_window();
		}
		if(sfml_menu_is_coord_on_button_top(pos_x, pos_y))
		{
			first_level_start();
			mainmenu_state = MAINMENU_SMALL;
		}
		break;
	case MAINMENU_SMALL:
		if(sfml_menu_is_coord_on_small_menu(pos_x, pos_y))
		{
			mainmenu_state = MAINMENU_ON;
		}
		break;
	default:
		break;
	}

	return 0;
}

