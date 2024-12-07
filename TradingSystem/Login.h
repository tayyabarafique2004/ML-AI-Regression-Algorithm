#include<iostream>
#include<string>
using namespace std;

#ifndef LOGIN_H
#define LOGIN_H

#pragma once

class Login
{
public:
        Login();
        // 
        Login(string userid, const string &date = " ");

    ~Login();

    // getters
    string getUserId() const;
    string getDate() const;

    // setters
    void setUserId(string id);
    void setdate(string &date);


private:
    string userid; // Not the Primary key 
    string date; // can be left empty (can Push To database through built in function)
    
    //lemme change this in db its nvarchar there
    //isVerified was also about this now status too ?y/n// let me see the tables again jya
    // we dont need Status actually during login 
    // remoove from db
};
//listen refresh db 
//oki lemme drop status

//dropped
#endif
