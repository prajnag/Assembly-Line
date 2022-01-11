#include<stdio.h>
#include<stdlib.h>
int min(int a, int b)
{
    return a < b ? a : b; 
}
void assembly()
{
    int m,n;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[n][m+2];
    int transfer[2*(n-1)][m-1];
    int station_number[6];
    int num=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m+2; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<2*(n-1); i++)
    {
        for(int j=0; j<m-1; j++)
        {
            scanf("%d", &transfer[i][j]);
        }
    }
    int dp[n][m+1];
    int l[n][m];
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m+1; j++) 
        {
            dp[i][j]=0;
        }
    }

    for(int i=0; i<n; i++)
    {
        dp[i][0]=arr[i][0]+arr[i][2];
        l[i][0]=dp[i][0];
    }
    int temp;
    for(int j=1; j<m; j++) 
    {
        for(int i=0; i<n;i++) 
        {
            if(i==0)
            {
                if(dp[i][j-1]<=dp[i+1][j-1]+transfer[i+1][j-1])
                {
                    l[i][j]=i+1;
                    temp=dp[i][j-1];

                }
                else
                {
                    l[i][j]=i+2;
                    temp=dp[i+1][j-1]+transfer[i+1][j-1];
                }
            }
            else if(i==n-1)
            {
                if(dp[i][j-1]<=dp[i-1][j-1]+transfer[i-1][j-1])
                {
                    l[i][j]=i+1;
                    temp=dp[i][j-1];

                }
                else
                {
                    l[i][j]=i;
                    temp=dp[i-1][j-1]+transfer[i-1][j-1];
                }
            }
            else
            {
                if(dp[i][j-1]<=dp[i-1][j-1]+transfer[i][j-1] && dp[i][j-1]<=dp[i+1][j-1]+transfer[i+2][j-1] )
                {
                   
                    l[i][j]=i+1;
                    temp=dp[i][j-1];
                }
                else
                {
                    if(dp[i-1][j-1]+transfer[i][j-1]<=dp[i+1][j-1]+transfer[i+2][j-1])
                    {
                        l[i][j]=i;
                        temp=dp[i-1][j-1]+transfer[i][j-1];
                    }
                    else
                    {
                    l[i][j]=i+2;
                    temp=dp[i+1][j-1]+transfer[i+2][j-1];
                    }
                    
                }    
            }
            dp[i][j]=temp+arr[i][j+2];
        }
    }
    for(int i=0; i<n; i++)
    {
        dp[i][m]=dp[i][m-1]+arr[i][1];
    }
    int final=1000000;
    int lfinal;
    for(int i=0; i<n; i++)
    {
        if(dp[i][m]<final)
        {
            final=dp[i][m];
            lfinal=i;
        }

    }
    printf("%d\n", final);
    int i=lfinal;
    int path[m];
    int pathnum=0;
    path[pathnum++]=i+1;
    for(int j=m-1; j>=1; j--)
    {
        path[pathnum++]=l[i][j];
        i=l[i][j]-1;
    }
    for(int i=m-1; i>=0; i--)
    {
        printf("%d\n", path[i]);
    }

}
int main()
{
    assembly();
    return 0;
}
