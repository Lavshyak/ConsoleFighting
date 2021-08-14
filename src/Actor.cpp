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


std::string Actor::GetName()
{
	return m_name;
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