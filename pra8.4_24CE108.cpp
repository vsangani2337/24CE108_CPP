#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<pair<string, int>> students;
    int n;
    string name;
    int score;

    cout << "Enter the number of students : ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter name and score for student " << (i + 1) << " : ";
        cin >> name >> score;
        students.push_back(make_pair(name, score));
    }

    sort(students.begin(), students.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    cout << endl << "Ranked List of Students :" << endl;
    cout << left << setw(11) << "Rank" << setw(13) << "Name" << setw(10) << "Score" << endl;
    cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;

    int rank = 1;
    for (const auto& student : students) {
        cout << left << setw(10) << rank << setw(15) << student.first << setw(10) << student.second << endl;
        rank++;
    }

    cout << "24CE108_VIVEK_SANGANI" << endl;
    return 0;
}
