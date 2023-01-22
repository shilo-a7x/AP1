<h1>Ex4 - Parallel Implementation</h1>
In this assignment we implemented a multiple thread implementation of the server.<br /> 
The server has the option to handle multiple clients by using threads. the server sends a menu to<br /> 
each client he is handling and serves each one of them simultaneously. The menu has 6 commants that the <br />
server can preform:<br />
1. Upload the train and the test files to the server. <br />
2. Change the settings of the KNN algorithm(K index and metric).<br />
3. Classify all the vectors in the test file using the classified train file.<br />
4. Print all the classifications of the vectors in the same order as in the test file. <br />
5. Do the same but save the data in a file in a given address.<br />
8. Close the client and exit.<br /><br />

After exiting the server continues to handle the clients that are still online.<br />
The server continues in an endless loop and is always waiting for a client.<br /><br />

<h2>Code execution:</h2>
We provided a makefile in the project dir (AP1/ex_4). <br/>
In the terminal, just type the following command (while in AP1/ex_4 dir):<br />
<code> make </code><br />
after that you'll get to executable files, for the server and the client.<br />

to activate the server:<br />
<code> server.out -file name- -port number- </code><br />

to activate the client:<br />
<code> client.out -ip number- -port number- </code><br />


<h3> examples of input and output: </h3>

output (in user):<br />
Welcome to the KNN Classifier Server. Please choose an option:<br />
1. upload an unclassified csv data file<br />
2. algorithm settings<br />
3. classify data<br />
4. display results<br />
5. download results<br />
8. exit<br />
input (in user):<br />
1<br />
output(in user):<br />
Please upload your local train CSV file. <br />
input (in user):<br />
-path-<br />
output(in user):<br />
Upload complete.
Please upload your local test CSV file. <br />
input (in user):<br />
-path-<br />
output(in user):<br />
Upload complete.<br /><br />

output (in user):<br />
Welcome to the KNN Classifier Server. Please choose an option:<br />
1. upload an unclassified csv data file<br />
2. algorithm settings<br />
3. classify data<br />
4. display results<br />
5. download results<br />
8. exit<br />
input (in user):<br />
3<br />
output(in user):<br />
classifying data complete<br />

output (in user):<br />
Welcome to the KNN Classifier Server. Please choose an option:<br />
1. upload an unclassified csv data file<br />
2. algorithm settings<br />
3. classify data<br />
4. display results<br />
5. download results<br />
8. exit<br />
input (in user):<br />
4<br />
output(in user):<br />
1  Iris-Setosa<br />
2  Iris-Virginica<br />
3  Iris-Versicolor<br />
4  Iris-Setosa<br />
...<br />
Done.<br />

output (in user):<br />
Welcome to the KNN Classifier Server. Please choose an option:<br />
1. upload an unclassified csv data file<br />
2. algorithm settings<br />
3. classify data<br />
4. display results<br />
5. download results<br />
8. exit<br />
input (in user):<br />
5<br />
-path-<br />

output (in user):<br />
Welcome to the KNN Classifier Server. Please choose an option:<br />
1. upload an unclassified csv data file<br />
2. algorithm settings<br />
3. classify data<br />
4. display results<br />
5. download results<br />
8. exit<br />
input (in user):<br />
8<br />

At this point the client will have a the test file classified in the path he gave in command 5.<br /> 
