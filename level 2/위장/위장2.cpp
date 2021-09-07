#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> hash_clothes;
    int num = clothes.size();
    vector<string> t;
    for(int i=0 ; i<num ; i++)
        hash_clothes[clothes[i][1]]++;

    for(auto i = hash_clothes.begin() ; i != hash_clothes.end() ; i++)
        answer *= (i->second + 1);
    
    answer--;
    return answer;
}
