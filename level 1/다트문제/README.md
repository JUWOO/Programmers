다트 게임
------------------

문제
----
카카오톡 게임별의 하반기 신규 서비스로 다트 게임을 출시하기로 했다. 다트 게임은 다트판에 다트를 세 차례 던져 그 점수의 합계로 실력을 겨루는 게임으로, 모두가 간단히 즐길 수 있다.

갓 입사한 무지는 코딩 실력을 인정받아 게임의 핵심 부분인 점수 계산 로직을 맡게 되었다. 다트 게임의 점수 계산 로직은 아래와 같다.

다트 게임은 총 3번의 기회로 구성된다.

각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.

점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고 각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱 (점수1 , 점수2 , 점수3 )으로 계산된다.

옵션으로 스타상(*) , 아차상(#)이 존재하며 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 아차상(#) 당첨 시 해당 점수는 마이너스된다.

스타상(*)은 첫 번째 기회에서도 나올 수 있다. 이 경우 첫 번째 스타상(*)의 점수만 2배가 된다. (예제 4번 참고)

스타상(*)의 효과는 다른 스타상(*)의 효과와 중첩될 수 있다. 이 경우 중첩된 스타상(*) 점수는 4배가 된다. (예제 4번 참고)

스타상(*)의 효과는 아차상(#)의 효과와 중첩될 수 있다. 이 경우 중첩된 아차상(#)의 점수는 -2배가 된다. (예제 5번 참고)

Single(S), Double(D), Triple(T)은 점수마다 하나씩 존재한다.

스타상(*), 아차상(#)은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다.

0~10의 정수와 문자 S, D, T, *, #로 구성된 문자열이 입력될 시 총점수를 반환하는 함수를 작성하라.

입력 형식

"점수|보너스|[옵션]"으로 이루어진 문자열 3세트.

예) 1S2D*3T

점수는 0에서 10 사이의 정수이다.

보너스는 S, D, T 중 하나이다.

옵선은 *이나 # 중 하나이며, 없을 수도 있다.

출력 형식

3번의 기회에서 얻은 점수 합계에 해당하는 정수값을 출력한다.

예) 37

입출력 예제

예제	dartResult	answer	설명

1	   1S2D*3T	   37	     11 * 2 + 22 * 2 + 33

2	   1D2S#10S	   9	     12 + 21 * (-1) + 101

3	   1D2S0T	     3	     12 + 21 + 03

4	   1S*2T*3S	   23	     11 * 2 * 2 + 23 * 2 + 31

5	   1D#2S*3S	   5	     12 * (-1) * 2 + 21 * 2 + 31

6	   1T2D3D#	   -4	     13 + 22 + 32 * (-1)

7	   1D2S3T*	   59	     12 + 21 * 2 + 33 * 2


링크 : <https://programmers.co.kr/learn/courses/30/lessons/17682#>


SOLUTION
---------
1. 변수

   answer : 최종 적으로 `v`에 저장된 점수를 합산한 변수.
      
   dartResult[] : 입력받는 문자열.
   
   num : 받아온 숫자를 저장한 변수. 별다른 처리를 준 적 없는 변수.
   
   first : 위의 `num`에 영역처리(`pow()`)처리를 한 점수. 이 점수를 배열 `v`에 추가하여 이후에 `v`를 처리하도록 한다.
   
   mul : 위의 `pow()`를 처리할 때, 몇 제곱으로 할지에 관한 변수.
   
   count : 몇 번째 점수인지. 영역을 분석하는 부분에서 `count++`을 추가하였다.
   
   s : 숫자를 받아올 때, `stoi()`를 처리하기 위한 string 변수.
   
   v : vector array. 숫자와 영역처리를 끝낸 점수를 우선적으로 저장해두는 배열. 이후 옵션 과정의 연산을 직접 `v`에 추가한다.
   
2. 알고리즘

   -받아오는 string은 3개의 영역으로 나뉜다. 총 3개의 점수 영역이며, 옵션 중 `*`은 앞의 점수에 영향을 미치기 때문에, 
   각 점수를 나눠서 저장할 필요가 있었다. 이를 고려하여 vector array인 `v`를 선언하여 점수와 영역 점수를 계산한 값을 각각 저장하였다.
   
   -string `dartResult`를 앞에서부터 차례 받아오며, 각 문자를 분석하였다. 각 루프에서 해당 문자가 숫자인지 영역인지 아니면 옵션인지를 구분한다.
   
   -이때, 하나의 점수 영역에서 숫자와 문자는 무조건 등장하므로, 우선 조건문을 통해 숫자를 받아오고, 그 다음에 문자를 분석하도록 하였다. 이때, 옵션은 문자를 분석하 후에 뒤이어 분석하는 것이 
   점수 계산에 편하므로 문자를 분석하는 조건문 안에 `dartResult[i+1]`의 형태로 분석하도록 하였다. 만약 옵션이 있다면 `i++`를 한 후, 해당 옵션을 배열 `v`에 직접 추가하였다.
   
   -숫자를 받아올 때, 범위 0-10이므로, `1`과 `10`을 고려해야한다.
   
   +`stoi()`는 문자열 전체에 대해서만 가능한 듯 하다. 고려할 것.


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num = 0; //점수
    int first = 0;
    int mul = 0;
    int count = 0;
    vector<int> v;
    for(int i=0 ; i<dartResult.size() ; i++)
    {
        //점수를 num에 받아오기
        if(dartResult[i]=='0')
            num = 0;
        else if('2'<=dartResult[i] && dartResult[i]<='9')
        {
            string s = "";
            s = dartResult[i];
            num = stoi(s);
        }
        else if(dartResult[i]=='1')
        {
            if(dartResult[i+1]!='0')
                num = 1;
            else if(dartResult[i+1]=='0')
            {
                num = 10;
                i++;
            }
        }
        
        if('A'<=dartResult[i] && dartResult[i]<='Z')
        {
            if(dartResult[i]=='S')
                mul = 1;
            else if(dartResult[i]=='D')
                mul = 2;
            else if(dartResult[i]=='T')
                mul = 3;
            first = pow(num, mul);
            v.push_back(first);
            
            
            if(dartResult[i+1] == '*')
            {
                if(count == 0)
                    v[count] *= 2;
                else
                {
                    v[count-1] *= 2;
                    v[count] *= 2;
                }
                i++;
            }
            else if(dartResult[i+1] == '#')
            {
                v[count] *= -1;
                i++;
            }
            count++;
            
        }
    }
    
    for(int i=0 ; i<3 ; i++)
        answer += v[i];
    return answer;
    
}
