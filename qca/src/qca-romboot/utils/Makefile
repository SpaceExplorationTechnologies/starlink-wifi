
DIRS = bin2hex checksum array2bin bin2barray

all:
	for i in $(DIRS) ; do make -C $$i || exit $? ; done

clean :
	for i in $(DIRS) ; do make -C $$i clean; done
