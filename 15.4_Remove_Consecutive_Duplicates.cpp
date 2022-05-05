#include<bits/stdc++.h>
using namespace std;

void ReomoveConsecutiveDuplicates(char A[],int j=0)
{
    if(A[j]=='\0')
        return;

    if(A[j]==A[j+1]){
        while(A[j]==A[j+1]){
            for(int i=j;A[i]!='\0';i++){
                A[i]=A[i+1];
        }
    }
    }
        ReomoveConsecutiveDuplicates(A,j+1);
}

 void RemoveDuplicates(char A[])
 {
     int i=0;
     for(i=0;A[i]!='\0';i++)
     {
         while(A[i]==A[i+1])
         {
            for(int j=i;A[j]!='\0';j++)
                A[j]=A[j+1];
         }
     }
 }

int main()
{
    char A[]="aaabbbcccxxxxxccccdddd";
    ReomoveConsecutiveDuplicates(A);

    cout<<A<<endl;

    return 0;
}
