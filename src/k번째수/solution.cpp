#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(commands.size());
    
    for (size_t i = 0; i < commands.size(); ++i) {
        vector<int> a(begin(array) + commands[i][0]-1, begin(array) + commands[i][1]);
        sort(begin(a), end(a));
        answer[i] = a[commands[i][2]-1];
    }
    
    return answer;
}