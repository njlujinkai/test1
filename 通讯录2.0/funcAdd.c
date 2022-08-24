#include "func.h"
//直接插入排序
void NewPersonInsertSort(Person* head)
{   
    Person* lt=AddressListCreat();
    bzero(lt,sizeof(*lt));
    Person *p;
    int flag;
    while(1)
    {
        printf("请输入姓名,性别,年龄,号码,ID:\n");
        scanf("%s%s%s%11s%s",lt->NAME,lt->SEX,lt->AGE,lt->TEL,lt->ID);
        getchar();
        flag=0;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
            if(mystrcmp(p->NAME,lt->NAME))
            {
                printf("姓名已存在!重新输入:\n");
                flag++;
                break;    
            }
            if(mystrcmp(p->TEL,lt->TEL))
            {
                printf("号码已存在!请重新输入:\n");
                flag++;
                break;
            }
            if(mystrcmp(p->ID,lt->ID))
            {
                printf("ID已存在!重新输入:\n");
                flag++;
                break;    
            }
        }
        if(0==flag)
        {
            break;
        }
    }
    //排序
    if(AddressListEmpty(head))
    {   
        lt->next=head->next;
        head->next=lt;
        converse(lt);
        return;
    }
    p=head;
    flag=0;
    while(p->next!=NULL)
    {   
        if(mystrcmps(p->next->NAME,lt->NAME))
        {
            lt->next=p->next;
            p->next=lt;
            flag++;
            break;
        }
        p=p->next;
    }
    if(0==flag)
    {
        lt->next=p->next;
        p->next=lt;
    }
    // //数据保存
    // converse(lt);
    return;
}