#pragma once
class Time
{
public:
	Time();
	~Time();

	void GameTime(float time);
	bool Game_over;
	int g_time;//게임시간
	void setGameTime(int time);
	
};

