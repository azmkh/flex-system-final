#include <iostream>
#include <vector>
#include <string>
//#include <queue>
//#include <algorithm>
#include <cmath>
//#include <map>
//#include <stack>
//#include <list>
#include <cstring>
#include "system.h"
#include "SFML/Graphics.hpp"
using namespace std;

//main classes
//student, marks, attendance, courses
//four seperate files for each main class 



const int MAX_NUMBER_OF_ITEMS = 3;

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("C:\\arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("LOGIN: ");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("PASSWORD: ");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("ENTER");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


int main()
{
	//SFML
	sf::RenderWindow window(sf::VideoMode(600, 600), "FLEX MANAGEMENT SYSTEM");
	sf::Texture texture;

	if (!texture.loadFromFile("C:\\flex.png"))
	{
		std::cout << "Error loading" << std::endl;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	//sf::Font font;

	//if (!font.loadFromFile("C:\\arial.ttf"))
	//{
	//	// handle error
	//}

	//sf::Text text;
	//sf::Text text2;
	//
	//text.setFont(font);
	//text.setString("LOGIN: ");
	//text.setFillColor(sf::Color::Red);
	//text.setCharacterSize(40);
	//

	//text2.setFont(font);
	//text2.setString("PASSWORD: ");
	//text2.setFillColor(sf::Color::Red);
	//text2.setCharacterSize(40);



	Menu menu(window.getSize().x, window.getSize().y);
	sf::RectangleShape rectangle(sf::Vector2f(200, 40));
	while (window.isOpen())
	{
		sf::Event e;


		//sf::Sprite sprite(texture);

		// or


		while (window.pollEvent(e))
		{

			if (sf::Event::KeyPressed)
			{
				if (sf::Keyboard::Enter)
				{
					cout << "Logged in! Success" << endl;
					window.close();
					break;
				}
			}

			/*if (e.type == sf::Event::Closed)
			{

			}*/


		}

		window.clear();

		window.draw(sprite);
		//window.draw(text);
		//window.draw(text2);
		menu.draw(window);
		rectangle.setPosition(300.f, 200.f);
		window.draw(rectangle);
		rectangle.setPosition(300.f, 340.f);
		window.draw(rectangle);
		//window.draw(rectangle);
		window.display();
		//window.clear();
		//window.display();
	}





    //calling main menu driver
    class system SMS;
    SMS.main_menu();





	return 0;

}