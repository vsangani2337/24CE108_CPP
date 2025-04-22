#include<iostream>
#include<vector>

using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person( string name , int age ) :  name(name) , age(age) {}

    void display_person() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person
{
protected:
    int employee_id;

public:
    Employee(string name, int age, int employee_id) : Person(name, age), employee_id(employee_id) {}

    void display_emp() const
    {
        display_person();
        cout << "Employee ID: " << employee_id << endl;
    }
};

class Manager : public Employee
{
protected:
    string department;
    vector<Employee> team;

public:
    Manager(string name, int age, int employee_id, string department)
        : Employee(name, age, employee_id), department(department) {}

    void addEmployee(const Employee& employee)
    {
        team.push_back(employee);
    }

    void display_manager()
    {
        display_emp();
        cout <<"Department: " << department << endl;
        cout <<"----------------------------"<< endl;
        cout << "Team Members:" << endl << endl;
        for (const auto& e : team)
        {
            e.display_emp();
        }
    }
};


int main() {

    Manager manager1("Alice Johnson", 40, 101, "IT Department");
    Employee emp1("Bob Smith", 28, 201);
    Employee emp2("Carol White", 32, 202);
    Employee emp3("Walter White", 35, 203);

    manager1.addEmployee(emp1);
    manager1.addEmployee(emp2);
    manager1.addEmployee(emp3);

    cout << "Manager Details:" << endl << endl;
    manager1.display_manager();

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}