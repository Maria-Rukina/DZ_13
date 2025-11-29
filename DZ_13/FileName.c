#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
    system("chcp 1251");

    char str[100];

    printf("Введите строку: ");
    //ели ели бобров
    fgets(str, sizeof(str), stdin); 
    str[strcspn(str, "\n")] = '\0';  // убрать \n

    char* words[50];    // до 50 слов
    int n = 0;          //счёт кол-во слов

    char* token = strtok(str, " \t");  // делим на слова по пробелам
    while (token != NULL && n < 50) 
    {
        words[n++] = token;
        token = strtok(NULL, " \t");
    }

    // Меняем местами указатели на первое и второе слово
    char* temp = words[0];
    words[0] = words[n - 1];
    words[n - 1] = temp;

    // Вывод
    for (int i = 0; i < n; i++) 
    {
        printf(" ");
        printf("%s", words[i]);
    }
    printf("\n");

    return 0;
}
