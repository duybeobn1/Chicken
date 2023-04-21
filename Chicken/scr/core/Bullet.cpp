#include "Bullet.h"

Bullet::Bullet()
{
    x_val = 0;
    y_val = 0;
    is_move_ = false;
    bulletType = BLASTER;
}
Bullet::~Bullet()
{
}

void Bullet::testRegression()
{
    // Test setting and getting x and y values
    setX(50);
    assert(getX() == 50);
    setY(100);
    assert(getY() == 100);
    cout << "Test 1 passed" << endl;

    // Test setting and getting move status
    setMove(true);
    assert(getMove() == true);
    setMove(false);
    assert(getMove() == false);
    cout << "Test 2 passed" << endl;
    // Test setting and getting bullet type
    setBulletType(1);
    assert(getBulletType() == 1);
    setBulletType(2);
    assert(getBulletType() == 2);
    cout << "Test 3 passed" << endl;
}
