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
#include "characterUI.h"
#include "gamestate_fight.h"

void UI_healthbar(struct Character* _character) {
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Graphics_DrawRect(_character->xPosition, _character->yPosition-128, 100, 15);

	CP_Settings_RectMode(CP_POSITION_CORNER);
	CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));

	CP_Graphics_DrawRect(_character->xPosition-50, _character->yPosition-7.5f - 128, (float)_character->health / (_character->health/100), 15);
	CP_Settings_RectMode(CP_POSITION_CENTER);

}