#include <stdio.h>

int strIsEqual(char * str1, char * str2){
    int i;
    int bool = 1;
    for(i = 0; str1[i] != '\0' || str2[i] != '\0'; i++){
        if(str1[i] != str2[i])
            bool = 0;
    }
    return bool;
}

int main() {
    char TABLE[37][2][7] =
              {  {".\0", ".-.-.-\0"},
                 {"0\0", "-----\0"},    {"1\0", ".----\0"},      {"2\0", "..---\0"},
                 {"3\0", "...--\0"},    {"4\0", "....-\0"},      {"5\0", ".....\0"},
                 {"6\0", "-....\0"},    {"7\0", "--...\0"},      {"8\0", "---..\0"},
                 {"9\0", "----.\0"},
                 {"a\0", ".-\0"},       {"b\0", "-...\0"},       {"c\0", "-.-.\0"},
                 {"d\0", "-..\0"},      {"e\0", ".\0"},          {"f\0", "..-.\0"},
                 {"g\0", "--.\0"},      {"h\0", "....\0"},       {"i\0", "..\0"},
                 {"j\0", ".---\0"},     {"k\0", "-.-\0"},        {"l\0", ".-..\0"},
                 {"m\0", "--\0"},       {"n\0", "-.\0"},         {"o\0", "---\0"},
                 {"p\0", ".--.\0"},     {"q\0", "--.-\0"},       {"r\0", ".-.\0"},
                 {"s\0", "...\0"},      {"t\0", "-\0"},          {"u\0", "..-\0"},
                 {"v\0", "...-\0"},     {"w\0", ".--\0"},        {"x\0", "-..-\0"},
                 {"y\0", "-.--\0"},     {"z\0", "--..\0"}
               } ;
    const int TABLE_SIZE = 37;

    int i;
    int u;

    char morse[100] = {0};

    //input
    printf("Code morse (avec un '/' entre chaque lettres) :\n");
    scanf("%s", morse);

    //separate with '/'
    char morseSep[100][100] = {0};
    
    int o = 0;
    int p = 0;
    for(i = 0; i<100; i++){
        if(morse[i] == '/'){
            morseSep[o][p] = '\0';
            p = 0;
            o++;
        }else{
            morseSep[o][p] = morse[i];
            p++;
        }
    }

    //decode
    char result[100] = {0};
    int b;
    for(i = 0; i<100; i++){
        if(morseSep[i][0] != 0){
            int b = 0;
            for(u = 0; u<TABLE_SIZE && b == 0; u++){
                if(strIsEqual(morseSep[i], TABLE[u][1])){
                    result[i] = TABLE[u][0][0];
                    b = 1;
                    printf("%c", TABLE[u][0][0]);
                }
            }
        }
    }
    printf("\n");

    //output
    printf("Le resultat est : \n");
    for(i = 0; i<100; i++){
        if(result[i] != 0)
            printf("%s", result[i]);
    }
    printf("\n");

    return 0;
}