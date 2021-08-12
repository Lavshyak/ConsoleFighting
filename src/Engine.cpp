#include "Engine.hpp"
#include <iostream>
#include "Actor.hpp"
#include <string>

#define cout std::cout
#define endl std::endl
#define cin std::cin
#define string std::string

Engine::Engine()
{
}

void Engine::ClearConsole()
{
	system("cls");
	cin.clear();
	fflush(stdin);
}

void Engine::DeleteActors()
{
	for (int i = 0; i < 3; i++)
		delete Users[i];
	delete Enemy;
	delete User;
}

void Engine::Users_Load()
{
}

int Engine::Users_Select()
{
	cout << "ВЫБОР ЮЗЕРА" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i << ": ";
		if (Users[i])
			cout << Users[i];
		else
			cout << "Empty";
		cout << endl;
	}
	string forCin;
	cout << "ВВЕДИ ЦИФРУ БЛЯТЬ..." << endl
		 << ">>";
	cin >> forCin;
	return std::stoi(forCin);
}