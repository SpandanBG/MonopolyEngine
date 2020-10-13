# MONOPOLY GAME

## # COMPONENTS

- **Die** : The _Die_ component represents the real world die with 6 sides. This is implemented using random number generator ranging from 1 to 6. The die is throw twice to get the simulation of throwing two dice.
- **Block** : The _Block_ component represents the a single step a player can take in the board. Each block has its own identification by name and may or may not have a color to it.
- **Board** : The _Board_ component represents the game board that contains the list of position that players can take. The _Board_ contains a collection of _Block_ which the player takes parts in in every turn.
- **Player** : The _Player_ component represents the real world player. Each player owns a _PlayerPeice_ which is unique to the game world. The _Player_ also has their own name, money and can collect a list of _Board_ position they can own in a match.
- **PlayerPeice** : A _PlayerPeice_ is a unique identification of a _Player_. One _PlayerPeice_ can be given to only one _Player_.
- **Match** : A group of *Player*s take part in a _Match_ with a given _Board_. A _Match_ can have one or more _Rounds_. In each _Round_ all the *Player*s take their turn to move on the _Board_ at least once. The _Match_ is over when only one _Player_ is left from the _PlayPool_ and non in the _SkipPool_.
- **Round** : A _Round_ contains as many number of _Turns_ as there are number of *Player*s. The _Round_ is complete when all the *Player*s have completed all their.
- **Turn** : In a _Turn_ each _Player_ performs a series of actions. The _Player_ throws the two dice; move in the board; interacts with the block on that position and then end their turn.
- **PlayPool** : The _PlayPool_ contains the list of *Player*s that can still play the game in a _Round_. If a _Player_ meets the lost criteria of the game, the _Player_ is moved to the _DeadPool_.
- **DeadPool** : The _DeadPool_ contains the list of *Player*s that cannot take part in a _Round_. When a _Player_ meets the lost criteria, the _Player_ is moved to the _DeadPool_.
- **SkipPool** : The _SkipPool_ contains the list of *Player*s and their respective number of rounds that they have to skip. A _Player_ may be moved to a the _SkipPool_ by an _Event_ block.

---

### # THE BLOCK COMPONENT

The _Block_ component can be either of two components:

- **Location** : A _Location_ block has a few more attributes. A _Location_ block can be bought by a player for money. Each _Location_ has its own price. If a player does not have enough money to buy the _Location_, the _Location_ is put up for auction to the rest of the *Player*s. A _Player_ who doesn't own a _Location_ falls on that _Location_ block has to pay a set rent to the owner _Player_.
- **Event** : A _Event_ block does not contain any location. However they may trigger an event that can change the landing _Player_'s money and/or move them to the _SkipPool_ for a set number of *Round*s. An _Event_ block can also give a _Player_ an additional _Turn_.

---

### # GAME START

A group of *Player*s enter for a _Match_ which a fixed amount of money to the starting _Block_ of the _Board_. At the beginning of the _Match_ a random _Player_ is selected to start the _Round_ first.

---

### # THE LOSING CRITERIA

A _Player_ falls under the losing criteria when their money is reduced to 0.
