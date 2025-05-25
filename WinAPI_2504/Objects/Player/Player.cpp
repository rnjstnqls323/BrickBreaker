#include "Framework.h"

Player::Player() :RectCollider({ 100,30 })
{
	SetLocalPosition(SPAWN_POINT);
    Init();
}

Player::~Player()
{
}

void Player::Update()
{
    localPosition = GetLocalPosition();
    Move();
    UpdateWorld();
}

void Player::MakeMesh()
{

    vertices.emplace_back(-halfSize.x, +halfSize.y);
    vertices.emplace_back(+halfSize.x, +halfSize.y);
    vertices.emplace_back(+halfSize.x, -halfSize.y);
    vertices.emplace_back(-halfSize.x, -halfSize.y);

    indices.emplace_back(0);
    indices.emplace_back(1);
    indices.emplace_back(2);

    indices.emplace_back(2); 
    indices.emplace_back(3);
    indices.emplace_back(0);

    SetColor(0.55f, 0.6f, 0.65f);
}

void Player::Move()
{
    
    if (Input::Get()->IsKeyPress(VK_UP) && localPosition.y < SPAWN_POINT.y - halfSize.y)
    {
        Translate(Vector2::Up() * speed * DELTA);
    }
    if (Input::Get()->IsKeyPress(VK_DOWN) && localPosition.y > 0 + halfSize.y)
    {
        Translate(Vector2::Down() * speed * DELTA);
    }
    if (Input::Get()->IsKeyPress(VK_RIGHT) && localPosition.x < SCREEN_WIDTH - halfSize.x)
    {
        Translate(Vector2::Right() * speed * DELTA);
    }
    if (Input::Get()->IsKeyPress(VK_LEFT) && localPosition.x > 0 + halfSize.x)
    {
        Translate(Vector2::Left() * speed * DELTA);
    }
}

