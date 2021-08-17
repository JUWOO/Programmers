#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int num = a.size();
    for(int i=0; i<num; i++)
        answer += a[i]*b[i];
    return answer;
}