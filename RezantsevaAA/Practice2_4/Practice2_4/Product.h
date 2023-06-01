#ifndef _PRODUCT_H //Product and Base
#define _PRODUCT_H
#include <fstream>

class Product
{
private:
	std::string code;
	std::string name;
	double cost;

public:
	
    Product();
    Product(const std::string& ncode, const std::string& nname, const double& ncost);
    Product(const Product& new_product);

    
    friend std::ifstream& operator>>(std::ifstream& buf, Product& data);
    friend std::istream& operator>>(std::istream& buf, Product& data);
    friend std::ostream& operator<<(std::ostream& buf, const Product& data);

    const Product& operator=(const Product& new_product); //!!!
    bool operator==(const std::string& str) const;
    bool operator==(const Product& prod) const;


	std::string get_name() const;
	std::string get_code() const;
    double get_cost() const;
};

class Base {
private:
	Product product;
	int count;

public:
	Base();
	
	friend std::ifstream& operator>>(std::ifstream& buf, Base& data);
	friend std::ostream& operator<<(std::ostream& buf, const Base& data);
	friend std::istream& operator>>(std::istream& buf, Base& data);

	bool operator == (const std::string& str) const;
	bool operator == (const Base& base) const;
	bool operator != (const Base& base) const;
	Base& operator+= (int add_count);

	Product get_product() const;
	int get_count() const;
	void set_count(const int ucount);
};

#endif _PRODUCT_H