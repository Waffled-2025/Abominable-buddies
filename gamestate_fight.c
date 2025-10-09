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
#include "gamestate_fight.h"





typedef struct { // Character template for player and enemy characters
	char name[50];
	CP_Image characterSprite;
	int health;
	int mana;
	float defense;
	int attackDamage;
} Character;






void player_attack_enemy() { // function for attacks 

}






void gamestate_fight_init(void)
{
	CP_System_Fullscreen();
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));

	Character playerOne = { "Wizard", CP_Image_Load("./Assets/YOU SHALL NOT PASS.png"), 80, 100, .0f, 10}; // Initilization of the wizard player character
	Character playerTwo = { "Tank",  CP_Image_Load("./Assets/Its merely a flesh wound.png"), 120, 50, .3f, 5 }; // Initilization of the tank player character
	Character playerThree = { "Rogue",  CP_Image_Load("./Assets/sneak sneak.png"), 90, 50, .1f, 15 }; // rogue

	Character enemyOne = { "Stupid idiot",  CP_Image_Load("./Assets/s n o w m e n e m y.png"), 100, 100, 0.2f, 10 };
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void gamestate_fight_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void gamestate_fight_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}
