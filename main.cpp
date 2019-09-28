#include "person.h"
#include "book.h"
#include "article.h"
#include "library.h"
#include <iostream>

using namespace std;

Library library;

void prefill() {
    Book * a = new Book("Hobbit", "J.R.R. Tolkien", "2006");
    a->addInstance(new TextInstance(1));
    a->addInstance(new TextInstance(2));
    a->addInstance(new TextInstance(3));
    library.addText(a);

    Book * a2 = new Book("Bastion", "Stephen King", "1994");
    a2->addInstance(new TextInstance(1));
    a2->addInstance(new TextInstance(2));
    a2->addInstance(new TextInstance(3));
    library.addText(a2);
    
    Book * a3 = new Book("Book3", "autor3", "2016");
    a3->addInstance(new TextInstance(1));
    a3->addInstance(new TextInstance(2));
    a3->addInstance(new TextInstance(3));
    library.addText(a3);

    Book * a4 = new Book("Book4", "autor4", "2016");
    a4->addInstance(new TextInstance(1));
    a4->addInstance(new TextInstance(2));
    a4->addInstance(new TextInstance(3));
    library.addText(a4);

    Book * a5 = new Book("Book5", "autor5", "2016");
    a5->addInstance(new TextInstance(1));
    a5->addInstance(new TextInstance(2));
    a5->addInstance(new TextInstance(3));
    library.addText(a5);

    Article * b = new Article("art1", "autor", "2017");
    b->addInstance(new TextInstance(1));
    library.addText(b);

    Article * b1 = new Article("art2", "autor", "2017");
    b1->addInstance(new TextInstance(1));
    library.addText(b1);

    Article * b2 = new Article("art3", "autor", "2017");
    b2->addInstance(new TextInstance(1));
    library.addText(b2);
}

void borrowText(Person * person) {
    string title;
    cout << "Wpisz tytuł: ";
    cin >> title;
    cout << "Szukam książki '" << title << "'" << endl;

    Text * text = library.search(title);
    
    if (text == NULL) {
        cout << "Nie znalazlam ksiazki :<";
        return;
    }

    cout << "Znalazłam! ";
    text->print();
    TextInstance * textInstance = text->borrowText(person);
    
    if (textInstance == NULL) {
        cout << "Nie ma wolnej książki :<" << endl;
        return;
    }
    cout << "Otrzymujesz książkę nr " << textInstance->id;
}

void returnText(Person * person) {
    cout << endl << "Aktualnie pozyczone ksiazki" << endl;
    person->printBorrowed();

    string choice;
    cout << "Wybierz pozycje: ";
    cin >> choice;

    TextInstance * textInstance = person->getBorrwedAt(stoi(choice));
    textInstance->returnText(person);
}

int main() {
    prefill();

    string name;
    cout << "Kim jesteś?: ";
    cin >> name;
    cout << "Witaj!" << endl;

    Person * person = new Person(name);

    string choice;

    while (true) {
        cout << "1. Wypożycz książkę" << endl;
        cout << "2. Oddaj książkę" << endl;
        cout << "q. Wyjdź" << endl;
        cin >> choice;

        if (choice == "q") {
            break;
        } else if (choice == "1") {
            borrowText(person);
        } else if (choice == "2") {
            returnText(person);
        }
        cout << endl << "-----------------------------" << endl << endl;
    }

    return 0;
}
