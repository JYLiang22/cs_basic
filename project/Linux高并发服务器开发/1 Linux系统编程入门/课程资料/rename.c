/*
    #include <stdio.h>
    int rename(const char *oldpath, const char *newpath);

*/
#include <stdio.h>

int main(int argc, char *argv[]){

    if(argc < 3){
        printf("arguments are not enough!\n");
        return -1;
    }

    int ret = rename(argv[1], argv[2]);
    if(ret == -1){
        perror("rename");
        return -1;
    }
    else{
        printf("successfully rename %s to %s!\n", argv[1], argv[2]);
    }

    return 0;
}