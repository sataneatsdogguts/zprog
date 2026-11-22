//week 12
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("expected 3 arguments\n");
        return 1;
    }

    const char * PATH = argv[1];
    const char * input_string = argv[2];

    FILE* f = fopen(PATH, "r");
    if (!f){
        printf("enter a valid path\n");
        return 2;
    }

    const int SIZE = 2048;
    int n;
    char buffer[SIZE];
     
    int res = -1;
    int o = 0;
    int cur_idx = 0;

    while ((n = fread(buffer, 1, SIZE - 1, f)) > 0 ) {
        buffer[n] = '\0';
        // printf("%s\n", buffer);
        for (int i = 0; i <= n; i++) {
            // printf("%c\n", buffer[i]);
            if (buffer[i] == input_string[cur_idx]){
                if (res == -1) res = (SIZE-1)*o + i;
                if (cur_idx == strlen(input_string) - 1) {
                    printf("\n%d\n", res);
                    return 0;
                }
                cur_idx += 1;
            }
            else {
                res = -1;
                cur_idx = 0;
            }
        }
        o+=1;
    }
    printf("%d\n", res);
    return 0;
}
