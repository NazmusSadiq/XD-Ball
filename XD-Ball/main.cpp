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
#include "Offline_Game.h"
#include "OneVOne.h"
#include "Online_Game.h"

#define WindowWidth 960
#define WindowHeight 720
#define PointLimit 5

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(WindowWidth, WindowHeight), "This is the menu", Style::Close | Style::Resize);
    Menu gamemenu(window.getSize().x, window.getSize().y);
    RectangleShape background(Vector2f(WindowWidth, WindowHeight)),offbackground(Vector2f(WindowWidth, WindowHeight)), onbackground(Vector2f(WindowWidth, WindowHeight)), optbackground(Vector2f(WindowWidth, WindowHeight));
    Texture mainbg, offbg, onbg, optbg,balltex,boxtex,pointup,pointdown,fb;
    mainbg.loadFromFile("mainbg.jpg");
    background.setTexture(&mainbg);
    offbg.loadFromFile("offline.jpg");
    offbackground.setTexture(&offbg);
    onbg.loadFromFile("online.jpg");
    onbackground.setTexture(&onbg);
    optbg.loadFromFile("option.jpg");
    optbackground.setTexture(&optbg);
    balltex.loadFromFile("ball.png");
    boxtex.loadFromFile("box.jpg");
    pointup.loadFromFile("pointup.png");
    pointdown.loadFromFile("pointdown.png");
    fb.loadFromFile("fireball.png");
    Sound menusound;
    Music bgsound;
    SoundBuffer buffer,wbfr,lbfr,bxpbfr,bxgbfr;
    bool playing = false, muted = false;
    buffer.loadFromFile("menutoggle.wav");
    bgsound.openFromFile("menubg.wav");
    wbfr.loadFromFile("winningsound.wav");
    lbfr.loadFromFile("losingsound.wav");
    bxpbfr.loadFromFile("boxpop.wav");
    bxgbfr.loadFromFile("boxgone.wav");
    menusound.setBuffer(buffer);
    bgsound.setLoop(true);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (!playing)
            {
                if(!muted)  
                    bgsound.play();
                playing = true;
            }

            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseMoved) 
                gamemenu.mousePressed(window,menusound);
                if (event.type == Event::KeyReleased || event.type == Event::MouseButtonReleased)
                {
                    if (event.key.code == Keyboard::Up)
                    {
                        gamemenu.MoveUp();
                        if(!muted)
                            menusound.play();
                    }
                    if (event.key.code == Keyboard::M)
                    {                       
                        if (bgsound.getStatus() == Sound::Playing)
                        {
                            bgsound.pause();
                        }
                        else
                        {
                            bgsound.play();
                        }
                        if (!muted)
                            muted = true;
                        else
                            muted = false;
                    }
                    if (event.key.code == Keyboard::Down)
                    {
                        gamemenu.MoveDown();
                        if (!muted)
                            menusound.play();
                    }

                    if (event.key.code == Keyboard::Return || event.mouseButton.button == Mouse::Left)
                    {
                        if (!muted)
                            menusound.play();
                        bgsound.stop();
                        RenderWindow Options(VideoMode(WindowWidth, WindowHeight), "Options", Style::Close | Style::Resize);

                        int num = gamemenu.GetPressedItem();
                        if (num == 0)
                        {
                            RenderWindow PlayOffline(VideoMode(WindowWidth, WindowHeight), "Play Offline", Style::Close | Style::Resize);
                            Paddle paddle(WindowWidth / 2-75, WindowHeight - 20);
                            Ball ball(WindowWidth / 2 , WindowHeight / 2,PlayOffline,balltex,wbfr,lbfr);
                            AI_Paddle aipaddle(WindowWidth / 2-75, 10);
                            while (PlayOffline.isOpen())
                            {
                                Event event;
                                while (PlayOffline.pollEvent(event))
                                {
                                    if (event.type == Event::Closed || ((event.type == event.KeyPressed) && (event.key.code == Keyboard::Escape)))
                                    {
                                        PlayOffline.close();
                                        if (!muted)
                                            bgsound.play();
                                    }
                                }
                                PlayOffline.draw(offbackground);
                                Offline_Game(PlayOffline, event, paddle,aipaddle,ball,muted, bxpbfr, bxgbfr,offbackground,pointup,pointdown,balltex,fb);
                                PlayOffline.display();
                            }
                        }
                        if (num == 1)
                        {
                            RenderWindow Play1V1(VideoMode(WindowWidth, WindowHeight), "Play 1V1", Style::Close | Style::Resize);
                            Paddle paddle1(WindowWidth / 2-75, WindowHeight - 20);
                            Ball ball(WindowWidth / 2,  WindowHeight / 2, Play1V1,balltex, wbfr, lbfr);
                            Paddle paddle2(WindowWidth / 2-75, 10);
                            while (Play1V1.isOpen())
                            {
                                Event event;
                                while (Play1V1.pollEvent(event))
                                {
                                    if (event.type == Event::Closed || ((event.type == event.KeyPressed) && (event.key.code == Keyboard::Escape)))
                                    {
                                        Play1V1.close();
                                        if (!muted)
                                            bgsound.play();
                                    }
                                }
                                Play1V1.draw(offbackground);
                                OneVOne(Play1V1, event, paddle1, paddle2, ball,muted, bxpbfr, bxgbfr,offbackground,pointup,pointdown,balltex,fb);
                                Play1V1.display();
                            }
                        }
                        if (num == 2)
                        {
                            RenderWindow PlayOnline(VideoMode(WindowWidth, WindowHeight), "Play Online", Style::Close | Style::Resize);
                            Paddle paddle(WindowWidth / 2-75, WindowHeight - 20);
                            Ball ball(WindowWidth / 2, WindowHeight / 2, PlayOnline, balltex, wbfr, lbfr);
                            AI_Paddle aipaddle(WindowWidth / 2-75, 10);
                            while (PlayOnline.isOpen())
                            {
                                Event event;
                                while (PlayOnline.pollEvent(event))
                                {
                                    if (event.type == Event::Closed || ((event.type == event.KeyPressed) && (event.key.code == Keyboard::Escape)))
                                    {
                                        PlayOnline.close();
                                        if (!muted)
                                            bgsound.play();
                                    }
                                }
                                PlayOnline.draw(onbackground);
                                Online_Game();
                                //To Do by Rafee
                                PlayOnline.display();
                            }
                        }

                        if (num == 3)
                        {
                            while (Options.isOpen())
                            {
                                Event vent;
                                while (Options.pollEvent(vent))
                                {
                                    if (vent.type == Event::Closed)
                                        Options.close();
                                    if (vent.type == Event::KeyPressed)
                                    {
                                        if (vent.key.code == Keyboard::Escape)
                                            Options.close();
                                    }
                                }
                                Options.clear();
                                Options.draw(optbackground);
                                Options.display();
                            }
                        }
                        if (num == 4)
                            window.close();
                        break;
                    }
                }

            }

            window.clear();
            window.draw(background);
            gamemenu.Draw(window);
            window.display();
        }
    }






