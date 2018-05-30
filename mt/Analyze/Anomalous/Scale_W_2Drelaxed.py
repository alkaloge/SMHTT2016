if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal','allJES','qcdup','qcddown','wup','wdown','up', 'down','JESup','JESdown'], help="Which TES?")
    parser.add_argument('--anti', default="iso", choices=['iso', 'anti'], help="Which TES?")
    options = parser.parse_args()


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

    factor0jet=1.00
    factor1jet=1.28
    factor2jet=1.00

    factor0jet_u=1.07
    factor1jet_u=1.41
    factor2jet_u=1.20

    factor0jet_d=0.93
    factor1jet_d=1.15
    factor2jet_d=0.80

    if (options.scale=="qcdup"):
        factor0jet=factor0jet_u
        factor1jet=factor1jet_u
        factor2jet=factor2jet_u
    if (options.scale=="qcddown"):
        factor0jet=factor0jet_d
        factor1jet=factor1jet_d
        factor2jet=factor2jet_d

    postfix=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix0=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix1=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    if (options.scale!="allJES"):
        postfix[0]=""
        postfix0[0]=""
        postfix1[0]=""
        postfix2[0]=""
    if (options.scale=="up"):
        postfix[0]="_CMS_scale_t_et_13TeVUp"
        postfix0[0]="_CMS_scale_t_et_13TeVUp"
        postfix1[0]="_CMS_scale_t_et_13TeVUp"
        postfix2[0]="_CMS_scale_t_et_13TeVUp"
    if (options.scale=="down"):
        postfix[0]="_CMS_scale_t_et_13TeVDown"
        postfix0[0]="_CMS_scale_t_et_13TeVDown"
        postfix1[0]="_CMS_scale_t_et_13TeVDown"
        postfix2[0]="_CMS_scale_t_et_13TeVDown"
    if (options.scale=="JESup"):
        postfix[0]="_CMS_scale_j_13TeVUp"
        postfix0[0]="_CMS_scale_j_13TeVUp"
        postfix1[0]="_CMS_scale_j_13TeVUp"
        postfix2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        postfix[0]="_CMS_scale_j_13TeVDown"
        postfix0[0]="_CMS_scale_j_13TeVDown"
        postfix1[0]="_CMS_scale_j_13TeVDown"
        postfix2[0]="_CMS_scale_j_13TeVDown"
    if (options.scale=="qcdup"):
        postfix0[0]="_QCDSFUncert_et_0jet_13TeVUp"
        postfix1[0]="_QCDSFUncert_et_boosted_13TeVUp"
        postfix2[0]="_QCDSFUncert_et_vbf_13TeVUp"
    if (options.scale=="qcddown"):
        postfix0[0]="_QCDSFUncert_et_0jet_13TeVDown"
        postfix1[0]="_QCDSFUncert_et_boosted_13TeVDown"
        postfix2[0]="_QCDSFUncert_et_vbf_13TeVDown"
    if (options.scale=="wup"):
        postfix0[0]="_WSFUncert_et_0jet_13TeVUp"
        postfix1[0]="_WSFUncert_et_boosted_13TeVUp"
        postfix2[0]="_WSFUncert_et_vbf_13TeVUp"
    if (options.scale=="wdown"):
        postfix0[0]="_WSFUncert_et_0jet_13TeVDown"
        postfix1[0]="_WSFUncert_et_boosted_13TeVDown"
        postfix2[0]="_WSFUncert_et_vbf_13TeVDown"

    post2=postfix
    if (options.scale=="qcdup"):
        post2[0]=""
    if (options.scale=="qcddown"):
        post2[0]=""
    if (options.scale=="wup"):
        post2[0]=""
    if (options.scale=="wdown"):
        post2[0]=""
    if (options.scale=="nominal"):
        post2[0]=""

    fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
    fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
    fDYL=ROOT.TFile("files_nominal/ZL.root","r")
    fW=ROOT.TFile("files_nominal/Wunscaled.root","r")
    fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
    fTTT=ROOT.TFile("files_nominal/TTT.root","r")
    fVV=ROOT.TFile("files_nominal/VV.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    #fout=ROOT.TFile("files_"+options.scale+"/W.root","recreate")

    mydir=options.scale
    if (options.scale=="allJES"):
         mydir="nominal"
    mydir2=options.scale
    if (options.scale=="allJES"):
         mydir2="JESup"

    if (options.scale=="wdown"):
       fout=ROOT.TFile("files_nominal/W_wdown.root","recreate")
    elif (options.scale=="wup"):
       fout=ROOT.TFile("files_nominal/W_wup.root","recreate")
    elif (options.scale=="qcddown"):
       fout=ROOT.TFile("files_nominal/W_qcddown.root","recreate")
    elif (options.scale=="qcdup"):
       fout=ROOT.TFile("files_nominal/W_qcdup.root","recreate")
    elif (options.scale=="up" or options.scale=="down" or options.scale=="JESdown" or options.scale=="JESup" or options.scale=="nominal" or options.scale=="allJES"):
       fDYS=ROOT.TFile("files_"+mydir+"/ZTT.root","r")
       fDYJ=ROOT.TFile("files_"+mydir+"/ZJ.root","r")
       fDYL=ROOT.TFile("files_"+mydir+"/ZL.root","r")
       fW=ROOT.TFile("files_"+mydir2+"/Wunscaled.root","r")
       print "files_"+mydir2+"/Wunscaled.root"
       fTTT=ROOT.TFile("files_"+mydir+"/TTT.root","r")
       fTTJ=ROOT.TFile("files_"+mydir+"/TTJ.root","r")
       fVV=ROOT.TFile("files_"+mydir+"/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_"+mydir2+"/W.root","recreate")

    print mydir2
    print fData.Get("n70SS").GetBinContent(2)
    print fDYL.Get("n70SS").GetBinContent(2)
    print fDYJ.Get("n70SS").GetBinContent(2)
    print fDYS.Get("n70SS").GetBinContent(2)
    print fTTT.Get("n70SS").GetBinContent(2)
    print fTTJ.Get("n70SS").GetBinContent(2)
    print fW.Get("n70SS").GetBinContent(2)
    QCDpassSS0=fData.Get("n70SS").GetBinContent(2)-fDYJ.Get("n70SS").GetBinContent(2)-fDYL.Get("n70SS").GetBinContent(2)-fDYS.Get("n70SS").GetBinContent(2)-fTTJ.Get("n70SS").GetBinContent(2)-fTTT.Get("n70SS").GetBinContent(2)-fW.Get("n70SS").GetBinContent(2)-fVV.Get("n70SS").GetBinContent(2)
    print "Proportion of W in data high mt SS (0 jet):",fW.Get("n70SS").GetBinContent(2)/fData.Get("n70SS").GetBinContent(2)
    print "Proportion of W in data high mt SS (boosted):",fW.Get("n70SS").GetBinContent(3)/fData.Get("n70SS").GetBinContent(3)
    print "Proportion of W in data high mt SS (VBF):",fW.Get("n70SS").GetBinContent(4)/fData.Get("n70SS").GetBinContent(4)
    SFpassOS0=(fData.Get("n70").GetBinContent(2)-fDYJ.Get("n70").GetBinContent(2)-fDYL.Get("n70").GetBinContent(2)-fDYS.Get("n70").GetBinContent(2)-fTTJ.Get("n70").GetBinContent(2)-fTTT.Get("n70").GetBinContent(2)-fVV.Get("n70").GetBinContent(2)-factor0jet*QCDpassSS0)/fW.Get("n70").GetBinContent(2)
    QCDpassSS1=fData.Get("n70SS").GetBinContent(3)-fDYJ.Get("n70SS").GetBinContent(3)-fDYL.Get("n70SS").GetBinContent(3)-fDYS.Get("n70SS").GetBinContent(3)-fTTJ.Get("n70SS").GetBinContent(3)-fTTT.Get("n70SS").GetBinContent(3)-fW.Get("n70SS").GetBinContent(3)-fVV.Get("n70SS").GetBinContent(3)
    SFpassOS1=(fData.Get("n70").GetBinContent(3)-fDYJ.Get("n70").GetBinContent(3)-fDYL.Get("n70").GetBinContent(3)-fDYS.Get("n70").GetBinContent(3)-fTTJ.Get("n70").GetBinContent(3)-fTTT.Get("n70").GetBinContent(3)-fVV.Get("n70").GetBinContent(3)-factor1jet*QCDpassSS1)/fW.Get("n70").GetBinContent(3)
    QCDpassSS2=fData.Get("n70SS").GetBinContent(4)-fDYJ.Get("n70SS").GetBinContent(4)-fDYL.Get("n70SS").GetBinContent(4)-fDYS.Get("n70SS").GetBinContent(4)-fTTJ.Get("n70SS").GetBinContent(4)-fTTT.Get("n70SS").GetBinContent(4)-fW.Get("n70SS").GetBinContent(4)-fVV.Get("n70SS").GetBinContent(4)
    SFpassOS2=(fData.Get("n70").GetBinContent(4)-fDYJ.Get("n70").GetBinContent(4)-fDYL.Get("n70").GetBinContent(4)-fDYS.Get("n70").GetBinContent(4)-fTTJ.Get("n70").GetBinContent(4)-fTTT.Get("n70").GetBinContent(4)-fVV.Get("n70").GetBinContent(4)-factor2jet*QCDpassSS2)/fW.Get("n70").GetBinContent(4)
    print "Proportion of QCD in high mt SS (0 jet):",QCDpassSS0/fData.Get("n70SS").GetBinContent(2)
    print "Proportion of QCD in high mt SS (boosted):",QCDpassSS1/fData.Get("n70SS").GetBinContent(3)
    print "Proportion of QCD in high mt SS (VBF):",QCDpassSS2/fData.Get("n70SS").GetBinContent(4)
    #print "0 jet", fData.Get("n70").GetBinContent(2),QCDpassSS0,fW.Get("n70SS").GetBinContent(2),fW.Get("n70SS").GetBinError(2)
    #print "0 jet error", 1.0/(fData.Get("n70").GetBinContent(2)**0.5),fW.Get("n70SS").GetBinError(2)/fW.Get("n70SS").GetBinContent(2),0.20*QCDpassSS0/fData.Get("n70").GetBinContent(2)
    #print "Boosted", fData.Get("n70").GetBinContent(3),QCDpassSS1,fW.Get("n70SS").GetBinContent(3),fW.Get("n70SS").GetBinError(3)
    #print "Boosted error", 1.0/(fData.Get("n70").GetBinContent(3)**0.5),fW.Get("n70SS").GetBinError(3)/fW.Get("n70SS").GetBinContent(3),0.20*QCDpassSS1/fData.Get("n70").GetBinContent(3)
    #print "VBF", fData.Get("n70").GetBinContent(4),QCDpassSS0,fW.Get("n70SS").GetBinContent(4),fW.Get("n70SS").GetBinError(4)
    #print "VBF error", 1.0/(fData.Get("n70").GetBinContent(4)**0.5),fW.Get("n70SS").GetBinError(4)/fW.Get("n70SS").GetBinContent(4),0.20*QCDpassSS2/fData.Get("n70").GetBinContent(4)
    #print SFpassOS0,SFpassOS1,SFpassOS2

    fout.cd()
    dir0OS=fout.mkdir("et_0jet")
    dir1OS=fout.mkdir("et_boosted")
    dir2OS=fout.mkdir("et_vbf")
    dir0QCDCROS=fout.mkdir("et_antiiso_0jet_cr")
    dir1QCDCROS=fout.mkdir("et_antiiso_boosted_cr")
    dir2QCDCROS=fout.mkdir("et_antiiso_vbf_cr")
    dir0WCROS=fout.mkdir("et_wjets_0jet_cr")
    dir1WCROS=fout.mkdir("et_wjets_boosted_cr")
    dir2WCROS=fout.mkdir("et_wjets_vbf_cr")
    dir0QCDCRSSOS=fout.mkdir("et_antiiso_0jet_crSS")
    dir1QCDCRSSOS=fout.mkdir("et_antiiso_boosted_crSS")
    dir2QCDCRSSOS=fout.mkdir("et_antiiso_vbf_crSS")
    dir0WCRSSOS=fout.mkdir("et_wjets_0jet_crSS")
    dir1WCRSSOS=fout.mkdir("et_wjets_boosted_crSS")
    dir2WCRSSOS=fout.mkdir("et_wjets_vbf_crSS")
    dir0SS=fout.mkdir("SS0jet")
    dir1SS=fout.mkdir("SS1jet")
    dir2SS=fout.mkdir("SSvbf")
    dir0QCD=fout.mkdir("QCD0jet")
    dir1QCD=fout.mkdir("QCD1jet")
    dir2QCD=fout.mkdir("QCDvbf")

    nbhist=1
    if options.scale=="allJES":
      nbhist=56
    for k in range(0,nbhist):
	print "et_0jet/W"+post2[k]
        hW0jet=fW.Get("et_0jet/W"+post2[k])
        hW0jet.Scale(SFpassOS0*factorw0jet)
        hW1jet=fW.Get("et_boosted/W"+post2[k])
        hW1jet.Scale(SFpassOS1*factorw1jet)
        print "et_vbf/W"+post2[k]
        hW2jet=fW.Get("et_vbf/W"+post2[k])
        print hW2jet.Integral()
        hW2jet.Scale(SFpassOS2*factorw2jet)
        print hW2jet.Integral()
        hW0jet_SS=fW.Get("SS0jet/W"+post2[k])
        hW0jet_SS.Scale(SFpassOS0*factorw0jet)
        hW1jet_SS=fW.Get("SS1jet/W"+post2[k])
        hW1jet_SS.Scale(SFpassOS1*factorw1jet)
        hW2jet_SS=fW.Get("SSvbf/W"+post2[k])
        hW2jet_SS.Scale(SFpassOS2*factorw2jet)
        hW0jet_QCD=fW.Get("QCD0jet/W"+post2[k])
        hW0jet_QCD.Scale(SFpassOS0*factorw0jet)
        hW1jet_QCD=fW.Get("QCD1jet/W"+post2[k])
        hW1jet_QCD.Scale(SFpassOS1*factorw1jet)
        hW2jet_QCD=fW.Get("QCDvbf/W"+post2[k])
        hW2jet_QCD.Scale(SFpassOS2*factorw2jet)

        #hWCR0jet=fW.Get("et_wjets_0jet_cr/W"+post2[k])
        #hWCR0jet.Scale(SFpassOS0*factorw0jet)
        #hWCR1jet=fW.Get("et_wjets_boosted_cr/W"+post2[k])
        #hWCR1jet.Scale(SFpassOS1*factorw1jet)
        #hWCR2jet=fW.Get("et_wjets_vbf_cr/W"+post2[k])
        #hWCR2jet.Scale(SFpassOS2*factorw2jet)

        #hQCDCR0jet=fW.Get("et_antiiso_0jet_cr/W"+post2[k])
        #hQCDCR0jet.Scale(SFpassOS0*factorw0jet)
        #hQCDCR1jet=fW.Get("et_antiiso_boosted_cr/W"+post2[k])
        #hQCDCR1jet.Scale(SFpassOS1*factorw1jet)
        #hQCDCR2jet=fW.Get("et_antiiso_vbf_cr/W"+post2[k])
        #hQCDCR2jet.Scale(SFpassOS2*factorw2jet)

        #hWCRSS0jet=fW.Get("et_wjets_0jet_crSS/W"+post2[k])
        #hWCRSS0jet.Scale(SFpassOS0*factorw0jet)
        #hWCRSS1jet=fW.Get("et_wjets_boosted_crSS/W"+post2[k])
        #hWCRSS1jet.Scale(SFpassOS1*factorw1jet)
        #hWCRSS2jet=fW.Get("et_wjets_vbf_crSS/W"+post2[k])
        #hWCRSS2jet.Scale(SFpassOS2*factorw2jet)

        #hQCDCRSS0jet=fW.Get("et_antiiso_0jet_crSS/W"+post2[k])
        #hQCDCRSS0jet.Scale(SFpassOS0*factorw0jet)
        #hQCDCRSS1jet=fW.Get("et_antiiso_boosted_crSS/W"+post2[k])
        #hQCDCRSS1jet.Scale(SFpassOS1*factorw1jet)
        #hQCDCRSS2jet=fW.Get("et_antiiso_vbf_crSS/W"+post2[k])
        #hQCDCRSS2jet.Scale(SFpassOS2*factorw2jet)

        fout.cd()
        dir0OS.cd()
        hW0jet.SetName("W"+postfix0[k])
        hW0jet.Write()
        dir1OS.cd()
        hW1jet.SetName("W"+postfix1[k])
        hW1jet.Write()
        dir2OS.cd()
        hW2jet.SetName("W"+postfix2[k])
        hW2jet.Write()

        #dir0QCDCROS.cd()
        #hQCDCR0jet.SetName("W"+postfix0)
        #hQCDCR0jet.Write()
        #dir1QCDCROS.cd()
        #hQCDCR1jet.SetName("W"+postfix1)
        #hQCDCR1jet.Write()
        #dir2QCDCROS.cd()
        #hQCDCR2jet.SetName("W"+postfix2)
        #hQCDCR2jet.Write()

        #dir0WCROS.cd()
        #hWCR0jet.SetName("W"+postfix0)
        #hWCR0jet.Write()
        #dir1WCROS.cd()
        #hWCR1jet.SetName("W"+postfix1)
        #hWCR1jet.Write()
        #dir2WCROS.cd()
        #hWCR2jet.SetName("W"+postfix2)
        #hWCR2jet.Write()

        #dir0QCDCRSSOS.cd()
        #hQCDCRSS0jet.SetName("W"+postfix0)
        #hQCDCRSS0jet.Write()
        #dir1QCDCRSSOS.cd()
        #hQCDCRSS1jet.SetName("W"+postfix1)
        #hQCDCRSS1jet.Write()
        #dir2QCDCRSSOS.cd()
        #hQCDCRSS2jet.SetName("W"+postfix2)
        #hQCDCRSS2jet.Write()

        #dir0WCRSSOS.cd()
        #hWCRSS0jet.SetName("W"+postfix0)
        #hWCRSS0jet.Write()
        #dir1WCRSSOS.cd()
        #hWCRSS1jet.SetName("W"+postfix1)
        #hWCRSS1jet.Write()
        #dir2WCRSSOS.cd()
        #hWCRSS2jet.SetName("W"+postfix2)
        #hWCRSS2jet.Write()

        dir0SS.cd()
        hW0jet_SS.SetName("W"+postfix0[k])
        hW0jet_SS.Write()
        dir1SS.cd()
        hW1jet_SS.SetName("W"+postfix1[k])
        hW1jet_SS.Write()
        dir2SS.cd()
        hW2jet_SS.SetName("W"+postfix2[k])
        hW2jet_SS.Write()

        dir0QCD.cd()
        hW0jet_QCD.SetName("W"+postfix0[k])
        hW0jet_QCD.Write()
        dir1QCD.cd()
        hW1jet_QCD.SetName("W"+postfix1[k])
        hW1jet_QCD.Write()
        dir2QCD.cd()
        hW2jet_QCD.SetName("W"+postfix2[k])
        hW2jet_QCD.Write()
        print postfix0[k],postfix1[k],postfix2[k]

