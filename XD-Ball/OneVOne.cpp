#include "OneVOne.h"

OneVOne::OneVOne(RenderWindow& Play1V1, Event& event, Paddle& paddle1, Paddle& paddle2, Ball& ball, RectangleShape& bg, Texture& pup, Texture& pdn,Texture& balltex,Texture& fb)
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        paddle1.movePaddleLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        paddle1.movePaddleRight();
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        paddle2.movePaddleLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        paddle2.movePaddleRight();
    }
    ball.reboundSides();
    ball.passTop(paddle1, paddle2);
    ball.passBottom(paddle1, paddle2);

    if (ball.getBallFloatRect().intersects(paddle1.getPaddleFloatRect()))
    {
        ball.reboundPaddle(paddle1);
    }

    if (ball.getBallFloatRect().intersects(paddle2.getPaddleFloatRect()))
    {
        ball.reboundPaddle(paddle2);
    }
    std::stringstream ss1, ss2, ss3;

    ss1 << "Player 1 Score: " << ball.playerscore << "\nPlayer 2 Score: " << ball.opponentscore;
    ss2 << "Player 1 Won.\nPress r to play again, esc to quit";
    ss3 << "Player 2 Won.\nPress r to play again, esc to quit";
    Text text1, text2, text3;
    Font font;
    font.loadFromFile("Plaguard-ZVnjx.otf");
    text1.setFont(font);
    text1.setCharacterSize(15);
    text1.setFillColor(Color::White);
    text1.setString(ss1.str());
    text2.setFont(font);
    text2.setCharacterSize(45);
    text2.setFillColor(Color::White);
    text2.setString(ss2.str());
    text3.setFont(font);
    text3.setCharacterSize(45);
    text3.setFillColor(Color::White);
    text3.setString(ss3.str());
    ball.update();
    paddle1.update();
    paddle2.update();
    ball.BoxFunctions(Play1V1, ball,pup,pdn,balltex,fb);
    Play1V1.clear();

    if (ball.playerscore == PointLimit)
    {
        Play1V1.draw(text2);
        ball.stop();

        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::R))
        {
            ball.playerscore = 0;
            ball.opponentscore = 0;
            paddle1.PaddleReset();
            paddle2.PaddleReset();
            paddle2.paddleposition.y = 10;
            ball.go();
        }
    }
    else if (ball.opponentscore == PointLimit)
    {
        Play1V1.draw(text3);
        ball.stop();

        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::R))
        {
            ball.playerscore = 0;
            ball.opponentscore = 0;
            paddle1.PaddleReset();
            paddle2.PaddleReset();
            paddle2.paddleposition.y = 10;
            ball.go();
        }
    }
    else
    {
        Play1V1.draw(bg);
        Play1V1.draw(text1);
        Play1V1.draw(paddle1.getPaddleObject());
        Play1V1.draw(ball.getBallObject());
        Play1V1.draw(ball.getBoxObject());
        Play1V1.draw(paddle2.getPaddleObject());
    }
}

