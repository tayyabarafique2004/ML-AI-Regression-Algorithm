#include <iostream>
#define NOMINMAX // Prevent macro conflicts with std::max

#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>
#include <stdexcept>
#include <conio.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <limits>

#include "DatabaseHandler.h"

// Global variables
std::atomic<bool> isRunning{ true };
bool isLoggedIn = false;
std::string loggedInUserId;
std::mutex consoleMutex;

// Utility functions
void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear screen
}

void moveCursorTo(int row, int col) {
    std::cout << "\033[" << row << ";" << col << "H"; // ANSI escape sequence to position cursor
}

int getValidatedInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }
}

std::string getValidatedInput(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) {
            return value;
        }
        std::cout << "Invalid input. Please enter a non-empty value.\n";
    }
}

std::string getPasswordInput(const std::string& prompt = "Enter Password: ") {
    std::cout << prompt;
    std::string password;
    char ch;
    while (true) {
        ch = _getch();  // Capture input
        if (ch == 13) break;  // Enter key
        if (ch == 8 && !password.empty()) {  // Backspace key
            password.pop_back();
            std::cout << "\b \b";  // Erase the last asterisk
        }
        else if (ch != 8) {
            password += ch;
            std::cout << "*";  // Display asterisks for entered characters
        }
    }
    std::cout << std::endl;  // Move to the next line after input
    return password;
}


// Function to update prices periodically
void UpdatePricesPeriodically(DatabaseHandler& dbHandler) {
    while (isRunning) {
        try {
            {
                std::lock_guard<std::mutex> lock(consoleMutex);
                dbHandler.ExecuteProcedure("AdjustAssetPrices");

                moveCursorTo(1, 0); // Position for updated prices display
                std::cout << "Updated Asset Prices:\n";
                dbHandler.DisplayPriceChanges();
                std::cout.flush();
            }
            std::this_thread::sleep_for(std::chrono::seconds(20));
        }
        catch (const std::exception& ex) {
            std::cerr << "Error updating prices: " << ex.what() << std::endl;
        }
    }
}

// User landing page
void userLandingPage() {
    try {
        DatabaseHandler dbHandler;

        std::cout << "\nWelcome to the Trading System!\n";
        dbHandler.DisplayAssets();

        int choice;
        do {
            std::cout << "\n===============================================\n";
            std::cout << "Trading Menu:\n";
            std::cout << "1. Buy an Asset\n";
            std::cout << "2. Sell an Asset\n";
            std::cout << "3. View Portfolio\n";
            std::cout << "4. Transfer Balance\n";
            std::cout << "5. Transfer Assets\n";
            std::cout << "6. Convert Assets\n";
            std::cout << "7. View Top Gainer\n";
            std::cout << "8. Exit\n";
            std::cout << "===============================================\n";

            choice = getValidatedInt("Enter your choice: ");
            int userID = dbHandler.GetUserIdByUsername(loggedInUserId);

            try {
                switch (choice) {
                case 1: {
                    int assetId = getValidatedInt("Enter Asset ID: ");
                    int quantity = getValidatedInt("Enter Quantity: ");
                    double price = dbHandler.FetchAssetPrice(assetId);
                    dbHandler.BuyAsset(userID, dbHandler.GetAssetNameById(assetId), quantity, price);
                    break;
                }
                case 2: {
                    int assetId = getValidatedInt("Enter Asset ID: ");
                    int quantity = getValidatedInt("Enter Quantity: ");
                    dbHandler.SellAsset(userID, assetId, quantity);
                    break;
                }
                case 3:
                    dbHandler.DisplayPortfolio(userID);
                    break;
                case 4:
                    dbHandler.TransferBalance(userID);
                    break;
                case 5: {
                    int receiverId = getValidatedInt("Enter Receiver ID: ");
                    int assetId = getValidatedInt("Enter Asset ID: ");
                    int quantity = getValidatedInt("Enter Quantity: ");
                    dbHandler.TransferAsset(userID, receiverId, assetId, quantity);
                    break;
                }
                case 6: {
                    int sourceAssetId = getValidatedInt("Enter Source Asset ID: ");
                    int targetAssetId = getValidatedInt("Enter Target Asset ID: ");
                    int quantity = getValidatedInt("Enter Quantity: ");
                    dbHandler.ConvertAsset(userID, sourceAssetId, targetAssetId, quantity);
                    break;
                }
                case 7:
                    dbHandler.PrintTopGainer();
                    break;
                case 8:
                    std::cout << "Exiting the trading system. Goodbye!\n";
                    return;
                default:
                    std::cout << "Invalid choice. Try again.\n";
                }
            }
            catch (const std::exception& ex) {
                std::cerr << "Error processing request: " << ex.what() << std::endl;
            }
        } while (true);
    }
    catch (const std::exception& ex) {
        std::cerr << "Error in user landing page: " << ex.what() << std::endl;
    }
}

// Authentication system
void authenticateUser() {
    DatabaseHandler dbHandler;

    std::cout << "\nWelcome to the Trading System!\n";

    int choice;
    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
        std::cout << "3. Exit\n";

        choice = getValidatedInt("Enter your choice: ");
        try {
            if (choice == 1) {
                std::string username = getValidatedInput("Enter username: ");
                std::string password = getPasswordInput();

                if (dbHandler.AuthenticateUser(username, password)) {
                    loggedInUserId = username;
                    userLandingPage();
                }
                else {
                    std::cout << "Invalid credentials. Try again.\n";
                }
            }
            else if (choice == 2) {
                std::string username = getValidatedInput("Enter username: ");
                std::string email = getValidatedInput("Enter email: ");
                std::string password = getPasswordInput();

                if (dbHandler.RegisterUser(username, email, password)) {
                    std::cout << "Registration successful.\n";
                }
                else {
                    std::cout << "Registration failed. Try again.\n";
                }
            }
            else if (choice == 3) {
                isRunning = false;
                return;
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    } while (isRunning);
}

// Main function
int main() {
    DatabaseHandler dbHandler;
    std::thread priceUpdater(UpdatePricesPeriodically, std::ref(dbHandler));

    while (isRunning) {
        try {
            authenticateUser();
        }
        catch (const std::exception& ex) {
            std::cerr << "Fatal error: " << ex.what() << std::endl;
            isRunning = false;
        }
    }

    isRunning = false;
    priceUpdater.join();

    return 0;
}
