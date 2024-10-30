#ifndef GROWING_PLANT
    #define GROWING_PLANT
    #include "../raylib/raylib.h"
    class Player;
    class Cameraz;

    class GrowingPlant {
    private:
        Rectangle rect;
        int maxSize;
        bool horizontal = false;
        int requiredMana;
        Cameraz* cam;
    public:
        GrowingPlant(Rectangle rect, int maxSize, bool horizontal, int requiredMana, Cameraz* cam);
        Rectangle getRect();
        int getMawSize();
        bool isHorizontal();
        int getRequiredMana();
        void growPlant(Player* p);
        void draw();
    };

#endif
