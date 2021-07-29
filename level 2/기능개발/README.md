기능개발
------------------

문제
----
프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 
각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.

또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고,
이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.

먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 
각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 때 
각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.

ex.

progresses : [93, 30, 55]

speeds : [1, 30, 5]

return : [2, 1]

링크 : <https://programmers.co.kr/learn/courses/30/lessons/42586?language=cpp>


SOLUTION
---------
1. 변수

   progresses와 speeds : 지금까지 진행한 작업량과 그 작업량을 하는데 걸리는 속도
   
   day : `progresses`와 `speeds`를 통해 앞으로 남은 작업을 끝내기 위해 필요한 총 일 수. queue 형태의 배열.
   
   now : `day`의 가장 앞에 있는 항목(`day.front()`). 현재 날짜에 배포할 가장 앞선 작업. 이 작업보다 뒤에 있는 것 중에서 작업이 끝난 것을 함께 배포할 예정. 
   now와 함께 배포가 될 때마다 pop(`day.pop()`)을 통해 queue에서 나가도록 한다.
   
   count : now의 작업과 함께 배포될 작업들의 숫자.
   
   
   
2. 알고리즘

   -`progresses`와 `speeds` array를 통해 각 작업 당 남은 일수를 정리해야 한다.
   
   -앞선 작업보다 뒤의 작업이 먼저 끝났을 경우, 앞선 작업이 배포될 때 함께 배포되어야 한다. 즉, 앞선 것이 먼저 나가는 상황. 따라서 해당 배열 `day`는 queue로 선언한다.
   
   -위의 내용을 작성한다.
   
   +그러나 위와 같은 방식을 구현할 경우 2중 loop를 사용하게 된다. 시간 복잡도가 O(n^2)으로 좋지 못하다. 해결할 방법을 고민할 필요가 있다.


CODE
----
```{.cpp}
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
