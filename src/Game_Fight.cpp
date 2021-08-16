#include "Game.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Game::Fight()
{
	int result=-1;
	while(result==-1)
	{
		eng.Move_User();
		eng.Move_Enemy();
		result = eng.Move_Result();
	}
}