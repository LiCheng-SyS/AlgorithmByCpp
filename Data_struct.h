#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <istream>
using namespace std;

class Data_struct{
public:struct linkListNode{
       linkListNode(int data):data(data),next(NULL){};
       int data;
       linkListNode *next;
    };
public:
    static void impleLinkList_bystruct();

public:
    static int data[10],next[10]; //指针 数据
public:
    static void impleLinkList_byarr();
};


#endif // DATA_STRUCT_H
