#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <string>
using namespace std;

struct TData {
	int year;
	int month;
	int day;
};

struct TTime {
	int hour;
	int minute;
	int seconds;
};

class TContainer 
{
public:
	int n;
	typedef TReceiptLine TElement;
	TElement* elements; //massiv elementov
	
};


class TReceiptLine: public TContainer
{
public:
	int count; //kolichestvo
	double sum;
	TProduct* product;
};


class TProduct : public TReceiptLine
{
public:
	long code;
	string name;
	double cost;
};

class TReceipt : public TContainer
{
public:
	long number; // index
	TData date;
	TTime time;
	TContainer products;
};

#endif _CONTAINER_H