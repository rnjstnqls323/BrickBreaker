#pragma once

class Ball : public CircleCollider
{
private:
	const int VERTEX_SIZE = 64;

public:
	Ball();
	~Ball();

	void Update();
	void ChangeSpawn(Vector2 pos);

	bool IsMove() { return isMove; }
	void SetIsMove(bool move) { isMove = move; }
	void AddSpeed(int speed) { this->speed += speed; }

	void ChangeCrashDirection(Vector2 overlap){ direction = overlap * -1; }
	void SetUpDirection() { direction = Vector2::Up(); }
	bool IsRectCollision(RectCollider* rect, Vector2* overlap, string tag);

private:
	void MakeMesh() override;
	void Move();
	void DownSpace();
	void CrashWall();
	

private:
	bool isMove = false;
	int speed = 400;

	Vector2 direction;

	
};