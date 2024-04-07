#	Nome: Rafael Urbanek Laurentino
#	GRR: 20224381
#	Nome: Vitor Lorenzo Cumim
#	GRR: 20224757 

# flags para compilação do likwid.
LIKWID = /home/soft/likwid
LIKWID_FLAGS = -I$(LIKWID)/include
LIKWID_LIB = -L${LIKWID}/lib -llikwid

# falgs de compilação.
CFLAGS = -Wall -O0 -DLIKWID_PERFMON $(LIKWID_FLAGS) -g # flags de compilacao 
CC = gcc

# regra default
	all = perfSl

# arquivos-objeto
	objects = perfSl.o sl.o eg.o gs.o eg3d.o gs3d.o utils.o
	fonte = ! -name '*.c' ! -name 'Makefile' ! -name 'README' ! -name '*.h' ! -name '*.bash'  
     
perfSl: $(objects)
	$(CC) $(objects) -o $(all) $(LIKWID_LIB) -lm

sl.o: sl.c
	$(CC) -c $(CFLAGS) sl.c

eg.o: eg.c
	$(CC) -c $(CFLAGS) eg.c

gs.o: gs.c
	$(CC) -c $(CFLAGS) gs.c

eg3d.o: eg3d.c
	$(CC) -c $(CFLAGS) eg3d.c

gs3d.o: gs3d.c
	$(CC) -c $(CFLAGS) gs3d.c

utils.o: utils.c
	$(CC) -c $(CFLAGS) utils.c

perfSl.o: perfSl.c
	$(CC) -c $(CFLAGS) perfSl.c

clean:                # Remove todos os arquivos temporários (.o) e o executável beale
	rm -f $(all) $(objects)

purge: clean          # Remove tudo o que não for o código-fonte original
	find . -type f $(fonte) -delete
