#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num = stages.size();
    vector<pair<float, int>> fail;
    //vector <vector<int>> fail(n,vector<int>(2,0));
    //vector<double> fail;
    vector<int> index;
    int count = num;
    sort(stages.begin(), stages.end());
    
    //0-N+1
    for(int i=0 ; i<N+2 ; i++)
        index.push_back(0);
    
    for(int i=0; i<num; i++)
        index[stages[i]]++;
    //return index;
    for(int i=1; i<N+1; i++)
    {
        count -= index[i-1];
        double failure = (double)index[i]/count;
        fail.push_back(pair<float, int>(failure, i));
    }
    
    sort(fail.rbegin(), fail.rend());
    for(int i=0; i<N; i++)
        answer.push_back(fail[i].second);

    return answer;
}