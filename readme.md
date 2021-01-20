# Projet Acceleration materien avec HLS

Groupe : 
* SOUALAH Mohand Tahar
* SI YOUCEF Amine
    

## Partie HLS:

    Cette partie consiste en la synthèse d'IP core grace a vivado HLS

### Partie 01:

Lors de cette partie, nous avions réalisé des sous scripts tcl qu'on lancer grace a python

#### Execution

* Lancer vivado hls Command prompt
* Ce rendre au repertoire ``hls``
* Executer le script python ``python run.py``

#### Résultat:

Les résultats obtenu sont présent dans la présentation intermédiaire effectué le 19/01/2021


### Partie 02:

Lors de cette 2eme partie, nous tentons d'effectuer l'automatisation entierement grace a un script python et cela en :
* Faire une combinaison de toute les directives possibles.
* Ecrire chaque directive dans un fichier ``Directives.tcl``
* Lancer la synthèse ``pyRun.tcl`` en passant le nom de la solution comme parametre.

Par la suite on envisage d'ajouter des algorithms qui nous permetront d'orienter l'automatisation et cela en :
* Suprimer une solution si elle consome plus de ressources que disponible.
* Orienter le choix des directives grace a un algo d'optimisation

#### Execution

* Lancer vivado hls Command prompt
* Ce rendre au repertoire ``hls``
* Executer le script python ``python pyRun.py``
