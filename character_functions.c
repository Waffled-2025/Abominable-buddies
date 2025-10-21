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

	int health;
	int maxHealth;

	int mana;
	int maxMana;
	int manaRegen;

	float defense;

	int attackDamage;

	float xPosition;
	float yPosition;

	int defended;

	int alive;
};

void character_action_attack(struct Character* _character1, struct Character* _character2) { // function for attacks, character1 damages character2 for (attackDmg) up to (attackDmg+10)
	_character2->health -= (int)((float)((rand() % ((10 + _character1->attackDamage) - _character1->attackDamage) + _character1->attackDamage)) * (1 - _character2->defense));
	if (_character2->defended) { // Resetting defense
		_character2->defended = 0;
		_character2->defense -= 0.5;
	}
	if (_character2->health < 0) { // Making sure health doesnt go into negatives
		_character2->health = 0;
	}
	return;
}
void character_action_heal(struct Character* _characterHealer, struct Character* _characterHealed) { // Heal character for (attackDmg) up to (attackDmg+5)
	if (_characterHealer->mana < 20) { return; }
	_characterHealed->health += (rand() % ((5 + _characterHealer->attackDamage) - _characterHealer->attackDamage) + _characterHealer->attackDamage);
	_characterHealer->mana -= 20;
	if (_characterHealed->health > _characterHealed->maxHealth) // NO OVERHEALTH FOR THE LOVE OF GOD
		_characterHealed->health = _characterHealed->maxHealth;
}
void character_action_rest(struct Character* _character) {
	_character->health += 5;
	_character->mana += 5;
	if (_character->health > _character->maxHealth) // No. OVERLHEALTH
		_character->health = _character->maxHealth;
	if (_character->mana > _character->maxMana) // No extra mana
		_character->mana = _character->maxMana;
}
void character_action_defend(struct Character* _character) { // Increases character defense by 50%
	if (!_character->defended)
		
		_character->defense += 0.5;
		_character->defended = 1;
}
void character_action_meditate(struct Character* _character) { // m a n a & m a g i c
	_character->mana += _character->manaRegen; // mana increases by mana regen
	if (_character->mana > _character->maxMana)
		_character->mana = _character->maxMana;
}
void character_action_bury(struct Character* _character) {
	_character->defense = 1;
}
void character_action_backstab(struct Character* _character, struct Character* _enemy, int buried) {
	if (buried == 1) {
		_enemy->health -= 30;
	}
}
