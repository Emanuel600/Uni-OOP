OBJS=main_p2.o poli_p2.o
COMPILER=g++
EXEC=P2-exec

OPTIONS=-g -Wall
COMPILE=$(COMPILER) $(OPTIONS)

P2-exec: $(OBJS)
	$(COMPILE) -Og -o $(EXEC)-debug $(OBJS)
	./$(EXEC)-debug

opt: $(OBJS)
	$(COMPILE) -O3 -o $(EXEC)-release $(OBJS) -O3
	./$(EXEC)-release

%.o: %.cpp
	$(COMPILE) -c $< -o $@

clean-obj:
	rm -f *o

clean:
	rm -f *o $(EXEC)
