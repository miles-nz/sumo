/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2019 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    GNEVehicleType.h
/// @author  Pablo Alvarez Lopez
/// @date    Jan 2018
/// @version $Id$
///
// Definition of Vehicle Types in NETEDIT
/****************************************************************************/
#ifndef GNECalibratorVehicleType_h
#define GNECalibratorVehicleType_h


// ===========================================================================
// included modules
// ===========================================================================

#include <utils/vehicle/SUMOVTypeParameter.h>

#include "GNEDemandElement.h"


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class GNEVehicleType
 * vehicleType vehicleType used by GNECalibrators
 */
class GNEVehicleType : public GNEDemandElement, public SUMOVTypeParameter {

public:
    /// @brief constructor
    GNEVehicleType(GNEViewNet* viewNet, const std::string &vTypeID, bool defaultVehicleType);

    /// @brief constructor
    GNEVehicleType(GNEViewNet* viewNet, const SUMOVTypeParameter &vTypeParameter, bool defaultVehicleType);

    /// @brief copy constructor
    GNEVehicleType(GNEViewNet* viewNet, const std::string &vTypeID, GNEVehicleType *vTypeOriginal);

    /// @brief destructor
    ~GNEVehicleType();

    /// @brief get color
    const RGBColor &getColor() const;

    /**@brief writte demand element element into a xml file
     * @param[in] device device in which write parameters of demand element element
     */
    void writeDemandElement(OutputDevice& device) const;

    /// @name Functions related with geometry of element
    /// @{
    /**@brief change the position of the element geometry without saving in undoList
     * @param[in] offset Position used for calculate new position of geometry without updating RTree
     */
    void moveGeometry(const Position& offset);

    /**@brief commit geometry changes in the attributes of an element after use of moveGeometry(...)
     * @param[in] undoList The undoList on which to register changes
     */
    void commitGeometryMoving(GNEUndoList* undoList);

    /// @brief update pre-computed geometry information
    void updateGeometry(bool updateGrid);

    /// @brief Returns position of additional in view
    Position getPositionInView() const;
    /// @}

    /// @name inherited from GUIGlObject
    /// @{
    /**@brief Returns the name of the parent object
     * @return This object's parent id
     */
    std::string getParentName() const;

    /**@brief Draws the object
     * @param[in] s The settings for the current view (may influence drawing)
     * @see GUIGlObject::drawGL
     */
    void drawGL(const GUIVisualizationSettings& s) const;
    /// @}

    /// @brief inherited from GNEAttributeCarrier
    /// @{
    /// @brief select attribute carrier using GUIGlobalSelection
    void selectAttributeCarrier(bool changeFlag = true);

    /// @brief unselect attribute carrier using GUIGlobalSelection
    void unselectAttributeCarrier(bool changeFlag = true);

    /* @brief method for getting the Attribute of an XML key
    * @param[in] key The attribute key
    * @return string with the value associated to key
    */
    std::string getAttribute(SumoXMLAttr key) const;

    /* @brief method for setting the attribute and letting the object perform additional changes
    * @param[in] key The attribute key
    * @param[in] value The new value
    * @param[in] undoList The undoList on which to register changes
    * @param[in] net optionally the GNENet to inform about gui updates
    */
    void setAttribute(SumoXMLAttr key, const std::string& value, GNEUndoList* undoList);

    /* @brief method for setting the attribute and letting the object perform additional changes
    * @param[in] key The attribute key
    * @param[in] value The new value
    * @param[in] undoList The undoList on which to register changes
    */
    bool isValid(SumoXMLAttr key, const std::string& value);

    /* @brief method for check if certain attribute is set (used by ACs with disjoint attributes)
     * @param[in] key The attribute key
     * @return true if it's set, false in other case
     */
    bool isDisjointAttributeSet(const SumoXMLAttr attr) const;

    /// @brief get PopPup ID (Used in AC Hierarchy)
    std::string getPopUpID() const;

    /// @brief get Hierarchy Name (Used in AC Hierarchy)
    std::string getHierarchyName() const;
    /// @}

protected:
    /// @brief flag to check if this GNEVehicleType is a default vehicle Type (For Vehicles, Pedestrians...)
    bool myDefaultVehicleType;

    /// @brief flag to check if this default GNEVehicleType was modified
    bool myDefaultVehicleTypeModified;

private:
    /// @brief method for setting the attribute and nothing else
    void setAttribute(SumoXMLAttr key, const std::string& value);

    /// @brief Invalidated copy constructor.
    GNEVehicleType(GNEVehicleType*) = delete;

    /// @brief Invalidated assignment operator
    GNEVehicleType* operator=(GNEVehicleType*) = delete;
};

#endif
/****************************************************************************/
