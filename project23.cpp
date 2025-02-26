#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    string fullName, iin, phoneNumber;
    int regionChoice, placeChoice, subjectChoice;

    cout << "Enter your full name: ";
    getline(cin, fullName);
    cout << "Enter your IIN: ";
    cin >> iin;
    cout << "Enter your phone number: ";
    cin >> phoneNumber;

    map<int, string> regions = {
        {1, "Astana"}, {2, "Almaty"}, {3, "Shymkent"}, {4, "Aktobe"}, {5, "Atyrau"},
        {6, "Karaganda"}, {7, "Kyzylorda"}, {8, "Aktau"}, {9, "Semey"}, {10, "Pavlodar"}, {11, "Taraz"}
    };

    cout << "Choose your region:" << endl;
    for (auto &pair : regions) {
        cout << pair.first << ") " << pair.second << endl;
    }
    cin >> regionChoice;

    map<int, vector<string>> locations = {
        {1, {"Astana, Temirbek Zhurganova, 18/2", "Astana, K. Mukhamedkhanova, 37a"}},
        {2, {"Almaty, Al-Farabi Avenue, 71/22"}},
        {3, {"Shymkent, 8th March Street, 22", "Shymkent, D. Kunaev Avenue, 21"}},
        {4, {"Aktobe, Shalkar, A. Zhankeldin, 89A"}},
        {5, {"Atyrau, Syrym Datov Street, 208"}},
        {6, {"Karaganda, Kazakhstan Street, 15a"}},
        {7, {"Kyzylorda, Left Bank, 115 (Bolashak University)"}},
        {8, {"Aktau, Microdistrict 1B, Building 12"}},
        {9, {"Semey, Glinka Street, 73g"}},
        {10, {"Pavlodar, Tolstoy Street, 101A"}},
        {11, {"Taraz, Karasu Microdistrict, 5A"}}
    };

    cout << "Choose your test place:" << endl;
    for (int i = 0; i < locations[regionChoice].size(); i++) {
        cout << i + 1 << ") " << locations[regionChoice][i] << endl;
    }
    cin >> placeChoice;

    string testDate, testTime;
    cout << "Enter test date (YYYY-MM-DD): ";
    cin >> testDate;
    cout << "Enter test time (HH:MM): ";
    cin >> testTime;

    map<int, string> subjects = {
        {1, "Physics-Mathematics"},
        {2, "Chemistry-Biology"},
        {3, "Informatics-Mathematics"},
        {4, "World History-English"},
        {5, "Geography-Mathematics"}
    };

    cout << "Choose a test subject:" << endl;
    for (auto &pair : subjects) {
        cout << pair.first << ") " << pair.second << endl;
    }
    cin >> subjectChoice;

    map<string, vector<string>> testQuestions = {
        {"Physics-Mathematics", {"What is Newton's second law?", "Find the derivative of x^2", "Explain Ohm's law", "Calculate force if mass = 10kg and acceleration = 5m/s^2", "Solve: x^2 - 4 = 0"}},
        {"Chemistry-Biology", {"What is Avogadro's number?", "Define photosynthesis", "What is pH of pure water?", "Explain DNA structure", "What is a chemical reaction?"}},
        {"Informatics-Mathematics", {"What is an algorithm?", "Convert 1010 binary to decimal", "Find the integral of e^x", "Explain recursion", "Solve: 3x - 7 = 2"}},
        {"World History-English", {"Who was the first president of the USA?", "What year did World War II end?", "What is the synonym of 'big'?", "Translate 'hello' into English", "Who wrote 'Romeo and Juliet'?"}},
        {"Geography-Mathematics", {"Name the longest river in the world", "Find the area of a circle", "What is the capital of Canada?", "Solve: 5x + 10 = 25", "Define a tectonic plate"}}
    };

    cout << "\nStarting test for: " << subjects[subjectChoice] << "\n";
    for (const string &question : testQuestions[subjects[subjectChoice]]) {
        cout << "Q: " << question << endl;
        string answer;
        getline(cin >> ws, answer);
    }

    cout << "Test completed!" << endl;
    cout << "Your test details:" << endl;
    cout << "Name: " << fullName << "\nIIN: " << iin << "\nPhone: " << phoneNumber << endl;
    cout << "Region: " << regions[regionChoice] << "\nLocation: " << locations[regionChoice][placeChoice - 1] << endl;
    cout << "Date & Time: " << testDate << " " << testTime << endl;
    cout << "Subject: " << subjects[subjectChoice] << endl;
    return 0;
}
