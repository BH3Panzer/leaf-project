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
            void setRectangle(Rectangle rect);
            void drawPlatform();
            Platform(Rectangle rect, Color col, Cameraz &cam);
    };

#endif
