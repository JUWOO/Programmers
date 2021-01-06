완주하지 못한 선수

풀이
>string : key값, 완주자 이름
>int : count 값. 동명이인인 경우를 위해서 존재
>if(strMap.end() == strMap.find(elem))
	//현재맵에 elem값이 없을 때,
>completion에서 map을 채워넣고 count를 1씩 추가한다면, paricipant에서 key값의 사람이 존재하는지 확인하고, 1씩 제거한다.

CODE
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> strMap;
	
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
