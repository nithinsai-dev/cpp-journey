//
// Created by NITHIN SAI on 14-06-2026.
//

#include "p18.h"

#include <iostream>

int main() {
    double balance = 500.00; // Starting balance
    int choice;
    double amount;

    do {
        std::cout << "\n--- Mock ATM Menu ---\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Your current balance is: $" << balance << "\n";
        }
        else if (choice == 2) {
            std::cout << "Enter deposit amount: $";
            std::cin >> amount;
            balance += amount;
            std::cout << "$" << amount << " deposited successfully.\n";
        }
        else if (choice == 3) {
            std::cout << "Enter withdrawal amount: $";
            std::cin >> amount;

            // Ternary operator to check if sufficient funds exist
            bool allowed = (amount <= balance) ? true : false;

            if (allowed) {
                balance -= amount;
                std::cout << "Please take your cash: $" << amount << "\n";
            } else {
                std::cout << "Error: Insufficient funds!\n";
            }
        }
        else if (choice != 4) {
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    std::cout << "\nThank you for using our ATM. Goodbye!\n";
    return 0;
}
