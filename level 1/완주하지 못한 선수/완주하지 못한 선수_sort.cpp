//완주하지 못한 선수
//sort 함수를 이용하였다.
//Time Complexity : O(nlogn)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //participant와 completion을 sort한 후 차례로 비교한다.
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0; i<completion.size(); i++)
    {
        if(participant[i]!=completion[i])
            return participant[i];
    }
    return participant[participant.size()-1];
}