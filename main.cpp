#include <iostream>
#include <vector>
#include "Dataset.hpp"
#include "TextIO.hpp"
using namespace std;

int main() {

    string file1 = "t1.txt";
    string file2 = "t2.txt";
    string file3 = "t3.txt";
    string file4 = "t4.txt";
    TextIO reader;
    Dataset d1 = reader.ReadFile(file1);
    Dataset d2 = reader.ReadFile(file2);
    Dataset d3 = reader.ReadFile(file3);
    Dataset d4 = reader.ReadFile(file4);
    vector<Dataset> datasets = {d1, d2, d3, d4};
    for(unsigned int i = 0; i < datasets.size(); i++)
    {
        cout << "Simulation " << i+1 << ": " << endl;
        cout << "\tNumber of batches of items: " << datasets.at(i).getNumOfBatches() << endl;
        cout << "\tNumber of items in each batch: " << datasets.at(i).getNumOfItemsInBatches() << endl;
        cout << "\tPercentage of batches containing bad items: " << datasets.at(i).getPercentageOfBadBatches() << "%" << endl;
        cout << "\tPercentage of items that are bad in a bad set: " << datasets.at(i).getPercentageOfBadItems()  << "%" << endl;
        cout << "\tItems sampled from each set: " << datasets.at(i).getItemsSampled() << endl;
        cout << endl << "Generating data sets:\n\n";
        reader.WriteFile(datasets.at(i));
        reader.AnalyzeFile(datasets.at(i));
        cout << endl;
    }

    Simulation sim = reader.ReadSimFile();
    double analyticalValue = sim.calculateAnalyticalModel();
    double simulatedValue = sim.simulate();
    string expectedValueString;
    string simulatedValueString;
    cout << "Simulated days: " << sim.getDays() << endl;
    cout << "Number of categories: " << sim.getNumOfCategories() << endl;
    cout << "Ranges and occurrences in each range: " << endl;
    for(int i = 0; i < sim.getNumOfCategories(); i++) {
        SimRange range(sim.getRanges().at(i));
        cout << range.getStartRange() << "-" << range.getEndRange() << ": " << range.getPercentage() << endl;
        if (sim.getRanges().at(i).isInRange(analyticalValue)) {
            expectedValueString = "Expected value is in the " + to_string(range.getStartRange()) + "-" +
                                  to_string(range.getEndRange()) + sim.getUnits() + " range.";
        }
        if (sim.getRanges().at(i).isInRange(simulatedValue)) {
            simulatedValueString = "Expected value is in the " + to_string(range.getStartRange()) + "-" +
                                   to_string(range.getEndRange()) + sim.getUnits() + " range.";
        }
    }
    cout << "Units of measure: " << sim.getUnits() << endl;

    cout << "Analytical model: " << analyticalValue <<". " << expectedValueString << endl;

    cout << "Simulation: " << simulatedValue << "." << simulatedValueString << endl;

    return 0;
}
