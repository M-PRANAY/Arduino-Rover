#include<Servo.h>
#include<NewPing.h>
#include<IRremote.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>


int Contrast = 100;
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

  // pinMode(ldrpin, OUTPUT);
  // pinMode(ldrout, INPUT);
  pinMode(echopin ,INPUT);
  pinMode(trigpin, OUTPUT);
  // put your setup code here, to run once:
  s1.attach(9);
  s1.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);



  
	Serial.begin(9600);
	// while (!Serial);

	// if (!mlx.begin()) {
	// 	Serial.println("Error connecting to MLX sensor. Check wiring.");
	// 	while (1);
	// };
  mlx.begin();





}

void loop() {


  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
	Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
	Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
	Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  lcd.setCursor(0,0); 
  lcd.print("OutTemp: ");
  lcd.print(mlx.readAmbientTempC());
  lcd.print((char)223);         //used to display degree symbol on display
  // lcd.write(0xdf);              //another way to display degree symbol
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("InTemp : ");
  lcd.print(mlx.readObjectTempC());
  lcd.print((char)223);         //used to display degree symbol on display
  // lcd.write(0xdf);
  lcd.print("C");

	// Serial.println();
	// delay(500);
  
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=20)
 {
  stop();
  delay(100);
  moveBackward();
  delay(300);
  stop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    delay(1000);
    stop();
  }else
  {
    turnLeft();
    delay(1000);
    stop();
  }
  }else
  {
   moveForward();
  }
   distance = readPing();

  





}








void RadarRover(){
  
}

int lookRight()
{
    s1.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    s1 .write(115); 
    return distance;
}

int lookLeft()
{
    s1.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    s1.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
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
