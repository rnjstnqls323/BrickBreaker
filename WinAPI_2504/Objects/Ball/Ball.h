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

	void ChangeCrashDirection(Vector2 overlap){ direction = overlap * -1; }
private:
	void MakeMesh() override;
	void Move();
	void DownSpace();
	void CrashWall();
	

private:
	bool isMove = false;
	int speed = 300;

	Vector2 direction;

	
};