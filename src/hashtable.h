#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAMELENTH 20
#define HASHSIZE      26
#define TRUE          1
#define FALSE         0

struct file {
    char name[FILENAMELENTH];
    struct file *next;
};

void insert(char *s);//将数据插入哈希表中
int search(char *s);//查询某个数据是否在哈希表中存在
void show_all();//显示哈希表中的所有数据
int hash();//哈希函数，返回在哈希表中的位置，哈希表各项元素以文件名首字母a-z区分
void init();//完成初始化工作
char case_insensitive(char ch);//将大写字母转化为小写字母，不区分大小写

#endif
