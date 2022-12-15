<h1>Ex2 - KNN</h1>
The KNN algorithm is an algorithm that gets a DB of vectors and tags, and an untagged vector.<br />
By checking the distance of the vector from the vectors and finding the K closest vectors in the DB,<br />
the algorithm tags the untagged vector with the most common tag among the K closest vector.<br />
This technique is used by machine-learning algorithm and other algorithms.<br />

<h3>Implementation</h3>
First after compiling, the user enters a command that contains 4 parameters: "a.out", "K", "file_name.csv" and a string. <br />
Then, the user enters n coordinates, when n signifies the number of parameters is each of the vectors in the DB.<br />
Any wrong input in these two stages is handled accordingly.<br />
In order to implement the KNN algorithm,the program uses a 'Reader' class that reads the data from a given ".csv" file.<br />
The 'Reader' extracts the vectors and the tags from the ".csv" file and puts them in a vector of 'Classifiable's. <br />
A 'Classifiable' is a class that contains a vector and a tag as members. It also has a distance member (a double).<br />
After that, the program calls the 'KNN' class that runs the algorithm itself.<br />
At first, 'KNN' uses an 'Initializer', that sets the distance of each 'Classifiable'.<br />
It sets it with a 'Distance' class which id defined by the string given in the cmd.<br />
If the string is "MAN" - uses manhattan distance.<br />
If the string is "AUC" - uses euclidean distance.<br />
If the string is "CHB" - uses chebyshev distance.<br />
If the string is "CAN" - uses canberra distance.<br />
If the string is "MIN" - uses minkowski distance.<br />
After initializing all the vector distances, the algorithm finds the K'th closest vector by a quick-select algorithm,<br />
and takes all the vectors that their distance from the given vector is equal or smaller then the K'th closest vector.<br />
After getting the K closest vectors, it finds the most common tag among these vectors and returns it as the answer.<br />
the whole proccess is running in a never-ending loop that always waits for a new vector input.<br />


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

