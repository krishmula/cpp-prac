#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtrack(vector<vector<char>>& board, string word, int row, int col, vector<vector<bool>>& visited, bool& res, string& str) {
    str += board[row][col];
    visited[row][col] = true;
    if (word.compare(str) == 0) {
        res = true;
        return;
    }

    if (word.find(str) == string::npos) {
        str.pop_back();
        visited[row][col] = false;
        return;
    }

    if (res == true) return;

    if (row - 1 >= 0 && visited[row - 1][col] == false) backtrack(board, word, row - 1, col, visited, res, str);
    if (col - 1 >= 0 && visited[row][col - 1] == false) backtrack(board, word, row, col - 1, visited, res, str);
    if (col + 1 < board[0].size() && visited[row][col + 1] == false) backtrack(board, word, row, col + 1, visited, res, str);
    if (row + 1 < board.size() && visited[row + 1][col] == false) backtrack(board, word, row + 1, col, visited, res, str);

}

bool exist(vector<vector<char>>& board, string word) {
    bool res = false;
    string str = "";

    for (int i = 0; i<board.size(); i++) {
        for (int j = 0; j<board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                str.clear();
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                backtrack(board, word, i, j, visited, res, str);
            }
        }
    }
    return res;
}

int main() {
  // string word = "SEE";
  // vector<vector<char>> board = {
  //     {'A', 'B', 'C', 'E'},
  //     {'S', 'F', 'C', 'S'},
  //     {'A', 'D', 'E', 'E'}
  // };

  string word = "abcd";
  vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};



  bool res = exist(board, word);
  cout << res;
}
