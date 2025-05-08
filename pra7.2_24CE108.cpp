#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to count words in a line without using <cctype> and <sstream>
int countWords(const string& line) {
    int wordCount = 0;
    bool inWord = false;  // Flag to track if we are inside a word
    
    for (char ch : line) {
        if (isspace(ch) || ch == '\n' || ch == '\t') {  
            if (inWord) {
                wordCount++;  // End of a word
                inWord = false;
            }
        } else {
            inWord = true; 
        }
    }

    if (inWord) {
        wordCount++;
    }
    
    return wordCount;
}

// Function for STL Approach
void processWithSTL(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;  
    }

    int totalLines = 0;
    int totalWords = 0;
    int totalCharacters = 0;

    vector<string> lines;  
    
    string line;
    while (getline(file, line)) {
        lines.push_back(line);  

        totalLines++;
        totalCharacters += line.length();
        totalWords += countWords(line);
    }

    file.close();

    cout << "\nSTL Approach Results:\n";
    cout << "Total Lines: " << totalLines << endl;
    cout << "Total Words: " << totalWords << endl;
    cout << "Total Characters: " << totalCharacters << endl;
}

// Function for Non-STL Approach
void processWithoutSTL(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return; 
    }

    int totalLines = 0;
    int totalWords = 0;
    int totalCharacters = 0;

    int maxLines = 1000;
    string* lines = new string[maxLines];  
    int currentLine = 0;

    string line;
    while (getline(file, line)) {
        if (currentLine >= maxLines) {
            maxLines *= 2;
            string* temp = new string[maxLines];
            for (int i = 0; i < currentLine; ++i) {
                temp[i] = lines[i];
            }
            delete[] lines;
            lines = temp;
        }

        lines[currentLine++] = line;  

        totalLines++;
        totalCharacters += line.length();
        totalWords += countWords(line);
    }

    file.close();

    cout << "\nNon-STL Approach Results:\n";
    cout << "Total Lines: " << totalLines << endl;
    cout << "Total Words: " << totalWords << endl;
    cout << "Total Characters: " << totalCharacters << endl;

    delete[] lines;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    // Call STL Approach
    processWithSTL(filename);

    // Call Non-STL Approach
    processWithoutSTL(filename);

    cout << endl << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
