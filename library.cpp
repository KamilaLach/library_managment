#include <iostream>
#include <string>
#include "library.h"
using namespace std;

Library :: Library() {}

void Library :: addText(Text * t) {
  texts.push_back(t);
}

Text * Library :: search(string title) {
  for (Text * t : texts) {
        if (*t == title) {
            return t;
        }
    }

    return NULL;
}
