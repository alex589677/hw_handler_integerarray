#include "IntegerArray.h"
#include <iomanip>

IntegerArray::IntegerArray(int arraySize) {
	size = arraySize;
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		ptr[i] = 0;
	}
}

IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size) {
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		ptr[i] = other.ptr[i];
	}
}

IntegerArray::~IntegerArray() {
	delete[] ptr;
}

int IntegerArray::getSize() {
	return size;
}

const IntegerArray& IntegerArray::operator=(const IntegerArray& right) {
	if (&right != this) {
		if (size != right.size) {
			delete[] ptr;
			size = right.size;
			ptr = new int[size];
		}
		for (int i = 0; i < size; i++) {
			ptr[i] = right.ptr[i];
		}
	}
	return *this;
}

bool IntegerArray::operator==(const IntegerArray& right) const {
	if (size != right.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (ptr[i] != right.ptr[i]) {
			return false;
		}
	}
	return true;
}

bool IntegerArray::operator!=(const IntegerArray& right) const {
	return !(*this == right);
}

int& IntegerArray::operator[](int index) {
	if (index < 0 || index >= size) {
		std::cout << "\nError: Subscript " << index
			<< " out of range " << std::endl;
		exit(1);
	}
	return ptr[index];
}

const int& IntegerArray::operator[](int index) const {
	if (index < 0 || index >= size) {
		std::cout << "\nError: Subscript " << index
			<< " out of range " << std::endl;
		exit(1);
	}
	return ptr[index];
}

void IntegerArray::push_back(const int value) {
	int* ptrNewArray = new int[size + 1];
	for (int i = 0; i < size; i++) {
		ptrNewArray[i] = ptr[i];
	}
	ptrNewArray[size] = value;
	size++;
	delete[] ptr;
	ptr = ptrNewArray;
}

void IntegerArray::insertBefore(int value, int index)
{
	int* data{ new int[size + 1] };
	for (int before{ 0 }; before < index; ++before)
		data[before] = ptr[before];

	data[index] = value;
	for (int after{ index }; after < size; ++after)
		data[after + 1] = ptr[after];

	delete[] ptr;
	ptr = data;
	++size;
}

int IntegerArray::getValue(int index) {
	return ptr[index];
}

void IntegerArray::pop_back() {
	size--;
	int* ptrNewArray = new int[size];
	for (int i = 0; i < size; i++) {
		ptrNewArray[i] = ptr[i];
	}
	delete[] ptr;
	ptr = ptrNewArray;
}

std::istream& operator>>(std::istream& input, IntegerArray& other) {
	for (int i = 0; i < other.size; i++) {
		input >> other.ptr[i];
	}
	return input;
}

std::ostream& operator<<(std::ostream& output, const IntegerArray& other) {
	int i;
	for (i = 0; i < other.size; i++) {
		output << std::setw(12) << other.ptr[i];
		if ((i + 1) % 4 == 0) {
			output << std::endl;
		}
	}
	if (i % 4 != 0) {
		output << std::endl;
	}
	return output;
}