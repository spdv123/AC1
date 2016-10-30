#include<iostream>
#include<string.h>
using namespace std;
int main()
{
        int nom[10]={9,1,3,3,4,5,9,7,8,9};
        int add[10]={8,7,0,9,0,9,8,0,0,0};
        int dec[10]={0,0,0,0,0,0,5,0,9,3};
        int num[100],num1[100],num2[100],num3[100],max=0,max1,flag=0;
        char s[100];
        int n,i,j,k,d;
        cin>>n;
        getchar();
        for(i=0;i<n;i++)
        {
                gets(s);
                max1=0;
                for(j=0;j<strlen(s);j++)
                {
                        num[j]=s[j]-'0';
                        num1[j]=num[j];
                        num2[j]=num[j];
                        num3[j]=num[j];
                }
                for(j=0;j<strlen(s);j++)
                {        for(k=0;k<strlen(s)-1;k++)
                        num3[k]=num[k];
                        if(nom[num[j]]>num[j])
                        {
                                num3[j]=nom[num[j]];

                        }
                        else
                        {
                                num3[j]=num[j];}
                        for(k=0;k<strlen(s);k++)
                                max1=max1*10+num3[k];
                        if(max1>max)
                        max=max1;
                        max1=0;
                }
                max1=0;
                for(j=0;j<strlen(s);j++)
                {
                        for(k=0;k<strlen(s)-1;k++)
                        num2[k]=num1[k];

                                for(k=strlen(s)-1;k>0;k--)
                                {
                                        if(dec[num1[k]]==0)
                                                k--;
                                        if(dec[num1[k]]!=0)
                                        {        num2[k]=dec[num1[k]];
                                        flag=1;
                                        break;
                                        }
                                }
                                if(flag==1)
                                {
                                        if(add[num1[j]]>num1[j])
                                        {
                                        num2[j]=add[num1[j]];
                                        }
                                        else
                                                num2[j]=num1[j];
                                }

                                for(d=0;d<strlen(s);d++)
                                max1=max1*10+num2[d];
                                if(max1>max)
                                max=max1;
                                max1=0;
                }
                        max1=0;
                        flag=0;

                        cout<<max<<endl;
                                max=0;
        }



        return 0;
}
