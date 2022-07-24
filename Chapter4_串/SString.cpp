#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 255 //因为弃用ch[0]，所以最大存储为254

typedef struct
{
    char ch[MAXLEN]; //弃用ch[0]
    int length;
} SString;

//串的赋值操作
bool StrAssign(SString &T, char *chars)
{
    int len = 0;
    while (chars[len] != '\0')
    {
        len++;
    }
    if (len >= MAXLEN)
        return false;
    for (int i = 1; i <= len; i++) //从ch[1]开始存储字符
        T.ch[i] = chars[i - 1];
    T.length = len;
    return true;
}

//求串长
int StrLength(SString S)
{
    return S.length;
}

//复制操作
void StrCopy(SString &T, SString s)
{
    for (int i = 1; i <= s.length; i++)
        T.ch[i] = s.ch[i];
    T.length = s.length;
}

//判空
bool StrEmpty(SString S)
{
    return S.length < 1;
}

//求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    //子串范围越界
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}

//比较操作
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

//定位操作
int Index(SString S, SString T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i <= n - m + 1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
            ++i;
        else
            return i;
    }
    return 0;
}

//清空串
void ClearString(SString &S)
{
    S.length = 0;
}

//销毁串
void DestroyString(SString &S)
{
    for (int i = 1; i <= S.length; i++)
        S.ch[i] = '\0';
    S.length = 0;
}

//串联接
bool Concat(SString &T, SString S1, SString S2)
{
    T.length = S1.length + S2.length;
    int i = 1;
    for (; i <= S1.length; i++)
        T.ch[i] = S1.ch[i];
    for (; i <= T.length; i++)
        T.ch[i] = S2.ch[i - S1.length];
    return true;
}

void print(SString S)
{
    for (int i = 1; i <= S.length; i++)
        printf("%c", S.ch[i]);
    printf("\nlen=%d", S.length);
}

int main()
{
    char a[] = "testStrAssign";
    SString s;
    StrAssign(s, a);
    print(s);
}