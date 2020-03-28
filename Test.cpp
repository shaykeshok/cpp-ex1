#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "habfy") == string("happy"));
    CHECK(find(text, "hafby") == string("happy"));
    //9
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
//5
}

TEST_CASE("Test replacement of s and z") {
    string text = "I have a big house with zula with 2*2 size";
    CHECK(find(text, "house") == string("house"));
    CHECK(find(text, "houze") == string("house"));
    CHECK(find(text, "zula") == string("zula"));
    CHECK(find(text, "sula") == string("zula"));
    CHECK(find(text, "size") == string("size"));
    CHECK(find(text, "zise") == string("size"));
    CHECK(find(text, "zize") == string("size"));
    CHECK(find(text, "sise") == string("size"));
//8
}

TEST_CASE("Test replacement of v,w and t,d and o,u") {
    string text = "we have to do 100 tests and we must not go more than 100 meters from the house";
    CHECK(find(text, "we") == string("we"));
    CHECK(find(text, "ve") == string("we"));
    CHECK(find(text, "have") == string("have"));
    CHECK(find(text, "hawe") == string("have"));
    CHECK(find(text, "to") == string("to"));
    CHECK(find(text, "tu") == string("to"));
    CHECK(find(text, "do") == string("to"));
    CHECK(find(text, "du") == string("to"));
    CHECK(find(text, "tests") == string("tests"));
    CHECK(find(text, "desds") == string("tests"));
    CHECK(find(text, "dests") == string("tests"));
    CHECK(find(text, "tesds") == string("tests"));
    CHECK(find(text, "and") == string("and"));
    CHECK(find(text, "ant") == string("and"));
    CHECK(find(text, "must") == string("must"));
    CHECK(find(text, "most") == string("must"));
    CHECK(find(text, "musd") == string("must"));
    CHECK(find(text, "mosd") == string("must"));
    CHECK(find(text, "frum") == string("from"));
//20
}

TEST_CASE("Test replacement of lower-case and upper-case and c,k,q") {
    string text = "ICQ is the best cakaqa ever";
    CHECK(find(text, "ICQ") == string("ICQ"));
    CHECK(find(text, "icq") == string("ICQ"));
    CHECK(find(text, "Icq") == string("ICQ"));
    CHECK(find(text, "IcQ") == string("ICQ"));
    CHECK(find(text, "ICq") == string("ICQ"));
    CHECK(find(text, "iCQ") == string("ICQ"));
    CHECK(find(text, "icQ") == string("ICQ"));
    CHECK(find(text, "ICC") == string("ICQ"));
    CHECK(find(text, "icc") == string("ICQ"));
    CHECK(find(text, "iCc") == string("ICQ"));
    CHECK(find(text, "IcC") == string("ICQ"));
    CHECK(find(text, "ICc") == string("ICQ"));
    CHECK(find(text, "ikc") == string("ICQ"));
    CHECK(find(text, "IKC") == string("ICQ"));
    CHECK(find(text, "iKc") == string("ICQ"));
    CHECK(find(text, "Ick") == string("ICQ"));
    CHECK(find(text, "iCK") == string("ICQ"));
    CHECK(find(text, "iqq") == string("ICQ"));
    CHECK(find(text, "iqc") == string("ICQ"));
    CHECK(find(text, "ikq") == string("ICQ"));
    CHECK(find(text, "ikk") == string("ICQ"));
    CHECK(find(text, "iqk") == string("ICQ"));
    CHECK(find(text, "ikc") == string("ICQ"));
    CHECK(find(text, "ick") == string("ICQ"));
    CHECK(find(text, "IqK") == string("ICQ"));
//26   
}

TEST_CASE("Test replacement of lower-case and upper-case and b,p") {
    string text = "Bibi and Binyamin Ganz play together";
    CHECK(find(text, "bibI") == string("Bibi"));
    CHECK(find(text, "BiBi") == string("Bibi"));
    CHECK(find(text, "Bibi") == string("Bibi"));
    CHECK(find(text, "biBi") == string("Bibi"));
    CHECK(find(text, "pibi") == string("Bibi"));
    CHECK(find(text, "bipi") == string("Bibi"));
    CHECK(find(text, "pipi") == string("Bibi"));
    CHECK(find(text, "PIPI") == string("Bibi"));
    CHECK(find(text, "bIpI") == string("Bibi"));
    CHECK(find(text, "pIBi") == string("Bibi"));
    CHECK(find(text, "PIBi") == string("Bibi"));
    CHECK(find(text, "PiBi") == string("Bibi"));
    CHECK(find(text, "Binyamin") == string("Binyamin"));
    CHECK(find(text, "binyamin") == string("Binyamin"));
    CHECK(find(text, "pinyamin") == string("Binyamin"));
    CHECK(find(text, "Pinyamin") == string("Binyamin"));
    CHECK(find(text, "pINyamin") == string("Binyamin"));
    CHECK(find(text, "play") == string("play"));
    CHECK(find(text, "blay") == string("play"));
    CHECK(find(text, "Play") == string("play"));
    CHECK(find(text, "Blay") == string("play"));
    //22
}

TEST_CASE("Test replacement of lower-case and upper-case and g,j") {
    string text = "Google play jungle speed";
    CHECK(find(text, "Google") == string("Google"));
    CHECK(find(text, "google") == string("Google"));
    CHECK(find(text, "GooGle") == string("Google"));
    CHECK(find(text, "gooGle") == string("Google"));
    CHECK(find(text, "Goojle") == string("Google"));
    CHECK(find(text, "gooJle") == string("Google"));
    CHECK(find(text, "joogle") == string("Google"));
    CHECK(find(text, "jooGle") == string("Google"));
    CHECK(find(text, "Joogle") == string("Google"));
    CHECK(find(text, "joojle") == string("Google"));
    CHECK(find(text, "JooJle") == string("Google"));
    CHECK(find(text, "JOOJLE") == string("Google"));
    CHECK(find(text, "jungle") == string("jungle"));
    CHECK(find(text, "gungle") == string("jungle"));
    CHECK(find(text, "junjle") == string("jungle"));
    CHECK(find(text, "gunjle") == string("jungle"));
    CHECK(find(text, "Jungle") == string("jungle"));
    CHECK(find(text, "JunGle") == string("jungle"));
    CHECK(find(text, "Gunjle") == string("jungle"));
    CHECK(find(text, "GunJle") == string("jungle"));
    CHECK(find(text, "JUNGLE") == string("jungle"));
    CHECK(find(text, "GUNJLE") == string("jungle"));
    CHECK(find(text, "GUnJLe") == string("jungle"));
    CHECK(find(text, "JuNgLe") == string("jungle"));
//25
}

