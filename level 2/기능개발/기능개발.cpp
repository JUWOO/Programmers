#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> day;
    int idx = progresses.size();
    int last;
    
    for(int i=0; i<idx ; i++)
    {
        last = 100 - progresses[i];
        if(last % speeds[i] != 0)
            day.push((last/speeds[i])+1);
        else
            day.push(last/speeds[i]);
    }

    while(day.size())
    {
        int i = 0;
        int now = day.front();
        int count = 0;
        day.pop();
        count++;
        while(day.size())
        {
            if(now >= day.front())
            {
                day.pop();
                count++;
            }
            else
                break;
        }
        answer.push_back(count);
        i++;
    }
    return answer;
}