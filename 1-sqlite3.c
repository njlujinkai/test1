#include<stdio.h>
#include<string.h>
#include<sqlite3.h>
int print(void* arg,int ncolumn,char** f_value,char** f_name)
{
    //name表示字段名
    //value表示数据
    int i;
    for(i=0;i<ncolumn;i++)
    {
        printf("%s=%s ",f_name[i],f_value[i]);
    }
    printf("\n");
    return 0;
}
int main(int argc,const char* argv[])
{
    sqlite3* ppdb;
    //打开或创建数据库
    int ret=sqlite3_open("stu.db",&ppdb);
    if(SQLITE_OK!=ret)
    {
        printf("sqlite3_open:%s\n",sqlite3_errmsg(ppdb));
        return -1;
    }
    //创建表
    char sql[128]={0};
    //将创建表的sql语句写入数组sql中去
    sprintf(sql,"create table if not exists stu(id int,name char,sex char,score int);");
    //执行数组sql中的sql语句
    ret=sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
    if(SQLITE_OK!=ret)
    {
        printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    //插入数据
    int i;
    int id,score;
    char name[32]={0};
    char sex;
    //循环插入两条记录
    for(i=0;i<2;i++)
    {
        printf("请输入学号,姓名，性别，分数\n");
        scanf("%d%s %c%d",&id,name,&sex,&score);
        //插入
        sprintf(sql,"insert into stu values(%d,'%s','%c',%d);",id,name,sex,score);
        ret=sqlite3_exec(ppdb,sql,NULL,NULL,NULL);
        if(SQLITE_OK!=ret)
        {
            printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
            return -1;
        }
        memset(sql,0,sizeof(sql));
    }
    //查询数据方法1(使用终端命令)
    sprintf(sql,"select* from stu;");
    ret=sqlite3_exec(ppdb,sql,print,NULL,NULL);
    if(SQLITE_OK!=ret)
    {
        printf("sqlite3_exec:%s\n",sqlite3_errmsg(ppdb));
        return -1;
    }
    memset(sql,0,sizeof(sql));
    //查询数据方法2(调用api)
    // sprintf(sql,"select* from stu;");
    // char **result;
    // int row,column;
    // //获取表
    // ret=sqlite3_get_table(ppdb,sql,&result,&row,&column,NULL);
    // if(SQLITE_OK!=ret)
    // {
    //     printf("sqlite3_get_table:%s\n",sqlite3_errmsg(ppdb));
    //     return -1;
    // }






    memset(sql,0,sizeof(sql));
    return 0;
    //第二次修改
	
}
