//Change data in this file to alter game rule

#ifndef EASYMOD_CUSTOMIZABLEDATA_H
#define EASYMOD_CUSTOMIZABLEDATA_H

//If the number of troops (non-naval army) reaches AreaTroopLimit, no army can enter that area.
//If the number of navies reaches AreaNavyLimit, no army can enter that area.
//Otherwise having troops and navies in the same area is allowed.
//However, in no case can an area contain more than 4 armies.
const int AreaTroopLimit = 4;
const int AreaNavyLimit = 1;

#endif //EASYMOD_CUSTOMIZABLEDATA_H
