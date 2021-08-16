/*
Этот класс уже будет делать нужные рассчеты, сложные вещи.
Возможно, все методы будут статичными.
*/
#ifndef ENGINE_H
#define ENGINE_H
  
#include "Actor.hpp"
#include "optional.hpp"
 
class Engine
{
	public:
	//Engine_Console.cpp
	void ClearConsole(); //очищает консоль и пользовательский ввод
	int CinValid(std::string userCin, int l, int r); //-1 ошибка, >=0 правильно, для внешнего использования.
	void OtladFName(int n, std::string name);
	
	//Engine_UsersBasic.cpp
	void DeleteActors(); //удаляет Акторов из памяти (если они будут объявлены в этом файле). Вызывается через Game.
	void Users_Select(int norl); //будет 3 пользователя, тут юзер выбирает нужного (User)
	void Users_Save(); //сохранить всех персонажей игрока
	void Users_Load(); //загрузить их
	void Create_User(); //определяет (создает) нового пользователя
	
	//Engine.cpp
	void Create_Enemy(); //определяет (создает) врага, подходящего для текущего состояния юзерского персонажа
	int Attack(); //кто атакует и какой результат.
	void Move_User();
	void Move_Enemy();
	int Move_Result();
	
	
	private:
	Actor **User, //выбранный игроком перс
	*Users[3]; //все персы
	Actor *Enemy; //враг
	
	void CinValid(int l, int r); //перегруз для внутреннего использования
	
	std::string userStr; //что юзер ввел
	tl::optional<int> userInt; //в это конвертится. -1 в случае неверного ввода
};

#endif //ENGINE_H
