#include <iostream>
#include <Data_struct.h>

using namespace std;


//地址指向想一个地址将指针区域串联
void  Data_struct::impleLinkList_bystruct(){
       Data_struct::linkListNode *head=NULL;
       head=new Data_struct::linkListNode(1);
       head->next =new Data_struct::linkListNode(2);
       head->next->next =new Data_struct::linkListNode(3);
       head->next->next->next =new Data_struct::linkListNode(4);

       Data_struct::linkListNode  *p=head;
       while (p!=NULL) {
           cout << p->next << endl;
       }
       cout << endl;
}


//ind 在 index节点后添加p
//节点p 后面 val
// 这里的next 是指 ->指针区域
void  LinkListadd(int ind ,int p,int val){
       Data_struct::next[ind]=p;
       Data_struct::data[p]=val;
       return ;
}
void Data_struct::impleLinkList_byarr(){
        int  head =3 ;
        data[3]=0;
        //头节点是3
        //3节点添加5节点,存的是1
        LinkListadd(3,5,1);
        //五节点添加2节点,存的是2
        LinkListadd(5,2,2);
        //2节点添加的是7节点 ,存的是3
        LinkListadd(2,7,3);
        // 第二个是下一个节点 ,最后一个是值
        LinkListadd(7,9,100);

        int p =head;
        while(p!=0){
            cout <<  " -> " << data[p]<<  endl;
            p=next[p];
        }
        cout << endl;
}

