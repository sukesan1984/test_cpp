#include        <stdio.h>
#include        <string.h>
int CV[0x100];

char* shiftand(char* text, char* pat){
    int i;
    int plen = strlen(pat);
    for(i = 0; i < 0x00; ++i){
        CV[i] = 0;
    }

    int mask = 1;
    for(i = 0; i < plen; ++i, mask <<= 1){
        //一周目
        //CV['a']  |= 001
        //CV['a']: 001
        //二周目
        //CV['b']  |= 010
        //CV['b']: 010
        //三周目
        //abcの時
            //CV['c'] |= 100
            //CV['c']: 100
        //abaの時
            //CV['a'] |= 100 //CV['a']: 001 |= 100
            //CV['a']: 101
        CV[pat[i]] |= mask;
    }

    int R = 0;
    char ch;

    mask = 1 << (plen - 1); //長さ分だけビットを移動
    while( (ch=*text++)!='\0'){
        R = ((R << 1) + 1) & CV[ch];
        if((R & mask) != 0) return text - plen;
    }
    return NULL;
};

int main(void)
{
    printf("%s\n", shiftand("hogefdsa", "ef"));
}
//memo
// abc: CV['a'] = 001
// abc: CV['b'] = 010
// aba: CV['a'] = 101
// abc: CV['b'] = 010
//int hoge = 1;  // 0001
//hoge <<= 1;    // 0010
//printf("%d\n", hoge);
//hoge <<= 1;    // 0100
//printf("%d\n", hoge);
//hoge <<= 1;    // 1000
//printf("%d\n", hoge);
