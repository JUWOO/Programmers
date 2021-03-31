다리를 지나는 트럭
------------------

문제
----
트럭 여러 대가 강을 가로지르는 일 차선 다리를 정해진 순으로 건너려 합니다.
모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 
트럭은 1초에 1만큼 움직이며, 다리 길이는 bridge_length이고 다리는 무게 weight까지 견딥니다.

solution 함수의 매개변수로 다리 길이 bridge_length, 다리가 견딜 수 있는 무게 weight, 트럭별 무게 truck_weights가 주어집니다.
이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 solution 함수를 완성하세요.

링크 : <https://programmers.co.kr/learn/courses/30/lessons/42583?language=cpp>


SOLUTION
---------
1. 변수

   answer : 시간 카운트
   
   q : 다리 위의 트럭을 나타내는, queue
   
   num : 트럭의 index
   
   sum : 다리 위 총 트럭의 중량
   
2. 알고리즘

   -종결까지 계속해서 시간을 count 해야하므로, 무한 루프를 돌린다. 한 번 루프를 돌 때마다 시간은 1씩 count되어야 한다.
   
   -다리에 트럭이 진입할 때(q.push()), 큐에는 해당 트럭이 들어가야하며, 동시에 총 무게도 조정해야한다. 또한, 트럭이 다리를 빠져나올 때, pop()과 총 무게도 새로 조정해야한다.
   
   -다리에 다른 트럭이 진입하지 않을 때에도, 트럭이 매 초마다 진행하고 있다는 의미로 push(0)을 해주는 게 포인트.
   
   -각 트럭이 다리를 지나는데 걸리는 총 시간은 bridge_length와 같다.


CODE
----
```{.cpp}
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
```

