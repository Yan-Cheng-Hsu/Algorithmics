#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;




class Solution
{
    public:
        void AA_HW9();
        void AA_HW9_1();
        void B_HW9();
        void C_HW9();
};
int sumup( int n );



void Solution::AA_HW9()
{
    vector<string> O;


    string s;
    string t;
    while( cin>>s && cin>> t )
    {
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
        if( L[s.length()][t.length()] == s.length() )
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    





    return;
}



void Solution::AA_HW9_1()
{
    vector<string> O;


    string s;
    string t;
    while( cin>>s && cin>> t )
    {

        int i = 0;
        int j = 0;

        while( i < s.length() && j < t.length() )
        {

            if( s[i] == t[j] )
            {
                i++;
                j++;
            }
            else
                j++;
        }


        if( i == s.length() )
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    





    return;
}




void Solution::B_HW9()
{
    vector<int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int> b;
        int num;
        cin>>num;
        for(int j=0;j<num;j++)
        {
            int B;
            cin>>B;
            b.push_back( B );
        }





        int sum = 0;
        for(int j=0;j<b.size();j++)
            sum = sum + b[j];



        int avg = sum / b.size();


        int loss = 0;
        
        for(int j=0;j<b.size();j++)
            loss = abs( avg - b[j] )  + loss;
    
        

        O.push_back( loss / 2 );



    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;


    return;
}




void Solution::C_HW9()
{
    vector<int> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        int len;
        cin>>len;
        int target;
        cin>>target;


        for(int i=0;i<2*len-1;i++)
        {
            int k = len - abs( i - len + 1 );
            for(int j=0;j<k;j++)
            {
                target--;
                if( target == 0 )
                {
                    int o = (k+1)/2 - abs( (j*2-k+1)/2 );
                    O.push_back( o ); 
                    break;
                }

            }
        }

    }
    
    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;


    return;
}





void test()
{
    Solution S;
    S.AA_HW9_1();
    return;
}


int main(void)
{
    test();
    return 0;
}