import numpy as np
import matplotlib.pyplot as plt

# Variable a modifier avant execution
nomfichier = "euler.txt" # <== fichier de donnees
#nomfichier = "logistique.txt"                     # <== fichier de donnees

# Récupération du nom de la fonction tabulée
fonction_tab = nomfichier[ : nomfichier.rfind(".")]
nomgraph = fonction_tab+".pdf" #  idem fic. entree avec extension .pdf

try:      # ouverture du fichier de donnees
  fich = open(nomfichier, "r")
except:
  print(" ! Impossible d'ouvrir le fichier %s."%nomfichier )
  print(" ! Verifier le chemin.\n")
  exit()

# Lecture des lignes d'entete
ligne = fich.readline().replace("\n","") # sans caractere de fin de ligne
entete= [ ]
while( ligne[0] == "#" ):
   entete.append( ligne[1:] )
   ligne =  fich.readline().replace("\n","")
fich.close()
print( " > fichier %s : %d lignes d'entete"%( nomfichier, len(entete) ) )

# concatenation des entetes en une seule ligne de titre :
titre = " ".join(entete)

# Lecture des donnees du fichier :
tab = np.loadtxt( nomfichier, dtype="float")


# Creation des listes d'abscisses/ordonnees : 1ere et 2eme colonnes
x  = tab[:,0]
y  = tab[:,3]

# Creation du graphique
plt.figure( figsize=(11.69, 8.27) ) # taille en inches : A4 paysage
plt.title( titre, fontsize=8)
plt.grid()

#plt.plot(x, y, label=fonction_tab)                # <== choix de la legende

plt.plot(x,y, label=fonction_tab)
plt.xlabel("x")                                   # <== variable d'abscisse
plt.ylabel("y")                                   # <== variable d'ordonnee

plt.autoscale(enable=True, axis='both', tight=None)

plt.legend()
fig = plt.gcf()
fig.savefig(nomgraph) # sauvegarde du fichier au format PDF
print(" < Le graphique %s a ete cree."%(nomgraph) )
print("   \tVous pouvez le visualiser avec :  okular %s"%(nomgraph))

plt.show()
plt.clf() # nettoyage ('clear figure')
