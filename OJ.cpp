#include <iostream>
#include "OJ.h"
#include <math.h>

#include <string>
#include <algorithm>


#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

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






//506 打热水 //​ 第一行输出排队顺序。
//第二行输出平均等待时间，结果保留两位小数。
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
        sort(student+1,student+rank_time_n+1,student_compare);//从第一个同学开始排
    }
    //总打水的时间,总等待时间
    int sumtime=0,waittime=0;//这是等了多久 是个累加变量
    for(int i=0;i<=rank_time_n;i++){
        cout << student[i].cnt_no;
        //总打水时间 第i同学的等待时间
        sumtime+=waittime;
        //下一个等待的时间
        waittime+=student[i].time;
    }
    cout << endl;
    cout << double(sumtime/rank_time_n)<<endl;
    //总等待时间/总人数
    return 1;
}


//​ 输出所有人过桥的最短时间。508
 int oj_508_n,oj_508num[1005],oj508_ans;
int OJ::river_crossing(){
    cin >> oj_508_n;
    for(int i=0;i<oj_508_n;i++){
         cin >> oj_508num[i];
    }
    sort(oj_508num,oj_508num+oj_508_n);
    //从最慢的开始跑,每次跑两个人

    for(int i=oj_508_n-1;1;i-=2){
        if(i==0){
           oj508_ans+=oj_508num[0];//一个人通过
           break;
        }else if(i==1){
            oj508_ans+=oj_508num[1];//两个人通过
              break;
        }else if(i==2){
            // 三个人通过
           oj508_ans+=oj_508num[1]+oj_508num[0]+oj_508num[2];
            break;
        }else{
            //两种方案 左侧是2个工具人,右侧是一个工具人  [最快和最慢一起max min-1  和 min -1 max-1+次慢和最快]  --选择小的一种
           oj508_ans+=min((oj_508num[0]+oj_508num[1]+oj_508num[i]+oj_508num[1]),oj_508num[i]+oj_508num[0]+oj_508num[i-1]+oj_508num[0]);
        }
    }
    cout << oj508_ans << endl;
    return 1;
}

/* 给出一个字符串，判断其中的左右圆括号是否匹配。
注：只需判断左右圆括号 ′(′  和  ′)′。
*/


// 首先栈是空的 压入一个左括号,
//在循环的第二次进来的时候  需要去找一个右括号
// 如果你当前找到了右括号 是一对
//需要判断栈顶部是否有值,因为每次一对都需要左括号 如果为空证明括号不是一对.
// 同时需要确定下一个左括号起始 ,栈清空 . 循环下去将已经有答案了.
char OJ::string_matching()
{
    stack<char>sta;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            sta.push(s[i]);
        }else if(s[i]==')'){
            if(!sta.empty() && s[i]=='C'){
               sta.pop();
               cout << "YES"<<endl;
            }else{
               cout<< "NO"<<endl;
            }
        }
    }
}





stack<char> s1;
stack<int> s2;


void cl(int x1){
    while (!s1.empty()) {
        s2.pop();
        s1.pop();
    }
    s1.push('t');
    s2.push(x1);
}
//定义2个栈
int OJ::string_bracket(){
    int ans =0;
    string s;
    //由于声明的栈为空 初始化两个值,可以省去一个判断不需要判断是否为空
    s1.push('t');
    s2.push(-1);
    cin >>s;
    for(int i =1;i<s.size();i++){
        if(s[i]=='('||s[i]=='}'||s[i]==']'){
                //和上题一样入栈
            s1.push(s[i]);
            s2.push(i);
        }else if(s[i]==')'){
            if(s1.top()=='('){
                  s1.pop();
                  s2.pop();
                  ans=max(ans,i-s2.top());
                  //ans 是最终的答案
                  //解释:由于s2的栈顶维护了一个下标,他不可能为空,
                  //由循环进来是寻找到了下一组的起始位子,
                  //所以 用当前的位子的下标-栈顶元素(已匹配到的上一个元素的位子(因为每次都压入了上次的地址和下标),所以直接娶取一个大的值)
                  // s2的栈顶  上一个不匹配的位子来更新 这一段他的长度  你的更新的地址下标之的的距离 不是对于-1这个标变量而更新的 因为pop的操作
            }else{
                  // 如果没有找到 则需要清空栈,然后再初始化 所以封装个函数
                 cl(i);
            }
        }else if(s[i]==']'){
            if(s1.top()=='['){
                  s1.pop();
                  s2.pop();
                  ans=max(ans,i-s2.top());
            }else{
                cl(i);
            }
        }else if(s[i]=='}'){
            if(s1.top()=='{'){
                  s1.pop();
                  s2.pop();
                  ans=max(ans,i-s2.top());
            }else {
                cl(i);
            }
        }
    }
    return ans;
}





//379 stack  wmslog
stack<int> sta_cnt; //正常数量
stack<int> sta_max; //极大值
int OJ::stack_379Wmslog9(){
   //定义一个n,对应n次操作
     int n = 0;
     cin >> n ;
     for(int i =0;i<n;i++){
          int temp =0;
          if(temp==0){
             cin >> temp;
             //sta_cnt.push(temp);
             if(sta_cnt.size()==1){
                 //触发了入栈操作,第一次  入栈的数量
                sta_cnt.push(temp);
                //极大值也进行入栈 ,后面需要比较求最大的入库数量
             }else{
                 //如果不是第一波入栈,需要进行比较 找出最大的
                 sta_max.push(max(sta_max.top(),temp));
             }
         }else if(temp==1){
              //不为0出栈
            if(!sta_cnt.empty()){
                sta_cnt.pop();
                sta_max.pop();
            }
          }else if(temp==2) {
            if(!sta_max.empty()){
                cout <<  sta_max.top() <<endl;
            }else{
                cout << 0 << endl;
            }
          }
     }
     return 0;
}

//382  //用队列模拟了以下约瑟夫环
int OJ::queue_number_off(){
          //n 个人 ,m的淘汰
    queue<int> que;
    int n , m;
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        que.push(i);
    }
    int now =1;
    while(que.size()!=1){
        //如果访问到报数的值
        if(now!=m){
             que.push(que.front());//如果安全了则放到队尾
             now++;  //从而开始  不然没结果
        }else{
            now=1;
             //否则是不安全的
            //因为会淘汰 所以从1开始报数
        }
        //zongshi 都要出队的
        que.pop();
    }
    cout << que.front()<< endl;
    return 1;
}


// 577 统计出现最多的单词  unorderend_map map
int OJ::map_single_word(){
   //如何找到最多的单词
   // 额外的单词是什么保留出现最多的
    map<string,int>m;
    string ans;  //答案
    string t;//输入
    int cnt=0;
    while(cin>>t){
        for(int i=0;i< t.size();i++){
            if(t[i]>='A' && t[i]<='Z'){
                t[i]+='a'-'A';
            }
        }
        m[t]++;
        //有序的map 的特性是不允许出现重复的key  所以  ++vaule 统计出现的 次数
    }

    for (const auto& [key, value] : m){
        cout << key << value <<endl;
    }
    //用一个和第一个二个做反复对比 最终返回大的值.
    for(auto it=m.begin();it!=m.end();it++){

        if(it->second > cnt){
            cout << it->second << endl;
            cout << it->first << endl;
            ans=it->first;
            cnt=it->second;
        }
    }
    cout << ans <<endl;
    return 1;
}

//566
int OJ::vector_statistics(){
  int n ,m ,cnt ;//you多少个用户了;
  unordered_map<string,int>umap; //无序

  cin >> n >> m;
  vector<vector<string> > v (n,vector<string>{});
  for(int i=0;i<m;i++){
       string a,b;
       cin >> a>>b;
       if(umap.count(a)==0){  //我不知道字符串出现第几行的数组 去记录一下
            umap[a]=cnt;
            v[cnt].push_back(a);
            v[cnt].push_back(b);
            cnt++;
       }else{
            //出现了呢?
           v[umap[a]].push_back(b);
       }
  }
for(int i=0;i<n;i++){
   for(int j=0;j<v[i].size();j++)
     {
       if(j){
         cout << " ";
       }
       cout << v[i][j];
     }
       cout <<endl;
  }
  return 1;
}



struct node_573{
   int id , offset,nextid;
   bool operator< (const node_573&b)const{
       if(this->nextid==b.id){
           //如果时间相同.id小的在前
           return this -> id>b.id;
       }
       //期待数字小的在前面
       return this->nextid >b.nextid;
   }
};
//573
int  OJ::priority_queue_573(){
      string t;
      int n=0;
      vector<node_573> xx;
      priority_queue<node_573> que1;
      while(cin >> t){
           if(t[0]=='#'){
               break;
           }
      }
     int id,offset;
     cin >> id >> offset;
     que1.push((node_573){id,offset,offset});

     cin >> n;
     for(int i =0; i<n ;i++){
        node_573 temp =que1.top(); //首先
        que1.pop();
        cout << temp.id <<endl;
        temp.nextid+=temp.offset;
        que1.push(temp);
     }
}



//240 1<=n<=7  max分解为为7=> 5x (n-1)
// 3(3-1)
// 4(4-1)
// 这题的推算公式->n=1  num[i]=1
//n=2  num[2]=3
//n=3  num[3]=9;
//n=4  num[4]=27; 位数 * 上一次的结果
//提前处理画图的长度   递归画图形

char ans[1005][1005];
int num[10]={0,1,3,9,27,81,243,729};
void func_240(int x , int y, int n){
    if(n==1){
        ans[x][y]='x';
        return ;
    }
    func_240(x,y,n-1); //左上
    func_240(x,y+num[n]/3*2,n-1); //右上
    func_240(x+num[n]/3*2,y,n-1);//左下
    func_240(x+num[n]/3,y+num[n]/3,n-1); //中间
    func_240(x+num[n]/3*2,y+num[n]/3*2,n-1); //右下
}


int OJ::recursive_240(){
    func_240(1,1,7);
    int t ;
    while(cin >> t){
       if(t==-1){
           break;
       }
    }
    for(int i=1;i<=num[t];i++){
        for(int j=1;j<=num[t];j++){
            if(ans[i][j]=='X'){
                 cout << "X";
            }else{
                 cout << ' ';
            }
            cout <<endl;
        }
    }
        cout <<'-' <<endl;
   return 1;
}



// 递归实现指数型枚举
// func () 每一层选定一个数字
// 1:选第一个字  1-n 都可以选
// 如果1 选1了 第二层只能是2  需要就是上一层选是几 和 本次递归的层数 ->两个参数即可
//参数1 从几开始选 ,参数2  第几曾



int func235_n,func235_num[15];
void printf235(int cnt ){
    for(int i=1;i<=cnt;i++){
        if(i!=1){
            cout << "";
        }
        cout << func235_num[i];
    }
    cout << endl;
}
void func_235 (int s,int deep){
    for(int i=s;i<=func235_n;i++){
         //从1开始?
        func235_num[deep]=i;
       //cout << func235_num[deep]<< endl;
        printf235(deep);
        func_235(i+1,deep+1);
    }
}

int OJ::recursive_235(){

    cin >> func235_n ;
    //选数的范围

    func_235(1,1);
    return 1;
}
