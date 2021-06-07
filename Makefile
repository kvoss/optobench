.PHONY: clean test all

all:
	python setup.py build_ext --inplace

clean:
	-rm *.so

test:
	sh ./testit.sh

