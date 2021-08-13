#include "Game.hpp"
#include <iostream>

#define cout std::cout 
#define endl std::endl
#define cin std::cin

Game::Game()
{
	cout<<"game started"<<endl;
	MainMenu();
	//eng.ClearConsole();
}

void Game::MainMenu()
{
	cout<<"------Main Menu-----"<<endl;
	cout<<"0: Contunie"<<endl;
	cout<<"1: New game"<<endl;
	
	int usercin;
	cin>>usercin;
	eng.Users_Select(usercin);
}

Game::~Game()
{
	eng.Users_Save();
	eng.DeleteActors();
	cout<<"game finished"<<endl;
}