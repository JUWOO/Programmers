#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
string change(string line) {
    int num = line.size();
    for(int i=0 ; i<num ; i++)
    {
        if('A'<=line[i] && line[i]<='Z')
            line[i] += 32;
    }
    return line;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    if(cacheSize == 0)
        return cities.size() * 5;
    for(int i=0 ; i<cities.size() ; i++)
    {
        string line = cities[i];
        line = change(line);
        auto it = find(v.begin(), v.end(), line);
        if(it == v.end())
        {
            if(cacheSize > v.size())
                v.push_back(line);
            else
            {
                for(int num=0 ; num<cacheSize-1 ; num++)
                    v[num] = v[num+1];
                v[cacheSize-1] = line;
            }
            answer += 5;
        }
        else
        {
            for(int num=distance(v.begin(),it) ; num<v.size()-1 ; num++)
                v[num] = v[num+1];
            v[v.size()-1] = line;
            answer += 1;
        }
    }
    return answer;
}