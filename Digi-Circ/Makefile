# Compilador
CC	= g++
CFLAGS	= -Wall -Werror

# Arquivos
SRCS	= Circ-Digi.cpp portas.cpp
OBJS	= $(SRCS:.cpp=.o)
EXE	= Simuador\ de\ Circuitos\ Digitais

.PHONY: all clean debug release prep

# Padrão
all: prep debug

# Regras de debug
DDIR	= debug
DEXE	= $(DDIR)/$(EXE)
DOBJS	= $(addprefix $(DDIR)/, $(OBJS))
DFLAGS	= $(CFLAGS) -O0 -g -DDEBUG

# Debug
debug: $(DEXE)

$(DEXE): $(DOBJS) portas.h
	$(CC) $(DFLAGS) -o $(DEXE) $^
	./$(DDIR)/$(EXE)

$(DDIR)/%.o: %.cpp
	$(CC) $(DFLAGS) -c $< -o $@

# Regras de release
RDIR	= release
REXE	= $(RDIR)/$(EXE)
ROBJS	= $(addprefix $(RDIR)/, $(OBJS))
RFLAGS	= $(CFLAGS) -O3 -DNDEBUG

# Release
release: $(REXE)

$(REXE): $(ROBJS) portas.h
	$(CC) $(RFLAGS) $^ -o $(REXE)
	valgrind ./$(RDIR)/$(EXE)

$(RDIR)/%.o: %.cpp
	$(CC) $(RFLAGS) -c $^ -o $@

# Preparar diretório
prep:
	@mkdir -p release debug

# Refazer tudo
remake: clean all

# Limpar tudo
clean:
	rm -f $(RDIR)/* $(DDIR)/*
