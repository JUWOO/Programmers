#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n)
{
	string answer = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] + n > 'z')
				s[i] = s[i] - 'z';
			answer.push_back(s[i] + n);
		}

		else if(s[i]>='A' && s[i]<='Z')
			{
				if (s[i] + n > 'Z')
					s[i] = s[i]  - 'Z';
				answer.push_back(s[i]+n);
			}

		else if (s[i] == ' ')
		{
			answer.push_back(s[i]);
		}
		
	}


	return answer;
}


int main()
{
	string ans = solution( "ABgt", 1 );
	cout << ans << endl;
	
}

