# School-Projects
// Smit Patel
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > generagteWinningPatterns(int gridSize)
{
    vector<vector<int> > patterns; 
    int i = 0;
    int j = 0;

    // horizontal
    for (i = 0; i < gridSize; i++) {
        vector<int> horizontalPatterns;
        for (j = 0; j < gridSize; j++) {
            horizontalPatterns.push_back(i);
            horizontalPatterns.push_back(j);
        }
        patterns.push_back(horizontalPatterns);
    }

    // vertical
    for (i = 0; i < gridSize; i++) {
        vector<int> verticalPatterns;
        for (j = 0; j < gridSize; j++) {
            verticalPatterns.push_back(j);
            verticalPatterns.push_back(i);
        }
        patterns.push_back(verticalPatterns);
    }

    vector<int> diagnola1Patterns;
    vector<int> diagnola2Patterns;
    for (i = 0; i < gridSize; i++) {

        for (j = 0; j < gridSize; j++) {
            if (j == i) {
                diagnola1Patterns.push_back(j);
                diagnola1Patterns.push_back(i);
            }

            if ((i+j) == (gridSize - 1)) {
                diagnola2Patterns.push_back(i);
                diagnola2Patterns.push_back(j);
            }
        }
    }
    patterns.push_back(diagnola1Patterns);
    patterns.push_back(diagnola2Patterns);

    return patterns;
}

bool hasPlayerWon(vector<vector<int> > patterns, char sign, char* board, int gridSize) {

    bool isWinning = true;
    int patternsLength = patterns.size();
    int i = 0;

    for (i = 0; i < patternsLength; i++) {
        long unsigned int j = 0;
        vector<int> pattern1 = patterns.at(i);
        isWinning = true;

        for (j = 0; j < pattern1.size(); j = j + 2) {
            int firstIndex = pattern1.at(j);
            int secondIndex = pattern1.at(j + 1);
            char valueAtIndex = *((board+firstIndex*gridSize) + secondIndex);

            if (valueAtIndex != sign) {
                isWinning = false;
            }
        }
        if (isWinning == true) break;
    }
    return isWinning;
}

void helper () {
    int grid;
    cin >> grid;

    char board[grid][grid];
    for(int i = 0; i < grid; i++){
        for(int j = 0; j < grid; j++){
            board[i][j] = '-';
            cout << board[i][j];
        }
        cout << endl;
    }

    vector<vector<int> > patterns = generagteWinningPatterns(grid); 

    char sign;
    int index = 0;
    while (cin >> sign) {
       int i = index % width
       int j = index / width 
        board[i][j] = sign;
        bool hasWon = hasPlayerWon(patterns, sign, (char *) board, grid);

        if (hasWon == true) {
            cout << sign << " wins" << endl;
        }
        index++;
    }

    count << "Tie." << endl;
}

int main() {
    int size;
    cout << "Enter game board size: ";
    cin >> size;
    char board[size][size];

    vector<vector<int> > patterns = generagteWinningPatterns(size); 
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = '-';
            cout << board[i][j];
        }
        cout << endl;
    }

    int turn = 0;
    while(turn < (size * size)) {
        int rows, columns;
        cin >> rows;
        cin >> columns;

        if(board[rows][columns] == 'X' || board[rows][columns] == 'O') {
            cout << "Cell is already been taken, please enter another cell. " << endl;
            continue;
        }

        if(rows >= size || rows < 0) {
            cout << "Invalid Cell!" << endl; 
            continue;
        } else if (columns >= size || columns < 0) {
            cout << "Invalid Cell!" << endl;
            continue;
        }

        char currentPlayerSign = turn % 2 == 0 ? 'X' : 'O';
        board[rows][columns] = currentPlayerSign;

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }

        bool hasWon = hasPlayerWon(patterns, currentPlayerSign, (char *) board, size);
        if (hasWon == true) {
            cout << currentPlayerSign << " WON!!!!" << endl;
            break;
        }
        turn ++;
        
        if (turn == (size * size)) {
            cout << "No winner!!" << " Match DRAW!!" << endl;
        }
    }
}
