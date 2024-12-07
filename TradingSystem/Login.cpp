#include "Login.h"



// Use a Built in Function to Fetch current date 
// Store it in a string and pass that to this constructor and store in DB 
Login::Login() : userid(" "), date(" ") {}
Login::~Login() {}

Login::Login(string userid, const string &date) : userid(userid), date(date) {}

string Login::getUserId(){
    return userid;
}
string Login::getDate(){
    return date;
}

void Login::setUserId(const string & id){
    userid = id;
}
void Login::setDate(const string &d){
   this->date = d;
}


