#ifndef _CAL_DATA_OUTPUT_PERCAP_H_
#define _CAL_DATA_OUTPUT_PERCAP_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 * 
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 * 
 * All rights to use the Software are granted on condition that such
 * rights are forfeited if User fails to comply with the terms of
 * this Agreement.
 * 
 * User agrees to identify, defend and hold harmless BATTELLE,
 * its officers, agents and employees from all liability involving
 * the violation of such Export Laws, either directly or indirectly,
 * by User.
 */


/*! 
* \file cal_data_output_percap.h
* \ingroup Objects
* \brief The CalDataOutputPercap class header file.
* \author James Blackwood
*/

#include <xercesc/dom/DOMNode.hpp>
#include "technologies/include/ical_data.h"

class CalDataOutputPercap : public ICalData {
public:
    CalDataOutputPercap();
    virtual CalDataOutputPercap* clone() const;

    virtual void XMLParse( const xercesc::DOMNode* aNode );
    virtual void toInputXML( std::ostream& aOut, Tabs* aTabs ) const;
    virtual void toDebugXML( std::ostream& aOut, Tabs* aTabs ) const;
    static const std::string& getXMLNameStatic();

    virtual void initCalc( const Demographic* aDemographics,
                           const int aPeriod );
    
    virtual void completeInit();

    virtual double getCalOutput();

private:
    //! Calibrated output on a per capita basis.
    double mCalOutputPercapValue;

    /*! \brief Cached population for the period of the calibration value.
    * \todo If population becomes dynamic this will have to change.
    */
    double mPopulation;
};

#endif // _CAL_DATA_OUTPUT_PERCAP_H_
