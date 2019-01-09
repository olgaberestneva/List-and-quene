#pragma once
#include "stdafx.h"

struct MyQueue
{
	double value;
	MyQueue *next;
};
struct queue //определение указателей на начало и конец очереди
{
	MyQueue*head; //начало очереди
	MyQueue*tail; //конец очереди
	int size; //размер очередь
};
queue *init(); //инициализация очереди
string back(queue *); //добавление в очередь в конец
string pop(queue *); //удаление первого элемента очереди

void show(queue*); //вывод очереди


void sum(queue*); //расчет по формуле