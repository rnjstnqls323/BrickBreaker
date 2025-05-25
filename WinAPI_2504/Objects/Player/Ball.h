#pragma once

class Ball : public CircleCollider
{
private:
	const int VERTEX_SIZE = 3;

public:
	Ball();
	~Ball();

	void Update();
private:
	void MakeMesh() override;

};