#include <string>
#include <numeric>

using namespace std;

string days[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
int numDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    return days[(accumulate(begin(numDays), begin(numDays) + a-1, 0) + b - 1) % 7];
}