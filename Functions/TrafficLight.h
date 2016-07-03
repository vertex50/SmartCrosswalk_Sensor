/*
 * TrafficLightController.h
 *
 *  Created on: 2 Jul 2016
 * @author 정영주
 * @rearrangedBy KwangEun An
 */

#ifndef FUNCTIONS_TRAFFICLIGHT_H_
#define FUNCTIONS_TRAFFICLIGHT_H_
#include "Arduino.h"

#include "PinRegister.h" //아두이노 핀번호 관리는 여기서 이루어집니다.테스트 할때는 잠시 뺴고 써도 되지만 실제 운용할때는 충돌이 발생하므로 빠지면 안됨!


//SmartCrosswalk_Sensor.cpp에서 쓸 함수들 이름만 정의 ㅇㅅㅇ!
void TrafficLight();
void TrafficLight_run();
void TrafficLight_carPass(int sig);

#endif /* FUNCTIONS_TRAFFICLIGHT_H_ */
