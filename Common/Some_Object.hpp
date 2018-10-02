#pragma once
#include <iostream>
#include <string>

class someObject {
public:
	someObject() : var1(rand()), var2("Hello World.") {}

	void printAttr() { std::cout << "var1 is " << this->var1 << " var2 is " << this->var2 << "\n"; }

	void setString(std::string ss) { this->var2 = ss; }

	~someObject() { std::cout << "someObject de constructor called " << this->var1 << ". \n"; }

private:
	int var1;
	std::string var2;
};