#include "Actor.hpp"
#include <sstream>

using std::endl;

Actor::Actor(std::string name, double maxHealth, double health,
double damage, double defence, int lvl, double lvlCurrent)
:m_name(name), m_maxHealth(maxHealth),m_health(health), m_damage(damage), m_defence(defence), m_lvl(lvl), m_lvlCurrent(lvlCurrent)
{
	m_lvlNeed=m_lvl*10+10;
}

std::string Actor::ToSave()
{
	std::stringstream ss;
	ss<<m_name<<endl;
	ss<<m_maxHealth<<endl;
	ss<<m_health<<endl;
	ss<<m_damage<<endl;
	ss<<m_defence<<endl;
	ss<<m_lvl<<endl;
	ss<<m_lvlCurrent<<endl;
	return ss.str();
}

int Actor::SendState(Actor &komu)
{
	double takedDamage;
	int ret;
	ret = komu.GetState(m_state, takedDamage, m_damage); 
	LvlUp(takedDamage);
	return ret;
}

void Actor::LvlUp(double lvlCurrent)
{
	m_lvlCurrent+=lvlCurrent*0.3;
	while(m_lvlCurrent>=m_lvlNeed)
	{
		m_lvlCurrent-=m_lvlNeed;
		m_lvl++;
		m_maxHealth+=5;
		m_health=m_maxHealth;
		m_damage+=3;
		m_defence+=1;
	}
}

int Actor::GetState(int state, double &takedDamage, double damage)
{
	//враг атакует, я атакую или бросаю
	if(state==1 && (m_state==1|| m_state==3))
	takedDamage=damage;
	 
	//враг атакует, я блокирую
	else if(state==1 && m_state==2)
		takedDamage=damage*0.2;
		
	//враг блокирует
	else if(state==2)
	{
		 takedDamage=0;
	}
	
	//враг бросает, я блокирую
	else if(state==3 & m_state==2)
		takedDamage=damage*0.5;
	//враг бросает, я бросаю
	else if(state==3 & m_state ==3)
	{
		if(damage>m_damage)
		takedDamage=damage*0.5;
		else takedDamage=0;
	}
	//враг бросает, я атакую
	else
	{
		 takedDamage=0;
	}
	
	return Damage(takedDamage);
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

std::string Actor::getstatus()
{
	std::stringstream ss;
	ss<<m_name<<": "<<m_health<<"/"<<m_maxHealth<<" HP, "<< m_damage <<" Damage, " << m_lvl << " LVL, " << m_lvlCurrent<<"/"<<m_lvlNeed << "lvl current";
	return ss.str(); 
 }
 
std::string Actor::GetState()
{
	if(m_state==1) return m_name + " атакует";
	else if(m_state==2) return m_name+" блокирует";
	else return m_name + " совершает бросок";
}