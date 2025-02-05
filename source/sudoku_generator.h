#ifndef SUDOKU_GENERATOR_HPP
#define SUDOKU_GENERATOR_HPP

#include <vector>
#include <set>
#include <string>

class newBoardGenerator {
public:
    newBoardGenerator(int** newGameBoard, int size, int gridSize);

    ~newBoardGenerator();

    void createCompletedBoard();

    //for seperation purposes these functions are made seperately but 
    //ensure that you create a completed board BEFORE you start erasing
    //as these functions assume you've already called the before function
    std::set<int> eraseNumOfSquares(int n, int minimumNumOfRowColVals);

    std::set<int> eraseNumOfSquaresSPattern(int n, int minimumNumOfRowColVals);

    std::set<int> eraseRandNumOfSquares(int n, int minimumNumOfRowColVals);

    void getAvailableNumberSet(int gridSpace,
                                std::vector<int> &target,
                                int excludedVal = -1) const;

    bool isUniqueSolution(std::vector<int> &emptyGrids, std::vector<int> &erasedNumbers, std::vector<int> &prevValues,
                            int erasedGrid, int erasedValue);
private:
    //picks a random number, INCLUDING the number argument given
    int pickRanVal(int n) const;

    void insertValueIntoGridSpace(int gridSpace, int value);

    int removeValueFromGridSpace(int gridSpace, int value);

    int calRowNumber(int gridSpace) const;

    int calColNumber(int gridSpace) const;

    int calMacroGridCoor(int gridSpace) const;

    int calGridNumber(int row, int col) const;

    bool** rowValues;
    bool** colValues;
    bool** grids;
    std::set<int> remainingGridNumbers;

    int** newGameBoard;
    int size;
    int gridSize;
    int numberOfAvailableGrids;
};

class CreationValueOutOfBounds: public std::exception {
public:
    CreationValueOutOfBounds(const std::string &msg = "") {
        message += msg;
    }

    std::string what() {
        return message;
    }
private:
    std::string message = "Generated value out of bounds!: ";
};


#endif