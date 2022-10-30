#include "Euler.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
//#include <direct.h>
#include <stdio.h>
#include <cmath>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>


using namespace std;




//remark 각 문항은 한 문항에 대응해
long long Euler::Euler22()
{
    Euler  euler1;
    euler1.num = 0;
    string name[6005];
    const   char* filename_str = "file\\euln22name.txt";
    ifstream ism(filename_str, ios::in); //只读方式打开文件
    if (!ism)
    {
        cout << "openfile!" << endl;
        return 0;
    }
    char filecontent;
    while (ism.get(filecontent) >> name[euler1.num])
    {
        euler1.num++;
    }
    ism.close();

    long long ans = 0;

    sort(name, name + 1);
    for (int i = 0; i < euler1.num; ++i)
    {
        int  count = 0;
        for (int j = 0; j < name[i].size(); j++)
        {
            count += name[i][j] - 'A' + 1;
            //A对应1 -A 才是后得0  +1 才能得到A的值
        }
        //COLIN这个名字的价值得乘以位数
        ans += count * (i + 1);
        //暴力
    }
    return ans;
}



//Euler32
int work(int* mark, int x) {
    while (x)
    {
        int t = x % 10;//最后一位
        if (mark[t] == 1) {
            return 0; //出现了冲突
        }
        mark[t] = 1; //没有冲突则标记
        x /= 10;
        //处理下一个数字
    }
    return 1;
}

int func(int x, int y, int z) {
    int mark[10] = { 0 };
    if (work(mark, x) && work(mark, y) && work(mark, z) && mark[0] == 0) {
        //충돌하지 않아야 하고 나타나지 않아야 해 //且没有 0
        return 1;
    }
    return 0;
}

int digit(int x) {
    return floor(log10(x)) + 1;
}

long long Euler::Euler32()
{
    Euler  euler1;
    euler1.ans = 0; //최종  결과
    int check[10005] = { 0 };//표지  arr
    //a i 的数字位数 ,b 是j 数字数位,，c是乘积的数字位数
    for (int i = 2; i < 100; i++)
    {
        for (int j = i + 1; 1; j++)
        {
            int a = digit(i), b = digit(j), c = digit(i * j);
            if (a + b + c > 9) {
                //如果大于 就不可能是答案
                break;
            }
            if (a + b + c == 9) {
                if (func(i, j, i * j)) {
                    cout << i << " " << j << "=" << i * j << endl;
                    if (check[i * j] == 0) {
                        check[i * j] = 1;
                        euler1.ans += i * j;
                    }
                }
            }
        }
    }
    cout << euler1.ans << endl;
    return 0;
}



int gcb33(int a, int b) {
    if (b == 0)return a;
    return gcb33(b, a % b);
}

int func33(int x, int y) {
    //拆成两位数 ，一个数十位 一个是个位
    int  x1 = x / 10, x2 = x % 10, y1 = y / 10, y2 = y % 10;
    if (!x1 || !x2 || !y1 || !y2) return 0; //有0则为平凡解

    //例举一个不平凡解, 如果分子分母的x1=y1  如果相等的  -如果约分的值和原分数的值一致的  x* y2== y* x2==true
    if (x1 == y1 && x * y2 == y * x2)return 1;
    if (x1 == y2 && x * y1 == y * x2)return 1;

    if (x2 == y1 && x * y2 == y * x1)return 1;
    if (x2 == y2 && x * y1 == y * x1)return 1;
    return 0;
}


long long Euler::Euler33() {
    int a = 1, b = 1; //全局的分子 分母
    //两位数不带0的
    for (int i = 11; i < 100; i++)
    {
        //分母得比分子大
        for (int j = i + 1; j < 100; j++)
        {
            //如果不平凡
            if (func33(i, j)) {
                cout << i << " / " << j << endl;
                a *= i; //分母字母的值都存在对应的数字里
                b *= j;
            }
        }

    }
    int t = gcb33(a, b); //公约数
    a /= t;
    b /= t;
    cout << a << "/" << b << endl;
    return 0;
}




int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)calloc((*returnSize = 2), sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        int x = target - nums[i];
        cout << x << endl;
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == x)
            {
                returnSize[0] = i;
                returnSize[1] = j;
                return res;
            }
        }
    }
    return  0;

}


long long Euler::leetcodeSum()
{
    int num[] = { 8,7,2,4,1 };
    int returnnum[1];
    int  target = 6;
    int* p = twoSum(num, 4, target, returnnum);
    for (int i = 0; i < 2; ++i)
    {
        cout << returnnum[i] << endl;
    }

    return 0;
}




int romanToInt(string s) {

    int ans = 0;
    //cout << s.size() << endl;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
            {
                ans += s[i + 1] == 'V' ? 4 : 9;
                i++;
            }
            else
            {
                ans += 1;
            }
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L' || s[i + 1] == 'C')
            {
                ans += s[i + 1] == 'L' ? 40 : 90;
                i++;
            }
            else
            {
                ans += 10;
            }
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D' || s[i + 1] == 'M')
            {
                ans += s[i + 1] == 'D' ? 400 : 900;
                i++;
            }
            else
            {
                ans += 100;
            }
        }
        else if (s[i] == 'V')
        {
            ans += 5;
        }
        else if (s[i] == 'L')
        {
            ans += 50;
        }
        else if (s[i] == 'D') {
            ans += 500;
        }
        else {
            ans += 1000;
        }
    }
    return ans;
}



int Euler::Leetcode_Roman_to_Integer()
{

    return 	romanToInt("IMII");

}



string intToRoman(int num) {

    int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    string reps[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

    string res;
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            res += reps[i];
        }
    }
    return res;


}

string Euler::Leetcode_intToRoman()
{
    return intToRoman(1005);
}


// 3或5的倍数在小于的自然数中，或的倍数有、、和，这些数之和是。求小于的自然数中所有或的倍数之和。

void Euler::euler1(){
    int sum = 0;
        for (int i = 1; i < 1000; ++i)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                sum += i;
            }
        }
        std::cout << sum << endl;
}


//有可能出现既是出现3x5的倍数之和()--> 等差数列  由3的倍数和+5的倍数和-15的倍数和。
void Euler:: euler1p()
{		//3的倍数首项+末项x项数（末项/首相）
    int temp1 = (3 + 999) * 333 / 2;	   //334
        //由于末项1000不存在，所以末位为995x（乘项数）/2
    int temp2 = (5 + 995) * 199 / 2;
    //由于15的末位不存在1000，则用相数推出末项为15*66  项数=1000/15=66 ->公式如下
    int temp3 = (15 + 990) * 66 / 2;

    cout << temp1 + temp2 - temp3 << endl;
}
//1000->Loop   O（n）-->随着N扩大 -->运行时间则随之扩大
//无论多大值计算4次->o(4) -->只计算O(1);常数抹掉 优化
//时间复杂度    ->如果当数据扩大一倍,程序运行的时间扩大多少倍。（算法根据数据规模如何扩大）


//偶斐波那契数:斐波那契数列中的每一项都是前两项的和。由和开始生成的斐波那契数列的前项为：考虑该斐波那契数列中不超过四百万的项，(求其中为偶数的项之和)。(偶数的和)
//example: 1,2,3,5,8,13
//两个数循环+ 往后读
void Euler::euler2()
{
    long long temp = 0;
    int a = 1, b = 2;
    while (b < 4000000)
    {
        if (b % 2 == 0)
        {
            temp += b;
        }
        b += a; //a往后移动一位
        a = b - a; //b往后移动一位
    }
    cout << temp << endl;
} //o(1);

//空间复杂度 -->内存o（n）递推

long long num1[50];
long long  funcxx(int x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    if (num1[x] != 0)
    {
        return num1[x];
    }
    return  num1[x] = funcxx(x - 1) + funcxx(x - 2);
}

//记忆数组  升级递归
void euler2plus()
{
    for (int i = 0; i < 50; ++i)
    {
        cout << i << ";" << funcxx(i) << endl;
    }
}






// 最大回文乘积回文数就是从前往后读和从后往前读都一样的数。由两个位数相乘得到的最大的回文数是 。
// 求由两个3位数相乘得到的最大的回文数。
int func(int x)
{
    //记录原值tempa ,t为调换过来的结果
    int tempa = x, t = 0;
    //数字反转
    while (x)
    {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return tempa == t;
}
void Euler::euler4()
{
    int ans = 0;  //暴力枚举
    //因为要求三位
    for (int i = 100; i < 1000; i++)
    {
        //从i开始不会有重复
        for (int j = i; j < 1000; j++)
        {
            if (func(i * j))
            {
                ans = max(ans, i * j);
            }
        }
    }
    cout << ans << endl;
}




//前十个自然数的平方的和 - 前十个自然数的和的平方是  ||平方的和与和的平方之差
void Euler::euler6()
{
    int sum = 0, psum = 0;
    for (int i = 0; i <= 100; ++i)
    {
        sum += i;
        psum += i * i;
    }
    cout << sum * sum - psum << endl;

}

//Find the thirteen adjacent digits in the 100- digit number that have the greatest product.What is the value of this product ?
//在如下的位数中1000连续四个数字的最大乘积是
//滑动窗口法

int Euler:: euler8()
{

    //求这个10000位数中连续十三个数字的最大乘积。
    char str[2000] = { 0 };
    long long ans = 0, now = 1, zero_cnt = 0;//当前窗口 由于乘积应该为1
    //C++中的CIN对象是类IoSoW对象。它用于接受来自标准输入设备（即键盘）的输入。它与标准C输入流stdin…相关联。。。提取操作员从使用键盘输入的对象中提取数据

    cin.getline(str, 2000);
    //cin >> str;

    int j = 0;
    int sn = strlen(str);
    for (int i = 0; i < sn; ++i)
    {
        if (str[i] == '\n' || str[i] == ' ')
        {
            str[i] = str[i + 1];//往后移动一位，对齐
            j++;
        }
        else
        {
            str[i - j] = str[i];	//出现过几次ture 的条件则整个数组数值往前移动一位
        }
    }
    str[sn - j] = '\0';	//对齐数组长度
    //cout << "retrun --->:" << str << endl;


    for (int i = 0; i < str[i]; i++)
    {
        if (i < 13)//第一个窗口
        {
            now *= str[i] - '0';
        }
        else if (str[i] != '0')
        {
            now *= str[i] - '0';
            //now /= str[i - 13]-'0'; //每次i-13 往后移动一格 -->窗口滑动 如果为有字符0就会报错
        }
        else
        {
            zero_cnt++;//如果为0+1
        }
        if (i >= 13)
        {
            if (str[i - 13] != '0')
            {
                now /= str[i - 13] - '0';
            }
            else
            {
                zero_cnt--;  //如果为0则 再次-1；
            }
        }
        if (zero_cnt == 0)
        {
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}




//阵中，有四个呈对角线排列的数被标记为红色。	方向数组
//void Euler:: euler11()
//{
//    int dirx[4] = { -1,0,1,1 };
//    int diry[4] = { 1,1,1,0 };
//    for (int i = 5; i < 25; ++i)
//    {
//        for (int j = 5; j < 25; ++j)
//        {
//            cin >> num1[i][j];
//        }
//    }
//    for (int i = 0; i < 25; ++i)
//    {
//        for (int j = 0; j < 25; ++i)
//        {
//            for (int k = 0; k < 4; ++k)
//            {
//                int temp = num1[i][j];
//                for (int l = 0; l <= 3; ++l)
//                {
//                    int x = i + l * dirx[k];
//                    int y = j + l * diry[k];
//                    temp *= num1[x][y];
//                }
//                ans1 = max(ans1, temp);

//            }
//        }
//    }
//    cout << ans1 << endl;
//}



//提示：C++的 语言中---> 8位long long 最大的范围 2的63次方-1   或-2的63次方    无法达到50位的 会越界。  int 的是31次方4位 short的是15次方 2位
//大和 ---求一下100个 50位数的和的 前十位数字   -->必须用字符串输入
///思路如下： 第一步 将数据的长度 存在下标0的位子 二：将数组倒着存个位放在最前面（好处是 不用向正着存时 进位后往后移动，直接在后面+一位最高位即可）	 总体就是存 + 进位

//首先定义字符   输入的数字应该对应两个数组

char  s113[1005], s213[1005];
int num113[1005], num213[1005],sum[1005];
void Euler::euler13()
{
    cin >> s113 >> s213;  //输入
    num113[0] = strlen(s113);  // 第一个数字的长度
    num213[0] = strlen(s213);  //d第二个数字的长度
    //遍历字符串  把数字的每一位存在对应的位数
    for (int i = 0, j = num113[0]; s113[i]; i++, j--)
    {
        //s11[i]是指遍历到字符串结束
        //J对应数字数组里的下标
        num113[j] = s113[i] - '0';
    }

    for (int i = 0, j = num213[0]; s213[i]; i++, j--)
    {
        num213[j] = s213[i] - '0';
    }

    sum[0] = max(num113[0], num213[0]);
    for (int i = 1; i <= sum[0]; i++)
    {

        sum[i] = num113[i] + num213[i];
    }
    //只是做了计算  步骤

    //进位
    for (int i = 1; i <= sum[0]; i++)
    {
        if (sum[i] > 9)
        {
            sum[i + 1] += sum[i] / 10;
            //++也行
            sum[i] %= 10;
            //取出进位的的数值
            if (i == sum[0]) // 长度变长进位 数值最高位到达上限 让长度加1
            {
                sum[0] ++;
            }
        }
    }
    //倒序 高位向低位输出
    for (int i = sum[0]; i > 0; i--)
    {
        cout << sum[i];
    }
    cout << endl;//换行
}


//尽管还未被证明，但普遍认为，从任何数开始最终都能回到（这被称为“考拉兹猜想”）。在小于一百万的数中，从哪个数开始迭代生成的序列最长？
long long euler14arr[10000005];
long long funceuler14(long long x)
{
    if (x == 1)
    {
        return 1;
    }
    if (x < 10000000 && euler14arr[x] != 0)
    {
        return  euler14arr[x];
    }
    long long t;
    if (x % 2 == 0)
    {
        t = funceuler14(x / 2) + 1;		 //求偶数公式
    }else
    {
        t = funceuler14(3 * x + 1) + 1;	  //求基数公式
    }

    if(x < 10000000)
    {
        euler14arr[x] = t;
    }
    return  t;
}

//记忆数组  升级递归   //用空间换时间
void Euler::euler14plus()
{
    long long ans = 0, mmax = 0;
    for (int i =1; i <= 1000000; ++i)
    {
        long long t = funceuler14(i);
        if (t > mmax)
        {
            mmax = t;
            ans = i;
        }
    }
    cout << ans << endl;
}





void functemp(int* t1, int* t2)
{
    t2[0] = t1[0];
    for (int i = 1; i <= t2[0]; ++i)
    {
        t2[i] += t1[i];
        if (t2[i] >9)
        {			//进位
            t2[i + 1] += t2[i] / 10;
            t2[i] %= 10;
            if (i == t2[0])
            {			  //MAX高位进位
                t2[0] ++ ;//计算完成
            }
        }
    }
}
void Euler::euler25()
{
    //循环 返回两个项数相加 整数加法  a ->-<b  两个数组相加 指针传过去
    int  num25[2][1010] = { {1,1},{1,1} }, a = 0, b = 1;
    //ab== 第一项和第二项   从第三个数开始
    for (int i = 3; i; ++i)
    {
        functemp(num25[a], num25[b]);
        if(num25[b][0]>=1000)
        {
            cout << i << endl;
            break;
        }
        //如果没又触发+完成
        swap(a, b);
    }
}






