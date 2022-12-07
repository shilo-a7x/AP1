<h1>Ex2_part1</h1>
The first part was practicing working with git commands and branches.<br />
A member of the team opened a branch, and commited and pushed two files from it.<br />
After that both team members were requiered to do the same but to merge in a three way merge.<br />
The tasks and the files of the exersize can be seen in the exersize's folder and in the branch history.<br />

<h1>Ex1_part2</h1>
The program gets two vectors from the user as a string input.<br />
Then it checks two things. The first is whether the vector's parameters contain valid double numbers only <br />
and the second is whether the length of the two vectors is identical.<br />
If one of the above cases is the case, the program prints an error massage and terminates itself.<br />
On the other case when the vectors are valid, the program calculates 5 distance methods between the two vectors.<br />
The distance functions are Euclidean, Manhattan, Chebyshev, Canberra and Minkowsky distances.<br />
After each calculation the program prints the result. If the result is an int the function will print the number with one digit after the point.<br />
If not, it will print the double with 16 digits after the point.<br />
Note that in Minkosky distance the p parameter we are using is 2, making it identical to the Euclidean distance.<br />
If needed, the p parameter in the Minkosky distance can be changed within the call to the function in the fourth parameter.<br />


<h2>Code execution command:</h2>
In the terminal, type the following line (while in ex_1/part_2/ dir):<br />
<code>  g++ -std=c++11 main.cpp vecDistances.cpp -o a.out </code><br />
And then type:<br />
<code> ./a.out </code><br />

<h3> example of input and output: </h3>
input:<br />
1 2 3 <br />
3 2 1 <br />
output:<br />
2.8284271247461903<br />
4.0<br />
2.0<br />
1.0<br />
2.8284271247461903

