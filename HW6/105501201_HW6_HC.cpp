#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
using namespace std;

class Term
{
    public:
        Term( char c = 'a' , int fre = 1 )
        {
            this -> fre = fre;
            this -> c = c;
        }
    public:
        int fre;
        char c;
        string out;
        //int fin;
    
};


class Solution
{
    public:
        void HC_HW6();
        //void Sort( vector<Term> &a );
        //bool Compare( char a , vector<Term> b );
};






void Solution::HC_HW6()
{
    string str;
    cin>>str;

    vector<Term> t;
    int x = 0;

    while( x < str.length() )
    {
        int counter = -1;

        for(int i=0;i<t.size();i++)
        {
            if( t[i].c == str[x] )
            {
                counter = i;
                break;
            }
        }



        if( counter == -1 )
        {
            Term a(str[x]);
            t.push_back( a );
        }
        else
            t[counter].fre++;
        x++;
    }


    for(int i=0;i<t.size();i++)
    {
        for(int j=i+1;j<t.size();j++)
        {
            if( t[i].fre < t[j].fre )
            {
                Term temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    int index = 0;
    while( index <  t.size() - 1 )
    {
        int sum = 0;
        for(int i=index+1;i<t.size();i++)
            sum = sum + t[i].fre;
        
        if( t[index].fre < sum )
        {
            t[index].out.append( 1 , '0' );
            for(int i=index+1;i<t.size();i++)
                t[i].out.append( 1 ,'1' );
        }
        else
        {
            t[index].out.append( 1 , '1' );
            for(int i=index+1;i<t.size();i++)
                t[i].out.append( 1 , '0' );   
        }
        index++;

    }


    int lastIndex = t.size()-1; 
    int strlindex = t[lastIndex].out.length()-1;

    if( int( t[lastIndex].out[strlindex] ) < int( t[lastIndex-1].out[strlindex] ) )
    {
        Term temp = t[lastIndex];
        t[lastIndex] = t[lastIndex-1];
        t[lastIndex-1] = temp;
    }

    /*for(int i=0;i<t.size();i++)
    {
        for(int j=i+1;j<t.size();j++)
        {
            if( atoi( t[i].out.c_str() ) > atoi( t[j].out.c_str() ) )
            {
                Term temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }*/


    for(int i=0;i<t.size();i++)
        cout<<t[i].c<<':'<<t[i].out<<endl;

    
    return;

}



void test()
{
    Solution S;
    S.HC_HW6();
    return;
}

int main(void)
{
    test();
    return 0;
}