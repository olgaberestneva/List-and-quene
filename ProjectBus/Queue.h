#pragma once
#include "stdafx.h"

struct MyQueue
{
	double value;
	MyQueue *next;
};
struct queue //����������� ���������� �� ������ � ����� �������
{
	MyQueue*head; //������ �������
	MyQueue*tail; //����� �������
	int size; //������ �������
};
queue *init(); //������������� �������
string back(queue *); //���������� � ������� � �����
string pop(queue *); //�������� ������� �������� �������

void show(queue*); //����� �������


void sum(queue*); //������ �� �������