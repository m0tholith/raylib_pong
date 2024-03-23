linux:
	cc src/* -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -ogame
	./game
