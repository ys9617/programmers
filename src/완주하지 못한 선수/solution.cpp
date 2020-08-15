#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hash_table;
    
    for (auto c : completion) {
        auto h = hash_table.find(c);
    
        if (h == end(hash_table)) {
            hash_table.insert(make_pair(c, 1));
        }
        else {
            h->second++;
        }
    }
    
    for (auto p : participant) {
        auto h = hash_table.find(p);
        
        if (h != end(hash_table) && h->second > 0) {
            h->second--;
        }
        else {
            return p;
        }
    }
}