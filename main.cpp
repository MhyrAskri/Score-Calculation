#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>

void printHeader();

using namespace std;

void printHeader() {

    cout << setw(15) << left << "Student";
    cout << setw(5) << right << "Score" << endl;
    cout << setw(20) << setfill('-') << "" << endl;
    cout << setfill(' ');

}

void printFooter(double average) {

    cout << setw(20) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << setw(15) << left << "Average Score";
    cout << setw(5) << right << average;

}

void printStudent(const string &student , int score) {

    cout << setprecision(1) << fixed;
    cout << setw(15) << left << student;
    cout << setw(5) << right << score << endl;

}

int processResponse(const string &response , const string &answerKey) {

    int score {0};
    for (size_t i = 0 ; i < answerKey.size() ; i++) {

        if (response.at(i) == answerKey.at(i)) {

            score++;

        }

    }

    return score;

}

int main() {

    ifstream inFile;
    string answerKey;
    string name;
    string response;
    int runningSum {0};
    int totalStudents {0};
    double averageScore {0.0};

    inFile.open("../scores.txt");

    if (!inFile) {

        cerr << "Problem opening file." << endl;
        return 1;

    }

    inFile >> answerKey;

    printHeader();

    while (inFile >> name >> response) {
        ++totalStudents;
        int score = processResponse(response , answerKey);
        runningSum += score;
        printStudent(name , score);
    }

    if (totalStudents != 0) {

        averageScore = static_cast<double> (runningSum) / totalStudents;

    }

    printFooter(averageScore);

    inFile.close();

    cout << endl << endl;
    getch();
    return 0;
}
