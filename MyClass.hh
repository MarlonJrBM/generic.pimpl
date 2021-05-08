#pragma once

#include "pimpl.hh"

class MyClass {
  public:
    MyClass();

    /**
     * Destructor has to be defined in implementation file (MyClass.cc), for obscure language reasons. 
     */
    ~MyClass();

    void doStuff();

  private:
    class MyClassImpl;
    pimpl<MyClassImpl> _impl;
};