#ifndef GROWING_PLANT
    #define GROWING_PLANT
    #include "../raylib/raylib.h"
    class Player;
    class Cameraz;

    class GrowingPlant {
    private:
        Rectangle rect;
        int maxSize;
        int size = 0;
        bool horizontal = false;
        bool fromLeft = true;
        bool haveGrow = false;
        bool growing = false;
        int requiredMana;
        Cameraz* cam;
        int frame = -1;
        float framePeriod = 0;
        float* delta;
        int id = -1;
        bool stateChange = false;
    public:
        GrowingPlant(Rectangle rect, int maxSize, bool horizontal, bool fromLeft, int requiredMana, Cameraz* cam, float* delta);
        Rectangle getRect(bool stateOk = false);
        int getMawSize();
        bool isHorizontal();
        int getRequiredMana();
        void growPlant();
        void startGrowing();
        bool isAround(Player* p);
        void draw(Texture2D*gVV, Texture2D* gVFLH, Texture2D* gVFRH);
        bool isGrowing();
        int getId();
        void setId(int n);
        bool isStateChange();
    };

#endif
