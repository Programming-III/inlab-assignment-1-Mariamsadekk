#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    int age;
    bool isHungry;

public:
    Animal();
    Animal(string name, int age, bool isHungry);
    virtual ~Animal();
    
    virtual void display() const;
    void feed();
    
    string getName() const;
    void setName(const string& name);
    int getAge() const;
    void setAge(int age);
    bool getIsHungry() const;
    void setIsHungry(bool hungry);
};

class Mammal : public Animal {
private:
    string furColor;

public:
    Mammal();
    Mammal(string name, int age, bool isHungry, string furColor);
    ~Mammal();
    
    void display() const override;
    
    string getFurColor() const;
    void setFurColor(const string& furColor);
};

class Bird : public Animal {
private:
    float wingSpan;

public:
    Bird();
    Bird(string name, int age, bool isHungry, float wingSpan);
    ~Bird();
    
    void display() const override;
    
    float getWingSpan() const;
    void setWingSpan(float wingSpan);
};

class Reptile : public Animal {
private:
    bool isVenomous;

public:
    Reptile();
    Reptile(string name, int age, bool isHungry, bool isVenomous);
    ~Reptile();
    
    void display() const override;
    
    bool getIsVenomous() const;
    void setIsVenomous(bool venomous);
};

#endif
