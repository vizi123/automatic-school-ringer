#include <DS3231.h>
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
#include <Event.h>
#include <Timer.h>


DS3231  rtc(SDA, SCL);
//clock fara RTC
/*
  pin 31 pt auto/man
  pin A2 minute
  pin A1 ore
  pin A0 suna
  pin 53 releu
*/

//low high sunt actioneaza invers dintr-un motiv necunoscut
//releu si buzzer acelasi pin
#define hi 0
#define lo 1

//la led-urile care nu sunt pe shield hi si lo nu sunt inversate
#define hi1 1
#define lo0 0

#define autoMan 6
#define oreNormale 5
#define buton_m A3
#define buton_h A2
#define buton_day A1
#define buton_suna A0
#define relay 3
#define lu 13
#define ma 12
#define mie 11
#define jo 10
#define vi 9
//sambata = all on
//duminica = all off


Timer t;
Time tt;
long long b, milbuth, milbutmin, milbutsuna, milbutday;
int day = tt.dow;
//b este pt print time -> serial
//t e pt ring();

bool safelock = 0;
/*
  safelock e pt ca functia suna() sa nu poata fi apelata cand deja se executa codul
  din ea;

  autoMode: 0 -automat, 1 - manual
*/

int now; // ca sa nu clipeasca led-urile; poate e usless

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
  Serial.println("beep");
  delay(500);
  digitalWrite(relay, hi);
  b = millis();
  milbuth = millis();
  milbutmin = millis();
  milbutsuna = millis();



  //shield setup
  Timer1.initialize();
  MFS.initialize(&Timer1);
  rtc.begin();
}
