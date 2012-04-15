semiscriptc: compiler.o
	gcc compiler.c -o semiscriptc

distbuild: semiscriptc
	mkdir -p distbuild/JS && ./semiscriptc -js semicolon.semi > distbuild/JS/semicolon.js
	mkdir -p distbuild/CoffeeScript && ./semiscriptc -cs semicolon.semi > distbuild/CoffeeScript/semicolon.coffee

clean:
	rm -rf semiscriptc *.o distbuild
