
#include "composer.h"
#include "sfml_actions.h"

int composer_run_main_window()
{
	sfml_actions_init_window();

	while (sfml_actions_is_window_open())
	{
		sfml_actions_check_events();
		if(sfml_actions_has_click_event())
		{
			sfml_actions_drop_circle();
		}
		sfml_actions_update_mouse_position();
		sfml_actions_draw_screen();
	}

	return 0;
}
