#pragma once

class Entity;

class Renderer;

class Game
{
private:
	Renderer renderer_;
	Entity* view_;

protected:
	void Loop();
	void GetInput();

public:
	const static int FPS = 60;
	const float MS_PER_UPDATE = (1000.0f / FPS);

	Game();
	virtual ~Game();

	void Start();
	void Stop();
};
