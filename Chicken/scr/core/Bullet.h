#ifndef BULLET_H_
#define BULLET_H_
#include "Global.h"
#include "string"
class Bullet {
public :
    Bullet();
    ~Bullet();

    void setX(const int& xVal){x_val = xVal;}
    void setY(const int& yVal){y_val = yVal;}
    int getX(){return x_val;}
    int getY(){return y_val;}
    void setMove(const bool& isMove){is_move_ = isMove;}
    bool getMove(){return is_move_;}
    void setBulletType(const int& type) {bulletType =type;}
    int getBulletType(){return bulletType;}
    void testRegression();
    
private : 
    int x_val;
    int y_val; 
    bool is_move_;
    int bulletType ;
};
#endif