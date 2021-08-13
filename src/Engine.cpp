#include "Engine.hpp"
#include <iostream>
#include "Actor.hpp"
#include <fstream>
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
	for (int i = 0; i < 3; i++)
	{
		delete Users[i];
	}
	delete User;
	delete Enemy;
}

void Engine::Users_Save()
{
	std::ofstream out;

	for (int i = 0; i < 3; i++)
	{
		if (Users[i])
		{
			out.open("/../users/user" + std::to_string(i) + ".txt");
			if (out.is_open())
			{
				out << Users[i]->ToSave();
			}
		}
	}
	out.close();
}

void Engine::Users_Select()
{
	cout << "Выбор пользователя" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i << ": ";
		if (Users[i])
		{
			cout << Users[i]->GetName();
		}
		else
			cout << "Empty";
		cout << endl;
	}
	User = Users[1];
}