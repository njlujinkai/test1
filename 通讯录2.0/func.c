#include "func.h"
//建立空通讯录
Person* AddressListCreat()
{
    Person* head=(Person*)malloc(sizeof(Person));
    head->next=NULL;
    return head;
}
//判断通讯录是否为空
bool AddressListEmpty(Person* head)
{
    return head->next==NULL? 1:0;
}
//遍历通讯录
void AddressListPrint(Person* head)
{   
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return;
    }
    Person* p=head->next;
    while(p!=NULL)
    {
        printf("姓名:%s 性别:%s 年龄:%s 电话%s ID:%s\n",p->NAME,p->SEX,p->AGE,p->TEL,p->ID);
        p=p->next;
    }
    return;
}
void clear()
{
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        ;
    }
}
//选项选择
int choice()
{   
    int c;
    printf("输入选项:\n");
    scanf("%d",&c);
    clear();
    return c;
}
//删除界面
void DeleteScreen(Person* head)
{   
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return;
    }
    
    char ID[32];
    char NAME[32];
    while(1)
    {
        printf("1.按ID删除\n2.按姓名删除\n0.退出\n");
        int j;
        switch(choice())
        {
            case 1:
                printf("输入ID:\n");
                scanf("%s",ID);
                j=PersonDeleteByID(head,ID);
                if(j==1)
                {
                    printf("删除成功!\n");
                }
                if(j==0)
                {
                    printf("删除失败!ID不存在!\n");
                }
                break;
            case 2:
                printf("输入姓名:\n");
                scanf("%s",NAME);
                j=PersonDeleteByNAME(head,NAME);
                if(j==1)
                {
                    printf("删除成功!\n");
                }
                if(j==0)
                {
                    printf("删除失败!姓名不存在!\n");
                }
                break;
            case 0:
                return;
            default:
                printf("选项不存在!重新输入:\n");
                break;
        }
    }
}
//修改界面
void FixScreen(Person* head)
{   
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return;
    }
    char ID[32];
    char NAME[32];
    while(1)
    {
        printf("1.按ID修改\n2.按姓名修改\n0.退出\n");
        switch(choice())
        {
            case 1:
                printf("输入ID:\n");
                scanf("%s",ID);
                PersonFixSortByID(head,ID);
                break;
            case 2:
                printf("输入姓名:\n");
                scanf("%s",NAME);
                PersonFixSortByNAME(head,NAME);
                break;
            case 0:
                return;
            default:
                printf("选项不存在!请重新输入!\n");
                break;
        }
    }
}

//搜索界面
void SearchScreen(Person* head)
{   
    if(AddressListEmpty(head))
    {
        printf("通讯录为空!\n");
        return;
    }
    
    char ID[32];
    char NAME[32];
    char TEL[32];
    while(1)
    {
        printf("1.按ID搜索\n2.按姓名搜索\n3.按号码搜索\n0.退出\n");
        switch(choice())
        {
            case 1:
                printf("输入ID:\n");
                scanf("%s",ID);
                PersonSearchByID(head,ID);
                break;
            case 2:
                printf("输入姓名:\n");
                scanf("%s",NAME);
                PersonSearchByNAME(head,NAME);
                break;
            case 3:
                printf("输入号码:\n");
                scanf("%s",TEL);
                PersonSearchByTEL(head,TEL);
                break;
            case 0:
                return;
            default:
                printf("选项不存在!请重新输入\n");
                break;
        }
    }
}
//菜单
void menu()
{   
    printf("**********通讯录***********\n");
    printf("1.新建联系人:\n");
    printf("2.删除联系人:\n");
    printf("3.修改联系人:\n");
    printf("4.搜索联系人:\n");
    printf("5.查看联系人:\n");
    printf("0.退出:\n");
}
//数据保存
void converse(Person* lt)
{
    FILE* fp=fopen("infor.txt","a");
    if(NULL==fp)
    {
        perror("fopen");
        return;
    }
    if(1!=fwrite(lt,sizeof(Person),1,fp))
    {
        perror("fwrite");
        return;
    }
    fclose(fp);
}

void ReadOldData(Person* head)
{
    //以只读方式打开数据存放的文件
    FILE* fp=fopen("infor.txt","r");
    if(NULL==fp)
    {
        perror("fopen");
        return;
    }
    while(1)
    {
        Person* lt=AddressListCreat();
        //如果没读到数据
        if(fread(lt,sizeof(Person)-sizeof(Person*),1,fp)==0)
        {
            perror("fread");
            free(lt);
            return;
        }
        fseek(fp,1,SEEK_CUR);
        //读到则进行直接插入排序
        if(AddressListEmpty(head))
        {   
            lt->next=head->next;
            head->next=lt;
        }
        else
        {
            Person* p=head;
            int flag=0;
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
        }
        //如果读到文件末尾
        if(feof(fp))
        {
            return;
        }
    }
    fclose(fp);
}

void NewDataConverse(Person* head)
{
    if(AddressListEmpty(head))
    {
        return;
    }
    FILE* fp=fopen("infor.txt","w");
    if(NULL==fp)
    {
        perror("fopen");
        return;
    }
    Person* p=head;
    while(1)
    {   
        p=p->next;
        if(p==NULL)
        {
            break;
        }
        if(1!=fwrite(p,sizeof(Person)-sizeof(Person *),1,fp))
        {
            perror("fwrite1");
            break;
        }
        char a='\n';
        if(1!=fwrite(&a,sizeof(char),1,fp))
        {
            perror("fwrite2");
            break;
        }
        
    }
    fclose(fp);
}