//---------------------------------------------------------
// file:	gamestate_template.h
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	header file for template gamestate
//
// documentation link:
// https://github.com/DigiPen-Faculty/CProcessing/wiki
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#pragma once
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

void character_action_attack(struct Character* _character1, struct Character* _character2);
void character_action_heal(struct Character* _characterHealer, struct Character* _characterHealed);
void character_action_rest(struct Character* _character);
void character_action_defend(struct Character* _character);
void character_action_meditate(struct Character* _character);