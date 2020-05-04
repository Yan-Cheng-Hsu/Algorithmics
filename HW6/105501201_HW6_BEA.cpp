#include <iostream>
#include <string.h>
#include<stdio.h>
using namespace std;

#define N 501

typedef unsigned long long int ull_int;
typedef ull_int bignum[N];





class Solution
{
    public:
        void BEA_HW6();
};




void Solution::BEA_HW6()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int exp1;
        cin>>exp1;
        int exp2;
        cin>>exp2;
        
        bignum num1 = {0};
        num1[0] = 2;
        bignum num2 = {0};
        num2[0] = 2;

        int j = 2;
        while( j <= exp1 )
        {
            bignum c = {0};            
            
            int index1 = 0;
            for(int x=N-1;x>=0;x--)
            {
                if(num1[x] != 0)
                {
                    index1 = x + 1;
                    break;
                }
            }

            for(int x=0;x<index1;x++)
            {
                for(int y=0;y<index1;y++)
                    c[x+y] = c[x+y] + num1[x] * num1[y];
            }

            for(int k=1;k<N;k++)
            {
                if( c[k-1] == 0 )
                    break;
                else
                {
                    if( c[k-1] >= 10000 )
                    {
                        int carry = c[k-1]/10000;
                        c[k-1] = c[k-1]%10000;
                        c[k] = c[k] + carry;
                    }
                }
            }

            for(int k=0;k<N;k++)
            {
                if( c[k] == 0 )
                    break;
                num1[k] = c[k];
            }

            j = j*2;
        }
        j = j/2;


        for(int x=0;x<exp1-j;x++)
        {
            bignum c = {0};            
            for(int k=0;k<N;k++)
                c[k] = num1[k]*2;

            
            for(int k=1;k<N;k++)
            {
                if( c[k-1] == 0 )
                    break;
                else
                {
                
                    if( c[k-1] >= 10000 )
                    {
                        int carry = c[k-1]/10000;
                        c[k-1] = c[k-1]%10000;
                        c[k] = c[k] + carry;
                    
                    }
                }
                
                
            }

            for(int k=0;k<N;k++)
            {
                if( c[k] == 0 )
                    break;
                num1[k] = c[k];
            }
        }







        j = 2;
        while( j <= exp2 )
        {
            bignum c = {0};  

            int index2 = 0;
            for(int x=N-1;x>=0;x--)
            {
                if( num2[x] != 0 )
                {
                    index2 = x + 1;
                    break;
                }
            }



            for(int x=0;x<index2;x++)
            {
                for(int y=0;y<index2;y++)
                    c[x+y] = c[x+y] + num2[x] * num2[y];
            }

            for(int k=1;k<N;k++)
            {
                if( c[k-1] == 0 )
                    break;
                else
                {
                
                    if( c[k-1] >= 10000 )
                    {
                        int carry = c[k-1]/10000;
                        c[k-1] = c[k-1]%10000;
                        c[k] = c[k] + carry;
                    }
                }
            }


            for(int k=0;k<N;k++)
            {
                if( c[k] == 0 )
                    break;
                num2[k] = c[k];
            }

            j = j*2;
        }
        j = j/2;
        for(int x=0;x<exp2-j;x++)
        {
            bignum c = {0};            
            for(int k=0;k<N;k++)
                c[k] = num2[k]*2;

            
            for(int k=1;k<N;k++)
            {
                if( c[k-1] == 0 )
                    break;
                else
                {
                
                    if( c[k-1] >= 10000 )
                    {
                        int carry = c[k-1]/10000;
                        c[k-1] = c[k-1]%10000;
                        c[k] = c[k] + carry;
                    
                    }
                }
        
                
            }

            for(int k=0;k<N;k++)
            {
                if( c[k] == 0 )
                    break;
                num2[k] = c[k];
            }

        }


        bignum result = {0};
        
        for(int y=0;y<N;y++)
        {
            if( num1[y] == 0 && num2[y] == 0 )
                break;
            result[y] = num1[y] + num2[y];
        }

        for(int y=1;y<N;y++)
        {
            if( result[y-1] == 0 )
                break;
            else
            {
                if( result[y-1] >= 10000 )
                {
                    int carry = result[y-1]/10000;
                    result[y-1] = result[y-1]%10000;
                    result[y] = result[y] + carry;
                }
            }
        }


        int index = 0;
        for(int y=N-1;y>=0;y--)
        {
            if(result[y]!=0)
            {
                index = y;
                break;
            }
        }


        for(int y=index;y>=0;y--)
        {
            
            if( y != index )
            {
                if(result[y] >= 1000)
                    cout<<result[y];
                else if(  100 <= result[y]  && result[y] < 1000 )
                    cout<<"0"<<result[y];
                else if( 10 <= result[y] && result[y] <100 )
                    cout<<"00"<<result[y];
                else
                    cout<<"000"<<result[y];
                
            }
            else
                cout<<result[y];
            
        }
        cout<<endl;

    }


    return;
}

void test()
{
    Solution S;
    S.BEA_HW6();
    return;
}


int main(void)
{
    test();
    return 0;
}