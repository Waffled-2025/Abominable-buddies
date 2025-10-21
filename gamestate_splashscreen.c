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
#include "gamestate_splashscreen.h"
#include "gamestate_menu.h"


CP_Image digipenLogo;
CP_Image abominableLogo;
int opacity;
int fadeIn;
float scale;
float time;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void gamestate_splashscreen_init(void)
{
	scale = 0;
	CP_System_SetWindowSize(CP_System_GetDisplayWidth()/2, CP_System_GetDisplayHeight()/2);
	opacity = 0;
	digipenLogo = CP_Image_Load("./Assets/Digipen_Red.png");
	abominableLogo = CP_Image_Load("./Assets/AS_LOGO.png");
	fadeIn = 1;
	// initialize variables and CProcessing settings for this gamestate
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_splashscreen_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(200, 200, 200, 0));
	if (opacity <= 250 && fadeIn) {

		opacity += 2;
	}
	else if (CP_System_GetSeconds() > 5 && opacity > 0) {
		opacity -= 2;
		fadeIn = 0;
	}
	else if (!fadeIn && scale < 1) {
		scale += 0.05f;
		time = CP_System_GetSeconds();
	}
	else if (CP_System_GetSeconds() > 10) {
		CP_Engine_SetNextGameState(gamestate_menu_init, gamestate_menu_update, gamestate_menu_exit);

	}
	
	 
	CP_Image_Draw(abominableLogo, (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight() / 2, CP_System_GetWindowWidth() * scale, CP_System_GetWindowHeight() * scale, 255);


	CP_Image_Draw(digipenLogo, (float)CP_System_GetWindowWidth() / 2, (float)CP_System_GetWindowHeight() / 2, ((float)CP_System_GetWindowHeight() * ((float)1.051 / (float).249))/4, (float)CP_System_GetWindowHeight()/4, opacity);


}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_splashscreen_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
