#define CATCH_CONFIG_MAIN

#include "allapot.hpp"
#include "catch.hpp"
#include "turista.hpp"
#include "varos.hpp"

#include <fstream>

using namespace std;

TEST_CASE("Bevetel es allapot") {

    Varos varos;

    varos.setBevetel(30);
    CHECK(varos.getBevetel() == 30);

    varos.setAllapot(0);

    CHECK(varos.getAllapotP() == 1); // 0 nem lehet, helyette min
    CHECK(varos.getAllapotN() == "lepusztult"); // points to name transformation

    varos.setAllapot(50);

    CHECK(varos.getAllapotP() == 50);
    CHECK(varos.getAllapotN() == "atlagos"); // points to name transformation

    varos.setAllapot(100);

    CHECK(varos.getAllapotP() == 99); // 100 nem lehet, helyette max
    CHECK(varos.getAllapotN() == "jo_allapotu"); // points to name transformation

}

TEST_CASE("Vart es erkezett turistak") {

    Varos varos;

    varos.setAllapot(0); // szorzok: japan * 0; modern * 1; mas * 1;

    varos.latogatas(1000, 1000, 1000); // japan, modern, mas
    
    CHECK(varos.getJapanErk() == 0); //japan
    CHECK(varos.getModernErk() == 1000); //mod
    CHECK(varos.getMasErk() == 1000); //mas

    varos.latogatas(0, 0, 0);

    CHECK(varos.getJapanErk() == 0); //japan
    CHECK(varos.getModernErk() == 0); //mod
    CHECK(varos.getMasErk() == 0); //mas

    // -------------------- //

    varos.setAllapot(50); // szorzok: japan * 1; modern * 1,1; mas * 1,1;

    varos.latogatas(1000, 1000, 1000); // japan, modern, mas

    CHECK(varos.getJapanErk() == 1000); //japan
    CHECK(varos.getModernErk() == 1100); //mod
    CHECK(varos.getMasErk() == 1100); //mas

    // -------------------- //

    varos.setAllapot(99); // szorzok: japan * 1,2; modern * 1,3; mas * 1;

    varos.latogatas(1000, 1000, 1000); // japan, modern, mas

    CHECK(varos.getJapanErk() == 1200); //japan
    CHECK(varos.getModernErk() == 1300); //mod
    CHECK(varos.getMasErk() == 1000); //mas

}

TEST_CASE("Javitas es romlas") {

    Varos varos;

    varos.setAllapot(1);
    varos.setBevetel(1'200'000'000); // 10 pont javithato, 200m / 20m = 10

    varos.javitas();

    CHECK(varos.getAllapotP() == 11); // 1 alap + 10 javpont

    varos.latogatas(0, 0, 450); // mas: 1000, 50-esevel egy pontot rontanak. 450 / 50 = 9 romlas pont

    CHECK(varos.getAllapotP() == 2); // 11 alap - 9 rompont

}