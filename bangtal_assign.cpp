#include <iostream>
#include <bangtal>
using namespace std;
using namespace bangtal;

int main()
{
    //룸1 생성
    auto room1 = Scene::create("룸1", "room1.jpg");
    auto door1 = Object::create("door.jpg", room1, 750, 120);

    //룸2 생성
    auto room2 = Scene::create("룸2", "room2.jpg");
    auto door2 = Object::create("door.jpg", room2, 650, 75);
    auto door3 = Object::create("door.jpg", room2, 50, 75);
    auto curtain = Object::create("cur.jpg", room2, 50, 75);

    //문1을 열면 룸2로 이동
    door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        room2->enter();
        return true;
        });

    //커튼을 오른쪽으로 치우기
    curtain->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        if (action == MouseAction::MOUSE_DRAG_RIGHT) {
            curtain->locate(room2, 250, 75);
        }
        return true;
        });

    //문3을 열면 탈출
    door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
        endGame();
        return true;
        });

    startGame(room1);
}
