#pragma once

class Game;

class BobNEve
{
protected:
	Game* game_;
public:
	BobNEve();
	virtual ~BobNEve();

	void Init();
	void Launch();
	void Start();
};
