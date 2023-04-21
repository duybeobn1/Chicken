#include "Player.h"

Player::Player()
{
    xVal = 0;
    yVal = 0;
    bulletType = BLASTER;
    status = true;
    bulletDamage = 0;
    heart = MAIN_HEART;
}
Player::~Player()
{
}

void Player::removeBullet(const int &idx)
{
    for (int i = 0; i < (int)bulletList.size(); i++)
    {
        if (idx < (int)bulletList.size())
        {
            Bullet *p_bullet = bulletList.at(idx);
            bulletList.erase(bulletList.begin() + idx);

            if (p_bullet)
            {
                delete p_bullet;
                p_bullet = NULL;
            }
        }
    }
}

void Player::testRegression()
{
    // Create a player object and check its initial state
    Player player;
    assert(player.getX() == 0);
    assert(player.getY() == 0);
    assert(player.getBulletType() == BLASTER);
    assert(player.getStatus() == true);
    assert(player.getBulletDamage() == 0);
    assert(player.getHeart() == 3);
    cout << "Test 1 passed" << endl;
    // Test setting and getting player position
    player.setX(100);
    player.setY(200);
    assert(player.getX() == 100);
    assert(player.getY() == 200);
    cout << "Test 2 passed" << endl;

    // Test setting and getting player bullet type
    player.setBulletType(NEUTRON);
    assert(player.getBulletType() == NEUTRON);
    cout << "Test 3 passed" << endl;

    // Test setting and getting player status
    player.setStatus(false);
    assert(player.getStatus() == false);
    cout << "Test 4 passed" << endl;

    // Test setting and getting player bullet damage
    player.setBulletDamage(10.5);
    assert(player.getBulletDamage() == 10.5);
    cout << "Test 5 passed" << endl;

    // Test setting and getting player heart count
    player.setHeart(2);
    assert(player.getHeart() == 2);
    cout << "Test 6 passed" << endl;

    // Test decreasing player heart count
    player.decreaseHeart();
    assert(player.getHeart() == 1);
    cout << "Test 7 passed" << endl;

    // Test adding and removing bullets from player's bullet list
    std::vector<Bullet *> bulletList;
    Bullet *bullet1;
    Bullet *bullet2;
    bulletList.push_back(bullet1);
    bulletList.push_back(bullet2);
    player.setBulletList(bulletList);
    assert(player.getBulletList().size() == 2);

    player.removeBullet(0);
    assert(player.getBulletList().size() == 1);
    assert(player.getBulletList()[0] == bullet2);

    delete bullet1;
    delete bullet2;
    cout << "Test 8 passed" << endl;
}