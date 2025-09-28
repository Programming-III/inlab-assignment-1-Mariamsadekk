#ifndef VISITOR_H
#define VISITOR_H

#include <string>
using namespace std;

class Visitor {
private:
    string visitorName;
    int ticketsBought;

public:
    Visitor();
    Visitor(string visitorName, int ticketsBought);
    ~Visitor();
    
    void displayInfo() const;
    
    string getVisitorName() const;
    void setVisitorName(const string& name);
    int getTicketsBought() const;
    void setTicketsBought(int tickets);
};

#endif
