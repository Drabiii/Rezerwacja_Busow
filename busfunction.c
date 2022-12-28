#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// exit(5) - brak pliku
// exit(6) - uszkodzone dane w pliku

void clearbuff() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int displaybus(char bus[20], int infobusoption) {
    char c;
    char source[15];
    int i = 1;
    if (infobusoption == 1) {
        strcpy(source, "miejsca1.txt");
    }
    else {
        strcpy(source, "miejsca2.txt");
    }
    FILE* file;
    file = fopen(source, "r");
    if (file == NULL) {
        printf("Nie znaleziono pliku!!!");
        getch();
        exit(5);
    }
    c = fgetc(file);
    printf("\n\t\t%s\n\n", bus);

    while (c != EOF) {
        if ((c != '1') && (c != '0')) {
            printf("Dane w pliku zostaly uszkodzone !\n");
            printf("Znak znajdujacy sie na pozycji %d jest niepoprawny!!!\n\n", i);
            printf("Nacisnij dowolny znak aby zakonczyc dzialanie programu....");
            getch();
            exit(6);
        }

        if (c == '1') {
            printf("%d. ", i);
            printf("[X]");
        }
        else {
            printf("%d. ", i);
            printf("[ ]");
        }
        c = fgetc(file);

        if (i % 2 == 0) {
            printf("\t");
            if (i % 4 == 0) {
                printf("\n");
            }
            else {
                printf("\t");
            }
        }
        else {
            printf("\t");
        }
        i++;
    }
    fclose(file);

    return 0;
}


int bookbus(int bookbusoption) {
    char c;
    char source[15];
    int i = 1;
    int numsit = 0;
    if (bookbusoption == 1) {
        strcpy(source, "miejsca1.txt");
    }
    else {
        strcpy(source, "miejsca2.txt");
    }

    FILE* file;
    file = fopen(source, "r+");
    if (file == NULL) {
        printf("Nie znaleziono pliku!!!");
        getch();
        exit(5);
    }

    printf("\nPodaj numer miejsca ktore chcesz zarezerwowac: ");
    scanf("%d", &numsit);
    clearbuff();
    while ((numsit >= 65) || (numsit <= 0)) {
        printf("\n\nNie ma takiego miejsca!!!\n");
        printf("Wybierz miejsce z przedzialu od 1 do 64 !!!\n\n");
        printf("----------------------------------------------");
        printf("\nPodaj numer miejsca ktore chcesz zarezerwowac: ");
        scanf("%d", &numsit);
        clearbuff();
    }
    fseek(file, numsit - 1, SEEK_SET);
    c = fgetc(file);
    if (c == '1') {
        bookinfoerror(&numsit);
        fseek(file, numsit - 1, SEEK_SET);
        c = fgetc(file);
        while (c == '1') {
            bookinfoerror(&numsit);
            fseek(file, numsit - 1, SEEK_SET);
            c = fgetc(file);
        }
    }
    if (c == '0') {
        fseek(file, numsit - 1, SEEK_SET);
        fputc('1', file);
    }
    fclose(file);
}


int cancelbus(int cancelbusoption) {
    char c;
    char source[15];
    int numsit = 0;
    int i = 1;
    if (cancelbusoption == 1) {
        strcpy(source, "miejsca1.txt");
    }
    else {
        strcpy(source, "miejsca2.txt");
    }

    FILE* file;
    file = fopen(source, "r+");
    if (file == NULL) {
        printf("Nie znaleziono pliku!!!");
        getch();
        exit(5);
    }

    printf("\nPodaj numer miejsca dla ktorego chcesz anulowac rezerwacje : ");
    scanf("%d", &numsit);
    clearbuff();
    while ((numsit >= 65) || (numsit <= 0)) {
        printf("\n\nNie ma takiego miejsca!!!\n");
        printf("Wybierz miejsce z przedzialu od 1 do 64 !!!\n\n");
        printf("--------------------------------------------------------------\n");
        printf("\nPodaj numer miejsca dla ktorego chcesz anulowac rezerwacje : ");
        scanf("%d", &numsit);
        clearbuff();
    }
    fseek(file, numsit - 1, SEEK_SET);
    c = fgetc(file);
    if (c == '0') {
        cancelinfoerror(&numsit);
        fseek(file, numsit - 1, SEEK_SET);
        c = fgetc(file);
        while (c == '0') {
            cancelinfoerror(&numsit);
            fseek(file, numsit - 1, SEEK_SET);
            c = fgetc(file);
        }
    }
    if (c == '1') {
        fseek(file, numsit - 1, SEEK_SET);
        fputc('0', file);
    }
    fclose(file);
}




int bookinfoerror(int* numsit) {
    char yesorno[2];
    printf("\n\nPodane miejsce jest ZAREZERWOWANE!\n\n");
    printf("Czy chcesz wyjsc ? Y/N\n");
    scanf("%2s", yesorno, 2);
    clearbuff();
    if (yesorno[0] == 'y') {
        return menu();
    }
    printf("-----------------------------------------------\n");
    printf("\nPodaj numer miejsca ktore chcesz zarezerwowac: ");
    scanf("%d", numsit);
    clearbuff();
    while ((*numsit >= 65) || (*numsit <= 0)) {
        printf("\n\nNie ma takiego miejsca!!!\n");
        printf("Wybierz miejsce z przedzialu od 1 do 64 !!!\n\n");
        printf("----------------------------------------------");
        printf("\nPodaj numer miejsca ktore chcesz zarezerwowac: ");
        scanf("%d", numsit);
        clearbuff();
    }
}


int cancelinfoerror(int* numsit) {
    char yesorno[2];
    printf("\n\nPodane miejsce NIE JEST ZAREZERWOWANE!!!\n\n");
    printf("Czy chcesz wyjsc ? Y/N\n");
    scanf("%2s", yesorno, 2);
    clearbuff();
    if (yesorno[0] == 'y') {
        return menu();
    }
    printf("-------------------------------------------------------------\n");
    printf("\nPodaj numer miejsca dla ktorego chcesz anulowac rezerwacje : ");
    scanf("%d", numsit);
    clearbuff();
    while ((*numsit >= 65) || (*numsit <= 0)) {
        printf("\n\nNie ma takiego miejsca!!!\n");
        printf("Wybierz miejsce z przedzialu od 1 do 64 !!!\n\n");
        printf("--------------------------------------------------------------\n");
        printf("\nPodaj numer miejsca dla ktorego chcesz anulowac rezerwacje : ");
        scanf("%d", numsit);
        clearbuff();
    }
}
