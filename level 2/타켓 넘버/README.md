타겟 넘버 
------------------

문제
----
n개의 음이 아닌 정수가 있습니다. 
이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다
예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3

+1-1+1+1+1 = 3

+1+1-1+1+1 = 3

+1+1+1-1+1 = 3

+1+1+1+1-1 = 3

사용할 수 있는 숫자가 담긴 배열 numbers, 
타겟 넘버 target이 매개변수로 주어질 때 
숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

링크 : <https://programmers.co.kr/learn/courses/30/lessons/43165>


SOLUTION
---------
1. 변수

   answer : 총 개수
   
   count : DFS의 깊이. 0에서 시작해 재귀함수에 한 번 들어갈 때마다 1씩 증가한다. 최대 깊이는 numbers의 size보다 커질 수 없다.
   
   sum : 진행한 numbers의 합계. 마지막 부분에서 sum과 target 값을 비교해야 한다.
   
   
   
2. 알고리즘

   -주어진 numbers에 대해 모든 경우의 수를 살펴보아야 한다. 즉, DFS 방식을 적용해야 한다.
   
   -DFS는 재귀함수를 이용한다. 따라서 종결조건을 작성하는데 유의할 것.
   
   -노드의 분기 case는 `+`인 경우와 `-`인 경우로 나뉜다.
   
   -종결 조건의 경우 DFS의 깊이와 numbers의 size를 비교하는 방식으로 진행.


CODE
----
```{.cpp}
using namespace std;

// answer : 결과적으로 return 할 값
// count : 깊이
// sum : 총 합계
void dfs(vector<int>& numbers, int& answer, int& target, int count, int sum)
{
	if(count == numbers.size()-1)
	{
		if(target == sum+numbers[count])
            answer++;
		if(target == sum-numbers[count])
            answer++;
        return;
	}
	dfs(numbers, answer, target, count+1, sum+numbers[count]);
	dfs(numbers, answer, target, count+1, sum-numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
	dfs(numbers, answer, target, 0, 0);
    return answer;
}
