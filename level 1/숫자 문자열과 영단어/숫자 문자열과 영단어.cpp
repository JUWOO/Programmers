#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int num = s.size();
    int i = 0;
    char c;
    string str = "";
    while(i != num)
    {
        c = s[i];
        if('a'<=c && c<='z')
        {
            if(c=='z')
            {
                str += '0';
                i += 4;
            }
            else if(c=='o')
            {
                str += '1';
                i += 3;
            }
            else if(c=='e')
            {
                str += '8';
                i += 5;
            }
            else if(c=='n')
            {
                str += '9';
                i += 4;
            }
            else if(c=='t')
            {
                if(s[i+1]=='w')
                {
                    str += '2';
                    i += 3;
                }
                else
                {
                    str += '3';
                    i += 5;
                }
            }
            else if(c=='f')
            {
                if(s[i+1]=='o')
                {
                    str += '4';
                    i += 4;
                }
                else
                {
                    str += '5';
                    i += 4;
                }
            }
            else if(c=='s')
            {
                if(s[i+1]=='i')
                {
                    str += '6';
                    i += 3;
                }
                else
                {
                    str += '7';
                    i += 5;
                }
            }
        }
        else
        {
            str += c;
            i++;
        }
        
    }
    answer = stoi(str);
    return answer;
}