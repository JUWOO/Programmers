3진법 뒤집기
------------------

문제
----
자연수 n이 매개변수로 주어집니다. n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.

제한사항

n은 1 이상 100,000,000 이하인 자연수입니다.

ex.

n (10진법)	n (3진법)	앞뒤 반전(3진법)	10진법으로 표현
45	        1200	        0021	       7

링크 : <https://programmers.co.kr/learn/courses/30/lessons/68935#>


SOLUTION
---------
1. 변수

   
   
   
   
2. 알고리즘

   -레벨1인데 꽤 해맸다. 처음에는 srting의 방식으로 접근하였으나, 이렇게 될 경우 stirng의 한 문자에 대해서 어떻게 int로 변형해야하지 몰라 더는 진행할 수 없었다.
   
   -그래서 string을 `stoi`를 이용하여, 정수의 형태로 바꾼 후, 그 값을 10진법의 형태로 바꾸었다. 그러나 이렇게 될 경우 몇 몇 가지의 경우에서 core dump error가 발생하였다.
   
   -string 방식에서 vector<int> array 방식으로 바꾸었고, 같은 알고리즘에서 문제는 쉽게 해결되었다.


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    int mul =1;
    while(n > 2)
    {
        v.push_back(n%3);
        n = n/3;
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    
    int num = v.size();
    for(int i=0; i<num; i++)
    {
        answer += v[i]*mul;
        mul *= 3;
    }
    return answer;
}
