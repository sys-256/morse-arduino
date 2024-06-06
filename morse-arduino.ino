const String morseToTranslate = ".-..-. - . ... - .----. -..-. ..--- ---.. ----. ...-- ---... / -.--. -...- .-.-.- --..-- -.--.-";
const char Values[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.,:?'-/()\"=+@ ";
const String Keys[50] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
						 "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
						 "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
						 ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--",
						 "---...", "..--..", ".----.", "-....-", "-..-.", "-.--.", "-.--.-", ".-..-.",
						 "-...-", ".-.-.", ".--.-.", "/"};

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	Serial.println(morseToTranslate);
	Serial.println(morseToText(morseToTranslate));
	Serial.println();
	delay(1000);
}

String morseToText(String input)
{
	/* Convert to buffer */
	char buffer[input.length() + 1];
	input.toCharArray(buffer, input.length() + 1);

	/* Split at every space */
	char *currentSplit;
	String result = "";
	currentSplit = strtok(buffer, " ");
	while (currentSplit != NULL)
	{
		/* Find the index of the key */
		int keyIndex;
		for (int i = 0; i < sizeof(Keys) / sizeof(Keys[0]); ++i)
		{
			if (Keys[i].equals(String(currentSplit)))
			{
				keyIndex = i;
				break;
			}
		}

		/* Add the value to the result */
		result += String(Values[keyIndex]);
		currentSplit = strtok(NULL, " ");
	}

	return result;
}
