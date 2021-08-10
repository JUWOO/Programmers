약수의 개수와 덧셈
------------------

문제
----
두 정수 left와 right가 매개변수로 주어집니다. left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.

링크 : <https://programmers.co.kr/learn/courses/30/lessons/77884>


SOLUTION
---------
1. 변수

   answer : 약수의 개수 따라 해당 값을 더하거나 뺀 결과값.
   
   count : 약수의 개수.
   
   left, right : 입력되는 값.
   
   
   
2. 알고리즘

   -`left`에서 `right`까지를 확인하다.
   
   -각 숫자에 대해 1부터 본인까지 차례로 나누어 나머지가 0이 되는 경우를 체크한다. 이를 통해 약수으 개수를 구할 수 있다.
   


CODE
----
```{.cpp}
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int count;
    for(int i=left; i<=right; i++)
    {
        count = 0;
        for(int j=1; j<=i; j++)
            if(i%j == 0)
                count++;
        if(count%2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}
