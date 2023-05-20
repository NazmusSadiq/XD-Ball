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

class Offline_Game
{
    int aipaddlecounter;
public:
<<<<<<< HEAD
	Offline_Game(RenderWindow& PlayOffline, Event& event, Paddle& paddle, AI_Paddle& aipaddle, Ball& ball,RectangleShape & bg,Texture& pup,Texture& pdn,Texture& balltex,Texture& fb);
=======
	Offline_Game(RenderWindow& PlayOffline, Event& event, Paddle& paddle, AI_Paddle& aipaddle, Ball& ball,RectangleShape & bg,Texture& pup,Texture& pdn);
>>>>>>> 99c76fd94d0349569df49390a80fde30e3ac6c9e
};
