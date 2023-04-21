#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "Global.h"
#include "Bullet.h"

#define WIDTH_MAIN 70
#define HEIGHT_MAIN 57
#define MAIN_SPEED 6
#define MAIN_HEART 3

class Player{
    public : 
    Player();
    ~Player();
    enum BULLET_SPEED {
        BLASTER_SPEED = 12, 
        NEUTRON_SPEED = 18,
        BORON_SPEED = 30,
    };

    int getX() const {return xVal;}
    int getY() const {return yVal;}
    void setX(const int x) {xVal = x;}
    void setY(const int y) {yVal = y;}
    void setBulletList(std::vector<Bullet *> bullet_list) { bulletList = bullet_list; }
    void setBulletDamage(float dame) {bulletDamage = dame;}
    std::vector<Bullet*> getBulletList() {return bulletList;}
    void removeBullet(const int& idx);

    void setBulletType(const int& bullet_type) {bulletType = bullet_type;}
    int getBulletType() const {return bulletType;}
    void setStatus(const bool& Status) {status = Status;}
    int getStatus() const {return status;}

    float getBulletDamage() const {return bulletDamage;}
    void setHeart(const int& Heart) {heart = Heart;}
    int getHeart() const {return heart;}
    void decreaseHeart() {heart--;}
    void testRegression();

    private: 
    std::vector<Bullet*> bulletList;
    int xVal; 
    int yVal;
    int bulletType;
    bool status;
    int heart;
    float bulletDamage;
};



#endif