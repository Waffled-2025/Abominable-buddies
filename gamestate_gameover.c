//---------------------------------------------------------
// file:	gamestate_template.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	template file for holding gamestate functions
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "gamestate_gameover.h"
#include "gamestate_buttons.h"
#include "gamestate_fight.h"
#include "gamestate_game.h"

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_gameover_init(void)
{
	CP_System_SetWindowSize(1200, 800);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextSize(150);

	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_gameover_update(void)
{
	CP_Settings_TextSize(150);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 130, 255, 100));
	CP_Font_DrawText("GAME OVER", 600, 100);

	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 500, 125, 600, 300)) {
		CP_Settings_Fill(CP_Color_Create(255, 0, 50, 255));
		if (CP_Input_MouseClicked()) {
			CP_Engine_SetNextGameState(gamestate_game_init, gamestate_game_update, gamestate_game_exit);
		}
	}
	else {
		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	}

	CP_Settings_TextSize(75);
	CP_Graphics_DrawRect(600, 300, 500, 125);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("RESTART", 600, 300);

	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 500, 125, 600, 450)) {
		CP_Settings_Fill(CP_Color_Create(255, 0, 50, 255));
		if (CP_Input_MouseClicked()) {
			CP_Engine_SetNextGameState(gamestate_game_init, gamestate_game_update, gamestate_game_exit);
		}
	}
	else {
		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	}

	CP_Graphics_DrawRect(600, 450, 500, 125);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("MAIN MENU", 600, 450);

	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 500, 125, 600, 600)) {
		CP_Settings_Fill(CP_Color_Create(255, 0, 50, 255));
		if (CP_Input_MouseClicked()) {
			CP_Engine_Terminate();
		}
	}
	else {
		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	}

	CP_Graphics_DrawRect(600, 600, 500, 125);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("QUIT", 600, 600);






	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_gameover_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
