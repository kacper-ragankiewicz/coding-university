#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <algorithm>

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

void readFile(map<string, int>& done) {
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

void writeFile(map<string, int> done) {
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

int averageCalc(const std::map<std::string, int>& done) {
    int sum = 0;
    int div = 1;

    auto it = done.begin();
    if (it != done.end()) {
        int prevEntry = it->second;
        ++it; // Move to the next entry
        for (; it != done.end(); ++it) {
            sum += std::abs(prevEntry - it->second);
            prevEntry = it->second;
            div++;
        }
    }

    if (div == 0) {
        return 0; // Handle division by zero case
    }

    int average = sum / div;
    return average;
}

bool checkDate(map<string,int> done) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    bool marked = false;

    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    string monthStr = (month < 10) ? "0" + to_string(month) : to_string(month);
    int year = 1900 + ltm->tm_year;

    for (const auto& entry : done) {
        if ((to_string(day) + "/" + monthStr + '/' + to_string(year))  == entry.first) {
            marked = true;
        }
    }

    return marked;
}

string getYesterdayDate() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    tm yesterday = *ltm;
    yesterday.tm_mday--;

    tm* yesterdayLtm = &yesterday;
    string dateString =
        to_string(yesterdayLtm->tm_mday) + "/" +
        to_string(1 + yesterdayLtm->tm_mon) + "/" +
        to_string(1900 + yesterdayLtm->tm_year);

    return dateString;
}

bool dateComparator(const string& date1, const string& date2) {
    int sortableDate1 = stoi(date1.substr(6, 4) + date1.substr(3, 2) + date1.substr(0, 2));
    int sortableDate2 = stoi(date2.substr(6, 4) + date2.substr(3, 2) + date2.substr(0, 2));

    return sortableDate1 < sortableDate2;
}

void sortMapByDate(map<string, int>& data) {
    vector<pair<string, int>> temp(data.begin(), data.end());
    std::stable_sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return dateComparator(a.first, b.first);
    });
    data.clear();
    for (const auto& pair : temp) {
        data[pair.first] = pair.second;
    }
}

int main() {
    map<string, int> done = {};
    string filename = "coding_university.md";
    const char* gitCommand = "git config user.email";

    bool marked = false;
    bool git = false;
    int count = 0;
    int average = 0;
    int result = system(gitCommand);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    string dayStr = (day < 10) ? "0" + to_string(day) : to_string(day);
    string monthStr = (month < 10) ? "0" + to_string(month) : to_string(month);
    int year = 1900 + ltm->tm_year;

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
        count = countDone;
        done.insert({(dayStr + "/" + monthStr + '/' + to_string(year)), count});
        // done[(to_string(day) + "/" + monthStr + '/' + to_string(year))] = count;
        sortMapByDate(done);
        writeFile(done);
    } else {
        cout << ">>> Already done, for edit, remove date from data.txt" << endl;
    }

    average = averageCalc(done);


    string time = "";

    if (countNotDone / ((int)average * 30) < 2 ) {
        time = (to_string(countNotDone / (int)average) + " days");
    } else {
        time = (to_string(countNotDone / ((int)average * 30)) + " months");
    }


    if( git == true ) {
        gitPush((dayStr + "/" + monthStr + '/' + to_string(year)));
    }

    cout << ">>> You have done: " << countDone <<" and there is: " << countNotDone << " left." << endl;
    cout << ">>> You do average: " << (int)average <<" per day, and in that speed, you will finish in: " << time << "." << endl;
    return 0;
}
