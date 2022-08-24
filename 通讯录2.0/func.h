#ifndef _FUNC_H
#define _FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <strings.h>
#define N 32
#define MAX 10
typedef struct Person
{   
    char NAME[N];
    char SEX[N];
    char AGE[N];
    char TEL[N];
    char ID[N];
    struct Person* next;
}Person;
//建立空通讯录
Person* AddressListCreat();
//头插法新建联系人
void NewPersonCreat(Person* head);
//判断通讯录是否为空
bool AddressListEmpty(Person* head);
//遍历通讯录
void AddressListPrint(Person* head);
//直接插入排序(按首字母排序)
void NewPersonInsertSort(Person* head);
//按ID删除联系人
int PersonDeleteByID(Person* head,char *ID);
//按姓名删除联系人
int PersonDeleteByNAME(Person* head,char *NAME);
//通过ID修改并排序
bool PersonFixSortByID(Person* head,char *ID);
//通过姓名修改并排序
bool PersonFixSortByNAME(Person* head,char *NAME);
//按ID搜索联系人
bool PersonSearchByID(Person* head,char* ID);
//按姓名搜索联系人
bool PersonSearchByNAME(Person* head,char* NAME);
//按号码搜索联系人
bool PersonSearchByTEL(Person* head,char* TEL);


//字符串长度
int mystrlen(char* a);
//判断字符串是否相等
bool mystrcmp(char* a,char* b);
//判断字符串大小
bool mystrcmps(char* a,char*b);
//选项选择
int choice();
//删除界面
void DeleteScreen(Person* head);
//修改界面
void FixScreen(Person* head);
//搜索界面
void SearchScreen(Person* head);
//菜单
void menu();
//清空缓冲区
void clear();
//
void converse(Person* lt);
void ReadOldData(Person* head);
void NewDataConverse(Person* head);















// //统计链表元素个数
// int AddressListcount(Person* head);
// //获取某一结点前一结点
// Person* FrontofNode(Person* head,Person* node);
// //寻找链表中姓名最小的结点
// Person* NAMEMIN(Person* head);
// //将通讯录按首字母排序
// void AddressListSort(Person* head);
#endif