void buttonControl() {
  if (digitalRead(buton_day) == 0 && millis() - milbutday > 250) {
    int finalDay;
    finalDay = tt.dow + 1;
    if (finalDay >= 8)
      finalDay = 1;

    rtc.setDOW(finalDay);
    milbutday = millis();
  }
  if (digitalRead(buton_h) == 0 && millis() - milbuth > 250) {
    int finalHour;
    finalHour = tt.hour + 1;
    if (finalHour >= 24)
      finalHour = 0;
    rtc.setTime(finalHour , tt.min , tt.sec);
    milbuth = millis();
  }
  if (digitalRead(buton_m) == 0 && millis() - milbutmin > 250) {
    int finalMin;
    finalMin = tt.min + 1;
    if (finalMin >= 60)
      finalMin = 0;
    rtc.setTime(tt.hour, finalMin , tt.sec);
    milbutmin = millis();
  }
  if (digitalRead(buton_suna) == 0) {
    digitalWrite(relay, hi);
    Serial.println("beep");
  }
  else if (safelock == 0) // previne apelarea functiei digitalWrite(relay, lo)
    //cand se executa functia oscillate()
    digitalWrite(relay, lo);

    
  //auto / manual + ore scurte / lungi

  
}
