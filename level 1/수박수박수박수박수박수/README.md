수박수박수박수박수
-----------------
문제
-----
길이가 n이고, 수박수박수박수....와 같은 패턴을 유지하는 문자열을 리턴하는 함수, solution을 완성하세요. 예를들어 n이 4이면 수박수박을 리턴하고 3이라면 수박수를 리턴하면 됩니다.

SOLUTION
---------
문제 흐름대로 풀이하였다.

```{.cpp}
string solution(int n) {
    string answer = "";
    int count = 0;
    count = n/2;
    for(int i = 0; i<count ; i++)
        answer += "수박";
    if(n%2==1)
        answer += "수";
    return answer;
}
```
비트 연산을 이용하면 코드가 훨씬하다.

```{.cpp}
string solution(int n) {
    string answer = "";

    for(int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";

    return answer;
}
```


