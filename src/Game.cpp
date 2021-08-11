#include "Game.hpp"
#include "Engine.hpp"
#include <iostream>

#define cout std::cout 
#define endl std::endl

Game::Game()
{
	cout<<"game started"<<endl;
	//MainMenu();
	
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