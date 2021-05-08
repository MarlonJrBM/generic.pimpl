#include "MyClass.hh"

#include <iostream>

class MyClass::MyClassImpl {
  public:
    void doStuff();
};

MyClass::MyClass() = default;

MyClass::~MyClass() = default;

void MyClass::doStuff() { _impl->doStuff(); }

void MyClass::MyClassImpl::doStuff() { std::cout << "Starting to do stuff !" << std::endl; }