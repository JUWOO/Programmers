
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int a, int b)
{
	long long answer = 0;
	int max, min;
  
  //a, b의 크기를 비교한다
	max = a > b ? a : b; 
	min = a < b ? a : b;
 
  //min부터 max까지 더한다
	for (int i = min; i <= max; i++)
		answer += i;
    
	return answer;
}

int main()
{
	long long sub = solution(3, 45);
	cout << sub << endl;
}
