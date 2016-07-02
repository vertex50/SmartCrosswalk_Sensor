// Do not remove the include below
#include "SmartCrosswalk_Sensor.h"


const int RCarred = 6;  //car red
const int RCaryel = 5;  //car yello
const int RCargre = 4;  //car green
const int RPerred = 3;  //person green
const int RPergre = 2;  //person red
const int LCarred = 13;  //car red
const int LCaryel = 12;  //car yello
const int LCargre = 11;  //car green
const int LPerred = 10;  //person green
const int LPergre = 9;  //person red

const int LED = 7;

int debugnum = 0;

void setup() {
	pinMode(RCarred, OUTPUT);
	pinMode(RCaryel, OUTPUT);
	pinMode(RCargre, OUTPUT);
	pinMode(RPergre, OUTPUT);
	pinMode(RPerred, OUTPUT);
	pinMode(LCarred, OUTPUT);
	pinMode(LCaryel, OUTPUT);
	pinMode(LCargre, OUTPUT);
	pinMode(LPergre, OUTPUT);
	pinMode(LPerred, OUTPUT);
	pinMode(LED, OUTPUT);
}
void LEDON(int light_change) {
	digitalWrite(LED, HIGH);
	delay(light_change);
}	//end LEDON

void CARRED(int light_change, int num, int blink_Open, int blink_Close) { 	//5s
	//Red on
	digitalWrite(RCarred, HIGH);
	digitalWrite(RCaryel, LOW);
	digitalWrite(RCargre, LOW);
	digitalWrite(RPergre, HIGH);
	digitalWrite(RPerred, LOW);
	digitalWrite(LCarred, HIGH);
	digitalWrite(LCaryel, LOW);
	digitalWrite(LCargre, LOW);
	digitalWrite(LPergre, HIGH);
	digitalWrite(LPerred, LOW);
	LEDON(light_change);
	//delay(light_change);//Light Change

	for (int i = 0; i < num; i++) { //0.5s => waveringly
		digitalWrite(RCarred, HIGH);
		digitalWrite(RCaryel, LOW);
		digitalWrite(RCargre, LOW);
		digitalWrite(RPergre, HIGH);
		digitalWrite(RPerred, LOW);
		digitalWrite(LCarred, HIGH);
		digitalWrite(LCaryel, LOW);
		digitalWrite(LCargre, LOW);
		digitalWrite(LPergre, HIGH);
		digitalWrite(LPerred, LOW);
		digitalWrite(LED, HIGH);
		LEDON(blink_Open);
		//delay(blink_Open);// Blinking open

		digitalWrite(RCarred, HIGH);
		digitalWrite(RCaryel, LOW);
		digitalWrite(RCargre, LOW);
		digitalWrite(RPergre, LOW);
		digitalWrite(RPerred, LOW);
		digitalWrite(LCarred, HIGH);
		digitalWrite(LCaryel, LOW);
		digitalWrite(LCargre, LOW);
		digitalWrite(LPergre, LOW);
		digitalWrite(LPerred, LOW);
		digitalWrite(LED, HIGH);
		LEDON(blink_Close);
		//delay(blink_Close);//Blinking close
	} //for
	digitalWrite(RCarred, LOW);
	digitalWrite(LCarred, LOW);
	digitalWrite(LED, LOW);
} //CARRED
void CARYELLOW(int light_change) {	//3s
	digitalWrite(RCarred, LOW);  //CAR YELLOW
	digitalWrite(RCaryel, HIGH);
	digitalWrite(RCargre, LOW);
	digitalWrite(RPergre, LOW);
	digitalWrite(RPerred, HIGH);
	digitalWrite(LCarred, LOW);  //CAR YELLOW
	digitalWrite(LCaryel, HIGH);
	digitalWrite(LCargre, LOW);
	digitalWrite(LPergre, LOW);
	digitalWrite(LPerred, HIGH);
	delay(light_change);
}  //end CARYELLOW
void CARGREEN(int light_change) {	//5s
	digitalWrite(RCarred, LOW);	//CAR GREEN
	digitalWrite(RCaryel, LOW);
	digitalWrite(RCargre, HIGH);
	digitalWrite(RPergre, LOW);
	digitalWrite(RPerred, HIGH);
	digitalWrite(LCarred, LOW);	//CAR GREEN
	digitalWrite(LCaryel, LOW);
	digitalWrite(LCargre, HIGH);
	digitalWrite(LPergre, LOW);
	digitalWrite(LPerred, HIGH);
	digitalWrite(LED, LOW);
	delay(light_change);
}	//end CARGREEN
void debug(int num) {
	CARGREEN(2500);
	CARYELLOW(1500);
	CARRED(2000, num, 50, 50);
	debugnum = 1;
}
void carPass(int sig) {
	switch (sig) {
	case 1:          //사람 검출
		CARYELLOW(3000); //3s
		CARRED(4000, 10, 100, 100); //5s
		break;

	case 0:        //red green 의 연결 신호
		CARGREEN(5000); //5s
		break;

	case 8:
		LEDON(5000); //5s
		break;

	case 9:
		debug(5); //깜빡임 반복횟수
		break;
	default:

		break;

	} //switch
} //carPass

void loop() {
	//if (debugnum==0){
	//carPass(9);
	//}
	//carPass(3);
	carPass(0);
	carPass(1);
}


