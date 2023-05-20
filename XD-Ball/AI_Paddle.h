#pragma once
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Window.hpp>

#define WindowWidth 960
#define WindowHeight 720

using namespace sf;
class AI_Paddle
{

private:
	double AIPaddleSpeed = 0.95;
	RectangleShape AIPaddleObject;

public:
	Vector2f AIPaddlePosition;
	AI_Paddle(double x, double y);
	Vector2f getAIPaddlePosition();
	RectangleShape getAIPaddleObject();
	FloatRect getAIPAddleFloatRect();

	void AIPaddleReset();
	void moveAIPaddleLeft();
	void moveAIPaddleRight();
	void update();
	void Rebound();
	void AIPaddleSpeedReverse();
};

