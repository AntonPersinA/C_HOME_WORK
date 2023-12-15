
int parenthesis_rule1(char *stroka)
{
    int skobe = 0;
    int i = 0;
    while (*(stroka + i) != *"\0")
    {
        if (*(stroka + i) == *"(" || *(stroka + i) == *"[" || *(stroka + i) == *"{")
        {
            skobe++;
        }
        if (*(stroka + i) == *")" || *(stroka + i) == *"]" || *(stroka + i) == *"}")
        {
            skobe--;
            if (skobe < 0)
                return 0;
        }
        ++i;
    }
    return !skobe;
}