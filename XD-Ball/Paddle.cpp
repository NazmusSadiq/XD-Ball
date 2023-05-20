#include "Paddle.h"

Paddle::Paddle(double x, double y)
{
	paddleposition.x = x;
	paddleposition.y = y;
	Paddleobject.setSize(Vector2f(150, 10));
	Paddleobject.setPosition(paddleposition);
	Paddleobject.setFillColor(Color::Blue);
}

Vector2f Paddle::getPaddlePosition()
{
	return paddleposition;
}

RectangleShape Paddle::getPaddleObject()
{
	return Paddleobject;
}

FloatRect Paddle::getPaddleFloatRect()
{
	return Paddleobject.getGlobalBounds();
}

void Paddle::PaddleReset()
{
	paddleposition.x = WindowWidth / 2-75;
	paddleposition.y = WindowHeight - 20;
}

void Paddle::movePaddleLeft()
{
	if (paddleposition.x>=0)
		paddleposition.x -= paddlespeed;
}

void Paddle::movePaddleRight()
{
	if (paddleposition.x<=WindowWidth-Paddleobject.getSize().x)
		paddleposition.x += paddlespeed;
}

void Paddle::update()
{
	Paddleobject.setPosition(paddleposition);
}
