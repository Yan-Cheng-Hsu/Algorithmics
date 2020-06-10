#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef unsigned long long int ull_int;
typedef signed long long int sll_int;
ull_int rs( ull_int target );
bool isPrime( int target );


class Solution 
{
    public:
        void PN_HW11();
        void PF_HW11();
        void RO_HW11();
};


void Solution::PN_HW11()
{
    vector<ull_int> O;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        ull_int target;
        cin>>target;
        if( target == rs( target ) )
            O.push_back( target );
    }
    for(int i=0;i<O.size();i++)
        cout<<O[i]<<" ";
    


    return;
}


ull_int rs( ull_int target )
{
    vector<ull_int> fl;
    fl.push_back( 1 );

    ull_int bound = int( sqrt( double(target) ) );
    for( ull_int j=bound;j>=2;j-- )
    {
        if( target%j == 0 )
        {
            fl.push_back(j);
            ull_int x = target / j;
            if( x != j )
                fl.push_back(x);
        }
    }

    ull_int sum = 0;
    for(int j=0;j<fl.size();j++)
        sum = sum + fl[j];
    return sum;
}






class Term
{
    public:
        Term( char c , int fre = 0 )
        {
            this -> c = c;
            this -> fre = fre;
        }
    public:
        char c;
        int fre;
};



void Solution::PF_HW11()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<Term> L;
        
        string str;
        cin>>str;

        int index = 0;

        while( index < str.length() )
        {
            bool t = false;

            int j = 0;
            while( j < L.size() )
            {
                if( L[j].c == str[index] )
                {
                    t = true;
                    L[j].fre++;
                    break;
                }
                j++;
            }

            if( !t )
            {
                Term a( str[index] , 1 );
                L.push_back( a );
            }
            index++;
        }


        vector<char> O;
        for(int k=0;k<L.size();k++)
        {
            if( isPrime( L[k].fre ) )
                O.push_back( L[k].c );
        }


        for(int x=0;x<O.size();x++)
        {
            for(int y=x+1;y<O.size();y++)
            {
                if( int( O[x] ) > int( O[y] ) )
                {
                    char temp = O[x];
                    O[x] = O[y];
                    O[y] = temp;
                }
            }
        }


        if( O.size() == 0 )
            cout<<"empty"<<endl;
        else
        {
            for(int k=0;k<O.size();k++)
                cout<<O[k];
            cout<<endl;
        }

    }


    return;
}



bool isPrime( int target )
{
    if( target == 1 )
        return false;
    int bound = int( sqrt( double(target) ) );
    for(int i=bound;i>=2;i--)
    {
        if( target%i == 0 )
            return false;
    }
    return true;
}





void Solution::RO_HW11()
{
    vector<char> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        sll_int t;
        sll_int s;
        cin>>t;
        cin>>s;

        if( t > s )
            O.push_back( '>' );
        else if( t < s )
            O.push_back( '<' );
        else
            O.push_back( '=' );
        
    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;
    


    return;
}




void test()
{
    Solution S;
    S.RO_HW11();
    return;
}


int main(void)
{
    test();
    return 0;
}