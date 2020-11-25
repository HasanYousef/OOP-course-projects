#pragma once

#include "Enemy.h"

//---------------------------------------------
Coord Enemy::Enemy_Movement()
{
	/* HERE WE HAVE TO ADD THE A* ALGORITHM*/
	return m_Ecoord;
}

//---get---enemy---indexes---------------------
Coord Enemy::Get_E_Coord() const
{
	return m_Ecoord;
}