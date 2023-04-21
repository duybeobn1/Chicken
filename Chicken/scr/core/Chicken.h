#ifndef CHICKEN_H_
#define CHICKEN_H_

#include <vector>
#include "Global.h"
#include "Bullet.h"
#include "Explode.h"

#define WIDTH_CHICKEN 75
#define HEIGHT_CHICKEN 68
#define CHICKEN_SPEED 1
#define CHICKEN_BULLET_SPEED 1
#define CHICKEN_HEART 2

class Chicken
{
private:
    float heart;
    std::vector<Bullet *> bulletList;
    int xVal;
    int yVal;
    StatusChicken status;
    bool comeBack;

public:
    Chicken();
    ~Chicken();

    void setX(const int &x) { xVal = x; }
    void setY(const int &y) { yVal = y; }
    int getX() const { return xVal; }
    int getY() const { return yVal; }

    void setBulletList(std::vector<Bullet *> bullet_list) { bulletList = bullet_list; }
    std::vector<Bullet *> getBulletList() const { return bulletList; }

    void setHeart(const float &Heart) { heart = Heart; }
    int getHeart() const { return heart; }
    void decrease(const float &bulletDamage) { heart -= bulletDamage; }

    void setComeBack(const bool &comeback) { comeBack = comeback; }
    bool getComeBack() const { return comeBack; }
    void setStatusRight();

    StatusChicken getStatus() { return status; }
    void setStatus(StatusChicken s);
    void testRegression();
};

#endif