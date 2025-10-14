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
#include "gamestate_game.h"
#include "gamestate_buttons.h"
#include "gamestate_fight.h"

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_game_init(void)
{
	CP_System_SetWindowSize(1200, 800);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 0));

	CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
	CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f - 200, ((float)CP_System_GetWindowHeight() / 3.f) + 475, CP_System_GetWindowWidth() / 15.f);
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f - 200, ((float)CP_System_GetWindowHeight() / 3.f)+475, CP_System_GetWindowWidth() / 15.f)) {
		CP_Settings_Fill(CP_Color_Create(11, 3, 252, 255));
		CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f - 200, ((float)CP_System_GetWindowHeight() / 3.f) + 475, CP_System_GetWindowWidth() / 15.f);
	}
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f - 200, ((float)CP_System_GetWindowHeight() / 3.f)+475, CP_System_GetWindowWidth() / 15.f) && CP_Input_MouseClicked()) {
		CP_Engine_SetNextGameState(gamestate_fight_init, gamestate_fight_update, gamestate_fight_exit);
	}
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
