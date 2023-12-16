#include <stdio.h>

int main(){
    int a=4;
    while(a==4){
        switch(a){
            case 5:
                printf("%d", a);
            case 4:
                printf("hey");
                break;
            case 6:
                printf("world");
        }
    }
    
}