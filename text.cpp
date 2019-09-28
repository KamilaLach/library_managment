#include <iostream>
#include <string>
#include <sstream>
#include "text.h"
using namespace std;

Text :: Text(string title, string author, string year) {
    this->title = title;
    this->author = author;
    this->year = year;
}

void Text :: print() {
    cout << "Tytuł: " << title << " Autor: " << author << " Rok wydania: " << year << endl;
}

void Text :: addInstance(TextInstance * ti) {
    ti->text = this;
    textInstances.push_back(ti);
}

TextInstance * Text :: borrowText(Person * person) {
    for (TextInstance * ti : textInstances) {
        if (ti->borrowed == NULL) {
            return ti->borrowText(person);
        }
    }

    return NULL;
}

bool Text :: operator==(const string searchTitle) {
    return this->title == searchTitle;
}
