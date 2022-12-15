<h1>Ex2 - KNN</h1>
The KNN algorithm is an algorithm that gets a DB of vectors and tags, and an untagged vector.<br />
By checking the distance of the vector from the vectors and finding the K closest vectors in the DB,<br />
the algorithm tags the untagged vector with the most common tag among the K closest vector.<br />
This technique is used by machine-learning algorithm and other algorithms.<br />

<h3>Implementation</h3>
First after compiling, the user enters a command that contains 4 parameters: "a.out", "K", "file_name.csv" and a string. <br />
In order to implement the algorithm we first constucted a 'Reader' class that reads the data from a given ".csv" file.<br />
The 'Reader' extracts the vectors and the tags from the ".csv" file and puts them in a vector of 'Classifiable's. <br />
A 'Classifiable' is a class that contains a vector and a tag as members.<br />
If one of the above cases is the case, the program prints an error massage and terminates itself.<br />
On the other case when the vectors are valid, the program calculates 5 distance methods between the two vectors.<br />
The distance functions are Euclidean, Manhattan, Chebyshev, Canberra and Minkowsky distances.<br />
After each calculation the program prints the result. If the result is an int the function will print the number with one digit after the point.<br />
If not, it will print the double with 16 digits after the point.<br />
Note that in Minkosky distance the p parameter we are using is 2, making it identical to the Euclidean distance.<br />
If needed, the p parameter in the Minkosky distance can be changed within the call to the function in the fourth parameter.<br />


<h2>Code execution:</h2>
In the terminal, just type the following command (while in ex_2 dir):<br />
<code> make </code><br />
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

