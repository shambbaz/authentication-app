#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ATTEMPTS 3
#define MIN_PASSWORD_LENGTH 8

// Yksinkertainen kayttajadata
struct User {
    char username[20];
    char password[20];
};

// Funktio salasanan vahvuuden tarkistukseen
int is_valid_password(char *password) {
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return 0; // Salasana liian lyhyt
    }

    int has_digit = 0, has_special = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (ispunct(password[i])) {
            has_special = 1;
        }
    }

    return has_digit && has_special; // Vaatimus: vahan yksi numero ja yksi erikoismerkki
}

// Funktio autentikointiin
int authenticate(struct User user, char *input_username, char *input_password) {
    if (strcmp(user.username, input_username) == 0 && strcmp(user.password, input_password) == 0) {
        return 1; // Onnistunut kirjautuminen
    }
    return 0; // Kirjautuminen epaonnistui
}

int main() {
    struct User user = {"admin", "password123!"}; // Esimerkki kayttaja
    char input_username[20], input_password[20];
    int attempts = 0;

    printf("Tervetuloa, anna kayttajatunnus ja salasana.\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Kayttajatunnus: ");
        scanf("%s", input_username);

        printf("Salasana: ");
        scanf("%s", input_password);

        // Tarkistetaan, onko salasana validi
        if (!is_valid_password(input_password)) {
            printf("Virheellinen salasana! Salasanan tulee olla vahan 8 merkkiä pitkä, sisaltaa numeron ja erikoismerkin.\n");
            continue;
        }

        // Autentikointi
        if (authenticate(user, input_username, input_password)) {
            printf("Tervetuloa sisaan!\n");
            break;
        } else {
            attempts++;
            printf("Vaarä kayttajatunnus tai salasana. Yrita uudelleen.\n");
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Olet ylittanyt sallitut yritykset. Kirjautuminen epaonnistui.\n");
    }

    return 0;
}
