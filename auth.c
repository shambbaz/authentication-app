// auth.c
#include <string.h>

int authenticate(const char *username, const char *password) {
    // Esimerkki kovakoodattu käyttäjätunnus ja salasana
    if (strcmp(username, "admin") == 0 && strcmp(password, "password123!") == 0) {
        return 1; // Onnistunut kirjautuminen
    }
    return 0; // Kirjautuminen epäonnistui
}
