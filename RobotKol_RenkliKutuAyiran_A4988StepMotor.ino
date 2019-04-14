#include <Servo.h>
Servo servo_kol1;
Servo servo_kol2;
Servo servo_gripper;
#define S0 6
#define S1 13
#define S2 7
#define S3 6
#define sensorOut 8
#define sw 9
const int stepPin = 3;
const int dirPin = 2;

int frequency = 0;
int periyot = 20;
double alfa = 0.75;
double yenileme = 0.0;

int pos;
int top =0;

int red = 0;
int green = 0;
int blue = 0;

int kirmizi_top = 0;
int mavi_top = 0;
int yesil_top = 0;
int kirmizi_kutu = 0;
int mavi_kutu = 0;
int yesil_kutu = 0;

int motorHizi = 20;

void setup() {
  Serial.begin(9600);
  servo_kol1.attach(12);
  servo_kol2.attach(10);
  servo_gripper.attach(11);

  pinMode(sw,  INPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  digitalWrite(stepPin, LOW);
  digitalWrite(dirPin, LOW);
  
  servo_kol1.write(0);
  servo_kol2.write(60);
  servo_gripper.write(50); 
  delay(1000);
}


void loop() {
  delay(1000);
  while(top==0)
  {Serial.println("ilk topu alacak");
    gohome();
    oku();
    delay(1000);
    sensor_oku();
    delay(1000);
    kaldir();    
    delay(1000);
  /////////////////////////////////////////////////////////////  
  //////////////////İLK TOP KIRMIZI MI///////////////
  /////////////////////////////////////////////////////////////
    if ((red < blue) && (red < green)&&(red<=100))
    {
      Serial.println("ilk top kırmızı");
    al();
    //İLK TOPU ALDI
    digitalWrite(dirPin, LOW);
    for (long int x = 0; x < 300000; x++) 
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(motorHizi);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(motorHizi);
    }
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(2000);  
    sensor_oku();
    delay(500);
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("ilk yer kırmızı");
    goto sonbir;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      }      
      oku();
      delay(2000);
      sensor_oku();
      delay(500);
      kaldir();
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("2. yer kırmızı");
    goto sonbir;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      }      
      oku();
      delay(2000);
      sensor_oku();
      delay(500);
      kaldir();
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("3. yer kırmızı");
    goto sonbir;}
    else 
      {gohome();}
    top=1;
    Serial.println("1.top tamamdır sıra 2.topta");
  }

  /////////////////////////////////////////////////////////////  
  //////////////////İLK TOP MAVİ Mİ///////////////
  /////////////////////////////////////////////////////////////
  if ((blue < red) && (blue < green))
    {Serial.println("ilk top mavi");
    al();
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 300000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(500);  
    sensor_oku();
    delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("ilk yer mavi");
    goto sonbir;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("2. yer mavi");
    goto sonbir;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("3. yer mavi");
    goto sonbir;}
    else 
      {gohome();}
    top=1;
    Serial.println("1.top tamamdır sıra 2.topta");
  }
  /////////////////////////////////////////////////////////////  
  //////////////////İLK TOP YEŞİL Mİ///////////////
  /////////////////////////////////////////////////////////////
  if ((green < blue) && (green < red))
    {
    al();
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 300000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(500);
    sensor_oku();
    delay(500);
    if ((green < blue) && (green < red)){birak();goto sonbir;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((green < blue) && (green < red)){birak();goto sonbir;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((green < blue) && (green < red)){birak();goto sonbir;}
    else 
      {gohome();}
    sonbir : 
    top=1;
    Serial.println("1.top tamamdır sıra 2.topta");
  }
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////////////////2.TOPTA SIRA///////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
while(top==1)
  {
    gohome();
    Serial.println("sıra2.topta");
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(1000);
      oku();
      delay(1000);
      sensor_oku();
      delay(1000);
      kaldir();    
      delay(1000);
  /////////////////////////////////////////////////////////////  
  //////////////////2. TOP KIRMIZI MI///////////////
  /////////////////////////////////////////////////////////////
    if ((red < blue) && (red < green)&&(red<=100))
    {
    Serial.println("2.top kırmızı");
    al();
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 210000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(2000);
    sensor_oku();
    delay(500);
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("1.yer kırmızı mı");goto soniki;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(2000);
      sensor_oku();
      delay(500);
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("2.yer kırmızı mı");goto soniki;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("3.yer kırmızı mı");goto soniki;}
    else 
      {gohome();}
    top=2;
    Serial.println("2.top tamamdır sıra 3.topta");
  }

  /////////////////////////////////////////////////////////////  
  //////////////////2. TOP MAVİ Mİ///////////////
  /////////////////////////////////////////////////////////////
  if ((blue < red) && (blue < green))
    {
    al();
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 210000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(2000);
    sensor_oku();
    delay(500);
    Serial.println("2.Top mavi");
    if ((blue < red) && (blue < green)){birak();Serial.println("1.yer mavi mi");goto soniki;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(2000);
      sensor_oku();
      delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("2.yer mavi mi");goto soniki;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(2000);
      sensor_oku();
      delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("3.yer mavi mi");goto soniki;}
    else 
      {gohome();}
      top=2;
    Serial.println("2.top tamamdır sıra 3.topta");
  }
  /////////////////////////////////////////////////////////////  
  //////////////////2. TOP YEŞİL Mİ///////////////
  /////////////////////////////////////////////////////////////
  if ((green < blue) && (green < red))
    {
    al();
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 210000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(2000);
    sensor_oku();
    delay(500);
    Serial.println("2.top yeşil");
    if ((green < blue) && (green < red)){birak();Serial.println("1.yer yeşil mi");goto soniki;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(2000);
      sensor_oku();
      delay(500);
    if ((green < blue) && (green < red)){birak();Serial.println("2.yer yeşil mi");goto soniki;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(2000);
      sensor_oku();
      delay(500);
    if ((green < blue) && (green < red)){birak();Serial.println("3.yer yeşil mi");goto soniki;}
    else 
      {gohome();}
    soniki : 
    top=2;
    Serial.println("2.top tamamdır sıra 3.topta");
  } 
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////////////////3.TOPTA SIRA///////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
while(top==2)
  {
    gohome();
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 180000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(1000);
      oku();
    delay(1000);
    sensor_oku();
    delay(1000);
    kaldir();    
    delay(1000);
    Serial.println("3.topta sıra");
  /////////////////////////////////////////////////////////////  
  //////////////////3. TOP KIRMIZI MI///////////////
  /////////////////////////////////////////////////////////////
    if ((red < blue) && (red < green)&&(red<=100))
    {
    Serial.println("3.Top kırmızı");
    al();
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 120000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(500);
    sensor_oku();
    delay(500);
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("1.yer kırmızı mı");goto sonuc;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("2.yer kırmızı mı");goto sonuc;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((red < blue) && (red < green)&&(red<=100)){birak();Serial.println("3.yer kırmızı mı");goto sonuc;}
    else 
      {gohome();}
    top=3;
    Serial.println("3.top tamamdır bitti");
  }

  /////////////////////////////////////////////////////////////  
  //////////////////3. TOP MAVİ Mİ///////////////
  /////////////////////////////////////////////////////////////
  if ((blue < red) && (blue < green))
    {
    al();
    Serial.println("3.Top mavi");
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 120000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(500);
    sensor_oku();
    delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("1.yer mavimi");goto sonuc;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("2.yer mavimi");goto sonuc;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((blue < red) && (blue < green)){birak();Serial.println("3.yer mavimi");goto sonuc;}
    else 
      {gohome();}
    top=3;
    Serial.println("3.top tamamdır bitti");
  }
  /////////////////////////////////////////////////////////////  
  //////////////////3. TOP YEŞİL Mİ///////////////
  /////////////////////////////////////////////////////////////
  if ((green < blue) && (green < red))
    {
    al();
    Serial.println("3.Top yeşil");
    //İLK TOPU ALDI
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 120000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
    //İLK KUTUNUN OLDUĞU YERE GELDİ
    delay(500);
    sensor_oku();
    delay(500);
    if ((green < blue) && (green < red)){birak();Serial.println("1.yer yeşil mi");goto sonuc;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((green < blue) && (green < red)){birak();Serial.println("2.yer yeşil mi");goto sonuc;}
      digitalWrite(dirPin, LOW);
      for (long int x = 0; x < 90000; x++) 
      {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(motorHizi);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(motorHizi);
      } 
      delay(500);
      sensor_oku();
      delay(500);
    if ((green < blue) && (green < red)){birak();Serial.println("3.yer yeşil mi");goto sonuc;}
    else 
      {gohome();}
    sonuc :
    top=3;
    Serial.println("3.top tamamdır bitti");
  } 
}
while(top==3){
    Serial.println("bitti");}
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void sensor_oku()
{
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(red);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(green);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  blue = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(blue);//printing RED color frequency
  Serial.println("  ");
  delay(100);
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void gohome()
{
  digitalWrite(dirPin, HIGH);
  for (long int x = 0; x < 100000000; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(motorHizi);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(motorHizi);
    if (digitalRead(sw) == HIGH)x = 100000000;
  }
  digitalWrite(dirPin, LOW);
  for (long int x = 0; x < 40000; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(motorHizi);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(motorHizi);
  }
}


void oku()
{
  delay(1000);
  servo_kol1.write(90);
  servo_kol2.write(90);
  delay(500);
  servo_gripper.write(60);
}
void kaldir()
{
  servo_kol1.write(0);
  servo_kol2.write(60);
  delay(500);
  servo_gripper.write(60);
}

void al()
{
  servo_kol1.write(80);
  servo_kol2.write(100);
  delay(1000);  
  servo_gripper.write(60);
  delay(1000);    
  servo_gripper.write(10); 
  delay(1000);  
  servo_kol1.write(0);
  servo_kol2.write(30);
}

void birak()
{
  delay(1000);    
//  servo_kol1.write(90);
//  servo_kol2.write(100);  
//  delay(500);  
  servo_gripper.write(60); 
  delay(500);  
  servo_kol1.write(0);
  servo_kol2.write(30);
  delay(1000);  
  servo_gripper.write(60); 
//  delay(1000);    
//  servo_kol1.write(0);
//  servo_kol2.write(60);
//  servo_gripper.write(10);  
//  gohome();  
}


