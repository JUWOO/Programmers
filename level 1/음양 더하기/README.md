음양더하기
---------------------

문제
----
어떤 정수들이 있습니다. 이 정수들의 절댓값을 차례대로 담은 정수 배열 absolutes와 이 정수들의 부호를 차례대로 담은 불리언 배열 signs가 매개변수로 주어집니다. 
실제 정수들의 합을 구하여 return 하도록 solution 함수를 완성해주세요.

링크 : <https://programmers.co.kr/learn/courses/30/lessons/81301>


SOLUTION
---------
1. 변수

   
   
   
2. 알고리즘

   -별 것 없음. 그냥 순서대로 받아오기.
   


CODE
----
```{.cpp}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int num = absolutes.size();
    for(int i=0; i<num;i++)
    {
        if(signs[i]==1)
            answer += absolutes[i];
        else
            answer -= absolutes[i];
    }
    return answer;
