#include <vector>
#include <array>
#include <algorithm>

using namespace std;

array<int, 5> num1 = {1, 2, 3, 4, 5};
array<int, 8> num2 = {2, 1, 2, 3, 2, 4, 2, 5};
array<int, 10> num3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<pair<int, int>> mgp = {{1, 0}, {2, 0}, {3, 0}};
    
    for (size_t i = 0; i < answers.size(); ++i) {
        if (answers[i] == num1[i % num1.size()]) mgp[0].second++;
        if (answers[i] == num2[i % num2.size()]) mgp[1].second++;
        if (answers[i] == num3[i % num3.size()]) mgp[2].second++;
    }
    
    stable_sort(begin(mgp), end(mgp), [](pair<int, int> m1, pair<int, int> m2){
        return m2.second < m1.second;
    });
    
    vector<int> result;
    for (auto m : mgp) {
        if (mgp[0].second == m.second) {
            result.push_back(m.first);
        }
    }
        
    return result;
}