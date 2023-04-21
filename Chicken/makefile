
chicken : Global.o Player.o Gift.o Explode.o Chicken.o Bullet.o Boss.o Base.o main.o 
	g++ Global.o Player.o Gift.o Explode.o Chicken.o Bullet.o Boss.o Base.o main.o -o chicken -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
testRegression : testRegression.o Global.o Player.o Gift.o Explode.o Chicken.o Bullet.o Boss.o
	g++ Global.o Player.o Gift.o Explode.o Chicken.o Bullet.o Boss.o testRegression.o -o testRegression
testRegression.o : testRegression.cpp scr/core/Boss.h scr/core/Bullet.h scr/core/Chicken.h scr/core/Explode.h scr/core/Gift.h scr/core/Global.h scr/core/Player.h
	g++ -Wall -c testRegression.cpp -g -o testRegression.o 
Global.o : scr/core/Global.h scr/core/Global.cpp
	g++ -Wall -c scr/core/Global.cpp -g -o Global.o
Player.o : scr/core/Player.h scr/core/Player.cpp scr/core/Bullet.h scr/core/Global.h
	g++ -Wall -c scr/core/Player.cpp -g -o Player.o
Gift.o : scr/core/Gift.cpp scr/core/Gift.h scr/core/Global.h
	g++ -Wall -c scr/core/Gift.cpp -g -o Gift.o
Explode.o : scr/core/Explode.h scr/core/Explode.cpp scr/core/Global.h
	g++ -Wall -c scr/core/Explode.cpp -g -o Explode.o
Chicken.o : scr/core/Chicken.h scr/core/Chicken.cpp scr/core/Global.h scr/core/Bullet.h scr/core/Explode.h
	g++ -Wall -c scr/core/Chicken.cpp -g -o Chicken.o
Bullet.o : scr/core/Bullet.h scr/core/Bullet.cpp scr/core/Global.h
	g++ -Wall -c scr/core/Bullet.cpp -g -o Bullet.o
Boss.o : scr/core/Boss.h scr/core/Boss.cpp scr/core/Bullet.h scr/core/Global.h scr/core/Explode.h
	g++ -Wall -c scr/core/Boss.cpp -g -o Boss.o
Base.o : scr/sdl2/Base.h scr/sdl2/Base.cpp scr/core/Boss.h scr/core/Bullet.h scr/core/Chicken.h scr/core/Explode.h scr/core/Gift.h scr/core/Global.h scr/core/Player.h
	g++ -Wall -c scr/sdl2/Base.cpp -g -o Base.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
main.o : scr/sdl2/main.cpp scr/sdl2/Base.h
	g++ -Wall -c scr/sdl2/main.cpp -g -o main.o -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
clean: 
	rm *.o main testRegression