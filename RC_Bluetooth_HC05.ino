const int kiri_belakang_maju = 3, kanan_belakang_maju = 4, kiri_depan_maju = 5 ,kanan_depan_maju = 6, kiri_belakang_mundur = 7, kanan_belakang_mundur = 8, kiri_depan_mundur = 9, kanan_depan_mundur = 10;

void setup() {
  //mengkonfiigurasi pin I/O
 Serial.begin(9600);
  pinMode(kiri_belakang_mundur,OUTPUT);
  pinMode(kanan_belakang_mundur,OUTPUT);
  pinMode(kiri_depan_mundur,OUTPUT);
  pinMode(kanan_depan_mundur,OUTPUT);
  pinMode(kiri_belakang_maju,OUTPUT);
  pinMode(kanan_belakang_maju,OUTPUT);
  pinMode(kiri_depan_maju,OUTPUT);
  pinMode(kanan_depan_maju,OUTPUT);
}

void loop() {
  // Pembacaan data dari pin serial komuunikasi (RX TX)
if(Serial.available() > 0){
  // menyimpan "data" kedalam sebuah variable bernama data dan bertipe char kemudian di print ke serial komunikasi di arduino ide
 char data = Serial.read();
 Serial.println(data);
delay(10);



// memproses data yang di terima kemudian di eksekusi sesuaii dengan fungsi yang di inginkan
  switch (data){
    case '1': 
    Maju();
    break;

    case '2':
    Mundur();
    break;

      case '3':
    Belok_kanan();
    break;


    case '4':
    Belok_kiri();
    break;


    default:
    Berhenti();
    break;
    }
  }
}


// fungsi" untuk mengontrol arah mobil
void Berhenti(){
digitalWrite(kiri_belakang_mundur, 0);
digitalWrite(kanan_belakang_mundur,0);
digitalWrite(kiri_depan_mundur,    0);
digitalWrite(kanan_depan_mundur,   0);

digitalWrite(kiri_belakang_maju, 0);
digitalWrite(kanan_belakang_maju,0);
digitalWrite(kiri_depan_maju,    0);
digitalWrite(kanan_depan_maju,   0);
}

void Maju(){
digitalWrite(kiri_belakang_mundur, 0);
digitalWrite(kanan_belakang_mundur,0);
digitalWrite(kiri_depan_mundur,    0);
digitalWrite(kanan_depan_mundur,   0);

digitalWrite(kiri_belakang_maju, 1);
digitalWrite(kanan_belakang_maju,1);
digitalWrite(kiri_depan_maju,    1);
digitalWrite(kanan_depan_maju,   1);
}

void Mundur(){
digitalWrite(kiri_belakang_mundur, 1);
digitalWrite(kanan_belakang_mundur,1);
digitalWrite(kiri_depan_mundur,    1);
digitalWrite(kanan_depan_mundur,   1);

digitalWrite(kiri_belakang_maju, 0);
digitalWrite(kanan_belakang_maju,0);
digitalWrite(kiri_depan_maju,    0);
digitalWrite(kanan_depan_maju,   0);
}
void Belok_kanan(){
digitalWrite(kiri_belakang_mundur, 0);
digitalWrite(kanan_belakang_mundur,1);
digitalWrite(kiri_depan_mundur,    0);
digitalWrite(kanan_depan_mundur,   1);

digitalWrite(kiri_belakang_maju,    1);
digitalWrite(kanan_belakang_maju,   0);
digitalWrite(kiri_depan_maju,       1);
digitalWrite(kanan_depan_maju,      0);
}

void Belok_kiri(){
digitalWrite(kiri_belakang_mundur, 1);
digitalWrite(kanan_belakang_mundur,0);
digitalWrite(kiri_depan_mundur,    1);
digitalWrite(kanan_depan_mundur,   0);

digitalWrite(kiri_belakang_maju,    0);
digitalWrite(kanan_belakang_maju,   1);
digitalWrite(kiri_depan_maju,       0);
digitalWrite(kanan_depan_maju,      1);
}
