# Project: Oxymetre
# Auteurs: Axel AUBRY - Pierre PICARD

#--- Fichiers sources -------------------------------------------------------------
FILES=affichage.c \
      calculPouls.c \
      calculSpO2.c \
      finDescr.c \
      finFichier.c \
      finMem.c \
      finUSB.c \
      fir.c \
      iir.c \
      initDescr.c \
      initFichier.c \
      initMem.c \
      initUSB.c \
      lecture.c \
      lectureUSB.c \
      mesure.c \
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
