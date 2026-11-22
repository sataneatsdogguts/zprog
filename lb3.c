#include <stdio.h>
#include <stdlib.h>

struct Size{
    int row;
    int col;
} size = {1, 1};

void PrintArr(char **arr2, int *len){
    for (int i = size.row-1; i >= 0; i--) {
        for (int j = 0; j < len[i]; j++) {
            printf("%c ", arr2[i][j]);
        }
        // printf("\n");
    }
        printf("\n");
}

char* resize1(char *arr, int new_len){
    char * tmp = (char*)realloc(arr, sizeof(char) * new_len);
    return tmp;
}

char** resize2(char **arr, int **len){
    char ** tmp = (char**)realloc(arr, sizeof(char*) * (size.row + 1));
    *len = (int*)realloc(*len, sizeof(int) * (size.row + 1));
    tmp[size.row] = malloc(sizeof(char));
    (*len)[size.row] = 0;
    size.row++;
    return tmp;
}

int main() {
    char string[1024];
    scanf("%s", string);
   
    char arr[1024];
    int *len = calloc(size.row, sizeof(int)); 
    char **arr2 = malloc(size.row * sizeof(char*));
    for (int i = 0; i < 1; i++) {
        arr2[i] = malloc(size.col * sizeof(char));
    }
    
    int p = -1;
    int j = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != '}') {
             if (string[i] == '{'){
                 p++;
                 if (p > size.row - 1) {
                     arr2 = resize2(arr2, &len); 
                 }
             }
            arr[j] = string[i];
            j++;
        }
        else {
            j--; 
            while (j >= 0 && arr[j] != '{'){
                len[p]++;
                if (len[p] > size.col) size.col = len[p];
                arr2[p] = resize1(arr2[p], len[p]);
                arr2[p][len[p] - 1] = arr[j];
                arr[j] = ' ';
                j--;
            }
            if (j >= 0) arr[j] = ' ';
            p--;
        }
        // printf("%d %d \n", size.row, size.col);
    }
    PrintArr(arr2, len);

    for (int i = 0; i < size.row; i++) free(arr2[i]);
    free(arr2);
    free(len);
    return 0;
}

