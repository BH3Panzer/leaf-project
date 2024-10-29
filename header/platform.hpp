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
            Platform(Rectangle rect, Color col, Cameraz &cam);
            void drawPlatform();
            Rectangle getRectangle();
            void setRectangle(Rectangle rect);
            
    };

#endif
