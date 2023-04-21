#ifndef BOSS_H_
#define BOSS_H_

#include <vector>
#include "Global.h"
#include "Bullet.h"
#include "Explode.h"

#define WIDTH_BOSS 200
#define HEIGHT_BOSS 117
#define BOSS_SPEED 1
#define BOSS_BULLET_SPEED 13

class Boss
{
public:
    Boss();
    ~Boss();

    void setX(const int &x) { xVal = x; }
    void setY(const int &y) { yVal = y; }
    int getX() const { return xVal; }
    int getY() const { return yVal; }

    void setBulletList(std::vector<Bullet *> bullet_list) { bulletList = bullet_list; }
    std::vector<Bullet *> getBulletList() { return bulletList; }
    StatusChicken getStatus() { return status; }
    void setStatus(StatusChicken s);
    void setHeart(const float &Heart) { heart = Heart; }
    float getHeart() const { return heart; }
    void decrease(const float &bullet_damage) { heart -= bullet_damage; }

    void testRegression();
private:
    float heart;
    std::vector<Bullet *> bulletList;
    int xVal;
    int yVal;
    StatusChicken status;
};

#endif
