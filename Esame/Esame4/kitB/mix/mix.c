// =====================================================================
//  mix.c
// =====================================================================

//  Author:         (c) 2018 --
//  License:        See the end of this file for license information
//  Created:        Jan 30, 2018

//  Last changed:   $Date: 2018/01/30 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include "mix.h"


// ---------------------------------------------------------------------
// mix
// ---------------------------------------------------------------------
// data-parallel GPU version

void mix(unsigned char*  in1, int  w1, int  h1,
         unsigned char*  in2, int  w2, int  h2,
         unsigned char** out, int* ow, int* oh,
         clut_device* dev, double* td) {


    // scrivere la soluzione qui...
}


// Copyright (C) 2018 --

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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
// USA
