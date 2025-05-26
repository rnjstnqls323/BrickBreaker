#include "Framework.h"

Brick::Brick() :RectCollider({ 68, 30 })
{
    halfSize = Size() * 0.5f;
    Init();
    tag = "Brick";
}

Brick::~Brick()
{
}

void Brick::Update()
{
    SettingColor(type);
    UpdateWorld();
}

void Brick::SettingColor(ColorType color)
{
    switch (color)
    {
    case Red:
        SetColor(1, 0, 0);
        break;
    case Orange:
        SetColor(1, 0.5, 0);
        break;
    case Yellow:
        SetColor(1, 1, 0);
        break;
    case Green:
        SetColor(0, 1, 0);
        break;
    case Gray:
        SetColor(0.8, 0.8, 0.8);
        break;
    }
}

void Brick::MakeMesh()
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
