#include "Game.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Game::Fight()
{
	eng.Create_Enemy();
	
	int result=1;
	while(result==1)
	{
		eng.PrintStat();
		eng.Move_User();
		eng.ClearConsole();
		eng.Move_Enemy();
		result = eng.Move_Result();
	}
	if(result==2)
	{
		cout<<"Все)) XDXDXD"<<endl;
	}
	eng.Users_Save();
	MainMenu();
}