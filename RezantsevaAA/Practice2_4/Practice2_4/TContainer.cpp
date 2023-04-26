#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
using namespace std;

template <class TELEM>
TContainer<TELEM>::TContainer(int _size) : size(_size), count(0)
{
	elem = new TELEM[size];
}

template <class TELEM>
TContainer<TELEM>::TContainer(const TContainer<TELEM>& _cnt)
{
	size = _cnt.size;
	count = _cnt.count;
	elem = new TELEM[size];
	for (int i = 0; i < count; i++)
		elem[i] = _cnt.elem[i];
}

template <class TELEM>
TContainer<TELEM>::~TContainer()
{
	if (size > 0) {
		delete[] elem;
		elem = 0;
		count = 0;
		size = 0;
	}
}

template <class TELEM>
void TContainer<TELEM>::resize(int dsize) // увеличить длину контейнера
{
	if (dsize == 0) dsize = sizestep;
	size += dsize;
	TELEM* tmp = new TELEM[size];
	for (int i = 0; i < count; i++)
		tmp[i] = elem[i];
	delete[] elem;
	elem = tmp;
}

template <class TELEM>
int TContainer<TELEM>::_find(const TELEM& _elm) const // найти элемент
{
	int nom = -1;
	int i = 0;
	while (i < count && nom == -1)
		if (elem[i] == _elm) nom = i; else i++;
	return nom;
}

template <class TELEM>
void TContainer<TELEM>::Add(TELEM _elm) // добавить элемент
{
	if (_find(_elm) == -1)
	{
		if (size == count) resize();
		elem[count++] = _elm;
	}
}

template <class TELEM>
void TContainer<TELEM>::Del(int index) // удалить элемент
{
	if (index > -1 && index < count)
		for (int i = index; i < count - 1; i++)
			elem[i] = elem[i + 1];
	count--;
}

template <class TELEM>
void TContainer<TELEM>::Del(TELEM _elm) // удалить элемент
{
	Del(_find(_elm)); // удалить удаляемый элемент 
}

template <class TELEM>
TELEM& TContainer<TELEM>::operator[](int index)
{
	if (index < 0 || index >= count)
	{
		TContainerExeption expt = cntINDOUTOFRANGE;
		throw expt;
	}
	return elem[index]; // тип возвращаемого значения
}

template <class TELEM>
TELEM& TContainer<TELEM>::operator[](const TELEM& _elm)
{
	int index;
	if ((index = _find(_elm)) == -1)
	{
		TContainerExeption expt = cntVALOUTOFRANGE;
		throw expt;
	}
	return elem[index]; // тип возвращаемого значения
}

template <class TELEM>
TContainer<TELEM>& TContainer<TELEM>::operator=(const
	TContainer<TELEM>& _cnt) // присваивание контейнеров
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
}

template <class TELEM>
TContainer<TELEM> TContainer<TELEM>::operator+(const
	TContainer<TELEM>& _cnt) // объединение контейнеров
{
	int i;
	TContainer<TELEM> tmp(count + _cnt.count + sizestep);
	for (i = 0; i < count; i++)
		tmp.elem[i] = elem[i];
	tmp.count = count;
	for (i = 0; i < _cnt.count; i++)
		tmp.Add(_cnt.elem[i]);
	return tmp;
}

template <class TELEM>
TContainer<TELEM> TContainer<TELEM>::operator*(const
	TContainer<TELEM>& _cnt) // пересечение контейнеров
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
}

template <class TELEM>
TContainer<TELEM> TContainer<TELEM>::operator-(const
	TContainer<TELEM>& _cnt) // разность контейнеров
{
	int i;
	TContainer<TELEM> tmp(count + sizestep);
	tmp.count = 0;
	for (i = 0; i < count; i++)
		if (_cnt._find(elem[i]) == -1) tmp.elem[tmp.count++] =
			elem[i];
	return tmp;
}