#include <mainwindow.h>
#include <globals.h>


void MainWindow::testFunc(){
    testmodes testmode = initPatternMultiples;
    // TODO popup to select testmode
    if(testmode==initPatternMultiples){
        testInitPatternsMultiples();
    }
}
// test that original pattern doesn't have more multiples than supposed to
void MainWindow::testInitPatternsMultiples(){
    // count up to maxMoves fails
    int fails = 0;
    int* failedPatterns = new int[globals.maxNumSlots*globals.maxMoves];
    memset(failedPatterns, 0, globals.maxNumSlots*globals.maxMoves*sizeof(int));
    for(int numC=globals.minNumColors; numC<=globals.maxNumColors; numC++){
        for(int numS=globals.minNumSlots; numS<=globals.maxNumSlots; numS++){
            for(int numM=1; numM<=numS; numM++){
                numMultiples = numM;
                numSlots = numS;
                numColors = numC;
                if( numColors*numMultiples < numSlots ) // checkNumberSanity
                    continue;
                for(int i=0; i<globals.numTestInits; i++){
                    newGame();
                    if(Game.countMaxOccurence()>numMultiples){
                        for(int i=0; i<numSlots; i++)failedPatterns[numSlots*fails+i] = Game.originalPattern[i];
                        fails++;
                    }
                    if(fails >= globals.maxMoves) break;
                }
            }
        }
    }

    // plot the fails
    if (fails==0) cout("no fails");
    else
        for(int i=0; i<fails; i++)
            updateAnyColorbar("plate", i, failedPatterns+numSlots*fails);
}




