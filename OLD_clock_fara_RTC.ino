#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
#include <Event.h>
#include <Timer.h>
#include <Wire.h>

//clock fara RTC
/*
  pin 31 pt auto/man
  pin A2 minute
  pin A1 ore
  pin A3 suna
  pin 53 releu
*/

//low high inverted
//releu si buzzer aceeasi
#define hi 0
#define lo 1

//la led-urile care nu-s pe shield hi si lo nu sunt inversate
#define hi1 1
#define lo0 0

#define autoMan 5
#define oreNormale 6
#define buton_m A3
#define buton_h A2
#define buton_day A1
#define buton_suna A5
#define relay 3
#define lu 13
#define ma 12
#define mie 11
#define jo 10
#define vi 9
//sambata = all on
//duminica = all off


//no idea
Timer t;

long long b, a, milbuth, milbutmin, milbutsuna, milbutday;
//a fiind pt secunde
//b este pt print time -> serial
//t e pt ring();


//multe de aici sunt useless
bool safelock = 0;

/*
  safelock e pt ca functia suna() sa nu poata fi apelata cand deja se executa codul din ea;

  automat reprezinta modul de operare (1 true adica activ sau 0, inactiv)
*/
int day = 1;
int now; // ca sa nu clipeasca led-urile; poate e usless
int s = 0, m = 0, h = 0;
void setup() {
  pinMode(buton_m, INPUT_PULLUP);
  pinMode(buton_h, INPUT_PULLUP);
  pinMode(buton_suna, INPUT_PULLUP);
  pinMode(autoMan, INPUT_PULLUP);
  pinMode(oreNormale, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(vi, OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay, lo);
  //MFS.writeLeds(LED_3, ON);
  //MFS.beep(5);
  Serial.println("beep");

  a = millis();
  b = millis();
  milbuth = millis();
  milbutmin = millis();
  milbutsuna = millis();



  //shield setup
  Timer1.initialize();
  MFS.initialize(&Timer1);

}


void loop() {
  //time traveller
  
  if (s >= 60) {
    s = 0;
    m++;
  }
  if (m >= 60) {
    m = 0;
    h++;
  }
  if (h >= 24) {
    h = 0;
    day++;
  }
  if (day >= 8) {
    day = 1;
  }
  if (millis() - a == 1000) {
    s++;
    a = millis();
  }





  //reading butoane
  if (digitalRead(buton_day) == 0 && millis() - milbutday > 200) {
    day++;
    milbutday = millis();
  }
  if (digitalRead(buton_h) == 0 && millis() - milbuth > 200) {
    h++;
    milbuth = millis();
  }
  if (digitalRead(buton_m) == 0 && millis() - milbutmin > 200) {
    m++;
    milbutmin = millis();
  }
  if (digitalRead(buton_suna) == 0) {
    digitalWrite(relay, hi);
    //MFS.beep(1);
    Serial.println("beep");
  }
  else if (safelock == 0) // previne digitalWrite 0 pe releu cand este apelata functia care suna de pauza
    digitalWrite(relay, lo);






//serial. 9600
  if (millis() - b == 500) {
    print_stuff();
    b = millis();
  }





  //write time to display
  
  float vartime = h * 100 + m;
  vartime = (float)vartime / 100;
  MFS.write(vartime, 2);



  //auto / man

  //if (digitalRead(autoMan) == 1 && day <=5)
    //if (digitalRead(oreNormale) == 1)
      //ringOreScurte();
    //else ringOreLungi();
  //switch urile sunt broken


  ringOreScurte();

  //leds
  showDay();
  //no idea
  t.update();
}
//oscileaza intre low, high odata la 2 secunde, revenind al starea initiala (low). daca se intampla ceva cu releul, functia face break;
int ring() {
  if (safelock == 0 /*autoMode == 1*/) {
    safelock = 1;

    Serial.println("suna");
    t.oscillate(relay, 1000, hi, 2);
    t.after(4000, offRelay);
  }
}

void offRelay() {
  safelock = 0;
  digitalWrite(relay, lo);
}

void ringOreScurte() {
  if (h == 8 && m == 0 && s >= 0 && s <= 3)
    ring();
  if (h == 8 && m == 50 && s >= 0 && s <= 3)
    ring();
  if (h == 9 && m == 0 && s >= 0 && s <= 3)
    ring();
  if (h == 9 && m == 50 && s >= 0 && s <= 3)
    ring();
  if (h == 10 && m == 0 && s >= 0 && s <= 3)
    ring();

  //pauza mare
  if (h == 10 && m == 50 && s >= 0 && s <= 3)
    ring();
  if (h == 11 && m == 10 && s >= 0 && s <= 3)
    ring();
  //pauza mare

  if (h == 12 && m == 0 && s >= 0 && s <= 3)
    ring();
  if (h == 12 && m == 10 && s >= 0 && s <= 3)
    ring();
  if (h == 13 && m == 0 && s >= 0 && s <= 3)
    ring();
  if (h == 13 && m == 10 && s >= 0 && s <= 3)
    ring();
  if (h == 14 && m == 0 && s >= 0 && s <= 3)
    ring();
  if (h == 14 && m == 10 && s >= 0 && s <= 3)
    ring();
  if (h == 15 && m == 0 && s >= 0 && s <= 3)
    ring();
}


void ringOreLungi() {
  if (h == 8 && m == 0 && s >= 0 && s <= 3)
    ring();
  if (h == 9 && m == 15 && s >= 0 && s <= 3)
    ring();
//1

  if (h == 9 && m == 20 && s >= 57 && s <= 59) 
    ring(); //PAUZA

  if(h == 10 && m == 35 && s >= 0 && s <= 3)
    ring();

}
//pt serial
void print_stuff() {
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.print(s);
  Serial.print("      zi: ");
  Serial.print(day);
  Serial.print(",  ore ");
  //if (digitalRead(oreNormale) == 1)
  //  Serial.print("normale");
  //else  Serial.print("prelungite");
  if (digitalRead(autoMan) == 1)
    Serial.print(",  mod auto");
  else  Serial.print(",  mod manual");
  Serial.println();

}


//1 luni
//2 marti
//3 miercuri
//4 joi
//5 vineri
//6 sambata
//7 duminica

void showDay() {
  //luni
  if (day == 1 && day != now) {
    now = day;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(lu, hi1);
  }
  //marti
  if (day == 2 && day != now) {
    now = day;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(ma, hi1);
  }
  //mie
  if (day == 3 && day != now ) {
    now = day;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(mie, hi1);
  }

  //joi
  if (day == 4 && day != now ) {
    now = day;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(jo, hi1);
  }

  //vineri
  if (day == 5 && day != now ) {
    now = day;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(vi, hi1);
  }

  //sambata
  if (day == 6 && day != now ) {
    now = day;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, hi1);
  }

  //dum
  if (day == 7 && day != now ) {
    now = day;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
  }

}

