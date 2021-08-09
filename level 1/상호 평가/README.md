상호평가
------------------
대학 교수인 당신은, 
상호평가를 통하여 학생들이 제출한 과제물에 학점을 부여하려고 합니다.

아래는 0번부터 4번까지 번호가 매겨진 5명의 학생들이 자신과 다른 학생의 과제를 평가한 점수표입니다.

No.	0	1	2	3	4

0	100	90	98	88	65

1	50	45	99	85	77

2	47	88	95	80	67

3	61	57	100	80	65

4	24	90	94	75	65

평균	45.5	81.25	97.2	81.6	67.8

학점	F	B	A	B	D

위의 점수표에서, i행 j열의 값은 i번 학생이 평가한 j번 학생의 과제 점수입니다.

0번 학생이 평가한 점수는 0번 행에담긴 [100, 90, 98, 88, 65]입니다.

0번 학생은 자기 자신에게 100점, 1번 학생에게 90점, 2번 학생에게 98점, 3번 학생에게 88점, 4번 학생에게 65점을 부여했습니다.

당신은 각 학생들이 받은 점수의 평균을 구하여, 기준에 따라 학점을 부여하려고 합니다.

만약, 학생들이 자기 자신을 평가한 점수가 유일한 최고점 또는 유일한 최저점이라면 그 점수는 제외하고 평균을 구합니다.

0번 학생이 받은 점수는 0번 열에 담긴 [100, 50, 47, 61, 24]입니다. 자기 자신을 평가한 100점은 자신이 받은 점수 중에서 유일한 최고점이므로, 평균을 구할 때 제외합니다.
0번 학생의 평균 점수는 (50+47+61+24) / 4 = 45.5입니다.

제외할 점수는 제외하고 평균을 구한 후, 아래 기준에 따라 학점을 부여합니다.

평균	학점

90점 이상	A

80점 이상 90점 미만	B

70점 이상 80점 미만	C

50점 이상 70점 미만	D

50점 미만	F

학생들의 점수가 담긴 정수형 2차원 배열 scores가 매개변수로 주어집니다. 
이때, 학생들의 학점을 구하여 하나의 문자열로 만들어서 return 하도록 solution 함수를 완성해주세요.



문제
----

링크 : <https://programmers.co.kr/learn/courses/30/lessons/83201>


SOLUTION
---------
1. 변수

    scores : 주어진 점수표
    
    num : 배열의 크기. 행과 열의 크기가 같은 배열이므로 `scores.size()`로 하나만 구해도 된다.
    
    sum : 각 학생의 점수 총합. 진행하면서 최종적으로는 평균값이 되기도 한다.
    
    big, small : 각 학생의 점수 총합을 구하면서, 해당 점수가 가장 큰 값인지, 가장 작은 값인지 비교하여 구한 변수값.
    
    count_s, count_b : 위에서 구한 `big`와 `small`이 본인이 자신에게 준 점수일 때, 그 점수가 유일한지 유일하지 않은지 체크하기 위한 변수이다.
   
   
   
2. 알고리즘

   -알고리즘이라고 할 것이 딱히 없다. 문제 그대로 2중 배열을 루프문을 통해 확인할 것. 가장 큰 값인지, 가장 작은 값인지를 확인하여 변수에 담아둘 것.
   
   -다만, 코드 자체가 지나치게 직관적이라서 길고 장황한 경황이 있다. 추후에 좋은 코드를 보게 되면 수정할 것.
   
   +'유일한 가장 큰 값' 혹은 '유일한 가장 작은 값'을 본인이 준 경우에만 제외하고 평균을 구하는 것이다. 
   이를 해결하기 위해 `count_b`와 `count_s` 변수를 사용하였다.
   


CODE
----
```{.cpp}
#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int num = scores.size();
    float sum;
    int big, small;
    int count_s = 0, count_b = 0;
    
    for(int i=0 ; i<num ; i++)
    {
        sum = 0;
        big = 0, small = 100;
        count_s = 0, count_b = 0;
        for(int j=0 ; j<num ; j++)
        {
            if(big < scores[j][i]) {
                big = scores[j][i];
                count_b = 0;
            }
            else if(big == scores[j][i])
                count_b++;
            if(small > scores[j][i]) {
                small = scores[j][i];
                count_s = 0;
            }
            else if(small == scores[j][i])
                count_s++;
            
            sum += scores[j][i];
        }
        if(scores[i][i] == small && count_s == 0)
        {
            sum -= scores[i][i];
            sum = sum / (num-1);
        }
        else if(scores[i][i] == big && count_b == 0)
        {
            sum -= scores[i][i];
            sum = sum / (num-1);
        }
        else
            sum = sum / num;
        
        if(sum >= 90)
            answer += 'A';
        else if(sum >= 80 && sum < 90)
            answer += 'B';
        else if(sum >= 70 && sum < 80)
            answer += 'C';
        else if(sum >= 50 && sum < 70)
            answer += 'D';
        else
            answer += 'F';
    }
    return answer;
}
