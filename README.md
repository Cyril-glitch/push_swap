This project has been created as part of the 42 curriculum by *cycolonn*.

# 📊 __Push_swap__


## 💬 __Description__


> __Push_swap__ est un exercice proposé par l'école 42 visant à nous familiariser avec le concept d'architecture basée sur les piles (ou "stack" en anglais) qui sont des structures de données fondées sur le principe LIFO ("last in, first out").

> Cela sera aussi pour nous l'occasion de nous confronter au choix et à l'optimisation d'un algorithme complexe de tri selon les contraintes de performances imposées par le sujet.
Dans ce projet, nous allons devoir réaliser un programme permettant de trier une suite de nombres aléatoires dans un ordre croissant.
Pour cela, nous allons pouvoir, tout au long du projet, répartir nos données dans deux piles (A et B) et y effectuer des mouvements spécifiques qui respectent les contraintes physiques réelles auxquelles sont soumises ce genre de structures.

> Le but final étant :

> ◦ Trier 100 nombres aléatoires en moins de 700 opérations.

> ◦ Trier 500 nombres aléatoires en moins de 5500 opérations.


---

## 📝 __Instructions__


### <ins>Récuperer le projet</ins>


```bash
git clone git@vogsphere.42paris.fr:vogsphere/intra-uuid-7aac1d5f-5b91-4e36-8a29-a31f15222267-7178535-cycolonn

```


### <ins>Compiler</ins>


> créer un executable __push_swap__ dans le sous dossier /bin.

```bash
make        # Compile le projet et génère l'exécutable 'push_swap'
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les objets et l'exécutable
make re     # Recompile tout depuis zéro

```


### <ins>Executer</ins>


> Le programe prend pour argument une suites d'entiers (positifs ou negatifs et sans doublons).
> Il afficheras les operations effectuées pour les trier.

```bash
./bin/push_swap 9 8 7 4 5 6 1 2 3

./bin/push_swap "9 8 7 4 5" 6 1 2 3

```


### <ins>Checker</ins>


> Pour confirmer que la liste a bien etait triée, un checker est fournis dans les ressources du sujet.

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

```

> Affiche "OK" si le programe a réussi a trier notre suite d'entiers.
> Affiche "KO" si ce n'est pas le cas.


---


## 🛠️ __Ressources__


> Cette section liste les ressources documentaires que j'ai utilisées lors de la conception du projet :


◦ __Documentation du projet__ : Sujet Push swap (42).

◦ __Articles sur le Turk Sort__ : [Push Swap_ Turk algorithm explained in 6 steps (Yutong Deng)](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0).
 				  [Push Swap — A journey to find most efficient sorting algorithm (A. Yigit Ogun)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

◦ __Outils de visualisation__ : [Push swap Visualizer (o-reo)](https://github.com/o-reo/push_swap_visualizer).

◦ __Checker et optimisation__ : [complexity](https://github.com/SimonCROS/push_swap_tester).

◦ __Compréhension Algorithmique__ : Explication détaillée des différentes phases du "Turk Sort" (google Gemini).

