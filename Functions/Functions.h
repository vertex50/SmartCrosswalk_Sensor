/*
 * Functions.h
 *
 *  Created on: 2 Jul 2016
 *      Author: KwangEun An
 *  Description: SmartCrosswalk_Sensor에서 사용할 수 있도록
 *  각 기능 헤더파일의 메타헤더파일. SmartCrosswalk_Sensor에서
 *  기능의 함수를 직접 사용하기 위해서 여기에 필수로 등록이 되어야함.
 */

#ifndef FUNCTIONS_FUNCTIONS_H_
#define FUNCTIONS_FUNCTIONS_H_


//SmartCrosswalk_Sensor.cpp안에서 함수를 쓸 수 있도록 헤더파일들을 include 합니다.

#include "BoundaryDetector.h" //레이저 감지 프로그램
#include "TrafficLight.h" //신호등 제어 프로그램
#include "ReceiveSignal.h" //아두이노에서 신호 수신
#include "SendSignal.h" //아두이노에서 신호 송신

//헤더는 여기 이전에 포함시켜야 함!
#endif /* FUNCTIONS_FUNCTIONS_H_ */
