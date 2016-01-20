#pragma once

#include "Renderer.h"
#include "PhysicManager.h"
#include "LeaderBoard.h"
#include "MainMenu.h"

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

	void Pause(Map* view);
	void Resume(Map* view);

protected:
	void Loop();
	void GetInput();

private:

	bool paused_;
	LeaderBoard* board_;
	Renderer renderer_;
	MenuBase* menu_;
};
