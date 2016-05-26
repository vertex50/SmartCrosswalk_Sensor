/**
 * @author 최홍준
 * @desc 광감지 센서로 부터 아날로그 입력으로 값을 보여주는 프로그램. 3발 광감지 센서를 사용.
 * @target Arduino Uno
 * @contact ghdwns7121@naver.com
 */

#include "Arduino.h"

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	int checkSensor();
}
int checkSensor() {
	if (analogRead(A0) < 4000)
		return 1;
	else if (analogRead(A1) < 4000)
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
void loop() {
	// put your main code here, to run repeatedly:
	int value0 = analogRead(A0);
	int value1 = analogRead(A1);
	int value2 = analogRead(A2);
	int value3 = analogRead(A3);
	int value4 = analogRead(A4);
	int value5 = analogRead(A5);
	value0 = (value0 / 10) * (value0 / 10);
	value1 = (value1 / 10) * (value1 / 10);
	value2 = (value2 / 10) * (value2 / 10);
	value3 = (value3 / 10) * (value3 / 10);
	value4 = (value4 / 10) * (value4 / 10);
	value5 = (value5 / 10) * (value5 / 10);
	Serial.print("value0 : ");
	Serial.println(value0);
	Serial.print("value1 : ");
	Serial.println(value1);
	Serial.print("value2 : ");
	Serial.println(value2);
	Serial.print("value3: ");
	Serial.println(value3);
	Serial.print("value4 : ");
	Serial.println(value4);
	Serial.print("value5 : ");
	Serial.println(value5);
	Serial.println("");
	delay(1000);
}
