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

		Name name; // ���

		friend class SocialNetwork;

	private:
		int id; // ���������� id
	};

	SocialNetwork();

	// ���������� ������ �������� � ���� 
	void AddNewMan(const Name name);

	// �������� �������� �� ���� 
	void DeleteMan(const Name name);

	// ��������� ������ ����� ����� ��������������
	void AddFriendship(const Name name_1, const Name name_2);

	// �������� ������ ��� 
	void showThreeHandshakes();

private: // ��������� �������
	// �������� �� ������������ ��������?
	bool areFriends(const Human& m1, const Human& m2);

	// ���������� �� ��� ������������ � man_id
	bool areExistsWithID(int man_id);

	// ����� �� ����� 
	Human findManByName(const Name name);

private: // ��������� ����
	int friendMatrix[SIZE][SIZE]; // ������� ������
	StaticArray<Human> people; // ������ ����� ������ ����
	StaticArray<bool> busyID; // ������� ID
};