    #include "Wallet.h"

#include "Wallet.h"

Wallet::Wallet() : walletId(0), userId(0), balance(0.0) {}

Wallet::Wallet(int walletId, int userId, double balance) 
    : walletId(walletId), userId(userId), balance(balance) {}

Wallet::~Wallet() {}

int Wallet::getWalletId() const { return walletId; }
void Wallet::setWalletId(int walletId) { this->walletId = walletId; }

int Wallet::getUserId() const { return userId; }
void Wallet::setUserId(int userId) { this->userId = userId; }

double Wallet::getBalance() const { return balance; }
void Wallet::setBalance(double balance) { this->balance = balance; }
