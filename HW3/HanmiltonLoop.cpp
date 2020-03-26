#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

class Solution
{
    public:
        void Input();
        void Preprocessing();
        bool HamiltonLoop();
    private:
        vector<int> input;
        int size;
        bool **adj;
        int *Solution;
};


void Solution::Input()
{
    int n; 
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int> IndexList;
        string s;
        cin>>s;
        
        for(int j=1;j<s.length();j++)
        {
            if( (int(s[j]>=48)) && (int(s[j]<=57)) && ( (int(s[j-1]<48)) || (int(s[j-1]>57)) ) )
                IndexList.push_back( j );
            if( (int(s[j-1]>=48)) && (int(s[j-1]<=57)) && ( (int(s[j]<48)) || (int(s[j]>57)) ) )
                IndexList.push_back( j-1 );
        }
        for(int k=0;k<IndexList.size();k=k+2)
        {
            int sum = 0;
            for(int x=IndexList[k];x<=IndexList[k+1];x++)
                sum = sum + ( int( s[x] ) - 48 ) * pow( 10.0 ,  IndexList[k+1] - x  );

            this -> input.push_back( sum - 1 );
        }
    }

    return;
}

void Solution::Preprocessing()
{
    //Initialization of size of adjancency matrix and Solution matrix
    int max = 0;
    for(int i=0;i<input.size();i++)
    {
        if( input[i] > max )
            max = input[i];
    }
    this -> size = max + 1;


    //Initialization of adjancency matrix
    this -> adj = new bool*[size];
    for(int i=0;i<size;i++)
        adj[i] = new bool[size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            adj[i][j] = false;
    }
    
    for(int i=0;i<input.size();i=i+2)
        adj[input[i]][input[i+1]] = true;


    //Initialization of Solution
    this -> Solution = new int[size];
    for(int i=0;i<size;i++)
        Solution[i] = -1;
    


    return;
}





void test()
{
    Solution S;
    S.Input();
    S.Preprocessing();

    return;
}

int main(void)
{
    test();
    return 0;
}