/*
 * Sudoku Background
 * Sudoku is a game played on a 9x9 grid. The goal of the game is to fill all cells of the grid with
 * digits from 1 to 9, so that each column, each row, and each of the nine 3x3 sub-grids (also known
 * as blocks) contain all of the digits from 1 to 9.
 *
 * Sudoku Solution Validator
 * Write a function validSolution/ValidateSolution/valid_solution() that accepts a 2D array representing
 * a Sudoku board, and returns true if it is a valid solution, or false otherwise. The cells of the sudoku
 * board may also contain 0's, which will represent empty cells. Boards containing one or more zeroes are
 * considered to be invalid solutions.
 * The board is always 9 cells by 9 cells, and every cell only contains integers from 0 to 9.
 *
 * Examples
 * validSolution([
 *   [5, 3, 4, 6, 7, 8, 9, 1, 2],
 *   [6, 7, 2, 1, 9, 5, 3, 4, 8],
 *   [1, 9, 8, 3, 4, 2, 5, 6, 7],
 *   [8, 5, 9, 7, 6, 1, 4, 2, 3],
 *   [4, 2, 6, 8, 5, 3, 7, 9, 1],
 *   [7, 1, 3, 9, 2, 4, 8, 5, 6],
 *   [9, 6, 1, 5, 3, 7, 2, 8, 4],
 *   [2, 8, 7, 4, 1, 9, 6, 3, 5],
 *   [3, 4, 5, 2, 8, 6, 1, 7, 9]
 * ]); // => true
 * validSolution([
 *   [5, 3, 4, 6, 7, 8, 9, 1, 2], 
 *   [6, 7, 2, 1, 9, 0, 3, 4, 8],
 *   [1, 0, 0, 3, 4, 2, 5, 6, 0],
 *   [8, 5, 9, 7, 6, 1, 0, 2, 0],
 *   [4, 2, 6, 8, 5, 3, 7, 9, 1],
 *   [7, 1, 3, 9, 2, 4, 8, 5, 6],
 *   [9, 0, 1, 5, 3, 7, 2, 1, 4],
 *   [2, 8, 7, 4, 1, 9, 6, 3, 5],
 *   [3, 0, 0, 4, 8, 1, 1, 7, 9]
 * ]); // => false
 */


// function to check if group of 9 numbers only contains integers from 0 to 9 
bool validGroup(unsigned int group[9]) {

  bool numCheck[9] = {false, false, false, false, false, false, false, false, false};
  bool valid = true;

  for (int i = 0; i <= 8; i++) {
    if (group[i] >= 1 && group[i] <= 9) {
      numCheck[group[i] - 1] = true;
    }
  }

  for (int i = 0; i <= 8; i++) {
    valid = valid && numCheck[i];
  }

  return valid;
}

bool validSolution(unsigned int board[9][9]) {

  bool valid = true;

  // check every row of board (from up to down)
  for (int i = 0; i <= 8; i++) {

    unsigned int row[9];

    // transform row into array
    for (int j = 0; j <= 8; j++) {
      row[j] = board[i][j];
    }

    valid = valid && validGroup(row);
  }

  // check every column of board (from left to right)
  for (int i = 0; i <= 8; i++) {

    unsigned int column[9];

    // transform column into array
    for (int j = 0; j <= 8; j++) {
      column[j] = board[j][i];
    }

    valid = valid && validGroup(column);
  }

  // check every block of board
  for (int i = 0; i <= 6; i += 3) {
    for (int j = 0; j <= 6; j += 3) {

      unsigned int block[9];
      // board[j][i] is upper left number of each block, so it's needed to add every number
      // in square [j][i] — [j + 2][i + 2]

      // transform block into array
      int pos = 0;
      for (int k = 0; k <= 2; k++) {
        for (int l = 0; l <= 2; l++) {
          block[pos] = board[j + l][i + k];
          pos++;
        }
      }

      valid = valid && validGroup(block);
    }
  }
  return valid;
}
