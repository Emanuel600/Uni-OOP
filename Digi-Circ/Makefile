# Compilador
CC	= g++
CFLAGS	= -Wall -Werror

# Arquivos
SRCS	= Circ-Digi.cpp portas.cpp
OBJS	= $(SRCS:.cpp=.o)
EXE	= Simuador\ de\ Circuitos\ Digitais

.PHONY: all clean debug release prep remake

# Padrão
all: prep debug

# Regras de debug
DDIR	= debug
DEXE	= $(DDIR)/$(EXE)
DOBJS	= $(addprefix $(DDIR)/, $(OBJS))
DFLAGS	= $(CFLAGS) -O0 -g -DDEBUG

# Debug
debug: $(DEXE)

$(DEXE): $(DOBJS)
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

$(REXE): $(ROBJS)
	$(CC) $(RFLAGS) $^ -o $(REXE)
	valgrind ./$(RDIR)/$(EXE)

$(RDIR)/%.o: %.cpp
	$(CC) $(RFLAGS) -c $^ -o $@

prep:
	@mkdir -p release debug

remake: clean all

clean: rm -f $(RDIR) $(DDIR)
