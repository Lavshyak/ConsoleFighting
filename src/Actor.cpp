#include "Actor.hpp"

Actor::Actor(std::string name)
:m_Name(name)
{
	m_health=100;	
}


std::string Actor::GetName()
{
	return m_Name;
}