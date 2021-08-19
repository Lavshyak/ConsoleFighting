#include "Game.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

Game::Game()
{
	eng.OtladFName(0,"CONSOLE FIGHTING");
	eng.Users_Load();
	MainMenu();
}

void Game::MainMenu()
{
	eng.OtladFName(0,"MainMenu");
	cout<<"0: Contunie"<<endl;
	cout<<"1: New game"<<endl;
	cout<<"2: Exit"<<endl;
	cout<<">>";
	string userCin;
	cin>>userCin;
	cout<<"n1";
	int userV=eng.CinValid(userCin,0,2);
	cout<<"n2";
	if(userV==-1)
	{
		eng.ClearConsole();
		MainMenu();
	}
	if(userV==0 | userV==1)
		eng.Users_Select(userV);
		Fight();
	eng.OtladFName(1,"MainMenu");
}

Game::~Game()
{
	eng.Users_Save();
	eng.DeleteActors();
	eng.OtladFName(1,"CONSOLE FIGHTING");
}