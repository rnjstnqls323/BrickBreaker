#include "Framework.h"

CircleCollider::CircleCollider(float radius) : radius(radius)
{
	type = Type::Circle;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::MakeMesh()
{
	vertices.reserve(VERTEX_SIZE + 1);

	float stepAngle = XM_2PI / VERTEX_SIZE;

	for (int i = 0; i <= VERTEX_SIZE; i++)
	{
		float x = cos(stepAngle * i) * radius;
		float y = sin(stepAngle * i) * radius;

		vertices.emplace_back(x, y);
	}
}

bool CircleCollider::IsPointCollision(const Vector2& point)
{
	float distance = (GetGlobalPosition() - point).Magnitude();

	return distance <= Radius();
}

bool CircleCollider::IsRectCollision(RectCollider* rect, Vector2* overlap)
{
    Vector2 circleCenter = GetLocalPosition(); // 원 중심
    Vector2 rectCenter = rect->GetLocalPosition();
    Vector2 rectHalfSize = rect->Size() * 0.5f;

    float left = rectCenter.x - rectHalfSize.x;
    float right = rectCenter.x + rectHalfSize.x;
    float bottom = rectCenter.y - rectHalfSize.y;
    float top = rectCenter.y + rectHalfSize.y;

    // 가장 가까운 점 (클램핑)
    float closestX = max(left, min(circleCenter.x, right));
    float closestY = max(bottom, min(circleCenter.y, top));

    Vector2 closestPoint = { closestX, closestY };

    // 충돌 벡터: 공 중심에서 가장 가까운 점까지
    Vector2 collisionVec = circleCenter - closestPoint;

    // 거리 제곱 계산
    float distanceSquared = collisionVec.x * collisionVec.x + collisionVec.y * collisionVec.y;

    if (distanceSquared < radius * radius)
    {
        if (overlap != nullptr)
        {
            Vector2 dir = rectCenter - circleCenter;
            dir.Normalize();
            *overlap = dir;
        }
        return true;
    }

    return false;
}

bool CircleCollider::IsCircleCollision(CircleCollider* circle)
{
	float distance = Vector2::Distance(circle->GetGlobalPosition(), GetGlobalPosition());

	return distance <= (Radius() + circle->Radius());
}
