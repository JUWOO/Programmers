모의고사
---------
문제
----
수포자는 수학을 포기한 사람의 준말입니다. 
수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 
수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...

2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...

3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 
가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

link : <https://programmers.co.kr/learn/courses/30/lessons/42840>

SOLUTION
---------

* 패턴을 각각의 배열에 넣고, `answers[]`의 0번째부터 마지막 값까지 한 번 씩 for문을 돌릴 때마다 각 배열의 숫자와 비교하도록 하였다.
* 배열의 숫자를 구하기 위해 `a mod b`를 이용하였다.
* 대소 비교 시에 for문으로 MAX 값을 찾은 후, 다시 한 번 더 반복문을 통해 MAX 값에 해당하는 학생의 번호를 찾았다.


```{.cpp}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[5] = {1,2,3,4,5};
    int two[8] = {2,1,2,3,2,4,2,5};
    int three[10] = {3,3,1,1,2,2,4,4,5,5};
    int MAX =0;
    int a=0, b=0, c=0;
    vector<int> count(3);
    
    for(int i=0 ; i<answers.size() ; i++)
    {
        a = i%5;
        b = i%8;
        c = i%10;
        if(answers[i]==one[a])  count[0]++;
        if(answers[i]==two[b])  count[1]++;
        if(answers[i]==three[c])  count[2]++;
    }
    for(int k=0 ; k<3 ; k++)
        if(MAX < count[k]) MAX = count[k];

    for(int j=0 ; j<3 ; j++)
        if(count[j]==MAX) answer.push_back(j+1);
  
    return answer;
}
```

처음 코드

처음에는 대소 비교를 if문을 통해 9가지 조건을 나열하였다. 그러나 해당 방식은 코드 작성이 번거로우며 직관적이지도 않다.

```{.cpp}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[5] = {1,2,3,4,5};
    int two[8] = {2,1,2,3,2,4,2,5};
    int three[10] = {3,3,1,1,2,2,4,4,5,5};
    int a=0, b=0, c=0;
    int count_a=0, count_b=0, count_c=0;
    
    for(int i=0 ; i<answers.size() ; i++)
    {
        a = i%5;
        b = i%8;
        c = i%10;
        if(answers[i]==one[a])
            count_a++;
        if(answers[i]==two[b])
            count_b++;
        if(answers[i]==three[c])
            count_c++;
    }
    if(count_a > count_c)
        if(count_a == count_b)
        {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(count_a < count_b)
            answer.push_back(2);
        else
            answer.push_back(1);
    else if(count_a < count_c)
        if(count_c == count_b)
        {
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(count_c < count_b)
            answer.push_back(2);
        else
            answer.push_back(3);
    else if(count_a == count_c)
        if(count_c == count_b)
        {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(count_c < count_b)
            answer.push_back(2);
        else
        {
            answer.push_back(1);
            answer.push_back(3);
        }

    return answer;
}
```
