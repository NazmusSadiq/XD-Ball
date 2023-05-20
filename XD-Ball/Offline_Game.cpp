#include "Offline_Game.h"

<<<<<<< HEAD
Offline_Game::Offline_Game(RenderWindow& PlayOffline, Event& event, Paddle& paddle, AI_Paddle& aipaddle, Ball& ball,RectangleShape& bg,Texture& pup, Texture& pdn,Texture& balltex,Texture& fb)
=======
Offline_Game::Offline_Game(RenderWindow& PlayOffline, Event& event, Paddle& paddle, AI_Paddle& aipaddle, Ball& ball,RectangleShape& bg,Texture& pup, Texture& pdn)
>>>>>>> 99c76fd94d0349569df49390a80fde30e3ac6c9e
{
    aipaddlecounter = 0;

    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
    {
        paddle.movePaddleLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
    {
        paddle.movePaddleRight();
    }
    ball.reboundSides();
    ball.passTopAI(paddle, aipaddle);
    ball.passBottomAI(paddle, aipaddle);
    if (ball.getBallFloatRect().intersects(paddle.getPaddleFloatRect()))
    {
        ball.reboundPaddle(paddle);
    }

    if (ball.getBallFloatRect().intersects(aipaddle.getAIPAddleFloatRect()))
    {
        ball.reboundAIPaddle(aipaddle);
    }

    if (ball.getBallFloatRect().left > (aipaddle.getAIPAddleFloatRect().left + 10))
    {
        if (aipaddlecounter % 30 == 0)
            aipaddle.moveAIPaddleRight();
    }
    if (ball.getBallFloatRect().left < (aipaddle.getAIPAddleFloatRect().left+10))
    {
        if (aipaddlecounter % 30 == 0)
            aipaddle.moveAIPaddleLeft();
    }
    if (ball.getBallPosition.x > WindowWidth)
        aipaddle.AIPaddleSpeedReverse();
    std::stringstream ss1, ss2, ss3;

    ss1 << "Your Score: " << ball.playerscore << "\nOpponent's Score: " << ball.opponentscore;
    ss2 << "You Won.\nPress r to play again, esc to quit";
    ss3 << "You Lost.\nPress r to play again, esc to quit";
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

    aipaddlecounter++;
    ball.update();
    paddle.update();
    aipaddle.update();
<<<<<<< HEAD
    ball.BoxFunctions(PlayOffline, ball,pup,pdn,balltex,fb);
=======
    ball.BoxFunctions(PlayOffline, ball,pup,pdn);
>>>>>>> 99c76fd94d0349569df49390a80fde30e3ac6c9e
    PlayOffline.clear();

    if (ball.playerscore == PointLimit)
    {
        PlayOffline.draw(text2);
        ball.stop();

        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::R))
        {
            ball.playerscore = 0;
            ball.opponentscore = 0;
            paddle.PaddleReset();
            aipaddle.AIPaddleReset();
            ball.go();
        }
    }
    else if (ball.opponentscore == PointLimit)
    {
        PlayOffline.draw(text3);
        ball.stop();

        if ((event.type == Event::KeyReleased) && (event.key.code == Keyboard::R))
        {
            ball.playerscore = 0;
            ball.opponentscore = 0;
            paddle.PaddleReset();
            aipaddle.AIPaddleReset();
            ball.go();
        }
    }
    else
    {
        PlayOffline.draw(bg);
        PlayOffline.draw(text1);
        PlayOffline.draw(paddle.getPaddleObject());
        PlayOffline.draw(ball.getBallObject());
        PlayOffline.draw(ball.getBoxObject());
        PlayOffline.draw(aipaddle.getAIPaddleObject());
    }
}
