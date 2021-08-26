캐시
------------------

문제
----
지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 해당 도시와 관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.

이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전 각 로직에 대한 성능 측정을 수행하였는데, 
제이지가 작성한 부분 중 데이터베이스에서 게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.

어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고, 
제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야 효율적인지 몰라 난감한 상황이다.

어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.

입력 형식

캐시 크기(cacheSize)와 도시이름 배열(cities)을 입력받는다.

cacheSize는 정수이며, 범위는 0 ≦ cacheSize ≦ 30 이다.

cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.

각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다.

출력 형식

입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.

조건

캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.

cache hit일 경우 실행시간은 1이다.

cache miss일 경우 실행시간은 5이다.

입출력 예제

캐시크기	도시이름(cities)	                                                                                                    실행시간

3	       ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	                              50

3	       ["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]	                                    21

2	       ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	60

5	       ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	52

2	       ["Jeju", "Pangyo", "NewYork", "newyork"]	16

0	       ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	25





링크 : <https://programmers.co.kr/learn/courses/30/lessons/17680>


SOLUTION
---------
1. 변수

    change() : 대문자를 소문자로 바꿔주는 함수. 모든 string에 대해 `change()`를 적용하고 진행할 것.
    
    cacheSize : 캐시의 크기. 이것에 따라 아래 `v`의 크기가 결정된다.
    
    v : vector array. 캐시에 해당하는 array로 LRU 알고리즘에 따라 들어가 있는 문자열의 순서와 종류가 바뀐다.
    
    it : `find()`를 통해 vector array `v` 안에서 특정 string을 찾고, 그 string의 pointer에 해당한다. 만약 찾지 못 했을 경우, it은 검색했던 배열 범위의 가장 끝을 가리키게 된다.
    
   
2. 알고리즘

   -LRU 캐시 교환 방식에 대해 알고 있어야 한다. (검색하면 쉽게 알 수 있음.)
   
   -find() 함수 사용하는 법에 대해 익힐 필요가 있음.
   
   -캐시 안에 문자열이 있을 때와 없을 때로 나누어서 문제를 해결해야한다.
   
   -문자열이 캐시 안에 있을 때 : 이 경우에는 이전의 캐시를 삭제해주고 가장 뒤로 새로운 문자열을 넣어주어야 한다.
   
   -문자열이 캐시 안에 없을 때 : 이 경우는 캐시가 가득 찼을 때와 차 있지 않을 때로 나누어야 한다. 기본적으로 새로운 문자열을 push()하는 것은 맞지만, 가득 차 있을 경우에는 가장 앞의 
   문자열을 제거한 후 push()를 진행해야 하는 반면, 가득 차 있지 않은 경우에는 그냥 push()만 하여도 된다.
   
   


CODE
----
```{.cpp}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
string change(string line) {
    int num = line.size();
    for(int i=0 ; i<num ; i++)
    {
        if('A'<=line[i] && line[i]<='Z')
            line[i] += 32;
    }
    return line;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    if(cacheSize == 0)
        return cities.size() * 5;
    for(int i=0 ; i<cities.size() ; i++)
    {
        string line = cities[i];
        line = change(line);
        auto it = find(v.begin(), v.end(), line);
        if(it == v.end())
        {
            if(cacheSize > v.size())
                v.push_back(line);
            else
            {
                for(int num=0 ; num<cacheSize-1 ; num++)
                    v[num] = v[num+1];
                v[cacheSize-1] = line;
            }
            answer += 5;
        }
        else
        {
            for(int num=distance(v.begin(),it) ; num<v.size()-1 ; num++)
                v[num] = v[num+1];
            v[v.size()-1] = line;
            answer += 1;
        }
    }
    return answer;
}
'''
