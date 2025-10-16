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



struct Character { // Character template for player and enemy characters
	char name[50];
	//CP_Image characterSprite;
	int health;
	int mana;
	int manaRegen;
	float defense;
	int attackDamage;
	float xPosition;
	float yPosition;
};

struct Character playerOne = { "Wizard", 80, 100, 50, .0f, 10, 200, 300 }; // Initilization of the wizard player character
struct Character playerTwo = { "Tank", 120, 30, 15, .3f, 5, 200, 800 };
struct Character playerThree = { "Rogue", 90, 50, 0, .1f, 15, 200, 1300 };

struct Character enemyOne = { "Stupid idiot 1", 100, 100, 25, 0.2f, 5, 900, 200 };
struct Character enemyTwo = { "Stupid idiot 2", 100, 100, 25, 0.2f, 5, 1000, 400 };
struct Character enemyThree = { "Stupid idiot 3", 100, 100, 25, 0.2f, 5, 900, 600 };


float selectButtonY;
int buttonSelectOpacity;
int actionSelect;

float characterSelectY;
float characterSelectX;
int enemySelectOpacity;
int enemySelect;
int selectedEnemy;

int delay;




void character_action_attack(struct Character* _player, struct Character* _enemy, int _attacker);
void button_Select();
void enemy_Select();
void enemy_Turn();
void character_action_heal(struct Character* _characterHealer, struct Character* _characterHealed);





void gamestate_fight_init(void)
{
	CP_System_SetWindowSize(1200, 800);
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));

	CP_Settings_TextSize(45);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

	selectButtonY = 100;
	buttonSelectOpacity = 0;
	actionSelect = 1;
	enemySelect = 0;
	characterSelectY = (float)CP_System_GetWindowHeight() / 2 - ((float)CP_System_GetWindowHeight() / 4);
	characterSelectX = (float)CP_System_GetWindowWidth() / 2 + (float)CP_System_GetWindowWidth() / 4;
	selectedEnemy = 1;

}

void gamestate_fight_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));
	
	CP_Image_Draw(CP_Image_Load("./Assets/sneak sneak.png"), (float)CP_System_GetWindowWidth()/2 , (float)CP_System_GetWindowHeight() / 2 + ((float)CP_System_GetWindowHeight()/4), 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/its merely a flesh wound.png"), (float)CP_System_GetWindowWidth() / 2  , (float)CP_System_GetWindowHeight() / 2 - ((float)CP_System_GetWindowHeight() / 4), 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/YOU SHALL NOT PASS.png"), (float)CP_System_GetWindowWidth() / (12/(float)5), (float)CP_System_GetWindowHeight() / 2 , 256, 256, 255);

	
	CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), enemyOne.xPosition, enemyOne.yPosition, 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), enemyTwo.xPosition, enemyTwo.yPosition, 256, 256, 255);
	CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), enemyThree.xPosition, enemyThree.yPosition, 256, 256, 255);



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
		button_Select(selectButtonY);
		CP_Image_Draw(CP_Image_Load("./Assets/button_select.png"), 100, selectButtonY, 128*1.5, 128*1.5, 255);
		buttonSelectOpacity = 0;
	}
	if (enemySelect) {

		enemySelectOpacity = 255;
		enemy_Select(characterSelectX, characterSelectY);
		CP_Image_Draw(CP_Image_Load("./Assets/character_select.png"), characterSelectX, characterSelectY, 128 * 1.5, 128 * 1.5, 255);
		enemySelectOpacity = 0;
	}





}


void gamestate_fight_exit(void)
{
}




void character_action_attack(struct Character* _player, struct Character* _enemy, int _attacker) { // function for attacks: (attacker --- 0 means player attacks enemy, 1 is other
	switch (_attacker) {
	case 0: // Enemy loses health = to player characters attack damage (min = attackDamage, max = attackDamage + 10, eg 15 - 25 or 30 - 40)
		_enemy->health -= (rand() % ((10 + _player->attackDamage) - _player->attackDamage) + _player->attackDamage);
		return;
	case 1: // Player loses health
		_player->health -= (rand() % ((10 + _enemy->attackDamage) - _enemy->attackDamage) + _enemy->attackDamage);
		return;
	}
}




void button_Select() {


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
			enemySelect = 1;
			break;
		case 2:

			break;
		case 3:

			break;
		}
		actionSelect = 0;
		delay = 1;
	}

}
void enemy_Select() {

	float time;
	if (CP_Input_KeyTriggered(KEY_DOWN)) {
		if (characterSelectY < (float)CP_System_GetWindowHeight() / 2 + ((float)CP_System_GetWindowHeight() / 4)) {
			characterSelectY += ((float)CP_System_GetWindowHeight() / 4);
			selectedEnemy += 1;
		}
		else {
			characterSelectY = (float)CP_System_GetWindowHeight() / 2 - ((float)CP_System_GetWindowHeight() / 4);

			selectedEnemy = 1;

		}

	}
	if (CP_Input_KeyTriggered(KEY_UP)) {
		if (characterSelectY > (float)CP_System_GetWindowHeight() / 2 - ((float)CP_System_GetWindowHeight() / 4)) {
			characterSelectY -= ((float)CP_System_GetWindowHeight() / 4);
			selectedEnemy -= 1;

		}
		else {
			characterSelectY = (float)CP_System_GetWindowHeight() / 2 + ((float)CP_System_GetWindowHeight() / 4);
			selectedEnemy = 3;

		}

	}
	if (selectedEnemy == 2) {
		characterSelectX = (float)CP_System_GetWindowWidth() / 2 + (float)CP_System_GetWindowWidth() / 3;
	}
	else {
		characterSelectX = (float)CP_System_GetWindowWidth() / 2 + (float)CP_System_GetWindowWidth() / 4;
	}
	if (delay) {
		time = CP_System_GetSeconds();
		delay = 0;
	}
	else
		time = 0;
	if (CP_System_GetSeconds() - time > 0.5) {

		if (CP_Input_KeyTriggered(KEY_ENTER)) {
			switch (selectedEnemy) {
			case 1:
				character_action_attack(&playerOne, &enemyOne, 0);
				break;
			case 2:
				character_action_attack(&playerOne, &enemyTwo, 0);
				break;
			case 3:
				character_action_attack(&playerOne, &enemyThree, 0);
				break;
			}
			enemySelect = 0;
		}
	}
}

void enemy_Turn() {

	int enemyActionChoice = (rand() % 2) + 1;


	if (enemyActionChoice == 1) {

		int enemyAttackChoice = (rand() % 3) + 1;

		switch (enemyAttackChoice) {
		case 1: 
			character_action_attack(&playerOne, &enemyOne, 1);
			break;
		case 2:
			character_action_attack(&playerTwo, &enemyOne, 1);
			break;
		case 3:
			character_action_attack(&playerThree, &enemyOne, 1);
			break;
		}

	}
	else if (enemyActionChoice) {
		int enemyHealChoice = (rand() % 3) + 1;

		switch (enemyHealChoice) {
		case 1:
			character_action_heal(&playerOne, &enemyOne, 1);
			break;
		case 2:
			character_action_heal(&playerTwo, &enemyOne, 1);
			break;
		case 3:
			character_action_heal(&playerThree, &enemyOne, 1);
			break;
		}
	}

}



void character_action_heal(struct Character* _characterHealer, struct Character* _characterHealed) {
	_characterHealed->health += (rand() % ((5 + _characterHealer->attackDamage) - _characterHealer->attackDamage) + _characterHealer->attackDamage);
}



