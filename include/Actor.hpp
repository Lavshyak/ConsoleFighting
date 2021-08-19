/*
Все персонажи игры - объекты этого класса.Планируется объявить указатели типа Actor либо в Engine, либо в Game. не знаю пока, где практически удобнее.
*/
#ifndef ACTOR_H
#define ACTOR_H
#include <string>
class Actor
{
	public:
	Actor(std::string name, double maxHealth=100, double health=100,
double damage=10, double defence=0, int lvl=0, double lvlCurrent=0);
	
	int SendState(Actor &komu);
	int GetState(int state, double &takedDamage, double damage=0);
	
	private: 
	void LvlUp(double lvlCurrent=0); 
	int Damage(double damage);
	
	std::string m_name;
	double m_maxHealth, m_health, m_damage, m_defence;
	int m_lvl; 
	double m_lvlCurrent, //текущие очки опыта
	m_lvlNeed; //сколько их надо, чтобы уровень увеличился
	int m_state; //1-атака, 2-блок, 3-бросок
	
	//геттеры
	public:
	std::string ToSave();
	std::string getname() {return m_name;}
	int getlvl() {return m_lvl;}
	
	double gethealth() {return m_health;}
	double getmaxHealth() {return m_maxHealth;}
	std::string  getstatus();
	std::string GetState();
	
	//сеттеры
	public:
	void setstate(int state) {m_state=state;}
};
#endif  //ACTOR_H