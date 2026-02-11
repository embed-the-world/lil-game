#pragma once

/**
 * @brief Mainmenu creation function.
 * 
 * @return int 0 on success.
 */
int mainmenu_process();

/**
 * @brief Draw menu items.
 * 
 * @return int 0 on success.
 */
int mainmenu_draw_menu();

int mainmenu_process_click(int pos_x, int pos_y);
