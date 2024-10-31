#ifndef IMPORTATION
    #define IMPORTATION
    #include <array>
    #include "../raylib/raylib.h"

    extern std::array<unsigned char, 1024> IMAGE_DATA_CARACTERE;
    extern Image caractere;
    extern std::array<unsigned char, 102400> IMAGE_DATA_LEAF;
    extern Image leaf;
    extern std::array<unsigned char, 10240> IMAGE_DATA_CARACTERE_WALK;
    extern Image caractereWalk;
    extern std::array<unsigned char, 11520> IMAGE_DATA_CARACTERE_RUN;
    extern Image caractereRun;
    extern std::array<unsigned char, 3456> IMAGE_DATA_CARACTERE_JUMP;
    extern Image caractereJump;

    extern std::array<unsigned char, 61440> IMAGE_DATA_CARACTERE_CONCENTRATION_OF_POWER;
    extern Image caractere_concentration;
    extern std::array<unsigned char, 36864> IMAGE_DATA_CARACTERE_GROWING_VINE;
    extern Image caractere_growing;
    extern std::array<unsigned char, 73728> IMAGE_DATA_CARACTERE_BRIDGE_VINE;
    extern Image caractere_bridge;

    extern std::array<unsigned char, 36864> IMAGE_DATA_GROWING_VINE;
    extern Image growing_vine;
    extern std::array<unsigned char, 10000> IMAGE_DATA_TEXTURES_PLATEFORMS;
    extern Image textures_plateformes;

#endif