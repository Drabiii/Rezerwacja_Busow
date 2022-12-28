#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login() {
    int a = 0, i = 0;
    char username[10], c = ' ';
    char password[10], code[10];
    char defaultuser[10] = "user";
    char defaultpassword[10] = "pass";

    system("cls");

    printf("\nZaloguj sie do systemu!\n\n");
    printf("\nWprowadz Login:  ");
    scanf("%9s", &username, 9);
    clearbuff(); //wywoa³enie fukncji czyszczenia buforu
    printf("\nWprowadz Haslo:  ");
    while (i < 10) {
        password[i] = getch();
        c = password[i];
        if (c == 13) break;
        else printf("*");
        i++;
        if (i == 9) {
            printf("\n\n\nWprowadzono za duzo znakow!!!\n\n");
            printf("Nacisnij dowolny klawisz, aby kontynuowac...");
            getch();
            return 1;
        }
    }
    password[i] = '\0';
    i = 0;

    int counter = 0;
    while (i < strlen(defaultuser)) {

        if ((username[i] == defaultuser[i]) && strlen(defaultuser) == strlen(username)) {

        }
        else {
            counter += 1;
        }
        if (password[i] == defaultpassword[i] && strlen(defaultpassword) == strlen(password)) {

        }
        else {
            counter += 1;
        }
        i++;
    }
    if (counter > 0) {
        printf("\nWprowadzono bledne dane !");
        getchar();
        exit(0);

    }
    else {
        printf("\n-------------------------\n");
        printf("\n\n\nPoprawnie zalogowano!");
        printf("\n\nNacisnij dowolny znak, aby kontynuowac....");
        getchar();
    }
    return 0;
}