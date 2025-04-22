#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Fuel {
protected:
    string fuel_type;

public:
    Fuel(const string& fuel) : fuel_type(fuel) {}

    void display_fuel() const {
        cout << "Fuel Type: " << fuel_type << endl;
    }
};

class Brand {
protected:
    string brand_name;

public:
    Brand(const string& brand) : brand_name(brand) {}

    void display_brand() const {
        cout << "Brand Name: " << brand_name << endl;
    }
};

class Car : public Fuel, public Brand {
private:
    string car_model;

public:
    Car(const string& model, const string& brand, const string& fuel)
        : Brand(brand), Fuel(fuel), car_model(model) {}

    void display_details() const {
        display_brand();
        display_fuel();
        cout << "Car Model: " << car_model << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    queue<Car> car_queue;

    car_queue.push(Car("Corolla", "Toyota", "Gasoline"));
    car_queue.push(Car("Model 3", "Tesla", "Electric"));
    car_queue.push(Car("F-150", "Ford", "Diesel"));

    while (!car_queue.empty()) {
        Car c = car_queue.front();
        c.display_details();
        car_queue.pop();
    }

    const int car_count = 3;
    Car car_array[car_count] = {
        Car("Civic", "Honda", "Hybrid"),
        Car("M5", "BMW", "Gasoline"),
        Car("Leaf", "Nissan", "Electric")
    };

    for (int i = 0; i < car_count; ++i) {
        car_array[i].display_details();
    }

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
