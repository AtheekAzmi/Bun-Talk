#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

// Function to display the menu
void displayMenu() {
    cout<<"\n\t------- Bun Talk bakery Menu -------";
	cout<<"\n\n\t[1] White Bread		- LKR 150.00";
	cout<<"\n\t[2] Kurakkan bread	- LKR 200.00";
	cout<<"\n\t[3] Bagutte		- LKR 340.00";
	cout<<"\n\t[4] Fish Bun		- LKR 100.00";
	cout<<"\n\n\t[5]Help.";
	cout<<"\n\t[0]Checkout.";
	cout<<"\n\t===================================";// Change "Finish" to "Exit"
    // Add more items to the menu
}

void displayHelp() {
    cout << "\tBun Talk Bakery Help:" << endl;
    cout << "\t----------------------------------------------" << endl;
    cout << "\t     Welcome to Bun Talk Bakery!     "<< endl;
    cout << "\t1) To place an order, enter the item number for\n\t each item you want to order." << endl;
    cout << "\t2) To finish your order, enter '0'." << endl;
    cout << "\t3) To display this help message again, enter '4'." << endl;
    cout << "\t4) To exit the program, enter '0'." << endl;
    cout << "\t----------------------------------------------" << endl;
}

int main() {
    // Authentication
    string username, password;
    cout <<  "\n\tWelcome To Bun Talk Bakery!";
    cout << "\n\t------ Please log in ------" << endl;
    cout << "\n\tUsername: ";
    cin >> username;
    cout << "\tPassword: ";
    cin >> password;

    // Simple authentication (not secure, just for demonstration)
    if(username == "Admin" && password == "Admin123"){
		cout<<"\n\tSuccessfully logged in.\n\n\t===================================\n\t---- Welcome to Bun Talk Bakery----\n\t==================================="<< endl;


        // Menu items and their prices
        map<int, string> items = {
            {1, "White Bread"},
            {2, "Kurakkan bread"},
            {3, "Bagutte"},
            {4, "Fish Bun"}
            // Add more items to the map
        };
        map<int, double> prices = {
            {1, 150.00},
            {2, 200.00},
            {3, 340.00},
            {4, 100.00}
            // Add more prices
        };

        vector<int> selectedItems;
        int choice;

        do {
            // Display menu and get customer's choice
            displayMenu();
            cout << "\n\n\tEnter item number: ";
            cin >> choice;

            if (choice == 5) {
                // Display the help message
                displayHelp();
            }

            else if (choice >= 1 && choice <= prices.size()) {
                selectedItems.push_back(choice);
            }
            else if (choice != 0) {
                cout << "Invalid choice. Please try again." << endl;
            }

        }

        while (choice != 0);

        // Calculate and print the bill
        double total = 0.0;
        cout << "\t--------------------------" << endl;
        cout << "\t Bun Talk Bakery Receipt" << endl;
        cout << "\t--------------------------" << endl;
        cout << "\tItem\t\tAmount\n" << endl;
        for (int item : selectedItems) {
            cout << "\t"<<left << setw(15) << items[item] << " LKR." << fixed << setprecision(2) << prices[item] << endl;
            total += prices[item];
        }
        cout << "\t--------------------------" << endl;
        cout << "\tTotal:          LKR." << total << endl;

        // Save the receipt to a text files
        ofstream receiptFile("receipt.txt");
        receiptFile << "\t--------------------------" << endl;
        receiptFile << "\t Bun Talk Bakery Receipt" << endl;
        receiptFile << "\t--------------------------" << endl;
        receiptFile << "\tItem\t\tAmount\n" << endl;
        for (int item : selectedItems) {
            receiptFile <<"\t"<< left << setw(15) << items[item] << " LKR." << fixed << setprecision(2) << prices[item] << endl;
        }
        receiptFile << "\t--------------------------" << endl;
        receiptFile << "\tTotal:          LKR." << total << endl;
        receiptFile.close();

        cout << "\n\t  ***** Thank you! *****" << endl;
    }

    else {
        cout << "\n\tLogin failed. \n\tEntered invalid username or password..." << endl;
    }

    return 0;
}
