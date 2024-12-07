#include "Order.h"

#include "Order.h"
#include "User.h"
#include "Asset.h"

// Constructor with User and Asset objects as arguments
Order::Order(string buyDate, string sellDate, User* user, Asset* asset)
    : buyDate(buyDate), sellDate(sellDate), user(user), asset(asset) {}

// Getter methods
string Order::getBuyDate() const {
    return buyDate;
}

string Order::getSellDate() const {
    return sellDate;
}

User* Order::getUser() const {
    return user;
}

Asset* Order::getAsset() const {
    return asset;
}
