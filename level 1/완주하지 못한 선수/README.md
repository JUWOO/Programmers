완주하지 못한 선수

풀이
----

string : key값, 완주자 이름

int : count 값. 동명이인인 경우를 위해서 존재

if(strMap.end() == strMap.find(elem))

//현재맵에 elem값이 없을 때,
	
completion에서 map을 채워넣고 count를 1씩 추가한다면, paricipant에서 key값의 사람이 존재하는지 확인하고, 1씩 제거한다.

CODE
----

```{.}
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
```

다음 문제를 sort로도 풀 수 있다.

```{.python}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //participant와 competion을 각각 sort한 후에 차례로 비교한다.
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0; i<completion.size(); i++)
    {
        if(participant[i]!=completion[i])
            return participant[i];
    }
    return participant[participant.size()-1];
}
```
이 경우에는 코드가 간결하며 이해하기가 쉽지만, 해시를 사용할 때보다 time complexity가 커진다.

sort()함수의 시간 복잡도는 nlon(n)이기 때문이다.
