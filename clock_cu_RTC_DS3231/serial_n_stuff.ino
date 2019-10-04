//pt serial si debugging
void print_stuff() {
  if (millis() - b == 1000) {
    //Serial.println(day);
    Serial.print(rtc.getTimeStr());\
    Serial.print("          tt.time:  ");
    Serial.print(tt.hour);
    Serial.print(":");
    Serial.print(tt.min);
    Serial.print(":");
    Serial.print(tt.sec);
    Serial.print("      zi: ");
    Serial.print(tt.dow);
    Serial.print(",  ore ");
    if (digitalRead(oreNormale) == 1)
      Serial.print("normale");
    else  Serial.print("prelungite");
    if (digitalRead(autoMan) == 0)
      Serial.print(",  mod auto");
    else  Serial.print(",  mod manual");
    Serial.println();
    b = millis();
  }
}
