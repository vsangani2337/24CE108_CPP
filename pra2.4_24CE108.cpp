#include <iostream>
using namespace std;

class retail_store {
private:
    int item_id;
    string item_name;
    int item_price;
    int item_quantity;

public:
    retail_store() {
        item_id = 0;
        item_name = "";
        item_price = 0;
        item_quantity = 0;
    }

    retail_store(int id, string name, int price, int quantity) {
        item_id = id;
        item_name = name;
        item_price = price;
        item_quantity = quantity;
    }

    void get_data() {
        cout << "Enter the ID of product: ";
        cin >> item_id;
        cin.ignore();
        cout << "Enter the name of product: ";
        getline(cin, item_name);
        cout << "Enter the price of product: ";
        cin >> item_price;
        cout << "Enter the quantity of product: ";
        cin >> item_quantity;
    }

    void put_data() {
        cout << endl;
        cout << "ID       : " << item_id << endl;
        cout << "Name     : " << item_name << endl;
        cout << "Price    : " << item_price << endl;
        cout << "Quantity : " << item_quantity << endl;
    }

    int get_id() {
        return item_id;
    }

    void add_quantity(int qty) {
        item_quantity += qty;
        cout << "Quantity updated." << endl;
    }

    void remove_quantity(int qty) {
        if (qty > item_quantity)
            cout << "Not enough stock to remove." << endl;
        else {
            item_quantity -= qty;
            cout << "Quantity removed." << endl;
        }
    }
};

int main() {
    retail_store store[3];
    int item_limit = 3;
    int total_item = 0;
    int choice;

    do {
        cout << endl << "----- Retail Store Menu -----" << endl;
        cout << "1. Add New Product" << endl;
        cout << "2. Show Product Information" << endl;
        cout << "3. Remove Quantity" << endl;
        cout << "4. Add Quantity" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (total_item < item_limit) {
                store[total_item].get_data();
                total_item++;
            } else {
                cout << "Item limit reached! Cannot add more items." << endl;
            }
            break;

        case 2: {
            int id;
            cout << "Enter the product ID: ";
            cin >> id;
            int found = 0;
            for (int i = 0; i < total_item; ++i) {
                if (store[i].get_id() == id) {
                    store[i].put_data();
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                cout << "Product not found." << endl;
            }
            break;
        }

        case 3: {
            int id, qty;
            cout << "Enter the product ID to remove quantity: ";
            cin >> id;
            cout << "Enter quantity to remove: ";
            cin >> qty;
            int found = 0;
            for (int i = 0; i < total_item; ++i) {
                if (store[i].get_id() == id) {
                    store[i].remove_quantity(qty);
                    found = 1;
                    break;
                }
            }
            if (found == 0) cout << "Product not found." << endl;
            break;
        }

        case 4: {
            int id, qty;
            cout << "Enter the product ID to add quantity: ";
            cin >> id;
            cout << "Enter quantity to add: ";
            cin >> qty;
            int found = 0;
            for (int i = 0; i < total_item; ++i) {
                if (store[i].get_id() == id) {
                    store[i].add_quantity(qty);
                    found = 1;
                    break;
                }
            }
            if (found == 0) cout << "Product not found." << endl;
            break;
        }

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    cout <<"24CE108_VIVEK_SANGANI" << endl;
    return 0;
}
