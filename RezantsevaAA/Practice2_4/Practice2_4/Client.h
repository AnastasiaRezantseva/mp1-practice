#ifndef _CLIENT_H 
#define _CLIENT_H

#include <string>
#include "Container.h"
#include "Product.h"
#include "Receipt.h"

template <typename Type>
void data_base(const TContainer<Type>& base, const std:: string& filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		file << base << std::endl;
	}
	file.close();
}

std::string getPath();
TContainer<Base> createStorage( std::string& path);
void getReceipt(const TContainer<Base>& storage); // TContainer<TReceipt>

#endif _CLIENT_H
