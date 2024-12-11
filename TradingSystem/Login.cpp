#include "Login.h"

// Default constructor
Login::Login() : userid(""), date("") {}

// Parameterized constructor
Login::Login(const std::string& userid, const std::string& date)
    : userid(userid), date(date) {}

// Destructor
Login::~Login() {}

// Getters
std::string Login::getUserId() const {
    return userid;
}

std::string Login::getDate() const {
    return date;
}

// Setters
void Login::setUserId(const std::string& userid) {
    this->userid = userid;
}

void Login::setDate(const std::string& date) {
    this->date = date;
}
