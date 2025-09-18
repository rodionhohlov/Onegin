//#include<TXlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

#define FILE_ADR_ASSERT(ex) if(!(ex)) { printf("error of reading file\n"); abort();}
#define STRING_COUNT_ASSERT(ex) if (!(ex)) { printf("counting strings returns adress NULL"); abort();}

void output_file(char* text);

int file_line_cnt(int* cnt, char* flag);

int file_line_cnt(char* flag);

int getc_len(char* str);

int main(void) {

    FILE* onegin = fopen("onegin.txt", "r");

    FILE_ADR_ASSERT(onegin);

    const char file_name[11] = "onegin.txt";

    struct stat file_info = {};
    stat(file_name, &file_info);

    rewind(onegin);

    int buf_len = file_info.st_size + 1;

    char* buffer = (char*)calloc(1, buf_len);

    printf("%d\n", buf_len);

    fread(buffer, sizeof(char), buf_len, onegin);

    buffer[buf_len-1] = '\0';

    /*for (int i = 0; i < 200; i++)
        printf("%c", buffer[i]);*/


    //printf("%s", buffer);

    char* flag = buffer;
    char* index = NULL;
    int str_count = file_line_cnt(flag);
    int ind = 0;

    int other_len = getc_len(buffer);

    printf("first stlen %d\n", other_len);

    char** stringer = (char**)calloc(str_count, sizeof(char*));

    stringer[ind] = buffer;

    ind++;

    for(int i = 0; i < buf_len; i++) {

        if (buffer[i] == '\n') {
            stringer[ind] = (char*)(buffer[i] + (ind+1)*sizeof(char*));
            ind++;
        }

        printf("adress flag is %p\n", stringer[ind]);

        if (index == NULL) {
            printf("adress is NULL!!!!!!\n");
            break;
        }

        printf("%s\n", stringer[i]);
    }


    printf("uncommon stlen %d\n", str_count);

    fclose(onegin);

    output_file(buffer);

    return 0;
}

void output_file(char* text) {

    FILE* res_out = fopen("output.txt", "w");

    if (res_out == NULL) {
        printf("error opening output file\n");
        return;
    }

   // fputs(text, res_out);
    //fprintf(res_out, "Lil gang");
    fclose(res_out);
}

int file_line_cnt(char* flag) {

    char* index = NULL;
    int cnt = 1;

    while(flag != NULL) {

        index = strchr(flag, '\n');

        flag = index + 1;

        //printf("adress flag is %p\n", flag);

        //if (strcmp("wh

        cnt++;

        if (index == NULL)
            break;
    }

    return cnt;
}

int getc_len(char* str) {
    int cnt = 1;

    for(int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            cnt++;
    }

    return cnt;
}

