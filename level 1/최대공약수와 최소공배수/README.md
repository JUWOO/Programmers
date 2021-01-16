최대공약수와 최소공배수
---------------------
문제
----
두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요. 
배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다. 
예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.

SOLUTION
----------
최대공약수(GCD)와 최소공배수(LCM).

최대공약수는 유클리드 호제법을 사용하면 된다.

* n, m: 최대공약수를 구하고자 하는 두 수
* r: n를 m로 나눈 나머지 = ( n%m ) = ( n mod m )
* `gcd(n,m) = gcd(m,r)` 를 이용한다.

최소공배수는 위에서 구한 최대공약수를 이용한다.

* n,m: 최소공배수를 구하고자 하는 두 수
* gcd(n,m): n과 m의 최대공약수
* (최소공배수 * 최대공약수 = n * m)를 이용
* `n * m / gcd(n,m)`를 이용한다.

링크 : <https://programmers.co.kr/learn/courses/30/lessons/12940>

```{.cpp}
#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m){
	while(m!=0){
		int r = n%m;
		n= m;
		m= r;
	}
	return n;
}

int lcm(int n, int m){
    return n * m / gcd(n,m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));
    
    return answer;
}
```
