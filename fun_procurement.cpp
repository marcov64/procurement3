#include "fun_head.h"

MODELBEGIN


EQUATION("X")
/*
Comment*/

RESULT(norm(100,1) )



EQUATION("EstimatedCost")
/*
Estimated costs, depending on the production and estimation skills
*/

v[0]=V("EstimationSkill");
v[5]=V("Complexity");//complexity of the work
v[1]=norm(0,v[0]*v[5]);//estimation error

WRITES(p,"norm",v[1]);
v[2]=V("Cost"); //real normal cost
v[3]=V("Skill");//objective production skill

v[4]=v[2]*v[3]*(1+v[1]);
RESULT(v[4] )


EQUATION("EstimatedRebate")
/*
Rebate offered by the firm on the basis of its estimation of the real costs
*/

v[1]=V("EstimatedCost");
v[0]=V("Cost");
v[2]=1-v[1]/v[0];

RESULT(v[2])

EQUATION("Rebate")
/*
Discount over announced cost
Computed as the estimated rebate times the opportunistic discount.
*/

v[0]=V("EstimatedRebate");
v[1]=V("OpportunisticRebate");
v[2]=v[1]+v[0];
RESULT(v[0]+v[1] )



EQUATION("ActualCost")
/*
Actual final cost, due to firms' skill and random risk
*/

v[0]=V("Risk");//degree of risk of the project
v[1]=V("Cost"); //theoretical cost

v[2]=v[1]*(1+norm(0,v[0]));

v[3]=V("Skill");

v[4]=v[3]*v[2];
if(v[4]<0.01)
 v[4]=0.01;
RESULT(v[4] )


EQUATION("Select")
/*
Choose one firm among the bidding ones
*/

v[3]=V("aRebate");
v[4]=V("aTrust");
v[20]=v[21]=0;
CYCLE(cur, "Firm")
 {
  v[0]=VS(cur,"Rebate");
  v[1]=VS(cur,"Trust");
  WRITES(cur,"ttag",(double)t);
  v[2]=pow(v[1],v[4])*pow(v[0],v[3]);
  WRITES(cur,"app",v[2]);
  v[20]+=VS(cur,"Trust");
  v[21]++;
 }

v[22]=v[20]/v[21];
cur=RNDDRAW("Firm","app");
INCRS(cur,"Win",1);
v[5]=VS(cur,"ActualCost");
v[6]=V("bTrust");
v[7]=VS(cur,"Trust");
v[9]=V("Cost");
v[10]=v[9]/v[5];
v[8]=v[6]*v[7]+v[10]*(1-v[6]);
WRITES(cur,"Trust",v[8]);

v[11]=(double)t;

v[12]=V("AvActualCost")*(v[11]-1)/(v[11]) +  v[5]/v[11];
WRITE("AvActualCost",v[12]);

v[13]=VS(cur,"Skill");
v[14]=V("AvSkill")*(v[11]-1)/(v[11]) +  v[13]/v[11];
WRITE("AvSkill",v[14]);

v[15]=VS(cur,"EstimationSkill");
v[16]=V("AvEstSkill")*(v[11]-1)/(v[11]) +  v[15]/v[11];
WRITE("AvEstSkill",v[16]);

v[23]=V("AvAvTrust")*(v[11]-1)/(v[11]) +  v[22]/v[11];
WRITE("AvAvTrust",v[23]);

RESULT(VS(cur,"idFirm") )

MODELEND




void close_sim(void)
{

}


