#include "Boss.h"

Boss::Boss()
{

    xVal = 0;
    yVal = 0;
    status.turn_down = 0;
    status.turn_up = 0;
    status.turn_left = 1;
    status.turn_right = 0;
    heart = 0;
}

Boss::~Boss()
{
}
void Boss::setStatus(StatusChicken s) {
    status.turn_down = s.turn_down;
    status.turn_up = s.turn_up;
    status.turn_left = s.turn_left;
    status.turn_right = s.turn_right;
}
void Boss::testRegression()
{
    // Test setting and getting x and y values
    setX(100);
    assert(getX() == 100);
    setY(50);
    assert(getY() == 50);
    cout << "Test 1 passed" << endl;
    // Test setting and getting bullet list
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet();
    std::vector<Bullet *> bullet_list;
    bullet_list.push_back(bullet1);
    bullet_list.push_back(bullet2);
    setBulletList(bullet_list);
    std::vector<Bullet *> retrieved_bullet_list = getBulletList();
    assert(retrieved_bullet_list.size() == 2);
    assert(retrieved_bullet_list[0] == bullet1);
    assert(retrieved_bullet_list[1] == bullet2);
    cout << "Test 2 passed" << endl;
    // Test setting and getting heart value
    setHeart(50.0);
    assert(getHeart() == 50.0);
    decrease(10.0);
    assert(getHeart() == 40.0);
    cout << "Test 3 passed " << endl;
    // Test setting and getting status

    StatusChicken retrieved_status = getStatus();
    assert(retrieved_status.turn_up == 1);
    assert(retrieved_status.turn_down == 0);
    assert(retrieved_status.turn_left == 0);
    assert(retrieved_status.turn_right == 0);
    cout << "Test 4 passed " << endl;
}
