
#include "composer.h"
#include "sfml_actions.h"
#include "mainmenu_main.h"

int composer_run_main_window()
{
	sfml_actions_init_window();

	while (sfml_actions_is_window_open())
	{
		/* check events */
		sfml_actions_check_events();

		/* fill screen */

		if(sfml_actions_has_click_event())
		{
			sfml_actions_process_click();
		}
		sfml_actions_update_mouse_position();
		/* - menu stuff */
		mainmenu_process();

		/* draw elements */
		sfml_actions_draw_screen();
		mainmenu_draw_menu();
	}

	return 0;
}
