#include "stdafx.h"

string AddList(List**begin) { //���������� �������� ������
	cout << "------------------------------------------------------" << endl << endl;
	Bus bus = testList();
	

	if (*begin == nullptr) {//���� ������ ����
		*begin = new List();
		(*begin)->bus = bus;
		(*begin)->next = nullptr;
	}
	else //���� ������ �� ����
	{
		List *copy = *begin;
		while (copy->next) copy = copy->next;
		copy->next = new List;
		copy = copy->next;
		copy->bus = bus;
		copy->next = nullptr;
	}
	system("cls");
	return "��������� ������";
}

Bus testList() { //�������� �� �������������
	Bus test;
	do {
		cout << "������� ����� ��������: ";
		cin >> test.busNumber;
	} while (test.busNumber == "");
	do {
		cout << "������� ��� ��������: ";
		cin.get();
		getline(cin, test.name);
	} while (test.busNumber == "");
	do {
		cout << "������� �������: ";
		cin >> test.route;
	} while (test.busNumber == "");
	test.status = false;
	return test;
}

void Printf(List*begin, int marker) {//����� ��������� ������
	switch (marker)
	{
	case 1: PrintfList(begin); break;
	case 2: PrintfPark(begin); break;
	case 3: PrintfRoute(begin); break;
	case 0: break;
	default:
		cout << "������� ������������ ��������" << endl;
	}
}

void PrintfRoute(List*begin) {
	system("cls");
	List* copy = begin;
	int counter = 0;
	if (copy == nullptr)
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	while (copy != nullptr) {
		++counter;
		if (copy->bus.status)
		{
			cout << "#" << counter << endl;
			cout << "������� ��������: " << copy->bus.name << endl;
			cout << "����� ��������: " << copy->bus.busNumber << endl;
			cout << "����� ��������: " << copy->bus.route << endl;
			cout << "������: " << (copy->bus.status ? "�������" : "����") << endl;
		}
		copy = copy->next;
	}
	system("pause");
	system("cls");
}

void PrintfPark(List*begin) {
	system("cls");
	List* copy = begin;
	int counter = 0;
	if (copy == nullptr)
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	while (copy != nullptr) {
		++counter;
		if (!copy->bus.status)
		{
			cout << "#" << counter << endl;
			cout << "������� ��������: " << copy->bus.name << endl;
			cout << "����� ��������: " << copy->bus.busNumber << endl;
			cout << "����� ��������: " << copy->bus.route << endl;
			cout << "������: " << (copy->bus.status ? "�������" : "����") << endl;
		}
		copy = copy->next;
	}
	system("pause");
	system("cls");
}

void PrintfList(List*begin) {
	system("cls");
	List* copy = begin;
	int counter = 0;
	if (copy == nullptr)
	{
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	while (copy != nullptr) {
		++counter;
		cout << "#" << counter << endl;
		cout << "������� ��������: " << copy->bus.name << endl;
		cout << "����� ��������: " << copy->bus.busNumber << endl;
		cout << "����� ��������: " << copy->bus.route << endl;
		cout << "������: " << (copy->bus.status ? "�������" : "����") << endl;
		copy = copy->next;
	}
	system("pause");
	system("cls");
}

void SearchBus(List*begin, int marker) {
	system("cls");
	List* copy = begin;
	int counter = 0;
	string number;
	if (marker == 2) {
		cout << "����� ������ �� ������ ��������" << endl << endl;
		cout << "������� ����� ��������: ";
		cin >> number;
		while (copy)
		{
			++counter;
			if ((*copy).bus.busNumber == number) {
				cout << "#" << counter << endl;
				cout << "������� ��������: " << copy->bus.name << endl;
				cout << "����� ��������: " << copy->bus.busNumber << endl;
				cout << "����� ��������: " << copy->bus.route << endl;
				cout << "������: " << (copy->bus.status ? "�������" : "����") << endl;
			}
			copy = copy->next;
		}
	}
	if (marker == 1) {
		cout << "����� ������ �� ����� ��������" << endl << endl;
		cout << "������� ��� ��������: ";
		cin.get();
		getline(cin, number);
		while (copy)
		{
			++counter;
			if ((*copy).bus.name == number) {
				cout << "#" << counter << endl;
				cout << "������� ��������: " << copy->bus.name << endl;
				cout << "����� ��������: " << copy->bus.busNumber << endl;
				cout << "����� ��������: " << copy->bus.route << endl;
				cout << "������: " << (copy->bus.status ? "�������" : "����") << endl;
			}
			copy = copy->next;
		}
	}
	if (marker == 0) {
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

void DeleteBus(List*begin, int marker) { //�������� �������� ������
	system("cls");
	List* temp = begin;
	List *helping = NULL;
	string number;

	if (marker == 0) {
		system("cls");
		return;
	}

	if (marker == 2) {
		cout << "����� ������ �� ������ ��������" << endl << endl;
		cout << "������� ����� ��������: ";
		cin >> number;
		while (temp && (*temp).bus.busNumber != number)
		{
			helping = temp; // ���������� �������� temp
			temp = temp->next;
		}

	}
	if (marker == 1) {
		cout << "����� ������ �� ����� ��������" << endl << endl;
		cout << "������� ��� ��������: ";
		cin.get();
		getline(cin, number);
		while (temp && (*temp).bus.name != number)
		{
			helping = temp; // ���������� �������� temp
			temp = temp->next;
		}
	}
	if (begin == temp) // ���� ������� ������� ���� ������� ������
	{
		begin = temp->next;
	}
	else
	{
		if (temp)
			helping->next = temp->next;
	}
	delete (temp);
	cout << "������� �����." << endl;

	system("pause");
	system("cls");
}


string setRoute(List*begin) {
	cout << "------------------------------------------------------" << endl << endl;
	List* copy = begin;
	string number;
	cout << "������� ����� ��������, ������� �������� ����: ";
	cin >> number;
	while (copy)
	{
		if ((*copy).bus.busNumber == number) {
			copy->bus.status = true;
			system("cls");
			return "������� " + copy->bus.busNumber + " ������� ����";
		}
		copy = copy->next;
	}
	system("cls");
	return "�� ������";
	
}

string setPark(List*begin) {
	cout << "------------------------------------------------------" << endl << endl;
	List* copy = begin;
	string number;
	cout << "������� ����� ��������, ������� ������ ����: ";
	cin >> number;
	while (copy)
	{
		if ((*copy).bus.busNumber == number) {
			copy->bus.status = false;
			system("cls");
			return "������� " + copy->bus.busNumber + " ������ ����";
		}
		copy = copy->next;
	}
	system("cls");
	return "�� ������";
}