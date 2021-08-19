#include "Engine.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Engine::ClearConsole()
{
	system("cls");
	cin.clear();
	fflush(stdin);
}

void Engine::OtladFName(int n, string name)
{
	if(m_otladka==false) return;
	if(n==0)
	cout<<"______________________________"<<name<<"{"<<endl;
	if(n==1)
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<name<<"}"<<endl;
}

int Engine:: CinValid(string userCin, int l, int r)
{
	int ret;
	try{
		ret = std::stoi(userCin);
	}
	catch(std::invalid_argument e)
	{
		return -1;
	}
	if(ret<l || ret>r) return -1;
	return ret;
}

void Engine::CinValid(int l, int r)
{
	cin>>userStr;
	try
	{
		userInt=std::stoi(userStr);
	}
	catch(std::invalid_argument e)
	{
		userInt=tl::nullopt;
		return;
	}
	if(userInt<l || userInt>r) userInt=tl::nullopt;
}