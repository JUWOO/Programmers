H-index
------------------

문제
----
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 
어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 
위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 
이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

ex.

citations : [3, 0, 6, 1, 5]

return : 3

링크 : <https://programmers.co.kr/learn/courses/30/lessons/42747>


SOLUTION
---------
1. 변수

   citations : 각 논문이 인용된 횟수. sort를 해서 보는 편이 좋다.
   
   now : 가장 앞에서부터 현재 보려는 논문의 인용횟수.
   
   count : `now`의 논문을 포함해, `now`보다 인용횟수가 많거나 같은 논문의 수
   
   
   
2. 알고리즘

   -`citations`를 sort해서 보는 게 편하다.
   
   -sort되어 있기 때문에, 현재 인용된 횟수(`citations[i]`)와 그 뒤로 남은 논문의 수(`count`)를 비교하면 된다.
   


CODE
----
```{.cpp}
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
