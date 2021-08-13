#include "Game.hpp"
#include <iostream>

#define cout std::cout 
#define endl std::endl

Game::Game()
{
	cout<<"game started"<<endl;
	MainMenu();
	//eng.ClearConsole();
}

void Game::MainMenu()
{
	cout<<"------Main Menu-----"<<endl;
	eng.Users_Select();
}

Game::~Game()
{
	eng.Users_Save();
	eng.DeleteActors();
	cout<<"game finished"<<endl;
}