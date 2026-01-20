This project has been created as part of the 42 curriculum by *cycolonn*.

# 📊 __Push_swap__


## 💬__Description__

__Push_swap__ est un exercice proposé par l'école 42 visant à nous familiariser avec le concept d'architecture basée sur les piles (ou "stack" en anglais) qui sont des structures de données fondées sur le principe LIFO ("last in, first out").

Cela sera aussi pour nous l'occasion de nous confronter au choix et à l'optimisation d'un algorithme complexe de tri selon les contraintes de performances imposées par le sujet.
Dans ce projet, nous allons devoir réaliser un programme permettant de trier une suite de nombres aléatoires dans un ordre croissant.
Pour cela, nous allons pouvoir, tout au long du projet, répartir nos données dans deux piles (A et B) et y effectuer des mouvements spécifiques qui respectent les contraintes physiques réelles auxquelles sont soumises ce genre de structures.

Le but final étant :
◦ Trier 100 nombres aléatoires en moins de 700 opérations.
◦ Trier 500 nombres aléatoires en moins de 5500 opérations.

---

## 📝 __Instructions__

### recuperer le projet

```bash
git clone git@vogsphere.42paris.fr:vogsphere/intra-uuid-7aac1d5f-5b91-4e36-8a29-a31f15222267-7178535-cycolonn

```

### compiler

creer un executable __push_swap__ dans le sous dossier /bin.

```bash
make        # Compile le projet et génère l'exécutable 'push_swap'
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les objets et l'exécutable
make re     # Recompile tout depuis zéro

```

### executer

Le programe pour argument une suites d'entiers (positifs ou negatifs sans doublons).
il afficheras les operations effectuer pour les triers.

```bash
./bin/push_swap 9 8 7 4 5 6 1 2 3

./bin/push_swap "9 8 7 4 5" 6 1 2 3

```

### checker

Pour confirmer que la liste a bien etait tries, un checker est fournis dans les ressources du sujet voici la commande effectuer pour l'utiliser

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

```

Affiche "OK" si le programe a reussi a trier notre suite d'entiers.
Affiche "KO" si ce n'est pas le cas.

---

## 🛠️__Ressources__

Cette sections listes les ressources documentaires que j'ai utilises lors de la conception du projet :

Documentation du projet : Sujet Push swap (42).

Articles sur le Turk Sort : [Push Swap_ Turk algorithm explained in 6 steps (Yutong Deng)](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0).
[Push Swap — A journey to find most efficient sorting algorithm (A. Yigit Ogun)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

Outils de visualisation : [Push swap Visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer).

checker et optimisation : [complexity](https://github.com/SimonCROS/push_swap_tester).

Compréhension Algorithmique : Explication détaillée des différentes phases du "Turk Sort" (stratégie de push A vers B, puis rapatriement B vers A)(google Gemini).
