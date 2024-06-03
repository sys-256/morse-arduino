#include <Regexp.h>

void setup() {
  Serial.begin(9600);
}

const String morseToTranslate = "- . ... - / ...- ---fsdf1kl2k --- .-. / .. -. ..-. --- asxz.-. -- .-fdsjcxz1$*( - .. -.-. .-";
const String Keys[51] = { ".-", "-...", "-.-.", "-..", ".", "..-..", "..-.", "--.", "....", "..", ".---",
                          "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                          "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
                          ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--",
                          "---...", "..--..", ".----.", "-....-", "-..-.", "-.--.", "-.--.-",  ".-..-.",
                          "-...-", ".-.-.", ".--.-.", "/" };
const char Values[51] = { 'A', 'B', 'C', 'D', 'E', 'É', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                          'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5',
                          '6', '7', '8', '9', '0', '.', ',', ':', '?', '"', '-', '/', '(', ')', '"',
                          '=', '+', '@', ' ' };

void loop() {
  Serial.println(morseToTranslate);
  Serial.println(morseToText(morseToTranslate));
  Serial.println();
  delay(1000);
}

String morseToText(String input) {
  /* Convert to buffer */
  char buffer[input.length() +1];
  input.toCharArray(buffer, input.length() + 1);

  /* Apply regex statement */
  MatchState ms(buffer);
  ms.GlobalReplace("[^-./ ]", "");

  /* Split every space */
  char *currentSplit;
  String result = "";
  currentSplit = strtok(buffer, " ");
  while (currentSplit != NULL) {
    /* Find the index of the key */
    int keyIndex;
    for (int i = 0; i < 51; ++i) {
      if (Keys[i].equals(String(currentSplit))) {
        keyIndex = i;
        break;
      }
    }

    /* Add the value to the result string */
    result += String(Values[keyIndex]);
    currentSplit = strtok(NULL, " ");
  }

  return result;
}
