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
#include "character_functions.h"
void gamestate_fight_init(void);
void gamestate_fight_update(void);
void gamestate_fight_exit(void);
int battleCompleted;
int gameLost;
void reset_characters(struct Character* _playerOne, struct Character* _playerTwo, struct Character* _playerThree);