
global hSS,hQCDSS

if __name__ == "__main__":


    import ROOT
    import argparse
    from ROOT import *
    import re
    from array import array

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'allJES','up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allTES'], help="Which TES?")
    options = parser.parse_args()

    factor0jet=1.07
    factor1jet=1.06
    factor2jet=1.00

    factor0jet_u=1.11
    factor1jet_u=1.12
    factor2jet_u=1.20

    factor0jet_d=1.03
    factor1jet_d=1.00
    factor2jet_d=0.80

    facteur=1.0

    samples=["ZTT", "ZJ", "ZL", "Wunscaled", "TTJ", "TTT", "VV"]


    mydir=options.scale
    if options.scale=="allJES":
       mydir="JESup"
    if options.scale=="nominal":
       mydir="nominal"

    '''
    fDYJ=ROOT.TFile("files_control/ZJ.root","r")
    fDYL=ROOT.TFile("files_control/ZL.root","r")
    fDYS=ROOT.TFile("files_control/ZTT.root","r")
    fW=ROOT.TFile("files_control/W.root","r")
    fTTJ=ROOT.TFile("files_control/TTJ.root","r")
    fTTT=ROOT.TFile("files_control/TTT.root","r")
    fVV=ROOT.TFile("files_control/VV.root","r")
    fData=ROOT.TFile("files_control/Data.root","r")
     '''

    fout=ROOT.TFile("files_control/QCD.root","recreate")

    fData=ROOT.TFile("files_control/Data.root","r")
    #hSS=fData.Get("OS_control/data_obs")
    #hQCDSS=fData.Get("OS_control/data_obs")
    #hSS.Reset()
    #hQCDSS.Reset()

    nbhist=1

    for k in range(0,nbhist):

	fileD=ROOT.TFile("./files_control/Data.root","r")

	for i in range(len(samples)):
	    print  samples[i]
	    file=ROOT.TFile("./files_control/"+str(samples[i])+".root","r")
            print "will look into ", file, str(samples[i])
            file.cd()
            dirList = gDirectory.GetListOfKeys()
            for k1 in dirList:
                name=k1.GetName()

                if "SScontrol" in name :
                    h1 = k1.ReadObj()
	            h1.cd()
	            print "will now look into SScontrol dir",h1
	            dirList2 = gDirectory.GetListOfKeys()

	            for k2 in dirList2:
      	                print  k1.GetName(), k2.GetName()
                        h2 = k2.ReadObj()
			hSS
			if k2.GetName()+"_data_obs" == k2.GetName() :
			  hSS=h2.Clone()
			if samples[i] in k2.GetName() :
                          h3=h2.Clone()
			  hSS.Add(h3,-1)
                          
                    hSS.Scale(factor2jet)
                    #hSS.SetName("QCD")

                    for i in range(0,hSS.GetSize()-2):
                        if hSS.GetBinContent(i)<0:
                            hSS.SetBinError(i,max(0,hSS.GetBinError(i)+hSS.GetBinContent(i)))
                            hSS.SetBinContent(i,0)

                if "QCDcontrol" in name :
                    h1 = k1.ReadObj()
	            h1.cd()
	            print "will now look into SScontrol dir",h1
	            dirList2 = gDirectory.GetListOfKeys()

	            for k2 in dirList2:
      	                print  k1.GetName(), k2.GetName()
                        h2 = k2.ReadObj()
			if k2.GetName()+"_data_obs" == k2.GetName() :
			  hQCDSS=h2.Clone()
			if samples[i] in k2.GetName() :
                          h4=h2.Clone()
			  hQCDSS.Add(h4,-1)
                          
		    hQCDSS.Scale(factor2jet)
		    #hQCDSS.SetName("QCD")

                    for i in range(0,hQCDSS.GetSize()-2):
                       if hQCDSS.GetBinContent(i)<0:
                          hQCDSS.SetBinError(i,max(0,hQCDSS.GetBinError(i)+hQCDSS.GetBinContent(i)))
                          hQCDSS.SetBinContent(i,0)

            fout.cd()
            dir0jet=fout.mkdir("OS_control")
            dir0jet.cd("OS_control")
            hQCDSS.Scale(hSS.Integral()/hQCDSS.Integral())
            hQCDSS.Write()


