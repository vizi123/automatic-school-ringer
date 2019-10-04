//oscileaza intre low, high odata la 2 secunde, revenind al starea initiala (low).
//daca este actionat releul din buton, functia oscillate() se opreste
void ring() {
  if (safelock == 0 /*&& digitalRead(autoMan) == 0*/) {
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
