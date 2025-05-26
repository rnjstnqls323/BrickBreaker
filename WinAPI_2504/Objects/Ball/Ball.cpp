#include "Framework.h"

Ball::Ball() :CircleCollider(10)
{
	Init();
    isActive = true;
    direction = Vector2::Up();
}

Ball::~Ball()
{
    
}

void Ball::Update()
{
    if(!isMove)
        DownSpace();

    if (isMove)
    {
        Move();         // 위치를 먼저 이동시키고
        CrashWall();    // 벽과 충돌 검사 및 반전
    }

    UpdateWorld();
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


        // 마지막 삼각형은 다시 첫 점(1)으로 연결
        if (i != VERTEX_SIZE)
            indices.emplace_back(i + 1);
        else
            indices.emplace_back(1);

        indices.emplace_back(i);
    }
    SetColor(0.7f, 0.7f, 0.9f); // 예: 연보라/회색 느낌
}

void Ball::Move()
{
    if (!isMove)
        return;
    SetLocalPosition(GetLocalPosition() + direction * speed * DELTA);
    
}

void Ball::DownSpace()
{
    if (Input::Get()->IsKeyDown(VK_SPACE))
        isMove = true;
}

void Ball::CrashWall()
{
    Vector2 pos = GetLocalPosition();

    //if (pos.x <= 0 + radius || pos.x >= SCREEN_WIDTH - radius || pos.y <= 0 + radius || pos.y >= SCREEN_HEIGHT - radius)
    if(pos.x<=0+radius || pos.x >= SCREEN_WIDTH - radius)
    {
        direction.x = direction.x * -1;
    }
    if (pos.y >= SCREEN_HEIGHT - radius)
    {
        direction.y = direction.y * -1;
    }
    if (pos.y <= 0)
    {
        BallManager::Get()->SetBallStart();
        int life = LifeManager::Get()->GetLifeSize() - 1;
        LifeManager::Get()->SetLifeSize(life);
    }
}

void Ball::ChangeSpawn(Vector2 pos)
{
    SetLocalPosition(pos);
}
