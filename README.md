This project has been created as part
of the 42 curriculum by *cycolonn*.

# 📊 __Push_swap__

## Description

__Push_swap__ est un exercice propose par l'ecole 42 visant a nous familiariser avec le concept d'architecture bases sur les piles (ou "stack" en anglais) qui sont des structures des 
donnees fondee sur le principe LIFO ("last in, first out").
Cela sera aussi pour nous l'occasion de nous confronter au choix et a l'optimisation d'un algorithme complexe de tri selon les contraintes de performances imposes par le sujet.
Dans ce projet nous allons devoir realiser un programme permettant de trier une suite de nombres aleatoires dans un ordre croissant.
Pour cela nous allons pouvoir tout au long du projet repartir nos donnees dans deux piles (A et B) et y effectuer des mouvements specifiques qui respect les contraintes physique reel 
auquel sont soumisent ce genre de structures. 

Le But final etant : ◦ trier 100 nombres aleatoires en moins de 700 operations.
		    ◦ trier 500 nombres aleatoires en moins de 5500 operations.

---


## __Instructions__


### recuperer le projet

```
git clone git@vogsphere.42paris.fr:vogsphere/intra-uuid-7aac1d5f-5b91-4e36-8a29-a31f15222267-7178535-cycolonn

```

### compiler

creer un executable __push_swap__ dans le sous dossier /bin.

```
make        # Compile le projet et génère l'exécutable 'push_swap'
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les objets et l'exécutable
make re     # Recompile tout depuis zéro

```

### executer

Le programe pour argument une suites d'entiers (positifs ou negatifs sans doublons).
il afficheras les operations effectuer pour les triers.

```

./bin/push_swap 9 8 7 4 5 6 1 2 3

./bin/push_swap "9 8 7 4 5" 6 1 2 3

```

### checker

Pour confirmer que la liste a bien etait tries, un checker est fournis dans les ressources du sujet voici la commande effectuer pour l'utiliser

```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

```

Affiche "OK" si le programe a reussi a trier notre suite d'entiers.
Affiche "KO" si ce n'est pas le cas.

---


## __Ressources__

Cette sections listes les ressources documentaires que j'ai utilises lors de la conception du projet :

    Documentation du projet : Sujet Push_swap (42).

    Articles sur le Turk Sort : [Push_Swap Turk algorithm explained in 6 steps (Yutong Deng)](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0).
    				[Push Swap — A journey to find most efficient sorting algorithm (A. Yigit Ogun)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

    Outils de visualisation : [Push_swap Visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer).

    checker et optimisation : [complexity](https://github.com/SimonCROS/push_swap_tester).

    Compréhension Algorithmique : Explication détaillée des différentes phases du "Turk Sort" (stratégie de push A vers B, puis rapatriement B vers A)(google Gemini).
