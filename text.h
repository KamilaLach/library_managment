#pragma once
#include <iostream>
#include <string>
#include <list>
#include "text_instance.h"
#include "person.h"
using namespace std;

class Text {
protected:
    string title;
    string author;
    string year;
public:
    Text(string title, string author, string year);
    void print();
    void addInstance(TextInstance*);
    TextInstance * borrowText(Person * person);
    bool operator==(const string);
private:
    list<TextInstance*> textInstances;
};
