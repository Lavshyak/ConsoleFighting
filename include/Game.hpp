/*
Это типа фасад (паттерн). Этот класс будет вызывать нужные методы класса Engine.
Что-то типа API.
*/
#ifndef GAME_H
#define GAME_H  
#include "Engine.hpp"
class Game
{
	public:
	Game(); //отсюда вызывает главное меню, как минимум.
	~Game(); //удаляет Акторов из памяти (если они будут объявлены в этом файле)
	
	private:
	void MainMenu(); //главное меню
	void Fight(); //процесс боя
};
#endif //GAME_H