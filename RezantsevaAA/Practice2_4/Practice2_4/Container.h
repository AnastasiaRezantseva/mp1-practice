#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <string>
using namespace std;

enum TContainerExeption { cntINDOUTOFRANGE, cntVALOUTOFRANGE };
template <class TELEM>
class TContainer
{
protected:
	TELEM* elem; // массив хранимых элементов
	int size; // размер массива
	int count; // к-во реально хранимых элементов
	const static int sizestep = 10; // шаг наращивания размерамассива
public:
	TContainer(int _size = 50);
	TContainer(const TContainer& _cnt);
	~TContainer ();

	const int& Сount() const { return count; }
	int& Сount() { return count; }
	const int& Sizestep() const { return sizestep; }
	void Add(TELEM _elm); // добавить элемент
	void Del(TELEM _elm); // удалить элемент по его значению
	void Del(int index); // удалить элемент по его номеру
	TELEM& operator[](int index); // индексация по номеру
		TELEM& operator[](const TELEM& _elm); // индексация по содержанию
		const TELEM& operator[](int index) const; // индексация по номеру
		const TELEM& operator[](const TELEM& _elm) const; // индексация по содержанию
		TContainer& operator=(const TContainer& _cnt); // присваивание контейнеров
		TContainer operator+(const TContainer& _cnt); // объединение контейнеров
		TContainer operator*(const TContainer& _cnt); // пересечение контейнеров
		TContainer operator-(const TContainer& _cnt); // разность контейнеров
protected:
	void resize(int dsize = 0); // увеличить длину контейнера
		int _find(const TELEM& _elm) const; // найти элемент
};

/*
struct TData {
	int year;
	int month;
	int day;
};

struct TTime {
	int hour;
	int minute;
	int seconds;
};

class TContainer
{
public:
	int n;
	typedef TReceiptLine TElement;
	TElement* elements; //massiv elementov

};


class TReceiptLine : public TContainer
{
public:
	int count; //kolichestvo
	double sum;
	TProduct* product;
};


class TProduct : public TReceiptLine
{
public:
	long code;
	string name;
	double cost;
};

class TReceipt : public TContainer
{
public:
	long number; // index
	TData date;
	TTime time;
	TContainer products;
};
*/

#endif _CONTAINER_H

