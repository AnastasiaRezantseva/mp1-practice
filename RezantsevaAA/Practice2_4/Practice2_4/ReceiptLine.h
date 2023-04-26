#ifndef _RECIPTLINE_H
#define _RECIPTLINE_H
#include <string>
#include "Container.h"
using namespace std;

class TReceiptLine : public TContainer
{
public:
	int count; //kolichestvo
	double sum;
	TProduct* product;
};

#endif _RECIPTLINE_H
