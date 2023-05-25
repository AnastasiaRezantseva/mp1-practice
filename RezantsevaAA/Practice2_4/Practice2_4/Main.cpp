#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "Client.h"
#include "Receipt.h"

using namespace std;

//C:\Users\Anastasiya\Desktop\test\mp1-practice\RezantsevaAA\Practice2_4\Practice2_4\Storage.txt
//C:\Users\itmm-y23b\Desktop\directory\mp1-practice\RezantsevaAA\Practice2_4\Practice2_4\Storage.txt
int main()
{
	std::string pathToStorage = getPath();
	TContainer<Base> storage = createStorage(pathToStorage);
	getReceipt(storage);
	return 0;

}