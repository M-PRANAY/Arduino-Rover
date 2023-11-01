#include<Servo.h>
#include<NewPing.h>
#include<IRremote.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>


int Contrast = 60;
LiquidCrystal lcd(47, 48, 53, 52, 43, 33);



Adafruit_MLX90614 mlx = Adafruit_MLX90614();


const int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

int trigpin = A14;
int LED = 52;
int echopin = A15;
Servo s1;
int LUB = 23;
int LUF = 25;
int LBF = 27;
int LBB = 29;
int LB = 2;
int LU = 3;
int RU = 4;
int RB = 5;
int RUF = 22;
int RUB = 24;
int RBF = 26;
int RBB = 28;

int self = 37;
int ir = 38;
int test = 39;

int ldrpin = A12;
int ldrout = 53;

NewPing sonar(trigpin,echopin,200);
int distance = 100;
void setup() {

  Serial.begin(9600);
  Serial.println("1");
  analogWrite(46, Contrast);
  lcd.begin(16, 2);


  irrecv.enableIRIn();
  irrecv.blink13(true);

  


  
	Serial.begin(9600);
	// while (!Serial);

	// if (!mlx.begin()) {
	// 	Serial.println("Error connecting to MLX sensor. Check wiring.");
	// 	while (1);
	// };
  mlx.begin();





}

void loop() {


    
  // lcd.setCursor(0,0); 
  // lcd.print("OutTemp: ");
  // lcd.print(mlx.readAmbientTempC());
  // lcd.print((char)223);         //used to display degree symbol on display
  // // lcd.write(0xdf);              //another way to display degree symbol
  // lcd.print("C");
  // lcd.setCursor(0,1);
  // lcd.print("InTemp : ");
  // lcd.print(mlx.readObjectTempC());
  // lcd.print((char)223);         //used to display degree symbol on display
  // // lcd.write(0xdf);
  // lcd.print("C");  


    if (irrecv.decode(&results)){
      // Serial.print(results.value);
    if(results.value == 486){
      moveForward();
    }
    if(results.value == 2534){
      moveBackward();
    }
    if(results.value == 1510){
      turnLeft();
    }
    if(results.value == 3558){
      turnRight();
    }
    if(results.value == 30240){
      stop();
    }    
    Serial.println(results.value);
    irrecv.resume();
  }

  





}




//  ---------------------------------------------------------------------------------------------------------------------

void moveForward(){
  digitalWrite(LED,LOW);
    digitalWrite(LB,HIGH);
    digitalWrite(LU,HIGH);
    digitalWrite(RU,HIGH);
    digitalWrite(RB,HIGH);
    digitalWrite(LUF,HIGH);
    digitalWrite(LUB,LOW);
    digitalWrite(LBF,HIGH);
    digitalWrite(LBB,LOW);
    digitalWrite(RUF,HIGH);
    digitalWrite(RUB,LOW);
    digitalWrite(RBF,HIGH);
    digitalWrite(RBB,LOW);

}

void moveBackward(){
  digitalWrite(LED,LOW);
    digitalWrite(LB,HIGH);
    digitalWrite(LU,HIGH);
    digitalWrite(RU,HIGH);
    digitalWrite(RB,HIGH);
    digitalWrite(LUF,LOW);
    digitalWrite(LUB,HIGH);
    digitalWrite(LBF,LOW);
    digitalWrite(LBB,HIGH);
    digitalWrite(RUF,LOW);
    digitalWrite(RUB,HIGH);
    digitalWrite(RBF,LOW);
    digitalWrite(RBB,HIGH);

}


void turnRight(){
  digitalWrite(LED,LOW);
    digitalWrite(LB,HIGH);
    digitalWrite(LU,HIGH);
    digitalWrite(RU,HIGH);
    digitalWrite(RB,HIGH);
    digitalWrite(LUF,HIGH);
    digitalWrite(LUB,LOW);
    digitalWrite(LBF,HIGH);
    digitalWrite(LBB,LOW);
    digitalWrite(RUF,LOW);
    digitalWrite(RUB,HIGH);
    digitalWrite(RBF,LOW);
    digitalWrite(RBB,HIGH);

}


void turnLeft(){
    digitalWrite(LED,LOW);
    digitalWrite(LB,HIGH);
    digitalWrite(LU,HIGH);
    digitalWrite(RU,HIGH);
    digitalWrite(RB,HIGH);
    digitalWrite(LUF,LOW);
    digitalWrite(LUB,HIGH);
    digitalWrite(LBF,LOW);
    digitalWrite(LBB,HIGH);
    digitalWrite(RUF,HIGH);
    digitalWrite(RUB,LOW);
    digitalWrite(RBF,HIGH);
    digitalWrite(RBB,LOW);

}

void stop(){
  digitalWrite(LED,HIGH);
  digitalWrite(LB,LOW);
  digitalWrite(LU,LOW);
  digitalWrite(RU,LOW);
  digitalWrite(RB,LOW);
}
