#include "CLI.h"
#include "ChangeSetsCommand.h"
#include "ClassifyCommand.h"
#include "DefaultIO.h"
#include "DisplayStringCommand.h"
#include "DownloadResultsCommand.h"
#include "KNN.h"
#include "KnnData.h"
#include "StandardIO.h"
#include "UploadCommand.h"

int main() {
    StandardIO sio;
    KNN knn("AUC", 5);
    KnnData knndata(&knn);
    vector<Command *> cvec;
    UploadCommand uc(&sio, &knndata);
    ChangeSetsCommand csc(&sio, &knndata);
    ClassifyCommand cc(&sio, &knndata);
    DisplayStringCommand dsc(&sio, &knndata);
    DownloadResultsCommand drsc(&sio, &knndata);
    cvec.push_back(&uc);
    cvec.push_back(&csc);
    cvec.push_back(&cc);
    cvec.push_back(&dsc);
    cvec.push_back(&drsc);
    CLI cli(&sio, cvec);
    cli.run();
}