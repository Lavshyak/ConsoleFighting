/*
Все персонажи игры - объекты этого класса.Планируется объявить указатели типа Actor либо в Engine, либо в Game. не знаю пока, где практически удобнее.
*/
#ifndef ACTOR_H
#define ACTOR_H
class Actor
{
	public:
	Actor();
	
	int Attack(Actor &kogo); //этот перс вызывает Defence() у того, кого атакует.
	int Defence(double damage); //этот перс получает урон. возвращает: 0-умер, 1-еще живой
	
	private:
	void LvlUp(); 
	
	double m_health, m_damage, m_defence;
	int m_lvl; 
	double m_lvlCurrent, //текущие очки опыта
	m_lvlNeed; //сколько их надо, чтобы уровень увеличился
};
#endif  //ACTOR_H