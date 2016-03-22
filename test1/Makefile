# Project: Oxymetre
# Auteurs: Axel AUBRY - Pierre PICARD

#--- Fichiers sources -------------------------------------------------------------
FILES=affichage.c \
      fir.c \
      iir.c \
      lecture.c \
      mesure.c \
      main.c \
      initmem.c \
      integration.c

#--- Nom de l'executable -----------------------------------------------------------
EXECUTABLE=oxymetre

#--- Building ------------------------------------------------------------------
$(EXECUTABLE):$(FILES)
	gcc $^ -o $@

#--- Cleaning ------------------------------------------------------------------
clean:
	rm -f $(EXECUTABLE)

#--- Building and cleaning -----------------------------------------------------
all: clean $(EXECUTABLE)
