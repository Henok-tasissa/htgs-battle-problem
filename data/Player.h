//
// Created by henok on 6/7/2019.
//

#ifndef HTGS_TUTORIALS_PLAYER_H
#define HTGS_TUTORIALS_PLAYER_H

#include <memory>
#include <cstdlib>
class Player : public htgs::IData{
public:
    Player(int x, int y, char t){
        int strength = rand()%100+1;

        this->x = x;
        this->y = y;
        this->t = t;
        this->strength = strength;
    }
    int getX(){return x;}
    int getY(){return y;}
    char getTeam(){return t;}
    int getStrength(){return strength;}
private:
    int x;
    int y;
    char t;
    int strength;
};
#endif //HTGS_TUTORIALS_PLAYER_H
