#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<SFML\Window.hpp>
#include "Paddle.h"
#include "AI_Paddle.h"

#define PointLimit 5
#define WindowWidth 960
#define WindowHeight 720

#define defaultballvelocity 1.35f

using namespace sf;
class Ball
{
private:
    Clock clk,boxclk;
    Time interval,elapsed=milliseconds(0);
    bool generated = false;
    CircleShape BallObject;
    Vector2f ballPosition,boxPosition;
    RectangleShape BoxObject;
    int index=-1;
public:
    CircleShape getBallObject();
    RectangleShape getBoxObject();
    Ball(double x, double y, RenderWindow & window,Texture& tex);
    FloatRect getBallFloatRect();
    FloatRect BoxRect;
    void reboundSides();
    void passTopAI(Paddle &paddle,AI_Paddle &aipaddle);
    void passTop(Paddle &paddle1, Paddle &paddle2);
    Vector2f getBallPosition;
    void passBottomAI(Paddle &paddle, AI_Paddle &aipaddle);
    void passBottom(Paddle& paddle1, Paddle& paddle2);
    int playerscore = 0, opponentscore = 0;
    void reboundPaddle(Paddle paddle);
    void reboundAIPaddle(AI_Paddle aipaddle);
    void BoxFunctions(RenderWindow & window,Ball& ball,Texture& tex0,Texture& tex1);
    void update();
    double ballVelocityX = 0.0f;
    double ballVelocityY = defaultballvelocity;
    void stop();
    void go();
    Sound loser,winner,boxpop,boxgone;
    SoundBuffer lbfr,wbfr,bxpbfr,bxgbfr;
};

