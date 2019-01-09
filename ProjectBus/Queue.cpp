#include "stdafx.h"

queue *init()  
{
	queue *lt = new queue;

	lt->size = 0; //������ ����
	lt->head = NULL; //��������� ������
	lt->tail = lt->head; //��������� ��������� �� ������

	return lt;

}
/* ��������� ������� � ����� ������ */
string back(queue *lt)
{
	cout << "------------------------------------------------------" << endl;
	double data;
	cout << "������� �����: ";
	cin >> data;
	MyQueue * node = new MyQueue;
	node->value = data;
	if (lt->tail != NULL) //���� ��������� �� ����
		lt->tail->next = node; //�� ��������� ����������� ����������� �������
	else { //���� ���������� ����, � ������ ������� �����
		lt->head = node; //�� ������ ����������� ��-�
	}

	lt->tail = node; //��������� ����������� ����������� ��-�
	lt->size += 1; //����������� ������
	system("cls");
	return "������� �������� � �������";
}
/* ��������� ������� �� ������ ������� */
string pop(queue *lt)
{
	if (lt->size == 0) {
		/* ������ ���� */
		return "������� �����!";
	}

	MyQueue *node = lt->head; //�������� ������ ������� �������
	double ret_val = node->value;

	lt->size -= 1; //��������� ������ �������
	lt->head = node->next; //������ ����������� ������ ������� �������

	free(node); //�������

	if (lt->size == 0) {
		/* ��� ��� ��������� ������� */
		lt->head = NULL; //������ ��������� �������
		lt->tail = NULL;
	}

	return "������� " + to_string(ret_val) + " �����";
}
void show(queue * lt) 
{
	cout << "------------------------------------------------------" << endl;
	MyQueue *tmp = lt->head;
	cout << "�������: ";
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
		cout << "������ ����." << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "������� �����: ";
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
	cout << "���������� ���������" << endl;
	cout << text << " ? " << endl;
	cout << "�����: " << sum << endl;
	system("pause");
	system("cls");
}
