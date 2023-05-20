#include "Ball.h"


Ball::Ball(double x, double y,RenderWindow & window,Texture& tex)
{
    ballPosition.x = x;
    ballPosition.y = y;
    BallObject.setRadius(7.0f);
    BallObject.setPosition(ballPosition);
    BallObject.setTexture(&tex);
    window.draw(BallObject);
    lbfr.loadFromFile("losingsound.wav");
    wbfr.loadFromFile("winningsound.wav");
    winner.setBuffer(wbfr);
    loser.setBuffer(lbfr);
}

void Ball::BoxFunctions(RenderWindow& window,Ball& ball,Texture& tex0,Texture& tex1,Texture& balltex,Texture& fb)
{
    elapsed += boxclk.restart();
    interval = seconds(10+rand()%6);
    if (!generated && elapsed>=interval)
    {
        generated = true;
        boxTimer = seconds(0);
        index = rand() % 3;
        if (index == 0)
        {
        boxPosition.x = rand() % (WindowWidth-50);
        boxPosition.y = WindowHeight / 2;
        BoxObject.setSize(Vector2f(50.0f, 75.0f));
        BoxObject.setPosition(boxPosition);
            BoxObject.setTexture(&tex0);
            window.draw(BoxObject);
        }

        else if (index == 1)
        {
            boxPosition.x = rand() % (WindowWidth - 50);
            boxPosition.y = WindowHeight / 2;
            BoxObject.setSize(Vector2f(50.0f, 75.0f));
            BoxObject.setPosition(boxPosition);
            BoxObject.setTexture(&tex1);
            window.draw(BoxObject);
        }
        else if (index == 2)
        {
            BoxObject.setSize(Vector2f(0, 0));
            ball.ballVelocityX *= 1.5;
            ball.ballVelocityY *= 1.5;
            ball.BallObject.setTexture(&fb);
            window.draw(ball.BallObject);
        }
        bxpbfr.loadFromFile("boxpop.wav");
        boxpop.setBuffer(bxpbfr);
        boxpop.play();
        BoxRect = BoxObject.getGlobalBounds();
    }
    if (index == 2 && (generated && elapsed >= interval + seconds(5) || ball.ballPosition.y >= WindowHeight - 5|| ball.ballPosition.y<=2))
    {
        index = -1;
        ball.BallObject.setTexture(&balltex);
        ball.ballVelocityX /= 2;
        if (ballVelocityY > 0)
            ball.ballVelocityY = defaultballvelocity;
        else
            ball.ballVelocityY = -defaultballvelocity;
        window.draw(ball.BallObject);
        generated = false;
        elapsed = milliseconds(0);
        BoxObject.setPosition(-100.0f, -100.0f);
    }
    else if (generated && elapsed>=interval+seconds(7))
    {
        generated = false;
        BoxObject.setPosition(-100.0f, -100.0f);
        elapsed = milliseconds(0);
    }
    if (generated && ball.getBallFloatRect().intersects(BoxRect))
    {
        elapsed = milliseconds(0);
        generated = false;
        bxgbfr.loadFromFile("boxgone.wav");
        boxgone.setBuffer(bxgbfr);
        boxgone.play();
        BoxObject.setPosition(-100.0f, -100.0f);
        if (index == 0) 
        {
            if (ball.ballVelocityY > 0)
                opponentscore++;
            else
                playerscore++;
        }
        else if (index == 1)
        {
            if (ball.ballVelocityY > 0)
                opponentscore--;
            else
                playerscore--;
        }
    }
}
CircleShape Ball::getBallObject()
{
    return BallObject;
}

RectangleShape Ball::getBoxObject()
{
    return BoxObject;
}

FloatRect Ball::getBallFloatRect()
{
    return BallObject.getGlobalBounds();
}

void Ball::reboundSides()
{
    if (ballPosition.x > WindowWidth)
        ballVelocityX *= -1;

    else if (ballPosition.x < 0)
        ballVelocityX *= -1;

}

void Ball::passTopAI(Paddle &paddle, AI_Paddle &aipaddle)
{
    if (ballPosition.y <= 2)
    {
        playerscore++;
        generated = false;
        BoxObject.setPosition(-100.0f, -100.0f);
        elapsed = milliseconds(0);
        if (playerscore == PointLimit)
            winner.play();
        paddle.PaddleReset();
        aipaddle.AIPaddleReset();
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight /2;
        clk.restart();
        if (playerscore < PointLimit)
        {
            while (1)
            {
                if (clk.getElapsedTime().asSeconds() >= 1)
                {
                    break;
                }
            }
        }
        ballVelocityX = 0.0f;
        ballVelocityY = -defaultballvelocity;
        

    }
}

void Ball::passTop(Paddle &paddle1, Paddle &paddle2)
{
    if (ballPosition.y <= 2)
    {
        playerscore++;
        generated = false;
        BoxObject.setPosition(-100.0f, -100.0f);
        elapsed = milliseconds(0);
        if (playerscore == PointLimit)
            winner.play();
        paddle1.PaddleReset();
        paddle2.PaddleReset();
        paddle2.paddleposition.y = 10;
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight / 2;
        clk.restart();
        if (playerscore < PointLimit)
        {
            while (1)
            {
                if (clk.getElapsedTime().asSeconds() >= 1)
                {
                    break;
                }
            }
        }
        ballVelocityX = 0.0f;
        ballVelocityY = -defaultballvelocity;


    }
}

void Ball::passBottomAI(Paddle &paddle, AI_Paddle &aipaddle)
{
    if (ballPosition.y >= WindowHeight - 5)
    {
        opponentscore++;
        generated = false;
        BoxObject.setPosition(-100.0f, -100.0f);
        elapsed = milliseconds(0);
        if(opponentscore==PointLimit)
            loser.play();
        paddle.PaddleReset();
        aipaddle.AIPaddleReset();
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight / 2;
        clk.restart();
        if (opponentscore < PointLimit)
        {
            while (1)
            {
                if (clk.getElapsedTime().asSeconds() >= 1)
                {
                    break;
                }
            }
        }
        ballVelocityX = 0.0f;
        ballVelocityY = defaultballvelocity;
    }
}

void Ball::passBottom(Paddle& paddle1, Paddle& paddle2)
{
    if (ballPosition.y >= WindowHeight - 5)
    {
        opponentscore++;
        generated = false;
        BoxObject.setPosition(-100.0f, -100.0f);
        elapsed = milliseconds(0);
        if (opponentscore == PointLimit)
            winner.play();
        paddle1.PaddleReset();
        paddle2.PaddleReset();
        paddle2.paddleposition.y = 10;
        ballPosition.x = WindowWidth / 2;
        ballPosition.y = WindowHeight / 2;
        clk.restart();
        if (opponentscore < PointLimit)
        {
            while (1)
            {
                if (clk.getElapsedTime().asSeconds() >= 1)
                {
                    break;
                }
            }
        }
        ballVelocityX = 0.0f;
        ballVelocityY = defaultballvelocity;
    }
}

void Ball::reboundPaddle(Paddle paddle)
{
    ballPosition.y -= (ballVelocityY * 30);
    float contact = paddle.paddleposition.x + 75;
    ballVelocityX = (ballPosition.x-contact) * 0.015;
    if (paddle.paddleposition.y > 500)
        ballVelocityY = -(defaultballvelocity-abs(ballVelocityX/4));
    else
        ballVelocityY = defaultballvelocity-abs(ballVelocityX/4);
    if (index == 2)
    {
        ballVelocityX *= 2;
        ballVelocityY *= 2;
    }
}

void Ball::reboundAIPaddle(AI_Paddle aipaddle)
{
    ballPosition.y -= (ballVelocityY * 30);
    float contact = aipaddle.AIPaddlePosition.x + 75;
    ballVelocityX = (ballPosition.x-contact) * 0.015;
    ballVelocityY = defaultballvelocity-abs(ballVelocityX/4);
    if (index == 2)
    {
        ballVelocityX *= 2;
        ballVelocityY *= 2;
    }
}


void Ball::update()
{

    ballPosition.x += ballVelocityX;
    ballPosition.y += ballVelocityY;

    BallObject.setPosition(ballPosition);
}

void Ball::stop()
{
    ballVelocityY = 0;
    ballVelocityX = 0;
}

void Ball::go()
{
    ballPosition.x = WindowWidth/2;
    ballPosition.y = WindowHeight/2;
    ballVelocityY= defaultballvelocity;
    ballVelocityX= 0.0f;
}
