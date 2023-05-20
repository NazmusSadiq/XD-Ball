#include "AI_Paddle.h"

AI_Paddle::AI_Paddle(double x, double y)
{
	AIPaddlePosition.x = x;
	AIPaddlePosition.y = y;
	AIPaddleObject.setSize(Vector2f(150, 10));
	AIPaddleObject.setFillColor(Color::Red);
	AIPaddleObject.setPosition(AIPaddlePosition);
}

Vector2f AI_Paddle::getAIPaddlePosition()
{
	return AIPaddlePosition;
}

RectangleShape AI_Paddle::getAIPaddleObject()
{
	return AIPaddleObject;
}

FloatRect AI_Paddle::getAIPAddleFloatRect()
{
	return AIPaddleObject.getGlobalBounds();
}
void AI_Paddle::AIPaddleReset()
{
	AIPaddlePosition.x = WindowWidth / 2-75;
	AIPaddlePosition.y = 10;
}
void AI_Paddle::moveAIPaddleLeft()
{
	if (AIPaddlePosition.x >= 0)
		AIPaddlePosition.x -= AIPaddleSpeed;
}

void AI_Paddle::moveAIPaddleRight()
{
	if (AIPaddlePosition.x <= WindowWidth-AIPaddleObject.getSize().x)
		AIPaddlePosition.x += AIPaddleSpeed;
}

void AI_Paddle::update()
{
	AIPaddleObject.setPosition(AIPaddlePosition);
}

void AI_Paddle::Rebound()
{
}

void AI_Paddle::AIPaddleSpeedReverse()
{
	AIPaddleSpeed *= -1;
}
