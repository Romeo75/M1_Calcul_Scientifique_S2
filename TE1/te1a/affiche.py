import numpy as np
import matplotlib.pyplot as plt

# Variable a modifier avant execution
nomfichier = "sin_left.txt" # <== fichier de donnees
nomfichier2 = "sin_right.txt"
nomfichier3 = "sin_centered.txt"
#nomfichier = "logistique.txt"                     # <== fichier de donnees

# Récupération du nom de la fonction tabulée
fonction_tab = nomfichier[ : nomfichier.rfind(".")]
fonction_tab2 = nomfichier2[ : nomfichier2.rfind(".")]
fonction_tab3 = nomfichier3[ : nomfichier3.rfind(".")]
nomgraph = fonction_tab+".pdf" #  idem fic. entree avec extension .pdf

try:      # ouverture du fichier de donnees
  fich = open(nomfichier, "r")
  fich2 = open (nomfichier2, "r")
  fich3 = open (nomfichier3, "r")
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
tab2 = np.loadtxt( nomfichier2, dtype="float")
tab3 = np.loadtxt( nomfichier3, dtype="float")

# Creation des listes d'abscisses/ordonnees : 1ere et 2eme colonnes
x  = tab[:,0]
y  = tab[:,1]

x2 = tab2[:,0]
y2 = tab2[:,1]

x3 = tab3[:,0]
y3 = tab3[:,1]

print(y2)
print(y3)

# Creation du graphique
plt.figure( figsize=(11.69, 8.27) ) # taille en inches : A4 paysage
plt.title( titre, fontsize=8)
plt.grid()

#plt.plot(x, y, label=fonction_tab)                # <== choix de la legende

plt.loglog(x,y, label=fonction_tab)
plt.loglog(x2,y2, label=fonction_tab2)
plt.loglog(x3,y3, label=fonction_tab3)
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
