#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//10진수를 넣으면 2진수로 출력
vector<int> binary_fn(int num, int n) {
    vector<int> v;
    while(num > 1)
    {
        v.push_back(num%2);
        num /= 2;
    }
    v.push_back(num);
    while(v.size() != n)
        v.push_back(0);
    reverse(v.begin(), v.end());
    return v;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int num = arr1.size();
    for(int i=0; i<num ; i++)
    {
        string line = "";
        vector<int> a1 = binary_fn(arr1[i], n);
        vector<int> a2 = binary_fn(arr2[i], n);
        for(int j=0 ; j<n ; j++)
        {
            if(a1[j] == 1 || a2[j] == 1)
                line += '#';
            else
                line += ' ';
        }
        answer.push_back(line);
    }
    return answer;
}