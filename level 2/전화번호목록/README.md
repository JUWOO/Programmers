전화번호 목록
-------------
문제
----
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다. 
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119

박준영 : 97 674 223

지영석 : 11 9552 4421

전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.


link : <https://programmers.co.kr/learn/courses/30/lessons/42577>

SOLUTION
---------
해시를 사용하지 않고도 문제를 풀 수 있어서, 해시를 사용하지 않았다.

전화번호 배열이 담긴 phone_book을 오름차순으로 sort할 경우 숫자의 앞부분(접두사)는 같고 뒷부분만 달라질 확률이 크다.

sort 후에 매번 반복을 진행할 때마다 현재 phone_book의 string이(phone_book[i]) 그 다음 string(phoone_book[i+1])의 접두사 부분에 존재하는지를 확인했다. 이때 사용한 함수는 substr이다.
그래서 존재할 경우 false를 return하였다.

01.
<pre>
<code>
using namespace std;
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0 ; i < phone_book.size()-1 ; i++)
    {
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size()))
            return false;
    }
    return answer;
}
</code>
</pre>

그러나 만약 해시를 사용할 경우에 다음과 같이 생각할 수 있다.

hash_map을 만들어 그 안에 phone_book의 string을 채운다.

phone_book에 저장된 번호를 앞에서부터 하나하나씩 비교한다. 이를 위해 phone_number 변수에 전화번호의 앞에서부터 차레로 담는다. 
하나를 담을 때마다 if문을 통해서 다음 phone_number가 hash_map에 있는지 확인하고, 또한 해당 번호가 자기 자신이 아닌 것을 확인한다.(phone_number != phone_book[i])

02.
<pre>
<code>
using namespace std;
bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> hash_map;
    for(int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for(int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }
    return answer;
}
</code>
</pre>


