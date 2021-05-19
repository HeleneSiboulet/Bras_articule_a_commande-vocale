import voce.*;



void setup() {
  SpeechInterface.init("/Users/macHelene/Documents/Processing/libraries/voce/library", true, true, "/Users/macHelene/Documents/Processing/libraries/voce/grammar", "direction");
}


void draw() {
  
  delay(100);
  if(voce.SpeechInterface.getRecognizerQueueSize() > 0){
   System.out.println(voce.SpeechInterface.popRecognizedString()+ "  ");
  }
 }
