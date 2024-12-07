#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <string>
#include "User.h"

class UserNode;
class Register {
public:
    Register();              
    ~Register();             
    void addUser(User user); 
   void deleteList(UserNode* node);

private:
    int RegId;
    
  
};

#endif // REGISTER_H
