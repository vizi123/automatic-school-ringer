void loop() {
  day = tt.dow;
  if (digitalRead(autoMan) == 0 && day <= 5)
    if (digitalRead(oreNormale) == 1) {
      ringOreScurte();
    }
    else {
      ringOreLungi();
    }
  tt = rtc.getTime();
  buttonControl();
  showHour();
  print_stuff();
  showDay();  //leds
  t.update();
}
