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
    {
        if(hash_clothes.end() == hash_clothes.find(clothes[i][1]))
        {
            hash_clothes[clothes[i][1]] = 1;
            t.push_back(clothes[i][1]);
        }
        else
            hash_clothes[clothes[i][1]]++;
    }
    int n = hash_clothes.size();
    
    for(int i=0 ; i<n ; i++)
        answer *= (hash_clothes[t[i]]+1);
    answer--;
    return answer;
}