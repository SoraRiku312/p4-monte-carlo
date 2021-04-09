/*
  Student Name: William Burch
  File Name: Dataset.cpp
  Assignment number: Project 4

  the dataset object
 */

#include "Dataset.hpp"


/*  Dataset::Dataset()
 *  creates the dataset object
 *  Parameters:
 *  int numOfBatches - the amount of batches
 *  int numOfItemsInBatches - the amount of items in each batch
 *  int percentageOfBadBatches - the percentage of batches that are bad
 *  int percentageOfBadItems - the amount of items bad in each bad
 *  int itemsSampled - the amount of items sampled
 */
Dataset::Dataset(int numOfBatches, int numOfItemsInBatches, int percentageOfBadBatches, int percentageOfBadItems,
                 int itemsSampled) {
    this->numOfBatches = numOfBatches;
    this->numOfItemsInBatches = numOfItemsInBatches;
    this-> percentageOfBadBatches = percentageOfBadBatches;
    this-> percentageOfBadItems = percentageOfBadItems;
    this->itemsSampled = itemsSampled;
    this->setTotalNumOfBadBatches(getNumOfBatches() * (getPercentageOfBadBatches() / 100.0));

}
/*  Dataset::getNumOfBatches()
 *  gets the amount of batches
 *  Returns int - the amount of batches
 */
int Dataset::getNumOfBatches() const {
    return numOfBatches;
}

/*  Dataset::getNumOfItemsInBatches()
 *  gets the amount of items in each batch
 *  Returns int - the amount of items in each batch
 */
int Dataset::getNumOfItemsInBatches() const {
    return numOfItemsInBatches;
}

/*  Dataset::getPercentageOfBadBatches()
 *  gets the percentage of bad batches
 *  Returns int - the percentage of bad batches
 */
int Dataset::getPercentageOfBadBatches() const {
    return percentageOfBadBatches;
}

/*  Dataset::getPercentageOfBadItems()
 *  gets the percentage of bad items in bad batches
 *  Returns int - the amount of bad items
 */
int Dataset::getPercentageOfBadItems() const {
    return percentageOfBadItems;
}

/*  Dataset::getItemsSampled()
 *  gets the amount of items sampled
 *  Returns int - the amount of items sampled
 */
int Dataset::getItemsSampled() const {
    return itemsSampled;
}

/*  Dataset::getTotalNumOfBadBatches()
 *  gets the amount of bad batches
 *  Returns int - the amount of bad batches
 */
int Dataset::getTotalNumOfBadBatches() const {
    return totalNumOfBadBatches;
}

/*  Dataset::setTotalNumOfBadBatches()
 *  sets the total amount of bad batches
 *  Parameters:
 *  int totalNumOfBadBatches - the total num of bad batches
 */
void Dataset::setTotalNumOfBadBatches(int totalNumOfBadBatches) {
    Dataset::totalNumOfBadBatches = totalNumOfBadBatches;
}

