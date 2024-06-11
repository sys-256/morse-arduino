// initialize all fysical inputs
const int buttonPin = 2;
const int translatePin = 3;

// initialize all variables
long lastTimeChanged = 0;
int translatePress = 0;

String morseToTranslate = "";
const char Values[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.,:?'-/()\"=+@ ";
const String Keys[50] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
						 "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
						 "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
						 ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--",
						 "---...", "..--..", ".----.", "-....-", "-..-.", "-.--.", "-.--.-", ".-..-.",
						 "-...-", ".-.-.", ".--.-.", "/"};

// setup serial and pinmodes
void setup()
{
	pinMode(buttonPin, INPUT);
	pinMode(translatePin, INPUT);
	Serial.begin(9600);
};

// run everytime
void loop()
{
	// When the translate button is pressed
	if (digitalRead(translatePin) == 1 && translatePress == 0)
	{
		Serial.println(morseToTranslate);
		Serial.println(morseToText(morseToTranslate));

		translatePress = 1;
	};

	// prevent infinite loop on translate button press
	if (digitalRead(translatePin) == 0 && translatePress == 1)
	{
		translatePress = 0;
		morseToTranslate = "";
	};

	// when morse button press
	if (digitalRead(buttonPin) == 1)
	{
		lastTimeChanged = millis(); // store time when pressed

		while (digitalRead(buttonPin) == 1)
		{
		}; // wait until unpressed

		// execute code depending on time pressed
		if (millis() - lastTimeChanged < 15)
		{
			Serial.println("False Registery");
		}
		else if (millis() - lastTimeChanged < 250)
		{
			Serial.println("Short");
			morseToTranslate += ".";
		}
		else if (millis() - lastTimeChanged < 1000)
		{
			Serial.println("Long");
			morseToTranslate += "-";
		}
		else if (millis() - lastTimeChanged < 4000)
		{
			Serial.println("nieuwe letter");
			morseToTranslate += " ";
		}
		else
		{
			Serial.println("Space");
			morseToTranslate += "/";
		};
	};
};

// morseToText function
String morseToText(String input)
{
	// Convert to buffer
	char buffer[input.length() + 1];
	input.toCharArray(buffer, input.length() + 1);

	// Split at every space
	char *currentSplit;
	String result = "";
	currentSplit = strtok(buffer, " ");
	while (currentSplit != NULL)
	{
		// Find the index of the key
		int keyIndex;
		for (int i = 0; i < sizeof(Keys) / sizeof(Keys[0]); ++i)
		{
			if (Keys[i].equals(String(currentSplit)))
			{
				keyIndex = i;
				break;
			}
		}

		// Add the value to the result
		result += String(Values[keyIndex]);
		currentSplit = strtok(NULL, " ");
	}

	return result;
}