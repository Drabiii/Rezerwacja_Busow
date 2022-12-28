#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "busfunction.h"

char ch[5][20] = { "FlixBus","NeoBus" };

int main() {
    if (login() == 1) {
        exit(2);
    }
    menu();
}

int menu() {
    int option;
    while (1) {
        system("cls");
        printf("\n");
        printf("Rezerwacja Busow\n\n\n");
        printf("(1) Lista Busow i miejsc\n");
        printf("\n");
        printf("(2) Rezerwacja biletu\n");
        printf("\n");
        printf("(3) Anulowanie Rezerwacji\n");
        printf("\n");
        printf("(4) Wyjscie\n\n");
        printf("\n");
        printf("Wpisz odpowiedni numer: ");
        scanf("%d", &option);
        clearbuff();
        switch (option) {
        case 1:
            infobus();
            break;
        case 2:
            book();
            break;
        case 3:
            cancel();
            break;
        case 4:
            exit(0);
        default:
            printf("\n\nWpisano Nie poprawna cyfre!!!\n");
            printf("\n\nNacisnij dowolny znak aby kontynuowac....");
            getch();
            break;
        }
    }
}

int infobus() {
    int infobusoption;
    system("cls");
    printf("\n");
    printf("Rezerwacja Busow\n\n\n");
    printf("(1) %s\n", ch[0]);
    printf("\n");
    printf("(2) %s\n", ch[1]);
    printf("\n");
    printf("(3) Powrot do menu glownego\n");
    printf("\nWprowadz numer: ");
    scanf("%d", &infobusoption);
    clearbuff();
    switch (infobusoption) {
    case 1:
        system("cls");
        displaybus(ch[0], 1);
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    case 2:
        system("cls");
        displaybus(ch[1], 2);
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    case 3:
        system("cls");
        menu();
        break;
    default:
        printf("\n\nWpisano Nie poprawna cyfre!!!\n");
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    }
}

int book() {
    int bookbusoption;
    system("cls");
    printf("\n");
    printf("Rezerwacja Miejsca Siedzacego\n\n\n");
    printf("(1) %s\n", ch[0]);
    printf("\n");
    printf("(2) %s\n", ch[1]);
    printf("\n");
    printf("(3) Powrot do menu glownego\n");
    printf("\nWprowadz numer: ");
    scanf("%d", &bookbusoption);
    clearbuff();
    switch (bookbusoption) {
    case 1:
        displaybus(ch[0], 1);
        bookbus(1);
        system("cls");
        displaybus(ch[0], 1);
        printf("\n\nPoprawnie zarezerwowano !");
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    case 2:
        displaybus(ch[1], 2);
        bookbus(2);
        system("cls");
        displaybus(ch[1], 2);
        printf("\n\nPoprawnie zarezerwowano !");
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    case 3:
        system("cls");
        menu();
        break;
    default:
        printf("\n\nWpisano Nie poprawna cyfre!!!\n");
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    }


}

int cancel() {
    int cancelbusoption;
    system("cls");
    printf("\n");
    printf("Anulowanie Rezerwacji!\n\n\n");
    printf("(1) %s\n", ch[0]);
    printf("\n");
    printf("(2) %s\n", ch[1]);
    printf("\n");
    printf("(3) Powrot do menu glownego\n");
    printf("\nWprowadz numer: ");
    scanf("%d", &cancelbusoption);
    clearbuff();
    switch (cancelbusoption) {
    case 1:
        displaybus(ch[0], 1);
        cancelbus(1);
        system("cls");
        displaybus(ch[0], 1);
        printf("\n\nPoprawnie Anulowano !");
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    case 2:
        displaybus(ch[1], 2);
        cancelbus(2);
        system("cls");
        displaybus(ch[1], 2);
        printf("\n\nPoprawnie Anulowano !");
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    case 3:
        system("cls");
        menu();
        break;
    default:
        printf("\n\nWpisano Nie poprawna cyfre!!!\n");
        printf("\n\nNacisnij dowolny znak aby kontynuowac....");
        getch();
        break;
    }
}