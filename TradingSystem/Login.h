#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>

class Login {
public:
    Login();                                       // Default constructor
    Login(const std::string& userid,               // Parameterized constructor
          const std::string& date = "");

    ~Login();                                      // Destructor

    // Getters
    std::string getUserId() const;
    std::string getDate() const;

    // Setters
    void setUserId(const std::string& userid);
    void setDate(const std::string& date);

private:
    std::string userid;  // User ID
    std::string date;    // Login date
};

#endif // LOGIN_H
