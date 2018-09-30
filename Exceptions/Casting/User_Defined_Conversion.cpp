#include <iostream>

class myClass {

public:
    operator int();

    explicit operator double();

};

myClass::operator int() {

    return 99;
}

myClass::operator double() {

    return 22.56;
}

int main() {

    myClass mc;

    int myint = mc;  //implicit conversion

    double mydouble = (double)mc;  //explicit conversion

    std::cout << " myint is " << myint << " and mydouble is " << mydouble << std::endl;

    return 0;
}