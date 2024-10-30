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

#endif