#define CATCH_CONFIG_MAIN  // Tämä määrittää pääohjelman Catch2:lle
#include "catch.hpp"  // Lisätään Catch2 headeri

// Oletetaan, että autentikointifunktio on määritelty auth.c-tiedostossa
extern int authenticate(const char *username, const char *password);

TEST_CASE("Authentication system works correctly") {
    SECTION("Correct username and password") {
        REQUIRE(authenticate("admin", "password123!") == 1);  // Testaa, että oikea käyttäjätunnus ja salasana menevät läpi
    }

    SECTION("Incorrect username") {
        REQUIRE(authenticate("wronguser", "password123!") == 0);  // Testaa väärä käyttäjätunnus
    }

    SECTION("Incorrect password") {
        REQUIRE(authenticate("admin", "wrongpassword") == 0);  // Testaa väärä salasana
    }

    SECTION("Incorrect username and password") {
        REQUIRE(authenticate("wronguser", "wrongpassword") == 0);  // Testaa molemmat väärät tiedot
    }
}
