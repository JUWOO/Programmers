#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool sosu(int num){
    if(num<2) return false;
    int a = (int)sqrt(num);
    for(int i=2 ; i<=a ; i++)
        if(num%i == 0)
            return false;
    return true;
}

int solution(vector<int> nums) {
    int num = nums.size();
    int a, b, c;
    int sum;
    int count = 0;
    for(int i=0; i<num-2; i++)
    {
        a = nums[i];
        for(int j=i+1; j<num-1; j++)
        {
            b = nums[j];
            for(int k=j+1; k<num; k++)
            {
                sum = a + b;
                sum += nums[k];
                if(sosu(sum))
                    count++;
                sum = 0;
            }
        }
    }

    return count;
}