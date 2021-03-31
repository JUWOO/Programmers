//다리를 지나는 트럭
//queue 문제
//Time Complexity : O(n)

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int num = 0;
    int sum = 0;
    
    while(1)
    {
        //시간 counting
        answer++;
        //bridge를 다 건널 때, queue에서 트럭을 pop하고,
        //다리 위 총 중량의 무게를 조정한다
        if(q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }
        
        if(sum+truck_weights[num] <= weight)
        {
            //마지막 트럭이 다리 위를 진입했을 경우, 다리 길이를 시간에 더해준 후, break.
            if(num == truck_weights.size()-1)
            {
                answer += bridge_length;
                break;
            }
            //queue에 트럭을 push한 후, 무게 중량을 조정한다.
            q.push(truck_weights[num]);
            sum += truck_weights[num];
            num++;
        }
        else
            q.push(0);

    } 
    return answer;
}