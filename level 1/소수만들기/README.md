소수 만들기
------------------


문제
----

주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다. 숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, 
nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

ex. [1,2,3,4]

return 1

링크 : <https://programmers.co.kr/learn/courses/30/lessons/12977>


SOLUTION
---------
1. 변수


   
   
   
2. 알고리즘

   -알고리즘이라고 할 것이 딱히 없다.
   
   -소수 여부를 측정하는 함수(`sosu`)를 따로 만들어 사용하였다.
   
   -3중 for문에, 함수 `sosu`까지 고려하면 거의 4중 for문이다. 이대로.. 괜찮은 것인가. 좀 더 좋은 효율의 알고리즘은 없을지 고민할 필요가 있다.
   


CODE
----
```{.cpp}
#include <vector>
#include <iostream>
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

int solution(vector<int> nums) {
    int num = nums.size();
    int a, b, c;
    int sum;
    int count = 0;
    for(int i=0; i<num-2; i++)
    {
        a = nums[i];
        for(int j=i+1; j<num-1; j++)
        {
            b = nums[j];
            for(int k=j+1; k<num; k++)
            {
                sum = a + b;
                sum += nums[k];
                if(sosu(sum))
                    count++;
                sum = 0;
            }
        }
    }

    return count;
}
