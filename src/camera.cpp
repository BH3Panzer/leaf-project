#include "../header/camera.hpp"
#include "../header/player.hpp"
#include "../header/platform.hpp"

void cameraFollowPlayer(Cameraz* cam, Player* p) {
    if (p->getRect().x - cam->x > GetScreenWidth()/32*20)
    {
        cam->x += 10;
    }
    else if (p->getRect().x - cam->x < GetScreenWidth()/32*12) {
        cam->x -= 10;
    }

    if (p->getRect().y - cam->y < GetScreenHeight()/16*4) {
        cam->y -= 10;
    }
    else if (p->getRect().y - cam->y > GetScreenHeight()/16*12) {
        cam->y += 10;
    }
}

void cameraFollowPlatform(Cameraz* cam, Platform* p) {
    if (p->getRectangle().x - cam->x > GetScreenWidth()/32*26)
    {
        cam->x += 10;
    }
    else if (p->getRectangle().x - cam->x < GetScreenWidth()/32*8) {
        cam->x -= 10;
    }

    if (p->getRectangle().y - cam->y < GetScreenHeight()/16*4) {
        cam->y -= 10;
    }
    else if (p->getRectangle().y - cam->y > GetScreenHeight()/16*12) {
        cam->y += 10;
    }
}
