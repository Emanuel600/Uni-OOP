# flags do compilador
CC	= g++
CFLAGS	= -Wall

# Arquivos do projeto
SRCS	= main_p2.cpp poli_p2.cpp
OBJS	= $(SRCS:.cpp=.o)
EXE	= P2-bin

.PHONY: all clean debug release prep remake

# Padrão
all: prep debug

# Para debug
DBGDIR	= debug
DBGEXE	= $(DBGDIR)/$(EXE)
DBGOBJS = $(addprefix $(DBGDIR)/, $(OBJS))
DBGCFLAGS=-g -O0 -DDEBUG

debug: $(DBGEXE)

$(DBGEXE): $(DBGOBJS)
	$(CC) $(CFLAGS) $(DBGCFLAGS) -o $(DBGEXE) $^
	./$(DGBEXE)

$(DBGDIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(DBGCFLAGS) -o $@ $<

# Para release
RELDIR	= release
RELEXE	= $(RELDIR)/$(EXE)
RELOBJS = $(addprefix $(RELDIR)/, $(OBJS))
RELCFLAGS=-O3 -DNDEBUG

release: $(RELEXE)

$(RELEXE): $(RELOBJS)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $(RELEXE) $^
	valgrind ./$(RELEXE)

$(RELDIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(RELCFLAGS) -o $@ $<

prep:
	@mkdir -p $(DBGDIR) $(RELDIR)

remake: clean all # Útil caso só modifique algo em .h ou na Makefile

clean:
	rm -f $(DBGDIR)/* $(RELDIR)/*
