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

The goals of creating this repository are:

  1. Use the open source community as well as professional developers. __Not__ individuals without a professional background in software engineering. They have done enough hard work in bootstrapping this project, its time they received some help from the open source community.
  2. Properly version control the software. You'll notice that there's a folder called `ReleaseNotes`. Its a pity that someone had to document the changes. Its time the open source community eases that pain on scientists with version control.
  3. Use the insights of the open source community to begin refactoring the software. This includes helping generate tests, documenting known issues/bugs, and increasing the simulations performance while also moving away from a dead language (\*cough\* fortran...).

These goals are here to help the scientific community be able to improve their research.
