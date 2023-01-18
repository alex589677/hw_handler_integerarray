#pragma once
#include <iostream>
#include <exception>
using namespace std;

class bad_length : public exception {
public:
	virtual const char* what() const noexcept override {
		return " error: wrong length array!";
	}
};

class bad_range : public exception {
public:
	virtual const char* what() const noexcept override {
		return " error: wrong range array!";
	}
};