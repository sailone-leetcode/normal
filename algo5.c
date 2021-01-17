

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if 0
int subStringFound(char *all_start, char *all_end, char *start)
{

    int offset = 0;
    char *offset_str = NULL;
    offset_str  = start;
    char *a = NULL;
    char *b = NULL;

    for (; offset_str + offset <= all_end && offset_str - offset >= all_start; offset++)
    {
        a = offset_str + offset;
        b = offset_str - offset;
        if (*a != *b)
        {
            break;
        }
        
    }

    return offset;
    
}
#endif

int 
subStringCmp(int len, char *s, int aa, int bb, char **subStart)
{
    int offset = 0;
    int start = aa;
    int end = bb;

    if (subStart ==  NULL)
        return 0;

    for ( offset = 0; start >= 0 && end < len; ++offset, start = aa - offset, end = bb + offset)
    {
        if (s[start] != s[end])
            break;

        *subStart = &s[start];
    }

        
    
    return offset;

}



char * longestPalindrome(char * s){
    int pos = 0;
    int len  = 0;

    char *bestPos = NULL;
    int best_len = 0;

    int tmp_len = 0;
    char *tmpPos = NULL;
    int is_even = 0;



    if (s == NULL)
        return "";
    
    len = strlen(s);
    if (len == 0)
        return "";
    
    if (len == 1)
        return s;

    if (len == 2)
    {
        if (s[0] == s[1])
            return s;
        else
        {
            s[1] = 0;
            return s;
        }
        
    }

    len = strlen(s);

    //even    abba
    for (pos = 0; pos < len; pos++)
     {
        tmp_len = subStringCmp(len, s, pos, pos+1, &tmpPos);
        if (tmp_len > best_len)
        {
            best_len = tmp_len;
            bestPos = tmpPos;

            is_even = 1;

            printf("even:%d bestLen %d bestPos %s\n", pos, best_len, bestPos);
        }
     }   

    //odd abcba
    for (pos = 0; pos < len; pos++)
     {
        tmp_len = subStringCmp(len, s, pos, pos+2, &tmpPos);
        if (tmp_len+1 > best_len)
        {
            best_len = tmp_len;
            bestPos = tmpPos;

            is_even = 0;
            printf("odd:%d bestLen %d bestPos %s\n", pos, best_len, bestPos);
        }
     }   
    
    if (bestPos != NULL)
    {
        if (is_even == 1)
            bestPos[best_len * 2] = 0;
        else
            bestPos[best_len * 2 + 1] = 0;
    }
    else
    {
        s[1] = 0;
        bestPos = s;
    }
        
    return bestPos;
}


int main()
{
    char s[1000] = {0};
    char *result = NULL;
    scanf("%s", s);
    result = longestPalindrome(s);
    printf("result : %s\n", result);

    return 0;
}
