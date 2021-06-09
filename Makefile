.PHONY: clean test all install

all:
	python setup.py build_ext --inplace

install:
	python setup.py install

clean:
	-rm *.so

test:
	sh ./testit.sh

