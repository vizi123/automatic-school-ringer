void ringOreLungi() {
  if (tt.hour == 8 && tt.min == 0 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //ora 1

  if (tt.hour == 9 && tt.min == 14 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //pauza intre astea 2 if uri

  if (tt.hour == 9 && tt.min == 21 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //ora 2

  if (tt.hour == 10 && tt.min == 24 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //pauza

  if (tt.hour == 10 && tt.min == 41 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //ora 2

  if (tt.hour == 11 && tt.min == 54 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //pauza

  if (tt.hour == 12 && tt.min == 1 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //ora 4

  if (tt.hour == 13 && tt.min == 14 && tt.sec >= 0 && tt.sec <= 2)
    ring();

  //pauza

  if (tt.hour == 13 && tt.min == 21 && tt.sec >= 0 && tt.sec <= 2)
    ring();
  //ora 5
  if (tt.hour == 14 && tt.min == 24 && tt.sec >= 0 && tt.sec <= 2)
    ring();
  //pauza
  if (tt.hour == 14 && tt.min == 41 && tt.sec >= 0 && tt.sec <= 2)
    ring();
  //ora 6
  if (tt.hour == 15 && tt.min == 54 && tt.sec >= 0 && tt.sec <= 2)
    ring();
  //gata programul
}
