
if __name__ == "__main__":

    import ROOT
    import argparse
    from ROOT import *
    import re
    from array import array

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal','allJES','qcdup','qcddown','wup','wdown','up', 'down','JESup','JESdown','allTES'], help="Which TES?")
    parser.add_argument('--anti', default="iso", choices=['iso', 'anti'], help="Which TES?")
    options = parser.parse_args()

    nbhist=1
    if options.scale=="allJES":
      nbhist=56
    if options.scale=="allTES":
      nbhist=12

    factorw0jet=1.0
    factorw1jet=1.0
    factorw2jet=1.0

    factorw0jet_u=1.10
    factorw1jet_u=1.10
    factorw2jet_u=1.30

    factorw0jet_d=0.90
    factorw1jet_d=0.90
    factorw2jet_d=0.70

    if (options.scale=="wup"):
        factorw0jet=factorw0jet_u
        factorw1jet=factorw1jet_u
        factorw2jet=factorw2jet_u
    if (options.scale=="wdown"):
        factorw0jet=factorw0jet_d
        factorw1jet=factorw1jet_d
        factorw2jet=factorw2jet_d

    factor0jet=1.07
    factor1jet=1.06
    factor2jet=1.00

    factor0jet_u=1.11
    factor1jet_u=1.12
    factor2jet_u=1.20

    factor0jet_d=1.03
    factor1jet_d=1.00
    factor2jet_d=0.80

    if (options.scale=="qcdup"):
        factor0jet=factor0jet_u
        factor1jet=factor1jet_u
        factor2jet=factor2jet_u
    if (options.scale=="qcddown"):
        factor0jet=factor0jet_d
        factor1jet=factor1jet_d
        factor2jet=factor2jet_d


    samples=["ZTT", "ZJ", "ZL", "Wunscaled", "TTJ", "TTT", "VV", "Data"]

    fDYS=ROOT.TFile("files_control/ZTT.root","r")
    fDYJ=ROOT.TFile("files_control/ZJ.root","r")
    fDYL=ROOT.TFile("files_control/ZL.root","r")
    fW=ROOT.TFile("files_control/Wunscaled.root","r")
    fTTJ=ROOT.TFile("files_control/TTJ.root","r")
    fTTT=ROOT.TFile("files_control/TTT.root","r")
    fVV=ROOT.TFile("files_control/VV.root","r")
    fData=ROOT.TFile("files_control/Data.root","r")
    fout=ROOT.TFile("files_control/W.root","recreate")

    mydir=options.scale


    fout.cd()
    dir20OS=fout.mkdir("et_vbf_D0_0p0to0p2")
    dir21OS=fout.mkdir("et_vbf_D0_0p2to0p4")
    dir22OS=fout.mkdir("et_vbf_D0_0p4to0p8")
    dir24OS=fout.mkdir("et_vbf_D0_0p8to1p0")
    dir20SS=fout.mkdir("SS20")
    dir21SS=fout.mkdir("SS21")
    dir22SS=fout.mkdir("SS22")
    dir24SS=fout.mkdir("SS24")
    dir20QCD=fout.mkdir("QCD20")
    dir21QCD=fout.mkdir("QCD21")
    dir22QCD=fout.mkdir("QCD22")
    dir24QCD=fout.mkdir("QCD24")

    dir30OS=fout.mkdir("et_vbf_D0_0p0to0p2_DCPm")
    dir31OS=fout.mkdir("et_vbf_D0_0p2to0p4_DCPm")
    dir32OS=fout.mkdir("et_vbf_D0_0p4to0p8_DCPm")
    dir34OS=fout.mkdir("et_vbf_D0_0p8to1p0_DCPm")
    dir30SS=fout.mkdir("SS30")
    dir31SS=fout.mkdir("SS31")
    dir32SS=fout.mkdir("SS32")
    dir34SS=fout.mkdir("SS34")
    dir30QCD=fout.mkdir("QCD30")
    dir31QCD=fout.mkdir("QCD31")
    dir32QCD=fout.mkdir("QCD32")
    dir34QCD=fout.mkdir("QCD34")

    dir40OS=fout.mkdir("et_vbf_D0_0p0to0p2_DCPp")
    dir41OS=fout.mkdir("et_vbf_D0_0p2to0p4_DCPp")
    dir42OS=fout.mkdir("et_vbf_D0_0p4to0p8_DCPp")
    dir44OS=fout.mkdir("et_vbf_D0_0p8to1p0_DCPp")
    dir40SS=fout.mkdir("SS40")
    dir41SS=fout.mkdir("SS41")
    dir42SS=fout.mkdir("SS42")
    dir44SS=fout.mkdir("SS44")
    dir40QCD=fout.mkdir("QCD40")
    dir41QCD=fout.mkdir("QCD41")
    dir42QCD=fout.mkdir("QCD42")
    dir44QCD=fout.mkdir("QCD44")

    dir50OS=fout.mkdir("et_vbf_D0hplus_0p0to0p2")
    dir51OS=fout.mkdir("et_vbf_D0hplus_0p2to0p4")
    dir52OS=fout.mkdir("et_vbf_D0hplus_0p4to0p8")
    dir54OS=fout.mkdir("et_vbf_D0hplus_0p8to1p0")
    dir50SS=fout.mkdir("SS50")
    dir51SS=fout.mkdir("SS51")
    dir52SS=fout.mkdir("SS52")
    dir54SS=fout.mkdir("SS54")
    dir50QCD=fout.mkdir("QCD50")
    dir51QCD=fout.mkdir("QCD51")
    dir52QCD=fout.mkdir("QCD52")
    dir54QCD=fout.mkdir("QCD54")

    dir60OS=fout.mkdir("et_vbf_DL1_0p0to0p2")
    dir61OS=fout.mkdir("et_vbf_DL1_0p2to0p4")
    dir62OS=fout.mkdir("et_vbf_DL1_0p4to0p8")
    dir64OS=fout.mkdir("et_vbf_DL1_0p8to1p0")
    dir60SS=fout.mkdir("SS60")
    dir61SS=fout.mkdir("SS61")
    dir62SS=fout.mkdir("SS62")
    dir64SS=fout.mkdir("SS64")
    dir60QCD=fout.mkdir("QCD60")
    dir61QCD=fout.mkdir("QCD61")
    dir62QCD=fout.mkdir("QCD62")
    dir64QCD=fout.mkdir("QCD64")

    dir70OS=fout.mkdir("et_vbf_DL1Zg_0p0to0p2")
    dir71OS=fout.mkdir("et_vbf_DL1Zg_0p2to0p4")
    dir72OS=fout.mkdir("et_vbf_DL1Zg_0p4to0p8")
    dir74OS=fout.mkdir("et_vbf_DL1Zg_0p8to1p0")
    dir70SS=fout.mkdir("SS70")
    dir71SS=fout.mkdir("SS71")
    dir72SS=fout.mkdir("SS72")
    dir74SS=fout.mkdir("SS74")
    dir70QCD=fout.mkdir("QCD70")
    dir71QCD=fout.mkdir("QCD71")
    dir72QCD=fout.mkdir("QCD72")
    dir74QCD=fout.mkdir("QCD74")

    dir0OS=fout.mkdir("OS_control")
    dir0SS=fout.mkdir("SScontrol")
    dir0QCD=fout.mkdir("QCDcontrol")

    nbhist=1
    for k in range(0,nbhist):
        QCDpassSS1=(fData.Get("n70SS").GetBinContent(3)-fDYJ.Get("n70SS").GetBinContent(3)-fDYL.Get("n70SS").GetBinContent(3)-fDYS.Get("n70SS").GetBinContent(3)-fTTJ.Get("n70SS").GetBinContent(3)-fTTT.Get("n70SS").GetBinContent(3)-fW.Get("n70SS").GetBinContent(3)-fVV.Get("n70SS").GetBinContent(3))
        SFpassOS1=((fData.Get("n70").GetBinContent(3)-fDYJ.Get("n70").GetBinContent(3)-fDYL.Get("n70").GetBinContent(3)-fDYS.Get("n70").GetBinContent(3)-fTTJ.Get("n70").GetBinContent(3)-fTTT.Get("n70").GetBinContent(3)-fVV.Get("n70").GetBinContent(3)-factor1jet*QCDpassSS1)/fW.Get("n70").GetBinContent(3))
        QCDpassSS2=(fData.Get("n70SS").GetBinContent(4)-fDYJ.Get("n70SS").GetBinContent(4)-fDYL.Get("n70SS").GetBinContent(4)-fDYS.Get("n70SS").GetBinContent(4)-fTTJ.Get("n70SS").GetBinContent(4)-fTTT.Get("n70SS").GetBinContent(4)-fW.Get("n70SS").GetBinContent(4)-fVV.Get("n70SS").GetBinContent(4))
        SFpassOS2=((fData.Get("n70").GetBinContent(4)-fDYJ.Get("n70").GetBinContent(4)-fDYL.Get("n70").GetBinContent(4)-fDYS.Get("n70").GetBinContent(4)-fTTJ.Get("n70").GetBinContent(4)-fTTT.Get("n70").GetBinContent(4)-fVV.Get("n70").GetBinContent(4)-factor2jet*QCDpassSS2)/fW.Get("n70").GetBinContent(4))

        SFpassOS2=SFpassOS1
	
        hW0jet=fW.Get("OS_control/W")
        hW0jet.Scale(SFpassOS2*factorw2jet)
        hW0jet_SS=fW.Get("SScontrol/W")
        hW0jet_SS.Scale(SFpassOS2*factorw2jet)
        hW0jet_QCD=fW.Get("QCDcontrol/W")
        hW0jet_QCD.Scale(SFpassOS2*factorw2jet)



	for i in range(len(samples)):
	    print  samples[i]
	    file=ROOT.TFile("./files_control/"+str(samples[i])+".root","r")
            print "will look into ", file, str(samples[i])
            file.cd()
            dirList = gDirectory.GetListOfKeys()
            for k1 in dirList:
                name=k1.GetName()

                if "control" in name :
                    h1 = k1.ReadObj()
	            h1.cd()
	            print "will now look into dir",name
	            dirList2 = gDirectory.GetListOfKeys()

	            for k2 in dirList2:
      	                print  k1.GetName(), k2.GetName()
                        h2 = k2.ReadObj()
			if samples[i] in k2.GetName() :
                          h3=h2.Clone()

                          h3.Scale(SFpassOS2*factorw2jet)


                          fout.cd()
		          if name == "OS_control" :
                            dir0OS.cd()
                          #hW0jet.SetName("W")
                          #hW0jet.Write()
                            h3.Write()

		          if name == "SScontrol" :
                              dir0SS.cd()
                          #hW0jet.SetName("W")
                            #hW0jet_SS.Write()
                              h3.Write()

		          if name == "QCDcontrol" :
                              dir0QCD.cd()
                          #hW0jet.SetName("W")
                            #hW0jet_QCD.Write()
                              h3.Write()


