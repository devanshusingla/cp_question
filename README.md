# cp_question
first self made cp question for pclub secy test

#2				Earth vs Fighting

There is tournament of pokemon to test whether ground pokemon are faster or fighting type pokemons. In the tournament, dugtrio is representing ground pokemon and lucario is representing fighting type pokemons. Both pokemons start at their initial position t<sub>0</sub> and b<sub>0</sub>.Dugtrio and Lucario take time T<sub>1</sub> and T<sub>2</sub> respectively. Lucario has to move on pillars, with top of pillar i represented by b<sub>i</sub>. Dugtrio has to go through tunnels linked at some places, which each such place i represented by t<sub>i</sub>. There are n<sub>2</sub> pillars and lucario has to reach to pillar n<sub>2</sub>-1 to win. The pillars between which Lucario can jump are p1<sub>i</sub> and p2<sub>i</sub> and number of such possible jumps are m<sub>1</sub>. There are n<sub>1</sub> interlinks between tunnels and dugtrio has to reach end of this tunnel maze which is at n<sub>1</sub>-1. The tunnels are joined by a<sub>i</sub>. You have to place your bet on one pokemon. On which pokemon will you place your bet to become richer?

values of b<sub>i</sub> and t<sub>j</sub> are i and j respectively and i and j belong to (0, n<sub>1</sub>) and (0, n<sub>2</sub>) respectively.

2<=n<sub>1</sub>, n<sub>2</sub><=20
0<=coordinates<=1000000

#3 INPUT

First line contains space separated n<sub>1</sub> and n<sub>2</sub>.
Followed by space separated m<sub>1</sub> and m<sub>2</sub>.
Followed by space separated T<sub>1</sub> and T<sub>2</sub>.
Following n<sub>1</sub> lines contain x and y coordinates separated by spaces.
Following n<sub>2</sub> lines contain x, y and z coordinates separated by spaces.
Following m<sub>1</sub> lines contain space separated p<sub>i</sub> and p<sub>j</sub>
Following m<sub>2</sub> lines contain space separated a<sub>i</sub> and a<sub>j</sub>

#3 OUTPUT

If lucario will win output "lucario as always" otherwise if dugtrio will win output "dugtrio got better luck today" otherwise if both will reach at same time output "not in mood to bet".

#3 EXAMPLE 1

#4 INPUT

3 3
1 1
2 3
0 0
1 1
2 2
0 0 0
1 1 1
2 2 2
0 1
1 2
0 1
0 2
1 2

#4 OUTPUT

dugtrio got better luck today

#3 EXAMPLE 2

#4 INPUT

4 6
3 5
4 7
0 0
2 0
2 1
1 2
0 0 0
0 0 1
1 0 1
1 1 1
1 1 0
2 1 0
0 1
1 2
2 3
1 3
0 1
1 2
2 3
3 4
4 5
0 5
2 5

#4 OUTPUT

not in mood to bet
