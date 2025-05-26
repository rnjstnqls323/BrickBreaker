#pragma once

class Life :public CircleCollider
{
private:
	const int VERTEX_SIZE = 64;
public:
	Life();
	~Life();

	void Update();
private:
	void MakeMesh() override;
};