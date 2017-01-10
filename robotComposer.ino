#include "pitches.h"

int one[] = {NOTE_C3, NOTE_DS3, NOTE_G3};
int two[] = {NOTE_D3, NOTE_F3, NOTE_A3};
int three[] = {NOTE_DS3, NOTE_G3, NOTE_AS3};
int four[] = {NOTE_F3, NOTE_GS3, NOTE_C4};
int five[] = {NOTE_G3, NOTE_B3, NOTE_D4};
int six[] = {NOTE_GS3, NOTE_C4, NOTE_DS4};
int seven[] = {NOTE_B2, NOTE_D3, NOTE_F3};

int *chords[7] = {one, two, three, four, five, six, seven};

int onePossibles[] = {0, 1, 2, 3, 4, 5, 6};
int twoPossibles[] = {4, 6};
int threePossibles[] = {5};
int fourPossibles[] = {4, 6};
int fivePossibles[] = {0, 2, 5};
int sixPossibles[] = {1, 3};
int sevenPossibles[] = {0, 2};

int *possibilities[7] = {
  // if we're on one, we can go anywhere
  onePossibles,
  // two can go to five or seven
  twoPossibles,
  // three can go to six
  threePossibles,
  // four can go to seven or five
  fourPossibles,
  // five cn go to one or three
  fivePossibles,
  // six can go to two or four
  sixPossibles,
  // seven can go to one or three
  sevenPossibles
};

int currentChordIndex;

void setup() {
  randomSeed(analogRead(0));
  currentChordIndex = 0;
}

void loop() {

  for (int totalNotes = 0; totalNotes < 5; totalNotes++) {

    int noteDuration = 1000 / (random(1, 3) * 2);
    tone(8, chords[currentChordIndex][random(0, 2)], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30 * random(1, 2);
    delay(pauseBetweenNotes);
    noTone(8);
  }
  if (currentChordIndex == 0 || currentChordIndex == 4){
    int pauseBetweenChords = 1000 / (random(2, 8)) * random(0, 3);
    delay(pauseBetweenChords);
    noTone(8);
  };

  int numPoss = sizeof(possibilities[currentChordIndex]) / sizeof(0) + 1;
  currentChordIndex = possibilities[currentChordIndex][random(0, numPoss)];

}





