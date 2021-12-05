#include <iostream>
#include "vector"
#include "matrix.h"
using namespace std;

vector<vector<int> > RandomMatrix(int n, int m)
{
    vector< vector<int> > res(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[i].push_back(rand()%10);
    return res;
}



int main() {
    //cout << a << endl << b << endl;
    cout << "Commands: " << endl;
    cout << "e - exit" << endl;
    cout << "m+m (+enter sizes of the first matrix) (+enter all matrix) (+enter sizes of the second matrix) (+enter all matrix) - plus two matrix" << endl;
    cout << "m*m (+enter sizes of the first matrix) (+enter all matrix) (+enter sizes of the second matrix) (+enter all matrix) - multiplication two matrix" << endl;
    cout << "mt (+enter sizes of matrix) (+enter all matrix) - transparent" << endl;
    cout << "m*a (+enter sizes of matrix) (+enter all matrix) (+enter number) - multiplication matrix" << endl;
    cout << "m^a (+enter sizes of matrix) (+enter all matrix) - pow()" << endl;
    cout << "dm (+enter sizes of matrix) (+enter all matrix) - determinant of the Matrix" << endl;


    string com;
    cin >> com;
    while(com != "e")
    {
        if(com == "m+m")
        {
            int m,n;
            cin >> n >> m;
            Matrix<int> a(n,m);
            cin >> a;
            cin >> n >> m;
            Matrix<int> b(n,m);
            cin >> b;
            try
            {
                cout << " " << (a+b) << endl;
            }
            catch (const char* msg)
            {
                cerr << "Exception caught: " << msg << endl;
            }
        }
        else if(com == "m*m")
        {
            int m,n;
            cin >> n >> m;
            Matrix<int> a(n,m);
            cin >> a;
            cin >> n >> m;
            Matrix<int> b(n,m);
            cin >> b;
            try
            {
                cout << " " << (a*b) << endl;
            }
            catch (const char* msg)
            {
                cerr << "Exception caught: " << msg << endl;
            }
        }
        else if(com == "mt")
        {
            int m,n;
            cin >> n >> m;
            Matrix<int> a(n,m);
            cin >> a;
            try
            {
                cout << " " << (a.transparent()) << endl;
            }
            catch (const char* msg)
            {
                cerr << "Exception caught: " << msg << endl;
            }
        }
        else if(com == "m*a")
        {
            int m,n;
            cin >> n >> m;
            Matrix<int> a(n,m);
            cin >> a;
            cin >> n;
            try
            {
                cout << " " << (a*n) << endl;
            }
            catch (const char* msg)
            {
                cerr << "Exception caught: " << msg << endl;
            }
        }
        else if(com == "m^a")
        {
            int m,n;
            cin >> n >> m;
            Matrix<double> a(n,m);
            cin >> a;
            cin >> n;
            try
            {
                cout << " " << (a^n) << endl;
            }
            catch (const char* msg)
            {
                cerr << "Exception caught: " << msg << endl;
            }
        }
        else if(com == "dm")
        {
            int n;
            cout << "Enter one number - size of matrix: ";
            cin >> n;
            Matrix<int> a(n,n);
            cin >> a;
            try
            {
                cout << " " << (a.determinant()) << endl;
            }
            catch (const char* msg)
            {
                cerr << "Exception caught: " << msg << endl;
            }
        }




        cin >> com;
    }

    return 0;
}
