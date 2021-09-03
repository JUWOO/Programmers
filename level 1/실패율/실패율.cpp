#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num = stages.size();
    vector<pair<float, int>> fail;
    vector<int> index;
    int count = num;
    sort(stages.begin(), stages.end());
    
    for(int i=0 ; i<N+2 ; i++)
        index.push_back(0);
    
    for(int i=0; i<num; i++)
        index[stages[i]]++;

    for(int i=1; i<N+1; i++)
    {
        count -= index[i-1];
        if(index[i]==0)
            fail.push_back(pair<float,int>(0,i));
        else
        {
            double failure = (double)index[i]/count;
            fail.push_back(pair<float, int>(failure, i));
        }
    }
    
    sort(fail.rbegin(), fail.rend());
    int c = 0;
    vector<int> a;
    for(int i=0; i<N; i++)
    {
        if(i<N-1 && fail[i].first == fail[i+1].first)
        {
            c++;
            a.push_back(fail[i].second);
        }
        else
            if(c > 0)
            {
                c++;
                a.push_back(fail[i].second);
                while(a.size()!=0)
                {
                    answer.push_back(a.back());
                    a.pop_back();
                }
            }
            else
                answer.push_back(fail[i].second);
    }
    return answer;
}
