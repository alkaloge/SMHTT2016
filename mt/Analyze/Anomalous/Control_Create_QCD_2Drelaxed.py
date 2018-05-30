if __name__ == "__main__":

    import ROOT
    import argparse

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

    mydir=options.scale
    if options.scale=="allJES":
       mydir="JESup"
    if options.scale=="nominal":
       mydir="nominal"

    fDYJ=ROOT.TFile("files_control/ZJ.root","r")
    fDYL=ROOT.TFile("files_control/ZL.root","r")
    fDYS=ROOT.TFile("files_control/ZTT.root","r")
    fW=ROOT.TFile("files_control/W.root","r")
    fTTJ=ROOT.TFile("files_control/TTJ.root","r")
    fTTT=ROOT.TFile("files_control/TTT.root","r")
    fVV=ROOT.TFile("files_control/VV.root","r")
    fData=ROOT.TFile("files_control/Data.root","r")
    fout=ROOT.TFile("files_control/QCD.root","recreate")

    fout.cd()
    dir0jet=fout.mkdir("OS_control")
    nbhist=1

    plots=["hmelaDCP_VBF", "hmelaDCPggH_VBF", "hmelaD0minus_VBF", "hmelaD0minusggH_VBF", "hmelaDPhijj_VBF", "hmelaDPhiUnsignedjj_VBF", "h1D_jpt1_VBF", "h1D_jpt2_VBF", "h1D_mjj_VBF", "h1D_met_VBF"]

    for k in range(len(plots)):
        print "will work for ", str(plots[k])
        hSS_0jet=fData.Get("SScontrol/"+str(plots[k])+"_SS_data_obs")
        hSS_0jet.Add(fDYJ.Get("SScontrol/"+str(plots[k])+"_SS_ZJ"),-1)
        hSS_0jet.Add(fDYL.Get("SScontrol/"+str(plots[k])+"_SS_ZL"),-1)
        hSS_0jet.Add(fTTJ.Get("SScontrol/"+str(plots[k])+"_SS_TTJ"),-1)
        hSS_0jet.Add(fTTT.Get("SScontrol/"+str(plots[k])+"_SS_TTT"),-1)
        hSS_0jet.Add(fW.Get("SScontrol/"+str(plots[k])+"_SS_W"),-1)
        hSS_0jet.Add(fVV.Get("SScontrol/"+str(plots[k])+"_SS_VV"),-1)
        hSS_0jet.Add(fDYS.Get("SScontrol/"+str(plots[k])+"_SS_ZTT"),-1)
        hSS_0jet.SetName(str(plots[k])+"_SS_QCD")
        hSS_0jet.Scale(factor2jet)
        for i in range(0,hSS_0jet.GetSize()-2):
            if hSS_0jet.GetBinContent(i)<0:
                hSS_0jet.SetBinError(i,max(0,hSS_0jet.GetBinError(i)+hSS_0jet.GetBinContent(i)))
                hSS_0jet.SetBinContent(i,0)

        hQCD_0jet=fData.Get("QCDcontrol/"+str(plots[k])+"_QCD_data_obs")
        hQCD_0jet.Add(fDYJ.Get("QCDcontrol/"+str(plots[k])+"_QCD_ZJ"),-1)
        hQCD_0jet.Add(fDYL.Get("QCDcontrol/"+str(plots[k])+"_QCD_ZL"),-1)
        hQCD_0jet.Add(fTTJ.Get("QCDcontrol/"+str(plots[k])+"_QCD_TTJ"),-1)
        hQCD_0jet.Add(fTTT.Get("QCDcontrol/"+str(plots[k])+"_QCD_TTT"),-1)
        hQCD_0jet.Add(fW.Get("QCDcontrol/"+str(plots[k])+"_QCD_W"),-1)
        hQCD_0jet.Add(fVV.Get("QCDcontrol/"+str(plots[k])+"_QCD_VV"),-1)
        hQCD_0jet.Add(fDYS.Get("QCDcontrol/"+str(plots[k])+"_QCD_ZTT"),-1)
        hQCD_0jet.SetName(str(plots[k])+"_QCD")
        hQCD_0jet.Scale(factor2jet)
        for i in range(0,hQCD_0jet.GetSize()-2):
            if hQCD_0jet.GetBinContent(i)<0:
                hQCD_0jet.SetBinError(i,max(0,hQCD_0jet.GetBinError(i)+hQCD_0jet.GetBinContent(i)))
                hQCD_0jet.SetBinContent(i,0)


        fout.cd()

        dir0jet.cd()
        hQCD_0jet.Scale(hSS_0jet.Integral()/hQCD_0jet.Integral())
        hQCD_0jet.SetName(str(plots[k])+"_OS_QCD")
        print "this is the name for the QCD TH1 ", str(plots[k])+"_OS_QCD"
        hQCD_0jet.Write()


