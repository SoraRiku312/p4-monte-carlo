/*
  Student Name: William Burch
  File Name: TextIO.cpp
  Assignment number: Project 4

  Input and output for the text files
 */

#ifndef PROJECT3_TEXTREADER_HPP
#define PROJECT3_TEXTREADER_HPP
#include <string>
#include <fstream>
#include "Dataset.hpp"
#include "Simulation.hpp"

using namespace std;

class TextIO {

private:
    ifstream inFile;
    ofstream outFile;
    void WriteBadFile(Dataset data);

    void WriteGoodFile(Dataset data);

public:
    TextIO();

    Dataset ReadFile(string fileName);

    void WriteFile(Dataset data);


    void AnalyzeFile(Dataset data);

    Simulation ReadSimFile();
};


#endif //PROJECT3_TEXTREADER_HPP
