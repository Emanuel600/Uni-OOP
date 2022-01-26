OBJS=main_p2.o poli_p2.o
COMPILER=g++
EXEC=P2-exec

OPTIONS=-g -Wall
COMPILE=$(COMPILER) $(OPTIONS)

P2-exec: $(OBJS)
	$(COMPILE) -o $(EXEC) $(OBJS)
	./P2-exec

%.o: %.cpp
	$(COMPILE) -c $< -o $@

clean-exec:
	rm -f *o

clean:
	rm -f *o $(EXEC)
