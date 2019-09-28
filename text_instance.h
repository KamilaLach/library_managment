#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Text;

class TextInstance {
public:
    int id;
    Text * text;
    Person * borrowed;
    TextInstance(int id);
    TextInstance * borrowText(Person * person);
    TextInstance * returnText(Person * person);
    void print();
};
