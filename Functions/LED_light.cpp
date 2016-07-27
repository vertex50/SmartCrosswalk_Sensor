/*
 * LED_light.cpp
 *
 *  Created on: 2016. 7. 27.
 *      Author: samsung
 */

#include "LED_light.h"
const int Carred = 6;  //car red
const int Caryel = 5;  //car yellow
const int Cargre = 4;  //car green
const int Perred = 3;  //person green
const int Pergre = 2;  //person red
const int LED = 7;
const int Button = 22;

void LED_light_setup()
{
    pinMode(Carred, OUTPUT);
    pinMode(Caryel, OUTPUT);
    pinMode(Cargre, OUTPUT);
    pinMode(Pergre, OUTPUT);
    pinMode(Perred, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(Button, INPUT);
}
void CARRED(int delaytime){
  digitalWrite(Carred,HIGH);
  digitalWrite(Caryel, LOW);
  digitalWrite(Cargre, LOW);
  digitalWrite(Pergre, HIGH);
  digitalWrite(Perred, LOW);
  digitalWrite(LED, HIGH);
  delay(delaytime);
}//CARRED
void CARYELLOW(int delaytime){
  digitalWrite(Carred,LOW);
  digitalWrite(Caryel, HIGH);
  digitalWrite(Cargre, LOW);
  digitalWrite(Pergre, LOW);
  digitalWrite(Perred, HIGH);
  delay(delaytime);
}//CARYELLOW
void CARGREEN(){
  digitalWrite(Carred,LOW);
  digitalWrite(Caryel, LOW);
  digitalWrite(Cargre, HIGH);
  digitalWrite(Pergre, LOW);
  digitalWrite(Perred, HIGH);
  digitalWrite(LED, LOW);
}//CARGREEN

void carPass(int sig){
  switch(sig){
    case 1:          //person pass
    	CARYELLOW(5000);
    	CARRED(25000);
    	break;
    case 0:        //car pass
     CARGREEN();
     break;
    default :
    break;
  }//end of switch
}//end of carPass

void LED_light_loop() {
  int buttonState;
  buttonState = digitalRead(Button); //button���� �޾��ִ� buttonState
  if(buttonState == LOW){ //button�� ������ ��
    carPass(1);//button LOW = person pass
  }
  else{
    carPass(0);//button HIGH = car pass
    }
}

