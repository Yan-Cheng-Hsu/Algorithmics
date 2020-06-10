#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;

bool check ( string s );
bool isSubsetSum( vector<int> set, int n, int sum ) ;

class Solution
{
    public:
        void KS_HW8();
        void C_HW8();
        void SS_HW8();
};

void Solution::KS_HW8()
{
    vector<int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int capacity;
        cin>>capacity;
        vector<int> W;
        vector<int> P;
        for(int j=0;j<4;j++)
        {
            int w;
            cin>>w;
            W.push_back( w );
        }
        for(int j=0;j<4;j++)
        {
            int p;
            cin>>p;
            P.push_back( p );
        }
     


        //n is items number and in our case is always equal to 5
        //W = capacity
        //P[n+1][capacity+1] = L
        //w[n] = w[x]
        //P[n] = v[n] 
        int L[5][capacity+1];
        for(int j=0;j<=capacity;j++)
            L[0][j] = 0;
        for(int j=0;j<=4;j++)
            L[j][0] = 0;


        for(int x=1;x<=4;x++)
        {
            for(int w=0;w<=capacity;w++)
            {
                if ( W[x-1] <= w )
                    L[x][w] = max( L[x-1][w] , P[x-1] + L[x-1][w - W[x-1]] );
                else
                    L[x][w] = L[x-1][w];
            }
        }

        for(int x=0;x<=4;x++)
        {
            for(int y=0;y<=capacity;y++)
                cout<<L[x][y]<<" ";
            cout<<endl;
        }
        cout<<endl;
        


        O.push_back( L[4][capacity] );
    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

    return;
}


void Solution::C_HW8()
{
    vector<int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int> c;
        int nc;
        cin>>nc;
        int target;
        cin>>target;
        for(int j=0;j<nc;j++)
        {
            int C;
            cin>>C;
            c.push_back( C );
        }

        vector<int> dp(target+1);
        for(int i = 1; i <= target; i++) 
            dp[i] = 2147483647;
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < c.size(); j++)
            {
                if(i >= c[j])
                    dp[i] = min( dp[i], dp[i-c[j]]+1 );
            }
        }

        O.push_back( dp[target] );

    }
    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

    return;
}

void Solution::SS_HW8()
{
    vector<string> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int> I;
        string s;
        cin>>s;
        while( !check( s ) )
        {
            I.push_back( atoi( s.c_str() ) );
            cin>>s;
        }

        int index = 0;
        while(1)
        {
            if( s[index] == ';' )
                break;
            index++;
        }
        
        string s1 = s.substr( 0 , index );
        I.push_back( atoi( s1.c_str() ) );


        s = s.substr( index+1 , s.length() - index - 1 );
        int target = atoi( s.c_str() );



        bool L = isSubsetSum( I , I.size() , target );

        if( L )
            O.push_back( "True" );
        else
            O.push_back( "False" );
        


    }
    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

    return;
}

bool check( string s )
{
    for(int i=0;i<s.length();i++)
    {
        if( s[i] == ';' )
            return true;
    }
    return false;
}



bool isSubsetSum( vector<int> set , int n , int sum ) 
{  
    if (sum == 0) 
        return true; 
    if (n == 0 && sum != 0) 
        return false; 
  
    if (set[n-1] > sum) 
        return isSubsetSum(set, n-1, sum); 
    return isSubsetSum(set, n-1, sum) ||  isSubsetSum(set, n-1, sum-set[n-1]);
}




void test()
{
    //cout<<"Input :"<<endl;
    //cout<<"The Sample Ouput Should Be: "<<endl;
    Solution S;
    S.KS_HW8();
    return;
}


int main(void)
{
    //cout<<"The Sample Input : "<<endl;
    test();
    return 0;
}




  