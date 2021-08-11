#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int num = numbers.size();
    int front;
    sort(numbers.begin(), numbers.end());
    for(int i=0; i<num; i++)
    {
        front = numbers[i];
        for(int j=i+1; j<num; j++)
            answer.push_back(front+numbers[j]);
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}