# Social-Network
Representing trust relationships between users in a social network with the use of directed graphs and identifying equivalence classes

# How to run
```bash
cd Social-Network/
make
make run
make clean
 ```
# Objective
This program picks out the nodes in the directed graph that have an equivalence relation. Recall that equivalence relations are those that reflexivity, symmetry, and transitivity. 

# Reflexivity
A Relation is reflexive if it contains the ordered pair, (a, a). In other words, a reflexive relation in which every relation relates to its self. A popular example is a=a.

# Symmetry
Symmetry says if an element a is related b then b must also be related to a. A popular example would be a != b. Since a != b, that means b != a.

# Transitivity
Transitivity says if a is related to b and b is related to c then c must be related to a. A popular example of this would be 1 < 2 < 3 => 1 < 3.

# How the input works.
Some example inputs are placed into the digraph.txt files. So the first line in the input file represents how many lines of relations are about to follow. The first element from the second line on is the current node and the numbers that follow are the relation that it has. So for instance,
```
1
6 1 2 7 0
```
The 1 represents that there is 1 relation defined below. 6 1 2 7 0 means that 6 has a relation with 1, 2, and 7. The 0 tells the program that it is the end of the line.

# Output
The program outputs the nodes that have an equivalence relation. Note that every node has an equivalent relation with itself, so all the nodes will appear in the output. Outputs of the following format:
```
{4,5,6}
```
This means that node 4 is in an equivalence relation with nodes 5 and 6.

# Applications
Equivalence relations exist everywhere, however they are very prominent in social networks, specifically in recommender systems on social networks. For instance, if node A is in equivalence relations with nodes B and C, it means that user A is good friends with user B and user C (node A trusts node B and node C). So it makes sense to recommend user B to make friends with user C and vice-versa, as it is highly like that they may know each other. Now you know how Facebook's "People You May Know" section works!  
