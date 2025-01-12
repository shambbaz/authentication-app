#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

#define MAX_ATTEMPTS 3
#define MIN_PASSWORD_LENGTH 8

// Yksinkertainen käyttäjätieto
struct User {
    std::string username;
    std::string password;
};

// Funktio salasanan vahvuuden tarkistukseen
bool is_valid_password(const std::string &password) {
    if (password.length() < MIN_PASSWORD_LENGTH) {
        return false; // Salasana liian lyhyt
    }

    bool has_digit = false, has_special = false;
    for (char c : password) {
        if (isdigit(c)) {
            has_digit = true;
        } else if (ispunct(c)) {
            has_special = true;
        }
    }

    return has_digit && has_special; // Vaatimus: vähintään yksi numero ja yksi erikoismerkki
}

// Funktio autentikointiin
bool authenticate(const User &user, const std::string &input_username, const std::string &input_password) {
    return (user.username == input_username && user.password == input_password); // Onnistunut kirjautuminen
}

int main() {
    User user = {"admin", "password123!"}; // Esimerkki käyttäjä
    std::string input_username, input_password;
    int attempts = 0;

    std::cout << "Tervetuloa, anna käyttäjätunnus ja salasana." << std::endl;

    while (attempts < MAX_ATTEMPTS) {
        std::cout << "Käyttäjätunnus: ";
        std::cin >> input_username;

        std::cout << "Salasana: ";
        std::cin >> input_password;

        // Tarkistetaan, onko salasana validi
        if (!is_valid_password(input_password)) {
            std::cout << "Virheellinen salasana! Salasanan tulee olla vähintään 8 merkkiä pitkä, sisältää numeron ja erikoismerkin." << std::endl;
            continue;
        }

        // Autentikointi
        if (authenticate(user, input_username, input_password)) {
            std::cout << "Tervetuloa sisään!" << std::endl;
            break;
        } else {
            attempts++;
            std::cout << "Väärä käyttäjätunnus tai salasana. Yritä uudelleen." << std::endl;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        std::cout << "Olet ylittänyt sallitut yritykset. Kirjautuminen epäonnistui." << std::endl;
    }

    return 0;
}
