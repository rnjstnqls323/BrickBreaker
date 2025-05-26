#include "Framework.h"
#include "Item.h"

Item::Item():CircleCollider(15)
{
    Init();
    isActive = true;
}

Item::~Item()
{
}

void Item::Update()
{
    Move();
    UpdateWorld();

    if (GetGlobalPosition().y <= 0)
        isActive = false;
}

void Item::MakeMesh()
{
    vertices.clear();
    indices.clear();


    vertices.emplace_back(0.0f, 0.0f); // 중심점

    float stepAngle = XM_2PI / VERTEX_SIZE;

    for (int i = 0; i <= VERTEX_SIZE; i++)
    {
        float x = cos(stepAngle * i) * radius;
        float y = sin(stepAngle * i) * radius;

        vertices.emplace_back(x, y);
    }

    for (int i = 1; i <= VERTEX_SIZE; i++)
    {
        indices.emplace_back(0);


        // 마지막 삼각형은 다시 첫 점(1)으로 연결
        if (i != VERTEX_SIZE)
            indices.emplace_back(i + 1);
        else
            indices.emplace_back(1);

        indices.emplace_back(i);
    }
    SetColor(1.0f, 0.8f, 0.6f);
}

void Item::Move()
{
    SetLocalPosition(GetLocalPosition() + direction * SPEED * DELTA);
}
