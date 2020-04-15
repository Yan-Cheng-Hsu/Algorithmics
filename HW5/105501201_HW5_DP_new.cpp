#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


class Solution
{
    public:
        void DP_HW5();
    
};

void Solution::DP_HW5()
{
    vector<string> O;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;

        int LastIndex = str.length() - 1;
        int etIndex;
        
        vector<int> b4etIndexList;
        vector<int> afetIndexList;

        for(int j=0;j<str.length();j++)
        {
            if( str[j] == '=' )
            {
                etIndex = j;
                break;
            }
        }


        int k = 1;
        double coef = 0;
        double constant = 0;

        int startIndex = 0;
        if(  )
        
        while( k < str.length() )
        {
            if( (str[k] == 'x') && (str[k-1] == '-') )
            {
                if( k < etIndex )
                    coef = coef - 1;
                else
                    coef = coef + 1;
                k++;
                continue;
            }

            if( (str[k] == 'x') && (str[k-1] == '+') )
            {
                if( k < etIndex )
                    coef = coef + 1;
                else
                    coef = coef - 1;
                k++;
                continue;
            }





            int startIndex = k;
            while( ( str[k] >= 48 ) || ( str[k] <=57 ) )
                k++;
            if( startIndex == 0 )
            {

            }

        }   

        










        if( coef == 0 && constant == 0)
            O.push_back( "IDENTITY" );
        else if( coef == 0 && constant !=0 )
            O.push_back( "IMPOSSIBLE" );
        else
        {
            double a = floor(-constant / coef);
            ostringstream ss;
            ss<<int(a);
            O.push_back( ss.str() );
        }

        

    }

    for(int i=0;i<O.size();i++)
        cout<<O[i]<<endl;
    



    return;
}


void test()
{
    Solution S;
    S.DP_HW5();
    return;
}

int main(void)
{
    //test();
    string s = "123456789";
    double a = strtod( s[1] , s[4] );
    cout<<a<<endl;


    return 0;
}