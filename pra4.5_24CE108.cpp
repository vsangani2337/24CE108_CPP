#include<iostream>
#include<vector>

using namespace std;

class Student
{
protected:
    float marks;
public:
    void set_marks( float m )
    {
        marks = m;
    }

    virtual string compute_grade() = 0;

    ~Student( ){}
};

class under_graduate : public Student
{
public:
    string compute_grade() override
    {
        if( marks >= 85 ) return "A";
        else if( marks >= 70 ) return "B";
        else if( marks >= 50 ) return "C";
        else return "F";
    }
};

class post_graduate : public Student
{
public:
    string compute_grade() override
    {
        if( marks >= 90 ) return "A";
        else if( marks >= 75 ) return "B";
        else if( marks >= 60 ) return "C";
        else return "F";
    }
};

int main()
{
    vector < Student* > students;

    int n;
    cout << "Enter the number of student : ";
    cin >> n;

    for ( int i = 0 ; i < n ; i++ )
    {
        int type;
        float m;

        cout << "Enter 1 for under graduate and 2 for Post graduate : ";
        cin >> type;

        cout << "Enter the marks of Student : ";
        cin >> m;

        Student* s = nullptr;

        if( type == 1 )
        {
            s = new under_graduate();
        }
        else if( type == 2 )
        {
            s = new post_graduate();
        }
        else
        {
            cout << "Invalid Student type!" << endl;
            continue;
        }

        s->set_marks( m );
        students.push_back(s);
    }

    cout << endl << "Student Grade : " << endl;
    for( size_t i = 0 ; i < students.size() ; ++i  )
    {
        cout << "Student " << i+1 << " Grade : " << students[i]->compute_grade() << endl;
    }

    for( size_t i = 0 ; i < students.size() ; ++i  )
    {
        delete students[i];

    }

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
