//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// Authors: S. Guatelli , M. G. Pia, INFN Genova and F. Ambroglini INFN Perugia, Italy
// 
// Based on code developed by the undergraduate student G. Guerrieri 
// Note: this is a preliminary beta-version of the code; an improved 
// version will be distributed in the next Geant4 public release, compliant
// with the design in a forthcoming publication, and subject to a 
// design and code review.
//
#include "G4MIRDLeftScapula.hh"

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
#include "G4Cons.hh"
#include "G4VisAttributes.hh"
#include "G4HumanPhantomMaterial.hh"
#include "G4EllipticalTube.hh"
#include "G4ThreeVector.hh"
#include "G4VPhysicalVolume.hh"
#include "G4RotationMatrix.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SubtractionSolid.hh"
#include "G4HumanPhantomColour.hh"
#include "G4Box.hh"

G4MIRDLeftScapula::G4MIRDLeftScapula()
{
}

G4MIRDLeftScapula::~G4MIRDLeftScapula()
{
}

G4VPhysicalVolume* G4MIRDLeftScapula::Construct(const G4String& volumeName, G4VPhysicalVolume* mother, 
						const G4String& colourName, G4bool wireFrame,G4bool)
{
  
  G4cout<<"Construct "<<volumeName<<" with mother volume "<<mother->GetName()<<G4endl;

  G4HumanPhantomMaterial* material = new G4HumanPhantomMaterial();
  G4Material* skeleton = material -> GetMaterial("skeleton");
 
  G4double ax_in = 17.* cm;
  G4double by_in = 9.8* cm;
  G4double ax_out = 19.*cm;
  G4double by_out = 9.8*cm;
  G4double dz= 16.4* cm;


  G4EllipticalTube* inner_scapula = new G4EllipticalTube("ScapulaIn", ax_in, by_in, (dz+ 1.*cm)/2);
  G4EllipticalTube* outer_scapula = new G4EllipticalTube("ScapulaOut", ax_out, by_out, dz/2);
  
 
  

  G4Box* subtraction = new G4Box("subtraction",ax_out, ax_out, ax_out);

  G4double xx = ax_out * 0.242 ; //(sin 14deg)
  G4double yy  = - ax_out * 0.97; // (cos 14 deg)
						   
  G4RotationMatrix* rm = new G4RotationMatrix();
  rm -> rotateZ(-14.* degree);

 

  G4SubtractionSolid* scapula_first =  new G4SubtractionSolid("Scapula_first",
							      outer_scapula,
							      subtraction,
							      rm, 
							      G4ThreeVector(xx, yy, 0. *cm));

  G4double xx2 = -ax_out * 0.62470 ; //(cos 51.34deg)
  G4double yy2  = ax_out * 0.78087; // (sin 51.34 deg)
						   
  G4RotationMatrix* rm2 = new G4RotationMatrix();
  rm2 -> rotateZ(-38.6598* degree);


  G4SubtractionSolid* scapula_bone =  new G4SubtractionSolid("Scapula",
							     scapula_first,
							     subtraction,
							     rm2, 
							     G4ThreeVector(xx2, yy2, 0. *cm));

  G4SubtractionSolid* scapula =  new G4SubtractionSolid("Scapula",
							scapula_bone,
							inner_scapula);

  G4LogicalVolume* logicLeftScapula = new G4LogicalVolume(scapula,
							  skeleton,
							  "logical" + volumeName,
							  0, 0, 0);

  G4VPhysicalVolume* physLeftScapula = new G4PVPlacement(0,
							 G4ThreeVector(0. * cm, 0. * cm, 24.1 *cm),
							 "physicalLeftScapula",
							 logicLeftScapula,
							 mother,
							 false,
							 0, true);

  // Visualization Attributes
  //G4VisAttributes* LeftScapulaVisAtt = new G4VisAttributes(G4Colour(0.94,0.5,0.5));
  G4HumanPhantomColour* colourPointer = new G4HumanPhantomColour();
  G4Colour colour = colourPointer -> GetColour(colourName);
  G4VisAttributes* LeftScapulaVisAtt = new G4VisAttributes(colour);
  LeftScapulaVisAtt->SetForceSolid(wireFrame);
  logicLeftScapula->SetVisAttributes(LeftScapulaVisAtt);

  G4cout << "LeftScapula created !!!!!!" << G4endl;

  // Testing LeftScapula Volume
  G4double LeftScapulaVol = logicLeftScapula->GetSolid()->GetCubicVolume();
  G4cout << "Volume of LeftScapula = " << LeftScapulaVol/cm3 << " cm^3" << G4endl;
  
  // Testing LeftScapula Material
  G4String LeftScapulaMat = logicLeftScapula->GetMaterial()->GetName();
  G4cout << "Material of LeftScapula = " << LeftScapulaMat << G4endl;
  
  // Testing Density
  G4double LeftScapulaDensity = logicLeftScapula->GetMaterial()->GetDensity();
  G4cout << "Density of Material = " << LeftScapulaDensity*cm3/g << " g/cm^3" << G4endl;

  // Testing Mass
  G4double LeftScapulaMass = (LeftScapulaVol)*LeftScapulaDensity;
  G4cout << "Mass of LeftScapula = " << LeftScapulaMass/gram << " g" << G4endl;

  
  return physLeftScapula;
}