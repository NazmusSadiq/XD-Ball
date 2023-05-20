#pragma once
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Window.hpp>

#define WindowWidth 960
#define WindowHeight 720

using namespace sf;
class Paddle
{
private:
	double paddlespeed = 0.95;
	RectangleShape Paddleobject;

public:
	Vector2f paddleposition;
	Paddle(double x, double y);
	Vector2f getPaddlePosition();
	RectangleShape getPaddleObject();
	FloatRect getPaddleFloatRect();

	void PaddleReset();
	void movePaddleLeft();
	void movePaddleRight();
	void update();
};

