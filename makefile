movie.gif: datos.dat plot.py
	python -W ignore plot.py

%.dat : a.out
	./a.out 

a.out: CarlosCordoba_Ejercicio30.cpp
	g++ CarlosCordoba_Ejercicio30.cpp

clean:
	rm -rf a.out datos.dat movie.gif *~