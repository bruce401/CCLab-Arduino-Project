//initialize variables for sensor pins
int lightPin = 2;
const int sensorMin = 0; //rain sensor minimum
const int sensorMax = 1024; //rain sensor maximum
const int pingPin = 12; //setup pingpin as 12

//If the Sensor Board is completely soaked; "case 0" will be 
//activated and " Flood " will be sent to the serial monitor.
//If the Sensor Board has water droplets on it; "case 1" will 
//be activated and " Rain Warning " will be sent to the serial 
//monitor.
//If the Sensor Board is dry; "case 2" will be activated and 
//" Not Raining " will be sent to the serial monitor. 
//initialize variables to store readings from sensors

int lightVal = 0;

//initialize variables for LED pins
int redPin = 11;
int greenPin = 10;
int bluePin = 9;


void setup()
{
  //initialize the serial port
  Serial.begin(9600);
  
  //set LED pins to output mode
//  pinMode(redPin, OUTPUT);
//  pinMode(greenPin, OUTPUT);
//  pinMode(bluePin, OUTPUT);
  
  //set LED pins to off
//  digitalWrite(redPin, HIGH);
//  digitalWrite(greenPin, HIGH);
//  digitalWrite(bluePin, HIGH);

//    pinMode(3, OUTPUT);
//    pinMode(5, OUTPUT);
//    pinMode(7, OUTPUT);
//
//   
//    digitalWrite(3, HIGH); // function to let you know it is ready
//    digitalWrite(5, HIGH);
//    digitalWrite(7, HIGH);
//    delay (500);
//    digitalWrite(3, LOW);
//    digitalWrite(5, LOW);
//    digitalWrite(7, LOW);
}

void loop()
{
  //read values from the sensors
  lightVal = analogRead(lightPin);
  //read the sensor on analog A0 
  int sensorReading = analogRead(A0);

  //map the sensor range (four options)
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  //display the readings on the serial monitor in a coherent way
  Serial.print("light reads ");
  Serial.println(lightVal);
  //range value:
  switch(range) {
   case 0: //sensor getting wet
     Serial.println("Flood");
    break;
    case 1: //sensor getting wet
      Serial.println("Rain warning");
      break;
   case 2: //Sensor dry 
    Serial.println("No Rain");
  break;
  }
  
  //wait one second before continuing. we're doing this so that we don't just see readings fly by the screen
  delay(1000);

  // the PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  //give a short LOW pulse beforehand to ensure a clean HIGH pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);

  if(range == 0){
    digitalWrite(7, HIGH);}//turn on red to tell you to stop watering
  if(range == 1){
    digitalWrite(5, HIGH);}//turn on yellow, you've almost had enough water
  if(range == 3){
    digitalWrite(3, HIGH);}//turn on green, the plant wants water
   delay(100);


  
 
  //turn on green if light sensor reads 600 or brighter
//  if (lightVal > 600)
//  {
//    green();
//  }
//  else 
//  { 
//    off();
//  }
  //wait one second
  delay(1000);
 
}
//
//void blue()
//{
//  digitalWrite(redPin, HIGH);
//  digitalWrite(greenPin, HIGH);
//  digitalWrite(bluePin, LOW);
//}
//
//void red()
//{
//  digitalWrite(redPin, LOW);
//  digitalWrite(greenPin, HIGH);
//  digitalWrite(bluePin, HIGH);
//}

//void green()
//{
//  digitalWrite(redPin, HIGH);
//  digitalWrite(greenPin, LOW);
//  digitalWrite(bluePin, HIGH);
//}
//
//void off()
//{
//  digitalWrite(redPin, HIGH);
//  digitalWrite(greenPin, HIGH);
//  digitalWrite(bluePin, HIGH);
//  
//}
//
//void on()
//{
//  digitalWrite(redPin, LOW);
//  digitalWrite(greenPin, LOW);
//  digitalWrite(bluePin, LOW);
//}
