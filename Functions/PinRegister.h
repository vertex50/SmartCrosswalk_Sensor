/*
 * PinRegister.h
 *
 *  Created on: 2 Jul 2016
 *      Author: KwangEun An
 *  Description: 각 기능들이 아두이노 Mega 2560에 사용되는 핀을
 *  등록하여 사용. 미리 여기서 다른 기능들이 점유하고 있는 핀을 확인할 수 있음.
 *  만약 테스트단계인 경우 각 기능의 헤더파일에서 PinRegister.h 파일을 주석처리하여
 *  테스트 진행 가능. 단, 내용을 업데이트 할 때는 꼭 포함되어야 함.
 */

#ifndef FUNCTIONS_PINREGISTER_H_
#define FUNCTIONS_PINREGISTER_H_
#include "pins_arduino.h" // 아두이노 아날로그 핀 번호 헤더

//PinNumberID.h 정의
//BoundaryDetector.h에서 쓰는 변수명과 핀 번호
const int photoDetector_1 = analogRead(A0);
const int photoDetector_2 = analogRead(A1);
const int photoDetector_3 = analogRead(A2);
const int photoDetector_4 = analogRead(A3);
const int photoDetector_5 = analogRead(A4);
const int photoDetector_6 = analogRead(A5);

//PinNumberID.h 정의
//TrafficLight.h에서 쓰는 변수명 과 핀 번호
const int carRed_right = 6;  //car red
const int carYelllow_right = 5;  //car yellow
const int carGreen_right = 4;  //car green
const int walkGreen_right = 3;  //person green
const int walkRed_right = 2;  //person red
const int carRed_left = 13;  //car red
const int carYellow_left = 12;  //car yellow
const int carGreen_left = 11;  //car green
const int walkRed_left = 10;  //person green
const int walkGreen_left = 9;  //person red
const int LED = 7; // 이건 무슨 용도...????


#endif /* FUNCTIONS_PINREGISTER_H_ */
