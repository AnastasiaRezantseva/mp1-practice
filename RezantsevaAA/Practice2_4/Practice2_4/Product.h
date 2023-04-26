#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <string>
#include "ReceiptLine.h"
using namespace std;

class TProduct : public TReceiptLine
{
public:
	long code;
	string name;
	double cost;
};

#endif _PRODUCT_H