# morse-arduino

Taakverdeling:

-   Mika: input knop naar morse
-   Bram: printen op LCD
-   Behuizing -> we zien nog wel of dat lukt

Evt. later aanpassen:

-   Datatype van `morseToTranslate` van `String` naar `char` veranderen (want dan is omzetten naar buffer niet meer nodig, maar voor knopje naar morse is String misschien handiger)

Initialiseren Arduino:
- Installeer [de arduino extensie](https://github.com/microsoft/vscode-arduino)
- Verwijder .vscode/
- Ctrl+Shift+P
- Typ in: Arduino: Initialize en run het
- Kies AVRISP mkII als programmer
- Commit de veranderingen in .vscode **niet**
