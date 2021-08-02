using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long a = 0;
    for(int i =0; i<count; i++)
        a += price*(i+1);
    answer = a - money;
    if(answer >= 0)
        return answer;
    else
        answer = 0;
        return answer;
}