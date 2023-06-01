#ifndef _RECIPTLINE_H 
#define _RECIPTLINE_H
#include "Product.h"
#include <fstream>

class ReceiptLine
{
private:
	int count;
	Product* product;
public:

	ReceiptLine();
	ReceiptLine(const Product& pr, const int& ncount, const double& nsum = 0);

	friend std::ifstream& operator>>(std::ifstream& buf, ReceiptLine& line);
	friend std::ostream& operator<<(std::ostream& buf, const ReceiptLine& line);
	friend std::istream& operator>>(std::istream& buf, ReceiptLine& line);

	bool operator == (const ReceiptLine& tmp) const;
	bool operator == (const Base& tmp) const;
	bool operator != (const ReceiptLine& tmp) const;
	bool operator == (const std::string& tmp) const;
	bool operator <= (const int& ncount) const;

	const ReceiptLine& operator = (const ReceiptLine& tmp); //!!!
	ReceiptLine& operator += (const int& ncount);
	ReceiptLine& operator -= (const int& ncount);

	Product* get_product() const;
	double get_sum() const;

	int get_count() const;
};
 
#endif _RECIPTLINE_H
