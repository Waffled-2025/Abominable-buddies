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
#include "character_functions.h"



struct Character playerOne = { "Tank", 120, 30, 15, .3f, 5, 600, 200, 0 };
struct Character playerTwo = { "Wizard", 80, 100, 50, .0f, 10, 500, 400, 0 }; 
struct Character playerThree = { "Rogue", 90, 50, 0, .1f, 15, 600, 600, 0 };

struct Character enemyOne = { "Stupid idiot 1", 100, 100, 25, 0.2f, 5, 900, 200, 0 };
struct Character enemyTwo = { "Stupid idiot 2", 100, 100, 25, 0.2f, 5, 1000, 400, 0 };
struct Character enemyThree = { "Stupid idiot 3", 100, 100, 25, 0.2f, 5, 900, 600, 0 };


float selectButtonY;
int buttonSelectOpacity;

float characterSelectY;
float characterSelectX;
int enemySelectOpacity;
int selectedEnemy;

int actionSelect;
int enemySelect;
int enemyTurn;
int playerTurn;

int delay;
int selectedAction;

int characterTurn;
int upDown;

int enemyActionChoice;



int allySelect;
int selectedAlly;



void button_Select(struct Character* _character);
void enemy_Select(struct Character* _player);
void enemy_Turn(struct Character _enemy);
void player_Turn(struct Character* _character);
void draw_characters();

void turn_manager();


void debug();




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
	enemyTurn = 0;
	characterSelectY = (float)CP_System_GetWindowHeight() / 2 - ((float)CP_System_GetWindowHeight() / 4);
	characterSelectX = (float)CP_System_GetWindowWidth() / 2 + (float)CP_System_GetWindowWidth() / 4;
	selectedEnemy = 1;
	selectedAction = 1;
	playerTurn = 1;
	characterTurn = 1;
	upDown = 0;
	allySelect = 0;
	selectedAlly = 1;

}

void gamestate_fight_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));

	draw_characters();

	turn_manager();

	debug();


}


void gamestate_fight_exit(void)
{
}


void button_Select(struct Character* _character) {



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
			if (_character == &playerOne) {
				character_action_defend(_character);
				characterTurn += 1;
			}
			if (_character == &playerTwo) {
				allySelect = 1;
			}
			if (_character == &playerThree) {
				characterTurn += 1;
			}

			break;
		case 3:
			if (_character == &playerOne) {
				character_action_rest(_character);
			}
			if (_character == &playerTwo) {
				character_action_meditate(_character);
			}
			if (_character == &playerThree) {

			}

			characterTurn += 1;

			break;
		}
		actionSelect = 0;
		delay = 1;
		if (enemyOne.health > 0) {
			selectedEnemy = 1;
			return;
		}
		else if (enemyOne.health < 1)
			selectedEnemy += 1;
		if (enemyTwo.health > 0)
			selectedEnemy = 2;
		else if (enemyTwo.health < 1)
			selectedEnemy += 1;
	}

}
void enemy_Select(struct Character* _player) {

	float time;
	if (CP_Input_KeyTriggered(KEY_DOWN)) {

		selectedEnemy += 1;
		upDown = 1;
	}
	else if (CP_Input_KeyTriggered(KEY_UP)) {

		selectedEnemy -= 1;
		upDown = -1;
	}


	switch (selectedEnemy)
	{
	case 1:
		if (enemyOne.health < 1) {
			selectedEnemy += upDown;
			break;
		}
		characterSelectY = enemyOne.yPosition;
		characterSelectX = enemyOne.xPosition;
		break;
	case 2:
		if (enemyTwo.health < 1) {
			selectedEnemy += upDown;
			break;
		}
		characterSelectY = enemyTwo.yPosition;
		characterSelectX = enemyTwo.xPosition;
		break;
	case 3:
		if (enemyThree.health < 1) {
			selectedEnemy += upDown;
			break;
		}
		characterSelectY = enemyThree.yPosition;
		characterSelectX = enemyThree.xPosition;
		break;
	case 4:
		selectedEnemy = 1;
		break;
	case 0:
		selectedEnemy = 3;
		break;
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
				character_action_attack(_player, &enemyOne);
				break;
			case 2:
				character_action_attack(_player, &enemyTwo);
				break;
			case 3:
				character_action_attack(_player, &enemyThree);
				break;
			}
			enemySelect = 0;
			characterTurn += 1;
		}
	}
}
void ally_Select(struct Character* _player) {

	float time;
	if (CP_Input_KeyTriggered(KEY_DOWN)) {

		selectedAlly += 1;
		upDown = 1;
	}
	else if (CP_Input_KeyTriggered(KEY_UP)) {

		selectedAlly -= 1;
		upDown = -1;
	}


	switch (selectedAlly)
	{
	case 1:
		if (playerOne.health < 1) {
			selectedAlly += upDown;
			break;
		}
		characterSelectY = playerOne.yPosition;
		characterSelectX = playerOne.xPosition;
		break;
	case 2:
		if (playerTwo.health < 1) {
			selectedAlly += upDown;
			break;
		}
		characterSelectY = playerTwo.yPosition;
		characterSelectX = playerTwo.xPosition;
		break;
	case 3:
		if (playerThree.health < 1) {
			selectedAlly += upDown;
			break;
		}
		characterSelectY = playerThree.yPosition;
		characterSelectX = playerThree.xPosition;
		break;
	case 4:
		selectedAlly = 1;
		break;
	case 0:
		selectedAlly = 3;
		break;
	}


	if (delay) {
		time = CP_System_GetSeconds();
		delay = 0;
	}
	else
		time = 0;
	if (CP_System_GetSeconds() - time > 0.5) {

		if (CP_Input_KeyTriggered(KEY_ENTER)) {
			switch (selectedAlly) {
			case 1:
				character_action_heal(_player, &playerOne);
				break;
			case 2:
				character_action_heal(_player, &playerTwo);
				break;
			case 3:
				character_action_heal(_player, &playerThree);
				break;
			}
			allySelect = 0;
			characterTurn += 1;
		}
	}
}







void enemy_Turn(struct Character _enemy) {

	enemyActionChoice = (rand() % 2) + 1;


	if (enemyActionChoice == 1) {

		int enemyAttackChoice = (rand() % 3) + 1;

		switch (enemyAttackChoice) {
		case 1: 
			character_action_attack(&enemyOne, &playerOne);
			break;
		case 2:
			character_action_attack(&enemyOne, &playerTwo);
			break;
		case 3:
			character_action_attack(&enemyOne, &playerThree);
			break;
		}

	}
	else if (enemyActionChoice == 2) {
		int enemyHealChoice = (rand() % 3) + 1;

		switch (enemyHealChoice) {
		case 1:
			character_action_heal(&enemyOne, &enemyOne);
			break;
		case 2:
			character_action_heal(&enemyOne, &enemyTwo);
			break;
		case 3:
			character_action_heal(&enemyOne, &enemyThree);
			break;
		}
	}
	characterTurn += 1;
	actionSelect = 1;
}

void player_Turn(struct Character* _character) {

	switch (characterTurn) {
	case 1:
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Graphics_DrawRect(100, 100, 150, 75);
		CP_Graphics_DrawRect(100, 200, 150, 75);
		CP_Graphics_DrawRect(100, 300, 150, 75);

		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
		CP_Font_DrawText("ATTACK", 100, 100);
		CP_Font_DrawText("DEFEND", 100, 200);
		CP_Font_DrawText("REST", 100, 300);


		break;

	case 3:
		
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Graphics_DrawRect(100, 100, 150, 75);
		CP_Graphics_DrawRect(100, 200, 150, 75);
		CP_Graphics_DrawRect(100, 300, 150, 75);

		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
		CP_Font_DrawText("ATTACK", 100, 100);
		CP_Font_DrawText("HEAL", 100, 200);
		CP_Font_DrawText("MEDITATE", 100, 300);

		break;

	case 5:
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Graphics_DrawRect(100, 100, 150, 75);
		CP_Graphics_DrawRect(100, 200, 150, 75);
		CP_Graphics_DrawRect(100, 300, 150, 75);

		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
		CP_Font_DrawText("ATTACK", 100, 100);
		CP_Font_DrawText("BACK STAB", 100, 200);
		CP_Font_DrawText("STEALTH", 100, 300);
		break;
	}

	if (actionSelect) {

		buttonSelectOpacity = 255;
		button_Select(_character);
		CP_Image_Draw(CP_Image_Load("./Assets/button_select.png"), 100, selectButtonY, 128 * 1.5, 128 * 1.5, 255);
		buttonSelectOpacity = 0;
	}
	if (enemySelect) {

		enemySelectOpacity = 255;
		enemy_Select(_character);
		CP_Image_Draw(CP_Image_Load("./Assets/character_select.png"), characterSelectX, characterSelectY, 128 * 1.5, 128 * 1.5, 255);
		enemySelectOpacity = 0;
	}

	if (allySelect) {
		enemySelectOpacity = 255;
		ally_Select(_character);
		CP_Image_Draw(CP_Image_Load("./Assets/character_select.png"), characterSelectX, characterSelectY, 128 * 1.5, 128 * 1.5, 255);
		enemySelectOpacity = 0;

	}

}




void draw_characters() {
	if (playerOne.health > 0) {
		CP_Image_Draw(CP_Image_Load("./Assets/its merely a flesh wound.png"), playerOne.xPosition, playerOne.yPosition, 256, 256, 255);
	}

	if (playerTwo.health > 0) {
		CP_Image_Draw(CP_Image_Load("./Assets/YOU SHALL NOT PASS.png"), playerTwo.xPosition, playerTwo.yPosition, 256, 256, 255);
	}

	if (playerThree.health > 0) {
		CP_Image_Draw(CP_Image_Load("./Assets/sneak sneak.png"), playerThree.xPosition, playerThree.yPosition, 656, 106, 255);
	}

	if (enemyOne.health > 0) {
		CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), enemyOne.xPosition, enemyOne.yPosition, 256, 256, 255);
	}

	if (enemyTwo.health > 0) {
		CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), enemyTwo.xPosition, enemyTwo.yPosition, 256, 256, 255);
	}

	if (enemyThree.health > 0) {
		CP_Image_Draw(CP_Image_Load("./Assets/s n o w m e n e m y.png"), enemyThree.xPosition, enemyThree.yPosition, 256, 256, 255);
	}

}




void turn_manager() {



	switch (characterTurn) {
	case 1:
		player_Turn(&playerOne);

		break;
	case 2:
		enemy_Turn(enemyOne);

		break;
	case 3:
		player_Turn(&playerTwo);

		break;
	case 4:
		enemy_Turn(enemyTwo);

		break;
	case 5:
		player_Turn(&playerThree);

		break;
	case 6:
		enemy_Turn(enemyThree);

		break;
	default:
		characterTurn = 1;
	}
}






void debug() {
	CP_Settings_TextSize(30);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_MIDDLE);
	char buffer[50] = { 0 };
	sprintf_s(buffer, _countof(buffer), "tank health: %d\ntank def: %.2f", playerOne.health, playerOne.defense);
	CP_Font_DrawText(buffer, 10.f, 400);
	sprintf_s(buffer, _countof(buffer), "wizard health: %d\nwizard mana: %d", playerTwo.health, playerTwo.mana);
	CP_Font_DrawText(buffer, 10.f, 450);
	sprintf_s(buffer, _countof(buffer), "rogue health: %d\nrogue mana: %d", playerThree.health, playerThree.mana);
	CP_Font_DrawText(buffer, 10.f, 500);
	sprintf_s(buffer, _countof(buffer), "enemy 1 health: %d\nenemy 1 mana: %d", enemyOne.health, enemyOne.mana);
	CP_Font_DrawText(buffer, 10.f, 550);
	sprintf_s(buffer, _countof(buffer), "enemy 2 health: %d\nenemy 2 mana: %d", enemyTwo.health, enemyTwo.mana);
	CP_Font_DrawText(buffer, 10.f, 600);
	sprintf_s(buffer, _countof(buffer), "enemy 3 health: %d\nenemy 2 mana: %d", enemyThree.health, enemyThree.mana);
	CP_Font_DrawText(buffer, 10.f, 650);
	sprintf_s(buffer, _countof(buffer), "Turn: %d\nenemyTurn: %d\nactionSelect: %d", characterTurn, enemyTurn, selectedAction);
	CP_Font_DrawText(buffer, 10.f, 700);
	CP_Settings_TextSize(45);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);

}
