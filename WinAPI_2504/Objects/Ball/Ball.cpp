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
        Move();         // ��ġ�� ���� �̵���Ű��
        CrashWall();    // ���� �浹 �˻� �� ����
    }

    UpdateWorld();
}

bool Ball::IsRectCollision(RectCollider* rect, Vector2* overlap, string tag)
{
    Vector2 circleCenter = GetLocalPosition(); // �� �߽�
    Vector2 rectCenter = rect->GetLocalPosition();
    Vector2 rectHalfSize = rect->Size() * 0.5f;

    float left = rectCenter.x - rectHalfSize.x;
    float right = rectCenter.x + rectHalfSize.x;
    float bottom = rectCenter.y - rectHalfSize.y;
    float top = rectCenter.y + rectHalfSize.y;

    // ���� ����� �� (Ŭ����)
    float closestX = max(left, min(circleCenter.x, right));
    float closestY = max(bottom, min(circleCenter.y, top));

    Vector2 closestPoint = { closestX, closestY };

    // �浹 ����: �� �߽ɿ��� ���� ����� ������
    Vector2 collisionVec = circleCenter - closestPoint;

    // �Ÿ� ���� ���
    float distanceSquared = collisionVec.x * collisionVec.x + collisionVec.y * collisionVec.y;

    if (distanceSquared < radius * radius)
    {
        if (overlap != nullptr && tag == "Bar")
        {
            Vector2 dir = rectCenter - circleCenter;
            dir.Normalize();
            *overlap = dir;
        }
        else if (overlap != nullptr && tag == "Brick")
        {
            Vector2 dir = { direction.x * -1, direction.y };

            *overlap = dir; 
        }
        return true;
    }

    return false;
}

void Ball::MakeMesh()
{
    vertices.clear();
    indices.clear();

    
    vertices.emplace_back(0.0f, 0.0f); // �߽���

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


        // ������ �ﰢ���� �ٽ� ù ��(1)���� ����
        if (i != VERTEX_SIZE)
            indices.emplace_back(i + 1);
        else
            indices.emplace_back(1);

        indices.emplace_back(i);
    }
    SetColor(0.7f, 0.7f, 0.9f); // ��: ������/ȸ�� ����
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
