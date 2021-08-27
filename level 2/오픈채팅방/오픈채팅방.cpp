#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//record를 vector array v로 만들어서 그 안의 name을 바꾸는 방법을 생각했음
//그런데, 그것보다는 차라리 관리자 명단을 따로 만들어서 그 안에서 변형을 하고, 그거에 맞춰서 출력하는 게 더 쉽지 않은가.....


vector<string> solution(vector<string> record) {
    vector<string> answer;
    int num = record.size();
    vector<vector<string>> v;
    vector<vector<string>> data;
    
    //이 부분은 그럼 그대로 유지하고, 대신에 이름 부분은 받아오지 않아도 되겠다.
    //이름 부분은 다른 배열을 선언하고 그 안에 저장하기(id-name)+update하기.
    for(int i=0 ; i<num ; i++)
    {
        string line = record[i];
        string word = "";
        vector<string> arr;
        //한 줄에 대해서 처리
        for(int j=0 ; j<line.size() ; j++)
        {
            if(isspace(line[j]))
            {
                arr.push_back(word);
                //answer.push_back(word);
                word = "";
            }
            else
                word += line[j];
        }
        arr.push_back(word);
        //answer.push_back(word);
        v.push_back(arr);
    }
    
    //data에 id-name 채워넣기. 최종 수정된 버전으로 저장하게 됨.
    vector<string> data_id;
    for(int i=0 ; i<num ; i++)
    {
        //출입여부
        if(v[i][0]=="Enter")
        {
            string id = v[i][1];
            string name = v[i][2];
            auto it = find(data_id.begin(), data_id.end(),id);
            //data에 같은 id가 없을 때,
            if(it == data_id.end())
            {
                vector<string> arr2;
                arr2.push_back(id);
                data_id.push_back(id);
                arr2.push_back(name);
                data.push_back(arr2);
                
            }
            //data에 같은 id가 존재할 때.
            else
            {
                int n = distance(data_id.begin(),it); //해당 id의 index
                data[n][1] = name;
            }
        }
        
        else if(v[i][0]=="Change")
        {
            string id = v[i][1];
            string name = v[i][2];
            //data에서 id 검색하기
            auto it = find(data_id.begin(),data_id.end(),id);
            int n = distance(data_id.begin(),it); //해당 id의 index
            data[n][1] = name;
        }
        else
            continue;
    }
    
    for(int i=0 ; i<num ; i++)
    {
        
    }
    
    for(int k=0 ; k<data.size() ; k++)
    {
        string juwoo = data[k][1];
        answer.push_back(juwoo);
    }
    return answer;
}