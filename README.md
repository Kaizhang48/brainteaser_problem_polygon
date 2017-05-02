# brainteaser_problem_polygon
A group of graphic designers is creating logos. Each of the logos is a polygon. Determine how many different logos were created by these artists.


The user inserts the logos in the following way: First the user inserts a positive integer n greater than or equal to 3. After this integer

the user inserts n pairs of real numbers each corresponding to a vertex of the polygon in order in which the artist has drawn the 

polygon. For example, the top-left blue figure can be given as:


4

-4 4 -2 7 -8 4 -2 1

Two figures should be recognized as the same logo if one can be obtained from the other using translation. Also the same drawing can be 

achieved by starting from a different vertex, or by drawing in a different orientation (clockwise or counter-clockwise).


The user inserts many logos: Each is given by an integer n, followed by n pairs of points. The user finishes the input by providing a 

value n that is ≤2. Your program should print a number that represents the total number of different logos created by the artists.

Example:

Input:

4 

-4 4 -2 7 -8 4 -2 1 

3 

-8 -3 -5 -2 -7 -1 

5 

5 6 6 8 2 8 2 4 6 4 

3 

9 3 7 4 6 2 

4 

-3 -1 3 2 1 -1 3 -4 

0

Output:

3
