#include<cstdio>
#include<iostream>
//#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

//PROBLEM:
/*
Write a program to determine whether an integer n (n > 2) is a prime.

if (n is a prime)
    return true;
else 
    return false;

*/



/*

Pseudo code for Solution to Prime Detection

Input: an arbitrary integer n (n > 2) 
Output: true or false





*/


class Solution
{
    public:
        bool PrimeDetection( int n );
};

bool Solution::PrimeDetection( int n )
{
    int Length = int( ceil( sqrt( float(n/2) ) )+2) ;

    bool numList[n];
    for(int i=0;i<Length;i++)
        numList[i] = true;
    
    for(int j=2;j<Length;j++)
    {
        if( numList[j] )
        {
            if( (n%j) != 0 )
            {
                for(int k=j;k<Length;k=k+j)
                    numList[k] = false;
            }
            else return false;
        }
    }

    return true;

}


void test()
{
    cout<< "plz input a number: ";
    int n;
    cin>>n;
    Solution S;
    if( S.PrimeDetection( n ) )
        cout<<"n is a prime."<<endl;
    else
        cout<<" n is not a prime. "<<endl;
}



int main(void)
{

    test(); 
    system( "pause" );
    return 0;
}


