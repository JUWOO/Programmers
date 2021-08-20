비밀지도
------------------

문제
----

네오는 평소 프로도가 비상금을 숨겨놓는 장소를 알려줄 비밀지도를 손에 넣었다. 
그런데 이 비밀지도는 숫자로 암호화되어 있어 위치를 확인하기 위해서는 암호를 해독해야 한다. 다행히 지도 암호를 해독할 방법을 적어놓은 메모도 함께 발견했다.

지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 "공백"(" ") 또는 "벽"("#") 두 종류로 이루어져 있다.

전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 "지도 1"과 "지도 2"라고 하자. 지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다. 
지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.

"지도 1"과 "지도 2"는 각각 정수 배열로 암호화되어 있다.

암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열이다.

ex.

매개변수	값

n	5

arr1	[9, 20, 28, 18, 11]

arr2	[30, 1, 21, 17, 28]

출력	["#####","# # #", "### #", "# ##", "#####"]

네오가 프로도의 비상금을 손에 넣을 수 있도록, 비밀지도의 암호를 해독하는 작업을 도와줄 프로그램을 작성하라.


링크 : <https://programmers.co.kr/learn/courses/30/lessons/17681>


SOLUTION
---------
1. 변수

   n : 지도의 크기. 2진수로 변경할 때, `n`에 맞춰 빈자리에 `0`을 채워넣어야 한다.
   
   arr1 : 비밀지도1에 해당하는 숫자 배열
   
   arr2 : 비밀지도2에 해당하는 숫자 배열
   
   line : 각 비밀지도 한 줄에 대해 비교하여 완성하게 될 최종 지도 1줄. `string`의 형태이다.
   
   a1 : 비밀지도1의 한 줄에 대해 2진수로 풀어 쓴 배열.
   
   a2 : 비밀지도2의 하 줄에 대해 2진술 풀어 쓴 배열.
   
   
   
   
2. 알고리즘

   -10진법의 수를 2진법을 바꾼 후, 그 2진법에 대해 각 자리수끼리 비교하는 방식을 가야한다.
   
   -2진법을 만드는 함수(`binary_fn`)을 만들었다. 다음 함수에서는 지도의 크기에 해다하는 `n`과 2진법으로 바꿀 수에 해다하는 10진수 `num`을 맥개변수로 받는다. vector array에 2진수의 형태로 수를 채워넣고,
    `n`에 맞춰 0을 넣어줘야 한다. 그 후 `reverse`를 적용한다.
    
   -최종반환 값의 형태가 `vector<string>`의 형태이므로 string의 형탱 맞춰 `#`과 ` (공백)`을 넣어준다.
   


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//10진수를 넣으면 2진수로 출력
vector<int> binary_fn(int num, int n) {
    vector<int> v;
    while(num > 1)
    {
        v.push_back(num%2);
        num /= 2;
    }
    v.push_back(num);
    while(v.size() != n)
        v.push_back(0);
    reverse(v.begin(), v.end());
    return v;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int num = arr1.size();
    for(int i=0; i<num ; i++)
    {
        string line = "";
        vector<int> a1 = binary_fn(arr1[i], n);
        vector<int> a2 = binary_fn(arr2[i], n);
        for(int j=0 ; j<n ; j++)
        {
            if(a1[j] == 1 || a2[j] == 1)
                line += '#';
            else
                line += ' ';
        }
        answer.push_back(line);
    }
    return answer;
}
```
