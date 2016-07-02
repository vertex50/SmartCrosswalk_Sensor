/*
 * LaserDetector.cpp
 *
 *  Created on: 2 Jul 2016
 * @desc 광감지 센서로 부터 아날로그 입력으로 값을 보여주는 프로그램. 3발 광감지 센서를 사용.
 * @target Arduino Uno
 * @contact ghdwns7121@naver.com
 * @author 최홍준
 * @rearrangedBy KwangEun An
 *
 *  @Links
 *  http://docs.whiteat.com/?p=1243 //불빛 들어오게 하는 법
 *  http://wiki.vctec.co.kr/opensource/arduino/serialmonitor //감지 하고 그 값을 시리얼 모니터에 출력
 *  http://makethat.tistory.com/15 //감지 하고 그 값을 시리얼 모니터에 출력
 *
 *
 * Description: 경계선 검사를 하여 물체의 진입을 확인한다.
 * 기존의 소스코드가 있어서 참고하여 작성 필요함. 부분부분 왜 했는지 의도가 불명확한 코드가 있음!
 */
#include "BoundaryDetector.h"
//레이저 빛이 센서를 맞췄는지 확인하는 함수인듯.
int _checkSensor() {
	if (analogRead(A0) < 4000) //이거 도데체 뭐하려더는 걸까??!;;;
		return 1;
	else if (analogRead(A1) < 4000)//왜 4000인거지???!
		return 1;
	else if (analogRead(A2) < 4000)
		return 1;
	else if (analogRead(A3) < 4000)
		return 1;
	else if (analogRead(A4) < 4000)
		return 2;
	else if (analogRead(A5) < 4000)
		return 2;
	else
		return 0;
}

//신호값을 증폭시킴
int _multiply(int value){
	return (value/10)*(value/10);//그러고보니 왜 10을 나눴는지 기억이 없다....(당황)
}

//처음 초기화 할때 필요한 정의, OOP의 생성자와 비슷한 개념이며
//SmartCrosswalk에서 처음 setup()에서 호출될 부분
void BoundaryDetector() {
	Serial.begin(9600);
	_checkSensor();
}

//SmartCrosswalk의 loop()에서 호출될 부분.
void BoundaryDetector_run() {
	Serial.print("photoDetector_1 : ");
	Serial.println(_multiply(photoDetector_1));
	Serial.print("photoDetector_2 : ");
	Serial.println(_multiply(photoDetector_2));
	Serial.print("photoDetector_3 : ");
	Serial.println(_multiply(photoDetector_3));
	Serial.print("photoDetector_4: ");
	Serial.println(_multiply(photoDetector_4));
	Serial.print("photoDetector_5 : ");
	Serial.println(_multiply(photoDetector_5));
	Serial.print("photoDetector_6 : ");
	Serial.println(_multiply(photoDetector_6));
	Serial.println("");
	delay(1000);
}
