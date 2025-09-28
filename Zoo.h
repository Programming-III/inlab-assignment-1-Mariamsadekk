#ifndef ZOO_H
#define ZOO_H

#include "Enclosure.h"
#include "Visitor.h"

class Zoo {
private:
    Enclosure** enclosures;
    int numberOfEnclosures;
    Visitor** visitors;
    int numberOfVisitors;
    int maxEnclosures;
    int maxVisitors;

public:
    Zoo();
    Zoo(int numEnclosures, int numVisitors);
    ~Zoo();
    
    void initializeZoo();
    void showZooStatus() const;
    bool addEnclosure(Enclosure* enclosure);
    bool addVisitor(Visitor* visitor);
    
    int getNumberOfEnclosures() const;
    int getNumberOfVisitors() const;
    Enclosure* getEnclosure(int index) const;
    Visitor* getVisitor(int index) const;
};

#endif
