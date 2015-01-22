# Geant

Geant is a toolkit for both full and fast Monte Carlo simulation of detectors in High Energy Physics. It is also designed to take into account the requirements of space and cosmic ray applications, nuclear, heavy ion and radiation computations, and medical applications.

---

This repository is a copy from [Cern](http://geant4.web.cern.ch/geant4/support/userdocuments.shtml).
When downloading the source, there was no explicit version control software being used.
To combat this, the source was downloaded, initialized into a Git repo, and then pushed up to this Github repo for safer storage.

You will notice that they call Geant "Geant4".
4 is simply a major version and inside of their source code, they use the minor and patch levels.
They also have a patch level for a patch level as well.
This does not follow semantic version control, but thanks to tags, you can now see exactly what changes from a patch's patch to a minor version bump.

The goals for creating this repository are:

  1. To use the talent of the open source community.
  2. To properly version control the software.
  3. To help refactor the software.

These goals are here to aid the scientific community and allow scientists to spend more time doing what they love: science.

## Documentation and Guides

- [User Documentation](http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/IntroductionToGeant4/fo/BookIntroToGeant4.pdf):

  The following document gives you a more complete introduction to Geant.

- [Installation Guide](http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/InstallationGuide/fo/BookInstalGuide.pdf):

  We strongly recommend installing the Geant toolkit under your computing environment before starting to read the following user's guides.
  You will gain much more from the user guides if you can check things out with a working version while you are reading them.
  This installation guide instructs you in the setting up of the Geant toolkit on your computer.

- [For Application Developers](http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/ForApplicationDeveloper/fo/BookForAppliDev.pdf):

  If you are new to Geant, we recommend that you read this document first.
  The first part of the document provides a step-by-step tutorial in the use of Geant; this is for a novice user.
  The second part describes the usage of the toolkit for practical applications, with a lot of example codes.
  After reading this part, you will be able to start to write a detector simulation program for most applications/experiments.
  The third part is for those who want to make more advanced use of the toolkit.

- [For Toolkit Developers](http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/ForToolkitDeveloper/fo/BookForToolDev.pdf):

  This document is for those who want to contribute to the extension of the functionality to the Geant toolkit - for example, to add a new physics process, to add a new particle, etc.
  It starts with the explanation of the object-oriented analysis and design performed by the original toolkit developers.
  Understanding this design is mandatory for a new toolkit developer.
  Then guidance on how to extend the functionality of each class category is given.

- [Physics Reference Manual](http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/PhysicsReferenceManual/fo/PhysicsReferenceManual.pdf):

  This is a detailed description of the physics interactions provided in the Geant toolkit.
  The theory, model or parameterization of each interaction is discussed.
  The Physics Reference Manual contains gaps in documentation which correspond to un-implemented interactions.
  There are also a few sections in which documentation is slight.
  Improvements in these sections are expected by the next release.
