#pragma once
#include<SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 5
#define WindowWidth 960
#define WindowHeight 720

using namespace sf;
class Menu
{
public:
	Menu(float width, float height);
	void Draw(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
	void mousePressed(RenderWindow& window, Sound& menusound);
	RectangleShape box;
	Texture boxtex;
private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
};

