#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<vector>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;


typedef unsigned long long int ull_int;



class BigNum
{
    friend ostream &operator<<( ostream &o , const BigNum &a );
    public:
        BigNum( string s = "")
        {  
            if( s.length() > 5 )
            {

                int i = s.length() - 5;
                while( i >= 0 )
                {
                    string a = s.substr( i , 5 );
                    ull_int in = atoi( a.c_str() );
                    this -> num.push_back( in );
                    cout<<"in = "<<in<<" "<<",i="<<i<<endl;
                    i = i - 5;
                }
                i = i + 5;
                if( i > 0 )
                {
                    int j = 0;
                    string a = s.substr( j , i-j );
                    ull_int in = atoi( a.c_str() );
                    cout<<"in = "<<in<<endl;
                    this -> num.push_back( in );
                    cout<<"size = "<<this -> num.size()<<endl;
                }

            }

            if( (s.length() > 0) && s.length() <=5 )
            {
                    string a = s.substr( 0 , s.length() );
                    ull_int in = atoi( a.c_str() );
                    this -> num.push_back( in );               
            }

        }
        BigNum operator+( const BigNum &a );
        BigNum operator*( const BigNum &a );
        BigNum operator^( const BigNum &a );
    protected:
        vector<ull_int> num;
};

ostream &operator<<( ostream &o , const BigNum &a )
{
    for(int i=a.num.size()-1;i>=0;i--)
    {
        ostringstream str;
        str<<a.num[i];
        if( i != a.num.size() - 1 )
        {
            if( a.num[i] >= 10000 )
                o<<str.str();
            else if(  1000 <= a.num[i] && a.num[i] < 10000 )
                o<<'0'<<str.str();
            else if(  100 <= a.num[i] && a.num[i] < 1000 )
                o<<"00"<<str.str();
            else if(  10 <= a.num[i] && a.num[i] < 100 )
                o<<"000"<<str.str();
            else if(  1 <= a.num[i] && a.num[i] < 10 )
                o<<"0000"<<str.str();
            else 
                o<<"000000";
        }
        else
            o<<str.str();      

    }
    return o;
}

BigNum BigNum::operator+( const BigNum &a )
{
    BigNum O;

    if( this -> num.size() == 0 && a.num.size() == 0)
        return O;
    if( this -> num.size() == 0 )
    {
        O = a;
        return O;
    }
    if( a.num.size() == 0 )
    {
        O.num = this -> num;
        return O;
    }

    if( this -> num.size() > a.num.size() )
    {
        O.num = this -> num;
        for(int i=0;i<a.num.size();i++)
            O.num[i] = O.num[i] + a.num[i];

        int i = 1; 
        while( i < O.num.size() )
        {
            if( O.num[i-1] >= 100000 )
            {
                ull_int carry = O.num[i-1] / 100000;
                O.num[i-1] = O.num[i-1] % 100000;
                O.num[i] = O.num[i] + carry;

            }
            i++;
        }

        if( O.num[i] >= 100000 )
        {
            O.num.push_back(0);
            i++;
            ull_int carry = O.num[i-1] / 100000;
            O.num[i-1] = O.num[i-1] % 100000;
            O.num[i] = O.num[i] + carry;
        }
        return O;


    }
    else
    {
        O.num = a.num;
        for(int i=0;i< this -> num.size() ;i++)
            O.num[i] = O.num[i] + this -> num[i];

        int i = 1; 
        while( i < O.num.size() )
        {
            if( O.num[i-1] >= 100000 )
            {
                ull_int carry = O.num[i-1] / 100000;
                O.num[i-1] = O.num[i-1] % 100000;
                O.num[i] = O.num[i] + carry;

            }
            i++;
        }

        if( O.num[i] >= 100000 )
        {
            O.num.push_back(0);
            i++;
            ull_int carry = O.num[i-1] / 100000;
            O.num[i-1] = O.num[i-1] % 100000;
            O.num[i] = O.num[i] + carry;
        }
        return O;
    }

}




void test()
{
    BigNum a("123456789101112");
    BigNum b("1000000000000000000000");
    BigNum c("10000000123456789101112");
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    cout<<"a+b="<<a+b<<endl;
    return;
}


int main(void)
{
    string s = "10";
    cout<<"s[0]="<<s[0]<<endl;
    cout<<"s[1]="<<s[1]<<endl;
    test();
    return 0;
}