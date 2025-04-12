#include<iostream>
#include<vector>

using namespace std;

class employee
{
private:
   string employee_name;
   int basic_salary;
   int bonus;

public:
    employee(string name , int salary , int Bonus)
    {
       employee_name = name;
       basic_salary = salary;
       bonus = Bonus;
       cal_total_salary();
    }

    double cal_total_salary()
    {
        return basic_salary + bonus ;
    }

    void put_data()
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "Employee Name : " << employee_name << endl;
        cout << "Basic Salary of Employee : " << basic_salary << endl;
        cout << "Bonus : " << bonus << endl;
        cout << "Total Salary of Employee : " << cal_total_salary() << endl;
        cout << "-----------------------------------------------------" << endl;
    }
};

int main(){

vector <employee>emp ;

   string name;
   int salary;
   int Bonus;
   int total_employee;

cout << "Enter the number of employee : ";
cin >> total_employee;

for( int i=0 ; i < total_employee ; i++)
   {
        cout << "-----------------------------------------------------" << endl;
        cout << " Enter the name of employee : ";
        cin >> name;
        cout << " Enter the basic salary of employee : ";
        cin >> salary;
        cout << " Enter the bonus : ";
        cin >> Bonus;
        cout << "-----------------------------------------------------" << endl;
        emp.emplace_back( name , salary , Bonus );
   }

for(auto &i : emp)
   {
       i.put_data();
       cout << endl;
   }

   cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
