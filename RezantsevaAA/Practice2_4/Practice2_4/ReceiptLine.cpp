//ReceiptLine
#include "ReceiptLine.h"
#include <iostream>

ReceiptLine::ReceiptLine()
{
	count = 0;
	product = nullptr;

}

ReceiptLine::ReceiptLine(const Product& pr, const int& ncount, const double& nsum)
{
	product = new Product;
	*product = pr;
	count = ncount;
}

std::ifstream& operator>>(std::ifstream& buf, ReceiptLine& line)
{
	if (line.product == nullptr) {
		line.product = new Product;
	}
	buf >> *(line.product) >> line.count;
	return buf;
}

std::ostream& operator<<(std::ostream& buf, const ReceiptLine& line)
{
	buf << *(line.product) << "Sum of this product = " << line.get_sum() << std::endl;
	return buf;
}

std::istream& operator>>(std::istream& buf, ReceiptLine& line)
{
	if (line.product == nullptr) line.product = new Product;
	buf >> *(line.product) >> line.count;
	return buf;
}

bool ReceiptLine::operator == (const ReceiptLine& tmp) const
{
	return (*(product) == *(tmp.product));
}

bool ReceiptLine::operator == (const Base& tmp) const
{
	return (*product == tmp.get_product());
}

bool ReceiptLine::operator != (const ReceiptLine& tmp) const {
	return !(product == tmp.product);
}

bool ReceiptLine::operator == (const std::string& tmp) const
{
	return *product == tmp;
}

bool ReceiptLine::operator <= (const int& ncount) const
{
	return count <= ncount;
}

ReceiptLine& ReceiptLine::operator = (const ReceiptLine& tmp) {
	product = tmp.product;
	count = tmp.count;
	return *this;
}

ReceiptLine& ReceiptLine::operator += (const int& ncount)
{
	count += ncount;
	return *this;
}

ReceiptLine& ReceiptLine::operator -= (const int& ncount) {
	count -= ncount;
	return *this;
}

Product* ReceiptLine::get_product() const
{
	return product;
}

int ReceiptLine::get_count() const
{
	return count;
}

double ReceiptLine::get_sum() const
{
	return (count * (product->get_cost()));
}
