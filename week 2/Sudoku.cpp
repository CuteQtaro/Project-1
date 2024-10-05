#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board(9, vector<int>(9)); // 9x9 board
vector<vector<bool>> checkRow(9, vector<bool>(9,true)); 
vector<vector<bool>> checkCol(9, vector<bool>(9,true)); 
vector<vector<bool>> checkBox(9, vector<bool>(9,true)); 

int counts = 0; // number of solutions

bool checking(int row, int col, int num){
    num--; // convert to 0-based index to match the index of vectors
    return checkRow[row][num] && checkCol[col][num] && checkBox[row/3*3+col/3][num]; 
    // check if number num is in row, column and box
}

// add number num to cell (row, col) and update checkRow, checkCol, checkBox
void addNumber(int row, int col, int num){
    
    board[row][col] = num;
    num--; // convert to 0-based index to match the index of vectors
    checkRow[row][num] = false;
    checkCol[col][num] = false;
    checkBox[row/3*3+col/3][num] = false;
}

// remove number num from cell (row, col) and update checkRow, checkCol, checkBox
void removeNumber(int row, int col, int num){
    board[row][col] = 0;
    num--; // convert to 0-based index to match the index of vectors
    checkRow[row][num] = true;
    checkCol[col][num] = true;
    checkBox[row/3*3+col/3][num] = true;
}

int countSol(int k){
    if (k == 81){ // if all cells are filled
        counts++;
        return 0;
    }
    int row = k/9; // row index of cell k
    int col = k%9; // column index of cell k
    if (board[row][col] != 0){ // if cell (row, col) is already filled
        return countSol(k+1);}
    for (int num = 1; num <= 9; num++){
        if (checking(row, col, num)){
            addNumber(row, col, num);
            countSol(k+1);
            removeNumber(row, col, num);
        }
    }
    return counts;
}

int main(){
    int temp;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> temp;
            if (temp != 0){
                addNumber(i, j, temp);
            }
        }
    }
    cout<<countSol(0);
    return 0;
}