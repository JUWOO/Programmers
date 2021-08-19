#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    int mul =1;
    while(n > 2)
    {
        v.push_back(n%3);
        n = n/3;
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    
    int num = v.size();
    for(int i=0; i<num; i++)
    {
        answer += v[i]*mul;
        mul *= 3;
    }
    return answer;
}