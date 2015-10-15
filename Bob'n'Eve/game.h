#pragma once

#include "Renderer.h"

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

};
