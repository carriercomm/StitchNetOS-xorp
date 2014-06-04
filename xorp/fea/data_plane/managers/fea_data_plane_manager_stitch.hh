// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, Version 2, June
// 1991 as published by the Free Software Foundation. Redistribution
// and/or modification of this program under the terms of any other
// version of the GNU General Public License is not permitted.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
// see the GNU General Public License, Version 2, a copy of which can be
// found in the XORP LICENSE.gpl file.
// 
#ifndef __FEA_DATA_PLANE_MANAGERS_FEA_DATA_PLANE_MANAGER_STITCH_HH__
#define __FEA_DATA_PLANE_MANAGERS_FEA_DATA_PLANE_MANAGER_STITCH_HH__
#include "libxipc/xrl_std_router.hh"
#include "fea_stitch_xif.hh"

class FeaDataPlaneManagerStitch {
    public:
        /**
         * Constructor.
         * @param finder the XRL router for XORP. 
         */
        FeaDataPlaneManagerStitch(XrlStdRouter &finder);
        void print_lc_message(string& lc_message);
    private:
        XrlFeaStitchV0p1Client &stitch_lc_fea; //XRL interface to stitch LC FEA
        
};
#endif //STITCH

