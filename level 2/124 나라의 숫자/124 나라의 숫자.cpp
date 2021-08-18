#include <string>
#include <vector>
#include <iostream>

using namespace std;

string rever(string answer) {
    int num = answer.length();
    int temp;
    for(int i=0; i<num/2 ; i++)
    {
        temp = answer[i];
        answer[i] = answer[num-(1+i)];
        answer[num-(1+i)] = temp;
    }
    return answer;
}

string solution(int n) {
    string answer = "";
    int last;
    int num = 0;
    while(n>2)
    {
        last = n%3;
        if(last == 0){
            answer += to_string(4);
            n = (n/3)-1;
        }
        else {
            answer += to_string(last);
            n = n/3;
        }
    }
    if(n!=0)
        answer += to_string(n);
    return rever(answer);
}