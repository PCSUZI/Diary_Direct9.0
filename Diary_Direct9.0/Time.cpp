#include "Time.h"
#include <time.h>


Time::Time()
{
	Game_over = false;
	g_time = 30;
}


Time::~Time()
{
}

void Time::GameTime(float time)
{
	if (g_time <= 0) {
		Game_over = true;
		return;
	}

	static float interval = 0;

	interval += time;
	if (interval >= 1)
	{
		g_time--;
		interval -= 1;
	}
}

void Time::setGameTime(int time)
{
	g_time = time;
}
