# Project: Oxymetre
# Auteurs: Axel AUBRY - Pierre PICARD

#--- Fichiers sources -------------------------------------------------------------
FILES=Affichage/affichage.c \
      Filtrage/filtrage.c \
      Lecture/lecture.c \
      main.c 

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
