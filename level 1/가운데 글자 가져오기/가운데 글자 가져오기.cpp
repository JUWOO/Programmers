//time complexity : O(1)
#include <string>
#include <vector>
#include <string.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.length();
    char array[n+1];
    int k = n/2;
    
    strcpy(array, s. c_str());
    
    if(n%2==0)
    {
        answer += array[k-1];
        answer += array[k];
    }
    else
        answer = array[k];
    
    return answer;
}