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
#include "charactermenu_functions.h"
#include "gamestate_buttons.h"
#include "gamestate_game.h"


void charactermenu(void) {
	CP_Settings_Fill((CP_Color_Create(0, 0, 0, 255)));
	CP_Graphics_DrawRect(600.f, 400.f, 1100.f, 700.f);
	CP_Settings_Fill((CP_Color_Create(255, 255, 255, 255)));
	CP_Graphics_DrawRect(1100.f, 75.f, 100.f, 50.f);

	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Font_DrawText("X", 1100.f, 75.f);
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 100.f,50.f , 1100.f, 75.f) && CP_Input_MouseClicked()) {
		menu = 0;
	}
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 100.f, 50.f, 1100.f, 75.f)) {
		CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
		CP_Font_DrawText("X", 1100.f, 75.f);
	}
	CP_Settings_Fill((CP_Color_Create(255, 255, 255, 255)));
	CP_Graphics_DrawRect(300.f, 200.f, 250.f, 85.f);
	button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 250.f, 85.f, 300.f, 200.f);
	CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
	CP_Font_DrawText("Protector", 300.f, 200.f);
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 250.f, 85.f, 300.f, 200.f)) {
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Font_DrawText("Protector", 300.f, 200.f);
	}



	CP_Settings_Fill((CP_Color_Create(255, 255, 255, 255)));
	CP_Graphics_DrawRect(300.f, 300.f, 250.f, 85.f);
	button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 250.f, 85.f, 300.f, 300.f);
	CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
	CP_Font_DrawText("Acolyte", 300.f, 300.f);
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 250.f, 85.f, 300.f, 300.f)) {
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Font_DrawText("Acolyte", 300.f, 300.f);
	}





	CP_Settings_Fill((CP_Color_Create(255, 255, 255, 255)));
	CP_Graphics_DrawRect(300.f, 400.f, 250.f, 85.f);
	button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 250.f, 85.f, 300.f, 400.f);
	CP_Settings_Fill(CP_Color_Create(3, 186, 252, 255));
	CP_Font_DrawText("PickPocket", 300.f, 400.f);
	if (button_func(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 250.f, 85.f, 300.f, 400.f)) {
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Font_DrawText("PickPocket", 300.f, 400.f);
	}
	return;
}