#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> vec(n, 1);
    
    for (auto l : lost) vec[l-1]--;
    
    for (auto r : reserve) vec[r-1]++;
    
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == 0) {
            if (i > 0 && vec[i-1] > 1) {
                vec[i-1]--;
                vec[i]++;
                continue;
            }
            
            if (i < vec.size() - 1 && vec[i+1] > 1) {
                vec[i+1]--;
                vec[i]++;
            }
        }
    }
    
    return count_if(begin(vec), end(vec), [](int e){ return e > 0; });
}