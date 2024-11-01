#include "../header/camera.hpp"
#include "../header/player.hpp"
#include "../header/platform.hpp"
#include "../raylib/raylib.h"
#include <iostream>

void cameraFollowPlayerF(Cameraz* cam, Player* p, float delta)
{
    Rectangle rectPlayer = p->getRect();
    int xDifference = rectPlayer.x + rectPlayer.width/2 - cam->x - GetScreenWidth()/2;
    int yDifference = rectPlayer.y + rectPlayer.height/2 - cam->y - GetScreenHeight()/2;

    cam->x += xDifference * delta * 3;
    cam->y += yDifference * delta * 5;
}

void cameraFollowPlayerC(Cameraz* cam, Player* p) {
    int modifier = 100;
    if (p->getRect().x - cam->x > GetScreenWidth()/32*20)
    {
        cam->velX += modifier;
    }
    else if (p->getRect().x - cam->x < GetScreenWidth()/32*8) {
        cam->velX -= modifier;
    }
    else {
        if (cam->velX > 0) {
            cam->velX -= modifier;
        }
        else if (cam->velX < 0) {
            cam->velX += modifier;
        }
    }

    if (p->getRect().y - cam->y < GetScreenHeight()/16*4) {
        cam->velY -= modifier;
    }
    else if (p->getRect().y - cam->y > GetScreenHeight()/16*12) {
        cam->velY += modifier;
    }
    else {
        if (cam->velY > 0) {
            cam->velY -= modifier;
        }
        else if (cam->velY < 0) {
            cam->velY += modifier;
        }
    }

    if (cam->velX > p->getVelMax().x) {
        cam->velX = p->getVel().x;
    }
    else if (cam->velX < -p->getVelMax().x) {
        cam->velX = p->getVel().x;
    }

    int tx = cam->velX;
    int ty = cam->velY;
    if (tx == 0) {
        cam->velX = 0;
    }
    if (ty == 0) {
        cam->velY = 0;
    }
}

void cameraFollowPlatform(Cameraz* cam, Platform* p) {
    int modifier = 300;
    if (p->getRectangle().x - cam->x > GetScreenWidth()/32*26)
    {
        cam->velX += modifier;
    }
    else if (p->getRectangle().x - cam->x < GetScreenWidth()/32*8) {
        cam->velX -= modifier;
    }
    else {
        if (cam->velX > 0) {
            cam->velX -= modifier;
        }
        else if (cam->velX < 0) {
            cam->velX += modifier;
        }
    }

    if (p->getRectangle().y - cam->y < GetScreenHeight()/16*4) {
        cam->velY -= modifier;
    }
    else if (p->getRectangle().y - cam->y > GetScreenHeight()/16*12) {
        cam->velY += modifier;
    }
    else {
        if (cam->velY > 0) {
            cam->velY -= modifier;
        }
        else if (cam->velY < 0) {
            cam->velY += modifier;
        }
    }
}

void cameraMove(Cameraz* cam, float& delta) {
    cam->x += cam->velX * delta;
    cam->y += cam->velY * delta;
}

void cameraSetScale(Cameraz* cam, int q) {
    cam->scale = q;
}

void cameraDebugTest(Cameraz* cam) {
    if (IsKeyPressed(KEY_B)) {
        cameraSetScale(cam, cam->scale-1);
        std::cout << "cam scale: " << cam->scale << std::endl;
    }
    else if (IsKeyPressed(KEY_N)) {
        cameraSetScale(cam, cam->scale+1);
        std::cout << "cam scale: " << cam->scale << std::endl;
    }
}

