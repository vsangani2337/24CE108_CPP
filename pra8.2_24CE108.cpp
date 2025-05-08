#include <iostream>
#include <sstream>
#include <map>
#include <cctype>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence : ";
    getline(cin, sentence);

    map<string, int> wordCount;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        for (auto& ch : word) {
            ch = tolower(ch); 
            if (ispunct(ch)) ch = ' '; 
        }
        stringstream cleanWordStream(word);
        cleanWordStream >> word;

        if (!word.empty())
            wordCount[word]++;
    }

    cout << endl <<"Word Frequency :" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}