//Matthew Groholski
//CSE Project 13: Singlethreading and multithreading in C++
//Single Thread Version

//NOTE: Use clang++ -std=c++11 main.cpp to compile. 
//Trying to determine why the class constructor for thread does not allow for functions with parameters in other versions.

//TODO: Determine why program won't compile without use of note and fix
//TODO: Make a stricter definition of what consitutes a word
//TODO: Consider different data types (Possibly a linked list?)
//TODO: Create Makefile
//TODO: Create own string header file
//TODO: Create own map header file

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <map>
#include <thread>

using namespace std;

void countWords(char *fileName);

int main(int argc, char *args[]) {
    //Checks amount of inputs
    if (argc != 2) {
        cout << "Incorrect amount of inputs." << endl;
        return 1;
    }

    //Begins clocking time
    clock_t beginTime = clock();
    thread single(countWords, args[1]);

    single.join();
    clock_t totalTime = clock() - beginTime;
    cout << "Total Time : " << (float) totalTime / CLOCKS_PER_SEC << " seconds" << endl;

}



void countWords(char* fileName) {
    map<string, int> words;
    long long totalWordCount = 0;

    //Begins read in file
    string line;
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "File did not open!" << endl;
        return;
    }

    while (getline(file,line)) {
        string word = "";

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                words[word]++;
                word = "";
                totalWordCount++;
                continue;
            }
            if ((tolower(line[i]) >= 'a' && tolower(line[i]) <= 'z') || line[i] == '\'') 
                word += tolower(line[i]);
        }

        words[word]++;
        word = "";
        totalWordCount++;
    }

    cout << "The total word count is : " << totalWordCount << endl;
    return;
}


