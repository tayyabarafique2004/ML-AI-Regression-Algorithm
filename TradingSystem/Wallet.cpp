#include "Wallet.h"


Wallet::Wallet() : userId(0), balance(0.0) {}

Wallet::Wallet( int userId, double balance) : userId(userId), balance(balance) {}

Wallet::~Wallet() {}

//int Wallet::getWalletId() const { return walletId; }
//void Wallet::setWalletId(int walletId) { this->walletId = walletId; }

int Wallet::getUserId() const { return userId; }
void Wallet::setUserId(int userId) { this->userId = userId; }

double Wallet::getBalance() const { return balance; }
void Wallet::setBalance(double balance) { this->balance = balance; }
