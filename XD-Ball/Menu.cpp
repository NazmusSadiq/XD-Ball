#include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include "Menu.h"



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Plaguard-ZVnjx.otf"))
	{
		std::cout << "Not Loaded";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Play VS CPU");
	menu[0].setPosition(Vector2f(width / 2-75, height / (MAX_NUMBER_OF_ITEMS + 1) * 1-30));
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Play 1 V 1");
	menu[1].setPosition(Vector2f(width / 2-75, height / (MAX_NUMBER_OF_ITEMS + 1) * 2-30));
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Play Online");
	menu[2].setPosition(Vector2f(width / 2-75, height / (MAX_NUMBER_OF_ITEMS + 1) * 3-30));
	menu[3].setFont(font);
	menu[3].setFillColor(Color::White);
	menu[3].setString("Options");
	menu[3].setPosition(Vector2f(width / 2 - 75, height / (MAX_NUMBER_OF_ITEMS + 1) * 4-30));
	menu[4].setFont(font);
	menu[4].setFillColor(Color::White);
	menu[4].setString("Exit Game");
	menu[4].setPosition(Vector2f(width / 2 - 75, height / (MAX_NUMBER_OF_ITEMS + 1) * 5-30));

	selectedItemIndex = 0 ;
}

void Menu::Draw(RenderWindow  &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		if (selectedItemIndex < 0)
			selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
		menu[selectedItemIndex].setFillColor(Color::Red);
}
 
void Menu::MoveDown()
{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		if (selectedItemIndex >= MAX_NUMBER_OF_ITEMS)
			selectedItemIndex = 0;
		menu[selectedItemIndex].setFillColor(Color::Red);
}

int Menu::GetPressedItem()
{
	return selectedItemIndex;
}


void Menu ::mousePressed(RenderWindow& window,Sound& menusound)
{
	Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
	FloatRect but_1 = menu[0].getGlobalBounds();
	FloatRect but_2 = menu[1].getGlobalBounds();
	FloatRect but_3 = menu[2].getGlobalBounds();
	FloatRect but_4 = menu[3].getGlobalBounds();
	FloatRect but_5 = menu[4].getGlobalBounds();
	if (but_1.contains(mousePos)) 
	{
		Color current = menu[0].getFillColor();
		menu[0].setFillColor(Color::Red);
		selectedItemIndex = 0;
		if(current!=Color::Red)
			menusound.play();
	}
	else 
	{
		menu[0].setFillColor(Color::White);
	}
	if (but_2.contains(mousePos)) 
	{
		Color current = menu[1].getFillColor();
		menu[1].setFillColor(Color::Red);
		selectedItemIndex = 1;
		if (current != Color::Red)
			menusound.play();
	}
	else 
	{
		menu[1].setFillColor(Color::White);
	}
	if (but_3.contains(mousePos)) 
	{
		Color current = menu[2].getFillColor();
		menu[2].setFillColor(Color::Red);
		selectedItemIndex = 2;
		if (current != Color::Red)
			menusound.play();
	}
	else 
	{
		menu[2].setFillColor(Color::White);
	}
	if (but_4.contains(mousePos)) 
	{
		Color current = menu[3].getFillColor();
		menu[3].setFillColor(Color::Red);
		selectedItemIndex = 3;
		if (current != Color::Red)
			menusound.play();
	}
	else 
	{
		menu[3].setFillColor(Color::White);
	}
	if (but_5.contains(mousePos)) 
	{
		Color current = menu[4].getFillColor();
		menu[4].setFillColor(Color::Red);
		selectedItemIndex = 4;
		if (current != Color::Red)
			menusound.play();
	}
	else 
	{
		menu[4].setFillColor(Color::White);
	}
}