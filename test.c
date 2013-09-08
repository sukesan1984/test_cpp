#include        <stdio.h>
#include        <string.h>
#include <sys/time.h>
#include <stdlib.h>>
/*const char *mystrstr(const char *text, const char *pat);*/

int isMatch(char *text, char *pat){
   while(*pat != '\0'){
       if(*text != *pat){
           //一致しない文字が来たらfalse
           return 0;
       }
       text += 1;
       pat += 1;
   }
   return 1;
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
    while(*text != '\0'){
        char* t = text;
        char* p = pat;
        // *tと*pが一致してたらtとpのポインタを移動させて次のループB
        while(*t == *p){ //trueの間だけループ
            // pが最後までいったらマッチしたとして、textをreturn;
            if(*p == '\0'){
                return text;
            }
            t++;
            p++;
        }
        // *tと*pが一致しなくなったら、textのポインタを移動して、次のループA
        text++;
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

        /*printf("true:%d\n", isMatch("abcdef", "ab"));*/
        /*printf("false:%d\n", isMatch("abcdef", "ce"));*/
        /*printf("false:%d\n", isMatch("abcdef", "abcdefg"));*/

        /*sp = mystrstr(s1,s2);*/
        /*printf("(defghijkmln)一致する場合 : %s\n",sp);*/
        /*sp = mystrstr(s1,s3);*/
        /*printf("(null)一致しない場合 : %s\n",sp);*/
        /*sp = mystrstr(s1,s4);*/
        /*printf("(null)検索対象文字列より長い場合 : %s\n",sp);*/
        /*sp = mystrstr(s1,s5);*/
        /*printf("\\0 : %s\n",sp);*/

        
        char *text = makeText();
        char *pat = "suke";

        int start;
        int end;
        struct timeval start_timeval, end_timeval;
        double sec_timeofday;

        printf("本物\n");

        gettimeofday( &start_timeval, NULL );

        sp = strstr(text, pat);
        printf("%s\n", sp);

        gettimeofday( &end_timeval, NULL );
        sec_timeofday = (end_timeval.tv_sec - start_timeval.tv_sec)
                + (end_timeval.tv_usec - start_timeval.tv_usec) / 1000000.0;
        printf("%f\n", sec_timeofday);


        printf("俺\n");
        gettimeofday( &start_timeval, NULL );

        sp = mystrstr(text, pat);
        printf("%s\n", sp);

        gettimeofday( &end_timeval, NULL );
        sec_timeofday = (end_timeval.tv_sec - start_timeval.tv_sec)
                + (end_timeval.tv_usec - start_timeval.tv_usec) / 1000000.0;
        printf("%f\n", sec_timeofday);
        
        return 0;
}

