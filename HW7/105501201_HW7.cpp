#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;

typedef signed long int l_int;
typedef unsigned long long int ull_int;

class Solution
{
    public:
        void T_HW7();
        void UN_HW7();
};


void Solution::T_HW7()
{
    vector<string> O;
    l_int n;
    cin>>n;
    while( n >= 0 )
    {
        string s;
        l_int num = n;
        while( num > 0 )
        {
            int r = num % 3;
            num = num / 3;
            stringstream ss;
            ss<<r;
            string a;
            ss>>a;
            s.insert( 0 , a );
        }

        if( s.length() == 0 )
            s.append( 1 , '0' );
        
        O.push_back(s);

        cin>>n;
        
    }
    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

    return;
}

void Solution::UN_HW7()
{
    vector<ull_int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        vector<ull_int> ugly( num );
        ugly[0] = 1;
        int m2 = 0;
        int m3 = 0;
        int m5 = 0;
        
        int j = 1;
        while( j < num )
        {
            ugly[j] = min( ugly[m2] * 2 , min( ugly[m3] * 3 , ugly[m5] * 5 ) );

            if( ugly[j] == ugly[m2] * 2 ) 
                m2++;
            if( ugly[j] == ugly[m3] * 3 ) 
                m3++;
            if( ugly[j] == ugly[m5] * 5 )
                m5++;
            j++;
        }

        O.push_back( ugly[j-1] );

    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;

    return;
}

void test()
{
    Solution S;
    S.UN_HW7();
    return;
}

int main(void)
{
    test();
    return 0;
}