#include "Chicken.h"

Chicken::Chicken()
{

    xVal = 0;
    yVal = 0;
    status.turn_down = 0;
    status.turn_up = 0;
    status.turn_left = 0;
    status.turn_right = 1;
    heart = 0;
    comeBack = true;
}

Chicken::~Chicken() {}

void Chicken::setStatusRight()
{
    status.turn_down = 0;
    status.turn_up = 0;
    status.turn_left = 0;
    status.turn_right = 1;
}
void Chicken::setStatus(StatusChicken s){
    status.turn_down = s.turn_down;
    status.turn_up = s.turn_up;
    status.turn_left = s.turn_left;
    status.turn_right = s.turn_right;
}
void Chicken::testRegression()
{
    Chicken chicken;
    assert(chicken.getX() == 0);
    assert(chicken.getY() == 0);
    assert(chicken.getHeart() == 0);
    assert(chicken.getComeBack() == true);
    assert(chicken.getStatus().turn_down == 0);
    assert(chicken.getStatus().turn_up == 0);
    assert(chicken.getStatus().turn_left == 0);
    assert(chicken.getStatus().turn_right == 1);
    cout << "Test 1 passed " << endl;
    // Test setter and getter functions
    chicken.setX(10);
    chicken.setY(20);
    assert(chicken.getX() == 10);
    assert(chicken.getY() == 20);

    chicken.setHeart(5);
    assert(chicken.getHeart() == 5);

    chicken.setComeBack(false);
    assert(chicken.getComeBack() == false);
    cout << "Test 2 passed " << endl;

    // Test removeBullet function
    Bullet *bullet1 = new Bullet();
    Bullet *bullet2 = new Bullet(); 
    std::vector<Bullet *> bullet_list;
    bullet_list.push_back(bullet1);
    bullet_list.push_back(bullet2);
    setBulletList(bullet_list);
    std::vector<Bullet *> bullet_received = getBulletList();
    assert(bullet_received.size() == 1);
    assert(bullet_received[0] == bullet2);
    cout << "Test 3 passed " << endl;
}