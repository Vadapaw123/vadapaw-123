/*
 * LteMaxCiOptMB.h
 *
 *  Created on: Apr 22, 2014
 *      Author: antonio
 */

#ifndef LTEMAXCIOPTMB_H_
#define LTEMAXCIOPTMB_H_

#include "LteScheduler.h"
#include <string>
#include "AmcPilot.h"

using namespace std;

typedef std::map< MacNodeId,std::vector<BandLimit> > SchedulingDecision;
typedef map<MacNodeId,UsableBands> UsableBandList;

class LteMaxCiOptMB : public virtual LteScheduler
{

    string problemFile_;
    string solutionFile_;


    vector<MacNodeId> ueList_;
    vector<MacCid> cidList_;
    SchedulingDecision schedulingDecision_;

    UsableBandList usableBands_;

    // read the CQIs and queue infos for each user and build an optimization problem
    void generateProblem();

    // call the interactive solver
    void launchProblem();

    // parse the solution
    void readSolution();

    // apply the scheduling decision in the allocator (occupies the Resource blocks)
    void applyScheduling();
public:
    LteMaxCiOptMB();
    virtual ~LteMaxCiOptMB(){};

    virtual void prepareSchedule();

    virtual void commitSchedule();



    // *****************************************************************************************


    void notifyActiveConnection(MacCid cid);

    void removeActiveConnection(MacCid cid);

    void updateSchedulingInfo();

};

#endif /* LTEMAXCIOPTMB_H_ */
