CFLAGS=-g -O3

all:tokenize

uimain.o: uimain.h
tokenizer.o: tokenizer.h
history.o: history.h

tokenize: uimain.o tokenizer.o history.o
          cc -o $@ $^ $(CFLAGS)

clean:
       rm -f *.o tokenize
