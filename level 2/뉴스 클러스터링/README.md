뉴스 클러스터링
------------------

문제
----
여러 언론사에서 쏟아지는 뉴스, 특히 속보성 뉴스를 보면 비슷비슷한 제목의 기사가 많아 정작 필요한 기사를 찾기가 어렵다. 
Daum 뉴스의 개발 업무를 맡게 된 신입사원 튜브는 사용자들이 편리하게 다양한 뉴스를 찾아볼 수 있도록 문제점을 개선하는 업무를 맡게 되었다.

개발의 방향을 잡기 위해 튜브는 우선 최근 화제가 되고 있는 "카카오 신입 개발자 공채" 관련 기사를 검색해보았다.

카카오 첫 공채..'블라인드' 방식 채용

카카오, 합병 후 첫 공채.. 블라인드 전형으로 개발자 채용

카카오, 블라인드 전형으로 신입 개발자 공채

카카오 공채, 신입 개발자 코딩 능력만 본다

카카오, 신입 공채.. "코딩 실력만 본다"

카카오 "코딩 능력만으로 2018 신입 개발자 뽑는다"

기사의 제목을 기준으로 "블라인드 전형"에 주목하는 기사와 "코딩 테스트"에 주목하는 기사로 나뉘는 걸 발견했다. 튜브는 이들을 각각 묶어서 보여주면 카카오 공채 관련 기사를 찾아보는 사용자에게 유용할 듯싶었다.

유사한 기사를 묶는 기준을 정하기 위해서 논문과 자료를 조사하던 튜브는 "자카드 유사도"라는 방법을 찾아냈다.

자카드 유사도는 집합 간의 유사도를 검사하는 여러 방법 중의 하나로 알려져 있다. 두 집합 A, B 사이의 자카드 유사도 J(A, B)는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의된다.

예를 들어 집합 A = {1, 2, 3}, 집합 B = {2, 3, 4}라고 할 때, 교집합 A ∩ B = {2, 3}, 
합집합 A ∪ B = {1, 2, 3, 4}이 되므로, 집합 A, B 사이의 자카드 유사도 J(A, B) = 2/4 = 0.5가 된다. 
집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.

자카드 유사도는 원소의 중복을 허용하는 다중집합에 대해서 확장할 수 있다. 다중집합 A는 원소 "1"을 3개 가지고 있고, 
다중집합 B는 원소 "1"을 5개 가지고 있다고 하자. 이 다중집합의 교집합 A ∩ B는 원소 "1"을 min(3, 5)인 3개, 
합집합 A ∪ B는 원소 "1"을 max(3, 5)인 5개 가지게 된다. 다중집합 A = {1, 1, 2, 2, 3}, 다중집합 B = {1, 2, 2, 4, 5}라고 하면, 
교집합 A ∩ B = {1, 2, 2}, 합집합 A ∪ B = {1, 1, 2, 2, 3, 4, 5}가 되므로, 자카드 유사도 J(A, B) = 3/7, 약 0.42가 된다.

이를 이용하여 문자열 사이의 유사도를 계산하는데 이용할 수 있다. 
문자열 "FRANCE"와 "FRENCH"가 주어졌을 때, 이를 두 글자씩 끊어서 다중집합을 만들 수 있다. 
각각 {FR, RA, AN, NC, CE}, {FR, RE, EN, NC, CH}가 되며, 교집합은 {FR, NC}, 
합집합은 {FR, RA, AN, NC, CE, RE, EN, CH}가 되므로, 두 문자열 사이의 자카드 유사도 J("FRANCE", "FRENCH") = 2/8 = 0.25가 된다.

입력 형식

입력으로는 str1과 str2의 두 문자열이 들어온다. 각 문자열의 길이는 2 이상, 1,000 이하이다.

입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다. 이때 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다. 
예를 들어 "ab+"가 입력으로 들어오면, "ab"만 다중집합의 원소로 삼고, "b+"는 버린다.

다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다. "AB"와 "Ab", "ab"는 같은 원소로 취급한다.

출력 형식

입력으로 들어온 두 문자열의 자카드 유사도를 출력한다. 유사도 값은 0에서 1 사이의 실수이므로, 이를 다루기 쉽도록 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력한다.

예제 입출력

str1	      str2	      answer

FRANCE	    french	    16384

handshake	  shake hands	65536

aa1+aa2	    AAAA12	    43690

E=M*C^2	    e=m*c^2	    65536


링크 : <https://programmers.co.kr/learn/courses/30/lessons/17677#>


SOLUTION
---------
1. 변수

    change() : 대문자를 모두 소문자로 바꿔주고, 그 외의 문자를 `0`으로 변환하여 문자열을 정리하는 함수이다.
    
    seperate() : `change()`함수를 통해 정리된 문자열을 두 글자씩 쪼개 정리하는 함수이다. 이때, 불필요한 경우도 모두 제외한다.
    
    index1 / index2 : 두 문자씩 정리할 때, 불필요한 문자가 포함된 부분의 index 값을 저장한 배열. 다음 배열을 위의 `seperate()`의 매개변수로 입력하여, 제외하는데 이용한다.
    
    spt1 / spt2 : `seperate()`의 반환된 배열을 받아올 변수.
    
    uni : `spt1`과 `spt2`의 합집합
    
    inter : `spt1`과 `spt2`의 교집합
    
    answer : 반환할 값. `uni`와 `inter` 배열의 size()를 통해 구할 수 있다. 이때, int, float 형에 주의할 것.
    
   
2. 알고리즘

   -좀 더 좋은 알고리즘이 있을 것이다. 내일 모법 답안 풀이 확인할 것.
   
   (내 방식)
   
   -다음 문제는 크게 2단계로 나눌 수 있다.
   
   1.주어진 str을 두 문자씩 나누어 분리하는 단계. 이때, 인식하지 않는 수에 대해서는 삭제하고 배열의 형태로 나타낼 것. ex.Aab+cgD >> {aa, ab, dg, gd}
   2.각각 분리된 형태의 두 배열을 비교하여 합집합, 교집합을 구하고 원하는 결과값을 반환하는 과정.
   
   -대문자 소문자를 소문자로 통일하고, 그 외의 문자에 대해서 `0`으로 변환하는 함수를 거쳐, 문자열을 정리한 후에 1번 과정을 진행하였다.
   
   -정리된 string `str1`과 `str2`에 대해, 문자로 인식하지 않은 `0`인 경우에 분할된 배열에서 인식하지 않을 부분의 index를 index array인 `index1`과 `index2`에 받아둔다. 
   이때, `0`인 경우가 string의 가장 처음 부분일 때, 중간 부분일 때, 가자 끝일 때르 고려하여 index array에 넣어야 한다. 이후, 중복되는 index를 삭제해야 한다. 
   이를 위해 `index1.erase(unique(index1.begin(), index1.end()), index1.end());`를 실행한다. (이 과정을 첫번째 함수인 `change()`에서 동시에 실행할 수 없는지 찾아볼 것.)
   
   -이제 2번 과정을 실행해야 한다. 현재 정리된 형태의 배열 `spt1`과 `spt2`가 존재한다. 합집합과 교집합을 구해야 한다.
   
   합집합 : `set_union(spt1.begin(), spt1.end(), spt2.begin(), spt2.end(), back_inserter(uni));`
   
   교집합 : `set_intersection(spt1.begin(), spt1.end(), spt2.begin(), spt2.end(), back_inserter(inter));`
   
   


CODE
----
```{.cpp}
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string change(string str) {
    int num = str.size();
    for(int i=0 ; i<num ; i++)
    {
        if('A'<=str[i] && str[i]<='Z')
            str[i] += 32;
        else if('a'<= str[i] && str[i]<='z')
            continue;
        else
            str[i] = '0';
    }
    return str;
}

vector<string> seperate(string str, vector<int> index) {
    int num = str.size();
    vector<string> spt;
    int j = 0;
    if(index.empty())
        for(int i=0 ; i<num-1 ; i++)
        {
            string line = "";
            line += str[i];
            line += str[i+1];
            spt.push_back(line);
        }
    else
        for(int i=0 ; i<num-1 ; i++)
        {
            string line = "";
            if(index[j] == i)
            {
                j++;
                continue;
            }
            else
            {
                line += str[i];
                line += str[i+1];
                spt.push_back(line);
            }
        }
    return spt;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<int> index1;
    vector<int> index2;
    vector<string> spt1;
    vector<string> spt2;
    vector<string> uni;
    vector<string> inter;
    str1 = change(str1);
    str2 = change(str2);
    for(int i=0 ; i<str1.size() ; i++)
        if(str1[i] == '0')
        {
            if(i-1 >= 0)
                index1.push_back(i-1);
            if(i < str1.size()-1)
                index1.push_back(i);
        }
    for(int i=0 ; i<str2.size() ; i++)
        if(str2[i] == '0')
        {
            if(i-1 >= 0)
                index2.push_back(i-1);
            if(i < str2.size()-1)
                index2.push_back(i);
        }
    index1.erase(unique(index1.begin(), index1.end()), index1.end());
    index2.erase(unique(index2.begin(), index2.end()), index2.end());
    

    spt1 = seperate(str1, index1);
    spt2 = seperate(str2, index2);

    
    sort(spt1.begin(), spt1.end());
    sort(spt2.begin(), spt2.end());
    
    
    set_union(spt1.begin(), spt1.end(), spt2.begin(), spt2.end(), back_inserter(uni));
    set_intersection(spt1.begin(), spt1.end(), spt2.begin(), spt2.end(), back_inserter(inter));
    if(inter.size()==0 && uni.size()==0)
        return 65536;
    else
    {
        float div = (float)inter.size()/(float)uni.size();
        answer = div * 65536;
        return answer;
    }
    
}
'''
