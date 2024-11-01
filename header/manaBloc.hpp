#ifndef MANA_BLOC
    #define MANA_BLOC
    #include "../raylib/raylib.h"
    class Player;
    class Cameraz;

    class ManaBloc
    {
        private:
            int x;
            int y;
            int quantityOfMana;
            int step = 0;
            int reloadDuration;
            int reloadingStep = 0;
            int frame = 0;
            float framePeriod = 0;
            bool goUp = true;
            int offset = 0;
            float offsetPeriod = 0;
            Cameraz* cam;
            float* delta;

        public:
            ManaBloc(int x, int y, int quantityOfMana, int reloadDuration, Cameraz* cam, float* delta);
            int getX();
            int getY();
            void draw(Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB);
            bool isLoad(bool useBloc = false);
            bool isTouch(Player* p);
            void actualisate();
            int getQuantityOfMana();
    };
#endif