#define CATCH_CONFIG_MAIN  // Tämä määrittää pääohjelman Catch2:lle
#include <catch2/catch.hpp>  // Lisätään Catch2 headeri

// Oletetaan, että autentikointifunktio on määritelty main.cpp-tiedostossa
extern bool authenticate(const std::string &username, const std::string &password);  // Muutettu C++-yhteensopivaksi

TEST_CASE("Authentication system works correctly") {
    SECTION("Correct username and password") {
        REQUIRE(authenticate("admin", "password123!") == true);  // Testaa, että oikea käyttäjätunnus ja salasana menevät läpi
    }

    SECTION("Incorrect username") {
        REQUIRE(authenticate("wronguser", "password123!") == false);  // Testaa väärä käyttäjätunnus
    }

    SECTION("Incorrect password") {
        REQUIRE(authenticate("admin", "wrongpassword") == false);  // Testaa väärä salasana
    }

    SECTION("Incorrect username and password") {
        REQUIRE(authenticate("wronguser", "wrongpassword") == false);  // Testaa molemmat väärät tiedot
    }
}