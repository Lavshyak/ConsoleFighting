#include "Engine.hpp"
#include <iostream>
#include "Actor.hpp"
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Engine::Create_Enemy()
{
	int lvl = (*User)->getlvl();
	
	Enemy = new Actor("Ork", 100+lvl*5, 5+lvl*5, lvl*5, lvl);
}



