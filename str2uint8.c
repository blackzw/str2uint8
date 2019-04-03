#include <stdio.h>
#include <string.h>
#define DEFAULT_FUNC 0  //默认功能
#define NO_SPLIT_OUTPUT 1 //输出没有', 0x'的分割，连续输出一行hex
#define OPTION_NO_SPLIT "nosplit"
int main(int argc, char** argv)
{
	printf("input: %s\n", argv[1]);

    int len = strlen(argv[1]);
    int i;
    int funcType = 0;
    if(argc > 2){
        char *p = strstr(argv[2], "--");
        if((p == NULL) || (p != argv[2])){
            p = strstr(argv[2], "-"); 
            if((p == NULL) || (p != 0)){
                printf("unknown option!\n");
            }
            else{
                printf("undefined option!\n"); 
            }
        }
        else{
            p = argv[2]+2; //获取option字段的起始
            printf("option is: %s\n", p);
            if (strcmp(p, OPTION_NO_SPLIT) == 0)
            {
                funcType = NO_SPLIT_OUTPUT;
            }
        }
    }
    
    switch (funcType){ // 选项部分
        case DEFAULT_FUNC:{ // 默认功能
            i = 0;
            printf("0x%x, ", argv[1][i]);
            for(i = 1; i < len; i++){
                if (i%8 == 0)
                {
                    printf("\n0x%x", argv[1][i]);
                }
                else{
                    printf("0x%x", argv[1][i]);
                }
                if (i+1 != len)
                {
                    printf(", ");
                }
            }
            printf("\n");
            break;
        }
        case NO_SPLIT_OUTPUT:{
            i = 0;
            printf("0x%x", argv[1][i]);
            for(i = 1; i < len; i++){
                printf("%x", argv[1][i]);
            }
            printf("\n");
            break;
        }
        default:
            break;
    }
    
    return 0;
}
