#include "Gift.h"

Gift::Gift()
{
    giftType = 0;
    comeBack = false;
}
Gift::~Gift()
{
}

int Gift::randomGift() const
{
    int randGiftType = rand() % 25;
    randGiftType = randGiftType < 3 ? randGiftType : 3;
    return randGiftType;
}
void Gift::testRegression()
{
    // create a new gift object
    Gift gift;
    assert(gift.getGiftType() == 0);
    assert(gift.getComeBack() == false);
    cout << "Test 1 passed" << endl;
    // test getX() and getY() methods
    gift.setX(100);
    gift.setY(200);
    assert(gift.getX() == 100);
    assert(gift.getY() == 200);
    cout << "Test 2 passed" << endl;

    // test setGiftType() and getGiftType() methods
    gift.setGiftType(2);
    assert(gift.getGiftType() == 2);
    cout << "Test 3 passed" << endl;

    // test setComeBack() and getComeBack() methods
    gift.setComeBack(true);
    assert(gift.getComeBack() == true);
    cout << "Test 4 passed" << endl;

    // test randomGift() method
    int randGiftType = gift.randomGift();
    assert(randGiftType >= 0 && randGiftType <= 3);
    cout << "Test 5 passed" << endl;
}