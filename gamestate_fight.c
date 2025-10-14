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
	int manaRegen;
	float defense;
	int attackDamage;
	int xPosition;
	int yPosition;
} Character;






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
	CP_System_Fullscreen();
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));

	Character playerOne = { "Wizard", CP_Image_Load("./Assets/YOU SHALL NOT PASS.png"), 80, 100, 30, .0f, 10, 200, 300}; // Initilization of the wizard player character
	Character playerTwo = { "Tank",  CP_Image_Load("./Assets/Its merely a flesh wound.png"), 120, 50, 15, .3f, 5, 200, 800 }; // Initilization of the tank player character
	Character playerThree = { "Rogue",  CP_Image_Load("./Assets/sneak sneak.png"), 90, 50, 0, .1f, 15, 200, 1300 }; // rogue

	Character enemyOne = { "Stupid idiot 1",  CP_Image_Load("./Assets/s n o w m e n e m y.png"), 100, 100, 0.2f, 10, 900, 300 };
	Character enemyOne = { "Stupid idiot 2",  CP_Image_Load("./Assets/s n o w m e n e m y.png"), 100, 100, 0.2f, 10, 900, 800 };
	Character enemyOne = { "Stupid idiot 3",  CP_Image_Load("./Assets/s n o w m e n e m y.png"), 100, 100, 0.2f, 10, 900, 1300 };


	


	
	
}

void gamestate_fight_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(100, 100, 100, 0));


	
}


void gamestate_fight_exit(void)
{
}
