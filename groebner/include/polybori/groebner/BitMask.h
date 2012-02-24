// -*- c++ -*-
//*****************************************************************************
/** @file BitMask.h 
 *
 * @author Alexander Dreyer
 * @date 2012-02-23
 *
 * This file includes the definition of the class @c BitMask.
 *
 * @par Copyright:
 *   (c) 2012 by The PolyBoRi Team
 *
**/
//*****************************************************************************

#ifndef polybori_groebner_BitMask_h_
#define polybori_groebner_BitMask_h_

// include basic definitions
#include "groebner_defs.h"

BEGIN_NAMESPACE_PBORIGB

/** @class BitMask
 * @brief This class defines a bit mask and related operations.
 *
 **/

template <unsigned NBits>
class BitMask;

template <>
class BitMask<0> {
public:
  static const unsigned nbits = 0;
  static const unsigned long mask = 0;

  unsigned long low(const unsigned long& value) const { return 0; }
  const unsigned long& high(const unsigned long& value) const { return value; }
  const unsigned long& shift(const unsigned long& value) const { return value; }
};

template <unsigned NBits>
class BitMask {
public:
  static const unsigned nbits = NBits;
  static const unsigned long mask = (BitMask<nbits-1>::mask << 1) + 1;

  unsigned long low(const unsigned long& value) const {
    return value & mask;
  }
  unsigned long high(const unsigned long& value) const {
    return value >> NBits;
  }
  unsigned long shift(const unsigned long& value) const {
    return value << NBits;
  }
};



END_NAMESPACE_PBORIGB

#endif /* polybori_groebner_BitMask_h_ */
