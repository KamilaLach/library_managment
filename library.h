#pragma once
#include <iostream>
#include <string>
#include <list>
#include "text.h"
using namespace std;

class Library {
public:
    Library();
    void addText(Text*);
    Text * search(string title);
private:
    list<Text*> texts;
};
