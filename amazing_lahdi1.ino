//delay(3000) adalah interval merah dengan kuning sisi selanjutnya
//led merah dihubungkan ke pin 2, 5, 8, dan 11.
//led kuning dihubungkan ke pin 3, 6, 9, dan 12. 
//led merah dihubungkan ke pin 4, 7, 10, dan 13

//Pengaturan Waktu
int Hijau = 7000;
int Kuning = 3000;

void setup() {
  // Pin 2 sampai 13 sebagai OUTPUT
  for(int led = 2; led <= 13; led++) {
    pinMode(led, OUTPUT);
  }
  
  // Kondisi awal lampu)
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
}

void loop() {
  // Jalur 1 (Selatan) Berjalan
  // ----------------------------------------
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  delay(Hijau);
  
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(Kuning);
  
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(3000);
  digitalWrite(6, HIGH);
  delay(Kuning);

  // Jalur 2 (Barat) Berjalan
  // ----------------------------------------
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, HIGH);
  delay(Hijau);
  
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(Kuning);
  
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(3000);
  digitalWrite(9, HIGH);
  delay(Kuning);

  // Jalur 3 (Utara) Berjalan
  // ----------------------------------------
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);
  delay(Hijau);
  
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(Kuning);
  
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(3000);
  digitalWrite(12, HIGH);
  delay(Kuning);
  
  // Jalur 4 (Timur) Berjalan
  // ----------------------------------------
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  delay(Hijau);
  
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(Kuning);
  
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(3000);
  digitalWrite(3, HIGH);
  delay(Kuning);
}