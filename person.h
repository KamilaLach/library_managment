#pragma once
#include <iostream>
#include <string>
#include <list>
// #include "text_instance.h"
using namespace std;

class TextInstance;

class Person {
private:
    string name;
    list<TextInstance*> textInstances;
public:
    Person(string name);
    void addTextInstance(TextInstance * ti);
    void removeTextInstance(TextInstance * ti);
    void printBorrowed();
    TextInstance * getBorrwedAt(int i);
};
