//by my own
//Time Complexity : O(n^2)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> array2;
    int start, end, num;
    int row = commands.size();

    for(int i=0 ; i<row ; i++)
    {
        start = commands[i][0];
        end = commands[i][1];
        num = commands[i][2];

        for(int j=start-1 ; j<end ; j++)
            array2.push_back(array[j]);
        sort(array2.begin(), array2.end());
        answer.push_back(array2[num-1]);
        for(int j : array2)
            array2.pop_back();
    }

    return answer;
}