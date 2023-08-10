// const int R1 = 6;
// const int R2 = 5;
// const int R3 = 4;
// const int R4 = 3;
// const int R5 = 2;
// const int C1 = A1;
// const int C2 = A2;
// const int C3 = A3;
// const int C4 = A4;
// const int C5 = A5;
// const int Rows[5] = { R1, R2, R3, R4, R5 };
// const int Cols[5] = { C1, C2, C3, C4, C5 };
// int temp_row = -1;
// int temp_col = -1;
// int row;
// int col;

// void start() {
//   Serial.begin(9600);
//   pinMode(R1, OUTPUT);
//   pinMode(R2, OUTPUT);
//   pinMode(R3, OUTPUT);
//   pinMode(R4, OUTPUT);
//   pinMode(R5, OUTPUT);
//   pinMode(C1, INPUT_PULLUP);  // Pull-down resistors on the analog input pins
//   pinMode(C2, INPUT_PULLUP);
//   pinMode(C3, INPUT_PULLUP);
//   pinMode(C4, INPUT_PULLUP);
//   pinMode(C5, INPUT_PULLUP);
// }

// void setup() {
//   start();
// }

// void loop() {
//   // for (int i = 0; i < 5; i++) {
//   //   digitalWrite(Rows[i], HIGH);
//   //   delay(50);  // Add a small delay to allow the voltage to settle
//   //   for (int j = 0; j < 5; j++) {
//   //     // if (i < 4 &  j != 4) {
//   //       int value = analogRead(Cols[j]);
//   //       delay(10);
//   //       // if (value < 950) {  // Adjust the threshold as needed
//   //         col = j;
//   //         row = i;
//   //         // if (temp_row != row || temp_col != col) {
//   //         // temp_row = row;
//   //         // temp_col = col;
//   //         Serial.print("Row ");
//   //         Serial.print(row);

//   //         Serial.print(" Col ");
//   //         Serial.print(col);
//   //         Serial.print(" Value ");
//   //         Serial.println(value);
//   //       // }
//   //     // }
//   //     // }
//   //     delay(10);  // Add a small delay between readings
//   //   }
//   //   digitalWrite(Rows[i], LOW);
//   //   delay(10);
//   // }

//   // if (temp_row != row || temp_col != col) {
//   //   temp_row = row;
//   //   temp_col = col;
//   //   Serial.print("Row ");
//   //   Serial.print(row);
//   //   Serial.print(" Col ");
//   //   Serial.println(col);
//   // }
//     digitalWrite(R5 ,  HIGH);
//     delay(10);
//     for (int j = 0 ; j <5 ; j++){
//   col = analogRead(Cols[3]);
//   Serial.print(" 4 ");
//   Serial.print("Row ");
//   //  Serial.print(j);
//   Serial.print(" Col ");
// // const int threshold[25] = [907 , 907 , 903 , 900,820 , 908 ,910  ,  908 ,  908 , 905   ,   908 , 910  ,906    ,  905  ,   880  ,   900 ,  907  ,   907  ,     907, 900    ,   902 , 902 , 899  , 897];


//   Serial.println(col);
//     delay(100);
//     }


//   digitalWrite(R3, LOW);
//   digitalWrite(R1, LOW);
//   digitalWrite(R2, LOW);
//   digitalWrite(R4, LOW);
//   digitalWrite(R5, LOW);
// }



const int R1 = 6;
const int R2 = 5;
const int R3 = 4;
const int R4 = 3;
const int R5 = 2;
const int C1 = A1;
const int C2 = A2;
const int C3 = A3;
const int C4 = A4;
const int C5 = A5;
const int Rows[5] = { R1, R2, R3, R4, R5 };
const int Cols[5] = { C1, C2, C3, C4, C5 };
int thresholds[25] = {
  213, 205, 204, 224, 287,
  891, 897, 892, 893, 889,
  894, 894, 886, 866, 874,
  699, 890, 895, 895, 890,
  895, 427, 256, 199, 197
};

int temp_row = -1;
int temp_col = -1;
int row;
int col;

void start() {
  Serial.begin(9600);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(C1, INPUT_PULLUP);  // Pull-down resistors on the analog input pins
  pinMode(C2, INPUT_PULLUP);
  pinMode(C3, INPUT_PULLUP);
  pinMode(C4, INPUT_PULLUP);
  pinMode(C5, INPUT_PULLUP);
}

void setup() {
  start();
}

void loop() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(Rows[i], HIGH);

    delay(10);  // Add a small delay to allow the voltage to settle
    for (int j = 0; j < 5; j++) {
      int value = analogRead(Cols[j]);

      col = j;
      row = i;
      //  if (value<(thresholds[row*5 + col]-5))
      //  {
      //    Serial.print(value);
      //    Serial.print(" ");
      //    Serial.print(thresholds[row*5 + col]);
      //        Serial.print(" ");
      //    Serial.println(row*5 + col);
      //  }
      // Serial.print("Row ");
      //   Serial.print(row);
      //   Serial.print(" Col ");
      //   Serial.print(col);
      //   Serial.print(" Value ");
      //   Serial.println(value);
      Serial.print(value);
      if (j == 4 and i==4) {
        Serial.print("");
      }
      else{
        Serial.print(",");
      }
      // ... repeat for all values

      // Add a small delay between readings
      delay(1);
    }
    digitalWrite(Rows[i], LOW);
    delay(1);
  }
  Serial.print("\n");
}
