//Matthew Groholski
//CSE Project 13: Singlethreading and multithreading in C++
//Multiple Thread Version

//NOTE: Use clang++ -std=c++11 FILENAME.cpp to compile
//NOTE: Program currently only works for the.txt file

//TODO: Create dynamic approach to finding file splits
//TODO: Determine why program won't compile without use of note and fix
//TODO: Make a stricter definition of what consitutes a word
//TODO: Consider different data types (Possibly a linked list?)
//TODO: Create Makefile
//TODO: Create own string header file
//TODO: Create own map header file
//TODO: Implement statistics feature

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <map>
#include <thread>

using namespace std;

map<string, int> words;
int totalWords = 0;

void countWords(int start, int end, string fileName);

int main (int argc, char* args[]) {
    //Checks amount of inputs
    if (argc != 2) {
        cout << "Incorrect amount of inputs." << endl;
        return 1;
    }

    if (strcmp(args[1], "../texts/the.txt") != 0) {
        cout << "Function not supported yet" << endl;
        return 3;
    }

    //Begins clocking time
    clock_t beginTime = clock();

    //Begins threads
    thread read1(countWords, 0, 3, args[1]);
    thread read2(countWords, 4, 7, args[1]);
    thread read3(countWords, 8, 11, args[1]);
    thread read4(countWords, 12, 15, args[1]);

    read1.join();
    read2.join();
    read3.join();
    read4.join();

    cout << "Total Amount of Words: " << totalWords << endl;

    clock_t totalTime = clock() - beginTime;
    cout << "Total Time : " << (float) totalTime / CLOCKS_PER_SEC << " seconds" << endl;
}

void countWords(int start, int end, string fileName) {
    ifstream file(fileName);

    if (!(file.is_open())) {
        cout << "Could not open file!" << endl;
        return;
    }

    int lineCount = (end - start) + 1;
    string line;

    //Skips to start
    while (start-- > 0)
        getline(file, line);

    while (lineCount-- > 0) {
        getline(file, line);
        string word = "";
        for(int i = 0; i < line.length(); i++) {
            if (line[i] == ' ') {
                words[word]++;
                word = "";
                totalWords++;
                continue;
            }
            if ((tolower(line[i]) >= 'a' && tolower(line[i]) <= 'z') || line[i] == '\'') 
                word += tolower(line[i]);
        }
        words[word]++;
        word = "";
        totalWords++;
    }
}
