위장
------------------

문제
----

스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.

예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.

종류	이름

얼굴	동그란 안경, 검정 선글라스

상의	파란색 티셔츠

하의	청바지

겉옷	긴 코트

스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 서로 다른 옷의 조합의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항

clothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있습니다.

스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.

같은 이름을 가진 의상은 존재하지 않습니다.

clothes의 모든 원소는 문자열로 이루어져 있습니다.

모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.

스파이는 하루에 최소 한 개의 의상은 입습니다.

입출력 예

clothes : [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]

return : 5

clothes : [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]

return : 3

입출력 예 설명

예제 #1

headgear에 해당하는 의상이 yellow_hat, green_turban이고 eyewear에 해당하는 의상이 blue_sunglasses이므로 아래와 같이 5개의 조합이 가능합니다.

1. yellow_hat
2. blue_sunglasses
3. green_turban
4. yellow_hat + blue_sunglasses
5. green_turban + blue_sunglasses


링크 : <https://programmers.co.kr/learn/courses/30/lessons/42578>


SOLUTION
---------
1. 변수

   
   
   
   
   
2. 알고리즘

   - 각 종류마다 착용할 수 있는 의상의 개수는 1개이다. 따라서, 옷을 입을 수 있는 총 가짓수는 (각 종류의 개수+1)을 하여 곱한 후, 아무것도 입지 않은 경우인 1을 빼주면 된다.
   - 결국 각 종류마다 속하 의상의 개수를 알아야 하는데, 2중 배열로 풀 수 있지만, hash map을 사용하면 쉽다. `unordered_map`을 선언하고, 루프문을 통해서 키 값에 해당하는 종류(string)에 대해 1씩 더하도록 하면 된다.
   - 이후, hash map의 int에 해당하는 값을 구해서 곱하면 되는데, c++ hash의 다른 함수 기능을 찾으면 아래에 내가 푼 코드보다 훨씬 깔끔하게 풀 수 있을 것.
   


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> hash_clothes;
    int num = clothes.size();
    vector<string> t;
    for(int i=0 ; i<num ; i++)
    {
        if(hash_clothes.end() == hash_clothes.find(clothes[i][1]))
        {
            hash_clothes[clothes[i][1]] = 1;
            t.push_back(clothes[i][1]);
        }
        else
            hash_clothes[clothes[i][1]]++;
    }
    int n = hash_clothes.size();
    
    for(int i=0 ; i<n ; i++)
        answer *= (hash_clothes[t[i]]+1);
    answer--;
    return answer;
}
```
