#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Client.h"

std::string getPath()
{
	std::string path;
	std::cout << "Input a path: ";
	std::cin >> path;

	return path;
} 

TContainer<Base> createStorage(std::string path) {
	TContainer<Base> storage; // Storage of products
	read(path, storage);

	return storage;
}

void getReceipt(const TContainer<Base>& storage)
{
	Receipt basket;
	basket.set_num(1);
	std::cout << "Our range: " << std::endl;
	std::cout << storage << std::endl;

	while (true) {

		std::cout << "Enter \n 0: complete shopping and print receipt\n " << "1: add some products \n " << "2: remove some products \n " << "3: show basket \n " << "4: print range \n " << std::endl;

		int client, flag = 1;
		std::cin >> client;

		if (client == 0) {
			flag = 0;
			if (basket.empty())
			{
				std::cout << "Nothing in the basket. Add something.\n" << std::endl;
				continue;
			}
			std::cout << basket << '\n';
			std::cout << "Thank you for your purchase " << std::endl;
			return;
		}

		if (client == 1) 
		{
			flag = 0;
			std::cout << "Input barcode of product and a count." << std::endl;
			std::string product;
			std::cin >> product;

			int count = 0, ucount;

			//product "merchandise"
			Base merchandise = *storage.find(product);
			count = merchandise.get_count();

			if (storage.find(product) == nullptr)
			{
				std::cout << "Wrong barcode." << std::endl;
				continue;
			}

			std::cin >> ucount;
			//changing count in the base
			if (ucount < 0 || ucount > count) {
				std::cout << "Wrong count. You can input a count of products only between 0 and " << count << std::endl;
				continue;
			}
			if (ucount == 0) {
				continue;
			}

			storage[storage._find(merchandise)].set_count(merchandise.get_count() - ucount);

			//add merchandise in the basket
			if (basket.find(merchandise) != nullptr)
				basket.add(*basket.find(merchandise), ucount);
			else {
				basket.add(merchandise.get_product(), ucount);

			}
			std::cout << "\nAdded \n" << std::endl;
		}
		if (client == 2) {

			flag = 0;
			basket.print_basket();
			if (basket.empty())
			{
				std::cout << "Basket is empty. Add something.\n" << std::endl;
				continue;
			}
			std::cout << "Which one do you want to remove ? Input barcode of product.\n" << std::endl;
			std::string product;
			std::cin >> product;
			int ucount;

			//find element in the basket
			ReceiptLine* tmp = basket.find(product);
			if (tmp == nullptr) {
				std::cout << "You dont have this product in the basket. \n" << std::endl;
				continue;
			}

			//client count 
			std::cout << "Input a count of products between 0 and " << tmp->get_count() << std::endl;
			std::cin >> ucount;
			if (ucount < 0 || ucount > tmp->get_count()) {
				std::cout << "Wrong count. Try again." << std::endl;
				continue;
			}

			// add deleted from the basket elements to the storage
			int index = storage._find(product);
			if (index >= 0 && index < storage.len())
			{
				storage[index] += ucount;
			}

			//remove 
			basket.remove(*tmp, ucount);
			std::cout << "\nDeleted \n" << std::endl;
			basket.print_basket();

		}
		if (client == 3)
		{
			flag = 0;
			if (basket.empty())
			{
				std::cout << "Nothing in the basket. Add something.\n" << std::endl;
				continue;
			}
			basket.print_basket();
		}
		if (client == 4)
		{
			std::cout << storage;
			flag = 0;
		}
		if (flag) std::cout << "Input Date is wrong. Try again. \n" << std::endl;
	}

	std::cout << "Thank you for your purchase. " << std::endl;

}
