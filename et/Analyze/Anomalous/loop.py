#!/usr/bin/env python
import ROOT
from ROOT import *
import re
from array import array

islog=1
unrollSV=1

file=ROOT.TFile("control.root","r")
file1=ROOT.TFile("control_out.root","recreate")

file1.mkdir("OS_control")

file.cd()
dirList = gDirectory.GetListOfKeys()
for k1 in dirList:
      name=k1.GetName()
      if "OS_control" in name:
         h1 = k1.ReadObj()
	 h1.cd()
	 print "will now look into ",name
	 dirList2 = gDirectory.GetListOfKeys()

	 for k2 in dirList2:
#	     print k2.GetName() 
	     if "hmela" in k2.GetName() :
      	         print  k1.GetName(), k2.GetName()
                 h2 = k2.ReadObj()
                 h3=h2.Clone()
                 file1.cd("OS_control")
                 h3.Write()
	 

