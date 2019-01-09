#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Bus
{
	string busNumber;
	string name;
	string route;
	bool status;
};
struct List
{
	Bus bus;
	List *next;
};

string AddList(List**);
Bus testList();

void Printf(List*, int);
void PrintfRoute(List*);
void PrintfPark(List*);
void PrintfList(List*);

void DeleteBus(List*, int);
void SearchBus(List*, int);

string setRoute(List*);
string setPark(List*);