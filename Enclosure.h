#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "Animal.h"

class Enclosure {
private:
    Animal** animals;
    int capacity;
    int currentCount;

public:
    Enclosure();
    Enclosure(int capacity);
    ~Enclosure();
    
    bool addAnimal(Animal* animal);
    void displayAnimals() const;
    
    int getCapacity() const;
    void setCapacity(int capacity);
    int getCurrentCount() const;
    Animal* getAnimal(int index) const;
};

#endif
