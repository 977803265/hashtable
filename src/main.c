#include "hashtable.h"

int main()
{
    char *file_names[] = {"app","because","custom","restory",\
                          "install","kill","malloc","free",\
                          "caps","apple","android","java",\
                          "js","php","python","c++"};
    int len = sizeof(file_names)/sizeof(char *);
    int i;
    for(i = 0; i < len; ++i)
    {
        insert(file_names[i]);
    }
    show_all();
    return 0;
}
