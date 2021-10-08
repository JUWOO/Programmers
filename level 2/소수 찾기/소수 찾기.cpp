#include <string>
#include <vector>
#include <algorithm>
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

int solution(string numbers) {
    int answer = 0;

    vector<int> num;
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 0; i < numbers.size(); i++)
            num.push_back(stoi(numbers.substr(0, i + 1)));
        
    } while (next_permutation(numbers.begin(), numbers.end()));

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());


    for (int i = 0; i < num.size(); i++)
    {
        if (sosu(num[i]))
            answer++;
    }

    return answer;
}
