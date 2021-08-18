124 나라의 숫자
------------------

문제
----
124 나라가 있습니다. 124 나라에서는 10진법이 아닌 다음과 같은 자신들만의 규칙으로 수를 표현합니다.

124 나라에는 자연수만 존재합니다.

124 나라에는 모든 수를 표현할 때 1, 2, 4만 사용합니다.

예를 들어서 124 나라에서 사용하는 숫자는 다음과 같이 변환됩니다.

10진법	124 나라	10진법	124 나라

1	      1	        6	      14

2	      2	        7	      21

3	      4	        8	      22

4	      11	      9	      24

5	      12	      10	     41

자연수 n이 매개변수로 주어질 때, n을 124 나라에서 사용하는 숫자로 바꾼 값을 return 하도록 solution 함수를 완성해 주세요.

제한사항

n은 500,000,000이하의 자연수 입니다.

링크 : <https://programmers.co.kr/learn/courses/30/lessons/12899>


SOLUTION
---------
1. 변수

   answer : 124 규칙에 맞춰 출력하게 될 숫자 string
   
   last : `n`을 3으로 나눈 나머지
   
   num : 진행한 numbers의 합계. 마지막 부분에서 sum과 target 값을 비교해야 한다.
   
   rever() : string을 reverse하는 함수. string에 숫자가 거꾸로 저장되는 관계로 reverse 함수를 만들었다.
   
   
   
2. 알고리즘

   -124나라의 규칙이 적용된 수들을 확인해보면, 결국 3진법의 변형된 형태이다. 따라 10진법을 3진법으로 바꾸는 것에 초점을 두고, 거기에서 추가적인 조건을 달아 구현하였다.
   
   -3진법으로 바꾸었을 때, 0이 속하지 않는 경우는 124나라의 규칙을 적용한 경우와 3진법의 형태와 같다. 따라서 이 경우는 3진법으로 표현한 후 반환하면 된다.
   
   -핵심은 3진법의 수에 0이 포함되었을 경우이다. 3진법으로 표현하였을 때, 예를 들어서 10진법 `18`은 3진법으로 `200`이고 124나라의 규칙을 적용하면 `124'이다.
   
   -3진법에서 `10`은 10진법의 4에 해당하는데, 이것을 그대로 적용해주면 124나라의 규칙에 맞추어 표현할 수 있다. 위의 예시에서, 200의 가장 낮은 자리의 수부터 `10`을 4로 표현하게 되면, 
   `120+10`의 형태이다. 이것에 124나라의 규칙을 적용하면, `12-+4`의 형태로, `124`가 된다.
   
   -이 규칙을 3진법으로 바꾸는 과정(`for()`)에 조건을 달아준다.
   
   -최종적으로 `for()`를 빠져나왔을 때, `answer`의 형태는 실제 정답에서 거꾸로 되어있으므로, `rever()`를 적용한다.
   
   -`rever()`는 모든 string에 대해 보는 것은 효율적이지 못 하기 때문에 절반에 대해서만 확인하도록 구현하였다. 그래서 가장 앞 자리의 숫자와 가장 뒷자리의 숫자를 교환하는 형식이다.


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string rever(string answer) {
    int num = answer.length();
    int temp;
    for(int i=0; i<num/2 ; i++)
    {
        temp = answer[i];
        answer[i] = answer[num-(1+i)];
        answer[num-(1+i)] = temp;
    }
    return answer;
}

string solution(int n) {
    string answer = "";
    int last;
    int num = 0;
    while(n>2)
    {
        last = n%3;
        if(last == 0){
            answer += to_string(4);
            n = (n/3)-1;
        }
        else {
            answer += to_string(last);
            n = n/3;
        }
    }
    if(n!=0)
        answer += to_string(n);
    return rever(answer);
}
