#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m){
	while(m!=0){
		int r = n%m;
		n= m;
		m= r;
	}
	return n;
}

int lcm(int n, int m){
    return n * m / gcd(n,m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));
    
    return answer;
}