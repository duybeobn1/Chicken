#ifndef GIFT_H_
#define GIFT_H_
#include "Global.h"
#define GIFT_WIDTH 49
#define GIFT_HEIGHT 58
#define WIDTH_LEVEL_UP 49
#define HEIGHT_LEVEL_UP 41
#define GIFT_SPEED 2
class Gift
{
public:
    Gift();
    ~Gift();

    void setX(const int &x) { xVal = x; }
    void setY(const int &y) { yVal = y; }
    int getX() const { return xVal; }
    int getY() const { return yVal; }

    void setGiftType(const int &type) { giftType = type; }
    int getGiftType() const { return giftType; }
    void setComeBack(const bool &back) { comeBack = back; }
    bool getComeBack() const { return comeBack; }
    int randomGift() const;
    void testRegression();
private:

    int xVal;
    int yVal;
    int giftType;
    bool comeBack;
};

#endif