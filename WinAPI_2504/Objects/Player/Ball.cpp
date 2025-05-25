#include "Framework.h"

Ball::Ball() :CircleCollider(100)
{
    SetLocalPosition(200, 200);
	Init();
    isActive = true;
}

Ball::~Ball()
{
    
}

void Ball::Update()
{
    UpdateWorld();


    Vector2 pos = GetGlobalPosition();
    ImGui::Text("Position: (%.1f, %.1f)", pos.x, pos.y);

    ImGui::Text("Is Active: %s", isActive ? "True" : "False");

    ImGui::End();
}

void Ball::MakeMesh()
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
        indices.emplace_back(i);

        // 마지막 삼각형은 다시 첫 점(1)으로 연결
        if (i != VERTEX_SIZE)
            indices.emplace_back(i + 1);
        else
            indices.emplace_back(1);
    }
    SetColor(0.7f, 0.7f, 0.9f); // 예: 연보라/회색 느낌
}
