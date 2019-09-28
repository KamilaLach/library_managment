#include <iostream>
#include <string>
#include "text_instance.h"
#include "text.h"
using namespace std;

TextInstance :: TextInstance(int id) {
  this->id = id;
}

TextInstance * TextInstance :: borrowText(Person * person) {
  borrowed = person;
  person->addTextInstance(this);
  return this;
}

TextInstance * TextInstance :: returnText(Person * person) {
  borrowed = NULL;
  person->removeTextInstance(this);
  return this;
}

void TextInstance :: print() {
  cout << "TextInstanceID: " << id << " | ";
  text->print();
}
