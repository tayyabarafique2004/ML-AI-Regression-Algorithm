// #include "Register.h"
// #include "User.h"
// Register::Register() : head(nullptr) { 
//     // Initialize head to nullptr in the constructor
// }

// Register::~Register() {
//     deleteList();  // Clean up the list when Register is destroyed
// }   

// void Register::deleteList(UserNode* node) {
//     if (node == nullptr) return;  // Base case for recursion
//     deleteList(node->next);  // Recursively delete all nodes
//     delete node;  // Delete the current node
// }

// void Register::addUser(User user) {
//     UserNode* newNode = new UserNode(user);  // No need for Register:: prefix here
//     if (head == nullptr) {
//         head = newNode;  // If list is empty, set head to the new node
//     } else {
//         UserNode* temp = head;
//         while (temp->next != nullptr) {  // Traverse to the end of the list
//             temp = temp->next;
//         }
//         temp->next = newNode;  // Add the new node at the end
//     }
// }


#include "Register.h"
#include "User.h"

// Constructor
Register::Register() : head(nullptr) {}

// Destructor
Register::~Register() {
    deleteList(head); // Call deleteList with head
}

// deleteList Function
void Register::deleteList(Register::UserNode* node) {
    if (node == nullptr) return;
    deleteList(node->next);
    delete node;
}


// addUser Function
void Register::addUser(User user) {
    Register::UserNode* newNode = new Register::UserNode(user); // Create a new UserNode
    if (head == nullptr) {
        head = newNode; // If the list is empty, set head
    } else {
        Register::UserNode* temp = head;
        while (temp->next != nullptr) { // Traverse to the end of the list
            temp = temp->next;
        }
        temp->next = newNode; // Add the new node at the end
    }
}

