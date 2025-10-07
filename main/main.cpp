#include "Animal.h"
#include "Enclosure.h"
#include "Visitor.h"
#include "Zoo.h"
#include <iostream>
using namespace std;
//here it is 

// ============== ANIMAL CLASS IMPLEMENTATION ===============
Animal::Animal() : name(""), age(0), isHungry(true) {}
Animal::Animal(string n, int a, bool hungry) : name(n), age(a), isHungry(hungry) {}
Animal::~Animal() {}
string Animal::getName() const { return name; }
int Animal::getAge() const { return age; }
bool Animal::getIsHungry() const { return isHungry; }
void Animal::setName(string n) { name = n; }
void Animal::setAge(int a) { age = a; }
void Animal::setIsHungry(bool h) { isHungry = h; }
void Animal::feed() { isHungry = false; }
void Animal::display() const {
    cout << name << " (Age: " << age << ", " << (isHungry ? "Hungry" : "Not Hungry") << ")" << endl;
}
// --------- Mammal ---------
Mammal::Mammal() : Animal(), furColor("") {}
Mammal::Mammal(string n, int a, bool hungry, string fur) : Animal(n, a, hungry), furColor(fur) {}
Mammal::~Mammal() {}
void Mammal::setFurColor(string c) { furColor = c; }
string Mammal::getFurColor() const { return furColor; }
void Mammal::display() const {
    Animal::display();
    cout << "Fur: " << furColor << endl;
}
// --------- Bird ---------
Bird::Bird() : Animal(), wingSpan(0.0f) {}
Bird::Bird(string n, int a, bool hungry, float ws) : Animal(n, a, hungry), wingSpan(ws) {}
Bird::~Bird() {}
void Bird::setWingSpan(float ws) { wingSpan = ws; }
float Bird::getWingSpan() const { return wingSpan; }
void Bird::display() const {
    Animal::display();
    cout << "Wing Span: " << wingSpan << "m" << endl;
}
// --------- Reptile ---------
Reptile::Reptile() : Animal(), isVenomous(false) {}
Reptile::Reptile(string n, int a, bool hungry, bool venom) : Animal(n, a, hungry), isVenomous(venom) {}
Reptile::~Reptile() {}
void Reptile::setIsVenomous(bool v) { isVenomous = v; }
bool Reptile::getIsVenomous() const { return isVenomous; }
void Reptile::display() const {
    Animal::display();
    cout << (isVenomous ? "Venomous" : "Not Venomous") << endl;
}
// --------- Enclosure ---------
Enclosure::Enclosure() : animals(nullptr), capacity(0), currentCount(0) {}
Enclosure::Enclosure(int cap) : capacity(cap), currentCount(0) {
    animals = new Animal*[capacity];
}
Enclosure::~Enclosure() {
    for (int i = 0; i < currentCount; i++)
        delete animals[i];
    delete[] animals;
}
void Enclosure::addAnimal(Animal* a) {
    if (currentCount < capacity)
        animals[currentCount++] = a;
}
void Enclosure::displayAnimals() const {
    cout << "Enclosure 1 Animals:" << endl;
    for (int i = 0; i < currentCount; i++) {
        animals[i]->display();
    }
}
// --------- Visitor ---------
Visitor::Visitor() : visitorName(""), ticketsBought(0) {}
Visitor::Visitor(string name, int tickets) : visitorName(name), ticketsBought(tickets) {}
Visitor::~Visitor() {}
void Visitor::setVisitorName(string n) { visitorName = n; }
void Visitor::setTicketsBought(int t) { ticketsBought = t; }
string Visitor::getVisitorName() const { return visitorName; }
int Visitor::getTicketsBought() const { return ticketsBought; }
void Visitor::displayInfo() const {
    cout << "Name: " << visitorName << endl;
    cout << "Tickets Bought: " << ticketsBought << endl;
}
// --------- Zoo ---------
Zoo::Zoo() {
    enclosure = nullptr;
    visitor = nullptr;
}
Zoo::~Zoo() {
    delete enclosure;
    delete visitor;
}
void Zoo::initializeZoo() {
    cout << "Zoo initialized successfully." << endl;
    enclosure = new Enclosure(3);
    enclosure->addAnimal(new Mammal("Lion", 5, true, "Golden"));
    enclosure->addAnimal(new Bird("Parrot", 2, false, 0.5f));
    enclosure->addAnimal(new Reptile("Snake", 3, true, true));
    visitor = new Visitor("Sarah Ali", 3);
}
void Zoo::showZooStatus() const {
    if (enclosure) enclosure->displayAnimals();
    if (visitor) visitor->displayInfo();
}
// --------- main ---------
int main() {
    Zoo zoo;
    zoo.initializeZoo();
    zoo.showZooStatus();
    return 0;
}
