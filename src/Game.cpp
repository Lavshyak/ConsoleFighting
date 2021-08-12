#include "Game.hpp"
#include <iostream>

#define cout std::cout 
#define endl std::endl

Game::Game()
{
	cout<<"\"Игра, которая не прощает\" started"<<endl;
	MainMenu();
	E.Users_Load();
	E.Users_Select();
	
}

void Game::MainMenu()
{
	cout<<"------Main Menu-----"<<endl;
}

Game::~Game()
{
	//Engine::DeleteActors();
	cout<<"game finished"<<endl;
}