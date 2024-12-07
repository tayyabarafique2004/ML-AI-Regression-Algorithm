#include "Registration.h"


// Constructor definition
Registration::Registration(string userId, string registrationDate, string verificationCode)
    : userId(userId), registrationDate(registrationDate), verificationCode(verificationCode) {}

// Destructor definition (if needed, currently empty as no dynamic memory allocation is done)
Registration::~Registration() {}

// Getter for userId
string Registration::getUserId() const {
    return userId;
}

// Getter for registrationDate
string Registration::getRegistrationDate() const {
    return registrationDate;
}

// Getter for verificationCode
string Registration::getVerificationCode() const {
    return verificationCode;
}

// Setter for userId
void Registration::setUserId(const string &userId) {
    this->userId = userId;
}

// Setter for registrationDate
void Registration::setRegistrationDate(const string &registrationDate) {
    this->registrationDate = registrationDate;
}

// Setter for verificationCode
void Registration::setVerificationCode(const string &verificationCode) {
    this->verificationCode = verificationCode;
}
