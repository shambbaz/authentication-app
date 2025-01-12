# Autentikointijärjestelmä

Tämä projekti on **yksinkertainen esimerkki autentikointijärjestelmästä**, joka on kirjoitettu C++:lla. Järjestelmä tarkistaa käyttäjän syöttämän käyttäjätunnuksen ja salasanan oikeellisuuden ja validoi salasanan vahvuuden. Tämä on vain yksinkertainen esimerkki, jossa käytetään ennalta määritettyjä arvoja. 

**Käyttäjätunnus**: `admin`  
**Salasana**: password123!

Projektissa on myös yksikkötestejä Catch2-kirjastoa käyttäen.

## Toiminnallisuus
- **Käyttäjien autentikointi**: Käyttäjä voi syöttää käyttäjätunnuksen ja salasanan, jotka verrataan esiasetettuihin arvoihin.
- **Salasanan vahvuus**: Salasanan tulee olla vähintään 8 merkkiä pitkä ja sisältää ainakin yksi numero ja yksi erikoismerkki.
- **Yksikkötestit**: Käytetään Catch2-kirjastoa testaamaan autentikointijärjestelmän toimivuus.

## Käyttöohjeet

1. **Projekti käyttöön**
    - Lataa tai kloonaa projekti GitHubista:
      ```bash
      git clone https://github.com/shambbaz/authentication-app.git
      ```
    - Siirry projektikansioon:
      ```bash
      cd authentication-app
      ```

2. **Rakentaminen ilman Makea**
    - Voit käyttää suoraan komentoriviltä `g++`-komentoa kääntämiseen ja ajamiseen:
      ```bash
      g++ -std=c++11 main.cpp test_auth.cpp -o autentikointijarjestelma
      ./autentikointijarjestelma
      ```
    - Tämä komento kääntää lähdekoodin ja luo suoritettavan tiedoston, joka voidaan suorittaa suoraan.

3. **Käytettävissä olevat testit**
    - Testejä voidaan ajaa käyttämällä Catch2-kirjastoa. Jos sinulla on asennettuna Catch2, voit suorittaa testit suoraan:
      ```bash
      ./autentikointijarjestelma_test
      ```

## Testit
Tässä projektissa on testit autentikointijärjestelmän toimivuuden varmistamiseksi. Catch2-kirjastoa käytetään yksikkötestien ajamiseen, jotka testaavat oikeiden ja väärien käyttäjätunnusten sekä salasanojen syötteiden käsittelyä.

## CMake-ohjeet
Jos haluat käyttää CMake:ä projektin kääntämiseen, voit käyttää seuraavia ohjeita:

1. Siirry `build`-hakemistoon:
    ```bash
    mkdir build
    cd build
    ```
2. Suorita CMake ja rakenna projekti:
    ```bash
    cmake ..
    cmake --build .
    ```

## License
Tämä projekti on lisensoitu MIT-lisenssillä. Katso [LICENSE](LICENSE) tiedosto lisätietoja varten.
