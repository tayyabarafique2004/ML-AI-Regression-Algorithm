#include<iostream>
#include<string>
using namespace std;

#ifndef USER_H
#define USER_H

#pragma once

class User
{
public:

     User();
     User(string userId,string username,string HashedPassword,int age,string email,int WalletId);
    ~User();

    // Getters and Setters
 //   int getId() const;
 //  void setId(int id);
    
    string getUsername() const;  
    void setUsername(const string& username);
    
    string getHashedPassword() const;
    void setHashedPassword(const string& hashedPassword);
    
    string getEmail() const;
    void setEmail(const string& email);
    
    int getAge() const;
    void setAge(int age);

    string getUserId()const;
    void setUserId(string userId);
 
  int getWalletId() const;
    void setWalletId(int walletId);
private:
// No need since its auto incremental We could have a search/fetch function from DB 
 //   int id;      //oki
    string userId;          
    string username;       
    string hashedPassword; 
    string email;          
    int age;    
    int WalletId;  

};

#endif