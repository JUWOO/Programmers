가운데 글자 가져오기
--------------------
문제
-----
단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

SOLUTION
---------
문제의 흐름을 그대로 쫓아갔다.

string s를 배열로 옮긴 후, if문을 통해 출력하는 방식으로 진행하였다.
string을 array로 변환할 때, `strcpy(array, s.c_str)`을 사용하였다.


```{.cpp}
//time complexity : O(1)
string solution(string s) {
    string answer = "";
    int n = s.length();
    char array[n+1];
    int k = n/2;
    
    strcpy(array, s. c_str());
    
    if(n%2==0)
    {
        answer += array[k-1];
        answer += array[k];
    }
    else
        answer = array[k];
    
    return answer;
}
```

다른 사람의 풀이를 보니 `substr()`을 사용하여 해결한 경우도 있는 것 같다. 이런 경우에 풀이가 좀 더 간단하다.
