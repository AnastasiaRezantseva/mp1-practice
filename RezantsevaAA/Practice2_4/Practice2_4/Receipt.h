#ifndef _RECEIPT_H
#define _RECEIPT_H
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
#endif _RECEIPT_H
