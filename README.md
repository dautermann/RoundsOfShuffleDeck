# RoundsOfShuffleDeck

## GENERAL DESCRIPTION:
This module solves a coding problem that involves shuffling a deck of cards.  The problem description is as follows:
You are given a deck containing n cards.  While holding the deck:

1. Take the top card off the deck and set it on the table
2. Take the next card off the top and put it on the bottom of the deck in your hand.
3. Continue steps 1 and 2 until all cards are on the table.  This is a round.
4. Pick up the deck from the table and repeat steps 1-3 until the deck is in the original order.

Write a program to determine how many rounds it will take to put a deck back into the original order. This will involve creating a data structure to represent the order of the cards.  This program should be written in C or C++.  Do not use STL.  It should take a number of cards in the deck as a command line argument and write the result to stdout. 

## ANSWER elaboration

A very nice explanation as to what's going on (and the number of rounds required) can be found in this [Stackexchange question/answer](https://codegolf.stackexchange.com/questions/15292/obtaining-ordering-of-cards).

Tests (1 through 50):

```
1: 1
2: 2
3: 3
4: 2
5: 5
6: 6
7: 5
8: 4
9: 6
10: 6
11: 15
12: 12
13: 12
14: 30
15: 15
16: 4
17: 17
18: 18
19: 10
20: 20
21: 21
22: 14
23: 24
24: 90
25: 63
26: 26
27: 27
28: 18
29: 66
30: 12
31: 210
32: 12
33: 33
34: 90
35: 35
36: 30
37: 110
38: 120
39: 120
40: 26
41: 41
42: 42
43: 105
44: 30
45: 45
46: 30
47: 60
48: 48
49: 120
50: 50
```

31 produces a peculiar output; it goes through 210 rounds.

It appears that primes have large cycles. For example, 97 has the largest cycle under 100: 6435.
