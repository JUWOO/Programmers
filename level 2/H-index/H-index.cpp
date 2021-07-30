#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int size = citations.size();
    int now;
    int count;
    sort(citations.begin(), citations.end());
    for(int i=0; i<size; i++)
    {
        now = citations[i];
        count = citations.size() - i;
        if(now == count)
            return now;
        else if(now < count)
            continue;
        else
            return count;
    }
}