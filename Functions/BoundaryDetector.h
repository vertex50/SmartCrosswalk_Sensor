/*
 * LaserDetector.h
 *
 *  Created on: 2 Jul 2016
 * @author 최홍준
 * @rearrangedBy KwangEun An
 */

#ifndef FUNCTIONS_BOUNDARYDETECTOR_H_
#define FUNCTIONS_BOUNDARYDETECTOR_H_

#include "Arduino.h"

#include "PinRegister.h" //아두이노 핀번호 관리는 여기서 이루어집니다.

//SmartCrosswalk_Sensor.cpp에서 쓸 함수들 이름만 정의 ㅇㅅㅇ!
//밖에서 쓸 변수명은 꼭 헤더파일 제목을 붙여서 코드 대혼란을 방지 !
void BoundaryDetector();
void BoundaryDetector_run();


#endif /* FUNCTIONS_BOUNDARYDETECTOR_H_ */
