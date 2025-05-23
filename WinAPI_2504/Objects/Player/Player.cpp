#include "Framework.h"

Player::Player() :RectCollider({ 150,50 })
{
	setCenter(GetGlobalPosition());
}

Player::~Player()
{
}

