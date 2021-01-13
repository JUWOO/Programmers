#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int k = 0, j =0;
    vector<int> arr;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(int i=0 ; i<n ; i++)
    {
        arr.push_back(1);
        if(lost[k]-1==i)
        {
            arr[i]--;
            k++;
        }
        if(reserve[j]-1==i)
        {
            arr[i]++;
            j++;
        }
    }

    for(int i2=0 ; i2<n; i2++)
    {
        if(arr[i2] == 0 && arr[i2-1] ==2)
        {
            arr[i2-1]--;
            arr[i2]++;
        }
        else if(arr[i2]==0 && arr[i2+1]==2)
        {
            arr[i2+1]--;
            arr[i2]++;
        }
    }

    for(int i3 = 0; i3<n; i3++)
        if(arr[i3]>=1)
            answer++;
 
    return answer;
}