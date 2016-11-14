//
//  ForbiddenPoint.hpp
//  Hydra
//
//  Created by Jewel on 2016/11/14.
//  Copyright © 2016年 Jewel. All rights reserved.
//

#ifndef ForbiddenPoint_hpp
#define ForbiddenPoint_hpp

#include <stdio.h>
#include "Board.hpp"
typedef unsigned long DWORD;

#define EMPTY_MOVE		0
#define TURN_MOVE		1
#define OPPONENT_MOVE	2
#define OUTSIDE_MOVE	3

#define UP_DOWN				0

#define LEFTUP_RIGHTDOWN	1

#define LEFT_RIGHT			2

#define RIGHTUP_LEFTDOWN	3


extern int diroff[9],width,height,height2;
extern Psquare board,boardb,boardk;


#define nxtP(p,i) (p=(Psquare)(((char*)p)+(i*s)))
#define prvP(p,i) (p=(Psquare)(((char*)p)-(i*s)))


#define NO_FORBIDDEN 0
#define THREE_THREE_FBD 1
#define FOUR_FOUR_FBD 2
#define LONGFBD 3

struct ChessAnalyzeData{
    int adjsameNxt;
    int adjemptyNxt;
    int jumpsameNxt;
    int jumpemptyNxt;
    int jumpjumpsameNxt;
    
    int adjsamePre;
    int adjemptyPre;
    int jumpsamePre;
    int jumpemptyPre;
    int jumpjumpsamePre;
    
    Psquare pNxt;
    Psquare pPrv;
    
    ChessAnalyzeData();
};

void AnalysisLine(Psquare p0,int direction,ChessAnalyzeData* data);

int KeyPointForbiddenCheck(Psquare p,int direction,int shift);

int ForbiddenCheck(ChessAnalyzeData *checkData,Psquare p0);

#endif /* ForbiddenPoint_hpp */
