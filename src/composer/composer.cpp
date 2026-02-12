
#include "composer.h"
#include "sfml_actions.h"
#include "mainmenu_main.h"
#include "first_level_main.h"

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
		first_level_process();

		/* draw elements */
		sfml_actions_draw_screen();
		first_level_draw();
		mainmenu_draw_menu();

		/* Let sfml render everything. */
		sfml_action_show_scene();
	}

	return 0;
}
