#ifndef _GAME_H_
#define _GAME_H_

#include "view.h"

class game
{
protected:
	view my_view;
	void loop();
	void get_input();
public:
	const static int FPS = 60;
	const float MS_PER_UPDATE = (1000.0f / FPS);

	game();
	void start();
	void stop();
};

#endif