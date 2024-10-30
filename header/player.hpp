#ifndef PLAYER
    #define PLAYER
    #include "../header/level.hpp"

    struct Sprite
    {
        Texture2D s;
        Texture2D rs;
    };

    class Player
    {
        private:
            Rectangle rect; // rectangle de collision
            Vector2 vel = {0, 0};
            Cameraz* cam;
            float* delta;
            int mana = 20;
            Vector2 velMax = {600, 2000};
            Vector2 acceleration = {6000, 3000};
            int jump = 900;
            Sprite sprite;
            Sprite spriteRun;
            Sprite spriteJump;
            int frameRunning = 0;
            float framePeriod = 0.05;
            int scale;
            bool lookRight = true;

        public:
            Player(Cameraz* cam, float* delta, Image sprite, Image spriteRun, Image spriteJump, int scale = 3);
            int detectCollision(std::vector<Platform>& platforms, bool horizontal = true) const;
            bool isOnFloor(std::vector<Platform>& platforms);
            void movement(std::vector<Platform> platforms);
            void drawPlayer();
            int getMana();
            void setMana(unsigned int mana);
            void addMana(unsigned int q);
            void subMana(unsigned int q);
            //void manaDebugTest();
            Rectangle getRect();
    };

#endif
