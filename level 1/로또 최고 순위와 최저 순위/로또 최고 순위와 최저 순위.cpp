#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int nums;
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<6; i++)
    {
        nums = lottos[i];
        if(nums == 0)
            count2++;
        else
            for(int j=0; j<6; j++)
                if(nums == win_nums[j])
                {
                    count1++;
                    break;
                }
    }
    
    if(count1 == 0 && count2 == 0)
        answer.push_back(6);
    else
        answer.push_back(7-(count1+count2));
        
    if(count1 > 0)
        answer.push_back(7-count1);
    else
        answer.push_back(6);
    return answer;
}