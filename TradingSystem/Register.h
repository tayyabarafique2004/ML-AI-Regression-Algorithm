#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <string>
#include "User.h"

class Register {
public:
    Register();              // Constructor
    ~Register();             // Destructor
    void addUser(User user); // Add a user to the list
   void deleteList(Register::UserNode* node);// Delete all nodes recursively

private:
    // Nested UserNode class inside Register
    class UserNode {
    public:
        User user;       // User object
        UserNode* next;  // Pointer to the next node

        UserNode(User user) : user(user), next(nullptr) {} // Constructor
    };

    UserNode* head; // Pointer to the first node in the list
};

#endif // REGISTER_H
