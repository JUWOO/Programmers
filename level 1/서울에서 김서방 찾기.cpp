#include <iostream>
#include <string>
#include <vector>


using namespace std;


string solution(vector<string> seoul)
{
	int i; //배열 seoul의 index
	for (i = 0; i < seoul.size(); i++)
	{
   
    //해당 배열과 Kim을 비교
		if (seoul[i] == "Kim")
			break;
	}

	string s;
  
  //int to string, 형변환(int형을 string형으로)
  
	s = to_string(i);
  
	string answer = "김서방은 " + s + "에 있다";
	return answer;
}

int main()
{
	string area = solution({ "Jane", "Kim" });
	cout << area << endl;
}
