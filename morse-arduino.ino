// Include libraries
#include <LiquidCrystal.h>

// Initialize all physical inputs
const int buttonPin = 2;
const int translatePin = 3;

// Initialize all variables
long lastTimeChanged = 0;
int translatePress = 0;

const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String morseToTranslate = "";
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
	pinMode(buttonPin, INPUT);
	pinMode(translatePin, INPUT);

	lcd.begin(16, 2);
	lcd.setCursor(0,0);
	lcd.print("Enter morse:");
	delay(1000);
	lcd.clear();
};

void loop()
{
	lcd.setCursor(0,0);
	lcd.print(morseToTranslate);
	lcd.blink();

	// When the translate button is pressed
	if (digitalRead(translatePin) == 1 && translatePress == 0)
	{
		Serial.println(morseToTranslate);
		Serial.println(morseToText(morseToTranslate));
		lcd.clear();
		lcd.print(morseToText(morseToTranslate));
		lcd.noBlink();
		delay(3000);
		lcd.clear();
		lcd.blink();

		translatePress = 1;
	};

	// Prevent infinite loop on translate button press
	if (digitalRead(translatePin) == 0 && translatePress == 1)
	{
		translatePress = 0;
		morseToTranslate = "";
	};

	// When morse button press
	if (digitalRead(buttonPin) == 1)
	{
		lastTimeChanged = millis(); // Store time of when pressed

		while (digitalRead(buttonPin) == 1)
		{
		}; // Wait until unpressed

		// Execute code depending on time pressed
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