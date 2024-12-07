#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "User.h"
#include "Asset.h"

using namespace std;

class Order {
public:
    // Constructor with User and Asset objects as arguments
    Order(string buyDate, string sellDate, User* user, Asset* asset);

    // Getter methods
    string getBuyDate() const;
    string getSellDate() const;
    User* getUser() const;
    Asset* getAsset() const;

private:
    string buyDate;     // Date when the order was bought
    string sellDate;    // Date when the order was sold
    User* user;         // Pointer to related User object (foreign key reference)
    Asset* asset;       // Pointer to related Asset object (foreign key reference)
};


#endif  // ORDER_H
