.PHONY: clean test all install

all:
	python3 setup.py build_ext --inplace

install:
	python3 setup.py install

clean:
	-rm *.so

test:
	#@sh ./testit.sh
	@python3 ./tt.py


