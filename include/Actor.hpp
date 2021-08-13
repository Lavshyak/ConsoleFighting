/*
Все персонажи игры - объекты этого класса.Планируется объявить указатели типа Actor либо в Engine, либо в Game. не знаю пока, где практически удобнее.
*/
#ifndef ACTOR_H
#define ACTOR_H
#include <string>
class Actor
{
	public:
	Actor(std::string name, double health=100,
double damage=10, double defence=0, int lvl=0, double lvlCurrent=0);
	
	std::string ToSave();
	
	std::string GetName();
	
	int Attack(Actor &kogo); //этот перс вызывает Defence() у того, кого атакует.
	int Defence(double damage); //этот перс получает урон. возвращает: 0-умер, 1-еще живой
	
	private:
	void LvlUp(); 
	
	std::string m_name;
	double m_health, m_damage, m_defence;
	int m_lvl; 
	double m_lvlCurrent, //текущие очки опыта
	m_lvlNeed; //сколько их надо, чтобы уровень увеличился
};
#endif  //ACTOR_H