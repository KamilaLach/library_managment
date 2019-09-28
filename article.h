#pragma once
#include <iostream>
#include <string>
#include "text.h"
using namespace std;

class Article : public Text{
protected:
    string title;
    string author;
    int year;
    int number;
 
public:
    Article(string title, string author, string year);
};