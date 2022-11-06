#pragma once
#include <string>

using namespace std;

class Leetcode
{
public:
	static int   Remove_Duplicates_from_Sorted_Array();
public:
	static int   Leetcode_removeElement();
public:
	static int   Search_Insert_Position();
public:
	static string  Count_and_Say();
public:
	static  int  Length_of_Last_Word();
public: // 只出现一次数字 > 不使用额外的空间 () 满足 线性的时间复度,位运算的应用 (满足交换的)
    static  int SingNumber_implement(vector<int> &nums);
public:
    static int SingNumber();
public:   //题目判断奇偶数  数据范围 10^ 10 次方   int 2 * 10^9    应该是用long long
    static long long  IsCardinal();

};
