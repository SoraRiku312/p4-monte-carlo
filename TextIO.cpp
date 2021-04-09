/*
  Student Name: William Burch
  File Name: TextIO.cpp
  Assignment number: Project 4

  Input and output for the text files
 */

#include <sstream>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <math.h>

#include "TextIO.hpp"

/*  TextIO::TextIO()
 *  creates the textreader object
 */
TextIO::TextIO() = default;

/*  TextIO::ReadFile()
 *  reads the text file provided and makes a dataset object
 *  Parameters:
 *  string fileName - the name of the file
 *  Returns Dataset - the dataset made with the file values
 */
Dataset TextIO::ReadFile(string fileName) {

    int numOfBatches = 0;
    int numOfItemsInBatches = 0;
    int percentageOfBadBatches = 0;
    int percentageOfBadItems = 0;
    int itemsSampled = 0;
    inFile.open(fileName, ifstream::in);
    string line;

    for(int i = 0; i < 5; i++)
    {
        getline(inFile, line);
        stringstream ss(line);
        switch (i) {
            case 0:
                ss >> numOfBatches;
                break;
            case 1:
                ss >> numOfItemsInBatches;
                break;
            case 2:
                ss >> percentageOfBadBatches;
                break;
            case 3:
                ss >> percentageOfBadItems;
                break;
            case 4:
                ss >> itemsSampled;
                break;
            default:
                break;
        }
    }
    Dataset dataset(numOfBatches, numOfItemsInBatches, percentageOfBadBatches, percentageOfBadItems, itemsSampled);
    inFile.close();
    return dataset;

}
/*  TextIO::ReadSimFile()
 *  reads the readings.txt file  and makes a simulation object
 *  Returns Simulation - the simulation made with the file values
 */
Simulation TextIO::ReadSimFile()
{
    int days;
    int numOfCategories;
    vector<SimRange> ranges;
    string units;
    string startRange;
    string endRange;
    string percentage;
    inFile.open("readings.txt", ifstream::in);
    string line;
    for(int i = 0; i < 2; i++)
    {
        getline(inFile, line);
        stringstream ss(line);
        switch(i){
            case 0:
                ss >> days;
                break;
            case 1:
                ss >> numOfCategories;
                break;
            default:
                break;
        }
    }
    for(int i = 0; i < numOfCategories; i++) {
        getline(inFile, line);
        stringstream ss(line);
        getline(ss, startRange, '-');
        getline(ss, endRange, ':');
        getline(ss, percentage);
        SimRange range(stoi(startRange), stoi(endRange), stoi(percentage));
        ranges.push_back(range);
    }
    getline(inFile, line);
    stringstream ss(line);
    ss >> units;
    inFile.close();

    Simulation sim(days, numOfCategories, ranges, units);
    return sim;

}

/*  TextIO::WriteFile()
 *  writes a dataset object to a file with random good or bad items
 *  Parameters:
 *  Dataset data - the dataset to make files from
 */
void TextIO::WriteFile(Dataset data)
{
    bool goodFile;
    int currentBadBatches = 0;
    int totalNumOfBadBatches = data.getTotalNumOfBadBatches();
    int badBatchInterval = data.getNumOfBatches() / totalNumOfBadBatches;
    for(int i = 0; i < data.getNumOfBatches(); i++)
    {
        goodFile = true;
        outFile.open("ds" + to_string(i+1) + ".txt");

        if(outFile.is_open())
        {
            if(currentBadBatches < totalNumOfBadBatches)
            {
                if(i % badBatchInterval == 0)
                {
                    cout << "Create bad set batch # " << i;
                    WriteBadFile(data);
                    cout << " total = " << data.getNumOfItemsInBatches() << " badpct = " << data.getPercentageOfBadItems() << endl;
                    currentBadBatches++;
                    goodFile = false;
                }
            }
            if(goodFile)
            {
                WriteGoodFile(data);
            }

        }
        outFile.close();
    }
    cout << "Total bad sets = " << totalNumOfBadBatches << endl;
}
/*  TextIO::WriteBadFile()
 *  writes the batch with bad items interspersed
 *  Parameters:
 *  Dataset data - the dataset to make files from
 */
void TextIO::WriteBadFile(Dataset data)
{
    int randInt;
    int numOfBadItems = 0;
    for(int i = 0; i < data.getNumOfItemsInBatches(); i++)
    {
        randInt = rand() % 100;
        if(randInt < data.getPercentageOfBadItems())
        {
            outFile << "b" << endl;
            numOfBadItems++;
        }else{
            outFile << "g" << endl;
        }
    }
    cout << ", totBad = " << numOfBadItems;

}
/*  TextIO::WriteBadFile()
 *  writes the batch with only good items
 *  Parameters:
 *  Dataset data - the dataset to make files from
 */
void TextIO::WriteGoodFile(Dataset data)
{

    for(int i = 0; i < data.getNumOfItemsInBatches(); i++)
    {
        outFile << "g" << endl;
    }

}
/*  TextIO::AnalyzeFile()
 *  analyzes each batch file to determine if good or bad
 *  Parameters:
 *  Dataset data - the dataset to make files from
 */
void TextIO::AnalyzeFile(Dataset data)
{
    vector<int> sample;
    vector<string> values;
    string nextValue;
    string value;
    int numOfBadBatchesDetected = 0;
    cout << "\nAnalyzing Data Sets: " << endl;
    for(int i = 0; i < data.getNumOfBatches(); i++)
    {

        inFile.open("ds" + to_string(i+1) + ".txt", ifstream::in);
        if(inFile.is_open())
        {
            for(int j = 0; j < data.getNumOfItemsInBatches(); j++) {
                sample.push_back(j);
                getline(inFile, nextValue);
                values.push_back(nextValue);
            }
            shuffle(sample.begin(), sample.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
            for(int j = 0; j < data.getItemsSampled(); j++)
            {
               value = values.at(sample.at(j));
               if(value == "b")
               {
                   cout << "batch #" << i << " is bad" << endl;
                   numOfBadBatchesDetected++;
                   break;
               }
            }

        }
        inFile.close();
        values.clear();
        sample.clear();

    }
    cout << "\nBase = " << (100 - data.getPercentageOfBadItems())/100.0 << " exponent " << data.getItemsSampled() << endl;
    cout << "P(failure to detect bad batch) = " << pow((100-data.getPercentageOfBadItems())/100.0, data.getItemsSampled()) << endl;
    cout << "Percentage of bad batches actually detected = " << (static_cast<double>(numOfBadBatchesDetected) / data.getTotalNumOfBadBatches())*100.0 << "%" << endl;

}

