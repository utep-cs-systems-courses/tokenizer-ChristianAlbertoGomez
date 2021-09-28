CFLAGS=-g -O3

all:tokenizer

uimain.o: uimain.h
tokenizer.o: tokenizer.h
history.o: history.h

tokenizer: uimain.o tokenizer.o history.o
          cc -o $@ $^ $(CFLAGS)

clean:
       rm -f *.o tokenize
run:
       ./tokenizer
