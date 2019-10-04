void showHour(){
  String timpAfisat = rtc.getTimeStr();
  timpAfisat[2] = '.';
  MFS.write(timpAfisat.toFloat(), 2);
}


//0 luni
//1 marti
//2 miercuri
//3 joi
//4 vineri
//5 sambata
//6 duminica
int increment = 0;
void showDay() {
  //luni
  if (tt.dow == 1 + increment && tt.dow != now + increment ) {
    now = tt.dow;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(lu, hi1);
  }
  //marti
  if (tt.dow == 2  + increment && tt.dow != now + increment ) {
    now = tt.dow;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(ma, hi1);
  }
  //mie
  if (tt.dow == 3  + increment && tt.dow != now + increment  ) {
    now = tt.dow;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(mie, hi1);
  }

  //joi
  if (tt.dow == 4  + increment && tt.dow != now  + increment ) {
    now = tt.dow;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(jo, hi1);
  }

  //vineri
  if (tt.dow == 5  + increment && tt.dow != now  + increment ) {
    now = tt.dow;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
    digitalWrite(vi, hi1);
  }

  //sambata
  if (tt.dow == 6  + increment && tt.dow != now + increment  ) {
    now = tt.dow;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, hi1);
  }

  //dum
  if (tt.dow == 7  + increment && tt.dow != now  + increment ) {
    now = tt.dow;
    for (int i = 13; i >= 9; i--)
      digitalWrite(i, lo0);
  }

}
