//
// Created by henok on 6/6/2019.
//

#ifndef HTGS_TUTORIALS_INITIALIZEPLAYER_H
#define HTGS_TUTORIALS_INITIALIZEPLAYER_H
#include<htgs/api/IData.hpp>
class InitializePlayer: public htgs::IData{
public:
    InitializePlayer(int x, int y, char t): x(x),y(y),t(t){}
    int getX(){return x;}
    int getY(){return y;}
    char getTeam(){ return t;}
private:
    int x;
    int y;
    char t;
};

#endif //HTGS_TUTORIALS_INITIALIZEPLAYER_H