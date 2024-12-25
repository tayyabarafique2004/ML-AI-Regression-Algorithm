#pragma once

#include <string>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>

class DatabaseHandler {
private:
    SQLHANDLE sqlEnvHandle;
    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLRETURN retCode;

    std::string connStr = "Driver={ODBC Driver 18 for SQL Server};Server=localhost,1433;Database=DbTrading;Uid=SA;Pwd=YourPassword123;Encrypt=no;TrustServerCertificate=yes;Connection Timeout=30;";

    void checkSuccess(SQLRETURN retCode, const std::string& errorMessage, SQLHANDLE handle = nullptr, SQLSMALLINT handleType = SQL_HANDLE_STMT);
    void logSQLError(SQLHANDLE handle, SQLSMALLINT type);

public:
    DatabaseHandler();
    ~DatabaseHandler();

    void ExecuteProcedure(const std::string& procedureName);
    void DisplayPriceChanges();
    void AddOrUpdateAsset(const std::string& assetName, const std::string& assetParentPair, double assetPrice, int assetQuantity);
    void BuyAsset(int userId, const std::string& assetName, int quantity, double price);
    void SellAsset(int userId, int assetId, int quantity);
    void DisplayAssets();
    double FetchAssetPrice(int assetId);
    void DisplayPortfolio(int userId);
    std::string GetAssetNameById(int assetId);
    double GetUserBalance(int userId);
    void TransferBalance(int senderId);
    int GetWalletId(int userId);
    void TransferAsset(int senderId, int receiverId, int assetId, int quantity);
    void ConvertAsset(int userId, int sourceAssetId, int targetAssetId, int sourceQuantity);
    void PrintTopGainer();
    bool AuthenticateUser(const std::string& username, const std::string& hashedPassword);
    bool RegisterUser(const std::string& username, const std::string& email, const std::string& hashedPassword);
    int GetUserIdByUsername(const std::string& username);
};
