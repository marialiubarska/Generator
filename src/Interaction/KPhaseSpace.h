//____________________________________________________________________________
/*!

\class    genie::KPhaseSpace

\brief    Kinematical phase space 

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          STFC, Rutherford Appleton Laboratory

\created  May 06, 2004

\cpright  Copyright (c) 2003-2009, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _KINEMATIC_PHASE_SPACE_H_
#define _KINEMATIC_PHASE_SPACE_H_

#include <cassert>

#include <TObject.h>

#include "Conventions/KineVar.h"
//#include "Interaction/KPhaseSpaceCut.h"
#include "Utils/Range1.h"

namespace genie {

class Interaction;

class KPhaseSpace : public TObject {

public:
  KPhaseSpace (void);
  KPhaseSpace (const Interaction * in);
 ~KPhaseSpace (void);

  void UseInteraction(const Interaction * in);

  //! Energy threshold
  double Threshold(void) const;

  //! Checks whether the interaction is above the energy threshold
  bool IsAboveThreshold(void) const;

  //! Check whether the current kinematics is in the allowed phase space
  bool IsAllowed (void) const;

  //! Return the kinematical variable limits
  Range1D_t  Limits  (KineVar_t kvar) const;
  double     Minimum (KineVar_t kvar) const;
  double     Maximum (KineVar_t kvar) const;

  Range1D_t  WLim    (void) const;  ///< W  limits
  Range1D_t  Q2Lim_W (void) const;  ///< Q2 limits @ fixed W
  Range1D_t  q2Lim_W (void) const;  ///< q2 limits @ fixed W
  Range1D_t  Q2Lim   (void) const;  ///< Q2 limits
  Range1D_t  q2Lim   (void) const;  ///< q2 limits
  Range1D_t  XLim    (void) const;  ///< x  limits
  Range1D_t  YLim    (void) const;  ///< y  limits
  Range1D_t  YLim_X  (void) const;  ///< y  limits @ fixed x

private:

  void Init(void);

  const Interaction * fInteraction;

ClassDef(KPhaseSpace,1)
};

}      // genie namespace
#endif // _KINE_PHASE_SPACE_H_

