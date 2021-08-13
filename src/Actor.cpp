#include "Actor.hpp"
#include <sstream>

#define endl std::endl;

Actor::Actor(std::string name)
:m_Name(name)
{
	m_health=100;	
}


std::string Actor::GetName()
{
	return m_Name;
}

std::string Actor::ToSave()
{
	std::stringstream ss;
	ss<<m_Name<<endl;
	ss<<m_health<<endl;
	ss<<m_damage<<endl;
	ss<<m_defence<<endl;
	ss<<m_lvl<<endl;
	ss<<m_lvlCurrent<<endl;
	ss<<m_lvlNeed<<endl;
	return ss.str();
}