#include <string>
#include <vector>

using namespace std;

#define START 0
#define END 1

int process[2000][2];

int solution(vector<string> lines) 
{
    int n = lines.size();
    for (int i=0; i<n; ++i) 
    {
        const string& str = lines[i];
		string time = str.substr(11, 12);
		string duration = str.substr(24);
		duration.erase(duration.end() - 1);

		int end = (((stoi(time.substr(0, 2)) * 3600) +
        		    (stoi(time.substr(3, 2)) * 60) +
        		     stoi(time.substr(6, 2))) * 1000)
				    + stoi(time.substr(9,3));
		int dur = (stod(duration) * 1000);

        process[i][START] = end - dur + 1;
        process[i][END] = end;
	}

    int answer = 0;
	for (int i=0; i<n; ++i) 
    {
		int start = process[i][END];
		int end = process[i][END] + 999;
		int cnt = 0;

		for (int j=i; j<n; ++j) 
        {
			if (process[j][START] <= end)
            {
                cnt++;
            }
		}
		answer = max(answer, cnt);
	}
    
    return answer;
}