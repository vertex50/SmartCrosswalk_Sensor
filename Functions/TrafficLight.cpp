/*
 * TrafficLightController.cpp
 * @desc LED로 차량과 보행자 신호등을 깜박이는 프로그램
 * @target Arduino Uno
 * @contact vertex50@cu.ac.kr
 *  Created on: 2 Jul 2016
 * @author 정영주
 * @rearrangedBy KwangEun An
 *
 * Description: 횡단보도 신호화 차량 신호를 제어하는 프로그램.
 */
#include "TrafficLight.h"

int debugnum = 0;//????? 이거 뭣하러 남겼더라.... 내가 확인용으로 한다고 하다가 만들었는데 ... from KwangEun An

void _ledOn(int light_change) {
	digitalWrite(LED, HIGH);
	delay(light_change);
}	//end LEDON
void _carRed(int light_change, int num, int blink_Open, int blink_Close) { 	//5s
	//Red on
	digitalWrite(carRed_right, HIGH);
	digitalWrite(carYelllow_right, LOW);
	digitalWrite(carGreen_right, LOW);
	digitalWrite(walkRed_right, HIGH);
	digitalWrite(walkGreen_right, LOW);
	digitalWrite(carRed_left, HIGH);
	digitalWrite(carYellow_left, LOW);
	digitalWrite(carGreen_left, LOW);
	digitalWrite(walkGreen_left, HIGH);
	digitalWrite(walkRed_left, LOW);
	_ledOn(light_change);
	//delay(light_change);//Light Change

	for (int i = 0; i < num; i++) { //0.5s => waveringly
		digitalWrite(carRed_right, HIGH);
		digitalWrite(carYelllow_right, LOW);
		digitalWrite(carGreen_right, LOW);
		digitalWrite(walkRed_right, HIGH);
		digitalWrite(walkGreen_right, LOW);
		digitalWrite(carRed_left, HIGH);
		digitalWrite(carYellow_left, LOW);
		digitalWrite(carGreen_left, LOW);
		digitalWrite(walkGreen_left, HIGH);
		digitalWrite(walkRed_left, LOW);
		digitalWrite(LED, HIGH);
		_ledOn(blink_Open);
		//delay(blink_Open);// Blinking open

		digitalWrite(carRed_right, HIGH);
		digitalWrite(carYelllow_right, LOW);
		digitalWrite(carGreen_right, LOW);
		digitalWrite(walkRed_right, LOW);
		digitalWrite(walkGreen_right, LOW);
		digitalWrite(carRed_left, HIGH);
		digitalWrite(carYellow_left, LOW);
		digitalWrite(carGreen_left, LOW);
		digitalWrite(walkGreen_left, LOW);
		digitalWrite(walkRed_left, LOW);
		digitalWrite(LED, HIGH);
		_ledOn(blink_Close);
		//delay(blink_Close);//Blinking close
	} //for
	digitalWrite(carRed_right, LOW);
	digitalWrite(carRed_left, LOW);
	digitalWrite(LED, LOW);
} //CARRED
void _carYellow(int light_change) {	//3s
	digitalWrite(carRed_right, LOW);  //CAR YELLOW
	digitalWrite(carYelllow_right, HIGH);
	digitalWrite(carGreen_right, LOW);
	digitalWrite(walkRed_right, LOW);
	digitalWrite(walkGreen_right, HIGH);
	digitalWrite(carRed_left, LOW);  //CAR YELLOW
	digitalWrite(carYellow_left, HIGH);
	digitalWrite(carGreen_left, LOW);
	digitalWrite(walkGreen_left, LOW);
	digitalWrite(walkRed_left, HIGH);
	delay(light_change);
}  //end CARYELLOW
void _carGreen(int light_change) {	//5s
	digitalWrite(carRed_right, LOW);	//CAR GREEN
	digitalWrite(carYelllow_right, LOW);
	digitalWrite(carGreen_right, HIGH);
	digitalWrite(walkRed_right, LOW);
	digitalWrite(walkGreen_right, HIGH);
	digitalWrite(carRed_left, LOW);	//CAR GREEN
	digitalWrite(carYellow_left, LOW);
	digitalWrite(carGreen_left, HIGH);
	digitalWrite(walkGreen_left, LOW);
	digitalWrite(walkRed_left, HIGH);
	digitalWrite(LED, LOW);
	delay(light_change);
}	//end CARGREEN

void _debug(int num) {
	_carGreen(2500);
	_carYellow(1500);
	_carRed(2000, num, 50, 50);
}


void TrafficLight_carPass(int sig) {
	switch (sig) {
	case 1:          //사람 검출
		_carYellow(3000); //3s
		_carRed(4000, 10, 100, 100); //5s
		break;

	case 0:        //red green 의 연결 신호
		_carGreen(5000); //5s
		break;

	case 8:
		_ledOn(5000); //5s
		break;

	case 9:
		_debug(5); //깜빡임 반복횟수
		break;
	default:

		break;

	}//switch
}

//처음 초기화 할때 필요한 정의, OOP의 생성자와 비슷한 개념이며
//SmartCrosswalk에서 처음 setup()에서 호출될 부분
void TrafficLight() {
	pinMode(carRed_right, OUTPUT);
	pinMode(carYelllow_right, OUTPUT);
	pinMode(carGreen_right, OUTPUT);
	pinMode(walkRed_right, OUTPUT);
	pinMode(walkGreen_right, OUTPUT);
	pinMode(carRed_left, OUTPUT);
	pinMode(carYellow_left, OUTPUT);
	pinMode(carGreen_left, OUTPUT);
	pinMode(walkGreen_left, OUTPUT);
	pinMode(walkRed_left, OUTPUT);
	pinMode(LED, OUTPUT);
}

//SmartCrosswalk의 loop()에서 호출될 부분.
void TrafficLight_run(){
	TrafficLight_carPass(0);
	TrafficLight_carPass(1);
}
