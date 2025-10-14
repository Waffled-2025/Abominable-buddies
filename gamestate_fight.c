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
#include "math.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"



typedef struct { // Character template for player and enemy characters
	char name[50];
	//CP_Image characterSprite;
	int health;
	int mana;
	int manaRegen;
	float defense;
	int attackDamage;
	int xPosition;
	int yPosition;
} Character;

Character playerOne = { "Wizard", 80, 100, 50, .0f, 10, 200, 300 }; // Initilization of the wizard player character
Character playerTwo = { "Tank", 120, 30, 15, .3f, 5, 200, 800 };
Character playerThree = { "Rogue", 90, 50, 0, .1f, 15, 200, 1300 };

Character enemyOne = { "Stupid idiot 1", 100, 100, 25, 0.2f, 10, 900, 300 };
Character enemyTwo = { "Stupid idiot 2", 100, 100, 25, 0.2f, 10, 900, 800 };
Character enemyThree = { "Stupid idiot 3", 100, 100, 25, 0.2f, 10, 900, 1300 };


float selectButtonY;
int buttonSelectOpacity;
int actionSelect;









void buttonSelect(float _selectButtonY) {


	int selectedAction = 1;

	if (CP_Input_KeyTriggered(KEY_DOWN)) {
		if (selectButtonY < 300) {
			selectButtonY += 100;
			selectedAction += 1;
		}
		else {
			selectButtonY = 100;
			selectedAction = 1;

		}

	}
	if (CP_Input_KeyTriggered(KEY_UP)) {
		if (selectButtonY > 100) {
			selectButtonY -= 100;
			selectedAction -= 1;

		}
		else {
			selectButtonY = 300;
			selectedAction = 3;

		}

	}


	if (CP_Input_KeyTriggered(KEY_ENTER)) {
		switch (selectedAction) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		}
	}


	
}






void character_action_attack(Character _player, Character _enemy, int _attacker) { // function for attacks: (attacker --- 0 means player attacks enemy, 1 is other
	switch (_attacker) {
		case 0: // Enemy loses health = to player characters attack damage (min = attackDamage, max = attackDamage + 10, eg 15 - 25 or 30 - 40)
			_enemy.health -= (rand() % ((10 + _player.attackDamage) - _player.attackDamage) + _player.attackDamage); 
			return;
		case 1: // Player loses health
			_player.health -= (rand() % ((10 + _enemy.attackDamage) - _enemy.attackDamage) + _enemy.attackDamage);
			return;
	}
}
void character_wizard_meditate(Character _wizard) {
	_wizard.mana += (rand() % ((_wizard.manaRegen + 5) - (_wizard.manaRegen - 5)) + (_wizard.manaRegen - 5));
}
void character_tank_defend(Character _tank) {
	_tank.defense += 0.45f;
}






void gamestate_fight_init(void)
{
	CP_System_SetWindowSize(1200, 800);
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));

	CP_Settings_TextSize(45);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	selectButtonY = 100;
	buttonSelectOpacity = 0;
	actionSelect = 1;
	
}

void gamestate_fight_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));
	
	CP_Image_Draw(CP_Image_Load("./Assets/sneak sneak.png"), (float)CP_System_GetWindowWidth()/2 , (float)CP_System_GetWindowHeight() / 2 + ((float)CP_System_GetWindowHeight()/4), 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/its merely a flesh wound.png"), (float)CP_System_GetWindowWidth() / 2  , (float)CP_System_GetWindowHeight() / 2 - ((float)CP_System_GetWindowHeight() / 4), 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/YOU SHALL NOT PASS.png"), (float)CP_System_GetWindowWidth() / (12/(float)5), (float)CP_System_GetWindowHeight() / 2 , 256, 256, 255);

	
	CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), (float)CP_System_GetWindowWidth() / 2 + (float)CP_System_GetWindowWidth() / 3, (float)CP_System_GetWindowHeight() / 2, 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), (float)CP_System_GetWindowWidth() / 2 + (float)CP_System_GetWindowWidth() / 4, (float)CP_System_GetWindowHeight() / 2 - ((float)CP_System_GetWindowHeight() / 4), 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), (float)CP_System_GetWindowWidth() / 2 + (float)CP_System_GetWindowWidth() / 4, (float)CP_System_GetWindowHeight() / 2 + ((float)CP_System_GetWindowHeight() / 4), 256, 256, 255);



	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));

	CP_Graphics_DrawRect(100, 100, 150, 75);

	CP_Graphics_DrawRect(100, 200, 150, 75);

	CP_Graphics_DrawRect(100, 300, 150, 75);


	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));

	CP_Font_DrawText("ATTACK", 100, 100);
	CP_Font_DrawText("DEFEND", 100, 200);
	CP_Font_DrawText("REST", 100, 300);
	




	if (actionSelect) {

		buttonSelectOpacity = 255;
		buttonSelect(selectButtonY);
		CP_Image_Draw(CP_Image_Load("./Assets/button_select.png"), 100, selectButtonY, 128*1.5, 128*1.5, 255);
		buttonSelectOpacity = 0;


	}






}


void gamestate_fight_exit(void)
{
}
