위장
------------------

문제
----

한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항

numbers는 길이 1 이상 7 이하인 문자열입니다.

numbers는 0~9까지 숫자만으로 이루어져 있습니다.

"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.


입력 : 17
출력 : 2



링크 : <https://programmers.co.kr/learn/courses/30/lessons/42839#qna>


SOLUTION
---------
1. 변수

   numbers : 처음에 주어지는 string 값. string 상태에서 `substr()`을 사용한 후, `stoi()`를 통해 `int`형으로 바꿔준다.
   
   num : `numbers`의 각 숫자로 만들 수 있는 모든 숫자 조합을 저장한 배열.
   
   sosu() : 해당 숫자가 소수인지 여부를 판별하는 함수.
   
   answer : 소수의 개수. `sosu()`를 실행하여 true 일 때만, `answer`의 값을 1씩 증가하도록 한다.
   
   
   
   
   
2. 알고리즘

   - 주어진 숫자로 만들 수 있는 모든 수 순열을 배열에 정리한 후, 그 배열에 대해 소수 여부를 판정해야 한다.
  
   - 소수 여부 판정 : `sosu` 함수를 따로 만들었다.
  
   - 문제는 주어진 수로 만들 수 있는 모든 순열이다. 이를 위해 `next_permutation` 함수를 사용하였다.
  
   - `next_permutation()`
  
   ```{.cpp}
   do {
      // 내부 코드를 실행한다.
   } while(next_permutation(numbers.begin(), numbers.end()))
  
   ```
   이처럼 numbers의 수에 대해 교환(?)에 의해 새 순열조합을 만들어내고, 그때마다 `do{}` 내부의 코드를 실행한다.
  
   - 이때, `numbers`의 모든 수에 대해 보는 게 아닌, 1자리 수부터 n자리 수까지 저장해두어야 한다. 따라서, `sunstr()`를 사용하였다.
  
  
   


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool sosu(int num){
    if(num<2) return false;
    int a = (int)sqrt(num);
    for(int i=2 ; i<=a ; i++)
        if(num%i == 0)
            return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;

    vector<int> num;
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 0; i < numbers.size(); i++)
            num.push_back(stoi(numbers.substr(0, i + 1)));
        
    } while (next_permutation(numbers.begin(), numbers.end()));

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());


    for (int i = 0; i < num.size(); i++)
    {
        if (sosu(num[i]))
            answer++;
    }

    return answer;
}
```
