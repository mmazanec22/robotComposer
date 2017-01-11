#include "pitches.h"

// low range
//int one[] = {NOTE_C3, NOTE_DS3, NOTE_G3, NOTE_C4};
//int two[] = {NOTE_D3, NOTE_F3, NOTE_GS3, NOTE_B2, NOTE_D4};
//int three[] = {NOTE_DS3, NOTE_G3, NOTE_AS3};
//int four[] = {NOTE_C3, NOTE_F3, NOTE_GS3, NOTE_C4};
//int five[] = {NOTE_B2, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_B3, NOTE_D4};
//int six[] = {NOTE_DS3, NOTE_GS3, NOTE_C4, NOTE_DS4};
//int seven[] = {NOTE_B2, NOTE_D3, NOTE_F3, NOTE_GS3, NOTE_B3};
//int ntwo[] = {NOTE_CS3, NOTE_F3, NOTE_GS3, NOTE_CS4};

// high range
int one[] = {NOTE_C4, NOTE_DS4, NOTE_G4, NOTE_C5};
int two[] = {NOTE_D4, NOTE_F4, NOTE_GS4, NOTE_B2, NOTE_D5};
int three[] = {NOTE_DS4, NOTE_G4, NOTE_AS4};
int four[] = {NOTE_C4, NOTE_F4, NOTE_GS4, NOTE_C5};
int five[] = {NOTE_B3, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B4, NOTE_D5};
int six[] = {NOTE_DS4, NOTE_GS4, NOTE_C5, NOTE_DS5};
int seven[] = {NOTE_B3, NOTE_D4, NOTE_F4, NOTE_GS4, NOTE_B4};
int ntwo[] = {NOTE_CS4, NOTE_F4, NOTE_GS4, NOTE_CS5};

int *chords[8] = {one, two, three, four, five, six, seven, ntwo};

int onePossibles[] = {1, 2, 3, 4, 5, 6, 7};
int twoPossibles[] = {4, 6};
int threePossibles[] = {5};
int fourPossibles[] = {4, 6};
int fivePossibles[] = {0, 2, 5};
int sixPossibles[] = {1, 3, 7};
int sevenPossibles[] = {0, 2};
int ntwoPossibles[] = {4};

int *possibilities[8] = {
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
  sevenPossibles,
  ntwoPossibles
};

int currentChordIndex;
int lastChordIndex;

void setup() {
  randomSeed(analogRead(0));
  currentChordIndex = 0;
}

void loop() {

  int lengthOfChord = 2000;
  int playedSoFar = 0;

  int numNotesPoss = sizeof(chords[currentChordIndex]) / sizeof(chords[currentChordIndex][0]) + 1;

  while (playedSoFar <= lengthOfChord) {

    int noteDuration = 1000 / (random(1, 3) * 2);
    playedSoFar = playedSoFar + noteDuration;

    tone(8, chords[currentChordIndex][random(0, numNotesPoss)], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30 * random(1, 2);
    delay(pauseBetweenNotes);
    noTone(8);
  }
  if (currentChordIndex == 0 && (lastChordIndex == 4 || lastChordIndex == 6)){
    tone(8, NOTE_C4, 1000/2);
    int pauseBetweenChords = 2000;
    delay(pauseBetweenChords);
    noTone(8);
  };

  lastChordIndex = currentChordIndex;
  int numPoss = sizeof(possibilities[currentChordIndex]) / sizeof(0) + 1;
  currentChordIndex = possibilities[currentChordIndex][random(0, numPoss)];

}





