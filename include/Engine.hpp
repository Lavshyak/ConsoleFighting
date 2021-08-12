/*
Этот класс уже будет делать нужные рассчеты, сложные вещи.
Возможно, все методы будут статичными.
*/
#ifndef ENGINE_H
#define ENGINE_H
  
#include "Actor.hpp"
class Engine
{
	public:
	Engine();
	void DeleteActors(); //удаляет Акторов из памяти (если они будут объявлены в этом файле). Вызывается через Game.
	
	void ClearConsole(); //очищает консоль и пользовательский ввод
	
	int Users_Select(); //будет 3 пользователя, тут юзер выбирает нужного (User)
	void Users_Save(); //сохранить всех персонажей игрока (перед выходом)
	void Users_Load(); //загрузить их
	
	void Create_Enemy(); //инициализирует врага, подходящего для текущего состояния юзерского персонажа
	
	int Attack(); //кто атакует и какой результат.
	
	private:
	Actor *User, 
	*Users[3];
	Actor *Enemy;
};

#endif //ENGINE_H
