#include "func.h"
//按ID删除联系人
int PersonDeleteByID(Person* head,char *ID)
{
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return -1;
    }
    Person* p=head;
    Person* q;
    while(p->next!=NULL)
    {   
        if(mystrcmp(p->next->ID,ID))
        {
            q=p;
            p=p->next;
            q->next=p->next;
            free(p);
            p=NULL;
            return 1;
        }
        p=p->next;
    }
    return 0;
}
//按姓名删除联系人
int PersonDeleteByNAME(Person* head,char *NAME)
{
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return -1;
    }
    Person* p=head;
    Person* q;
    while(p->next!=NULL)
    {   
        if(mystrcmp(p->next->NAME,NAME))
        {
            q=p;
            p=p->next;
            q->next=p->next;
            free(p);
            p=NULL;
            return 1;
        }
        p=p->next;
    }
    return 0;
}