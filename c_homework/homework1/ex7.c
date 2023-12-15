#include <string.h>


int str_in_str1(char *stroka1, char *stroka2)
{
    if (strlen(stroka1) > strlen(stroka2) || (*stroka2 == *"") || (*stroka1 == *""))
    {
        return 0;
    }
    int i = 0;
    int g = 0;
    int flag = 1;
    int count = 0;
    for (g = 0; g <= strlen(stroka2) - strlen(stroka1); ++g)
    {
        flag = 1;
        for (i = 0; i < (strlen(stroka1)); ++i)
        {
            if (*(stroka1 + i) != *(stroka2 + g + i))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            count++;
        }
    }
    return count;
}