<h1>Ex3 - server & client</h1>
We now want to create a server that uses the KNN algorithm we built in order to classify vectors for clients.<br /> 
The clients send a vector with the distance parameter and a K variable and the server clssifies it and returns the<br /> 
classification to the client. the client then prints the server's classification.<br />
if the user enters  a wrong input the client will print it to the screen.<br />
they will both continue to go until the user enters -1, then the clien shuts down.<br />
the server will continue until terminated.<br /><br />

<h2>Code execution:</h2>
We provided a makefile in the project dir (AP1/ex_3). <br/>
In the terminal, just type the following command (while in AP1/ex_3 dir):<br />
<code> make </code><br />
after that you'll get to executable files, for the server and the client.<br />

to activate the server:<br />
<code> server.out <file name> <port number> </code><br />

to activate the client:<br />
<code> client.out <ip number> <port number> </code><br />


<h3> examples of input and output: </h3>
input (in user):<br />
6.9 3.1 4.9 1.5 MAN 20 <br />
output (also in user):<br />
Iris-versicolor<br />

input (in user):<br />
6.9 3.1 4.9 1.5 AEV 20 <br />
output (also in user):<br />
input invalid<br />
