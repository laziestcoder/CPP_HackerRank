#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/// Edit Here

///type operator sign (parameters) { /*... body ...*/ }

class Matrix
{
public:
    vector<vector<int>>a;
    Matrix & operator + (const Matrix &m)
    {
        for(int i=0; i<m.a.size(); i++)
        {
            for(int j=0; j<m.a[0].size(); j++)
            {
                this->a[i][j] = this->a[i][j]+m.a[i][j];
            }
        }
        return *this;
    }
};

///Editable Ends
int main ()
{
    int cases,k;
    cin >> cases;
    for(k=0; k<cases; k++)
    {
        Matrix x;
        Matrix y;
        Matrix result;
        int n,m,i,j;
        cin >> n >> m;
        for(i=0; i<n; i++)
        {
            vector<int> b;
            int num;
            for(j=0; j<m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for(i=0; i<n; i++)
        {
            vector<int> b;
            int num;
            for(j=0; j<m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x+y;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/**
Problem Setter's code:

// overloading operators example
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    public:
        vector<vector<int> > a;
        Matrix operator + (const Matrix&);
};

Matrix Matrix::operator+ (const Matrix& param) {
    Matrix temp;
    int n = a.size(),i,j;
    int m = a[0].size();
    for(i=0;i<n;i++) {
        vector<int> b;
        for(j=0;j<m;j++) {
            b.push_back(param.a[i][j]+a[i][j]);
        }
        temp.a.push_back(b);
    }
    return temp;
}

int main () {
    int cases,k;
    cin >> cases;
    for(k=0;k<cases;k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n,m,i,j;
        cin >> n >> m;
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x+y;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cout << result.a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
*/
