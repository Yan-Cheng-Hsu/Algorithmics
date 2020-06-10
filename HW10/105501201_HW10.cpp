#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class Solution
{
    public:
        void LCS_HW10();
        void AP_HW10();
        void BB_HW10();
};



void Solution::LCS_HW10()
{
    vector<int> O;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        string s;
        string t;
        cin>>s;
        cin>>t;
   
        int L[s.length()+1][t.length()+1];

        for(int j=0;j<=s.length();j++)
            L[j][0] = 0;
        for(int j=0;j<=t.length();j++)
            L[0][j] = 0;
        
        for(int x=1;x<=s.length();x++)
        {
            for(int y=1;y<=t.length();y++)
            {
                if( s[x-1] == t[y-1] )
                    L[x][y] = L[x-1][y-1] + 1;
                else  
                    L[x][y] = max( L[x-1][y] , L[x][y-1] );
            }
        }

        O.push_back( L[s.length()][t.length()] );
    }


    

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;


    return;
}



void Solution::AP_HW10()
{
    vector<int> O;
    int n;
    cin>>n;


    for(int i=0;i<n;i++)
    {
        int sum;
        cin>>sum;

        int k = 1;
        
        while( sum >= k*(k+1)/2 )
            k++;
        
        O.push_back( k*(k+1)/2 - sum );
        O.push_back( k );

    }

    for(int i=1;i<O.size();i=i+2)
        cout<<O[i-1]<<" "<<O[i]<<endl;




    return;
}


void Solution::BB_HW10()
{

    vector<int> w;
    for(int i=0;i<24;i++)
    {
        int n;
        cin>>n;
        w.push_back( n );
    }

    vector<int> path( 10 );
    for(int i=0;i<3;i++)
        path[i] = w[i];
    

    for(int i=3;i<6;i++)
    {
        int a[3];
        for(int j=0;j<3;j++)
            a[j] = path[j] + w[i+3*j];
        int temp = min( a[0] , a[1] );
        path[i] = min( temp , a[3] );
    }

    for(int i=6;i<9;i++)
    {
        for(int)
    }






    return;
}


void test()
{
    Solution S;
    S.AP_HW10();
    return;
}


int main(void)
{
    test();
    return 0;
}