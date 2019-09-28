#include <iostream>
#include <string>
#include "person.h"
#include "text_instance.h"
using namespace std;

Person :: Person(string name) {
    this->name = name;
}

void Person :: addTextInstance(TextInstance * ti) {
    textInstances.push_back(ti);
}

void Person :: removeTextInstance(TextInstance * ti) {
    textInstances.remove(ti);
}

void Person :: printBorrowed() {
    int i = 0;

    for (TextInstance * ti : textInstances) {
        cout << i << ". ";
        ti->print();
        i++;
    }
}

TextInstance * Person :: getBorrwedAt(int i) {
    list<TextInstance*>::iterator it = textInstances.begin();
    advance(it, i);
    return *it;
}
