//============================================================================
//    Apothesis: A kinetic Monte Calro (KMC) code for deposotion processes.
//    Copyright (C) 2019  Nikolaos (Nikos) Cheimarios
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//============================================================================

#ifndef SITE_H
#define SITE_H

#include <string>
#include <vector>
#include <list>
#include <map>

#include "process.h"

using namespace std;
using namespace MicroProcesses;

/**  The site is where a process will be performed. The lattice is
 * a series of sites put together in space with certain symmetry. */

namespace SurfaceTiles
{

// Forward decleration - Not implemented yet
class Element;

class Site
{
public:

    /// Contructor.
    Site();

    /// Destructor.
    virtual ~Site();

    /// The position of the neighbour.
    enum NeighPoisition{
                         WEST,
                         WEST_UP,
                         WEST_DOWN,
                         EAST,
                         EAST_UP,
                         EAST_DOWN,
                         NORTH,
                         SOUTH
                       };

    /// The site that is activated if the neighbours are all occupied.
    enum ActivationSite{
                         ACTV_WEST,
                         ACTV_WEST_UP,
                         ACTV_WEST_DOWN,
                         ACTV_EAST,
                         ACTV_EAST_UP,
                         ACTV_EAST_DOWN,
                         ACTV_NORTH,
                         ACTV_SOUTH
                       };

    /// Set the height of the particular site.
    void setHeight( int );

    /// Get the height of the particular site.
    int getHeight();

    /// Set the neigbours.
    void setNeigh( Site*);

    /// Get the neigbours at the same level.
    vector< Site* > getNeighs();

    /// Check if this site is activeand can absorb.
    bool isActive();

    /// Set an ID for this site.
    void setID( int );

    /// Get the ID of this lattice.
    int getID();

    /// Set the number of the neighbours according to the height of its neighbour sites
    void setNeighboursNum( int );

    /// Returns the number of the neighbours according to the height of its neighbour sites.
    int getNeighboursNum();

    /// Set the neihbour position for this site.
    void setNeighPosition( Site*, NeighPoisition  );

    /// Get the neihbour position for this site.
    Site* getNeighPosition( NeighPoisition );

    /// Stores the sites that are activated.
    void storeActivationSite( Site* s, ActivationSite as);

    /// Returns the sites that are activated.
    Site* getActivationSite( ActivationSite as);

    /// This will holds all the elements that can interact with the surfaces.
    /// Important when we talk about surface reactions.
    /// Element class has not implement yet for that we use forward decleration.
    void setElements( Element* );

    /// Add a processes in the list of processes that this site can participate in.
    void addProcess( Process* );

    /// Remove a processes from the list of processes that this site can participate in.
    void removeProcess( Process* );

protected:
    /// The ID of the site.
    int m_iID;

    /// The indexes coming from the vector.
    int m_iIIndex;
    int m_iJIndex;

    /// The height in the particular position.
    int m_iHeight;

    /// The neighbours at the same level - We do not need this because we have the map (see below).
    vector< Site*> m_vNeigh;

    /// Holds the number of the neighbours of the particular site according to each height/
    int m_iNumNeighs;

    /// A map that holds the neihbour sites according to their orientation.
    map< NeighPoisition, Site*> m_mapNeigh;

    /// A map that hold the sites that this site can activate if it has all the its neighbours occupied.
    map< ActivationSite, Site* > m_mapAct;

    /// To check if a site is occupied or not.
    bool m_bIsOccupied;

    /// The list of processes that this site can participate in.
    list< Process* > m_lProcs;
};

}

#endif
