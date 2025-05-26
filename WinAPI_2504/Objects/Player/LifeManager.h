#pragma once

class LifeManager : public Singleton<LifeManager> {
	friend class Singleton;

private:
	LifeManager();
	~LifeManager();


private:
	vector<CircleCollider*> life;
};