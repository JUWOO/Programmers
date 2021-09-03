실패율
------------------

문제
----
슈퍼 게임 개발자 오렐리는 큰 고민에 빠졌다. 그녀가 만든 프랜즈 오천성이 대성공을 거뒀지만, 요즘 신규 사용자의 수가 급감한 것이다. 원인은 신규 사용자와 기존 사용자 사이에 스테이지 차이가 너무 큰 것이 문제였다.

이 문제를 어떻게 할까 고민 한 그녀는 동적으로 게임 시간을 늘려서 난이도를 조절하기로 했다. 역시 슈퍼 개발자라 대부분의 로직은 쉽게 구현했지만, 실패율을 구하는 부분에서 위기에 빠지고 말았다. 오렐리를 위해 실패율을 구하는 코드를 완성하라.
실패율은 다음과 같이 정의한다.

스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변수로 주어질 때, 
실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.

제한사항

스테이지의 개수 N은 1 이상 500 이하의 자연수이다.

stages의 길이는 1 이상 200,000 이하이다.

stages에는 1 이상 N + 1 이하의 자연수가 담겨있다.

각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.

단, N + 1 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.

만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.

스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.

입출력 예

N	  stages	                  result

5	  [2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]

4	  [4,4,4,4,4]	              [4,1,2,3]


입출력 예 설명

입출력 예 #1

1번 스테이지에는 총 8명의 사용자가 도전했으며, 이 중 1명의 사용자가 아직 클리어하지 못했다. 따라서 1번 스테이지의 실패율은 다음과 같다.

1 번 스테이지 실패율 : 1/8

2번 스테이지에는 총 7명의 사용자가 도전했으며, 이 중 3명의 사용자가 아직 클리어하지 못했다. 따라서 2번 스테이지의 실패율은 다음과 같다.

2 번 스테이지 실패율 : 3/7

마찬가지로 나머지 스테이지의 실패율은 다음과 같다.

3 번 스테이지 실패율 : 2/4

4번 스테이지 실패율 : 1/2

5번 스테이지 실패율 : 0/1

각 스테이지의 번호를 실패율의 내림차순으로 정렬하면 다음과 같다.

[3,4,2,1,5]


링크 : <https://programmers.co.kr/learn/courses/30/lessons/42889#>


SOLUTION
---------
1. 변수

    answer : 최종적으로 출력할 결과 배열
    
    N : stage의 총 개수
    
    stages : 매개변수로 입력 받는 자료.
    
    num : stages의 size로, 게임을 플레이한 총 유저의 수이다.
    
    vector<pair<float, int>> fail : 실패율과 그 때의 stage를 pair로 갖는 배열이다.
    
    index : `stages`에서 각 스테이징 남아있는(문제를 풀지 못한) 사람의 수를 count한 배열.
   
   
   
   
2. 알고리즘

   -`vector<pair<float, int>>` array를 사용하였다.
   
   -`stages`에서 각 stage에서 멈춘 이용자의 수를 확인하기 위해, `index` array를 추갈 선언한 후, 각 배열의 index에서 이용자 수만큼 더하도록 한다. 
   이후, `index` array를 바탕으로 실패율을 계산할 예정인데, 반복문을 통해 각 stage 마다의 실패율을 계산한다.
   
   -이때, 분모에 해당하는 각 stage의 문제를 풀기로 도전한 사람의 수는 이전 단게에서 다음 단계로 넘어오지 못한 사람의 수를 빼주어야 하므로 `count -= index[i-1]`을 해주어야 한다.
   
   -주의사항은 분자가 `0`일 때, 실패율은 float형 이므로 다른 수로 나눌 때, 0이 아닌 다른 값이 들어갈 수 있다. 따라서, 이를 방지학 위해 실패율이 0인 경우는 확실하게 따로 처리하는 것이 좋다.
    실패율이 `0`이란 의미는 그 stage를 푸는데 성공한 사람이 0명이라는 의미이다.
   
   -이후, `vector<pair<float, int>> fail`에서 첫번째 요소를 바탕으로 sort를 적용하였을 때(`sort(fail.rbegin(), fail.rend())`), 두번째 요소(`fail.second`)가 `answer`에 해당한다.
   
   -그러나 위의 요소를 그대로 `answer`에 넣게 되면, 같은 실패율의 경우 작은 stage부터 입력되는 게 역순으로 이루어지게 된다. 이 부분을 고려해야 한다.


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num = stages.size();
    vector<pair<float, int>> fail;
    vector<int> index;
    int count = num;
    sort(stages.begin(), stages.end());
    
    for(int i=0 ; i<N+2 ; i++)
        index.push_back(0);
    
    for(int i=0; i<num; i++)
        index[stages[i]]++;

    for(int i=1; i<N+1; i++)
    {
        count -= index[i-1];
        if(index[i]==0)
            fail.push_back(pair<float,int>(0,i));
        else
        {
            double failure = (double)index[i]/count;
            fail.push_back(pair<float, int>(failure, i));
        }
    }
    
    sort(fail.rbegin(), fail.rend());
    int c = 0;
    vector<int> a;
    for(int i=0; i<N; i++)
    {
        if(i<N-1 && fail[i].first == fail[i+1].first)
        {
            c++;
            a.push_back(fail[i].second);
        }
        else
            if(c > 0)
            {
                c++;
                a.push_back(fail[i].second);
                while(a.size()!=0)
                {
                    answer.push_back(a.back());
                    a.pop_back();
                }
            }
            else
                answer.push_back(fail[i].second);
    }
    return answer;
}
