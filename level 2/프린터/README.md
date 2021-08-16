프린터
------------------

문제
----
일반적인 프린터는 인쇄 요청이 들어온 순서대로 인쇄합니다. 그렇기 때문에 중요한 문서가 나중에 인쇄될 수 있습니다. 
이런 문제를 보완하기 위해 중요도가 높은 문서를 먼저 인쇄하는 프린터를 개발했습니다. 이 새롭게 개발한 프린터는 아래와 같은 방식으로 인쇄 작업을 수행합니다.

1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
3. 그렇지 않으면 J를 인쇄합니다.
4. 
예를 들어, 4개의 문서(A, B, C, D)가 순서대로 인쇄 대기목록에 있고 중요도가 2 1 3 2 라면 C D A B 순으로 인쇄하게 됩니다.

내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 알고 싶습니다. 위의 예에서 C는 1번째로, A는 3번째로 인쇄됩니다.

현재 대기목록에 있는 문서의 중요도가 순서대로 담긴 배열 priorities와 
내가 인쇄를 요청한 문서가 현재 대기목록의 어떤 위치에 있는지를 알려주는 location이 매개변수로 주어질 때, 
내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 return 하도록 solution 함수를 작성해주세요.

ex.

priorities : [2, 1, 3, 2]

location : 2

return : 1

링크 : <https://programmers.co.kr/learn/courses/30/lessons/42587>


SOLUTION
---------
1. 변수

   priorities : 각 문서의 우선순위가 담겨있는 배열. 이때, 각 문서는 이 `priorities`의 index(=location)으로 결정된다.
   
   location : 몇 번째 문서인지에 대한 변수. 최후에 return 할 때에는 
   
   printer : `priorites`의 index값. queue의 형태이며, index값의 앞뒤 조정을 통해 순서를 조정할 것이다.
   
   sorted : 배열의 index 이다. location 값으로 볼 수 있으며, 이때 `sorted`에 차례로 들어간 순서대로 출력될 것이다. 
   즉, 위의 예시의 경우 sorted : [2, 3, 0, 1]이고, 이때 0번째에 해당하는 것이 가장 먼저 출력되며, 이때 가장 먼저 출력되는 것의 location은 2이다. 이때, 2의 자리에 있는 것은 priorities의 3이다.
   
   
   
   
2. 알고리즘

   -`priorities`를 처음부터 보되, 만약 해당하지 않는 값이 경우 있는 그대로 뒤로 넣어줘야 한다. 이때, queue가 사용된다.
   
   -`priorities`를 직접 큐로 넣어 작동하는 경우 index와의 관계나, `priorities` 내의 최대값을 찾는 것에 문제가 발생할 수 있다. 
   이를 해결하기 위해서, `priorities`의 `index`에 해당하는 queue를 선언하여, index의 값을 `pop()`하고 `push()`하도록 하여야 한다.
   
   -`priorities`에서 가장 큰 값을 찾는데에는 `max_element()`를 사용한다. (<https://0xlordfo.tistory.com/27>)
   
   -만약 가장 큰 값에 해당하는 index의 상황에 도달하면, 해당 index를 `sorted` 배열에 추가하고, `priorities`의 값은 `0`으로 초기화한다.
   
   

CODE
----
```{.cpp}

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer;
    vector<int> sorted;
    for(int i=0; i<priorities.size(); i++)
        printer.push(i);
    while(!printer.empty())
    {
        int now_index = printer.front();
        printer.pop();
        if(priorities[now_index] != *max_element(priorities.begin(),priorities.end()))
            printer.push(now_index);
        else
        {
            sorted.push_back(now_index);
            priorities[now_index] = 0;
        }
    }
    for(int i=0; i<sorted.size(); i++)
        if(sorted[i] == location)
            return i+1;
}
