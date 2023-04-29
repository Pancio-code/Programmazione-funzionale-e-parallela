// =====================================================================
//  px4.h
// =====================================================================

//  Author:         (c) 2019 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Feb 17, 2019
 
//  Last changed:   $Date: 2019/02/17 15:00:07 $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#ifndef __PX4__
#define __PX4__

#include "clut.h"

void px4(unsigned char* in, unsigned char* out, int h, int w, double* td, clut_device* dev);

#endif


// Copyright (C) 2019 Camil Demetrescu
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
