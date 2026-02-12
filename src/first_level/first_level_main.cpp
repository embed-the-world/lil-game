
#include <iostream>

#include "first_level_main.h"
#include "sfml_actions.h"

#define PLAYER_VELOCITY (40.0f)

enum first_level_state_machine {
	FIRST_LEVEL_START = 0,
	FIRST_LEVEL_OFF,
	FIRST_LEVEL_RUNNING,
	FIRST_LEVEL_PAUSED,
} first_level_state = FIRST_LEVEL_OFF;

bool is_victory = false;

int first_level_stop()
{
	first_level_state = FIRST_LEVEL_OFF;
	return 0;
}

int first_level_start()
{
	std::cout << "-- start level 1\n";
	first_level_state = FIRST_LEVEL_START;
	return 0;
}

int first_level_process()
{
	switch(first_level_state)
	{
	case FIRST_LEVEL_OFF:
		break;
	case FIRST_LEVEL_START:
		/* init elements */
		sfml_actions_init_level_assets();
		sfml_actions_load_victory_text();
		first_level_state = FIRST_LEVEL_RUNNING;
		break;
	case FIRST_LEVEL_RUNNING:

		
		if(sfml_actions_is_move_down_active())
		{
			std::cout << "move - down\n";
			sfml_actions_move_player(0, PLAYER_VELOCITY);
		}
		if(sfml_actions_is_move_left_active())
		{
			std::cout << "move - left\n";
			sfml_actions_move_player(-PLAYER_VELOCITY, 0);
		}
		if(sfml_actions_is_move_up_active())
		{
			std::cout << "move - up\n";
			sfml_actions_move_player(0, -PLAYER_VELOCITY);
		}
		if(sfml_actions_is_move_right_active())
		{
			std::cout << "move - right\n";
			sfml_actions_move_player(PLAYER_VELOCITY, 0);
		}
		if(sfml_actions_is_victory())
		{
			is_victory = true;
		}
		else
		{
			is_victory = false;
		}
		break;
	case FIRST_LEVEL_PAUSED:
		break;
	default:
		break;
	}
	return 0;
}

int first_level_draw()
{
	switch(first_level_state)
	{
	case FIRST_LEVEL_OFF:
		break;
	case FIRST_LEVEL_START:
		break;
	case FIRST_LEVEL_RUNNING:
		sfml_actions_draw_level_assets();
		if(is_victory)
		{
			sfml_actions_draw_victory_text();
		}
		break;
	case FIRST_LEVEL_PAUSED:
		break;
	default:
		break;
	}
	return 0;
}
