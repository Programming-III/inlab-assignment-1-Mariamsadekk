#include "Animal.h"
#include "Enclosure.h"
#include "Visitor.h"
#include "Zoo.h"
#include <iostream>
using namespace std;

// ============== ANIMAL CLASS IMPLEMENTATION ===============
Animal::Animal() : name("Unknown"), age(0), isHungry(true) {}

Animal::Animal(string name, int age, bool isHungry) 
    : name(name), age(age), isHungry(isHungry) {}

Animal::~Animal() {}

void Animal::display() const {
    cout << "- " << name << " (Age: " << age << ", " 
         << (isHungry ? "Hungry" : "Not Hungry") << ")";
}

void Animal::feed() {
    isHungry = false;
}

string Animal::getName() const { return name; }
void Animal::setName(const string& name) { this->name = name; }
int Animal::getAge() const { return age; }
void Animal::setAge(int age) { this->age = age; }
bool Animal::getIsHungry() const { return isHungry; }
void Animal::setIsHungry(bool hungry) { this->isHungry = hungry; }

// ============== MAMMAL CLASS IMPLEMENTATION ==============
Mammal::Mammal() : Animal(), furColor("Brown") {}

Mammal::Mammal(string name, int age, bool isHungry, string furColor)
    : Animal(name, age, isHungry), furColor(furColor) {}

Mammal::~Mammal() {}

void Mammal::display() const {
    //display the info of the animal fur
    Animal::display();
    cout << ", Fur: " << furColor;
}

string Mammal::getFurColor() const { return furColor; }
void Mammal::setFurColor(const string& furColor) { this->furColor = furColor; }

// ============== BIRD CLASS IMPLEMENTATION ==============
Bird::Bird() : Animal(), wingSpan(0.0f) {}

Bird::Bird(string name, int age, bool isHungry, float wingSpan)
    : Animal(name, age, isHungry), wingSpan(wingSpan) {}

Bird::~Bird() {}

void Bird::display() const {
    Animal::display();
    cout << ", Wing Span: " << wingSpan << "m";
}

float Bird::getWingSpan() const { return wingSpan; }
void Bird::setWingSpan(float wingSpan) { this->wingSpan = wingSpan; }

// ============== REPTILE CLASS IMPLEMENTATION ==============
Reptile::Reptile() : Animal(), isVenomous(false) {}

Reptile::Reptile(string name, int age, bool isHungry, bool isVenomous)
    : Animal(name, age, isHungry), isVenomous(isVenomous) {}

Reptile::~Reptile() {}

void Reptile::display() const {
    Animal::display();
    cout << ", " << (isVenomous ? "Venomous" : "Non-venomous");
}

bool Reptile::getIsVenomous() const { return isVenomous; }
void Reptile::setIsVenomous(bool venomous) { this->isVenomous = venomous; }

// ============== ENCLOSURE CLASS IMPLEMENTATION ==============
Enclosure::Enclosure() : capacity(5), currentCount(0) {
    animals = new Animal*[capacity];
    for (int i = 0; i < capacity; i++) {
        animals[i] = nullptr;
    }
}

Enclosure::Enclosure(int capacity) : capacity(capacity), currentCount(0) {
    this->animals = new Animal*[capacity];
    for (int i = 0; i < capacity; i++) {
        animals[i] = nullptr;
    }
}

Enclosure::~Enclosure() {
    for (int i = 0; i < currentCount; i++) {
        delete animals[i];
    }
    delete[] animals;
}

bool Enclosure::addAnimal(Animal* animal) {
    if (currentCount < capacity && animal != nullptr) {
        animals[currentCount] = animal;
        currentCount++;
        return true;
    }
    return false;
}

void Enclosure::displayAnimals() const {
    for (int i = 0; i < currentCount; i++) {
        if (animals[i] != nullptr) {
            animals[i]->display();
            cout << endl;
        }
    }
}

int Enclosure::getCapacity() const { return capacity; }
void Enclosure::setCapacity(int capacity) { this->capacity = capacity; }
int Enclosure::getCurrentCount() const { return currentCount; }

Animal* Enclosure::getAnimal(int index) const {
    if (index >= 0 && index < currentCount) {
        return animals[index];
    }
    return nullptr;
}

// ============== VISITOR CLASS IMPLEMENTATION ==============
Visitor::Visitor() : visitorName("Unknown"), ticketsBought(0) {}

Visitor::Visitor(string visitorName, int ticketsBought)
    : visitorName(visitorName), ticketsBought(ticketsBought) {}

Visitor::~Visitor() {}

void Visitor::displayInfo() const {
    cout << "Name: " << visitorName << endl;
    cout << "Tickets Bought: " << ticketsBought << endl;
}

string Visitor::getVisitorName() const { return visitorName; }
void Visitor::setVisitorName(const string& name) { this->visitorName = name; }
int Visitor::getTicketsBought() const { return ticketsBought; }
void Visitor::setTicketsBought(int tickets) { this->ticketsBought = tickets; }

// ============== ZOO CLASS IMPLEMENTATION ==============
Zoo::Zoo() : numberOfEnclosures(0), numberOfVisitors(0), maxEnclosures(10), maxVisitors(50) {
    enclosures = new Enclosure*[maxEnclosures];
    visitors = new Visitor*[maxVisitors];
    for (int i = 0; i < maxEnclosures; i++) enclosures[i] = nullptr;
    for (int i = 0; i < maxVisitors; i++) visitors[i] = nullptr;
}

Zoo::Zoo(int numEnclosures, int numVisitors) 
    : numberOfEnclosures(0), numberOfVisitors(0), maxEnclosures(numEnclosures), maxVisitors(numVisitors) {
    enclosures = new Enclosure*[maxEnclosures];
    visitors = new Visitor*[maxVisitors];
    for (int i = 0; i < maxEnclosures; i++) enclosures[i] = nullptr;
    for (int i = 0; i < maxVisitors; i++) visitors[i] = nullptr;
}

Zoo::~Zoo() {
    for (int i = 0; i < numberOfEnclosures; i++) {
        delete enclosures[i];
    }
    for (int i = 0; i < numberOfVisitors; i++) {
        delete visitors[i];
    }
    delete[] enclosures;
    delete[] visitors;
}

void Zoo::initializeZoo() {
    cout << "Zoo initialized successfully." << endl << endl;
    
    // Create first enclosure with mixed animals
    Enclosure* enc1 = new Enclosure(5);
    enc1->addAnimal(new Mammal("Lion", 5, true, "Golden"));
    enc1->addAnimal(new Bird("Parrot", 2, false, 0.5f));
    enc1->addAnimal(new Reptile("Snake", 3, true, true));
    addEnclosure(enc1);
    
    // Create a visitor
    Visitor* visitor1 = new Visitor("Sarah Ali", 3);
    addVisitor(visitor1);
}

void Zoo::showZooStatus() const {
    for (int i = 0; i < numberOfEnclosures; i++) {
        cout << "Enclosure " << (i + 1) << " Animals:" << endl;
        if (enclosures[i] != nullptr) {
            enclosures[i]->displayAnimals();
        }
        cout << endl;
    }
    
    if (numberOfVisitors > 0) {
        cout << "Visitor Info:" << endl;
        for (int i = 0; i < numberOfVisitors; i++) {
            if (visitors[i] != nullptr) {
                visitors[i]->displayInfo();
                cout << endl;
            }
        }
    }
}

bool Zoo::addEnclosure(Enclosure* enclosure) {
    if (numberOfEnclosures < maxEnclosures && enclosure != nullptr) {
        enclosures[numberOfEnclosures] = enclosure;
        numberOfEnclosures++;
        return true;
    }
    return false;
}

bool Zoo::addVisitor(Visitor* visitor) {
    if (numberOfVisitors < maxVisitors && visitor != nullptr) {
        visitors[numberOfVisitors] = visitor;
        numberOfVisitors++;
        return true;
    }
    return false;
}

int Zoo::getNumberOfEnclosures() const { return numberOfEnclosures; }
int Zoo::getNumberOfVisitors() const { return numberOfVisitors; }

Enclosure* Zoo::getEnclosure(int index) const {
    if (index >= 0 && index < numberOfEnclosures) {
        return enclosures[index];
    }
    return nullptr;
}

Visitor* Zoo::getVisitor(int index) const {
    if (index >= 0 && index < numberOfVisitors) {
        return visitors[index];
    }
    return nullptr;
}

// ============== MAIN FUNCTION ==============
int main() {
    // Create and initialize the zoo
    Zoo* myZoo = new Zoo(5, 10);
    
    // Initialize the zoo with default setup
    myZoo->initializeZoo();
    
    // Display the current zoo status
    myZoo->showZooStatus();
    
    // Clean up
    delete myZoo;
    
    return 0;
}
