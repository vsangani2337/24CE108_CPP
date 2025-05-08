#include <iostream>
#include <map>
#include <vector>

using namespace std;

void addFolder(map<string, vector<string>>& directory) {
    string folderName;
    cout << "Enter folder name: ";
    cin >> folderName;
    
    if (directory.find(folderName) == directory.end()) {
        directory[folderName] = {};
        cout << "Folder added successfully!" << endl;
    } else {
        cout << "Folder already exists!" << endl;
    }
}

void addFile(map<string, vector<string>>& directory) {
    string folderName, fileName;
    cout << "Enter folder name: ";
    cin >> folderName;

    if (directory.find(folderName) == directory.end()) {
        cout << "Folder doesn't exist. Please add it first." << endl;
        return;
    }

    cout << "Enter file name: ";
    cin >> fileName;
    directory[folderName].push_back(fileName);
    cout << "File added successfully!" << endl;
}

void displayDirectory(const map<string, vector<string>>& directory) {
    if (directory.empty()) {
        cout << "No folders available." << endl;
        return;
    }

    for (const auto& folder : directory) {
        cout << "Folder: " << folder.first << endl;
        if (folder.second.empty()) {
            cout << "  [No files]" << endl;
        } else {
            cout << " Files: ";
            for (const auto& file : folder.second) {
                cout << file << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    map<string, vector<string>> directory;
    int choice;

    do {
        cout << "\n1. Add Folder\n2. Add File\n3. Display Directory\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addFolder(directory); break;
            case 2: addFile(directory); break;
            case 3: displayDirectory(directory); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    cout << "24CE108_VIVEK_SANGANI" << endl;
    
    return 0;

    
}
