#include "whale.h"

Whale::Whale(char* debugName){
	name = debugName;
	male = new Semaphore("maleWhale",1);
	female = new Semaphore("femaleWhale",1);
	matchmaker = new Semaphore("matchmakerWhale",1);
	newMember = new Semaphore("newMember",0);
	match = 0; //number of whales waiting to be matched
	matched=0; //number of whales have been matched
	pairNO=1; 
}

Whale::~Whale(){

  delete male;
  delete female;
  delete matchmaker;
  delete newMember;
  
}


void Whale::Male(){
  
  male->P(); //block other male
  
  match ++; 
  
  
  while(match<3){  	//only when there are three whales from different classes are waiting, can the match continues
    newMember->P();	//wait for the other two
  }
  newMember->V(); 	//when the match completed, wake up the other two on the newMember list
  newMember->V();	 //there must be two whales on the newMember list, when the third whale find it can complete the match
		       //it's easier using broadcast with CV 
  if(matched==2){	 //when the third whale completes the match, initialize the flags before it returns
    match=0;
    matched=0;
    matchmaker->V();	//and let other whales continue the match
    female->V();
    male->V();
    printf("male whale return from match NO.%d\n",pairNO);
    printf("match NO. %d completed\n",pairNO);//before the third whale return, send a signal imply a match is completed
    pairNO++; 
  }
  else{                 //the first two whales complete the match,don't initialize flags, they just return
    matched ++; 
    printf("male whale return from match NO.%d\n",pairNO);
  }
}

void Whale::Female(){
  
  female->P(); //block other female
  
  match ++;

  
  while(match<3){
    newMember->P();
  }
  
  newMember->V();
  newMember->V();
  
  if(matched==2){
    match=0;
    matched=0;
    matchmaker->V();
    female->V();
    male->V();
    printf("female whale return from match NO.%d\n",pairNO);
    printf("match NO. %d completed\n",pairNO);
    pairNO++;
  }
  else{
    matched ++;
    printf("female whale return from match NO.%d\n",pairNO);
  }
  
  
}

void Whale::Matchmaker(){
  
  matchmaker->P(); //block other matchmaker
  
  match ++;
    
  while(match<3){
    newMember->P();
  }
  
  newMember->V();
  newMember->V();
  
  if(matched==2){
    match=0;
    matched=0;
    matchmaker->V();
    female->V();
    male->V();
    printf("matchmaker whale return from match NO.%d\n",pairNO);
    printf("match NO. %d completed\n",pairNO);
    pairNO++;
  }
  else{
    matched ++;
    printf("matchmaker whale return from match NO.%d\n",pairNO);   
  }
}