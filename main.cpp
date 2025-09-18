#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

#define FILE_ADR_ASSERT(ex) if(!(ex)) { printf("error of reading file\n"); abort();}
#define STRING_COUNT_ASSERT(ex) if (!(ex)) { printf("counting strings returns adress NULL"); abort();}

int main(void) {

    FILE* onegin = fopen("onegin.txt", "r");

    FILE_ADR_ASSERT(onegin);

    const char* file_name = "onegin.txt";

    struct stat file_info = {};

    stat(file_name, &file_info);

    rewind(onegin);

    int buf_len = file_info.st_size;

    char* buffer = (char*)calloc(1, buf_len + 1);

    printf("%d\n", buf_len);

    fread(buffer, 1, buf_len, onegin);

    buffer[buf_len+1] = '\0';

    int str_count = 0;

   /* for (int i = 0; i < 100; i++)
        printf("%s", buffer);   */

    char* index = NULL;        //проход по указателям ищем \n
                               //qsort
    while(*index != '\0') {

        int flag = 0;

        index = strchr(buffer, '\n');

       // flag = buffer + index;

        printf("adress str_cnt is %p\n", index);

        str_count++;

        if (index == NULL)
            break;
    }

    printf("%d\n", str_count);

    fclose(onegin);

    return 0;
}
