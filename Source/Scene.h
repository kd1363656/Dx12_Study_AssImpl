#pragma once

class Scene
{
public:

	Scene() = default;
	~Scene() = default;

	bool Init(); // ‰Šú‰»

	void Update(); // XVˆ—

	void Draw(); // •`‰æˆ—

private:

};

extern Scene* g_Scene;