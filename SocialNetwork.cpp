#include "SocialNetwork.h"
#include <memory>
#include <iostream>


SocialNetwork::Human::Human() : id(-1)
{
	
}

SocialNetwork::Human::Human(const Name _name, int _id) : id(_id)
{
	strcpy_s(name, _name);
}

SocialNetwork::Human & SocialNetwork::Human::operator=(const Human& other)
{
	strcpy_s(name, other.name);
	id = other.id;
	return *this;
}


SocialNetwork::Human::Human(const Human& other)
{
	strcpy_s(name, other.name);
	id = other.id;

}

bool SocialNetwork::Human::operator==(const Human& other)
{
	return other.id == this->id;
}

SocialNetwork::SocialNetwork()
{
	for (int i = 0; i < SIZE; i++)
	{
		busyID.Add(false);
		for (int j = 0; j < SIZE; j++)
		{
			friendMatrix[i][j] = 0;
		}
	}
}

// Добавление нового человека в сеть 
void SocialNetwork::AddNewMan(const Name name)
{
	Human man = findManByName(name);
	if (man.id >= 0)
	{
		return;
	}

	int i = 0;
	for (; i < SIZE; i++)
	{
		if (!busyID[i])
		{
			break;
		}
	}
	busyID[i] = true;
	people.Add(Human(name, i));
}

// Удаление человека из сети 
void SocialNetwork::DeleteMan(const Name name)
{
	Human man = findManByName(name);
	if (man.id < 0)
	{
		return;
	}
	busyID[man.id] = false;
	int index = people.Find(man);

	for (int i = 0; i < people.Size(); i++)
	{
		friendMatrix[i][man.id] = 0;
		friendMatrix[man.id][i] = 0; 
	}

	people.Delete(index);
}


// Установка дружбы между двумя пользователями
void SocialNetwork::AddFriendship(const Name name_1, const Name name_2)
{
	Human m1 = findManByName(name_1);
	Human m2 = findManByName(name_2);

	if (m1.id < 0 || m2.id < 0)
	{
		return;
	}
	friendMatrix[m1.id][m2.id] = 1;
	friendMatrix[m2.id][m1.id] = 1;
}

// Алгоритм поиска пар 
void SocialNetwork::showThreeHandshakes()
{
	int wavesLevels[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		wavesLevels[i] = -1;
	}
	wavesLevels[0];

	StaticArray<int> queue;
	queue.Add(0);

	while (queue.Size())
	{
		int currentManIndex = queue[0];
		queue.Delete(0);
		for (int i = 0; i < people.Size(); i++)
		{
			if (areFriends(people[currentManIndex], people[i]) && wavesLevels[i] == -1)
			{
				wavesLevels[i] = wavesLevels[currentManIndex] + 1;
				queue.Add(i);
			}
		}
	}

	for (int i = 0; i < people.Size(); i++)
	{
		std::cout << people[i].name << " friends with 3 handshakes : ";
		for (int j = 0; j < people.Size(); j++)
		{
			if (j == i)
			{
				j++;
			}
			if (abs(wavesLevels[i] - wavesLevels[j]) <= 3)
			{
				std::cout << " " << people[j].name;
			}
		}
		std::cout << std::endl;
	}
}


// Приватные функции
// Являются ли пользователи друзьями?
bool SocialNetwork::areFriends(const Human& m1, const Human& m2)
{
	return friendMatrix[m1.id][m2.id] == 1;
}

// Существует ли уже пользователь с man_id
bool SocialNetwork::areExistsWithID(int man_id)
{
	for (int i = 0; i < people.Size(); i++)
	{
		if (people[i].id == man_id)
		{
			return true;
		}
	}
	return false;
}

// Поиск по имени 
SocialNetwork::Human SocialNetwork::findManByName(const Name name)
{
	for (int i = 0; i < people.Size(); i++)
	{
		if (!strcmp(name, people[i].name))
		{
			return people[i];
		}
	}
	return Human();
}

