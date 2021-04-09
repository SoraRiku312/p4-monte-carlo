/*
  Student Name: William Burch
  File Name: Dataset.hpp
  Assignment number: Project 4

  the dataset object
 */

#ifndef PROJECT4_DATASET_HPP
#define PROJECT4_DATASET_HPP


class Dataset {

private:
    int numOfBatches;
    int numOfItemsInBatches;
    int percentageOfBadBatches;
    int percentageOfBadItems;
    int itemsSampled;

    int totalNumOfBadBatches;



public:
    Dataset(int numOfBatches, int numOfItemsInBatches, int percentageOfBadBatches,
            int percentageOfBadItems, int itemsSampled);

    int getNumOfBatches() const;

    int getNumOfItemsInBatches() const;

    int getPercentageOfBadBatches() const;

    int getPercentageOfBadItems() const;

    int getItemsSampled() const;

    int getTotalNumOfBadBatches() const;

    void setTotalNumOfBadBatches(int totalNumOfBadBatches);

};


#endif //PROJECT4_DATASET_HPP
