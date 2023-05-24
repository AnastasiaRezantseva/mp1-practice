#ifndef _RECEIPT_H 
#define _RECEIPT_H 
#include <iostream>
#include <fstream>

#include "Container.h"
#include "ReceiptLine.h"
#include "Product.h"

struct TDate
{
	tm* timeinfo;
	void now() const;
};

class Receipt
{
private:
	int num; // id of receipt
	int size; //length of receipt
	TDate date;
	TContainer<ReceiptLine> products;

public:

	Receipt();
	Receipt(const Receipt& receipt);

	virtual ~Receipt() {}

	friend std::istream& operator>>(std::istream& buf, Receipt& date);
	friend std::ostream& operator<<(std::ostream& buf, const Receipt& date);

	Receipt& operator=(const Receipt& receipt);
	
	void add(const ReceiptLine& product, const int& count = 0);
	void add(const Product& product, const int& count);
	void remove(const ReceiptLine& product, const int& count);

	void print_receiptline() const;
	void pdate();
	void set_num(const int& q);
	void print_basket() const;
	double sum() const;

	ReceiptLine* find(const Base& product) const;
	ReceiptLine* find(const std::string& product) const;

	int len() const;
	bool empty();
};

#endif _RECEIPT_H
