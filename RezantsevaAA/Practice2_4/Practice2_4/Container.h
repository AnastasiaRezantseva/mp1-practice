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
	TContainer(int _size = 50)
	{
		elem = new TELEM[size];
	};

	TContainer(const TContainer& _cnt)
	{
		size = _cnt.size;
		count = _cnt.count;
		elem = new TELEM[size];
		for (int i = 0; i < count; i++)
			elem[i] = _cnt.elem[i];
	};

	~TContainer()
	{
			if (size > 0) {
				delete[] elem;
				elem = 0;
				count = 0;
				size = 0;
			}
	};

	const int& Сount() const { return count; }
	int& Сount() { return count; }
	const int& Sizestep() const { return sizestep; }
	void Add(TELEM _elm) // добавить элемент
	{
		if (_find(_elm) == -1)
		{
			if (size == count) resize();
			elem[count++] = _elm;
		}
	}; 

	void Del(TELEM _elm) // удалить элемент по его значению
	{
		Del(_find(_elm));
	}; 

	void Del(int index) // удалить элемент по его номеру
	{
		if (index > -1 && index < count)
			for (int i = index; i < count - 1; i++)
				elem[i] = elem[i + 1];
		count--;
	};

	TELEM& operator[](int index) // индексация по номеру
	{
		if (index < 0 || index >= count)
		{
			TContainerExeption expt = cntINDOUTOFRANGE;
			throw expt;
		}
		return elem[index]; // тип возвращаемого значения
	}; 
		TELEM& operator[](const TELEM& _elm) // индексация по содержанию
		{
			int index;
			if ((index = _find(_elm)) == -1)
			{
				TContainerExeption expt = cntVALOUTOFRANGE;
				throw expt;
			}
			return elem[index]; // тип возвращаемого значения
		};

		const TELEM& operator[](int index) const; // индексация по номеру
		const TELEM& operator[](const TELEM& _elm) const; // индексация по содержанию
		
		TContainer& operator=(const TContainer& _cnt) // присваивание контейнеров
		{
			if (this != &_cnt) {
				delete[] elem;;
				size = _cnt.size;
				count = _cnt.count;
				elem = new TELEM[size];
				for (int i = 0; i < count; i++)
					elem[i] = _cnt.elem[i];
			}
			return *this;
		};

		TContainer operator+(const TContainer& _cnt) // объединение контейнеров
		{
			int i;
			TContainer<TELEM> tmp(count + _cnt.count + sizestep);
			for (i = 0; i < count; i++)
				tmp.elem[i] = elem[i];
			tmp.count = count;
			for (i = 0; i < _cnt.count; i++)
				tmp.Add(_cnt.elem[i]);
			return tmp;
		};

		TContainer operator*(const TContainer& _cnt) // пересечение контейнеров
		{
			int i;
			int ss = count;
			if (ss < _cnt.count) ss = _cnt.count;
			TContainer<TELEM> tmp(ss + sizestep);
			tmp.count = 0;
			for (i = 0; i < count; i++)
				if (_cnt._find(elem[i]) != -1) tmp.elem[tmp.count++] =
					elem[i];
			return tmp;
		};

		TContainer operator-(const TContainer& _cnt) // разность контейнеров
		{
			int i;
			TContainer<TELEM> tmp(count + sizestep);
			tmp.count = 0;
			for (i = 0; i < count; i++)
				if (_cnt._find(elem[i]) == -1) tmp.elem[tmp.count++] =
					elem[i];
			return tmp;
		};

protected:
	void resize(int dsize = 0) // увеличить длину контейнера
	{
		if (dsize == 0) dsize = sizestep;
		size += dsize;
		TELEM* tmp = new TELEM[size];
		for (int i = 0; i < count; i++)
			tmp[i] = elem[i];
		delete[] elem;
		elem = tmp;
	}; 

	int _find(const TELEM& _elm) const // найти элемент
	{
		int nom = -1;
		int i = 0;
		while (i < count && nom == -1)
			if (elem[i] == _elm) nom = i; else i++;
		return nom;
	}; 
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

