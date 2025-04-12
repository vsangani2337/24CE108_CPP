#include <iostream>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    float price;

    Product(int product_id, string product_name, int product_quantity, float product_price) {
        id = product_id;
        name = product_name;
        quantity = product_quantity;
        price = product_price;
    }

    void update_quantity(int product_quantity) {
        quantity = product_quantity;
    }
};

class Inventory {
private:
    Product* products[50];
    int product_count = 0;

public:
    void add_product() {
        if (product_count >= 50) {
            cout << "Inventory is full" << endl;
            return;
        }

        int product_id, product_quantity;
        string product_name;
        float product_price;

        cout << "Enter Product ID: ";
        cin >> product_id;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, product_name);

        cout << "Enter Product Quantity: ";
        cin >> product_quantity;

        cout << "Enter Product Price: ";
        cin >> product_price;

        products[product_count++] = new Product(product_id, product_name, product_quantity, product_price);
    }

    void update_quantity(int id, int quantity) {
        for (int i = 0; i < product_count; ++i) {
            if (products[i]->id == id) {
                products[i]->update_quantity(quantity);
                cout << "Quantity updated successfully." << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    float calculate_total_value() {
        float total_value = 0;
        for (int i = 0; i < product_count; ++i) {
            total_value += products[i]->quantity * products[i]->price;
        }
        return total_value;
    }

    ~Inventory() {
        for (int i = 0; i < product_count; ++i) {
            delete products[i];
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << endl << "1. Add Product" << endl;
        cout << "2. Update Product Quantity" << endl;
        cout << "3. Calculate Total Inventory Value" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.add_product();
                break;
            case 2: {
                int product_id, product_quantity;
                cout << "Enter Product ID to update: ";
                cin >> product_id;
                cout << "Enter new quantity: ";
                cin >> product_quantity;
                inventory.update_quantity(product_id, product_quantity);
                break;
            }
            case 3:
                cout << "Total Inventory Value: $" << inventory.calculate_total_value() << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    cout <<"24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
