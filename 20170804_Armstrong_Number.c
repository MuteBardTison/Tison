//Amstrong Number
#include<stdio.h>
#include<math.h>
int main(){
    int i;
    for(i=1;i<1000;i++){
        if(i == pow((i/1000),3)+pow((i/100%10),3)+pow((i/10%10),3)+pow((i%10),3))
            printf("%d\n", i);
    }
    return 0;
}
