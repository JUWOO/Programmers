#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num = 0; //점수
    int first = 0;
    int mul = 0;
    int count = 0;
    vector<int> v;
    for(int i=0 ; i<dartResult.size() ; i++)
    {
        //점수를 num에 받아오기
        if(dartResult[i]=='0')
            num = 0;
        else if('2'<=dartResult[i] && dartResult[i]<='9')
        {
            string s = "";
            s = dartResult[i];
            num = stoi(s);
        }
        else if(dartResult[i]=='1')
        {
            if(dartResult[i+1]!='0')
                num = 1;
            else if(dartResult[i+1]=='0')
            {
                num = 10;
                i++;
            }
        }
        
        if('A'<=dartResult[i] && dartResult[i]<='Z')
        {
            if(dartResult[i]=='S')
                mul = 1;
            else if(dartResult[i]=='D')
                mul = 2;
            else if(dartResult[i]=='T')
                mul = 3;
            first = pow(num, mul);
            v.push_back(first);
            
            
            if(dartResult[i+1] == '*')
            {
                if(count == 0)
                    v[count] *= 2;
                else
                {
                    v[count-1] *= 2;
                    v[count] *= 2;
                }
                i++;
            }
            else if(dartResult[i+1] == '#')
            {
                v[count] *= -1;
                i++;
            }
            count++;
            
        }
    }
    
    for(int i=0 ; i<3 ; i++)
        answer += v[i];
    return answer;
    
}