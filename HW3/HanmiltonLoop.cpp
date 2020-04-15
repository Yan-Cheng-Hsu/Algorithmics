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
        bool *visit;
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
    {
        adj[input[i]][input[i+1]] = true;
        adj[input[i+1]][input[i]] = true;
    }

    //Initialization of Solution matrix

    this -> Solution = new int[size];
    for(int i=0;i<size;i++)
        Solution[i] = -1;
    
    //Initialization of visit matrix

    this -> visit = new bool[size];
    for(int i=0;i<size;i++)
        visit[i] = false;
    

    return;
}


bool Solution::HamiltonLoop()
{
    int k = 1;
    //Start from Vertex 0 to visit
    //Actually, starting point makes no difference to whether there is a H loop.
    this -> Solution[0] = 0;
    this -> visit[Solution[0]] = true;

    while( k > 0 )
    {
        Solution[k] = Solution[k] + 1;
        while( k < size )
        {
            if( ( !visit[Solution[k]] ) && ( adj[Solution[k-1]][Solution[k]] ) )
                break;
            else 
                Solution[k] = Solution[k] + 1;
        }

        if( ( Solution[k] < size ) && ( k == size - 1 ) && (adj[Solution[k]][Solution[0]]) )
            break;
        else if( ( k < size ) && ( Solution[k] < size ) )
        {
            visit[Solution[k]] = true;
            k = k + 1;
        }
        else
        {
            Solution[k] = -1;
            k = k - 1;
            visit[Solution[k]] = false;
        }
    }

    if( k == ( size - 1 ) )
        return true;
    else 
        return false;
}




void test()
{
    vector<string> Output;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Solution S;
        S.Input();
        S.Preprocessing();
        if( S.HamiltonLoop() )
            Output.push_back( "True" );
        else
            Output.push_back( "False" );
        
    }

    for(int i=0;i<Output.size();i++)
        cout<<Output[i]<<endl;
    

    return;
}

int main(void)
{
    test();
    return 0;
} 
