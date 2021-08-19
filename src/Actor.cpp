#include "Actor.hpp"
#include <sstream>

using std::endl;

Actor::Actor(std::string name, double health,
double damage, double defence, int lvl, double lvlCurrent)
:m_name(name), m_health(health),
m_damage(damage),m_defence(defence),
m_lvl(lvl), m_lvlCurrent(lvlCurrent)
{

}

std::string Actor::ToSave()
{
	std::stringstream ss;
	ss<<m_name<<endl;
	ss<<m_health<<endl;
	ss<<m_damage<<endl;
	ss<<m_defence<<endl;
	ss<<m_lvl<<endl;
	ss<<m_lvlCurrent<<endl;
	return ss.str();
}

int Actor::SendState(Actor &komu)
{
	return komu.GetState(m_state, m_damage); 
}

int Actor::GetState(int state, double damage)
{
	//враг атакует, я атакую или бросаю
	if(state==1 & (m_state==1| m_state==3))
		return Damage(damage); 
	//враг атакует, я блокирую
	else if(state==1 & m_state==2)
		return Damage(damage*0.2); 
		
	//враг блокирует
	else if(state==2) return 1;
	
	//враг бросает, я блокирую
	else if(state==3 & m_state==2)
		return Damage(damage*0.5);
	//враг бросает, я бросаю
	else if(state==3 & m_state ==3)
	{
		if(damage>m_damage) return Damage(damage*0.5);
		else return 1; 
	}
	//враг бросает, я атакую
	else return 1;
}

int Actor::Damage(double damage)
{
	damage-=m_defence;
	if(damage<=0) return 1;
	m_health-=damage;
	if(m_health<=0)
	{
		return 0;
	}
	else return 1; 
}