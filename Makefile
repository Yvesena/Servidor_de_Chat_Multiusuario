CC = gcc
CFLAGS = -Wall -pthread -Iinclude   # -Iinclude diz ao compilador onde achar libtslog.h

# Arquivos de saída
OBJ = libtslog/tslog.o testes/test_logging.o

all: test_logging

# Compila a biblioteca
libtslog/tslog.o: libtslog/tslog.c include/libtslog.h
	$(CC) $(CFLAGS) -c libtslog/tslog.c -o libtslog/tslog.o

# Compila o programa de teste
testes/test_logging.o: testes/test_logging.c include/libtslog.h
	$(CC) $(CFLAGS) -c testes/test_logging.c -o testes/test_logging.o

# Linka tudo e gera o executável
test_logging: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o test_logging

clean:
	rm -f libtslog/*.o testes/*.o test_logging app.log
