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
#include "gamestate_menu.h"
#include "gamestate_splashscreen.h"
#include "gamestate_game.h"
#include "gamestate_buttons.h"

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_menu_init(void)
{
	CP_Settings_TextSize(100);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_V_MIDDLE, CP_TEXT_ALIGN_H_CENTER );
	CP_System_SetWindowSize(1200 , 800);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_menu_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 0));

	CP_Settings_Fill( CP_Color_Create(0, 0, 0, 255));
	CP_Graphics_DrawRect((float)CP_System_GetWindowWidth()/2.f , ((float)CP_System_GetWindowHeight() / 3.f)+200, CP_System_GetWindowWidth()/ 3.f, CP_System_GetWindowHeight()/ 8.f);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("START", (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 200);
	button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 200);
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 200)&& CP_Input_MouseClicked()) {
		CP_Engine_SetNextGameState(gamestate_game_init, gamestate_game_update, gamestate_game_exit);
	}
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 200)) {
		CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
		CP_Font_DrawText("START", (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 200);
	}

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Graphics_DrawRect((float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 312, CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("QUIT", (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 312);
	button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 312);
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 312) && CP_Input_MouseClicked()) {
		CP_Engine_Terminate();
	}
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 312)) {
		CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
		CP_Font_DrawText("QUIT", (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 312);
	}
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Graphics_DrawRect((float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 425, CP_System_GetWindowWidth() / 3.f, CP_System_GetWindowHeight() / 8.f);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Font_DrawText("CREDITS", (float)CP_System_GetWindowWidth() / 2.f, ((float)CP_System_GetWindowHeight() / 3.f) + 425);
	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_menu_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
