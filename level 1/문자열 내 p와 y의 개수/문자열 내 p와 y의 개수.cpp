bool solution(string s)
{
    bool answer = true;
    int yCount = 0;
    int pCount = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s.at(i)=='p' || s.at(i)=='P')
            pCount++;
        else if(s.at(i)=='y' || s.at(i)=='Y')
            yCount++;
    }
    
    if(pCount == yCount)
        answer = true;
    else
        answer = false;

    return answer;
}