#include <stdio.h>
#include <string.h>

int main(){
    char a[1000];
    int b,c;
    scanf("%s",&a);
    b=strlen(a);
    printf("%c",a[0]);
    for(int i=0;i<b;i++){
        if(a[i]=='-'){
        printf("%c",a[i+1]);
    }
}
}
