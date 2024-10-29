#ifndef PLAYER
    #define PLAYER

    #include "../header/level.hpp"

    class Player
    {
        private:
            Rectangle rect = {5, 5, 12 * 3, 16 * 3}; // rectangle de collision
            Vector2 vel = {0, 0};
            Cameraz cam;
            float* delta;
            Vector2 velMax = {1000, 1000};
            Vector2 acceleration = {3000, 400};
            int jump = 100;
            int mana = 20;

        public:
            Player(Cameraz &cam, float* delta);
            int detectCollision(std::vector<Platform>& platforms, bool horizontal = true) const;
            bool isOnFloor(std::vector<Platform>& platforms);
            void movement(std::vector<Platform> platforms);
            void drawPlayer();
            int getMana();
            void setMana(int mana);
            void addMana(int q);
            void subMana(int q);
            void manaDebugTest();
    };

#endif
