/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 2001, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** Reliability module developed by:                                   **
**   Terje Haukaas (haukaas@ce.berkeley.edu)                          **
**   Armen Der Kiureghian (adk@ce.berkeley.edu)                       **
**                                                                    **
** ****************************************************************** */
                                                                        
// $Revision: 1.3 $
// $Date: 2001-08-20 00:37:26 $
// $Source: /usr/local/cvs/OpenSees/SRC/reliability/analysis/stepSize/ArmijoRule.h,v $


//
// Written by Terje Haukaas (haukaas@ce.berkeley.edu) during Spring 2000
// Revised: haukaas 06/00 (core code)
//			haukaas 06/01 (made part of official OpenSees)
//			haukaas 08/19/01 (modifications for Release 1.2 of OpenSees)
//

#ifndef ArmijoRule_h
#define ArmijoRule_h

#include <StepSizeRule.h>
#include <GFunEvaluator.h>
#include <XuTransformation.h>

class ArmijoRule : public StepSizeRule
{

public:
	ArmijoRule(GFunEvaluator *passedGFunEvaluator, 
		XuTransformation *passedXuTransformation,
		int passedMaxNumReductions,
		double passedFirstTrialStep);
	~ArmijoRule();

	int		computeStepSize(Vector u, Vector grad_G, double G, Vector d);
	double	getStepSize();
	double getGFunValue();

protected:

private:
	double stepSize;
	GFunEvaluator *theGFunEvaluator;
	XuTransformation *theXuTransformation;
	double gFunValue;
	int maxNumReductions;
	double firstTrialStep;

};

#endif
