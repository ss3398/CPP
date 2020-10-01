CC = g++
OUTPUTDIR = .
OUTPUT = Hw3cc
RM = rm
CFLAGS = -Werror
POUTFILE = Hw3ccout.txt
TAR = tar
TAROPTS = -czvf
TARFILE = Hw3.tar.gz


all: Hw3cc.cc Hw3.h
	$(CC) -o $(OUTPUTDIR)/$(OUTPUT) $(CFLAGS) Hw3cc.cc
	$(OUTPUTDIR)/$(OUTPUT) > $(POUTFILE)
	$(TAR) $(TAROPTS) $(TARFILE) Hw3cc.cc Hw3.h gawk.code numbers.txt Makefile $(POUTFILE)

clean:
	$(RM) $(OUTPUT) $(TARFILE)


