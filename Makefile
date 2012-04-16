semiscriptc: compiler.c
	gcc compiler.c -o semiscriptc

compiler.c:
	gperf compiler.gperf > compiler.c

distbuild: semiscriptc
	mkdir -p distbuild/JS && ./semiscriptc -js semicolon.semi > distbuild/JS/semicolon.js
	mkdir -p distbuild/CoffeeScript && ./semiscriptc -cs semicolon.semi > distbuild/CoffeeScript/semicolon.coffee

clean:
	rm -rf compiler.c semiscriptc *.o distbuild
