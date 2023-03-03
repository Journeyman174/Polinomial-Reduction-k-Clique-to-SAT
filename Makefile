IN=tests/in/$(CTG)/test$(TEST).in
OUT=tests/out/$(CTG)/test$(TEST).out
AUX=tests/aux/$(CTG)/test$(TEST).aux

build:
	#complete if necessary
	g++ kCliqueBKT.cpp -o kCliqueBKT
	g++ kCliqueReduction.cpp -o kCliqueReduction
run_backtracking:
	#complete rule	
	./kCliqueBKT $(IN) > $(OUT)
	
run_reduction:
	#complete here
	./kCliqueReduction $(IN) > $(AUX)

clean:
	#complete if necessary
	rm -rf kCliqueBKT
	rm -rf kCliqueReduction
