#include "User.h"

// Constructor
User::User() : id(0), age(0) {}
//Another
User::User(int id,string userId,string username,string HashedPassword,int age,string email,int WalletId)
{
    this->id=id;
    this->age=age;
    this->email=email;
    this->username=username;
    this->userId=userId;
    this->hashedPassword=HashedPassword;
    this->WalletId=WalletId;    

}
// Destructor
User::~User() {}

// Getter and Setter for id
int User::getId() const {
    return id;
}

void User::setId(int id) {
    this->id = id;
}

// Getter and Setter for username
std::string User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

// Getter and Setter for hashedPassword
std::string User::getHashedPassword() const {
    return hashedPassword;
}

void User::setHashedPassword(const std::string& hashedPassword) {
    this->hashedPassword = hashedPassword;
}

// Getter and Setter for email
std::string User::getEmail() const {
    return email;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

// Getter and Setter for age
int User::getAge() const {
    return age;
}

void User::setAge(int age) {
    this->age = age;
}

int User::getWalletId() const {
    return WalletId;
}

void User::setWalletId(int walletId) {
    this->WalletId = walletId;
}