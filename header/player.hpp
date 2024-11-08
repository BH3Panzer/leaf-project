#ifndef PLAYER
    #define PLAYER
    #include "../header/level.hpp"
    #include <cstddef>
    #include <iostream>

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
            int mana = 0;
            Vector2 velMax = {600, 2000};
            Vector2 acceleration = {6000, 3000};
            int jump = 900;
            int climbingSpeed = 2000;
            int climbingMaxSpeed = 400;
            Sprite sprite;
            Sprite spriteRun;
            Sprite spriteJump;
            Sprite spriteConcetration;
            Sprite spriteGrow;
            Sprite spriteBridge;
            int frame = -1;
            float framePeriod = 0;
            bool lookRight = true;
            GrowingPlant* plantAround = NULL;
            bool pConcentration = false;
            bool pReady = false;

        public:
            Player();
            Player(Cameraz* cam, float* delta, Image sprite, Image spriteRun, Image spriteJump, Image spriteConcetration, Image spriteGrow, Image spriteBridge);
            int detectCollision(std::vector<Platform>& platforms, bool horizontal = true) const;
            bool isOnFloor(std::vector<Platform>& platforms);
            bool isOnGrowingVine(std::vector<GrowingPlant>& plants);
            void movement(std::vector<Platform> platforms, std::vector<GrowingPlant> plants);
            void drawPlayer();
            int getMana();
            void setMana(unsigned int mana);
            void addMana(unsigned int q);
            void subMana(unsigned int q);
            void manaDebugTest();
            Rectangle getRect();
            Vector2 getVel();
            Vector2 getVelMax();
            void handleInterract(Level* level);
            void recoverManaBloc(Level* level);
            void setPosition(int x, int y);
    };

#endif
