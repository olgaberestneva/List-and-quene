#include "stdafx.h"

queue *init()  
{
	queue *lt = new queue;

	lt->size = 0; //размер ноль
	lt->head = NULL; //начальный пустой
	lt->tail = lt->head; //последный указывает на первый

	return lt;

}
/* Добавляем элемент в конец списка */
string back(queue *lt)
{
	cout << "------------------------------------------------------" << endl;
	double data;
	cout << "Введите число: ";
	cin >> data;
	MyQueue * node = new MyQueue;
	node->value = data;
	if (lt->tail != NULL) //если последний не пуст
		lt->tail->next = node; //то последним становиться добавленный элемент
	else { //если последнего нету, а значит очередь пуста
		lt->head = node; //то первым добавленный эл-т
	}

	lt->tail = node; //последним становиться добавленный эл-т
	lt->size += 1; //увеличиваем размер
	system("cls");
	return "Элемент добавлен в очередь";
}
/* Извлекаем элемент из начала очереди */
string pop(queue *lt)
{
	if (lt->size == 0) {
		/* Список пуст */
		return "Очередь пуста!";
	}

	MyQueue *node = lt->head; //получаем первый элемент очереди
	double ret_val = node->value;

	lt->size -= 1; //уменьшаем размер очереди
	lt->head = node->next; //первым становиться второй элемент очереди

	free(node); //удаляем

	if (lt->size == 0) {
		/* Это был последний элемент */
		lt->head = NULL; //делаем указатели пустыми
		lt->tail = NULL;
	}

	return "Элемент " + to_string(ret_val) + " вышел";
}
void show(queue * lt) 
{
	cout << "------------------------------------------------------" << endl;
	MyQueue *tmp = lt->head;
	cout << "Очередь: ";
	for(int i = 0; i<lt->size; i++)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
	system("pause");
	system("cls");
}


void sum(queue*begin)
{
	system("cls");
	double sum = 0, i = 0, x;
	string text;
	MyQueue*copy = begin->head;
	if (begin->size == 0) {
		cout << "Список пуст." << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "Введите число: ";
		cin >> x;
		for (int i = 0; i < begin->size; i++)
		{
			sum += copy->value * pow(x, i);
			text += to_string(copy->value) + " * " + to_string(x) + "^";
			if (i == begin->size - 1)
				text += to_string(i) + " = ";
			else
				text += to_string(i) + " + ";
			copy = copy->next;
		}
	}
	system("cls");
	cout << "Получившее выражение" << endl;
	cout << text << " ? " << endl;
	cout << "Ответ: " << sum << endl;
	system("pause");
	system("cls");
}
