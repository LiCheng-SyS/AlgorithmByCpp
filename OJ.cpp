#include <iostream>
#include "OJ.h"
#include "vector"
#include <math.h>

#include <string>
#include <algorithm>
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


//​ 输出一个数表示最小值，输出时忽略数字的前导零。 length 表示要d 掉掉位数
// 大致思路 不能交换掉方式 遇到特定情况会出现问题
// 循环的上届条件为当前需要删除的位数 netx 同时维护一个指向 最后一位的地址
// 内层从输入的字符串开始找 如果,前一位大于后一位,重置最后一位的地址指向当前.满足则 跳出,删除当前位数的字符串
// 去除前导0,如果数组的特性 非0 即为真,则判断是否为0如果为0 则直接输出 将标记维护为1  则判断 是否1为来输出没有前导0的部分删除
// 删除完成 本质上就是小数在前 ,大数在后小数在前
// 题目 by 504
int OJ::deletenum(){
    //还没找到能cin 的方法故 用固定的变量代替输出
    string s;
    cin >> s;
    int length=0; //这是要d掉数字的位数
    cin >> length;


   // string s="179566";
   // int length=4;
    for(int i=0;i<length;i++){
          int ind =s.size()-1; //指向字符串的最后一位
          for(int j=1;j<s.size();j++){
               if(s[j-1]>s[j]){
                   //如果当前位大于上一位
                   ind =j-1;
                   break;
                   //他已经违反了规则  则跳出删除
               }
          }
          cout<< ind << endl;
          s.replace(ind,1,""); // 第一个参数为替换下标的位子,recplace的长度,3 长度为""
    }

    //去前导0
    int flag=0;
    for(int i=0;i<s.size();i++){
        if(flag==1){
            cout <<s[i];
        }else if(flag!='0'){
            cout  << s[i];
              flag=1;
        }
    }
    cout << endl;//补一个换行
    return 1;
}



//题目 by 505
//排序:现在有 𝑛 个正整数，将他们连成一排，组成一个最大的整数。 字典序的排序和排序int值踩在很大区别
//前12121后12112
//前9612后1296
bool Max_integer_compare(const string &a,const string &b){
   // *** 重要期待前 加后 的字典序 >后+前的字典序
    string ago =a+b,last=b+a;
    cout << "前"<< ago <<"后" <<  last<<endl;
    return ago >last;
}
int n;
string s[100005];//int 要求的上届
int OJ::Max_integer(){
    cin >> n;
    for(int i=0;i<n;i++){
         cin >> s[i];
    }
    //排序
    cout << "3+n"<<s+n << endl;
    sort(s,s+n,Max_integer_compare);
    for(int i =0;i<n;i++){
        cout <<s[i];
        //从前连接到后
    }
    //缺失endl 则去掉了空格
    cout <<endl;
    return 1;// 语法
}






//506 打热水
//对于每个打水的人来说
struct time_node{
  int cnt_no, time;//打水时间time /--cnt_no 编号
};

bool student_compare(const time_node &node1,const time_node &node2 ){
        //期待的结果为 ,前面的同学 小于后面的同学
    return node1.time<node2.time;
}

time_node student[35];
int rank_time_n=0; //总共多少同学
int OJ::rank_time(){
    for(int i=1;i<rank_time_n;i++)
     {
        //打水时间
        cin >> student[i].time;
        student[i].cnt_no=i;//编号完成
        sort(student+1,student+rank_time_n+1,student_compare);
    }
    //总打水的时间,总等待时间
    int sumtime=0,waittime=0;
    for(int i=0;i<=rank_time_n;i++){
        cout << student[i].cnt_no;
        //总打水时间
        sumtime+=waittime;
        //下一个等待的时间
        waittime+=student[i].time;
    }
    cout << endl;
    cout << double(sumtime/rank_time_n)<<endl;
    return 1;
}



