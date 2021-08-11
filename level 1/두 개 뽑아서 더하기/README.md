두 개 뽑아서 더하기
------------------

문제
----
정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

제한사항

numbers의 길이는 2 이상 100 이하입니다.

numbers의 모든 수는 0 이상 100 이하입니다.


ex.

numbers : [2,1,3,4,1]

return : [2,3,4,5,6,7]


링크 : <https://programmers.co.kr/learn/courses/30/lessons/68644>


SOLUTION
---------
1. 변수

   number : 받게 되는 숫자 나열
   
   answer : return학 될 vector array
   
   
   
2. 알고리즘

   -직관적으로 접근하였음.
   
   -`sort(q.begin(), q.end())`와 `q.erase(unique(q.begin(), q.end()), q.end())`를 이용하였음.
   


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int num = numbers.size();
    int front;
    sort(numbers.begin(), numbers.end());
    for(int i=0; i<num; i++)
    {
        front = numbers[i];
        for(int j=i+1; j<num; j++)
            answer.push_back(front+numbers[j]);
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}
