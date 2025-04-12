#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[3];

public:
    Student() {
        rollNo = 0;
        name = "Default Student";
        marks[0] = marks[1] = marks[2] = 0;
    }

    Student(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float getAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks for 3 subjects: ";
        cin >> marks[0] >> marks[1] >> marks[2];
    }

    void display() const {
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Marks       : " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average     : " << getAverage() << endl;
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << endl << "Enter details for student " << (i + 1) << ":" << endl;
        students[i].input();
    }

    cout << endl << "Student Details:" << endl;
    for (int i = 0; i < n; i++) {
        cout << endl << "Student " << (i + 1) << ":" << endl;
        students[i].display();
    }

    cout << "24CE108_VIVEK_SANGANI" << endl;
    return 0;
}
