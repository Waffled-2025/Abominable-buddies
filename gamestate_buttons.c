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
#include "gamestate_buttons.h"




int button_func(float colliderX, float colliderY, float rectXDimension, float rectYDimension, float rectXPos, float rectYPos) {
	return ((colliderX < (rectXPos + (rectXDimension / 2)) && colliderX >(rectXPos - (rectXDimension / 2))) &&
		(colliderY < (rectYPos + (rectYDimension / 2)) && colliderY >(rectYPos - (rectYDimension / 2))));
}
