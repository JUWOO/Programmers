문자열 내 p와 y의 개수
----------------------

문제
-----
대문자와 소문자가 섞여있는 문자열 s가 주어집니다. s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 다르면 False를 return 하는 solution를 완성하세요. 'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴합니다. 단, 개수를 비교할 때 대문자와 소문자는 구별하지 않습니다.

예를 들어 s가 pPoooyY면 true를 return하고 Pyy라면 false를 return합니다.

SOLUTION
---------
문제 흐름 그대로 진행하였다. 각 문자열의 위치를 볼 수 있게 for문을 돌리고, 해당 문자가 p, P, y, Y인지 여부를 체크하였다.

```{.cpp}
bool solution(string s)
{
    bool answer = true;
    int yCount = 0;
    int pCount = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='p' || s[i]=='P')
            pCount++;
        else if(s[i]=='y' || s[i]=='Y')
            yCount++;
    }
    
    if(pCount == yCount)
        answer = true;
    else
        answer = false;

    return answer;
}
```
