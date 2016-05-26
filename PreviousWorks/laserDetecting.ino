/**
 * @author 최홍준
 * @desc 광 감지 센서가 레이저 신호를 받을 때 이에 대한 민감도를 출력하는 프로그램.
 * @target Arduino Uno
 * @contact ghdwns7121@naver.com
 * 레이저 센서 이용 참고 URL
http://docs.whiteat.com/?p=1243 //불빛 들어오게 하는 법
http://wiki.vctec.co.kr/opensource/arduino/serialmonitor //감지 하고 그 값을 시리얼 모니터에 출력
http://makethat.tistory.com/15 //감지 하고 그 값을 시리얼 모니터에 출력
 */

#include "Arduino.h"

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}

void loop() {
	// put your main code here, to run repeatedly:
	digitalWrite(13, HIGH);
	int value = analogRead(A0);
	Serial.println(value);
	delay(100);
}
