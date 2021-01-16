#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[5] = {1,2,3,4,5};
    int two[8] = {2,1,2,3,2,4,2,5};
    int three[10] = {3,3,1,1,2,2,4,4,5,5};
    int a=0, b=0, c=0;
    int count_a=0, count_b=0, count_c=0;
    
    for(int i=0 ; i<answers.size() ; i++)
    {
        a = i%5;
        b = i%8;
        c = i%10;
        if(answers[i]==one[a])
            count_a++;
        if(answers[i]==two[b])
            count_b++;
        if(answers[i]==three[c])
            count_c++;
    }
    if(count_a > count_c)
        if(count_a == count_b)
        {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(count_a < count_b)
            answer.push_back(2);
        else
            answer.push_back(1);
    else if(count_a < count_c)
        if(count_c == count_b)
        {
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(count_c < count_b)
            answer.push_back(2);
        else
            answer.push_back(3);
    else if(count_a == count_c)
        if(count_c == count_b)
        {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(count_c < count_b)
            answer.push_back(2);
        else
        {
            answer.push_back(1);
            answer.push_back(3);
        }

    return answer;
}