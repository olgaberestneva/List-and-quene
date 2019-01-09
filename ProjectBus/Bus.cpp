#include "stdafx.h"

string AddList(List**begin) { //добавление элемента списка
	cout << "------------------------------------------------------" << endl << endl;
	Bus bus = testList();
	

	if (*begin == nullptr) {//если список пуст
		*begin = new List();
		(*begin)->bus = bus;
		(*begin)->next = nullptr;
	}
	else //если список не пуст
	{
		List *copy = *begin;
		while (copy->next) copy = copy->next;
		copy->next = new List;
		copy = copy->next;
		copy->bus = bus;
		copy->next = nullptr;
	}
	system("cls");
	return "Добавлена запись";
}

Bus testList() { //проверка на заполненность
	Bus test;
	do {
		cout << "Введите номер автобуса: ";
		cin >> test.busNumber;
	} while (test.busNumber == "");
	do {
		cout << "Введите ФИО водителя: ";
		cin.get();
		getline(cin, test.name);
	} while (test.busNumber == "");
	do {
		cout << "Введите маршрут: ";
		cin >> test.route;
	} while (test.busNumber == "");
	test.status = false;
	return test;
}

void Printf(List*begin, int marker) {//вывод элеиентов списка
	switch (marker)
	{
	case 1: PrintfList(begin); break;
	case 2: PrintfPark(begin); break;
	case 3: PrintfRoute(begin); break;
	case 0: break;
	default:
		cout << "Введено неправильное значение" << endl;
	}
}

void PrintfRoute(List*begin) {
	system("cls");
	List* copy = begin;
	int counter = 0;
	if (copy == nullptr)
	{
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	while (copy != nullptr) {
		++counter;
		if (copy->bus.status)
		{
			cout << "#" << counter << endl;
			cout << "Фамилия водителя: " << copy->bus.name << endl;
			cout << "Номер автобуса: " << copy->bus.busNumber << endl;
			cout << "Номер маршрута: " << copy->bus.route << endl;
			cout << "Статус: " << (copy->bus.status ? "маршрут" : "парк") << endl;
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
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	while (copy != nullptr) {
		++counter;
		if (!copy->bus.status)
		{
			cout << "#" << counter << endl;
			cout << "Фамилия водителя: " << copy->bus.name << endl;
			cout << "Номер автобуса: " << copy->bus.busNumber << endl;
			cout << "Номер маршрута: " << copy->bus.route << endl;
			cout << "Статус: " << (copy->bus.status ? "маршрут" : "парк") << endl;
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
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	while (copy != nullptr) {
		++counter;
		cout << "#" << counter << endl;
		cout << "Фамилия водителя: " << copy->bus.name << endl;
		cout << "Номер автобуса: " << copy->bus.busNumber << endl;
		cout << "Номер маршрута: " << copy->bus.route << endl;
		cout << "Статус: " << (copy->bus.status ? "маршрут" : "парк") << endl;
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
		cout << "Поиск записи по номеру автобуса" << endl << endl;
		cout << "Введите номер автобуса: ";
		cin >> number;
		while (copy)
		{
			++counter;
			if ((*copy).bus.busNumber == number) {
				cout << "#" << counter << endl;
				cout << "Фамилия водителя: " << copy->bus.name << endl;
				cout << "Номер автобуса: " << copy->bus.busNumber << endl;
				cout << "Номер маршрута: " << copy->bus.route << endl;
				cout << "Статус: " << (copy->bus.status ? "маршрут" : "парк") << endl;
			}
			copy = copy->next;
		}
	}
	if (marker == 1) {
		cout << "Поиск записи по имени водителя" << endl << endl;
		cout << "Введите имя водителя: ";
		cin.get();
		getline(cin, number);
		while (copy)
		{
			++counter;
			if ((*copy).bus.name == number) {
				cout << "#" << counter << endl;
				cout << "Фамилия водителя: " << copy->bus.name << endl;
				cout << "Номер автобуса: " << copy->bus.busNumber << endl;
				cout << "Номер маршрута: " << copy->bus.route << endl;
				cout << "Статус: " << (copy->bus.status ? "маршрут" : "парк") << endl;
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

void DeleteBus(List*begin, int marker) { //удаление элемента списка
	system("cls");
	List* temp = begin;
	List *helping = NULL;
	string number;

	if (marker == 0) {
		system("cls");
		return;
	}

	if (marker == 2) {
		cout << "Поиск записи по номеру автобуса" << endl << endl;
		cout << "Введите номер автобуса: ";
		cin >> number;
		while (temp && (*temp).bus.busNumber != number)
		{
			helping = temp; // предыдущее значение temp
			temp = temp->next;
		}

	}
	if (marker == 1) {
		cout << "Поиск записи по имени водителя" << endl << endl;
		cout << "Введите имя водителя: ";
		cin.get();
		getline(cin, number);
		while (temp && (*temp).bus.name != number)
		{
			helping = temp; // предыдущее значение temp
			temp = temp->next;
		}
	}
	if (begin == temp) // если элемент который надо удалить первый
	{
		begin = temp->next;
	}
	else
	{
		if (temp)
			helping->next = temp->next;
	}
	delete (temp);
	cout << "Элемент удалён." << endl;

	system("pause");
	system("cls");
}


string setRoute(List*begin) {
	cout << "------------------------------------------------------" << endl << endl;
	List* copy = begin;
	string number;
	cout << "Введите номер автобуса, который покидает парк: ";
	cin >> number;
	while (copy)
	{
		if ((*copy).bus.busNumber == number) {
			copy->bus.status = true;
			system("cls");
			return "Автобус " + copy->bus.busNumber + " покинул парк";
		}
		copy = copy->next;
	}
	system("cls");
	return "Не найден";
	
}

string setPark(List*begin) {
	cout << "------------------------------------------------------" << endl << endl;
	List* copy = begin;
	string number;
	cout << "Введите номер автобуса, который прибыл парк: ";
	cin >> number;
	while (copy)
	{
		if ((*copy).bus.busNumber == number) {
			copy->bus.status = false;
			system("cls");
			return "Автобус " + copy->bus.busNumber + " прибыл парк";
		}
		copy = copy->next;
	}
	system("cls");
	return "Не найден";
}