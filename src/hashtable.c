#include "hashtable.h"

struct file *files[HASHSIZE];

void init()
{
    int i;
    for(i = 0; i < HASHSIZE; ++i)
    {
        files[i] = NULL;
    }
}

int search(char *s)
{
    int num = hash(s);
    if(files[num] != NULL)
    {
        struct file *p = files[num];
        while(p != NULL)
        {
            if(strcmp(p->name, s) == 0)
                return TRUE;
            p = p->next;
        }
    }
    return FALSE;
}

char case_insensitive(char ch)
{
    if(isupper(ch))
    {
        return ch - 'A' + 'a';
    }
    return ch;
}

int hash(char *s)
{
    return case_insensitive(s[0]) - 'a';
}

void show_all()
{
    int i;
    struct file *p = NULL;
        for(i = 0; i < HASHSIZE; ++i)
        {
            p = files[i];
            while(p != NULL)
            {
                printf("%s\n", p->name);
                p = p->next;
            }
            printf("\n");
        }
}

void insert(char *s)
{
    if(search(s) == FALSE)
    {
        int num = hash(s);
        struct file *newnode = (struct file *)malloc(sizeof(struct file));
        strcpy(newnode->name, s);
        if(files[num] == NULL)
        {
            files[num] = newnode;
            files[num]->next = NULL;
        }
        else
        {
            newnode->next = files[num];//插入链表的方式为头插
            files[num] = newnode;
        }
    }
    //else do nothing;
}
