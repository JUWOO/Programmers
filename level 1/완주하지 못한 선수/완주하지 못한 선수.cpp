//해쉬 문제이다
//해쉬 map을 사용하였다.
//Time complexity : O(n)
//21.03.30 수정

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //string : key값, 완주자 이름
    //int : count 값. 동명이인인 경우를 위해서 존재
    unordered_map<string, int> strMap;
    //srtMap(hashMap)만들기.
    for(auto elem : completion)
    {
        //strMap에 elem(completion의 사람 이름)값이 없을 때,
        //strMap에 <elem,1>을 추가한다.
        if(strMap.end() == strMap.find(elem))
            strMap.insert(make_pair(elem, 1));
        //동명이인의 경우, 이미 존재하는 <elem, ->에 count++하기
        else
            strMap[elem]++;
    }

    for(auto elem : participant)
    {
        //strMap에서 'elem'을 key로 갖는 것을 발견하지 못하면,
        //그게 바로 정답. answer=elem
        if(strMap.end() == strMap.find(elem))
        {
            answer = elem;
            break;
        }
		//그런데 elem이 있음 >> 동명이인의 경우를 체크해야 한다.
        else
        {
			//strMap[elem] : count
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