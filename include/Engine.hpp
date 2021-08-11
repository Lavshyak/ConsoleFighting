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
	static void DeleteActors(); //удаляет Акторов из памяти (если они будут объявлены в этом файле). Вызывается через Game.
	
	static void ClearConsole(); //очищает консоль и пользовательский ввод
	
	static int Users_Select(); //будет 3 пользователя, тут юзер выбирает нужного
	static void Users_Save(); //сохранить всех персонажей игрока (перед выходом)
	static void Users_Load(); //загрузить их
	
	static void Create_Enemy(); //инициализирует врага, подходящего для текущего состояния юзерского персонажа
	
	static int Attack();
	
	private:
	static Actor &User, *Users, *Enemy;
};

#endif //ENGINE_H
