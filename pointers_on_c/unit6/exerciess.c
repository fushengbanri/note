#include<stdio.h>
#include<string.h> 
#define NUL '\0'

char *find_char();
int del_substr();
char *match();
void reverse_string();


int main()
{
    char str[]="ABCDEFGH";
    char s[]="CDE";
    char *dst;

    //dst=find_char(str, s);
    //del_substr(str, s);
    reverse_string(str);
    //printf("%s\n",dst);
    printf("%s\n", str);
}

char *find_char(char  *source, char  *chars)
{
    char *cp;
    if(source != NULL && chars != NULL){
        for(char *str=source;*str != '\0'; str++){
            for(cp=chars; *cp!='\0'; cp++)
                if( *str == *cp)
                    return str;
        }
    }
    return NULL;
}

char *match(char *str, char *want)
{
    while(*want != NUL)
        if(*want++ != *str++){
            //printf("str=%s\t want=%s\n",str,want);
            return NULL;
        }
    return str;
}

int del_substr(char *str, char  *substr)
{
    char *next;

    while(*str != NUL){
        next=match(str, substr);
        if(next!= NULL)
            break;
        str++;
    }
    if(*str == NUL)
        return 1;
    while(*str++ = *next++);
    return 0;
}

void reverse_string(char *str)
{
    char *sp=str+strlen(str)-1;
    char buf;
    int i=0;
    while(str<sp){
        buf=*sp;
        *sp--=*str;
        *str++=buf;
    }
}

