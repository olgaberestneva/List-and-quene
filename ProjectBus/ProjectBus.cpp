// ProjectBus.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void menuList();
void menuQueue();
void baners(string, string);

int markers;
int position;

int main()
{
	system("cls");
	setlocale(LC_ALL, "rus");
	while (true)
	{
		baners("Курсовая работа студентки 1 курса ФИТР", "Берестневой Ольги");
		cout << "1 - Программа для работы с линейным списком" << endl;
		cout << "2 - Программа для работы с очередью" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберите желаемую операцию: ";
		cin >> position;
		switch (position)
		{
		case 0: exit(0); break;
		case 1: menuList(); break;
		case 2: menuQueue(); break;
		default:
			system("cls");
			break;
		}
	}
    return 0;
}

void menuList() {
	system("cls");
	List *begin = nullptr;
	string text = "";
	while (true) {
		baners("Работа с линейным списком", text);
		cout << "1 - Добавить новый автобус" << endl;
		cout << "2 - Удаление автобуса" << endl;
		cout << "3 - Вывести список" << endl;
		cout << "4 - Поиск автобуса" << endl;
		cout << "5 - Отправить на маршрут" << endl;
		cout << "6 - Оптравить в парк" << endl;
		cout << "7 - Назад" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберите желаемую операцию: ";
		cin >> position;
		switch (position)
		{
		case 0: exit(0); break;
		case 1: text = AddList(&begin); break;
		case 2:
			system("cls");
			do
			{
				cout << "Удаляем по ..." << endl;
				cout << "1 - имени водителя " << endl;
				cout << "2 - номеру автобуса " << endl;
				cout << "0 - Назад " << endl;
				cout << "Выберите операцию: ";
				cin >> markers;
				DeleteBus(begin, markers);
			} while (markers > 0 && markers < 3);
			
			break;
		case 3: 
			system("cls");
			do
			{
				cout << "Вывести ..." << endl;
				cout << "1 - все автобусы " << endl;
				cout << "2 - автобусы находящие в парке " << endl;
				cout << "3 - автобусы находящие в маршруте " << endl;
				cout << "0 - Назад " << endl;
				cout << "Выберите операцию: ";
				cin >> markers;
				Printf(begin, markers);
				break;
			} while (markers > 0 && markers < 4);
			text = "";
			break;
		case 4: 
			system("cls");
			do
			{
				cout << "Ищем по ..." << endl;
				cout << "1 - имени водителя: " << endl;
				cout << "2 - номеру автобуса: " << endl;
				cout << "0 - Назад " << endl;
				cout << "Выберите операцию: ";
				cin >> markers;
				SearchBus(begin, markers);
			} while (markers > 0 && markers < 3);
			text = "";
			break;
		case 5: text = setRoute(begin); break;
		case 6: text = setPark(begin); break;
		case 7: main(); break;
		default:
			system("cls");
			break;
		}
	}
}

void menuQueue() {
	queue *QUEUE = init();
	string text = "";
	while (true)
	{
		system("cls");
		baners("Работа с очередью", text);
		cout << "1 - Добавить элемент в очередь" << endl;
		cout << "2 - Удалить элемент из очереди" << endl;
		cout << "3 - Вывести элементы очереди" << endl;
		cout << "4 - Получить ответ по формуле" << endl;
		cout << "7 - Назад" << endl;
		cout << "0 - Выход" << endl;
		cout << "Выберите желаемую операцию: ";
		cin >> position;
		switch (position)
		{
		case 0: exit(0); break;

		case 1: text = back(QUEUE); break;
		case 2: text = pop(QUEUE); break;
		case 3: show(QUEUE); break;
		case 4: sum(QUEUE); break;

		case 7: main(); break;
		default:
			system("cls");
			break;
		}

	}
}

void baners(string name, string option) {
	cout << "------------------------------------------------------" << endl;
	cout << name << endl;
	cout << endl;
	cout << option << endl;
	cout << "------------------------------------------------------" << endl << endl;
}