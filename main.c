#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_SIZE 6

char c[1000];

void load_buffer(){
    FILE *fptr;
    if ((fptr = fopen("password.bin", "rb")) == NULL){
        printf("Error! Opening file");
    }
    fscanf(fptr, "%[^\n]", c);
}

int isValid(char psw[PASSWORD_SIZE]){
    if (strcmp(psw,c) == 0){
        printf("Password is cracked: %s\n", psw);
        return 0;
    }else{
        return -1;
    }
}

int bruteForce(){
    char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    //Brute Force Here
    char password[PASSWORD_SIZE];
    password[PASSWORD_SIZE - 1] = '\n';

    int i, j, k, l, m, n;

    for(i = 0; i < 26; ++i){
        password[0] = letters[i];
        for(j = 0; i < 26; ++j){
            password[1] = letters[j];
            for(k = 0; i < 26; ++k){
                password[2] = letters[k];
                for(l = 0; i < 26; ++l){
                    password[3] = letters[l];
                    for(m = 0; i < 26; ++m){
                        password[4] = letters[m];
                        for(n = 0; n < 26; ++n){
                            if (isValid(password) == 0){
                                return 0; //Password cracked
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Password not found!\n");
    return -1; //Password not cracked
}

int main(){
    load_buffer();
    clock_t start_time = clock();

    bruteForce();
    clock_t end_time = clock();
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}















