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
CP_Image Level1Background;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_game_init(void)
{
	 Level1Background = CP_Image_Load ("image_2025-10-17_132724709.png");
	CP_System_SetWindowSize(1200, 800);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	
	
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_game_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 0));
	CP_Image_Draw(Level1Background, 600, 400, 1200, 800, 255);

	//CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));     //first encounter
	//CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f - 203, ((float)CP_System_GetWindowHeight() / 3.f) + 468, CP_System_GetWindowWidth() / 18.f);
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f - 203, ((float)CP_System_GetWindowHeight() / 3.f)+468, CP_System_GetWindowWidth() / 18.f)) {
		CP_Settings_Fill(CP_Color_Create(11, 3, 252, 255));
		CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f - 203, ((float)CP_System_GetWindowHeight() / 3.f) + 468, CP_System_GetWindowWidth() / 18.f);
	}
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f - 203, ((float)CP_System_GetWindowHeight() / 3.f)+468, CP_System_GetWindowWidth() / 18.f) && CP_Input_MouseClicked()) {
		CP_Engine_SetNextGameState(gamestate_fight_init, gamestate_fight_update, gamestate_fight_exit);
	}

	//CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));    //second encounter
	//CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f + 97, ((float)CP_System_GetWindowHeight() / 3.f)+297 , CP_System_GetWindowWidth() / 18.f);
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f + 97, ((float)CP_System_GetWindowHeight() / 3.f)+297 , CP_System_GetWindowWidth() / 18.f)&& battleCompleted>=1) {
		CP_Settings_Fill(CP_Color_Create(11, 3, 252, 255));
		CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f + 97, ((float)CP_System_GetWindowHeight() / 3.f)+297 , CP_System_GetWindowWidth() / 18.f);
	}
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f + 97, ((float)CP_System_GetWindowHeight() / 3.f)+297 , CP_System_GetWindowWidth() / 18.f) && CP_Input_MouseClicked()&&battleCompleted>=1) {
		CP_Engine_SetNextGameState(gamestate_fight_init, gamestate_fight_update, gamestate_fight_exit);
	}

	//CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));//third encounter
	//CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f - 355, ((float)CP_System_GetWindowHeight() / 3.f) + 97, CP_System_GetWindowWidth() / 18.f);
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f - 355, ((float)CP_System_GetWindowHeight() / 3.f) + 97, CP_System_GetWindowWidth() / 18.f)&&battleCompleted>=2) {
		CP_Settings_Fill(CP_Color_Create(11, 3, 252, 255));
		CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f - 355, ((float)CP_System_GetWindowHeight() / 3.f) + 97, CP_System_GetWindowWidth() / 18.f);
	}
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f - 355, ((float)CP_System_GetWindowHeight() / 3.f) + 97, CP_System_GetWindowWidth() / 18.f) && CP_Input_MouseClicked()&&battleCompleted>=2) {
		CP_Engine_SetNextGameState(gamestate_fight_init, gamestate_fight_update, gamestate_fight_exit);
	}

	//CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));//fourth encounter
	//CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f + 350, ((float)CP_System_GetWindowHeight() / 3.f) , CP_System_GetWindowWidth() / 18.f);
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f + 350, ((float)CP_System_GetWindowHeight() / 3.f) , CP_System_GetWindowWidth() / 18.f)&&battleCompleted>=3) {
		CP_Settings_Fill(CP_Color_Create(11, 3, 252, 255));
		CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f + 350, ((float)CP_System_GetWindowHeight() / 3.f) , CP_System_GetWindowWidth() / 18.f);
	}
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f + 350, ((float)CP_System_GetWindowHeight() / 3.f) , CP_System_GetWindowWidth() / 18.f) && CP_Input_MouseClicked()&&battleCompleted>=3) {
		CP_Engine_SetNextGameState(gamestate_fight_init, gamestate_fight_update, gamestate_fight_exit);
	}

	//CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));//Boss encounter
	//CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f , 0, CP_System_GetWindowWidth() / 4.f);
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f , 0, CP_System_GetWindowWidth() / 4.f)&&battleCompleted>=4) {
		CP_Settings_Fill(CP_Color_Create(11, 3, 252, 255));
		CP_Graphics_DrawCircle((float)CP_System_GetWindowWidth() / 2.f , 0, CP_System_GetWindowWidth() / 4.f);
	}
	if (button_func_circle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), (float)CP_System_GetWindowWidth() / 2.f , 0, CP_System_GetWindowWidth() / 4.f) && CP_Input_MouseClicked()&&battleCompleted>=4) {
		CP_Engine_SetNextGameState(gamestate_fight_init, gamestate_fight_update, gamestate_fight_exit);
	}

	
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Graphics_DrawRect((float)CP_System_GetWindowWidth() / 2.f+400, ((float)CP_System_GetWindowHeight() / 3.f) +350, CP_System_GetWindowWidth() / 4.f, CP_System_GetWindowHeight() / 8.f);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize((float)60);
	CP_Font_DrawText("CHARACTERS", (float)CP_System_GetWindowWidth() / 2.f+400, ((float)CP_System_GetWindowHeight() / 3.f) + 350);
	button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 4.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f+400, ((float)CP_System_GetWindowHeight() / 3.f) + 350);
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 4.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f+400, ((float)CP_System_GetWindowHeight() / 3.f) + 350) && CP_Input_MouseClicked()) {
		//call for character function thing when made
	}
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CP_System_GetWindowWidth() / 4.f, CP_System_GetWindowHeight() / 8.f, (float)CP_System_GetWindowWidth() / 2.f+400, ((float)CP_System_GetWindowHeight() / 3.f) + 350)) {
		CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
		CP_Font_DrawText("CHARACTERS", (float)CP_System_GetWindowWidth() / 2.f+400, ((float)CP_System_GetWindowHeight() / 3.f) + 350);
	}














	// check input, update simulation, render etc.
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
