#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

int countCharacterSequence(const string& filename, const string& sequence) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open the file: " << filename << endl;
        return 0;
    }

    int count = 0;
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(sequence);
        while (pos != string::npos) {
            ++count;
            pos = line.find(sequence, pos + sequence.length());
        }
    }

    file.close();
    return count;
}

void readFile(unordered_map<string, int>& done) {
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Failed to open the file for reading." << endl;
        // return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string key;
        int value;
        if (iss >> key >> value) {
            done[key] = value;
        }
    }

    inputFile.close();
}

void writeFile(unordered_map<string, int> done) {
    ofstream outputFile("data.txt");
    if (!outputFile) {
        cerr << "Failed to open the file for writing." << endl;
        // return 1;
    }

     for (const auto& entry : done) {
        outputFile << entry.first << " " << entry.second << endl;
    }
    outputFile.close();
}

int meanCalc(unordered_map<string, int> done) {
    int sum = 0;
    int div = 0;
    int mean = 0;

        for ( const auto& entry : done ) {
        sum += entry.second;
        div++;
    }

    mean = sum / div;

    return mean;
}

bool checkDate(unordered_map<string,int> done) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    bool marked = false;

    for (const auto& entry : done) {
        if ((to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + '/' + to_string(1900 + ltm->tm_year))  == entry.first) {
            marked = true;
        }
    }

    return marked;
}

int main() {
    unordered_map<string, int> done = {};
    string filename = "README-pl.md";

    bool marked = false;
    int dayli = 4;
    int count = 0;
    int mean = 0;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    readFile(done);
    marked = checkDate(done);

    if ( marked == false ) {
        cout << "You didnt report your work today" << endl;
        cout << "Give a number: ";
        cin >> count;
            done[(to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + '/' + to_string(1900 + ltm->tm_year))] = count;
            writeFile(done);
    } else {
        cout << "Already done" << endl;
    }

    mean = meanCalc(done);

    string markedNot = "- [ ]";
    string markedDone = "- [X]";
    int countNotDone = countCharacterSequence(filename, markedNot);
    int countDone = countCharacterSequence(filename, markedDone);

    string time = "";

    if (countNotDone / ((int)mean * 30) < 1 ) {
        time = (to_string(countNotDone / (int)mean) + " days");
    } else {
        time = (to_string(countNotDone / ((int)mean * 30)) + " months");
    }

    cout << "You have done: " << countDone <<" and there is: " << countNotDone << " left." << endl;
    cout << "You do mean: " << (int)mean <<" per day, and in that speed, you will finish in: " << time << "." << endl;
    return 0;
}
