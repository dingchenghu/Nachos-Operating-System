#include "whaleTest.h"

Whale* whale;

void m1(int param){
  DEBUG('w', "m1:0\n");
  whale->Male();
  DEBUG('w', "m1:1\n");
}

void f1(int param){
  DEBUG('w', "f1:0\n");
  whale->Female();
  DEBUG('w', "f1:1\n");
}

void mm1(int param){
  DEBUG('w', "mm1:0\n");
  whale->Matchmaker();  
  DEBUG('w', "mm1:1\n");
}


void m2(int param){
  DEBUG('w', "m2:0\n");
  whale->Male();
  DEBUG('w', "m2:1\n");
}

void f2(int param){
  DEBUG('w', "f2:0\n");
  whale->Female();
  DEBUG('w', "f2:1\n");
}

void mm2(int param){
  DEBUG('w', "mm2:0\n");
  whale->Matchmaker();  
  DEBUG('w', "mm2:1\n");
}

void m3(int param){
  DEBUG('w', "m3:0\n");
  whale->Male();
  DEBUG('w', "m3:1\n");
}

void f3(int param){
  DEBUG('w', "f3:0\n");
  whale->Female();
  DEBUG('w', "f3:1\n");
}

void mm3(int param){
  DEBUG('w', "mm3:0\n");
  whale->Matchmaker();  
  DEBUG('w', "mm3:1\n");
}


void WhaleTest::start(){
  
    DEBUG('t', "Entering WhaleMatchingTest");
    
    whale = new Whale("test");
    
    Thread *t = new Thread("m1");
    t->Fork(m1, 0);
    t = new Thread("mm2");
    t->Fork(mm2, 0);
    t = new Thread("m3");
    t->Fork(m3, 0);
    t = new Thread("f1");
    t->Fork(f1, 0);
    t = new Thread("f2");
    t->Fork(f2, 0);
    t = new Thread("f3");
    t->Fork(f3, 0);
    t = new Thread("mm1");
    t->Fork(mm1, 0);
    t = new Thread("m2");
    t->Fork(m2, 0);
    t = new Thread("mm3");
    t->Fork(mm3, 0);
    //t = new Thread("nine");
    
}