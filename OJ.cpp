#include <iostream>
#include "OJ.h"
#include "vector"
#include <math.h>
using namespace std;



bool is_prime(int n){
    if(n==1)return false;//取反为和数true 为质数
    else
        {
        for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)return false;
        return true;
  }
}

long long OJ::fib() {
     long long  fibarr[105]={1,1},ans=3,val=0,fin;
      for(int i=2; i<=100; i++){
        fibarr[i]=fibarr[i-1]+fibarr[i-2];
        //cout << fibarr[i]<< endl;
      }
      for(int j=2;j<=100;j++){
             if(!is_prime(fibarr[j])){
                  //cout << fibarr[j]<< endl;
                  val++;
                  //cout << fibarr[j]<<endl;
                  if(val==ans){
                        fin= fibarr[j];
                  }
             }

        }
      return fin;
 }


int OJ::letter_maximum_range(){
   //记录上一个 元音字母的位置,指向当前元音的位子  算一下距离, neext 再将last指向当前位子 不断计算
     char str[105]; //​ 共一行，一个长度不大于 100 的字符串。
     cin >> str;
     int  first =-1,ans=99999; //有他说是最近 ,我将它初始化位比较大的值
     for(int i=0;i<=str[0];i++){
         if(str[i]=='A'||str[i]=='E'|str[i]=='I'||str[i]=='O'||str[i]=='U'){
               if(str[i]==-1){
                    first=i;
               }else{
                    ans=max(ans, i-first);  //以保证是上一个字母的位子
                    first=i;
               }
         }
     }
     cout << ans <<endl;
}
