#include "scr/core/Boss.h"
#include "scr/core/Boss.h"
#include "scr/core/Bullet.h"
#include "scr/core/Chicken.h"
#include "scr/core/Explode.h"
#include "scr/core/Gift.h"
#include "scr/core/Player.h"

int main() {
    Boss boss;
    Bullet bullet;
    Chicken chicken;
    Explode explode;
    Gift gift;
    Player player;
    cout << "Test non SDL class : " << endl;

    cout << "Test boss : " << endl;
    boss.testRegression();

    cout << "Test Bullet : " << endl;
    bullet.testRegression();

    cout << "Test chicken : " << endl;
    chicken.testRegression();

    cout << "Test gift : " << endl;
    gift.testRegression();

    cout << "Test player : "<< endl;
    player.testRegression();

    cout << "All tests passed." << endl; 
    
    return 0;
}