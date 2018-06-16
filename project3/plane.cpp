#include "plane.h"
#include "iostream"

plane::plane()
{

}

void plane::setLives(int l){
    lives = l;
}

int plane::getLives(){
    return lives;
}

void plane::shoot(){
    using namespace std;
    cout << "a";
}
