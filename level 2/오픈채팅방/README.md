오픈채팅방
------------------

문제
----
카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데, 본래 닉네임이 아닌 가상의 닉네임을 사용하여 채팅방에 들어갈 수 있다.

신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 다양한 사람들이 들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다. 채팅방에 누군가 들어오면 다음 메시지가 출력된다.

"[닉네임]님이 들어왔습니다."

채팅방에서 누군가 나가면 다음 메시지가 출력된다.

"[닉네임]님이 나갔습니다."

채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다.

채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.

채팅방에서 닉네임을 변경한다.

닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다.

예를 들어, 채팅방에 "Muzi"와 "Prodo"라는 닉네임을 사용하는 사람이 순서대로 들어오면 채팅방에는 다음과 같이 메시지가 출력된다.

"Muzi님이 들어왔습니다."

"Prodo님이 들어왔습니다."

채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다.

"Muzi님이 들어왔습니다."

"Prodo님이 들어왔습니다."

"Muzi님이 나갔습니다."

Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."

"Prodo님이 들어왔습니다."

"Prodo님이 나갔습니다."

"Prodo님이 들어왔습니다."

채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다. 
이제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다.

"Prodo님이 들어왔습니다."

"Ryan님이 들어왔습니다."

"Prodo님이 나갔습니다."

"Prodo님이 들어왔습니다."

채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 모든 기록이 처리된 후, 
최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함수를 완성하라.

제한사항

record는 다음과 같은 문자열이 담긴 배열이며, 길이는 1 이상 100,000 이하이다.

다음은 record에 담긴 문자열에 대한 설명이다.

모든 유저는 [유저 아이디]로 구분한다.

[유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - "Enter [유저 아이디] [닉네임]" (ex. "Enter uid1234 Muzi")

[유저 아이디] 사용자가 채팅방에서 퇴장 - "Leave [유저 아이디]" (ex. "Leave uid1234")

[유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - "Change [유저 아이디] [닉네임]" (ex. "Change uid1234 Muzi")

첫 단어는 Enter, Leave, Change 중 하나이다.

각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.

유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.

유저 아이디와 닉네임의 길이는 1 이상 10 이하이다.

채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.

입출력 예

record	

["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]

result

["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]


링크 : <https://programmers.co.kr/learn/courses/30/lessons/42888>


SOLUTION
---------
1. 변수

   
    `vector<string> answer` : 최종 결과값. 원하는 결과를 string의 형탤 담아야 한다.
  
    `int num` : `record`의 사이즈.
  
    `vector<vector<string>> v` : `record`의 값을 공백에 맞춰 나누어 담은 배열.
    
    unordered_map<string, string> hash_map : `v`를 바탕으로 `uid`와 `name`의 관계를 정리한 해시맵.
    
   
   
2. 알고리즘

   -가장 먼저 string의 형태인 `record`를 공백에 따라 분리해 보기 쉽게 2중 배열의 형태로 만들어야 한다. 아래의 코드에서는 일일이 `" "(공백)`에 따라 분리가 되도록 이중 포문을 설치하였지만, 
   추후에 다른 문제에서도 적용할 수 있게 함수의 형탤 만들어두는 것도 편할 것 같다.
   
   -string에서 받아온 문자들은 이중 vector array `v`에 담기게 된다.
   
   -`v`를 통해 들어오고 나간 것에 따라 uid에 따른 이름을 update한 배열을 만들어야 한다. 이때, 처음에는 2중 for문을 이용하여 vector array `data`에 일일이 담아서 정리하였다. 
   그런데 이 경우, 변수의 값이 지나치게 커질 때, 런타임 에러가 난다. 따라서 이 보다 효율적인 알고리즘을 구현해야 하는데, 이때 `hash_map`을 사용한다. 그렇게 되면 2중 for문을 일일이 구현했던 것을 한 번에
    해결할 수 있으며, 수식이 간단해진다.
    
   -가장 마지막에는 `v`를 바탕으로 원하는 결과값을 출력하되, 사람의 닉네임에 대해서는 `hash_map`을 참고하여야 한다.


CODE
----
with hash
```{.cpp}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int num = record.size();
    vector<vector<string>> v;
    unordered_map<string, string> hash_map;
    
    for(int i=0 ; i<num ; i++)
    {
        string line = record[i];
        string word = "";
        vector<string> arr;
        //한 줄에 대해서 처리
        for(int j=0 ; j<line.size() ; j++)
        {
            if(isspace(line[j]))
            {
                arr.push_back(word);
                //answer.push_back(word);
                word = "";
            }
            else
                word += line[j];
        }
        arr.push_back(word);
        //answer.push_back(word);
        v.push_back(arr);
    }
        
    for(int i = 0; i < num; i++)
        if(v[i][0]!="Leave")
            hash_map[v[i][1]] = v[i][2];
    
      
    for(int i=0 ; i<num ; i++)
    {
        string line = "";
        if(v[i][0]=="Enter")
        {
            line += hash_map[v[i][1]];
            line += "님이 들어왔습니다.";
        }
        else if(v[i][0]=="Leave")
        {
            line += hash_map[v[i][1]];
            line += "님이 나갔습니다.";
        }
        else
            continue;
        answer.push_back(line);
    }
    return answer;
}
