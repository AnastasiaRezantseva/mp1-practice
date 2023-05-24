#ifndef _CONTAINER_H
#define _CONTAINER_H
#include <string>
#include <iostream>


enum TContainerExeption { cntINDOUTOFRANGE, cntVALOUTOFRANGE };
template <class TELEM>
class TContainer
{
protected:

	TELEM* elem; // array of stored elements
	int size; // array size
	int count; // number of actually stored elements
	const static int sizestep = 10; // array increment step

public:
	TContainer(int _size = 50)
	{
		elem = new TELEM[_size];
		count = 0;
		size = _size;
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
	
	int getCount()
	{
		return count;
	};

	int getSize()
	{
		return size;
	};

	void setCount(int new_count)
	{
		size = new_count;
	};
	
	int getSizestep()
	{
		return sizestep;
	};
	
	void Add(TELEM _elm) // add element
	{
		if (_find(_elm) == -1)
		{
			if (size == count) resize();
			elem[count++] = _elm;
		}
	}; 

	void Del(TELEM _elm) // remove element by its value
	{
		Del(_find(_elm));
	}; 

	void Del(int index) // remove element by number
	{
		if (index > -1 && index < count)
			for (int i = index; i < count - 1; i++)
				elem[i] = elem[i + 1];
		count--;
	};

	TELEM& operator[](const TELEM& _elm) // content indexing
	{
		int index;
		if ((index = _find(_elm)) == -1)
		{
			TContainerExeption expt = cntVALOUTOFRANGE;
			throw expt;
		}
		return elem[index]; 
	};

	TELEM& operator[](int index) const //  indexing by number
	{	
		if (index < 0 || index >= count)
		{
			TContainerExeption expt = cntINDOUTOFRANGE;
			throw expt;
		}
		return elem[index]; 
	}; 


	const TELEM& operator[](const TELEM& _elm) const // content indexing
	{
		int index;
		if ((index = _find(_elm)) == -1)
		{
			TContainerExeption expt = cntVALOUTOFRANGE;
			throw expt;
		}
		return elem[index]; 
	}; 
		
	TContainer& operator=(const TContainer& _cnt) // container assignment
	{
		if (this != &_cnt) {
			delete[] elem;
			size = _cnt.size;
			count = _cnt.count;
			elem = new TELEM[size];
			for (int i = 0; i < count; i++)
				elem[i] = _cnt.elem[i];
		}
		return *this;
	};

	TContainer operator+(const TContainer& _cnt) // container pooling
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

	TContainer operator*(const TContainer& _cnt) // container crossing
	{
		int i;
		int ss = count;
		if (ss < _cnt.count) 
		{ 
			ss = _cnt.count;
		}
		TContainer<TELEM> tmp(ss + sizestep);
		tmp.count = 0;
		for (i = 0; i < count; i++)
			if (_cnt._find(elem[i]) != -1) 
			{
				tmp.elem[tmp.count++] = elem[i];
			}
		return tmp;
	};

	TContainer operator-(const TContainer& _cnt) // container difference
	{
		int i;
		TContainer<TELEM> tmp(count + sizestep);
		tmp.count = 0;
		for (i = 0; i < count; i++)
			if (_cnt._find(elem[i]) == -1) 
			{
				tmp.elem[tmp.count++] = elem[i];
			}
		return tmp;
	};

	friend std::istream& operator>>(std::istream& buf, TContainer<TELEM>& data)
	{
		int add_count;
		buf >> add_count;
		if (add_count > data.size - data.count) {
			data.resize(add_count + data.count - data.size);
		}

		for (int i = data.count; i < data.count + add_count; i++) {
			buf >> data.elem[i];
		}
		data.count += add_count;
		return buf;
	};
	
	friend  std::ostream& operator<<(std::ostream& buf, const TContainer<TELEM>& data)
	{
		buf << "Number of elements : " << data.count << '\n';
		for (int i = 0; i < data.count; i++) {
			buf << data.elem[i] << '\n';
		}

		return buf;
	};
	
	void set_step(const int& nstep)
	{
		sizestep = nstep;
	};

	void insert(const TELEM& value, const int& index = count)
	{
		if (index < 0 || index > count) {
			std::cout << "Wrong index" << std::endl;
			return;
		}

		if (count == size)
		{
			resize();
		}

		TELEM* tmp = new TELEM[count];
		for (int i = 0; i < count; i++)
		{
			tmp[i] = elem[i];
		}
		elem[index] = value;
		for (int i = index; i < count; i++)
		{
			elem[i + 1] = tmp[i];
		}
		count++;
		delete[] tmp;
	};

	void push_back(const TELEM& value)
	{
		if (count == size)
		{
			resize();
		}
		elem[count] = value;
		count++;
	};

	void push_front(const TELEM& value)
	{
		insert(value, 0);
	};
	
	void pop_id(const int& index) {
		if (index < 0 || index >= count) {
			std::cout << "Wrong index" << std::endl;
			return;
		}
		TELEM* tmp = new TELEM[count];
		for (int i = 0; i < count; i++)
		{
			tmp[i] = elem[i];
		}

		for (int i = 0; i < index; i++)
		{
			elem[i] = tmp[i];
		}

		for (int i = index + 1; i < count; i++)
		{
			elem[i - 1] = tmp[i];
		}
		count -= 1;
		delete[] tmp;
	};

	void pop_value(const TELEM& value) {
		for (int i = 0; i < count; i++)
		{
			if (elem[i] == value)
			{
				pop_id(i);
				return;
			}
		}
	};

	void pop_back()
	{
		pop_id(count - 1);
	};

	void pop_front() {
		pop_id(0);
	};

	int len() const {
		return count;
	};

	template <typename  Type> // fine id
	int _find(const Type& _elm) const
	{
		int nom = -1;
		for (int i = 0; i < count; i++)
		{
			if (elem[i] == _elm)
			{
				return i;
			}
		}

		return nom;
	};

	template <typename  Type> // type of find element
	TELEM* find(const Type& element) const
	{
		for (int i = 0; i < count; i++) {
			if (elem[i] == element) {
				return &elem[i];
			}
		}
		return nullptr;
	};

	void resize(int dsize = 0) // increase container length
	{
		if (dsize == 0)
		{
			dsize = sizestep;
		}
		size += dsize;
		TELEM* tmp = new TELEM[size];
		for (int i = 0; i < count; i++)
			tmp[i] = elem[i];
		delete[] elem;
		elem = tmp;
	};

};



template <class Type>
void read(const std::string& path, TContainer<Type>& data)
{
	std::ifstream file(path);

	if (!file) {
		throw "Wrong path.";
	}
	file >> data;
	file.close();
};



#endif _CONTAINER_H
