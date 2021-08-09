#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int num = scores.size();
    float sum;
    int big, small;
    int count_s = 0, count_b = 0;
    
    for(int i=0 ; i<num ; i++)
    {
        sum = 0;
        big = 0, small = 100;
        count_s = 0, count_b = 0;
        for(int j=0 ; j<num ; j++)
        {
            if(big < scores[j][i]) {
                big = scores[j][i];
                count_b = 0;
            }
            else if(big == scores[j][i])
                count_b++;
            if(small > scores[j][i]) {
                small = scores[j][i];
                count_s = 0;
            }
            else if(small == scores[j][i])
                count_s++;
            
            sum += scores[j][i];
        }
        if(scores[i][i] == small && count_s == 0)
        {
            sum -= scores[i][i];
            sum = sum / (num-1);
        }
        else if(scores[i][i] == big && count_b == 0)
        {
            sum -= scores[i][i];
            sum = sum / (num-1);
        }
        else
            sum = sum / num;
        
        if(sum >= 90)
            answer += 'A';
        else if(sum >= 80 && sum < 90)
            answer += 'B';
        else if(sum >= 70 && sum < 80)
            answer += 'C';
        else if(sum >= 50 && sum < 70)
            answer += 'D';
        else
            answer += 'F';
    }
    return answer;
}