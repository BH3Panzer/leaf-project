#ifndef PLAYER
    #define PLAYER
    #include "../header/level.hpp"

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
            Texture2D sprite;
            int scale;

        public:
            Player(Cameraz* cam, float* delta, Image sprite, int scale = 3);
            int detectCollision(std::vector<Platform>& platforms, bool horizontal = true) const;
            bool isOnFloor(std::vector<Platform>& platforms);
            void movement(std::vector<Platform> platforms);
            void drawPlayer();
            int getMana();
            void setMana(int mana);
            void addMana(int q);
            void subMana(int q);
            void manaDebugTest();
            Rectangle getRect();
    };

#endif
