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
	Enemy = new Actor("Ork", 50+lvl*5, 5+lvl*5, lvl*5, lvl);
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
	Enemy->setstate(1);
	OtladFName(1,"Move_Enemy");
}

int Engine::Move_Result()
{
	OtladFName(0,"Move_Result");
	
	cout<<(*User)->getname()<<": "<<(*User)->gethealth()<<" HP"<<endl;
	cout<<Enemy->getname()<<": "<<Enemy->gethealth()<<" HP"<<endl;
	
	int re, ru, reu;
	re = (*User)->SendState(*Enemy);
	ru = Enemy->SendState(**User);
	
	if(re==0) cout<<Enemy->getname()<<": Помираю..."<<endl;
	if(ru==0) cout<<(*User)->getname()<<": Помираю..."<<endl;
	
	if(re==1 & ru==1)  reu=1;
	else if(re==1 & ru==0) reu=2;
	else if(re==0 & ru==1) reu=3;
	else reu=2;
	
	if(reu==2) delete (*User);
	OtladFName(1,"Move_Result");
	return reu; 
}
