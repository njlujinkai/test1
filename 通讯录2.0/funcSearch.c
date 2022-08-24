#include "func.h"
//按ID搜索联系人
bool PersonSearchByID(Person* head,char* ID)
{
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return 0;
    }
    Person* p=head->next;
    while(p!=NULL)
    {   
        if(mystrcmp(p->ID,ID))
        {
            printf("搜索完成!\n");
            printf("姓名:%s 性别:%s 年龄:%s 号码:%s ID:%s\n",p->NAME,p->SEX,p->AGE,p->TEL,p->ID);
            return 1;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("搜索完成!\n");
        printf("ID不存在!\n");
        return 0;
    }
}
//按姓名搜索联系人
bool PersonSearchByNAME(Person* head,char* NAME)
{
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return 0;
    }
    Person* p=head->next;
    while(p!=NULL)
    {   
        if(mystrcmp(p->NAME,NAME))
        {
            printf("搜索完成!\n");
            printf("姓名:%s 性别:%s 年龄:%s 号码:%s ID:%s\n",p->NAME,p->SEX,p->AGE,p->TEL,p->ID);
            return 1;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("搜索完成!\n");
        printf("姓名不存在!\n");
        return 0;
    }
}
//按号码搜索联系人
bool PersonSearchByTEL(Person* head,char* TEL)
{
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return 0;
    }
    Person* p=head->next;
    while(p!=NULL)
    {   
        if(mystrcmp(p->TEL,TEL))
        {
            printf("搜索完成!\n");
            printf("姓名:%s 性别:%s 年龄:%s 号码:%s ID:%s\n",p->NAME,p->SEX,p->AGE,p->TEL,p->ID);
            return 1;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("搜索完成!\n");
        printf("号码不存在!\n");
        return 0;
    }
}