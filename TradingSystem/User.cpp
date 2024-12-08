#include "User.h"
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>
#include <sstream>
// Constructor
User::User()  //id(0), age(0) 
{
    this->age =0;
}
//Another
User::User(string userId,string username,string HashedPassword,int age,string email,int WalletId)
{
    //this->id=id; 
    this->age=age;
    this->email=email;
    this->username=username;
    this->userId=userId;
    this->password=HashedPassword;
    this->WalletId=WalletId;    

}
// Destructor
User::~User() {}

void User::insertUserToDb()
{

}

string User::hashPassword(const string & password)
{
    //hash function
   hash<string>hashfunction;
   size_t hashedPassword= hashfunction(password);
   //converting to hexadecimal
   ostringstream hexastring;
   hexastring<<hex<<hashedPassword;
   return hexastring.str();
}

string User:: generateUserId(const string& userName)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> dist(100, 999); // 3-digit random number
    int randomDigits = dist(generator);

    string userId = userName.substr(0, 3); // First 3 characters of username
    userId += to_string(randomDigits);
    return userId;
}

string User::generateVerificationCode(int length)
{
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist(0, chars.size() - 1);

    std::string code;
    for (int i = 0; i < length; ++i) {
        code += chars[dist(generator)];
    }
    return code;
}

// Getter and Setter for id
// int User::getId() const {
//     return id;
// }

// void User::setId(int id) {
//     this->id = id;
// }

// Getter and Setter for username
std::string User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

// Getter and Setter for hashedPassword
std::string User::getHashedPassword() const {
    return password;
}

void User::setHashedPassword(const std::string& hashedPassword) {
    this->password = password;
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

