//해쉬 문제이다
//해쉬 map을 사용하였다.
//Time complexity : O(n)

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> strMap;
	//string : key값, 완주자 이름
	//int : count 값. 동명이인인 경우를 위해서 존재
    for(auto elem : completion)
    {
        if(strMap.end() == strMap.find(elem))
		//현재맵에 elem값이 없을 때,
            strMap.insert(make_pair(elem, 1));
        else
            strMap[elem]++;
			//동명이인의 경우 count++하기
    }

    for(auto elem : participant)
    {
        if(strMap.end() == strMap.find(elem))
        {
            answer = elem;
            break;
        }
        else
        {
            strMap[elem]--;
            if(strMap[elem] < 0)
            {
                answer = elem;
                break;
            }
        }
    }
    return answer;
}