#define _CRT_SECURE_NO_WARNINGS
#include "Receipt.h"
#include "Product.h"
#include "time.h"

void TDate::now() const {
	time_t rawtime; //creates and object of the built in time function
	time(&rawtime); //gets the time from the computer
	tm* timeinfo = localtime(&rawtime); //store that time here
	std::cout << asctime(timeinfo) << std::endl;
}

Receipt :: Receipt()
{
	num = 0; 
	size = 0; 
	date.timeinfo = NULL;
}

Receipt::Receipt(const Receipt& receipt)
{
	num = receipt.num;
	size = receipt.size;
	date = receipt.date;
	products = TContainer<ReceiptLine>(receipt.products);
}

std::istream& operator>>(std::istream& buf, Receipt& date)
{
	buf >> date.num >> date.size >> date.products;
	return buf;
}

std::ostream& operator<<(std::ostream& buf, const Receipt& receipt)
{
	buf << "\nReceipt's id: " << receipt.num << std::endl;
	buf << "Time of receipt formation: ";
	receipt.date.now();
	buf << "Products: \n";
	for (int i = 0; i < receipt.size; i++) {
		buf << receipt.products[i];
	}
	buf << std::endl;
	buf << "Total cost = " << receipt.sum() << '\n';
	return buf;
}

Receipt& Receipt :: operator=(const Receipt& receipt)
{
	num = receipt.num;
	size = receipt.size;
	date = receipt.date;
	products = receipt.products;
	return *this;
}

void Receipt::add(const Product& product, const int& count)
{
	ReceiptLine tmp(product, count, product.get_cost());
	add(tmp, count);
}

void Receipt::add(const ReceiptLine& line, const int& count)
{
	int id = products._find(line);
	if (id != -1)
	{
		if (products[id] == line) {
			products[id] += count;
			return;
		}
	}
	size += 1;
	products.push_back(line);
}

void Receipt::remove(const ReceiptLine& product, const int& count)
{
	for (int i = 0; i < count; i++) {
		if (products[i] == product) {
			if (products[i] <= count) { products.pop_id(i); }
			else { products[i] -= count; }
		}
	}
}

void Receipt::print_basket() const {
	if (!size) {
		std::cout << "Nothing in the cart. Add something!" << std::endl;
		return;
	}
	std::cout << "Your products: " << std::endl;
	std::cout << products << std::endl;
}

double Receipt::sum() const
{
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += products[i].get_sum();
	}
	return sum;
}

void Receipt::print_receiptline() const {
	if (!size) std::cout << "Nothing in the cart. Add something!" << std::endl;
	std::cout << "Your products:: " << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << products[i] << std::endl;
}

void Receipt:: pdate() {
	date.now();
}

void Receipt::set_num(const int& q) {
	(q > 0) ? num = q : num = 1;
}

int Receipt::len() const
{
	return size;
}

bool Receipt::empty()
{
	return size == 0;
}

ReceiptLine* Receipt::find(const Base& product) const
{
	for (int i = 0; i < size; i++)
	{
		if (products[i] == product)
			return &products[i];
	}
	return nullptr;
}
ReceiptLine* Receipt::find(const std::string& product) const
{
	ReceiptLine tmp;
	for (int i = 0; i < size; i++)
	{
		if (products[i] == product)
			return &products[i];
	}
	return nullptr;
}