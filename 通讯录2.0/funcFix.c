#include "func.h"
//通过ID修改并排序
bool PersonFixSortByID(Person* head,char *ID)
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
            PersonDeleteByID(head,ID);
            NewPersonInsertSort(head);
            printf("修改成功!\n");
            return 1;
        }
        p=p->next;
    }
    printf("修改失败!ID不存在!\n");
    return 0;

}
//通过姓名修改并排序
bool PersonFixSortByNAME(Person* head,char *NAME)
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
            PersonDeleteByNAME(head,NAME);
            NewPersonInsertSort(head);
            printf("修改成功!\n");
            return 1;
        }
        p=p->next;
    }
    printf("修改失败!姓名不存在!\n");
    return 0;

}