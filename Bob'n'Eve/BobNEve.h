#pragma once

class Game;

class BobNEve
{
public:
	BobNEve();
	virtual ~BobNEve();

	void Init();
	void Launch();
	void Start();

protected:
	Game* game_;
};
