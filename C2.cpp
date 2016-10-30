#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int fac[1010],top;
void resolve(int a){
    top=0;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            fac[top++]=i;
            while(a%i==0) a/=i;
        }
    }
    if(a>1) fac[top++]=a;
}
int power(int p){
    int ans=1,temp=2;
    while(p){
        if(p&1) ans=ans*temp;
        temp=temp*temp;
        p>>=1;
    }
    return ans;
}
int main()
{
    int x,y;
    while(cin>>x>>y){
        if(y%x){  printf("0\n");  continue; }
        int w=y/x;
        resolve(w);
        printf("%d\n",power(top));
    }
    return 0;
}
