#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student
{
private:
    int scores[5];
public:
    void input()
    {
        cin>>scores[0]>>scores[1]>>scores[2]>>scores[3]>>scores[4];
    }

    int calculateTotalScore()
    {
        return scores[0]+scores[1]+scores[2]+scores[3]+scores[4];
    }
};

int main()
{
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++)
    {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++)
    {
        int total = s[i].calculateTotalScore();
        if(total > kristen_score)
        {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}

/**
Other Solutions
class Student {
    int totalScore = 0;
    public:
    void Input() {
        for (int i = 0; i < 5; i++) {
            int x;
            cin >> x;
            totalScore += x;
        }
    }
    int CalculateTotalScore() {
        return totalScore;
    }
};
---------------
class Student {
  public:
    Student() {}

    void Input() {
        for (int i = 0; i < 5; ++i) {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
    }
    int CalculateTotalScore() {
        int res = 0;
        for (int i = 0; i < v.size(); ++i) {
res += v[i];}
        return res;
    }

    vector<int> v;
};
----------------


struct Student {
	int ans;
	void Input() {
		ans = 0;
		for(int i = 0; i < 5; ++ i) {
			int x;
			scanf("%d", &x);
			ans += x;
		}
	}
	int CalculateTotalScore() const {
		return ans;
	}
};

*/

