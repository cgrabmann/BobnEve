#pragma once

#include "Renderer.h"
#include <Box2D/Dynamics/b2World.h>

class Entity;

class Game
{
public:
	const static int FPS = 60;
	const float MS_PER_UPDATE = (1000.0f / FPS);

	Game();
	virtual ~Game();

	void Start();
	void Stop();

protected:
	void Loop();
	void GetInput();

private:
	Renderer renderer_;
	Entity* view_;
	b2World world_;

};
