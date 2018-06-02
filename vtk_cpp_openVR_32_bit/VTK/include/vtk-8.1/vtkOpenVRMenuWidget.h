/*=========================================================================

Program:   Visualization Toolkit
Module:    vtkOpenVRMenuWidget.h

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
* @class   vtkOpenVRMenuWidget
* @brief   3D widget to display a menu in VR
*
*/

#ifndef vtkOpenVRMenuWidget_h
#define vtkOpenVRMenuWidget_h

#include "vtkRenderingOpenVRModule.h" // For export macro
#include "vtkAbstractWidget.h"

class vtkOpenVRMenuRepresentation;
class vtkPropMap;
class vtkProp;

class VTKRENDERINGOPENVR_EXPORT vtkOpenVRMenuWidget : public vtkAbstractWidget
{
public:
  /**
  * Instantiate the object.
  */
  static vtkOpenVRMenuWidget *New();

  //@{
  /**
  * Standard vtkObject methods
  */
  vtkTypeMacro(vtkOpenVRMenuWidget, vtkAbstractWidget);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;
  //@}

  /**
  * Specify an instance of vtkWidgetRepresentation used to represent this
  * widget in the scene. Note that the representation is a subclass of vtkProp
  * so it can be added to the renderer independent of the widget.
  */
  void SetRepresentation(vtkOpenVRMenuRepresentation *rep);

  /**
  * Create the default widget representation if one is not set.
  */
  void CreateDefaultRepresentation() VTK_OVERRIDE;

  //@{
  /**
   * Get the widget state.
   */
  vtkGetMacro( WidgetState, int );
  //@}

  // Manage the state of the widget
  enum _WidgetState {Start=0,Active};


  /**
  * Create a tooltip associated to a prop.
  * Note that if the tooltip is already assigned to this prop,
  * its text will be replaced
  */
  void AddTooltip(vtkProp *prop, vtkStdString* str);
  void AddTooltip(vtkProp *prop, const char* str);

protected:
  vtkOpenVRMenuWidget();
  ~vtkOpenVRMenuWidget() VTK_OVERRIDE;

  int WidgetState;

  // These are the callbacks for this widget
  static void StartMenuAction(vtkAbstractWidget*);
  static void SelectMenuAction(vtkAbstractWidget*);
  static void MoveAction(vtkAbstractWidget*);

  /**
  * Update callback to check for the hovered prop
  */
  static void Update(vtkAbstractWidget*);

  vtkPropMap *PropMap; //PIMPL'd map of (vtkProp,char*)

private:
  vtkOpenVRMenuWidget(const vtkOpenVRMenuWidget&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOpenVRMenuWidget&)VTK_DELETE_FUNCTION;

};
#endif
