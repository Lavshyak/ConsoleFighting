#include "Engine.hpp"
#include <iostream>
#include "Actor.hpp"
#include <fstream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Engine::Create_Enemy()
{
	int lvl = (*User)->getlvl();
	Enemy = new Actor("Ork", 50+lvl*5, 50+lvl*5, 5+lvl*3, lvl*2, lvl);
}

void Engine::Move_User()
{
	OtladFName(0,"Move_User");
	cout<<"1: Attack"<<endl
	<<"2: Block"<<endl
	<<"3: Throw"<<endl;
	cout<<">>";
	CinValid(1,3);
	(*User)->setstate(userInt.value());
	OtladFName(1,"Move_User");
}

void Engine::Move_Enemy()
{
	OtladFName(0,"Move_Enemy");
	srand(Enemy->gethealth());
	Enemy->setstate(1+rand()%3);
	OtladFName(1,"Move_Enemy");
}

int Engine::Move_Result()
{
	OtladFName(0,"Move_Result");
	int re, ru, reu;
	re = (*User)->SendState(*Enemy);
	ru = Enemy->SendState(**User);
	
	cout<<(*User)->GetState()<<endl;
	cout<<Enemy->GetState()<<endl;
	
	if(re==0) cout<<Enemy->getname()<<": Помираю..."<<endl;
	if(ru==0) cout<<(*User)->getname()<<": Помираю..."<<endl;
	
	if(re==1 & ru==1)  reu=1;
	else if(re==1 & ru==0) reu=2;
	else if(re==0 & ru==1) reu=3;
	else reu=2;
	
	if(reu==2) (*User)=nullptr;
	OtladFName(1,"Move_Result");
	return reu; 
}

void Engine::PrintStat()
{
	cout<<(*User)->getstatus()<<endl;
	cout<<Enemy->getstatus()<<endl;
}