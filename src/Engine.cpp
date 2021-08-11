#include "Engine.hpp"
#include <iostream>

#define cout std::cout 
#define endl std::endl
#define cin std::cin

void Engine::ClearConsole()
{
	system("cls");
	cin.clear();
	fflush(stdin);
}

void Engine::DeleteActors()
{
	//delete [] Users;
	Actor *p;
	p = new Actor;
	delete p;
	
	Enemy = new Actor;
	//delete Enemy;
}

/*int Engine::Users_Select()
{
	Users = new Actor[3];
	Enemy = new Actor;
	int a;
	cin>>a;
	return a;
}*/