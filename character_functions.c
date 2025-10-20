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
#include "gamestate_template.h"
#include "math.h"
#include "stdlib.h"

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
	int defended;
};

void character_action_attack(struct Character* _character1, struct Character* _character2) { // function for attacks: (attacker --- 0 means player attacks enemy, 1 is other
	_character2->health -= (int)((float)((rand() % ((10 + _character1->attackDamage) - _character1->attackDamage) + _character1->attackDamage)) * (1 - _character2->defense));
	if (_character2->defended) {
		_character2->defended = 0;
	}
	return;
}
void character_action_heal(struct Character* _characterHealer, struct Character* _characterHealed) {
	_characterHealed->health += (rand() % ((5 + _characterHealer->attackDamage) - _characterHealer->attackDamage) + _characterHealer->attackDamage);
	_characterHealer->mana -= 20;
}
void character_action_rest(struct Character* _character) {
	_character->health += 5;
	_character->mana += 5;
}
void character_action_defend(struct Character* _character) {
	_character->defense += 0.5;
	_character->defended = 1;
}
void character_action_meditate(struct Character* _character) {
	_character->mana += _character->manaRegen;
}

