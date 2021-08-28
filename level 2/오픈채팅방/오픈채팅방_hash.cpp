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
