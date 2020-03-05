#include<stdio.h>
#include<iostream>
//#include<algorithm>
#include<math.h>
#include<vector.h>
using namespace std;

//PROBLEM:
/*
Write a program to detect an integer n (n > 2) if n is a prime.

if (n is a prime)
    return true;
else 
    return false;

*/

class BigNumber
{
    public:
        BigNumber(string Input)
        {
            vector<int> Bignum;
        }
};


class Solution
{
    public:
        bool PrimeDetection( int n );
};

bool Solution::PrimeDetection( int n )
{
    int Length = int( ceil( sqrt(n/2) )+2) ;

    bool prime[n];
    for(int i=0;i<Length;i++)
        prime[i] = true;
    
    for(int j=2;j<Length;j++)
    {
        if( prime[j] )
        {
            if( (n%j) != 0 )
            {
                for(int k=j;k<Length;k=k+j)
                    prime[k] = false;
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

void test2()
{

}


int main(void)
{

    //test(); 
    system( "pause" );
    return 0;
}


