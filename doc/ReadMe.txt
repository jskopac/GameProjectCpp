1. Beskrivning:

Vårat spel är baserat på pac-man. Spelaren styr pac-man figuren med hjälp av piltangenterna (upp, ner, höger, vänster) och målet är att äta så många prickar som möjligt utan att krocka med något spöke, om man krockar med ett spöke så avslutas spelet och skärmen visar vilken poäng man fick.





2. Instruktion för att bygga och testa:

Vi har använt filstrutkuren som finns på kurssidan i Learn.
Bildfilerna som används i spelet finns i ./resources/images och fonten som används finns i ./resources/fonts.
För att bygga spelet navigerar man till rotmappen i en terminal, skriver “make” och sen kör man play filen som hamnar i ./build/debug mappen, t.ex. genom att skriva ./build/debug/play i samma terminal.

För att testa spelet så kan man styra pacman och se om det går att äta prickarna, om poängen går upp och om spelet avslutas när man kolliderar med ett spöke.

(Vi har använt MacOS med ARM-processorer)
