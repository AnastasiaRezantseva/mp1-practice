#ifndef _CLIENT_H 
#define _CLIENT_H

#include <string>
#include "Container.h"
#include "Product.h"
#include "Receipt.h"

std::string getPath();
TContainer<Base> createStorage(std::string path);
void getReceipt(const TContainer<Base>& storage);

#endif _CLIENT_H
