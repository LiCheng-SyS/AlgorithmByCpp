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

