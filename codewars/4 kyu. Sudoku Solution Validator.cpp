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
