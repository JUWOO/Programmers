#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string change(string str) {
    int num = str.size();
    for(int i=0 ; i<num ; i++)
    {
        if('A'<=str[i] && str[i]<='Z')
            str[i] += 32;
        else if('a'<= str[i] && str[i]<='z')
            continue;
        else
            str[i] = '0';
    }
    return str;
}

//2ju3ki+ 2j ju u3 3k ki i+
//index : 0 2 3 5 >> 0 / 2-3 / 5

vector<string> seperate(string str, vector<int> index) {
    int num = str.size();
    vector<string> spt;
    int j = 0;
    if(index.empty())
        for(int i=0 ; i<num-1 ; i++)
        {
            string line = "";
            line += str[i];
            line += str[i+1];
            spt.push_back(line);
        }
    else
        for(int i=0 ; i<num-1 ; i++)
        {
            string line = "";
            if(index[j] == i)
            {
                j++;
                continue;
            }
            else
            {
                line += str[i];
                line += str[i+1];
                spt.push_back(line);
            }
        }
    return spt;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<int> index1;
    vector<int> index2;
    vector<string> spt1;
    vector<string> spt2;
    vector<string> uni;
    vector<string> inter;
    str1 = change(str1);
    str2 = change(str2);
    for(int i=0 ; i<str1.size() ; i++)
        if(str1[i] == '0')
        {
            if(i-1 >= 0)
                index1.push_back(i-1);
            if(i < str1.size()-1)
                index1.push_back(i);
        }
    for(int i=0 ; i<str2.size() ; i++)
        if(str2[i] == '0')
        {
            if(i-1 >= 0)
                index2.push_back(i-1);
            if(i < str2.size()-1)
                index2.push_back(i);
        }
    index1.erase(unique(index1.begin(), index1.end()), index1.end());
    index2.erase(unique(index2.begin(), index2.end()), index2.end());

    spt1 = seperate(str1, index1);
    spt2 = seperate(str2, index2);

    
    sort(spt1.begin(), spt1.end());
    sort(spt2.begin(), spt2.end());
    
    
    set_union(spt1.begin(), spt1.end(), spt2.begin(), spt2.end(), back_inserter(uni));
    set_intersection(spt1.begin(), spt1.end(), spt2.begin(), spt2.end(), back_inserter(inter));
    if(inter.size()==0 && uni.size()==0)
        return 65536;
    else
    {
        float div = (float)inter.size()/(float)uni.size();
        answer = div * 65536;
        return answer;
    }
    
}