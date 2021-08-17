내적
------------------


문제
----

길이가 같은 두 1차원 정수 배열 a, b가 매개변수로 주어집니다. a와 b의 내적을 return 하도록 solution 함수를 완성해주세요.

이때, a와 b의 내적은 a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] 입니다. (n은 a, b의 길이)



링크 : <https://programmers.co.kr/learn/courses/30/lessons/70128>


SOLUTION
---------
1. 변수

   
   
2. 알고리즘

   -알고리즘이라고 할 것이 딱히 없다.
   
   -푸는데 1분도 안 걸림..
   


CODE
----
```{.cpp}
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
