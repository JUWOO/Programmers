#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int num = record.size();
    vector<vector<string>> v;
    vector<vector<string>> data;
    
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
        string line = "";
        if(v[i][0]=="Enter")
        {
            string id = v[i][1];
            for(int j=0 ; j<data.size() ; j++)
            {
                if(data[j][0]==id)
                {
                    line += data[j][1];
                    break;
                }
            }
            line += "님이 들어왔습니다.";
        }
        else if(v[i][0]=="Leave")
        {
            string id = v[i][1];
            for(int j=0 ; j<data.size() ; j++)
            {
                if(data[j][0]==id)
                {
                    line += data[j][1];
                    break;
                }
            }
            line += "님이 나갔습니다.";
        }
        else
            continue;
        answer.push_back(line);
    }
    return answer;
}
