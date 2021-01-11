K번째 수
--------
문제
----
배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면

array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.

다음 배열을 정렬하면 [2, 3, 5, 6]입니다. 
이때, 배열의 3번째 숫자는 5입니다.

배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, 
commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

링크 : <https://programmers.co.kr/learn/courses/30/lessons/42748>


SOLUTION
---------
문제의 흐름을 따라 진행하였다.

`for`을 통해 `commands`의 값을 차례로 받아와 `start`, `end`, `num`에 받았으며, `array`의 해당 숫자의 값을 새로운 배열인 `array2`에 받아와 진행하였다.

1.
```{.cpp}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> array2;
    int start, end, num;
    int row = commands.size();
    for( int i=0; i < row;i++)
    {
        start = commands[i][0];
        end = commands[i][1];
        num = commands[i][2];
        for(int j=start-1 ; j < end ; j++)
            array2.push_back(array[j]);
        sort(array2.begin(), array2.end());
        answer.push_back(array2[num-1]);
        for(int j : array2)
            array2.pop_back();
    }
    return answer;
  }
```
  
하지만 해당 방식의 경우는 시간 복잡도가 O(n^2)에 해당한다.
  
이를 해결하기 위해 첫번째 for문을 돌릴 때, 한 번에 해결하는 방식을 고민해보았다.

기존의 array가 손상되지 않게 temp 배열을 선언하고, 그 temp 내에서 commands에서 주어진 범위 부분에 대하여 sort를 진행한 후, 그 안에서 바로 정답을 받아 answer에 넣는 방식으로 
진행할 경우 이중 for문을 사용하지 않아도 된다.
  
2.
```{.cpp}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }
    return answer;
}
```
  
  
  
