#pragma once
#include <iostream>

class IntegerArray {
private:
	int size;
	int* ptr;
public:
	IntegerArray() = default;
	IntegerArray(int);
	IntegerArray(const IntegerArray& other);
	~IntegerArray();
	int getSize();
	const IntegerArray& operator=(const IntegerArray&);
	bool operator==(const IntegerArray&) const;
	bool operator!=(const IntegerArray& right) const;
	int& operator[](int);
	const int& operator[](int) const;
	void push_back(const int value);
	void insertBefore(int value, int index);
	int getValue(int index);
	void pop_back();
	friend std::ostream& operator<<(std::ostream&, const IntegerArray&);
	friend std::istream& operator>>(std::istream&, IntegerArray&);
};