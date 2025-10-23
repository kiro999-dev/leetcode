#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        unordered_map<char, bool> row;
        unordered_map<char, bool> col;
        unordered_map<char, bool> box;
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.' && row.count(board[i][j]))
            {
                cout << "row " << i << " not valid\n";
                return false;
            }
            if (board[j][i] != '.' && col.count(board[j][i]))
            {
                cout << "col " << i << " not valid\n";
                return false;
            }
            int boxRow = 3 * (i / 3) + j / 3; 
            int boxCol = 3 * (i % 3) + j % 3; 
            char val = board[boxRow][boxCol];
            cout<<val<<" ";
            if (val != '.' && box.count(val))
            {
                cout << "box (" << i / 3 << "," << i % 3 << ") not valid\n";
                return false;
            }
            if (board[i][j] != '.')
                row[board[i][j]] = true;
            if (board[j][i] != '.')
                col[board[j][i]] = true;
            if (val != '.')
                box[val] = true;
        }
        cout<<'\n';
    }
    return true;
}


};
int main()
{

    vector<vector<char>> board = {
       {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    Solution a;
    a.isValidSudoku(board);
}
