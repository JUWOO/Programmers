#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int numb = nums.size();
    vector<int> check;
    int last;
    sort(nums.begin(), nums.end());
    for(int i=0; i<numb; i++)
    {   
        last = check.size();
        if(last==numb/2)
            break;
        
        if(i == 0)
            check.push_back(nums[i]);
        else if(check[last-1] == nums[i])
            continue;
        else
            check.push_back(nums[i]);
    }
    answer = check.size();
    return answer;
}