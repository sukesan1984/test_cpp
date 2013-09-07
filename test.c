#include        <stdio.h>
#include        <string.h>
#include <sys/time.h>
#include <stdlib.h>>
/*const char *mystrstr(const char *text, const char *pat);*/

int isMatch(char *text, char *pat){
   /*if(strlen(text) < strlen(pat)){*/
       /*return 0;*/
   /*}*/

   if(*pat == '\0'){//最後までいったら、全てマッチした
       return 1;
   }

   if(text[0] != pat[0]){
       return 0;
   }

   return isMatch(text+1, pat+1);
};

char* makeText(){
    char *text = (char*) malloc(1024 * 1024 * 100);
    int i;

    for(i = 0; i< 1024 * 1024 * 100 - 1; i++){
        text[i] = 0x20 + rand() % 0x60;
    }
    return text;
};

char* mystrstr(char* text, char* pat){
    int textLength = strlen(text);
    int patLength = strlen(pat);
    if(textLength < patLength) {
        return NULL;
    }
    if(patLength == 0){
        return text;
    }

    char first = pat[0];
    /*char *hoge = text + 1;*/
    printf("%c", *(text + 1));

    int i = 0;

    for(i=0; i < textLength - 1; i++){
        //一文字目が見つかるまで
        if (first != text[i]){
            continue;
        }
        if(isMatch(&text[i], pat)){
            return &text[i];
        }
    }
    return NULL;
};

int main(void)
{
        char    s1[] = "abcdefghijklmn";        /* 検索対象文字列 */
        char    s2[] = "defgh";                 /* 一致する場合 */
        char    s3[] = "xyz";                   /* 一致しない場合 */
        char    s4[] = "abcdefghijklmnopqr";    /* 検索対象文字列より長い場合 */
        char    s5[] = "";                      /* \0 */
        char    *sp;

        sp = mystrstr(s1,s2);
        printf("一致する場合 : %s\n",sp);
        sp = mystrstr(s1,s3);
        printf("一致しない場合 : %s\n",sp);
        sp = mystrstr(s1,s4);
        printf("検索対象文字列より長い場合 : %s\n",sp);
        sp = mystrstr(s1,s5);
        printf("\\0 : %s\n",sp);

        
        /*char *text = makeText();*/
        /*char *pat = "sukesan";*/

        /*int start;*/
        /*int end;*/
        /*struct timeval start_timeval, end_timeval;*/
        /*double sec_timeofday;*/

        /*printf("本物\n");*/

        /*gettimeofday( &start_timeval, NULL );*/

        /*sp = strstr(text, pat);*/
        /*printf("%s\n", sp);*/

        /*gettimeofday( &end_timeval, NULL );*/
        /*sec_timeofday = (end_timeval.tv_sec - start_timeval.tv_sec)*/
                /*+ (end_timeval.tv_usec - start_timeval.tv_usec) / 1000000.0;*/
        /*printf("%f\n", sec_timeofday);*/


        /*printf("俺\n");*/
        /*gettimeofday( &start_timeval, NULL );*/

        /*sp = mystrstr(text, pat);*/
        /*printf("%s\n", sp);*/

        /*gettimeofday( &end_timeval, NULL );*/
        /*sec_timeofday = (end_timeval.tv_sec - start_timeval.tv_sec)*/
                /*+ (end_timeval.tv_usec - start_timeval.tv_usec) / 1000000.0;*/
        /*printf("%f\n", sec_timeofday);*/
        
        return 0;
}

