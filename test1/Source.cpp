#define CATCH_CONFIG_MAIN
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/catch.hpp"


void printString(char* str, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return;
}

char* concat(char* str1, char* str2, int n)
{
    char error[8] = "Wrong n";
    if (strlen(str2) < n)
        return error;
    char* c = (char*)malloc((strlen(str1) + n+1));
    for (int i = 0; i < strlen(str1); i++)
    {
        c[i] = str1[i];
    }
    for (int i = 0; i < n; i++)
    {
        c[i + strlen(str1)] = str2[i];
    }
    c[strlen(str1) + n] = '\0';
    return c;
}


void myStrCpy(char* str1, char* str2)
{
    for (int i = 0; i < strlen(str2); i++)
    {
        str1[i] = str2[i];
    }
    str1[strlen(str2)] = '\0';
    return;
}

int findIndexOf(char* s, char c)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
        {
            return i;
        }
    }
    return -1;
}


char* getAlphabet(char* str, char* alphabet)
{
    char ans[255];
    strcpy(ans, "");

    for (int i = 0; i < strlen(str); i++)
    {
        if (findIndexOf(ans, str[i]) == -1)
        {
            strncat(ans, &str[i], 1);
        }
    }
    strcpy(alphabet, ans);
    return alphabet;
}



int task11(char* str1, char* str2)
{
    char alphabet[255];
    getAlphabet(str2, alphabet);
    //printf("alphabet\n");
    //puts(alphabet);
    int cnt = 0, maxCnt = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        if (findIndexOf(alphabet, str1[i]) != -1)
        {
            cnt++;
        }
        else
        {
            if (cnt > maxCnt) {
                maxCnt = cnt;
            }
            cnt = 0;
        }

    }
    if (maxCnt == 0)
        return cnt;
    return maxCnt;
}

/*
int main()
{
    printf("1 - 2\n2 - 5\n3 - 8\n4 - 11\n");
    int q;
    scanf("%i", &q);

    if (q == 1)
    {
        char str1[255], str2[255];
        //2
        printf("2\n");
        printf("Enter two strings and integer\n");
        //strcpy(str1, "abababab");
        //strcpy(str2, "adadadad");
        scanf("%s", &str1);
        scanf("%s", &str2);
        int n = 2;
        scanf("%i", &n);

        printString(concat(str1, str2, n), strlen(str1) + n);
        printf("\n");
    }
    if (q == 2)
    {

        //5

        char str3[255], str4[255];
        printf("5\n");
        //strcpy(str3, "aaaa");
        //strcpy(str4, "cccc");
        printf("Enter 2 strings\n");
        scanf("%s", &str3);
        scanf("%s", &str4);
        myStrCpy(str3, str4);

        printString(str3, strlen(str3));
        printf("\n");

    }
    if (q == 3)
    {
        //8
        char str5[255], str6[255];
        printf("Enter a string and a symbol\n");
        char c;

        scanf("%s", &str5);
        fgetc(stdin);
        c = fgetc(stdin);
        //strcpy(str1, "aaaba");
        printf("8 answer is %i\n", findIndexOf(str5, c));
    }

    if (q == 4)
    {
        //11
        char str7[255], str8[255];
        printf("11\n");
        printf("Enter two strings\n");
        //strcpy(str1, "aaaa");
        //strcpy(str2, "acccc");
        scanf("%s", &str7);
        scanf("%s", &str8);
        printf("%i\n", task11(str7, str8));
    }


    return 0;
}
*/
TEST_CASE("CONCAT")
{
    char str1[255], str2[255];
    
   
    strcpy(str1, "a");
    strcpy(str2, "b");
    

    
    REQUIRE(strcmp(concat(str1, str2,1), "ab"));
    
    
}
TEST_CASE("myStrCpy")
{
    char str1[255], str2[255];
    

    strcpy(str1, "a");
    strcpy(str2, "b");


    myStrCpy(str1, str2);
    REQUIRE(strcmp(str1, str2));
}
TEST_CASE("findIndexOf")
{
    char str5[255], str6[255];
   
    char c = 'b';
    strcpy(str6, "aaaba");
    REQUIRE(findIndexOf(str6, c) == 3);
}
TEST_CASE("getAlphabet")
{
    
    char str7[255], str8[255];
   
    strcpy(str7, "aaaa");
    strcpy(str8, "acccc");
   
    REQUIRE(task11(str7, str8) == 4);
}
