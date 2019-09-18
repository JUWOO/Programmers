
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//a=month, b=day
string solution(int a, int b)
{
  //해당 일까지 총 며칠인지를 구한다
  //switch문을 돌려 차례로 해당 월의 일수를 더한다
	for (int i = 1; i < a; i++)
	{
		switch (i) {
		case 1:
			b += 31;
			break;
		case 2:
			b += 29;
			break;
		case 3:
			b += 31;
			break;
		case 4:
			b += 30;
			break;
		case 5:
			b += 31;
			break;
		case 6:
			b += 30;
			break;
		case 7:
			b += 31;
			break;
		case 8:
			b += 31;
			break;
		case 9:
			b += 30;
			break;
		case 10:
			b += 31;
			break;
		case 11:
			b += 30;
			break;
		}
	}

	string Arr[7] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
  
  //해당 총 일수를 7로 나눠 나머지를 통해 요일을 알 수 있다
	b = b % 7;
	return Arr[b];
}

int main()
{
	string today = solution(7, 12);
	cout << today << endl;
}

