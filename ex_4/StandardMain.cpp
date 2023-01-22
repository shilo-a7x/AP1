#include "StandardIO.h"
#include "DefaultIO.h"
#include "CLI.h"
#include "KNN.h"
#include "KnnData.h"
#include "UploadCommand.h"
#include "ClassifyCommand.h"
#include "ChangeSetsCommand.h"
#include "DisplayStringCommand.h"
#include "DownloadResultsCommand.h"

int main()
{
    StandardIO sio();
    KNN knn("AUC", 5);
    KnnData knndata(&knn);
    vector<Command> cvec;
    cvec.push_back(UploadCommand((DefaultIO*)&sio, &knndata));
    cvec.push_back(ChangeSetsCommand((DefaultIO*)&sio, &knndata));
    cvec.push_back(ClassifyCommand((DefaultIO*)&sio, &knndata));
    cvec.push_back(DisplayStringCommand((DefaultIO*)&sio, &knndata));
    cvec.push_back(DownloadResultsCommand((DefaultIO*)&sio, &knndata));
    CLI cli((DefaultIO*)&sio, cvec);  
    cli.run();  
}