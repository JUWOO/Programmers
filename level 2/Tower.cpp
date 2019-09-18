#include <iostream>
#include <vector>

using namespace std;


vector<int> solution(vector<int> heights) //heights 건물 높이
{
	vector<int> stack; //건물의 높이를 차례로 저장 / 현재의 높이 값과 앞의 높이를 비교하기 위한 벡터
	vector<int> answer; //최종 결과값, 송신된 건물 번호 배열

  //i는 건물 번호(0부터 시작)
	for (int i = 0; i < heights.size(); i++)
	{
		int j;
    
    //stack.size()는 stack에 들어있는 건물의 개수
		for (j = stack.size() - 1; j >= 0; j--)
		{
    
      //i번째 건물의 높이와 stack에 들어있는 건물의 높이를
      //제일 마지막에 들어간 건물부터 차례로 비교한다
			if (heights[i] < stack[j])
			{
				break;
			}
		}
    
    //for문을 무사히 탈출할 경우 j=-1이다.
    //결국 최종 결정된 j+1이 송신된 건물의 번호
    
		stack.push_back(heights[i]); //stack에 건물 높이를 차례로 입력
		answer.push_back(j + 1); //answer값에 송신된 건물의 번호를 넣는 것
    
	}
	return answer;
}

int main()
{
	vector<int> v = solution({ 6,9,5,7,4 });
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	
}
