숫자 문자열과 영단어
---------------------

문제
----
네오와 프로도가 숫자놀이를 하고 있습니다. 네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.

다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.

1478 → "one4seveneight"

234567 → "23four5six7"

10203 → "1zerotwozero3"

이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다. 
s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

참고로 각 숫자에 대응되는 영단어는 다음 표와 같습니다.

숫자	영단어

0	zero

1	one

2	two

3	three

4	four

5	five

6	six

7	seven

8	eight

9	nine

ex.

s : "one4seveneight"

return : 1478

링크 : <https://programmers.co.kr/learn/courses/30/lessons/81301>


SOLUTION
---------
1. 변수

   
   
   
2. 알고리즘

   -string의
   
   -
   


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int num = s.size();
    int i = 0;
    char c;
    string str = "";
    while(i != num)
    {
        c = s[i];
        if('a'<=c && c<='z')
        {
            if(c=='z')
            {
                str += '0';
                i += 4;
            }
            else if(c=='o')
            {
                str += '1';
                i += 3;
            }
            else if(c=='e')
            {
                str += '8';
                i += 5;
            }
            else if(c=='n')
            {
                str += '9';
                i += 4;
            }
            else if(c=='t')
            {
                if(s[i+1]=='w')
                {
                    str += '2';
                    i += 3;
                }
                else
                {
                    str += '3';
                    i += 5;
                }
            }
            else if(c=='f')
            {
                if(s[i+1]=='o')
                {
                    str += '4';
                    i += 4;
                }
                else
                {
                    str += '5';
                    i += 4;
                }
            }
            else if(c=='s')
            {
                if(s[i+1]=='i')
                {
                    str += '6';
                    i += 3;
                }
                else
                {
                    str += '7';
                    i += 5;
                }
            }
        }
        else
        {
            str += c;
            i++;
        }
        
    }
    answer = stoi(str);
    return answer;
}
