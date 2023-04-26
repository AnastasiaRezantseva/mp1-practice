#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <string>
#include "Container.h"
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

class TReceipt : public TContainer
{
public:
	long number; // index
	TData date;
	TTime time;
	TContainer products;
};
#endif _PRODUCT_H