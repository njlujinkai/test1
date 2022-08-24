#include "func.h"
int main(int argc,const char*argv[])
{
    //建立空通讯录
    Person* head=AddressListCreat();
    ReadOldData(head);
    while(1)
    {
        menu();
        switch(choice())
        {   
            case 0:
                NewDataConverse(head);
                printf("退出中...\n");
                sleep(1);
                return 0;
            case 1:
                NewPersonInsertSort(head);
                printf("新建联系人成功!\n");
                sleep(1);
                break;
            case 2:
                DeleteScreen(head);
                sleep(1);
                break;
            case 3:
                FixScreen(head);
                sleep(1);
                break;
            case 4:
                SearchScreen(head);
                sleep(1);
                break;
            case 5:
                AddressListPrint(head);
                sleep(1);
                break;
            default:
                printf("选项不存在!重新输入:\n");
                sleep(1);
                break;
        }
    }
}