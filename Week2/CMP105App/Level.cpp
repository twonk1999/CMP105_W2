#include "Level.h"
#include <string>
#include <iostream>

using namespace std;
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "load from file failed" << std::endl;
	}


	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		text.setFont(font);
		text.setCharacterSize(35);
		text.setFillColor(sf::Color::Red);
		text.setPosition(400, 0);
		std::cout << "Here's some text" << std::endl;
		text.setString("You have pressed the 'W' key \n");
		input->setKeyUp(sf::Keyboard::W);
	}
	if ((input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::L) && input->isKeyDown(sf::Keyboard::K)))
	{
		text.setFont(font);
		text.setCharacterSize(35);
		text.setFillColor(sf::Color::Red);
		text.setPosition(400, 0);
		std::cout << "Here's some text" << std::endl;
		text.setString("You have pressed the 'J, K, and L' keys together \n");
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		std::cout << "The escape key was pressed: exiting game" << std::endl;
		window->close();
	}
}



// Update game objects
void Level::update()
{
	sf::Vector2u location(input->getMouseX(), input->getMouseY());
	string stringToDisplay = to_string(location.x);
	string stringToDisplay2 = to_string(location.y);
	text.setString("X position: " + stringToDisplay + " Y position: " + stringToDisplay2);
	text.setFont(font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Red);
	text.setPosition(0, 0);


}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}