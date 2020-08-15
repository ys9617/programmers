#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> bin;
    
    for (auto move : moves) {
        for (size_t col = 0; col < board.size(); ++col) {
            if (board[col][move-1] != 0) {
                if (!bin.empty() && bin.back() == board[col][move-1]) {
                    bin.pop_back();
                    answer+=2;
                }
                else {
                    bin.push_back(board[col][move-1]);
                }
                
                board[col][move-1] = 0;
                break;
            }
        }
    }
    
    return answer;
}