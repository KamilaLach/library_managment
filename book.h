#pragma once
#include <iostream>
#include <string>
#include "text.h"
using namespace std;

class Book : public Text {
protected:
    string title;
    string author;
    int year;
    int number;
 
public:
    Book(string title, string author, string year);
};