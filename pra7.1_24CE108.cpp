#include <iostream>
#include <cstring>
#include <map>

using namespace std;

// Non-STL Approach

struct WordEntry {
    char* word;
    int count;
};

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

int isPunctuation(char c) {
    return (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':' || c == '\t' || c == '\n');
}

int findWord(WordEntry* list, int count, const char* token) {
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].word, token) == 0) return i;
    }
    return -1;
}

void processWithoutSTL(const char* text) {
    char* textCopy = new char[strlen(text) + 1];
    strcpy(textCopy, text);
    toLowerCase(textCopy);

    WordEntry* words = new WordEntry[100];
    int count = 0;

    char* token = strtok(textCopy, " ,.!?;:\t\n");
    while (token) {
        int idx = findWord(words, count, token);
        if (idx != -1) {
            words[idx].count++;
        } else {
            words[count].word = new char[strlen(token) + 1];
            strcpy(words[count].word, token);
            words[count].count = 1;
            count++;
        }
        token = strtok(nullptr, " ,.!?;:\t\n");
    }

    cout << endl << "Frequencies (Non-STL):" << endl;
    for (int i = 0; i < count; i++) {
        cout << words[i].word << ": " << words[i].count << endl;
        delete[] words[i].word;
    }

    delete[] words;
    delete[] textCopy;
}

// STL Approach

void processWithSTL(const string& text) {
    map<string, int> freq;
    string word;
    int length = text.length();
    for (int i = 0; i < length; i++) {
        char c = text[i];

        if (isPunctuation(c)) {
            if (!word.empty()) {
                freq[word]++;
                word.clear();
            }
        } else {
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }
            word += c;
        }
    }

    if (!word.empty()) {
        freq[word]++;
    }

    cout << endl << "Frequencies (STL):" << endl;
    for (const pair<string, int>& p : freq) {
        cout << p.first << ": " << p.second << endl;
    }
}

int main() {
    string text;
    cout << "Enter a paragraph:" << endl;
    getline(cin, text);

    processWithoutSTL(text.c_str()); // Non-STL approach
    processWithSTL(text);            // STL approach

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
