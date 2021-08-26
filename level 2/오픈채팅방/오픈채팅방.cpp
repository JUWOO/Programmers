#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int num = record.size();
    for(int i=0 ; i<num ; i++)
    {
        vector<string> v;
        string line = "";
        srting word = "";
        line = record[i];
        //한 줄에 대해서 처리
        for(int j=0 ; j<line.size() ; j++)
        {
            if(line[j]==' ')
            {
                v.push_back(word);
                word = "";
            }
            else
                word += line[j];
        }
        for(int k=0 ; k<3 ; k++)
        {
            //k=0일 때,
            if(v[k]=='Enter')
        }
        
    }
    return answer;
}