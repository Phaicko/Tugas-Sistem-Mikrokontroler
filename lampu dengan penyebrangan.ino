int Hijau = 7000;
int Kuning = 3000;

int KuningTransisi = 2000;   // Waktu kuning sebelum lampu jalan menjadi merah
int WaktuMenyeberang = 5000; // Lama pejalan kaki menyeberang
int KuningInterupsi = 2000;  // Waktu kuning jalan setelah pejalan kaki selesai

// Pin Pushbutton
const int btnSelatan = A0;
const int btnBarat = A1;

// Pin lampu penyeberang
const int pedMerahSelatan = A2;
const int pedHijauSelatan = A3;
const int pedMerahBarat = A4;
const int pedHijauBarat = A5;

void setup() {
  // Pin 2 sampai 13 sebagai OUTPUT (Lampu jalan utama)
  for(int led = 2; led <= 13; led++) {
    pinMode(led, OUTPUT);
  }
  
  // Pin lampu penyeberang sebagai OUTPUT
  pinMode(pedMerahSelatan, OUTPUT);
  pinMode(pedHijauSelatan, OUTPUT);
  pinMode(pedMerahBarat, OUTPUT);
  pinMode(pedHijauBarat, OUTPUT);

  // Menggunakan INPUT_PULLUP untuk tombol agar tidak butuh resistor eksternal
  pinMode(btnBarat, INPUT_PULLUP);
  pinMode(btnSelatan, INPUT_PULLUP);
  
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);

  // Kondisi awal lampu penyeberang (semua merah)
  digitalWrite(pedMerahSelatan, HIGH);
  digitalWrite(pedMerahBarat, HIGH);
  digitalWrite(pedHijauSelatan, LOW);
  digitalWrite(pedHijauBarat, LOW);
}

// Fungsi khusus pengganti delay() untuk memantau tombol dan mengatur lampu penyeberang
void cekTombolDanDelay(int waktuDelay, int pinTombol, int pinHijau, int pinKuning, int pinMerah, int pinPedMerah, int pinPedHijau) {
  int waktuBerjalan = 0;
  
  while (waktuBerjalan < waktuDelay) {
    // Jika tombol ditekan (logika LOW karena INPUT_PULLUP)
    if (digitalRead(pinTombol) == LOW) { 
      
      // Peringatan lampu jalan hijau -> kuning
      digitalWrite(pinHijau, LOW);
      digitalWrite(pinKuning, HIGH);
      delay(KuningTransisi); 
      
      // Menyeberang lampu jalan kuning -> merah, lampu penyeberang merah -> hijau
      digitalWrite(pinKuning, LOW);
      digitalWrite(pinMerah, HIGH);
      digitalWrite(pinPedMerah, LOW);
      digitalWrite(pinPedHijau, HIGH);
      delay(WaktuMenyeberang); 
      
      // Selesai menyeberang lampu penyeberang hijau -> merah, lampu jalan merah -> kuning
      digitalWrite(pinPedHijau, LOW);
      digitalWrite(pinPedMerah, HIGH);
      digitalWrite(pinMerah, LOW);
      digitalWrite(pinKuning, HIGH);
      delay(KuningInterupsi);
      
      // Lanjut Normal lampu jalan kuning -> hijau
      digitalWrite(pinKuning, LOW);
      digitalWrite(pinHijau, HIGH);
      
      // Mencegah interupsi berulang jika tombol ditahan (debounce)
      while(digitalRead(pinTombol) == LOW) {
        delay(10);
      }
    }
    
    // Jeda kecil untuk loop checker
    delay(10); 
    waktuBerjalan += 10;
  }
}

void loop() {
  // ========================================
  // Jalur 1 (Selatan)
  // ========================================
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  
  // Memantau tombol A1 dan mengontrol lampu penyeberang Selatan
  cekTombolDanDelay(Hijau, btnSelatan, 2, 3, 4, pedMerahSelatan, pedHijauSelatan);
  
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(Kuning);
  
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(3000);
  digitalWrite(6, HIGH);
  delay(Kuning);

  // ========================================
  // Jalur 2 (Barat)
  // ========================================
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, HIGH);
  
  // Memantau tombol A0 dan mengontrol lampu penyeberang Barat
  cekTombolDanDelay(Hijau, btnBarat, 5, 6, 7, pedMerahBarat, pedHijauBarat);
  
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(Kuning);
  
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(3000);
  digitalWrite(9, HIGH);
  delay(Kuning);

  // ========================================
  // Jalur 3 (Utara) (Tanpa Penyeberang)
  // ========================================
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

  // ========================================
  // Jalur 4 (Timur) (Tanpa Penyeberang)
  // ========================================
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