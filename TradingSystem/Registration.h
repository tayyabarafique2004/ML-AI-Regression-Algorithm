#ifndef REGISTRATIONS_H
#define REGISTRATIONS_H

#include <iostream>
#include <string>
#include "User.h"

class Registrations {
public:
    Registrations();                    // Constructor
    ~Registrations();                   // Destructor

    void addUser(const User& user);     // Add a user
    void deleteAllUsers();              // Delete all users
    void displayUsers() const;          // Display all users

    // Getters and setters for registration details
    std::string getUserId() const;
    std::string getRegistrationDate() const;
    std::string getVerificationCode() const;

    void setUserId(const std::string& userId);
    void setRegistrationDate(const std::string& registrationDate);
    void setVerificationCode(const std::string& verificationCode);

private:
    struct UserNode {                   // Define a node in the linked list
        User user;
        UserNode* next;

        UserNode(const User& user, UserNode* next = nullptr)
            : user(user), next(next) {}
    };

    UserNode* head;                     // Pointer to the head of the list
    int regId;                          // Registration ID
    std::string userId;                 // User ID
    std::string registrationDate;       // Registration Date
    std::string verificationCode;       // Verification Code
};

#endif // REGISTRATIONS_H
