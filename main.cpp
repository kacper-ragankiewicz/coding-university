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

void gitPull() {
    const char* gitCommand = "git pull --quiet";
    int result = system(gitCommand);
    if (result == 0) {
        cout << result << endl;
    } else {
        cout << result << endl;
    }
    return;
}

void gitPush(string date) {
    const string gitCommitString = "git commit -m '" + date +"' --quiet ";\
    const char* gitCommit = gitCommitString.c_str();
    const char* gitCommand = "git add .";
    const char* gitPush = "git push --quiet";
    int result = system(gitCommand);
    if (result == 0) {
        cout << result << endl;
        int result = system(gitCommit);
        if (result == 0) {
            cout << result << endl;
            int result = system(gitPush);
            if (result == 0) {
                cout << result << endl;
            } else {
            cout << result << endl;
            }
        } else {
            cout << result << endl;
        }
    } else {
        cout << result << endl;
    }
    return;
}

void readFile(unordered_map<string, int>& done) {
    ifstream inputFile("date.txt");
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
    ofstream outputFile("date.txt");
    if (!outputFile) {
        cerr << "Failed to open the file for writing." << endl;
        // return 1;
    }

     for (const auto& entry : done) {
        outputFile << entry.first << " " << entry.second << endl;
    }
    outputFile.close();
}

int averageCalc(unordered_map<string, int> done) {
    int sum = 0;
    int div = 0;
    int average = 0;

    auto it = done.begin();
    if (it != done.end()) {
        int prevEntry = it->second;
        ++it; // Move to the second entry

        for (; it != done.end(); ++it) {
            sum += abs(it->second - prevEntry);
            prevEntry = it->second;
            cout << "sum " << sum <<endl;
            div++;
        }
    }

    average = sum / div;

    return average;
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

string getYesterdayDate() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    // Get yesterday's date
    tm yesterday = *ltm;
    yesterday.tm_mday--;

    tm* yesterdayLtm = &yesterday;

    // Format the date as a string
    string dateString =
        to_string(yesterdayLtm->tm_mday) + "/" +
        to_string(1 + yesterdayLtm->tm_mon) + "/" +
        to_string(1900 + yesterdayLtm->tm_year);

    return dateString;
}

int main() {
    unordered_map<string, int> done = {};
    string filename = "coding_university.md";

    bool marked = false;
    bool git = false;
    int dayli = 4;
    int count = 0;
    int average = 0;
    int workdone = 0;
    const char* gitCommand = "git config user.email";
    int result = system(gitCommand);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    if (result == 0) {
        git = true;
        cout << endl;
    } else {
        cout << "No github" << endl;
    }

    if ( git == true ) {
    gitPull();
    }

    readFile(done);
    marked = checkDate(done);

    string markedNot = "- [ ]";
    string markedDone = "- [X]";
    int countNotDone = countCharacterSequence(filename, markedNot);
    int countDone = countCharacterSequence(filename, markedDone);


    if ( marked == false ) {
        string yesterday = getYesterdayDate();
        auto it = done.find(yesterday);
        if ( it != done.end()) {
            cout << ">>> Found yesterday." << endl;
            count = countDone;
        } else {
            // cout << ">>> You didn't report your work today" << endl;
            // cout << ">> Give a number: ";
            // cin >> workdone;
            count = countDone;
        }
        done[(to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + '/' + to_string(1900 + ltm->tm_year))] = count;
        writeFile(done);
        average = averageCalc(done);
    } else {
        average = averageCalc(done);
        cout << ">>> Already done, for edit, remove date from data.txt" << endl;
    }



    string time = "";

    if (countNotDone / ((int)average * 30) < 2 ) {
        time = (to_string(countNotDone / (int)average) + " days");
    } else {
        time = (to_string(countNotDone / ((int)average * 30)) + " months");
    }


    if( git == true ) {
        gitPush((to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + '/' + to_string(1900 + ltm->tm_year)));
    }

    cout << ">>> You have done: " << countDone <<" and there is: " << countNotDone << " left." << endl;
    cout << ">>> You do average: " << (int)average <<" per day, and in that speed, you will finish in: " << time << "." << endl;

    return 0;
}
