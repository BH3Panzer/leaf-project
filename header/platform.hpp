#ifndef PLATFORM
    #define PLATFORM

    #include "../header/colors.hpp"
    #include "../header/camera.hpp"

    class Platform
    {
        private:
            Rectangle rect;
            Color col;
            Cameraz cam;

        public:
            Rectangle getRectangle();
            Color getColor();
            void setRectangle(Rectangle rect);
            void setColor(Color col);
            void drawPlatform();
            Platform(Rectangle rect, Color col, Cameraz &cam);
    };

#endif
