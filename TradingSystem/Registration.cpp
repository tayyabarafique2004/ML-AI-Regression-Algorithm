#include "Registrations.h"

// Constructor
Registrations::Registrations()
    : head(nullptr), regId(0), userId(""), registrationDate(""), verificationCode("") {}

// Destructor
Registrations::~Registrations() {
    deleteAllUsers(); // Clean up all dynamically allocated nodes
}

// Add a user to the list
void Registrations::addUser(const User& user) {
    UserNode* newNode = new UserNode(user, head); // Create a new node and point it to the current head
    head = newNode;                              // Update head to the new node
}

// Delete all users
void Registrations::deleteAllUsers() {
    UserNode* current = head;
    while (current) {
        UserNode* temp = current;
        current = current->next;
        delete temp; // Free memory for each node
    }
    head = nullptr; // Reset the head pointer
}

// Display all users
void Registrations::displayUsers() const {
    UserNode* current = head;
    while (current) {
        // Access user details using the User class getters
        std::cout << "Username: " << current->user.getUsername() 
                  << ", Email: " << current->user.getEmail() 
                  << ", Age: " << current->user.getAge() 
                  << ", Wallet ID: " << current->user.getWalletId()
                  << std::endl;
        current = current->next;
    }
}

// Getters and setters for registration details
std::string Registrations::getUserId() const {
    return userId;
}

std::string Registrations::getRegistrationDate() const {
    return registrationDate;
}

std::string Registrations::getVerificationCode() const {
    return verificationCode;
}

void Registrations::setUserId(const std::string& userId) {
    this->userId = userId;
}

void Registrations::setRegistrationDate(const std::string& registrationDate) {
    this->registrationDate = registrationDate;
}

void Registrations::setVerificationCode(const std::string& verificationCode) {
    this->verificationCode = verificationCode;
}
