#ifndef BAR
    #define BAR
    #include "../raylib/raylib.h"
    #include "../header/camera.hpp"

    class Bar {
    private:
        int max;
        int current;
        Color col;
        Color borderCol;
        Rectangle rect;
        Cameraz* cam;

    public:
        Bar();
        Bar(int max, int current, Color col, Color borderCol, Rectangle rect, Cameraz* cam);
        int getMax();
        int getCurrent();
        Color getColor();
        Color getBorderColor();
        Rectangle getRectangle();
        void setMax(int max);
        void setCurrent(int current);
        void draw();
    };



#endif
