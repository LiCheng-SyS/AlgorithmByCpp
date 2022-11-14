#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#include "Leetcode.h"

#include "Euler.h"
#include "OJ.h"

#include <bitset>
#include <string>

using namespace std;




struct node{
      int  num , cnt ;//最定义类型 大于号没用
      //==a.num < b.sum  ,但是应该是数字小的在前面
      //但是默认是个大顶队 你如果从小到大排序你就得弄个大于小于反之
      bool operator< (const node &b) const{
          return  this ->num > b.num;  //从大到小????????
      }
};

struct func{
    bool operator() (const node &a, const node &b){
          return a.num < b.num;
    }
};

int main()
{
        //cout  << bitset<sizeof(12)*8>(12) << endl;

       //通过类名调用静态成员函数和非静态成员函数
       //Euler* eule = new Euler;
       //  cout << eule->Euler22() << endl;

       //        OJ* oj1=new OJ;
       //        cout << oj1->fib()<< endl;
       //cout << eule->Leetcode_intToRoman() << endl;
       //通过类名调用静态成员函数和非静态成员函数;


     //  cout <<  Leetcode::IsCardinal() << endl;
     //cout <<  OJ::letter_maximum_range()<< endl;
     //cout << OJ::Max_integer()<<endl;
     //cout << OJ::string_matching()<<endl;
     //cout << OJ::stack_379Wmslog9()<<endl;
     //cout << OJ::map_single_word()<<endl;
     return 0;
}
