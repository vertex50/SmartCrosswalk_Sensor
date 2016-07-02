// Do not remove the include below
#include "SmartCrosswalk_Sensor.h"

/*
 * Description: 아두이노가 처음 실행될 때 1회 불러지는 곳
 * 여기서 기능들을 쓰려면
 * 1. Functions.h 파일에 등록이 되어 있어야 되고.
 * 2. 각 기능의 헤더파일에 여기에서 호출될 함수가 추상화(등록)되어 있어야됨!
 */
void setup() {
	TrafficLight();
	BoundaryDetector();
}

/*
 * 여기서 직접 실행하기보다 되도록 기능 파일을 만들어 _run()함수를 호출하여
 * 작성하는 것을 추천함. 여기서 작성하면 안보이는 부분과 충돌이 일어나 개발에 고생할 수 있음!
 */
void loop() {
	TrafficLight_run();
	BoundaryDetector_run();
}


