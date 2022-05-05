#include<iostream>
using namespace std;

void perm(char s[],int l,int h)
{
    int i;
    if(l==h)
        printf("%s\n",s);
    else{
        for ( i = l; i <= h; i++)
        {
            swap(s[i],s[l]);
            perm(s,l+1,h);
            swap(s[i],s[l]);
        }
        
    }
}

void perm2(char s[],int k)
{
    static int A[10]={0};
    static char res[10];
    int i;

    if(s[k]=='\0')
    {
        res[k]='\0';
        printf("%s\n",res);
    }
    else
    {
        for ( i = 0; s[i] != '\0'; i++)
        {
            if(A[i]==0)
            {
                res[k]=s[i];
                A[i]=1;
                perm2(s,k+1);
                A[i]=0;
            }
        }
        
    }
}

int main()
{
    char X[]="ABC";
    perm2(X,0);

    return 0;
}