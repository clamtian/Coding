#include<stdio.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include "utility.h"


void byteorder(){
    union{
        short value;
        char union_bytes[3];
    }test;
    test.value = 0x0102;
    if((test.union_bytes[0] == 1) && (test.union_bytes[1] == 2)){
        printf("big endian\n");
    }else if((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1)){
        printf("little endian\n");
    }else{
        printf("unknown...\n");
    }
}
int main(){
    in_addr in1, in2;
    in1.s_addr = inet_addr("1.2.3.4");
    in2.s_addr = inet_addr("10.24.3.4");
    char *sz1 = inet_ntoa(in1);
    char *sz2 = inet_ntoa(in2);
    cout << sz1 << endl;
    cout << sz2 << endl;
}

