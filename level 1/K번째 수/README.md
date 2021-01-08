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

for문을 통해 commands의 값을 차례로 받아와 start, end, num에 받았으며, array의 해당 숫자의 값을 새로운 배열인 array2에 받아와 진행하였다.

1.
<pre>
<code>
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
  </code>
  </pre>
