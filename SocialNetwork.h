#pragma once

#include "StaticArrayh.h"

#define NAMELENGTH 30

typedef char Name[NAMELENGTH];


class SocialNetwork
{
public:
	struct Human
	{
		Human();
		Human(const Name _name, int _id);
		Human& operator=(const Human& other);
		Human(const Human& other);

		bool operator==(const Human& other);

		Name name; // Имя

		friend class SocialNetwork;

	private:
		int id; // Внутренний id
	};

	SocialNetwork();

	// Добавление нового человека в сеть 
	void AddNewMan(const Name name);

	// Удаление человека из сети 
	void DeleteMan(const Name name);

	// Установка дружбы между двумя пользователями
	void AddFriendship(const Name name_1, const Name name_2);

	// Алгоритм поиска пар 
	void showThreeHandshakes();

private: // Приватные функции
	// Являются ли пользователи друзьями?
	bool areFriends(const Human& m1, const Human& m2);

	// Существует ли уже пользователь с man_id
	bool areExistsWithID(int man_id);

	// Поиск по имени 
	Human findManByName(const Name name);

private: // Приватные поля
	int friendMatrix[SIZE][SIZE]; // Матрица дружбы
	StaticArray<Human> people; // Список людей внутри сети
	StaticArray<bool> busyID; // Занятые ID
};