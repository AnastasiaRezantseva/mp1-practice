#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <string>
using namespace std;

enum TContainerExeption { cntINDOUTOFRANGE, cntVALOUTOFRANGE };
template <class TELEM>
class TContainer
{
protected:
	TELEM* elem; // ������ �������� ���������
	int size; // ������ �������
	int count; // �-�� ������� �������� ���������
	const static int sizestep = 10; // ��� ����������� ��������������
public:
	TContainer(int _size = 50);
	TContainer(const TContainer& _cnt);
	~TContainer ();

	const int& �ount() const { return count; }
	int& �ount() { return count; }
	const int& Sizestep() const { return sizestep; }
	void Add(TELEM _elm); // �������� �������
	void Del(TELEM _elm); // ������� ������� �� ��� ��������
	void Del(int index); // ������� ������� �� ��� ������
	TELEM& operator[](int index); // ���������� �� ������
		TELEM& operator[](const TELEM& _elm); // ���������� �� ����������
		const TELEM& operator[](int index) const; // ���������� �� ������
		const TELEM& operator[](const TELEM& _elm) const; // ���������� �� ����������
		TContainer& operator=(const TContainer& _cnt); // ������������ �����������
		TContainer operator+(const TContainer& _cnt); // ����������� �����������
		TContainer operator*(const TContainer& _cnt); // ����������� �����������
		TContainer operator-(const TContainer& _cnt); // �������� �����������
protected:
	void resize(int dsize = 0); // ��������� ����� ����������
		int _find(const TELEM& _elm) const; // ����� �������
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

