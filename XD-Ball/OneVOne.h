#pragma once
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<string>
#include <cstdlib>
#include <sstream>
#include "Menu.h"
#include "AI_Paddle.h"
#include "Paddle.h"
#include "Ball.h"

#define WindowWidth 960
#define WindowHeight 720
#define PointLimit 5

using namespace sf;
class OneVOne
{
public:
	OneVOne(RenderWindow& Play1V1, Event& event, Paddle& paddle1, Paddle& paddle2, Ball& ball, RectangleShape& bg,Texture& pup, Texture& pdn);
};

