#include "Engine.hpp"
#include <iostream>
#include "Actor.hpp"
#include <fstream>

#define cout std::cout
#define endl std::endl
#define cin std::cin
#define string std::string

void Engine::ClearConsole()
{
	system("cls");
	cin.clear();
	fflush(stdin);
}

void Engine::DeleteActors()
{
	OtladFName(0,"DeleteActors");
	for (int i = 0; i < 3; i++)
	{
		delete Users[i];
		cout<<"вычещен юзер, "<<i<<endl;
	}
	User=nullptr;
	delete Enemy;
	cout<<"вычещен enemy"<<endl;
}

void Engine::Users_Save()
{
	
	std::ofstream out;

	for (int i = 0; i < 3; i++)
	{
		if (Users[i])
		{
			
			out.open(("users/user" + std::to_string(i) + ".txt").c_str());
			if (out.is_open())
			{
				out << Users[i]->ToSave();
				cout<<"юзер сохранен,"<<i<<endl;
			}
			out.close();
		}	
	}
	OtladFName(1,"DeleteActors");
}

void Engine::Users_Load()
{
	OtladFName(0,"Users_Load");
	
	std::ifstream in;

	string name = "";
	double health, damage, defence;
	int lvl;
	double lvlCurrent;

	for (int i = 0; i < 3; i++)
	{
		in.open(("users/user" + std::to_string(i) + ".txt").c_str());
		if (in.is_open())
		{
			in >> name;
			if (name == "")
				break;

			in >> health >> damage >> defence >> lvl >> lvlCurrent;

			Users[i] = new Actor(name, health,
								 damage, defence, lvl, lvlCurrent);
		}
		in.close();
	}
	OtladFName(1,"Users_Load");
}

void Engine::Users_Select(int norl)
{
	OtladFName(0,"Users_Select");
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

	cout << "введи ЦИФРУ" << endl
		 << ">>";
	int usercin;
	cin >> usercin;
	if (usercin<2 | usercin> - 1)
	{
		User = &Users[usercin]; //User
	}
	else
	{
		ClearConsole();
		cout << usercin << " - неверно";
		Users_Select(norl);
	}

	if (norl == 0) //на загрузку
	{
		if (!User)
		{
			cout << "Персонаж не создан." << endl;
			Create_User();
		}
	}
	else if (norl == 1) //на создание
	{
		cout << "Создаем нового персонажа вместо выбранного. Перезапусти игру, чтоб отменить" << endl;
		Create_User();
	}
	else
		cout << "norl не 0 или 1 (ошибка кода)" << endl;
		OtladFName(1,"Users_Select");
}

void Engine::Create_User()
{
	OtladFName(0,"Create_User");
	cout << "Имя нового персонажа: ";
	string name;
	cin >> name;
	*User = new Actor(name);
	cout<<(*User)->GetName()
	<<" создан"<<endl;
	OtladFName(1,"Create_User");
	
}

void OtladFName(int n, string name)
{
	if(n==0)
	cout<<"-------------"<<name<<"-------------"<<endl;
	if(n==1)
	cout<<"~~~~~"<<name<<"~~~~~~"<<endl;
}