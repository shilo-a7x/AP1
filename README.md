<h1>Ex1_part1</h1>

<h1>Ex1_part2</h1>
The code gets as a user input 2 vectors with element data type of double.<br />
The size of the vectors are set by the user input, and can be set to any size (within double range).<br />
If the user enters different size vectors, since mathamaticly it isnt a possible case, the code returns a error message.<br />
If the users input contains non numbers, the error message - "error - nonum inserted" will appear and the code will stop.<br/>
Then the code calls 5 different disatance functions, each calculate the distance according to a different method and prints each result in a new line.<br />
The 4th function divides by 0 therfore if the input is 0 it will return 'nan'<br/>
The 5th function (Minkowski distance) the calculation is calculated for order p, the code default is p=2, by inserting a 3rd int argument the function will calculated for the given p.<br />

<h2>To execute the code we need to run the following commands:</h2>
<code>  g++ -std=c++11 main.cpp vecDistances.cpp -o a.out </code><br />
then:<br />
<code> ./a.out </code><br />

<h3> example: </h3>
in the terminal insert vector elements by row.<br />
input:<br />
1 2 3 (vector 1)<br />
3 2 1 (vector 2)<br />
output:<br />
2.8284<br />
4.0000<br />
2.0000<br />
1.0000<br />
2.8284<br />
