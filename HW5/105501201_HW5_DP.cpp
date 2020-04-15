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


        b4etIndexList.push_back( 0 );
        for(int j=1;j<etIndex;j++)
        {
            if( (str[j] == '+') || (str[j] == '-') )
                b4etIndexList.push_back(j);
        }


        afetIndexList.push_back( etIndex + 1 );
        for(int j=etIndex+2;j<str.length();j++)
        {
            if( (str[j] == '+') || (str[j] == '-') )
                afetIndexList.push_back(j);
        }


        double coef = 0;
        double constant = 0;

        for(int j=0;j<b4etIndexList.size();j++)
        {
            if( j == 0 && j == b4etIndexList.size() - 1 )
            {
                if( str[0] == '-' )
                {
                    if( str[etIndex-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=1;k<etIndex-1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 2 - k ); 


                        coef = coef - sum;
                        if( etIndex-1 == 1 )
                            coef = coef - 1;


                    }
                    else
                    {
                        double sum = 0;
                        for(int k=1;k<etIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 1 - k );
                        constant = constant - sum; 
                    }
                }
                else
                {
                    if( str[etIndex-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=0;k<etIndex - 1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 2 - k ); 
                        coef = coef + sum;
                        if( etIndex-1 == 0 )
                            coef = coef + 1;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=0;k<etIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 1 - k );
                        constant = constant + sum; 
                    }

                }
            }           


            else if( j == 0 )
            {
                if( str[0] == '-' )
                {
                    if( str[b4etIndexList[1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=1;k<b4etIndexList[1]-1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[1] - 2 - k ); 
                        coef = coef - sum;

                        if( b4etIndexList[1]-1 == 1 )
                            coef = coef - 1;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=1;k<b4etIndexList[1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[1] - 1 - k );

                        constant = constant - sum; 
                    }
                }
                else
                {
                    if( str[b4etIndexList[1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=0;k<b4etIndexList[1]-1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[1] - 2 - k ); 


                        if( b4etIndexList[1]-1 == 0 )
                            coef = coef + 1;
                        coef = coef + sum;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=0;k<b4etIndexList[1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[1] - 1 - k );
                        constant = constant + sum; 
                    }

                }
            }
            else if( j == (b4etIndexList.size() - 1) )
            {
                if( str[b4etIndexList[j]] == '-' )
                {
                    if( str[etIndex-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k < (etIndex-1);k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 2 - k ); 
                        
                        if( etIndex-1 == b4etIndexList[j]+1 )
                            coef = coef - 1;
                        coef = coef - sum;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k<etIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 1 - k );
                        constant = constant - sum; 
                    }
                }
                else
                {
                    if( str[etIndex-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k < (etIndex-1);k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 2 - k ); 
                        coef = coef + sum;

                        if( b4etIndexList[j]+1 == etIndex-1 )
                            coef = coef + 1;


                    }
                    else
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k<etIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , etIndex - 1 - k );
                        constant = constant + sum; 
                    }

                }
            }
            else
            {
                if( str[b4etIndexList[j]] == '-' )
                {
                    if( str[b4etIndexList[j+1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k < (b4etIndexList[j+1]-1);k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[j+1]- 2 - k ); 


                        if( b4etIndexList[j]+1 == b4etIndexList[j+1]-1 )
                            coef = coef - 1;
                        coef = coef - sum;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k<b4etIndexList[j+1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[j+1] - 1 - k );
                        constant = constant - sum; 
                    }
                }
                else
                {
                    if( str[b4etIndexList[j+1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k < (b4etIndexList[j+1]-1);k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[j+1]- 2 - k ); 
                        coef = coef + sum;

                        if( b4etIndexList[j]+1 == b4etIndexList[j+1]-1 )
                            coef = coef + 1;

                    }
                    else
                    {
                        double sum = 0;
                        for(int k=b4etIndexList[j]+1;k<b4etIndexList[j+1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , b4etIndexList[j+1] - 1 - k );
                        constant = constant + sum; 
                    }
                }

            }

            
        }
       

        for(int j=0;j<afetIndexList.size();j++)
        {
            if( (j == 0 ) && ( j == afetIndexList.size()-1 ) )
            {
                if( str[afetIndexList[0]] == '-' )
                {
                    if( str[LastIndex] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0]+1;k<LastIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - 1 - k ); 
                        coef = coef + sum;

                        if( afetIndexList[0]+1 == LastIndex )
                            coef = coef + 1;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0]+1;k<LastIndex+1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - k );
                        constant = constant + sum; 
                    }
                }
                else
                {
                    if( str[LastIndex] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0];k<LastIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - 1 - k ); 
                        coef = coef - sum;
                        if( afetIndexList[0] == LastIndex )
                            coef = coef - 1;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0];k<LastIndex+1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - k );
                        constant = constant - sum; 
                    }

                }
            }

            else if( j == 0 )
            {
                if( str[afetIndexList[0]] == '-' )
                {
                    if( str[afetIndexList[1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0]+1;k<afetIndexList[1]-1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[1] - 2 - k ); 

                        if( afetIndexList[0]+1 == afetIndexList[1]-1 )
                            coef = coef + 1;
                        coef = coef + sum;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0]+1;k<afetIndexList[1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[1] - 1 - k );
                        constant = constant + sum; 
                    }
                }
                else
                {
                    if( str[afetIndexList[1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0];k<afetIndexList[1]-1;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[1] - 2 - k ); 
                        
                        if( afetIndexList[0] == afetIndexList[1]-1 )
                            coef = coef - 1;

                        coef = coef - sum;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[0];k<afetIndexList[1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[1] - 1 - k );
                        constant = constant - sum; 
                    }

                }
            }
            else if( j == (afetIndexList.size() - 1) )
            {
                if( str[afetIndexList[j]] == '-' )
                {
                    if( str[LastIndex] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k < LastIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - 1 - k ); 
                        coef = coef + sum;

                        if( afetIndexList[j]+1 == LastIndex )
                            coef = coef + 1;


                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k<str.length();k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - k );
                        constant = constant + sum; 
                    }
                }
                else
                {
                    if( str[LastIndex] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k < LastIndex;k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - 1 - k ); 
                        coef = coef - sum;
                        if( afetIndexList[j]+1 == LastIndex )
                            coef = coef - 1;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k<str.length();k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , LastIndex - k );
                        constant = constant - sum; 
                    }

                }
            }
            else
            {
                if( str[afetIndexList[j]] == '-' )
                {
                    if( str[afetIndexList[j+1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k < (afetIndexList[j+1]-1);k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[j+1]- 2 - k ); 
                        coef = coef + sum;
                        if( afetIndexList[j]+1 == afetIndexList[j+1]-1 )
                            coef = coef + 1;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k<afetIndexList[j+1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[j+1] - 1 - k );
                        constant = constant + sum; 
                    }
                }
                else
                {
                    if( str[afetIndexList[j+1]-1] == 'x' )
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k < (afetIndexList[j+1]-1);k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[j+1]- 2 - k ); 
                        coef = coef - sum;
                        if( afetIndexList[j]+1 == afetIndexList[j+1]-1 )
                            coef = coef - 1;
                    }
                    else
                    {
                        double sum = 0;
                        for(int k=afetIndexList[j]+1;k<afetIndexList[j+1];k++)
                            sum = sum + ( int(str[k]) - 48 ) * pow( 10.0 , afetIndexList[j+1] - 1 - k );
                        constant = constant - sum; 
                    }
                }

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
    test();

    return 0;
}