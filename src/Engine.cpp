#include "Engine.hpp"
#include <iostream>
#include "Actor.hpp"

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
	for(int i=0;i<3;i++)
	{
		delete(Users[i]);
	}
	delete User;
	delete Enemy;
}

void Engine::Users_Save()
{
	for(int i=0;i<3;i++)
	{
		if(Users[i])
		{
			
		}
	}
}



int Engine::Users_Select()
{
	cout<<"ВЫБОР ЮЗЕРА (ЦИФРА)"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<i<<": ";
		if(Users[i])
		{
			cout<<Users[i]->GetName();
		}
		else cout<<"Empty";
		cout<<endl;
	}
}

Engine::Engine()
{
	
	}