//Product and Base realization
#include "Product.h"
#include <string>

//Product's functions realization

Product::Product()
{
    code = '*';
    name = '*';
    cost = 0;
}

Product::Product(const std::string& ncode, const std::string& nname, const double& ncost)
{
    code = ncode;
    name = nname;
    cost = ncost;

}

Product::Product(const Product& new_product)
{
    code = new_product.code;
    name = new_product.name;
    cost = new_product.cost;
}

//overloaded operations
std::ifstream& operator>>(std::ifstream& buf, Product& data)
{
    buf >> data.code >> data.name >> data.cost;
    return buf;
}

std::ostream& operator<<(std::ostream& buf, const Product& data)
{
    buf << data.code << " " << data.name << " " << data.cost << " ";
    return buf;
}

std::istream& operator>>(std::istream& buf, Product& data)
{
    buf >> data.code >> data.name >> data.cost;
    return buf;
}

const Product& Product::operator=(const Product& new_product)
{
    if (this != &new_product) {
        code = new_product.code;
        name = new_product.name;
        cost = new_product.cost;
    }
    return *this;
}

bool Product::operator==(const std::string& str) const {
    return (code == str || name == str);
}

bool Product::operator==(const Product& prod) const
{
    return (code == prod.code && name == prod.name && cost == prod.cost);
}

std::string Product::get_name() const {
    return name;
}

std::string Product::get_code() const {
    return code;
}

double Product::get_cost() const {
    return cost;
}

//Base's functions realization

Base::Base()
{
    count = 0;
}

//overloaded operations
std::ifstream& operator>>(std::ifstream& buf, Base& data) {
    buf >> data.product >> data.count;
    return buf;
}

std::ostream& operator<<(std::ostream& buf, const Base& data) {
    buf << data.product << " " << data.count << std::endl;
    return buf;
}

std::istream& operator>>(std::istream& buf, Base& data) {
    buf >> data.product >> data.count;
    return buf;
}

bool Base::operator == (const std::string& str) const
{
    return product == str;
}

bool Base::operator == (const Base& base) const
{
    return product == base.product;
}

bool Base::operator != (const Base& base) const
{
    return !(*this == base);
}

Base& Base::operator+= (int add_count) {
    count += add_count;

    return *this;
}

//Base functions
Product Base::get_product() const
{
    return product;
}

int Base::get_count() const
{
    return count;
}

void Base::set_count(const int ucount)
{
    count = ucount;
}
