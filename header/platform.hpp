#ifndef PLATFORM
    #define PLATFORM

    #include "../header/colors.hpp"
    #include "../header/camera.hpp"
    #include <vector>

    class Platform
    {
        private:
            Rectangle rect;
            Color col;
            Cameraz* cam;
            int* seed;
            Texture2D* sprite;
            int width;
            int height;
            bool plant;
            std::vector<int> texturePattern = {};

        public:
            Platform(Rectangle rect, Color col, Cameraz* cam, Texture2D* sprite, bool plant);
            void drawPlatform();
            Rectangle getRectangle();
            Color getColor();
            void setRectangle(Rectangle rect);
            void setColor(Color col);
            bool isPlant();
            Rectangle* getRectPointeur();
    };

#endif
