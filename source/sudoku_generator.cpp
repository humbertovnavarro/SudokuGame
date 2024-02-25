#include "sudoku_generator.h"

#include <random>
#include <vector>
#include <set>

std::random_device generator;
std::mt19937 rng(generator());

newBoardGenerator::newBoardGenerator(int** newGameBoard, int size, int gridSize)
                :newGameBoard(newGameBoard), size(size), gridSize(gridSize), numberOfAvailableGrids(size * size)
    {
        for(int i = 0; i < size * size; ++i) {
            remainingGridNumbers.insert(i);
        }
        rowValues = new bool*[size];
        colValues = new bool*[size];
        grids = new bool*[size];

        for(int i = 0; i < size; ++i) {
            rowValues[i] = new bool[size]{};
            colValues[i] = new bool[size]{};
            grids[i] = new bool[size]{};
        }
    }

newBoardGenerator::~newBoardGenerator() {
    for(int i = 0; i < size; ++i) {
        delete[] rowValues[i];
        delete[] colValues[i];
        delete[] grids[i];
    }

    delete[] rowValues;
    delete[] colValues;
    delete[] grids;
}

void newBoardGenerator::createCompletedBoard() {
    if (!size) return;

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            rowValues[i][j] = colValues[i][j] = grids[i][j] = false;
        }
    }

    std::vector<int> **dp = new std::vector<int>*[size];
    for(int i = 0; i < size; ++i) {
        dp[i] = new std::vector<int>[size];
    }

    //backtracking algorithm, randomized for sudoku
    getAvailableNumberSet(0, dp[0][0]);

    int totalGridsOneLess = size * size - 1;
    for(int i = 0; i < totalGridsOneLess;) {

        int row = calRowNumber(i);
        int col = calColNumber(i);

        if (dp[row][col].empty()) {
            --i;
            removeValueFromGridSpace(i, newGameBoard[calRowNumber(i)][calColNumber(i)]);
            continue;
        }

        int index = pickRanVal(dp[row][col].size() - 1);
        int value = dp[row][col][index];
        dp[row][col].erase(dp[row][col].begin() + index);

        insertValueIntoGridSpace(i, value);
        ++i;
        
        getAvailableNumberSet(i, dp[calRowNumber(i)][calColNumber(i)]);
    }
    insertValueIntoGridSpace(size * size - 1, 
                dp[size-1][size-1][0]);
    //end of algorithm

    for(int i = 0; i < size; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
}

std::set<int> newBoardGenerator::eraseNumOfSquares(int n) {
    std::vector<int> erasedNumbers;
    std::vector<int> prevValues;
    std::set<int> invalidGrids;

    if (n < 0 || n > size * size) {
        throw CreationValueOutOfBounds("Number of values erased too large, or too small");
    }

    for (int i = 0; i < n; ++i) {
        int index = pickRanVal(remainingGridNumbers.size() - 1);

        auto iterator = remainingGridNumbers.begin();

        std::advance(iterator, index);

        int gridNumber = *iterator;

        int row = calRowNumber(gridNumber);
        int col = calColNumber(gridNumber);

        int prevValue = newGameBoard[row][col];

        erasedNumbers.push_back(gridNumber);
        prevValues.push_back(prevValue);

        //hold value that's removed for pruning for searching other solutions
        int value = removeValueFromGridSpace(gridNumber, prevValue);

        remainingGridNumbers.erase(gridNumber);

        if (!isUniqueSolution(erasedNumbers, gridNumber, value)) {
            insertValueIntoGridSpace(gridNumber, prevValue);
            invalidGrids.insert(gridNumber);
            erasedNumbers.pop_back();
            prevValues.pop_back();
            --i;
        }

        for (int j = 0; j < int(erasedNumbers.size()); ++j) {
            removeValueFromGridSpace(erasedNumbers[j], prevValues[j]);
        }
    }

    remainingGridNumbers.merge(invalidGrids);

    return remainingGridNumbers;
}

bool newBoardGenerator::isUniqueSolution(std::vector<int> &emptyGrids, int erasedGrid, int erasedValue) {
    if (emptyGrids.empty()) return true;

    std::vector<std::vector<int>> dp(emptyGrids.size());

    //solution checking algorithm, altered to continuing going even after a solution is found
    int index = 0;
    int gridNumber = emptyGrids[index];

    //this checks if the checked grid number is the same as the one where we erased the previous value
    //if it is avoid the excluded value as we know that has one solution
    if (erasedGrid == gridNumber) {
        getAvailableNumberSet(gridNumber, dp[0], erasedValue);
    } else {
        getAvailableNumberSet(gridNumber, dp[0]);
    }

    while(!dp[0].empty() || index > 0) {
        //checks if current index is empty
        if (dp[index].empty()) {
            --index;
            gridNumber = emptyGrids[index];
            removeValueFromGridSpace(gridNumber, newGameBoard[calRowNumber(gridNumber)][calColNumber(gridNumber)]);
            continue;
        }

        int value = dp[index][0];
        dp[index].erase(dp[index].begin());

        insertValueIntoGridSpace(gridNumber, value);

        //checks if the current index is out of bounds, which means it's solved
        if (index >= int(dp.size() - 1)) {
            return false;
        }

        ++index;
        gridNumber = emptyGrids[index];
        
        if (erasedGrid == gridNumber) {
            getAvailableNumberSet(gridNumber, dp[index], erasedValue);
        } else {
            getAvailableNumberSet(gridNumber, dp[0]);
        }
    }
    //end of algorithm

    return true;
}

//picks a random number, INCLUDING the number argument given
int newBoardGenerator::pickRanVal(int n) const {
    if (n < 0) return -1;
    if (!n) return 0;

    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, n);

    return distribution(generator);
}

void newBoardGenerator::SValueRemove(int colRowMinimum, int minimum) {
    
}

void newBoardGenerator::insertValueIntoGridSpace(int gridSpace, int value) {
    rowValues[calRowNumber(gridSpace)][value - 1] = true;
    colValues[calColNumber(gridSpace)][value - 1] = true;
    grids[calMacroGridCoor(gridSpace)][value - 1] = true;

    newGameBoard[calRowNumber(gridSpace)][calColNumber(gridSpace)] = value;
}

int newBoardGenerator::removeValueFromGridSpace(int gridSpace, int value)
{
    rowValues[calRowNumber(gridSpace)][value - 1] = false;
    colValues[calColNumber(gridSpace)][value - 1] = false;
    grids[calMacroGridCoor(gridSpace)][value - 1] = false;

    int valueReturn = newGameBoard[calRowNumber(gridSpace)][calColNumber(gridSpace)];
    newGameBoard[calRowNumber(gridSpace)][calColNumber(gridSpace)] = 0;
    return valueReturn;
}

void newBoardGenerator::
    getAvailableNumberSet(int gridSpace, std::vector<int> &target, int excludedVal) const {   
        for (int i = 0; i < size; ++i) {
            if(!rowValues[calRowNumber(gridSpace)][i] &&
               !colValues[calColNumber(gridSpace)][i] &&
               !grids[calMacroGridCoor(gridSpace)][i] &&
                i + 1 != excludedVal) {
                    target.push_back(i + 1);
            }

        }
}

int newBoardGenerator::calRowNumber(int gridSpace) const{
    return (gridSpace / size);
}

int newBoardGenerator::calColNumber(int gridSpace) const{
    return(gridSpace % size);
}

int newBoardGenerator::calMacroGridCoor(int gridSpace) const {
    int gridRow = (gridSpace / size) / (gridSize);
    int gridCol = (gridSpace % size) / (gridSize);

    return (gridRow * gridSize + gridCol);
}

int newBoardGenerator::calGridNumber(int row, int col) const {
    return ((row * size) + col);
}