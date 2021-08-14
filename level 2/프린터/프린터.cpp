#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int num = priorities.size();
    queue<int> check;
    vector<int> check2;
    int juwoo[num];
    int temp;
    int count = 0;
    for(int i=0; i<num; i++)
    {
        check.push(priorities[i]);
        check2.push_back(priorities[i]);
    }
    sort(priorities.begin(), priorities.end());
    for(int j=0; j<num; j++)
    {
        count = 0;
        for(int i=0; i<num; i++)
            if(priorities[j]==check2[i])
            {
                check2[i] = 0;
                count = i;
                break;
            }
        while(priorities[j]!=check.front())
        {
            temp = check.front();
            check.pop();
            check.push(temp);
        }
        juwoo[count] = j+1;
        check.pop();
    }
    answer = juwoo[location];
    return answer;
}

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer;                         //queue에 index 삽입.
    vector<int> sorted;                         //정렬된 결과 저장용
    for(int i=0; i<priorities.size(); i++) {
        printer.push(i);
    }
    while(!printer.empty()) {
        int now_index = printer.front();
        printer.pop();
        if(priorities[now_index] != *max_element(priorities.begin(),priorities.end())) {
            //아닌경우 push
            printer.push(now_index);
        } else {
            //맞는경우
            sorted.push_back(now_index);
            priorities[now_index] = 0;
        }
    }
    for(int i=0; i<sorted.size(); i++) {
        if(sorted[i] == location) return i+1;
    }
}
