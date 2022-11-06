#include "Leetcode.h"

#include <iostream>
#include <vector>


using namespace std;


int removeDuplicates(vector<int>& nums) {

	if (nums.size() == 0)
	{
		return  0;
	}

	int  last = nums[0], flag = 1;
	//必须保证ARR元素有序
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != last)
		{
			last = nums[i];//判断和之前存好的数字是否一致，不一致说明则是新数
			nums[flag] = nums[i];//存好的现在的第几个数字
			flag++;
		}
		cout << nums[i] << endl;
	}

	return  flag;
}

int Leetcode::Remove_Duplicates_from_Sorted_Array()
{
	int str[] = { 1,1,2,2,2,3 };
	vector<int> strArray(str, str + 6);
	return 	removeDuplicates(strArray);
}


int removeElement(vector<int>& nums, int val) {
	if (nums.size() == 0)
	{
		return  0;
	}
	int flag = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != val)
		{
			//当前不满足条件的 存好的现在的第几个数字
			nums[flag] = nums[i];//存好的现在的第几个数字
			flag++;
		}
	}

	return  flag;
}



int Leetcode::Leetcode_removeElement()
{
	int str[] = { 1,1,2,2,2,3 };
	vector<int> strArray(str, str + 6);
	return  removeElement(strArray, 3);
}




int searchInsert(vector<int>& nums, int target) {
	if (nums[nums.size() - 1] < target)
	{
		return  nums.size();
	}
	int l = 0, r = nums.size() - 1;
	while (l != r)
	{
		int	mid = (l + r) / 2;
		if (nums[mid] >= target)
		{
			//如果大于目标数则为1
			r = mid;
		}
		else
		{   //如果小于目标则标识为0,而第一个1就是答案 所以需要+1
			l = mid + 1;
		}
	}
	return l;
}




int Leetcode::Search_Insert_Position()
{
	int val[] = { 1,3,5,6 };
	vector<int> valArray(val, val + 4);
	return  searchInsert(valArray, 5);

}


/**
 * \brief 
 * \param n 
 * \return 38 TODO
 */
string countAndSay(int n) {
	string arr = "1"; // 首先初始化一个储存结果的数组
	if (n == 1) //n==1为特例
		return arr;

	// 第1层循环，循环中的第i次将生成 n=i+1 时的外观数列
	for (int i = 1; i < n; i++) //注意，i从1开始循环，因为n==1的情况已经单独判断了
	{
		char word = arr[0]; //word代表当前被搜查的数字
		int num = 1; //(计数器)num代表当前被搜查的数字在当前arr序列中出现的个数，已经发现这个数字了，所以num先置1

		string temp = ""; //temp为存储新生成序列的字符串

		// 第2层循环，循环中的第j次将扫描元素arr[j]
		for (int j = 1; j < arr.size(); j++) //因为arr[0]已经搜过了，所以j从1开始
		{
			if (word == arr[j]) //如果arr[j]==当前被搜寻的数字word，则计数器num加1
			{
				num++;
			}
			else if (word != arr[j]) //如果word != arr[j]，说明word数字子串已经结束了，出现了新的数字
			{
				char num_char = num + '0';
				temp += num_char; //将个数加入新序列中
				temp += word; //将被搜寻数字也加入新序列中

				word = arr[j]; //reset 将word设为新的被搜寻数字
				num = 1; //reset
			}
		}
		// 边界处理
		// 注意，上面的循环结束后，旧序列中排在最后一个的数字虽然被搜到了，但并没有被加入到新序列中，因此要把它也补进去
		char num_char = num + '0';
		temp += num_char;
		temp += word;
		arr = temp; //将新生成的序列赋给arr
	}
	return arr;
}

string Leetcode::Count_and_Say()
{
	return  countAndSay(3);
}


int lengthOfLastWord(string s) {
	int  l = -1, r = -1;//左右指针都指向-1 如果不是不存在且 右指针-左-1就为正确答案
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] != ' ' && r == -1)
		{
			r = i;
		}
		else if (r != -1 && s[i] == ' ')
		{
			l = i;
			break;
		}
	}
	if (r == -1)
	{
		return  0;
	}
	return r - l;
}

int Leetcode::Length_of_Last_Word()
{
	return  lengthOfLastWord("Hello World");
}


int  Leetcode::SingNumber_implement(vector<int> &nums){

    int ans =0;
    for(int i=0;i<nums.size();i++){
        //cout << nums[i]<< " first" << ans << endl;
        ans ^=nums[i];
        //cout << nums[i]<< "last" << ans << endl;
    }
    return ans;
}




//位运算   不用第三个变量 来交换两个变量  ---别乱用 容易死
//  0 ^ x =x   基数会被返还
//  x ^ x =0
int Leetcode::SingNumber(){
    int valarr[]={1,2,2,1,4,4,8};
    vector<int>setArr(valarr,valarr+7);
    return   SingNumber_implement(setArr);
}


//对于任何一个数 & 1，因为1的二进制是1，在它的补码中，除了最后一位为1，其它全部为0，
//前面提到，按位与运算&只有当两个数都为1时结果才是1，因此，任何一个数与1相与，只有最低位可能为1，
//因此最终的结果只有0和1两种情况，而且结果取决于另外那个数二进制中的最后一位（若为1，最终结果便为1，若为0，结果便是0）


//正常  x % 2==0 // 负数会出问题  //找错用下 gdb
long long Leetcode::IsCardinal(){
    int cnt=0;
    int valarr[]={1,2,3,4,5,6,-7,8,9,10};
    vector<int>setArr(valarr,valarr+10);
    for(int i =1;i<setArr.size();i++){
            if(setArr[i] & 1 !=0){
                cnt++;
            }
    }
    return cnt;
}






 
