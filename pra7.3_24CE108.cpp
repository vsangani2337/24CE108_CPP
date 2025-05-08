#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    int quantity;
    double price;

    void display() const {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
};

class InventorySystem {
private:
    vector<Product> inventory;
    string filename;

public:
    InventorySystem(const string& file) : filename(file) {
        inventory = loadInventory();
    }

    vector<Product> loadInventory() {
        ifstream file(filename);
        string line;
        vector<Product> products;
        while (getline(file, line)) {
            string name;
            int quantity;
            double price;

            size_t pos = line.find(',');
            name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            quantity = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            price = stod(line);

            products.push_back({name, quantity, price});
        }
        file.close();
        return products;
    }

    void saveInventory() {
        ofstream file(filename, ios::trunc);
        if (file.is_open()) {
            for (const auto& product : inventory) {
                file << product.name << "," << product.quantity << "," << product.price << endl;
            }
            file.close();
        } else {
            cout << "Error opening file for writing!" << endl;
        }
    }

    void addProduct(const Product& product) {
        inventory.push_back(product);
        saveInventory();
    }

    void viewInventory() const {
        if (inventory.empty()) {
            cout << "Inventory is empty." << endl;
        } else {
            for (const auto& product : inventory) {
                product.display();
            }
        }
    }

    void searchProduct(const string& searchName) const {
        for (const auto& product : inventory) {
            if (product.name == searchName) {
                product.display();
                return;
            }
        }
        cout << "Product not found!" << endl;
    }
};

int main() {
    string filename = "inventory.txt";
    InventorySystem system(filename);

    int choice;
    do {
        cout << "\nInventory System Menu:" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1: {
            string name;
            int quantity;
            double price;
            
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;

            Product newProduct = {name, quantity, price};
            system.addProduct(newProduct);
            cout << "Product added successfully!" << endl;
            break;
        }
        case 2: {
            cout << "Inventory:" << endl;
            system.viewInventory();
            break;
        }
        case 3: {
            string searchName;
            cout << "Enter product name to search: ";
            cin.ignore();
            getline(cin, searchName);

            cout << "Searching for " << searchName << "..." << endl;
            system.searchProduct(searchName);
            break;
        }
        case 4:
            cout << "Exiting the system." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
