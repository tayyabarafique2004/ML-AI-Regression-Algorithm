#include<iostream>
#include<string>
using namespace std;


#ifndef WALLET_H
#define WALLET_H

#pragma once

class Wallet {
public:
    Wallet();
    Wallet(int userId, double balance);
    ~Wallet();

  //  int getWalletId() const;
   // void setWalletId(int walletId);

    int getUserId() const;
    void setUserId(int userId);

    double getBalance() const;
    void setBalance(double balance);

private:
  //  int walletId;
    int userId;
    float balance;
};

#endif