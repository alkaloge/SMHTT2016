if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'allJES','up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allTES'], help="Which TES?")
    options = parser.parse_args()

    factor0jet=1.00
    factor1jet=1.28
    factor2jet=1.00

    factor0jet_u=1.07
    factor1jet_u=1.41
    factor2jet_u=1.20

    factor0jet_d=0.93
    factor1jet_d=1.15
    factor2jet_d=0.80

    postfix=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_JetAbsoluteFlavMap_13TeVDown","_CMS_scale_j_JetAbsoluteFlavMap_13TeVUp","_CMS_scale_j_JetAbsoluteMPFBias_13TeVDown","_CMS_scale_j_JetAbsoluteMPFBias_13TeVUp","_CMS_scale_j_JetAbsoluteScale_13TeVDown","_CMS_scale_j_JetAbsoluteScale_13TeVUp","_CMS_scale_j_JetAbsoluteStat_13TeVDown","_CMS_scale_j_JetAbsoluteStat_13TeVUp","_CMS_scale_j_JetFlavorQCD_13TeVDown","_CMS_scale_j_JetFlavorQCD_13TeVUp","_CMS_scale_j_JetFragmentation_13TeVDown","_CMS_scale_j_JetFragmentation_13TeVUp","_CMS_scale_j_JetPileUpDataMC_13TeVDown","_CMS_scale_j_JetPileUpDataMC_13TeVUp","_CMS_scale_j_JetPileUpPtBB_13TeVDown","_CMS_scale_j_JetPileUpPtBB_13TeVUp","_CMS_scale_j_JetPileUpPtEC1_13TeVDown","_CMS_scale_j_JetPileUpPtEC1_13TeVUp","_CMS_scale_j_JetPileUpPtEC2_13TeVDown","_CMS_scale_j_JetPileUpPtEC2_13TeVUp","_CMS_scale_j_JetPileUpPtHF_13TeVDown","_CMS_scale_j_JetPileUpPtHF_13TeVUp","_CMS_scale_j_JetPileUpPtRef_13TeVDown","_CMS_scale_j_JetPileUpPtRef_13TeVUp","_CMS_scale_j_JetRelativeBal_13TeVDown","_CMS_scale_j_JetRelativeBal_13TeVUp","_CMS_scale_j_JetRelativeFSR_13TeVDown","_CMS_scale_j_JetRelativeFSR_13TeVUp","_CMS_scale_j_JetRelativeJEREC1_13TeVDown","_CMS_scale_j_JetRelativeJEREC1_13TeVUp","_CMS_scale_j_JetRelativeJEREC2_13TeVDown","_CMS_scale_j_JetRelativeJEREC2_13TeVUp","_CMS_scale_j_JetRelativeJERHF_13TeVDown","_CMS_scale_j_JetRelativeJERHF_13TeVUp","_CMS_scale_j_JetRelativePtBB_13TeVDown","_CMS_scale_j_JetRelativePtBB_13TeVUp","_CMS_scale_j_JetRelativePtEC1_13TeVDown","_CMS_scale_j_JetRelativePtEC1_13TeVUp","_CMS_scale_j_JetRelativePtEC2_13TeVDown","_CMS_scale_j_JetRelativePtEC2_13TeVUp","_CMS_scale_j_JetRelativePtHF_13TeVDown","_CMS_scale_j_JetRelativePtHF_13TeVUp","_CMS_scale_j_JetRelativeStatEC_13TeVDown","_CMS_scale_j_JetRelativeStatEC_13TeVUp","_CMS_scale_j_JetRelativeStatFSR_13TeVDown","_CMS_scale_j_JetRelativeStatFSR_13TeVUp","_CMS_scale_j_JetRelativeStatHF_13TeVDown","_CMS_scale_j_JetRelativeStatHF_13TeVUp","_CMS_scale_j_JetSinglePionECAL_13TeVDown","_CMS_scale_j_JetSinglePionECAL_13TeVUp","_CMS_scale_j_JetSinglePionHCAL_13TeVDown","_CMS_scale_j_JetSinglePionHCAL_13TeVUp","_CMS_scale_j_JetTimePtEta_13TeVDown","_CMS_scale_j_JetTimePtEta_13TeVUp"]
    post2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix0=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix1=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfixTES=["_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"]

    if options.scale!="allJES":
        postfix[0]=""

    if (options.scale!='allJES'):
       postfix0[0]=""
       postfix1[0]=""
       postfix2[0]=""
    if (options.scale=="up"):
        postfix0[0]="_CMS_scale_t_et_13TeVUp"
        postfix1[0]="_CMS_scale_t_et_13TeVUp"
        postfix2[0]="_CMS_scale_t_et_13TeVUp"
    if (options.scale=="down"):
        postfix0[0]="_CMS_scale_t_et_13TeVDown"
        postfix1[0]="_CMS_scale_t_et_13TeVDown"
        postfix2[0]="_CMS_scale_t_et_13TeVDown"
    if (options.scale=="JESup"):
        postfix0[0]="_CMS_scale_j_13TeVUp"
        postfix1[0]="_CMS_scale_j_13TeVUp"
        postfix2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
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

    if (options.scale=="JESup"):
        post2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        post2[0]="_CMS_scale_j_13TeVDown"
    if (options.scale=="up"):
        post2[0]="_CMS_scale_t_et_13TeVUp"
    if (options.scale=="down"):
        post2[0]="_CMS_scale_t_et_13TeVDown"
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
        postfix0[0]=""
        postfix1[0]=""
        postfix2[0]=""

    facteur=1.0
    if (options.scale=="qcdup"):
        factor0jet=factor0jet_u
        factor1jet=factor1jet_u
        factor2jet=factor2jet_u
    if (options.scale=="qcddown"):
        factor0jet=factor0jet_d
        factor1jet=factor1jet_d
        factor2jet=factor2jet_d

    mydir=options.scale
    if options.scale=="allJES":
       mydir="JESup"
    if options.scale=="nominal":
       mydir="nominal"

    if options.scale=="allTES":
      for j in range(0,12):
         post2[j]=postfixTES[j]
         postfix0[j]=postfixTES[j]
         postfix1[j]=postfixTES[j]
         postfix2[j]=postfixTES[j]

    if options.scale=="up" or options.scale=="down" or options.scale=="JESup" or options.scale=="JESdown" or options.scale=="allJES" or options.scale=="allTES":
       fDYJ=ROOT.TFile("files_"+mydir+"/ZJ.root","r")
       fDYL=ROOT.TFile("files_"+mydir+"/ZL.root","r")
       fDYS=ROOT.TFile("files_"+mydir+"/ZTT.root","r")
       fW=ROOT.TFile("files_"+mydir+"/W.root","r")
       fTTJ=ROOT.TFile("files_"+mydir+"/TTJ.root","r")
       fTTT=ROOT.TFile("files_"+mydir+"/TTT.root","r")
       fVV=ROOT.TFile("files_"+mydir+"/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_"+mydir+"/QCD.root","recreate")
    elif options.scale=="wup":
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_wup.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_wup.root","recreate")
    elif options.scale=="wdown":
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_wdown.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_wdown.root","recreate")
    elif options.scale=="qcdup":
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_qcdup.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_qcdup.root","recreate")
    elif options.scale=="qcddown":
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_qcddown.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_qcddown.root","recreate")
    else:
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD.root","recreate")

    fout.cd()
    dir0jet=fout.mkdir("et_0jet")
    dir1jet=fout.mkdir("et_boosted")
    dir2jet=fout.mkdir("et_vbf")
    dir3jet=fout.mkdir("et_vbf_D0_0p0to0p2")
    dir4jet=fout.mkdir("et_vbf_D0_0p2to0p4")
    dir5jet=fout.mkdir("et_vbf_D0_0p4to0p8")
    dir7jet=fout.mkdir("et_vbf_D0_0p8to1p0")

    dir3jetggH=fout.mkdir("et_vbf_D0_0p0to0p2_ggH")
    dir4jetggH=fout.mkdir("et_vbf_D0_0p2to0p4_ggH")
    dir5jetggH=fout.mkdir("et_vbf_D0_0p4to0p8_ggH")
    dir7jetggH=fout.mkdir("et_vbf_D0_0p8to1p0_ggH")


    dir33jetggH=fout.mkdir("et_vbf_D0_0p0to0p2_DCPm_ggH")
    dir34jetggH=fout.mkdir("et_vbf_D0_0p2to0p4_DCPm_ggH")
    dir35jetggH=fout.mkdir("et_vbf_D0_0p4to0p8_DCPm_ggH")
    dir37jetggH=fout.mkdir("et_vbf_D0_0p8to1p0_DCPm_ggH")

    dir43jetggH =fout.mkdir("et_vbf_D0_Pito1p5m_ggH");
    dir44jetggH =fout.mkdir("et_vbf_D0_1p5to0_ggH");
    dir45jetggH =fout.mkdir("et_vbf_D0_0to1p5p_ggH");
    dir47jetggH =fout.mkdir("et_vbf_D0_1p5toPi_ggH");

    dir53jetggH =fout.mkdir("et_vbf_Pito1p6m_ggH");
    dir54jetggH =fout.mkdir("et_vbf_1p6to0_ggH");
    dir55jetggH =fout.mkdir("et_vbf_0to1p6p_ggH");
    dir57jetggH =fout.mkdir("et_vbf_1p6toPi_ggH");

    dir63jetggH =fout.mkdir("et_vbf_Pito1p6m_ggH_Uns");
    dir64jetggH =fout.mkdir("et_vbf_1p6to0_ggH_Uns");
    dir65jetggH =fout.mkdir("et_vbf_0to1p6p_ggH_Uns");
    dir67jetggH =fout.mkdir("et_vbf_1p6toPi_ggH_Uns");

    dir73jetggH =fout.mkdir("et_vbf_dPhia_ggH");
    dir74jetggH =fout.mkdir("et_vbf_dPhib_ggH");
    dir75jetggH =fout.mkdir("et_vbf_dPhic_ggH");
    dir77jetggH =fout.mkdir("et_vbf_dPhid_ggH");



    dir53jet=fout.mkdir("et_vbf_D0hplus_0p0to0p2")
    dir54jet=fout.mkdir("et_vbf_D0hplus_0p2to0p4")
    dir55jet=fout.mkdir("et_vbf_D0hplus_0p4to0p8")
    dir57jet=fout.mkdir("et_vbf_D0hplus_0p8to1p0")
    dir63jet=fout.mkdir("et_vbf_DL1_0p0to0p2")
    dir64jet=fout.mkdir("et_vbf_DL1_0p2to0p4")
    dir65jet=fout.mkdir("et_vbf_DL1_0p4to0p8")
    dir67jet=fout.mkdir("et_vbf_DL1_0p8to1p0")
    dir73jet=fout.mkdir("et_vbf_DL1Zg_0p0to0p2")
    dir74jet=fout.mkdir("et_vbf_DL1Zg_0p2to0p4")
    dir75jet=fout.mkdir("et_vbf_DL1Zg_0p4to0p8")
    dir77jet=fout.mkdir("et_vbf_DL1Zg_0p8to1p0")

    dirWCR0jet=fout.mkdir("et_wjets_0jet_cr")
    dirWCR1jet=fout.mkdir("et_wjets_boosted_cr")
    dirWCR2jet=fout.mkdir("et_wjets_vbf_cr")
    dirQCDCR0jet=fout.mkdir("et_antiiso_0jet_cr")
    dirQCDCR1jet=fout.mkdir("et_antiiso_boosted_cr")
    dirQCDCR2jet=fout.mkdir("et_antiiso_vbf_cr")

    nbhist=1
    if options.scale=="allJES":
       nbhist=56
    if options.scale=="allTES":
       nbhist=12

    for k in range(0,nbhist):
        hSS_0jet=fData.Get("SS0jet/data_obs")
	print "SS0jet/ZJ"+post2[k]
        hSS_0jet.Add(fDYJ.Get("SS0jet/ZJ"+post2[k]),-1)
        hSS_0jet.Add(fDYL.Get("SS0jet/ZL"+post2[k]),-1)
        hSS_0jet.Add(fTTJ.Get("SS0jet/TTJ"+post2[k]),-1)
        hSS_0jet.Add(fTTT.Get("SS0jet/TTT"+post2[k]),-1)
	print "SS0jet/W"+postfix0[k]
        hSS_0jet.Add(fW.Get("SS0jet/W"+postfix0[k]),-1)
        hSS_0jet.Add(fVV.Get("SS0jet/VV"+post2[k]),-1)
        hSS_0jet.Add(fDYS.Get("SS0jet/ZTT"+post2[k]),-1)
        hSS_0jet.SetName("QCD"+postfix0[k])
	print fData.Get("SS0jet/data_obs").Integral(),fDYJ.Get("SS0jet/ZJ"+post2[k]).Integral()+fDYL.Get("SS0jet/ZL"+post2[k]).Integral()+fDYS.Get("SS0jet/ZTT"+post2[k]).Integral(),fTTJ.Get("SS0jet/TTJ"+post2[k]).Integral()+fTTT.Get("SS0jet/TTT"+post2[k]).Integral(),fVV.Get("SS0jet/VV"+post2[k]).Integral(),fW.Get("SS0jet/W"+postfix0[k]).Integral()
        hSS_0jet.Scale(factor0jet)
        for i in range(0,hSS_0jet.GetSize()-2):
            if hSS_0jet.GetBinContent(i)<0:
                hSS_0jet.SetBinError(i,max(0,hSS_0jet.GetBinError(i)+hSS_0jet.GetBinError(i)))
                hSS_0jet.SetBinContent(i,0)

        hQCD_0jet=fData.Get("QCD0jet/data_obs")
        hQCD_0jet.Add(fDYJ.Get("QCD0jet/ZJ"+post2[k]),-1)
        hQCD_0jet.Add(fDYL.Get("QCD0jet/ZL"+post2[k]),-1)
        hQCD_0jet.Add(fTTJ.Get("QCD0jet/TTJ"+post2[k]),-1)
        hQCD_0jet.Add(fTTT.Get("QCD0jet/TTT"+post2[k]),-1)
        hQCD_0jet.Add(fW.Get("QCD0jet/W"+postfix0[k]),-1)
        hQCD_0jet.Add(fVV.Get("QCD0jet/VV"+post2[k]),-1)
        hQCD_0jet.Add(fDYS.Get("QCD0jet/ZTT"+post2[k]),-1)
        hQCD_0jet.SetName("QCD"+postfix0[k])
        hQCD_0jet.Scale(factor0jet)
        for i in range(0,hQCD_0jet.GetSize()-2):
            if hQCD_0jet.GetBinContent(i)<0:
                hQCD_0jet.SetBinError(i,max(0,hQCD_0jet.GetBinError(i)+hQCD_0jet.GetBinError(i)))
                hQCD_0jet.SetBinContent(i,0)

        hSS_1jet=fData.Get("SS1jet/data_obs")
        hSS_1jet.Add(fDYJ.Get("SS1jet/ZJ"+post2[k]),-1)
        hSS_1jet.Add(fDYL.Get("SS1jet/ZL"+post2[k]),-1)
        hSS_1jet.Add(fTTJ.Get("SS1jet/TTJ"+post2[k]),-1)
        hSS_1jet.Add(fTTT.Get("SS1jet/TTT"+post2[k]),-1)
        hSS_1jet.Add(fW.Get("SS1jet/W"+postfix1[k]),-1)
        hSS_1jet.Add(fVV.Get("SS1jet/VV"+post2[k]),-1)
        hSS_1jet.Add(fDYS.Get("SS1jet/ZTT"+post2[k]),-1)
        hSS_1jet.SetName("QCD"+postfix1[k])
        hSS_1jet.Scale(factor1jet)
        for i in range(0,hSS_1jet.GetSize()-2):
            if hSS_1jet.GetBinContent(i)<0:
                hSS_1jet.SetBinError(i,max(0,hSS_1jet.GetBinError(i)+hSS_1jet.GetBinError(i)))
                hSS_1jet.SetBinContent(i,0)

        hQCD_1jet=fData.Get("QCD1jet/data_obs")
        hQCD_1jet.Add(fDYJ.Get("QCD1jet/ZJ"+post2[k]),-1)
        hQCD_1jet.Add(fDYL.Get("QCD1jet/ZL"+post2[k]),-1)
        hQCD_1jet.Add(fTTJ.Get("QCD1jet/TTJ"+post2[k]),-1)
        hQCD_1jet.Add(fTTT.Get("QCD1jet/TTT"+post2[k]),-1)
        hQCD_1jet.Add(fW.Get("QCD1jet/W"+postfix1[k]),-1)
        hQCD_1jet.Add(fVV.Get("QCD1jet/VV"+post2[k]),-1)
        hQCD_1jet.Add(fDYS.Get("QCD1jet/ZTT"+post2[k]),-1)
        hQCD_1jet.SetName("QCD"+postfix1[k])
        hQCD_1jet.Scale(factor1jet)
        for i in range(0,hQCD_1jet.GetSize()-2):
            if hQCD_1jet.GetBinContent(i)<0:
                hQCD_1jet.SetBinError(i,max(0,hQCD_1jet.GetBinError(i)+hQCD_1jet.GetBinError(i)))
                hQCD_1jet.SetBinContent(i,0)

        hSS_2jet=fData.Get("SSvbf/data_obs")
        hSS_2jet.Add(fDYJ.Get("SSvbf/ZJ"+post2[k]),-1)
        hSS_2jet.Add(fDYL.Get("SSvbf/ZL"+post2[k]),-1)
        hSS_2jet.Add(fTTJ.Get("SSvbf/TTJ"+post2[k]),-1)
        hSS_2jet.Add(fTTT.Get("SSvbf/TTT"+post2[k]),-1)
        hSS_2jet.Add(fW.Get("SSvbf/W"+postfix2[k]),-1)
        hSS_2jet.Add(fVV.Get("SSvbf/VV"+post2[k]),-1)
        hSS_2jet.Add(fDYS.Get("SSvbf/ZTT"+post2[k]),-1)
        hSS_2jet.SetName("QCD"+postfix2[k])
        hSS_2jet.Scale(factor2jet)
        for i in range(0,hSS_2jet.GetSize()-2):
            if hSS_2jet.GetBinContent(i)<0:
                hSS_2jet.SetBinError(i,max(0,hSS_2jet.GetBinError(i)+hSS_2jet.GetBinError(i)))
                hSS_2jet.SetBinContent(i,0)

        hQCD_2jet=fData.Get("QCDvbf/data_obs")
        hQCD_2jet.Add(fDYJ.Get("QCDvbf/ZJ"+post2[k]),-1)
        hQCD_2jet.Add(fDYL.Get("QCDvbf/ZL"+post2[k]),-1)
        hQCD_2jet.Add(fTTJ.Get("QCDvbf/TTJ"+post2[k]),-1)
        hQCD_2jet.Add(fTTT.Get("QCDvbf/TTT"+post2[k]),-1)
        hQCD_2jet.Add(fW.Get("QCDvbf/W"+postfix2[k]),-1)
        hQCD_2jet.Add(fVV.Get("QCDvbf/VV"+post2[k]),-1)
        hQCD_2jet.Add(fDYS.Get("QCDvbf/ZTT"+post2[k]),-1)
        hQCD_2jet.SetName("QCD"+postfix2[k])
        hQCD_2jet.Scale(factor2jet)
        for i in range(0,hQCD_2jet.GetSize()-2):
            if hQCD_2jet.GetBinContent(i)<0:
                hQCD_2jet.SetBinError(i,max(0,hQCD_2jet.GetBinError(i)+hQCD_2jet.GetBinError(i)))
                hQCD_2jet.SetBinContent(i,0)

        hSS_3jet=fData.Get("SS3/data_obs")
        hSS_3jet.Add(fDYJ.Get("SS3/ZJ"+post2[k]),-1)
        hSS_3jet.Add(fDYL.Get("SS3/ZL"+post2[k]),-1)
        hSS_3jet.Add(fTTJ.Get("SS3/TTJ"+post2[k]),-1)
        hSS_3jet.Add(fTTT.Get("SS3/TTT"+post2[k]),-1)
        hSS_3jet.Add(fW.Get("SS3/W"+postfix2[k]),-1)
        hSS_3jet.Add(fVV.Get("SS3/VV"+post2[k]),-1)
        hSS_3jet.Add(fDYS.Get("SS3/ZTT"+post2[k]),-1)
        hSS_3jet.SetName("QCD"+postfix2[k])
        hSS_3jet.Scale(factor2jet)
        for i in range(0,hSS_3jet.GetSize()-2):
            if hSS_3jet.GetBinContent(i)<0:
                hSS_3jet.SetBinError(i,max(0,hSS_3jet.GetBinError(i)+hSS_3jet.GetBinError(i)))
                hSS_3jet.SetBinContent(i,0)

        hQCD_3jet=fData.Get("QCD3/data_obs")
        hQCD_3jet.Add(fDYJ.Get("QCD3/ZJ"+post2[k]),-1)
        hQCD_3jet.Add(fDYL.Get("QCD3/ZL"+post2[k]),-1)
        hQCD_3jet.Add(fTTJ.Get("QCD3/TTJ"+post2[k]),-1)
        hQCD_3jet.Add(fTTT.Get("QCD3/TTT"+post2[k]),-1)
        hQCD_3jet.Add(fW.Get("QCD3/W"+postfix2[k]),-1)
        hQCD_3jet.Add(fVV.Get("QCD3/VV"+post2[k]),-1)
        hQCD_3jet.Add(fDYS.Get("QCD3/ZTT"+post2[k]),-1)
        hQCD_3jet.SetName("QCD"+postfix2[k])
        hQCD_3jet.Scale(factor2jet)
        for i in range(0,hQCD_3jet.GetSize()-2):
            if hQCD_3jet.GetBinContent(i)<0:
                hQCD_3jet.SetBinError(i,max(0,hQCD_3jet.GetBinError(i)+hQCD_3jet.GetBinError(i)))
                hQCD_3jet.SetBinContent(i,0)


        hSS_53jet=fData.Get("SS53/data_obs")
        hSS_53jet.Add(fDYJ.Get("SS53/ZJ"+post2[k]),-1)
        hSS_53jet.Add(fDYL.Get("SS53/ZL"+post2[k]),-1)
        hSS_53jet.Add(fTTJ.Get("SS53/TTJ"+post2[k]),-1)
        hSS_53jet.Add(fTTT.Get("SS53/TTT"+post2[k]),-1)
        hSS_53jet.Add(fW.Get("SS53/W"+postfix2[k]),-1)
        hSS_53jet.Add(fVV.Get("SS53/VV"+post2[k]),-1)
        hSS_53jet.Add(fDYS.Get("SS53/ZTT"+post2[k]),-1)
        hSS_53jet.SetName("QCD"+postfix2[k])
        hSS_53jet.Scale(factor2jet)
        for i in range(0,hSS_53jet.GetSize()-2):
            if hSS_53jet.GetBinContent(i)<0:
                hSS_53jet.SetBinError(i,max(0,hSS_53jet.GetBinError(i)+hSS_53jet.GetBinError(i)))
                hSS_53jet.SetBinContent(i,0)

        hQCD_53jet=fData.Get("QCD53/data_obs")
        hQCD_53jet.Add(fDYJ.Get("QCD53/ZJ"+post2[k]),-1)
        hQCD_53jet.Add(fDYL.Get("QCD53/ZL"+post2[k]),-1)
        hQCD_53jet.Add(fTTJ.Get("QCD53/TTJ"+post2[k]),-1)
        hQCD_53jet.Add(fTTT.Get("QCD53/TTT"+post2[k]),-1)
        hQCD_53jet.Add(fW.Get("QCD53/W"+postfix2[k]),-1)
        hQCD_53jet.Add(fVV.Get("QCD53/VV"+post2[k]),-1)
        hQCD_53jet.Add(fDYS.Get("QCD53/ZTT"+post2[k]),-1)
        hQCD_53jet.SetName("QCD"+postfix2[k])
        hQCD_53jet.Scale(factor2jet)
        for i in range(0,hQCD_53jet.GetSize()-2):
            if hQCD_53jet.GetBinContent(i)<0:
                hQCD_53jet.SetBinError(i,max(0,hQCD_53jet.GetBinError(i)+hQCD_53jet.GetBinError(i)))
                hQCD_53jet.SetBinContent(i,0)

        hSS_63jet=fData.Get("SS63/data_obs")
        hSS_63jet.Add(fDYJ.Get("SS63/ZJ"+post2[k]),-1)
        hSS_63jet.Add(fDYL.Get("SS63/ZL"+post2[k]),-1)
        hSS_63jet.Add(fTTJ.Get("SS63/TTJ"+post2[k]),-1)
        hSS_63jet.Add(fTTT.Get("SS63/TTT"+post2[k]),-1)
        hSS_63jet.Add(fW.Get("SS63/W"+postfix2[k]),-1)
        hSS_63jet.Add(fVV.Get("SS63/VV"+post2[k]),-1)
        hSS_63jet.Add(fDYS.Get("SS63/ZTT"+post2[k]),-1)
        hSS_63jet.SetName("QCD"+postfix2[k])
        hSS_63jet.Scale(factor2jet)
        for i in range(0,hSS_63jet.GetSize()-2):
            if hSS_63jet.GetBinContent(i)<0:
                hSS_63jet.SetBinError(i,max(0,hSS_63jet.GetBinError(i)+hSS_63jet.GetBinError(i)))
                hSS_63jet.SetBinContent(i,0)

        hQCD_63jet=fData.Get("QCD63/data_obs")
        hQCD_63jet.Add(fDYJ.Get("QCD63/ZJ"+post2[k]),-1)
        hQCD_63jet.Add(fDYL.Get("QCD63/ZL"+post2[k]),-1)
        hQCD_63jet.Add(fTTJ.Get("QCD63/TTJ"+post2[k]),-1)
        hQCD_63jet.Add(fTTT.Get("QCD63/TTT"+post2[k]),-1)
        hQCD_63jet.Add(fW.Get("QCD63/W"+postfix2[k]),-1)
        hQCD_63jet.Add(fVV.Get("QCD63/VV"+post2[k]),-1)
        hQCD_63jet.Add(fDYS.Get("QCD63/ZTT"+post2[k]),-1)
        hQCD_63jet.SetName("QCD"+postfix2[k])
        hQCD_63jet.Scale(factor2jet)
        for i in range(0,hQCD_63jet.GetSize()-2):
            if hQCD_63jet.GetBinContent(i)<0:
                hQCD_63jet.SetBinError(i,max(0,hQCD_63jet.GetBinError(i)+hQCD_63jet.GetBinError(i)))
                hQCD_63jet.SetBinContent(i,0)

        hSS_73jet=fData.Get("SS73/data_obs")
        hSS_73jet.Add(fDYJ.Get("SS73/ZJ"+post2[k]),-1)
        hSS_73jet.Add(fDYL.Get("SS73/ZL"+post2[k]),-1)
        hSS_73jet.Add(fTTJ.Get("SS73/TTJ"+post2[k]),-1)
        hSS_73jet.Add(fTTT.Get("SS73/TTT"+post2[k]),-1)
        hSS_73jet.Add(fW.Get("SS73/W"+postfix2[k]),-1)
        hSS_73jet.Add(fVV.Get("SS73/VV"+post2[k]),-1)
        hSS_73jet.Add(fDYS.Get("SS73/ZTT"+post2[k]),-1)
        hSS_73jet.SetName("QCD"+postfix2[k])
        hSS_73jet.Scale(factor2jet)
        for i in range(0,hSS_73jet.GetSize()-2):
            if hSS_73jet.GetBinContent(i)<0:
                hSS_73jet.SetBinError(i,max(0,hSS_73jet.GetBinError(i)+hSS_73jet.GetBinError(i)))
                hSS_73jet.SetBinContent(i,0)

        hQCD_73jet=fData.Get("QCD73/data_obs")
        hQCD_73jet.Add(fDYJ.Get("QCD73/ZJ"+post2[k]),-1)
        hQCD_73jet.Add(fDYL.Get("QCD73/ZL"+post2[k]),-1)
        hQCD_73jet.Add(fTTJ.Get("QCD73/TTJ"+post2[k]),-1)
        hQCD_73jet.Add(fTTT.Get("QCD73/TTT"+post2[k]),-1)
        hQCD_73jet.Add(fW.Get("QCD73/W"+postfix2[k]),-1)
        hQCD_73jet.Add(fVV.Get("QCD73/VV"+post2[k]),-1)
        hQCD_73jet.Add(fDYS.Get("QCD73/ZTT"+post2[k]),-1)
        hQCD_73jet.SetName("QCD"+postfix2[k])
        hQCD_73jet.Scale(factor2jet)
        for i in range(0,hQCD_73jet.GetSize()-2):
            if hQCD_73jet.GetBinContent(i)<0:
                hQCD_73jet.SetBinError(i,max(0,hQCD_73jet.GetBinError(i)+hQCD_73jet.GetBinError(i)))
                hQCD_73jet.SetBinContent(i,0)

        hSS_4jet=fData.Get("SS4/data_obs")
        hSS_4jet.Add(fDYJ.Get("SS4/ZJ"+post2[k]),-1)
        hSS_4jet.Add(fDYL.Get("SS4/ZL"+post2[k]),-1)
        hSS_4jet.Add(fTTJ.Get("SS4/TTJ"+post2[k]),-1)
        hSS_4jet.Add(fTTT.Get("SS4/TTT"+post2[k]),-1)
        hSS_4jet.Add(fW.Get("SS4/W"+postfix2[k]),-1)
        hSS_4jet.Add(fVV.Get("SS4/VV"+post2[k]),-1)
        hSS_4jet.Add(fDYS.Get("SS4/ZTT"+post2[k]),-1)
        hSS_4jet.SetName("QCD"+postfix2[k])
        hSS_4jet.Scale(factor2jet)
        for i in range(0,hSS_4jet.GetSize()-2):
            if hSS_4jet.GetBinContent(i)<0:
                hSS_4jet.SetBinError(i,max(0,hSS_4jet.GetBinError(i)+hSS_4jet.GetBinError(i)))
                hSS_4jet.SetBinContent(i,0)

        hQCD_4jet=fData.Get("QCD4/data_obs")
        hQCD_4jet.Add(fDYJ.Get("QCD4/ZJ"+post2[k]),-1)
        hQCD_4jet.Add(fDYL.Get("QCD4/ZL"+post2[k]),-1)
        hQCD_4jet.Add(fTTJ.Get("QCD4/TTJ"+post2[k]),-1)
        hQCD_4jet.Add(fTTT.Get("QCD4/TTT"+post2[k]),-1)
        hQCD_4jet.Add(fW.Get("QCD4/W"+postfix2[k]),-1)
        hQCD_4jet.Add(fVV.Get("QCD4/VV"+post2[k]),-1)
        hQCD_4jet.Add(fDYS.Get("QCD4/ZTT"+post2[k]),-1)
        hQCD_4jet.SetName("QCD"+postfix2[k])
        hQCD_4jet.Scale(factor2jet)
        for i in range(0,hQCD_4jet.GetSize()-2):
            if hQCD_4jet.GetBinContent(i)<0:
                hQCD_4jet.SetBinError(i,max(0,hQCD_4jet.GetBinError(i)+hQCD_4jet.GetBinError(i)))
                hQCD_4jet.SetBinContent(i,0)

        hSS_54jet=fData.Get("SS54/data_obs")
        hSS_54jet.Add(fDYJ.Get("SS54/ZJ"+post2[k]),-1)
        hSS_54jet.Add(fDYL.Get("SS54/ZL"+post2[k]),-1)
        hSS_54jet.Add(fTTJ.Get("SS54/TTJ"+post2[k]),-1)
        hSS_54jet.Add(fTTT.Get("SS54/TTT"+post2[k]),-1)
        hSS_54jet.Add(fW.Get("SS54/W"+postfix2[k]),-1)
        hSS_54jet.Add(fVV.Get("SS54/VV"+post2[k]),-1)
        hSS_54jet.Add(fDYS.Get("SS54/ZTT"+post2[k]),-1)
        hSS_54jet.SetName("QCD"+postfix2[k])
        hSS_54jet.Scale(factor2jet)
        for i in range(0,hSS_54jet.GetSize()-2):
            if hSS_54jet.GetBinContent(i)<0:
                hSS_54jet.SetBinError(i,max(0,hSS_54jet.GetBinError(i)+hSS_54jet.GetBinError(i)))
                hSS_54jet.SetBinContent(i,0)

        hQCD_54jet=fData.Get("QCD54/data_obs")
        hQCD_54jet.Add(fDYJ.Get("QCD54/ZJ"+post2[k]),-1)
        hQCD_54jet.Add(fDYL.Get("QCD54/ZL"+post2[k]),-1)
        hQCD_54jet.Add(fTTJ.Get("QCD54/TTJ"+post2[k]),-1)
        hQCD_54jet.Add(fTTT.Get("QCD54/TTT"+post2[k]),-1)
        hQCD_54jet.Add(fW.Get("QCD54/W"+postfix2[k]),-1)
        hQCD_54jet.Add(fVV.Get("QCD54/VV"+post2[k]),-1)
        hQCD_54jet.Add(fDYS.Get("QCD54/ZTT"+post2[k]),-1)
        hQCD_54jet.SetName("QCD"+postfix2[k])
        hQCD_54jet.Scale(factor2jet)
        for i in range(0,hQCD_54jet.GetSize()-2):
            if hQCD_54jet.GetBinContent(i)<0:
                hQCD_54jet.SetBinError(i,max(0,hQCD_54jet.GetBinError(i)+hQCD_54jet.GetBinError(i)))
                hQCD_54jet.SetBinContent(i,0)

        hSS_64jet=fData.Get("SS64/data_obs")
        hSS_64jet.Add(fDYJ.Get("SS64/ZJ"+post2[k]),-1)
        hSS_64jet.Add(fDYL.Get("SS64/ZL"+post2[k]),-1)
        hSS_64jet.Add(fTTJ.Get("SS64/TTJ"+post2[k]),-1)
        hSS_64jet.Add(fTTT.Get("SS64/TTT"+post2[k]),-1)
        hSS_64jet.Add(fW.Get("SS64/W"+postfix2[k]),-1)
        hSS_64jet.Add(fVV.Get("SS64/VV"+post2[k]),-1)
        hSS_64jet.Add(fDYS.Get("SS64/ZTT"+post2[k]),-1)
        hSS_64jet.SetName("QCD"+postfix2[k])
        hSS_64jet.Scale(factor2jet)
        for i in range(0,hSS_64jet.GetSize()-2):
            if hSS_64jet.GetBinContent(i)<0:
                hSS_64jet.SetBinError(i,max(0,hSS_64jet.GetBinError(i)+hSS_64jet.GetBinError(i)))
                hSS_64jet.SetBinContent(i,0)

        hQCD_64jet=fData.Get("QCD64/data_obs")
        hQCD_64jet.Add(fDYJ.Get("QCD64/ZJ"+post2[k]),-1)
        hQCD_64jet.Add(fDYL.Get("QCD64/ZL"+post2[k]),-1)
        hQCD_64jet.Add(fTTJ.Get("QCD64/TTJ"+post2[k]),-1)
        hQCD_64jet.Add(fTTT.Get("QCD64/TTT"+post2[k]),-1)
        hQCD_64jet.Add(fW.Get("QCD64/W"+postfix2[k]),-1)
        hQCD_64jet.Add(fVV.Get("QCD64/VV"+post2[k]),-1)
        hQCD_64jet.Add(fDYS.Get("QCD64/ZTT"+post2[k]),-1)
        hQCD_64jet.SetName("QCD"+postfix2[k])
        hQCD_64jet.Scale(factor2jet)
        for i in range(0,hQCD_64jet.GetSize()-2):
            if hQCD_64jet.GetBinContent(i)<0:
                hQCD_64jet.SetBinError(i,max(0,hQCD_64jet.GetBinError(i)+hQCD_64jet.GetBinError(i)))
                hQCD_64jet.SetBinContent(i,0)

        hSS_74jet=fData.Get("SS74/data_obs")
        hSS_74jet.Add(fDYJ.Get("SS74/ZJ"+post2[k]),-1)
        hSS_74jet.Add(fDYL.Get("SS74/ZL"+post2[k]),-1)
        hSS_74jet.Add(fTTJ.Get("SS74/TTJ"+post2[k]),-1)
        hSS_74jet.Add(fTTT.Get("SS74/TTT"+post2[k]),-1)
        hSS_74jet.Add(fW.Get("SS74/W"+postfix2[k]),-1)
        hSS_74jet.Add(fVV.Get("SS74/VV"+post2[k]),-1)
        hSS_74jet.Add(fDYS.Get("SS74/ZTT"+post2[k]),-1)
        hSS_74jet.SetName("QCD"+postfix2[k])
        hSS_74jet.Scale(factor2jet)
        for i in range(0,hSS_74jet.GetSize()-2):
            if hSS_74jet.GetBinContent(i)<0:
                hSS_74jet.SetBinError(i,max(0,hSS_74jet.GetBinError(i)+hSS_74jet.GetBinError(i)))
                hSS_74jet.SetBinContent(i,0)

        hQCD_74jet=fData.Get("QCD74/data_obs")
        hQCD_74jet.Add(fDYJ.Get("QCD74/ZJ"+post2[k]),-1)
        hQCD_74jet.Add(fDYL.Get("QCD74/ZL"+post2[k]),-1)
        hQCD_74jet.Add(fTTJ.Get("QCD74/TTJ"+post2[k]),-1)
        hQCD_74jet.Add(fTTT.Get("QCD74/TTT"+post2[k]),-1)
        hQCD_74jet.Add(fW.Get("QCD74/W"+postfix2[k]),-1)
        hQCD_74jet.Add(fVV.Get("QCD74/VV"+post2[k]),-1)
        hQCD_74jet.Add(fDYS.Get("QCD74/ZTT"+post2[k]),-1)
        hQCD_74jet.SetName("QCD"+postfix2[k])
        hQCD_74jet.Scale(factor2jet)
        for i in range(0,hQCD_74jet.GetSize()-2):
            if hQCD_74jet.GetBinContent(i)<0:
                hQCD_74jet.SetBinError(i,max(0,hQCD_74jet.GetBinError(i)+hQCD_74jet.GetBinError(i)))
                hQCD_74jet.SetBinContent(i,0)

        hSS_5jet=fData.Get("SS5/data_obs")
        hSS_5jet.Add(fDYJ.Get("SS5/ZJ"+post2[k]),-1)
        hSS_5jet.Add(fDYL.Get("SS5/ZL"+post2[k]),-1)
        hSS_5jet.Add(fTTJ.Get("SS5/TTJ"+post2[k]),-1)
        hSS_5jet.Add(fTTT.Get("SS5/TTT"+post2[k]),-1)
        hSS_5jet.Add(fW.Get("SS5/W"+postfix2[k]),-1)
        hSS_5jet.Add(fVV.Get("SS5/VV"+post2[k]),-1)
        hSS_5jet.Add(fDYS.Get("SS5/ZTT"+post2[k]),-1)
        hSS_5jet.SetName("QCD"+postfix2[k])
        hSS_5jet.Scale(factor2jet)
        for i in range(0,hSS_5jet.GetSize()-2):
            if hSS_5jet.GetBinContent(i)<0:
                hSS_5jet.SetBinError(i,max(0,hSS_5jet.GetBinError(i)+hSS_5jet.GetBinError(i)))
                hSS_5jet.SetBinContent(i,0)

        hQCD_5jet=fData.Get("QCD5/data_obs")
        hQCD_5jet.Add(fDYJ.Get("QCD5/ZJ"+post2[k]),-1)
        hQCD_5jet.Add(fDYL.Get("QCD5/ZL"+post2[k]),-1)
        hQCD_5jet.Add(fTTJ.Get("QCD5/TTJ"+post2[k]),-1)
        hQCD_5jet.Add(fTTT.Get("QCD5/TTT"+post2[k]),-1)
        hQCD_5jet.Add(fW.Get("QCD5/W"+postfix2[k]),-1)
        hQCD_5jet.Add(fVV.Get("QCD5/VV"+post2[k]),-1)
        hQCD_5jet.Add(fDYS.Get("QCD5/ZTT"+post2[k]),-1)
        hQCD_5jet.SetName("QCD"+postfix2[k])
        hQCD_5jet.Scale(factor2jet)
        for i in range(0,hQCD_5jet.GetSize()-2):
            if hQCD_5jet.GetBinContent(i)<0:
                hQCD_5jet.SetBinError(i,max(0,hQCD_5jet.GetBinError(i)+hQCD_5jet.GetBinError(i)))
                hQCD_5jet.SetBinContent(i,0)

        hSS_55jet=fData.Get("SS5/data_obs")
        hSS_55jet.Add(fDYJ.Get("SS5/ZJ"+post2[k]),-1)
        hSS_55jet.Add(fDYL.Get("SS5/ZL"+post2[k]),-1)
        hSS_55jet.Add(fTTJ.Get("SS5/TTJ"+post2[k]),-1)
        hSS_55jet.Add(fTTT.Get("SS5/TTT"+post2[k]),-1)
        hSS_55jet.Add(fW.Get("SS5/W"+postfix2[k]),-1)
        hSS_55jet.Add(fVV.Get("SS5/VV"+post2[k]),-1)
        hSS_55jet.Add(fDYS.Get("SS5/ZTT"+post2[k]),-1)
        hSS_55jet.SetName("QCD"+postfix2[k])
        hSS_55jet.Scale(factor2jet)
        for i in range(0,hSS_55jet.GetSize()-2):
            if hSS_55jet.GetBinContent(i)<0:
                hSS_55jet.SetBinError(i,max(0,hSS_55jet.GetBinError(i)+hSS_55jet.GetBinError(i)))
                hSS_55jet.SetBinContent(i,0)

        hQCD_55jet=fData.Get("QCD55/data_obs")
        hQCD_55jet.Add(fDYJ.Get("QCD55/ZJ"+post2[k]),-1)
        hQCD_55jet.Add(fDYL.Get("QCD55/ZL"+post2[k]),-1)
        hQCD_55jet.Add(fTTJ.Get("QCD55/TTJ"+post2[k]),-1)
        hQCD_55jet.Add(fTTT.Get("QCD55/TTT"+post2[k]),-1)
        hQCD_55jet.Add(fW.Get("QCD55/W"+postfix2[k]),-1)
        hQCD_55jet.Add(fVV.Get("QCD55/VV"+post2[k]),-1)
        hQCD_55jet.Add(fDYS.Get("QCD55/ZTT"+post2[k]),-1)
        hQCD_55jet.SetName("QCD"+postfix2[k])
        hQCD_55jet.Scale(factor2jet)
        for i in range(0,hQCD_55jet.GetSize()-2):
            if hQCD_55jet.GetBinContent(i)<0:
                hQCD_55jet.SetBinError(i,max(0,hQCD_55jet.GetBinError(i)+hQCD_55jet.GetBinError(i)))
                hQCD_55jet.SetBinContent(i,0)

        hSS_65jet=fData.Get("SS65/data_obs")
        hSS_65jet.Add(fDYJ.Get("SS65/ZJ"+post2[k]),-1)
        hSS_65jet.Add(fDYL.Get("SS65/ZL"+post2[k]),-1)
        hSS_65jet.Add(fTTJ.Get("SS65/TTJ"+post2[k]),-1)
        hSS_65jet.Add(fTTT.Get("SS65/TTT"+post2[k]),-1)
        hSS_65jet.Add(fW.Get("SS65/W"+postfix2[k]),-1)
        hSS_65jet.Add(fVV.Get("SS65/VV"+post2[k]),-1)
        hSS_65jet.Add(fDYS.Get("SS65/ZTT"+post2[k]),-1)
        hSS_65jet.SetName("QCD"+postfix2[k])
        hSS_65jet.Scale(factor2jet)
        for i in range(0,hSS_65jet.GetSize()-2):
            if hSS_65jet.GetBinContent(i)<0:
                hSS_65jet.SetBinError(i,max(0,hSS_65jet.GetBinError(i)+hSS_65jet.GetBinError(i)))
                hSS_65jet.SetBinContent(i,0)

        hQCD_65jet=fData.Get("QCD65/data_obs")
        hQCD_65jet.Add(fDYJ.Get("QCD65/ZJ"+post2[k]),-1)
        hQCD_65jet.Add(fDYL.Get("QCD65/ZL"+post2[k]),-1)
        hQCD_65jet.Add(fTTJ.Get("QCD65/TTJ"+post2[k]),-1)
        hQCD_65jet.Add(fTTT.Get("QCD65/TTT"+post2[k]),-1)
        hQCD_65jet.Add(fW.Get("QCD65/W"+postfix2[k]),-1)
        hQCD_65jet.Add(fVV.Get("QCD65/VV"+post2[k]),-1)
        hQCD_65jet.Add(fDYS.Get("QCD65/ZTT"+post2[k]),-1)
        hQCD_65jet.SetName("QCD"+postfix2[k])
        hQCD_65jet.Scale(factor2jet)
        for i in range(0,hQCD_65jet.GetSize()-2):
            if hQCD_65jet.GetBinContent(i)<0:
                hQCD_65jet.SetBinError(i,max(0,hQCD_65jet.GetBinError(i)+hQCD_65jet.GetBinError(i)))
                hQCD_65jet.SetBinContent(i,0)

        hSS_75jet=fData.Get("SS75/data_obs")
        hSS_75jet.Add(fDYJ.Get("SS75/ZJ"+post2[k]),-1)
        hSS_75jet.Add(fDYL.Get("SS75/ZL"+post2[k]),-1)
        hSS_75jet.Add(fTTJ.Get("SS75/TTJ"+post2[k]),-1)
        hSS_75jet.Add(fTTT.Get("SS75/TTT"+post2[k]),-1)
        hSS_75jet.Add(fW.Get("SS75/W"+postfix2[k]),-1)
        hSS_75jet.Add(fVV.Get("SS75/VV"+post2[k]),-1)
        hSS_75jet.Add(fDYS.Get("SS75/ZTT"+post2[k]),-1)
        hSS_75jet.SetName("QCD"+postfix2[k])
        hSS_75jet.Scale(factor2jet)
        for i in range(0,hSS_75jet.GetSize()-2):
            if hSS_75jet.GetBinContent(i)<0:
                hSS_75jet.SetBinError(i,max(0,hSS_75jet.GetBinError(i)+hSS_75jet.GetBinError(i)))
                hSS_75jet.SetBinContent(i,0)

        hQCD_75jet=fData.Get("QCD75/data_obs")
        hQCD_75jet.Add(fDYJ.Get("QCD75/ZJ"+post2[k]),-1)
        hQCD_75jet.Add(fDYL.Get("QCD75/ZL"+post2[k]),-1)
        hQCD_75jet.Add(fTTJ.Get("QCD75/TTJ"+post2[k]),-1)
        hQCD_75jet.Add(fTTT.Get("QCD75/TTT"+post2[k]),-1)
        hQCD_75jet.Add(fW.Get("QCD75/W"+postfix2[k]),-1)
        hQCD_75jet.Add(fVV.Get("QCD75/VV"+post2[k]),-1)
        hQCD_75jet.Add(fDYS.Get("QCD75/ZTT"+post2[k]),-1)
        hQCD_75jet.SetName("QCD"+postfix2[k])
        hQCD_75jet.Scale(factor2jet)
        for i in range(0,hQCD_75jet.GetSize()-2):
            if hQCD_75jet.GetBinContent(i)<0:
                hQCD_75jet.SetBinError(i,max(0,hQCD_75jet.GetBinError(i)+hQCD_75jet.GetBinError(i)))
                hQCD_75jet.SetBinContent(i,0)

        hSS_7jet=fData.Get("SS7/data_obs")
        hSS_7jet.Add(fDYJ.Get("SS7/ZJ"+post2[k]),-1)
        hSS_7jet.Add(fDYL.Get("SS7/ZL"+post2[k]),-1)
        hSS_7jet.Add(fTTJ.Get("SS7/TTJ"+post2[k]),-1)
        hSS_7jet.Add(fTTT.Get("SS7/TTT"+post2[k]),-1)
        hSS_7jet.Add(fW.Get("SS7/W"+postfix2[k]),-1)
        hSS_7jet.Add(fVV.Get("SS7/VV"+post2[k]),-1)
        hSS_7jet.Add(fDYS.Get("SS7/ZTT"+post2[k]),-1)
        hSS_7jet.SetName("QCD"+postfix2[k])
        hSS_7jet.Scale(factor2jet)
        for i in range(0,hSS_7jet.GetSize()-2):
            if hSS_7jet.GetBinContent(i)<0:
                hSS_7jet.SetBinError(i,max(0,hSS_7jet.GetBinError(i)+hSS_7jet.GetBinError(i)))
                hSS_7jet.SetBinContent(i,0)

        hQCD_7jet=fData.Get("QCD7/data_obs")
        hQCD_7jet.Add(fDYJ.Get("QCD7/ZJ"+post2[k]),-1)
        hQCD_7jet.Add(fDYL.Get("QCD7/ZL"+post2[k]),-1)
        hQCD_7jet.Add(fTTJ.Get("QCD7/TTJ"+post2[k]),-1)
        hQCD_7jet.Add(fTTT.Get("QCD7/TTT"+post2[k]),-1)
        hQCD_7jet.Add(fW.Get("QCD7/W"+postfix2[k]),-1)
        hQCD_7jet.Add(fVV.Get("QCD7/VV"+post2[k]),-1)
        hQCD_7jet.Add(fDYS.Get("QCD7/ZTT"+post2[k]),-1)
        hQCD_7jet.SetName("QCD"+postfix2[k])
        hQCD_7jet.Scale(factor2jet)
        for i in range(0,hQCD_7jet.GetSize()-2):
            if hQCD_7jet.GetBinContent(i)<0:
                hQCD_7jet.SetBinError(i,max(0,hQCD_7jet.GetBinError(i)+hQCD_7jet.GetBinError(i)))
                hQCD_7jet.SetBinContent(i,0)

        hSS_57jet=fData.Get("SS57/data_obs")
        hSS_57jet.Add(fDYJ.Get("SS57/ZJ"+post2[k]),-1)
        hSS_57jet.Add(fDYL.Get("SS57/ZL"+post2[k]),-1)
        hSS_57jet.Add(fTTJ.Get("SS57/TTJ"+post2[k]),-1)
        hSS_57jet.Add(fTTT.Get("SS57/TTT"+post2[k]),-1)
        hSS_57jet.Add(fW.Get("SS57/W"+postfix2[k]),-1)
        hSS_57jet.Add(fVV.Get("SS57/VV"+post2[k]),-1)
        hSS_57jet.Add(fDYS.Get("SS57/ZTT"+post2[k]),-1)
        hSS_57jet.SetName("QCD"+postfix2[k])
        hSS_57jet.Scale(factor2jet)
        for i in range(0,hSS_57jet.GetSize()-2):
            if hSS_57jet.GetBinContent(i)<0:
                hSS_57jet.SetBinError(i,max(0,hSS_57jet.GetBinError(i)+hSS_57jet.GetBinError(i)))
                hSS_57jet.SetBinContent(i,0)

        hQCD_57jet=fData.Get("QCD57/data_obs")
        hQCD_57jet.Add(fDYJ.Get("QCD57/ZJ"+post2[k]),-1)
        hQCD_57jet.Add(fDYL.Get("QCD57/ZL"+post2[k]),-1)
        hQCD_57jet.Add(fTTJ.Get("QCD57/TTJ"+post2[k]),-1)
        hQCD_57jet.Add(fTTT.Get("QCD57/TTT"+post2[k]),-1)
        hQCD_57jet.Add(fW.Get("QCD57/W"+postfix2[k]),-1)
        hQCD_57jet.Add(fVV.Get("QCD57/VV"+post2[k]),-1)
        hQCD_57jet.Add(fDYS.Get("QCD57/ZTT"+post2[k]),-1)
        hQCD_57jet.SetName("QCD"+postfix2[k])
        hQCD_57jet.Scale(factor2jet)
        for i in range(0,hQCD_57jet.GetSize()-2):
            if hQCD_57jet.GetBinContent(i)<0:
                hQCD_57jet.SetBinError(i,max(0,hQCD_57jet.GetBinError(i)+hQCD_57jet.GetBinError(i)))
                hQCD_57jet.SetBinContent(i,0)

        hSS_67jet=fData.Get("SS67/data_obs")
        hSS_67jet.Add(fDYJ.Get("SS67/ZJ"+post2[k]),-1)
        hSS_67jet.Add(fDYL.Get("SS67/ZL"+post2[k]),-1)
        hSS_67jet.Add(fTTJ.Get("SS67/TTJ"+post2[k]),-1)
        hSS_67jet.Add(fTTT.Get("SS67/TTT"+post2[k]),-1)
        hSS_67jet.Add(fW.Get("SS67/W"+postfix2[k]),-1)
        hSS_67jet.Add(fVV.Get("SS67/VV"+post2[k]),-1)
        hSS_67jet.Add(fDYS.Get("SS67/ZTT"+post2[k]),-1)
        hSS_67jet.SetName("QCD"+postfix2[k])
        hSS_67jet.Scale(factor2jet)
        for i in range(0,hSS_67jet.GetSize()-2):
            if hSS_67jet.GetBinContent(i)<0:
                hSS_67jet.SetBinError(i,max(0,hSS_67jet.GetBinError(i)+hSS_67jet.GetBinError(i)))
                hSS_67jet.SetBinContent(i,0)

        hQCD_67jet=fData.Get("QCD67/data_obs")
        hQCD_67jet.Add(fDYJ.Get("QCD67/ZJ"+post2[k]),-1)
        hQCD_67jet.Add(fDYL.Get("QCD67/ZL"+post2[k]),-1)
        hQCD_67jet.Add(fTTJ.Get("QCD67/TTJ"+post2[k]),-1)
        hQCD_67jet.Add(fTTT.Get("QCD67/TTT"+post2[k]),-1)
        hQCD_67jet.Add(fW.Get("QCD67/W"+postfix2[k]),-1)
        hQCD_67jet.Add(fVV.Get("QCD67/VV"+post2[k]),-1)
        hQCD_67jet.Add(fDYS.Get("QCD67/ZTT"+post2[k]),-1)
        hQCD_67jet.SetName("QCD"+postfix2[k])
        hQCD_67jet.Scale(factor2jet)
        for i in range(0,hQCD_67jet.GetSize()-2):
            if hQCD_67jet.GetBinContent(i)<0:
                hQCD_67jet.SetBinError(i,max(0,hQCD_67jet.GetBinError(i)+hQCD_67jet.GetBinError(i)))
                hQCD_67jet.SetBinContent(i,0)

        hSS_77jet=fData.Get("SS77/data_obs")
        hSS_77jet.Add(fDYJ.Get("SS77/ZJ"+post2[k]),-1)
        hSS_77jet.Add(fDYL.Get("SS77/ZL"+post2[k]),-1)
        hSS_77jet.Add(fTTJ.Get("SS77/TTJ"+post2[k]),-1)
        hSS_77jet.Add(fTTT.Get("SS77/TTT"+post2[k]),-1)
        hSS_77jet.Add(fW.Get("SS77/W"+postfix2[k]),-1)
        hSS_77jet.Add(fVV.Get("SS77/VV"+post2[k]),-1)
        hSS_77jet.Add(fDYS.Get("SS77/ZTT"+post2[k]),-1)
        hSS_77jet.SetName("QCD"+postfix2[k])
        hSS_77jet.Scale(factor2jet)
        for i in range(0,hSS_77jet.GetSize()-2):
            if hSS_77jet.GetBinContent(i)<0:
                hSS_77jet.SetBinError(i,max(0,hSS_77jet.GetBinError(i)+hSS_77jet.GetBinError(i)))
                hSS_77jet.SetBinContent(i,0)

        hQCD_77jet=fData.Get("QCD77/data_obs")
        hQCD_77jet.Add(fDYJ.Get("QCD77/ZJ"+post2[k]),-1)
        hQCD_77jet.Add(fDYL.Get("QCD77/ZL"+post2[k]),-1)
        hQCD_77jet.Add(fTTJ.Get("QCD77/TTJ"+post2[k]),-1)
        hQCD_77jet.Add(fTTT.Get("QCD77/TTT"+post2[k]),-1)
        hQCD_77jet.Add(fW.Get("QCD77/W"+postfix2[k]),-1)
        hQCD_77jet.Add(fVV.Get("QCD77/VV"+post2[k]),-1)
        hQCD_77jet.Add(fDYS.Get("QCD77/ZTT"+post2[k]),-1)
        hQCD_77jet.SetName("QCD"+postfix2[k])
        hQCD_77jet.Scale(factor2jet)
        for i in range(0,hQCD_77jet.GetSize()-2):
            if hQCD_77jet.GetBinContent(i)<0:
                hQCD_77jet.SetBinError(i,max(0,hQCD_77jet.GetBinError(i)+hQCD_77jet.GetBinError(i)))
                hQCD_77jet.SetBinContent(i,0)
"""
########################3

        hSS_3jetggH=fData.Get("SS3ggH/data_obs")
        hSS_3jetggH.Add(fDYJ.Get("SS3ggH/ZJ"+post2[k]),-1)
        hSS_3jetggH.Add(fDYL.Get("SS3ggH/ZL"+post2[k]),-1)
        hSS_3jetggH.Add(fTTJ.Get("SS3ggH/TTJ"+post2[k]),-1)
        hSS_3jetggH.Add(fTTT.Get("SS3ggH/TTT"+post2[k]),-1)
        hSS_3jetggH.Add(fW.Get("SS3ggH/W"+postfix2[k]),-1)
        hSS_3jetggH.Add(fVV.Get("SS3ggH/VV"+post2[k]),-1)
        hSS_3jetggH.Add(fDYS.Get("SS3ggH/ZTT"+post2[k]),-1)
        hSS_3jetggH.SetName("QCD"+postfix2[k])
        hSS_3jetggH.Scale(factor2jet)
        for i in range(0,hSS_3jetggH.GetSize()-2):
            if hSS_3jetggH.GetBinContent(i)<0:
                hSS_3jetggH.SetBinError(i,max(0,hSS_3jetggH.GetBinError(i)+hSS_3jetggH.GetBinError(i)))
                hSS_3jetggH.SetBinContent(i,0)

        hQCD_3jetggH=fData.Get("QCD3ggH/data_obs")
        hQCD_3jetggH.Add(fDYJ.Get("QCD3ggH/ZJ"+post2[k]),-1)
        hQCD_3jetggH.Add(fDYL.Get("QCD3ggH/ZL"+post2[k]),-1)
        hQCD_3jetggH.Add(fTTJ.Get("QCD3ggH/TTJ"+post2[k]),-1)
        hQCD_3jetggH.Add(fTTT.Get("QCD3ggH/TTT"+post2[k]),-1)
        hQCD_3jetggH.Add(fW.Get("QCD3ggH/W"+postfix2[k]),-1)
        hQCD_3jetggH.Add(fVV.Get("QCD3ggH/VV"+post2[k]),-1)
        hQCD_3jetggH.Add(fDYS.Get("QCD3ggH/ZTT"+post2[k]),-1)
        hQCD_3jetggH.SetName("QCD"+postfix2[k])
        hQCD_3jetggH.Scale(factor2jet)
        for i in range(0,hQCD_3jetggH.GetSize()-2):
            if hQCD_3jetggH.GetBinContent(i)<0:
                hQCD_3jetggH.SetBinError(i,max(0,hQCD_3jetggH.GetBinError(i)+hQCD_3jetggH.GetBinError(i)))
                hQCD_3jetggH.SetBinContent(i,0)

        hSS_33jetggH=fData.Get("SS33ggH/data_obs")
        hSS_33jetggH.Add(fDYJ.Get("SS33ggH/ZJ"+post2[k]),-1)
        hSS_33jetggH.Add(fDYL.Get("SS33ggH/ZL"+post2[k]),-1)
        hSS_33jetggH.Add(fTTJ.Get("SS33ggH/TTJ"+post2[k]),-1)
        hSS_33jetggH.Add(fTTT.Get("SS33ggH/TTT"+post2[k]),-1)
        hSS_33jetggH.Add(fW.Get("SS33ggH/W"+postfix2[k]),-1)
        hSS_33jetggH.Add(fVV.Get("SS33ggH/VV"+post2[k]),-1)
        hSS_33jetggH.Add(fDYS.Get("SS33ggH/ZTT"+post2[k]),-1)
        hSS_33jetggH.SetName("QCD"+postfix2[k])
        hSS_33jetggH.Scale(factor2jet)
        for i in range(0,hSS_33jetggH.GetSize()-2):
            if hSS_33jetggH.GetBinContent(i)<0:
                hSS_33jetggH.SetBinError(i,max(0,hSS_33jetggH.GetBinError(i)+hSS_33jetggH.GetBinError(i)))
                hSS_33jetggH.SetBinContent(i,0)

        hQCD_33jetggH=fData.Get("QCD33ggH/data_obs")
        hQCD_33jetggH.Add(fDYJ.Get("QCD33ggH/ZJ"+post2[k]),-1)
        hQCD_33jetggH.Add(fDYL.Get("QCD33ggH/ZL"+post2[k]),-1)
        hQCD_33jetggH.Add(fTTJ.Get("QCD33ggH/TTJ"+post2[k]),-1)
        hQCD_33jetggH.Add(fTTT.Get("QCD33ggH/TTT"+post2[k]),-1)
        hQCD_33jetggH.Add(fW.Get("QCD33ggH/W"+postfix2[k]),-1)
        hQCD_33jetggH.Add(fVV.Get("QCD33ggH/VV"+post2[k]),-1)
        hQCD_33jetggH.Add(fDYS.Get("QCD33ggH/ZTT"+post2[k]),-1)
        hQCD_33jetggH.SetName("QCD"+postfix2[k])
        hQCD_33jetggH.Scale(factor2jet)
        for i in range(0,hQCD_33jetggH.GetSize()-2):
            if hQCD_33jetggH.GetBinContent(i)<0:
                hQCD_33jetggH.SetBinError(i,max(0,hQCD_33jetggH.GetBinError(i)+hQCD_33jetggH.GetBinError(i)))
                hQCD_33jetggH.SetBinContent(i,0)


        hSS_43jetggH=fData.Get("SS43ggH/data_obs")
        hSS_43jetggH.Add(fDYJ.Get("SS43ggH/ZJ"+post2[k]),-1)
        hSS_43jetggH.Add(fDYL.Get("SS43ggH/ZL"+post2[k]),-1)
        hSS_43jetggH.Add(fTTJ.Get("SS43ggH/TTJ"+post2[k]),-1)
        hSS_43jetggH.Add(fTTT.Get("SS43ggH/TTT"+post2[k]),-1)
        hSS_43jetggH.Add(fW.Get("SS43ggH/W"+postfix2[k]),-1)
        hSS_43jetggH.Add(fVV.Get("SS43ggH/VV"+post2[k]),-1)
        hSS_43jetggH.Add(fDYS.Get("SS43ggH/ZTT"+post2[k]),-1)
        hSS_43jetggH.SetName("QCD"+postfix2[k])
        hSS_43jetggH.Scale(factor2jet)
        for i in range(0,hSS_43jetggH.GetSize()-2):
            if hSS_43jetggH.GetBinContent(i)<0:
                hSS_43jetggH.SetBinError(i,max(0,hSS_43jetggH.GetBinError(i)+hSS_43jetggH.GetBinError(i)))
                hSS_43jetggH.SetBinContent(i,0)

        hQCD_43jetggH=fData.Get("QCD43ggH/data_obs")
        hQCD_43jetggH.Add(fDYJ.Get("QCD43ggH/ZJ"+post2[k]),-1)
        hQCD_43jetggH.Add(fDYL.Get("QCD43ggH/ZL"+post2[k]),-1)
        hQCD_43jetggH.Add(fTTJ.Get("QCD43ggH/TTJ"+post2[k]),-1)
        hQCD_43jetggH.Add(fTTT.Get("QCD43ggH/TTT"+post2[k]),-1)
        hQCD_43jetggH.Add(fW.Get("QCD43ggH/W"+postfix2[k]),-1)
        hQCD_43jetggH.Add(fVV.Get("QCD43ggH/VV"+post2[k]),-1)
        hQCD_43jetggH.Add(fDYS.Get("QCD43ggH/ZTT"+post2[k]),-1)
        hQCD_43jetggH.SetName("QCD"+postfix2[k])
        hQCD_43jetggH.Scale(factor2jet)
        for i in range(0,hQCD_43jetggH.GetSize()-2):
            if hQCD_43jetggH.GetBinContent(i)<0:
                hQCD_43jetggH.SetBinError(i,max(0,hQCD_43jetggH.GetBinError(i)+hQCD_43jetggH.GetBinError(i)))
                hQCD_43jetggH.SetBinContent(i,0)



        hSS_53jetggH=fData.Get("SS53ggH/data_obs")
        hSS_53jetggH.Add(fDYJ.Get("SS53ggH/ZJ"+post2[k]),-1)
        hSS_53jetggH.Add(fDYL.Get("SS53ggH/ZL"+post2[k]),-1)
        hSS_53jetggH.Add(fTTJ.Get("SS53ggH/TTJ"+post2[k]),-1)
        hSS_53jetggH.Add(fTTT.Get("SS53ggH/TTT"+post2[k]),-1)
        hSS_53jetggH.Add(fW.Get("SS53ggH/W"+postfix2[k]),-1)
        hSS_53jetggH.Add(fVV.Get("SS53ggH/VV"+post2[k]),-1)
        hSS_53jetggH.Add(fDYS.Get("SS53ggH/ZTT"+post2[k]),-1)
        hSS_53jetggH.SetName("QCD"+postfix2[k])
        hSS_53jetggH.Scale(factor2jet)
        for i in range(0,hSS_53jetggH.GetSize()-2):
            if hSS_53jetggH.GetBinContent(i)<0:
                hSS_53jetggH.SetBinError(i,max(0,hSS_53jetggH.GetBinError(i)+hSS_53jetggH.GetBinError(i)))
                hSS_53jetggH.SetBinContent(i,0)

        hQCD_53jetggH=fData.Get("QCD53ggH/data_obs")
        hQCD_53jetggH.Add(fDYJ.Get("QCD53ggH/ZJ"+post2[k]),-1)
        hQCD_53jetggH.Add(fDYL.Get("QCD53ggH/ZL"+post2[k]),-1)
        hQCD_53jetggH.Add(fTTJ.Get("QCD53ggH/TTJ"+post2[k]),-1)
        hQCD_53jetggH.Add(fTTT.Get("QCD53ggH/TTT"+post2[k]),-1)
        hQCD_53jetggH.Add(fW.Get("QCD53ggH/W"+postfix2[k]),-1)
        hQCD_53jetggH.Add(fVV.Get("QCD53ggH/VV"+post2[k]),-1)
        hQCD_53jetggH.Add(fDYS.Get("QCD53ggH/ZTT"+post2[k]),-1)
        hQCD_53jetggH.SetName("QCD"+postfix2[k])
        hQCD_53jetggH.Scale(factor2jet)
        for i in range(0,hQCD_53jetggH.GetSize()-2):
            if hQCD_53jetggH.GetBinContent(i)<0:
                hQCD_53jetggH.SetBinError(i,max(0,hQCD_53jetggH.GetBinError(i)+hQCD_53jetggH.GetBinError(i)))
                hQCD_53jetggH.SetBinContent(i,0)

        hSS_63jetggH=fData.Get("SS63ggH/data_obs")
        hSS_63jetggH.Add(fDYJ.Get("SS63ggH/ZJ"+post2[k]),-1)
        hSS_63jetggH.Add(fDYL.Get("SS63ggH/ZL"+post2[k]),-1)
        hSS_63jetggH.Add(fTTJ.Get("SS63ggH/TTJ"+post2[k]),-1)
        hSS_63jetggH.Add(fTTT.Get("SS63ggH/TTT"+post2[k]),-1)
        hSS_63jetggH.Add(fW.Get("SS63ggH/W"+postfix2[k]),-1)
        hSS_63jetggH.Add(fVV.Get("SS63ggH/VV"+post2[k]),-1)
        hSS_63jetggH.Add(fDYS.Get("SS63ggH/ZTT"+post2[k]),-1)
        hSS_63jetggH.SetName("QCD"+postfix2[k])
        hSS_63jetggH.Scale(factor2jet)
        for i in range(0,hSS_63jetggH.GetSize()-2):
            if hSS_63jetggH.GetBinContent(i)<0:
                hSS_63jetggH.SetBinError(i,max(0,hSS_63jetggH.GetBinError(i)+hSS_63jetggH.GetBinError(i)))
                hSS_63jetggH.SetBinContent(i,0)

        hQCD_63jetggH=fData.Get("QCD63ggH/data_obs")
        hQCD_63jetggH.Add(fDYJ.Get("QCD63ggH/ZJ"+post2[k]),-1)
        hQCD_63jetggH.Add(fDYL.Get("QCD63ggH/ZL"+post2[k]),-1)
        hQCD_63jetggH.Add(fTTJ.Get("QCD63ggH/TTJ"+post2[k]),-1)
        hQCD_63jetggH.Add(fTTT.Get("QCD63ggH/TTT"+post2[k]),-1)
        hQCD_63jetggH.Add(fW.Get("QCD63ggH/W"+postfix2[k]),-1)
        hQCD_63jetggH.Add(fVV.Get("QCD63ggH/VV"+post2[k]),-1)
        hQCD_63jetggH.Add(fDYS.Get("QCD63ggH/ZTT"+post2[k]),-1)
        hQCD_63jetggH.SetName("QCD"+postfix2[k])
        hQCD_63jetggH.Scale(factor2jet)
        for i in range(0,hQCD_63jetggH.GetSize()-2):
            if hQCD_63jetggH.GetBinContent(i)<0:
                hQCD_63jetggH.SetBinError(i,max(0,hQCD_63jetggH.GetBinError(i)+hQCD_63jetggH.GetBinError(i)))
                hQCD_63jetggH.SetBinContent(i,0)

        hSS_73jetggH=fData.Get("SS73ggH/data_obs")
        hSS_73jetggH.Add(fDYJ.Get("SS73ggH/ZJ"+post2[k]),-1)
        hSS_73jetggH.Add(fDYL.Get("SS73ggH/ZL"+post2[k]),-1)
        hSS_73jetggH.Add(fTTJ.Get("SS73ggH/TTJ"+post2[k]),-1)
        hSS_73jetggH.Add(fTTT.Get("SS73ggH/TTT"+post2[k]),-1)
        hSS_73jetggH.Add(fW.Get("SS73ggH/W"+postfix2[k]),-1)
        hSS_73jetggH.Add(fVV.Get("SS73ggH/VV"+post2[k]),-1)
        hSS_73jetggH.Add(fDYS.Get("SS73ggH/ZTT"+post2[k]),-1)
        hSS_73jetggH.SetName("SS"+postfix2[k])
        hSS_73jetggH.Scale(factor2jet)
        for i in range(0,hSS_73jetggH.GetSize()-2):
            if hSS_73jetggH.GetBinContent(i)<0:
                hSS_73jetggH.SetBinError(i,max(0,hSS_73jetggH.GetBinError(i)+hSS_73jetggH.GetBinError(i)))
                hSS_73jetggH.SetBinContent(i,0)


        hQCD_73jetggH=fData.Get("QCD73ggH/data_obs")
        hQCD_73jetggH.Add(fDYJ.Get("QCD73ggH/ZJ"+post2[k]),-1)
        hQCD_73jetggH.Add(fDYL.Get("QCD73ggH/ZL"+post2[k]),-1)
        hQCD_73jetggH.Add(fTTJ.Get("QCD73ggH/TTJ"+post2[k]),-1)
        hQCD_73jetggH.Add(fTTT.Get("QCD73ggH/TTT"+post2[k]),-1)
        hQCD_73jetggH.Add(fW.Get("QCD73ggH/W"+postfix2[k]),-1)
        hQCD_73jetggH.Add(fVV.Get("QCD73ggH/VV"+post2[k]),-1)
        hQCD_73jetggH.Add(fDYS.Get("QCD73ggH/ZTT"+post2[k]),-1)
        hQCD_73jetggH.SetName("QCD"+postfix2[k])
        hQCD_73jetggH.Scale(factor2jet)
        for i in range(0,hQCD_73jetggH.GetSize()-2):
            if hQCD_73jetggH.GetBinContent(i)<0:
                hQCD_73jetggH.SetBinError(i,max(0,hQCD_73jetggH.GetBinError(i)+hQCD_73jetggH.GetBinError(i)))
                hQCD_73jetggH.SetBinContent(i,0)

"""
##############
        hSS_4jetggH=fData.Get("SS3ggH/data_obs")
        hSS_4jetggH.Add(fDYJ.Get("SS3ggH/ZJ"+post2[k]),-1)
        hSS_4jetggH.Add(fDYL.Get("SS3ggH/ZL"+post2[k]),-1)
        hSS_4jetggH.Add(fTTJ.Get("SS3ggH/TTJ"+post2[k]),-1)
        hSS_4jetggH.Add(fTTT.Get("SS3ggH/TTT"+post2[k]),-1)
        hSS_4jetggH.Add(fW.Get("SS3ggH/W"+postfix2[k]),-1)
        hSS_4jetggH.Add(fVV.Get("SS3ggH/VV"+post2[k]),-1)
        hSS_4jetggH.Add(fDYS.Get("SS3ggH/ZTT"+post2[k]),-1)
        hSS_4jetggH.SetName("QCD"+postfix2[k])
        hSS_4jetggH.Scale(factor2jet)
        for i in range(0,hSS_4jetggH.GetSize()-2):
            if hSS_4jetggH.GetBinContent(i)<0:
                hSS_4jetggH.SetBinError(i,max(0,hSS_4jetggH.GetBinError(i)+hSS_4jetggH.GetBinError(i)))
                hSS_4jetggH.SetBinContent(i,0)

        hQCD_4jetggH=fData.Get("QCD3ggH/data_obs")
        hQCD_4jetggH.Add(fDYJ.Get("QCD3ggH/ZJ"+post2[k]),-1)
        hQCD_4jetggH.Add(fDYL.Get("QCD3ggH/ZL"+post2[k]),-1)
        hQCD_4jetggH.Add(fTTJ.Get("QCD3ggH/TTJ"+post2[k]),-1)
        hQCD_4jetggH.Add(fTTT.Get("QCD3ggH/TTT"+post2[k]),-1)
        hQCD_4jetggH.Add(fW.Get("QCD3ggH/W"+postfix2[k]),-1)
        hQCD_4jetggH.Add(fVV.Get("QCD3ggH/VV"+post2[k]),-1)
        hQCD_4jetggH.Add(fDYS.Get("QCD3ggH/ZTT"+post2[k]),-1)
        hQCD_4jetggH.SetName("QCD"+postfix2[k])
        hQCD_4jetggH.Scale(factor2jet)
        for i in range(0,hQCD_4jetggH.GetSize()-2):
            if hQCD_4jetggH.GetBinContent(i)<0:
                hQCD_4jetggH.SetBinError(i,max(0,hQCD_4jetggH.GetBinError(i)+hQCD_4jetggH.GetBinError(i)))
                hQCD_4jetggH.SetBinContent(i,0)


        hSS_34jetggH=fData.Get("SS33ggH/data_obs")
        hSS_34jetggH.Add(fDYJ.Get("SS33ggH/ZJ"+post2[k]),-1)
        hSS_34jetggH.Add(fDYL.Get("SS33ggH/ZL"+post2[k]),-1)
        hSS_34jetggH.Add(fTTJ.Get("SS33ggH/TTJ"+post2[k]),-1)
        hSS_34jetggH.Add(fTTT.Get("SS33ggH/TTT"+post2[k]),-1)
        hSS_34jetggH.Add(fW.Get("SS33ggH/W"+postfix2[k]),-1)
        hSS_34jetggH.Add(fVV.Get("SS33ggH/VV"+post2[k]),-1)
        hSS_34jetggH.Add(fDYS.Get("SS33ggH/ZTT"+post2[k]),-1)
        hSS_34jetggH.SetName("QCD"+postfix2[k])
        hSS_34jetggH.Scale(factor2jet)
        for i in range(0,hSS_34jetggH.GetSize()-2):
            if hSS_34jetggH.GetBinContent(i)<0:
                hSS_34jetggH.SetBinError(i,max(0,hSS_34jetggH.GetBinError(i)+hSS_34jetggH.GetBinError(i)))
                hSS_34jetggH.SetBinContent(i,0)

        hQCD_34jetggH=fData.Get("QCD33ggH/data_obs")
        hQCD_34jetggH.Add(fDYJ.Get("QCD33ggH/ZJ"+post2[k]),-1)
        hQCD_34jetggH.Add(fDYL.Get("QCD33ggH/ZL"+post2[k]),-1)
        hQCD_34jetggH.Add(fTTJ.Get("QCD33ggH/TTJ"+post2[k]),-1)
        hQCD_34jetggH.Add(fTTT.Get("QCD33ggH/TTT"+post2[k]),-1)
        hQCD_34jetggH.Add(fW.Get("QCD33ggH/W"+postfix2[k]),-1)
        hQCD_34jetggH.Add(fVV.Get("QCD33ggH/VV"+post2[k]),-1)
        hQCD_34jetggH.Add(fDYS.Get("QCD33ggH/ZTT"+post2[k]),-1)
        hQCD_34jetggH.SetName("QCD"+postfix2[k])
        hQCD_34jetggH.Scale(factor2jet)
        for i in range(0,hQCD_34jetggH.GetSize()-2):
            if hQCD_34jetggH.GetBinContent(i)<0:
                hQCD_34jetggH.SetBinError(i,max(0,hQCD_34jetggH.GetBinError(i)+hQCD_34jetggH.GetBinError(i)))
                hQCD_34jetggH.SetBinContent(i,0)


        hSS_44jetggH=fData.Get("SS43ggH/data_obs")
        hSS_44jetggH.Add(fDYJ.Get("SS43ggH/ZJ"+post2[k]),-1)
        hSS_44jetggH.Add(fDYL.Get("SS43ggH/ZL"+post2[k]),-1)
        hSS_44jetggH.Add(fTTJ.Get("SS43ggH/TTJ"+post2[k]),-1)
        hSS_44jetggH.Add(fTTT.Get("SS43ggH/TTT"+post2[k]),-1)
        hSS_44jetggH.Add(fW.Get("SS43ggH/W"+postfix2[k]),-1)
        hSS_44jetggH.Add(fVV.Get("SS43ggH/VV"+post2[k]),-1)
        hSS_44jetggH.Add(fDYS.Get("SS43ggH/ZTT"+post2[k]),-1)
        hSS_44jetggH.SetName("QCD"+postfix2[k])
        hSS_44jetggH.Scale(factor2jet)
        for i in range(0,hSS_44jetggH.GetSize()-2):
            if hSS_44jetggH.GetBinContent(i)<0:
                hSS_44jetggH.SetBinError(i,max(0,hSS_44jetggH.GetBinError(i)+hSS_44jetggH.GetBinError(i)))
                hSS_44jetggH.SetBinContent(i,0)

        hQCD_44jetggH=fData.Get("QCD43ggH/data_obs")
        hQCD_44jetggH.Add(fDYJ.Get("QCD43ggH/ZJ"+post2[k]),-1)
        hQCD_44jetggH.Add(fDYL.Get("QCD43ggH/ZL"+post2[k]),-1)
        hQCD_44jetggH.Add(fTTJ.Get("QCD43ggH/TTJ"+post2[k]),-1)
        hQCD_44jetggH.Add(fTTT.Get("QCD43ggH/TTT"+post2[k]),-1)
        hQCD_44jetggH.Add(fW.Get("QCD43ggH/W"+postfix2[k]),-1)
        hQCD_44jetggH.Add(fVV.Get("QCD43ggH/VV"+post2[k]),-1)
        hQCD_44jetggH.Add(fDYS.Get("QCD43ggH/ZTT"+post2[k]),-1)
        hQCD_44jetggH.SetName("QCD"+postfix2[k])
        hQCD_44jetggH.Scale(factor2jet)
        for i in range(0,hQCD_44jetggH.GetSize()-2):
            if hQCD_44jetggH.GetBinContent(i)<0:
                hQCD_44jetggH.SetBinError(i,max(0,hQCD_44jetggH.GetBinError(i)+hQCD_44jetggH.GetBinError(i)))
                hQCD_44jetggH.SetBinContent(i,0)



        hSS_54jetggH=fData.Get("SS53ggH/data_obs")
        hSS_54jetggH.Add(fDYJ.Get("SS53ggH/ZJ"+post2[k]),-1)
        hSS_54jetggH.Add(fDYL.Get("SS53ggH/ZL"+post2[k]),-1)
        hSS_54jetggH.Add(fTTJ.Get("SS53ggH/TTJ"+post2[k]),-1)
        hSS_54jetggH.Add(fTTT.Get("SS53ggH/TTT"+post2[k]),-1)
        hSS_54jetggH.Add(fW.Get("SS53ggH/W"+postfix2[k]),-1)
        hSS_54jetggH.Add(fVV.Get("SS53ggH/VV"+post2[k]),-1)
        hSS_54jetggH.Add(fDYS.Get("SS53ggH/ZTT"+post2[k]),-1)
        hSS_54jetggH.SetName("QCD"+postfix2[k])
        hSS_54jetggH.Scale(factor2jet)
        for i in range(0,hSS_54jetggH.GetSize()-2):
            if hSS_54jetggH.GetBinContent(i)<0:
                hSS_54jetggH.SetBinError(i,max(0,hSS_54jetggH.GetBinError(i)+hSS_54jetggH.GetBinError(i)))
                hSS_54jetggH.SetBinContent(i,0)

        hQCD_54jetggH=fData.Get("QCD53ggH/data_obs")
        hQCD_54jetggH.Add(fDYJ.Get("QCD53ggH/ZJ"+post2[k]),-1)
        hQCD_54jetggH.Add(fDYL.Get("QCD53ggH/ZL"+post2[k]),-1)
        hQCD_54jetggH.Add(fTTJ.Get("QCD53ggH/TTJ"+post2[k]),-1)
        hQCD_54jetggH.Add(fTTT.Get("QCD53ggH/TTT"+post2[k]),-1)
        hQCD_54jetggH.Add(fW.Get("QCD53ggH/W"+postfix2[k]),-1)
        hQCD_54jetggH.Add(fVV.Get("QCD53ggH/VV"+post2[k]),-1)
        hQCD_54jetggH.Add(fDYS.Get("QCD53ggH/ZTT"+post2[k]),-1)
        hQCD_54jetggH.SetName("QCD"+postfix2[k])
        hQCD_54jetggH.Scale(factor2jet)
        for i in range(0,hQCD_54jetggH.GetSize()-2):
            if hQCD_54jetggH.GetBinContent(i)<0:
                hQCD_54jetggH.SetBinError(i,max(0,hQCD_54jetggH.GetBinError(i)+hQCD_54jetggH.GetBinError(i)))
                hQCD_54jetggH.SetBinContent(i,0)

        hSS_64jetggH=fData.Get("SS63ggH/data_obs")
        hSS_64jetggH.Add(fDYJ.Get("SS63ggH/ZJ"+post2[k]),-1)
        hSS_64jetggH.Add(fDYL.Get("SS63ggH/ZL"+post2[k]),-1)
        hSS_64jetggH.Add(fTTJ.Get("SS63ggH/TTJ"+post2[k]),-1)
        hSS_64jetggH.Add(fTTT.Get("SS63ggH/TTT"+post2[k]),-1)
        hSS_64jetggH.Add(fW.Get("SS63ggH/W"+postfix2[k]),-1)
        hSS_64jetggH.Add(fVV.Get("SS63ggH/VV"+post2[k]),-1)
        hSS_64jetggH.Add(fDYS.Get("SS63ggH/ZTT"+post2[k]),-1)
        hSS_64jetggH.SetName("QCD"+postfix2[k])
        hSS_64jetggH.Scale(factor2jet)
        for i in range(0,hSS_64jetggH.GetSize()-2):
            if hSS_64jetggH.GetBinContent(i)<0:
                hSS_64jetggH.SetBinError(i,max(0,hSS_64jetggH.GetBinError(i)+hSS_64jetggH.GetBinError(i)))
                hSS_64jetggH.SetBinContent(i,0)

        hQCD_64jetggH=fData.Get("QCD63ggH/data_obs")
        hQCD_64jetggH.Add(fDYJ.Get("QCD63ggH/ZJ"+post2[k]),-1)
        hQCD_64jetggH.Add(fDYL.Get("QCD63ggH/ZL"+post2[k]),-1)
        hQCD_64jetggH.Add(fTTJ.Get("QCD63ggH/TTJ"+post2[k]),-1)
        hQCD_64jetggH.Add(fTTT.Get("QCD63ggH/TTT"+post2[k]),-1)
        hQCD_64jetggH.Add(fW.Get("QCD63ggH/W"+postfix2[k]),-1)
        hQCD_64jetggH.Add(fVV.Get("QCD63ggH/VV"+post2[k]),-1)
        hQCD_64jetggH.Add(fDYS.Get("QCD63ggH/ZTT"+post2[k]),-1)
        hQCD_64jetggH.SetName("QCD"+postfix2[k])
        hQCD_64jetggH.Scale(factor2jet)
        for i in range(0,hQCD_64jetggH.GetSize()-2):
            if hQCD_64jetggH.GetBinContent(i)<0:
                hQCD_64jetggH.SetBinError(i,max(0,hQCD_64jetggH.GetBinError(i)+hQCD_64jetggH.GetBinError(i)))
                hQCD_64jetggH.SetBinContent(i,0)

        hSS_74jetggH=fData.Get("SS63ggH/data_obs")
        hSS_74jetggH.Add(fDYJ.Get("SS63ggH/ZJ"+post2[k]),-1)
        hSS_74jetggH.Add(fDYL.Get("SS63ggH/ZL"+post2[k]),-1)
        hSS_74jetggH.Add(fTTJ.Get("SS63ggH/TTJ"+post2[k]),-1)
        hSS_74jetggH.Add(fTTT.Get("SS63ggH/TTT"+post2[k]),-1)
        hSS_74jetggH.Add(fW.Get("SS63ggH/W"+postfix2[k]),-1)
        hSS_74jetggH.Add(fVV.Get("SS63ggH/VV"+post2[k]),-1)
        hSS_74jetggH.Add(fDYS.Get("SS63ggH/ZTT"+post2[k]),-1)
        hSS_74jetggH.SetName("SS"+postfix2[k])
        hSS_74jetggH.Scale(factor2jet)
        for i in range(0,hSS_74jetggH.GetSize()-2):
            if hSS_74jetggH.GetBinContent(i)<0:
                hSS_74jetggH.SetBinError(i,max(0,hSS_74jetggH.GetBinError(i)+hSS_74jetggH.GetBinError(i)))
                hSS_74jetggH.SetBinContent(i,0)


        hQCD_74jetggH=fData.Get("QCD63ggH/data_obs")
        hQCD_74jetggH.Add(fDYJ.Get("QCD63ggH/ZJ"+post2[k]),-1)
        hQCD_74jetggH.Add(fDYL.Get("QCD63ggH/ZL"+post2[k]),-1)
        hQCD_74jetggH.Add(fTTJ.Get("QCD63ggH/TTJ"+post2[k]),-1)
        hQCD_74jetggH.Add(fTTT.Get("QCD63ggH/TTT"+post2[k]),-1)
        hQCD_74jetggH.Add(fW.Get("QCD63ggH/W"+postfix2[k]),-1)
        hQCD_74jetggH.Add(fVV.Get("QCD63ggH/VV"+post2[k]),-1)
        hQCD_74jetggH.Add(fDYS.Get("QCD63ggH/ZTT"+post2[k]),-1)
        hQCD_74jetggH.SetName("QCD"+postfix2[k])
        hQCD_74jetggH.Scale(factor2jet)
        for i in range(0,hQCD_74jetggH.GetSize()-2):
            if hQCD_74jetggH.GetBinContent(i)<0:
                hQCD_74jetggH.SetBinError(i,max(0,hQCD_74jetggH.GetBinError(i)+hQCD_74jetggH.GetBinError(i)))
                hQCD_74jetggH.SetBinContent(i,0)

#############
        hQCD_5jetggH=fData.Get("QCD5ggH/data_obs")
        hQCD_5jetggH.Add(fDYJ.Get("QCD5ggH/ZJ"+post2[k]),-1)
        hQCD_5jetggH.Add(fDYL.Get("QCD5ggH/ZL"+post2[k]),-1)
        hQCD_5jetggH.Add(fTTJ.Get("QCD5ggH/TTJ"+post2[k]),-1)
        hQCD_5jetggH.Add(fTTT.Get("QCD5ggH/TTT"+post2[k]),-1)
        hQCD_5jetggH.Add(fW.Get("QCD5ggH/W"+postfix2[k]),-1)
        hQCD_5jetggH.Add(fVV.Get("QCD5ggH/VV"+post2[k]),-1)
        hQCD_5jetggH.Add(fDYS.Get("QCD5ggH/ZTT"+post2[k]),-1)
        hQCD_5jetggH.SetName("QCD"+postfix2[k])
        hQCD_5jetggH.Scale(factor2jet)
        for i in range(0,hQCD_5jetggH.GetSize()-2):
            if hQCD_5jetggH.GetBinContent(i)<0:
                hQCD_5jetggH.SetBinError(i,max(0,hQCD_5jetggH.GetBinError(i)+hQCD_5jetggH.GetBinError(i)))
                hQCD_5jetggH.SetBinContent(i,0)



        hSS_55jetggH=fData.Get("SS55ggH/data_obs")
        hSS_55jetggH.Add(fDYJ.Get("SS55ggH/ZJ"+post2[k]),-1)
        hSS_55jetggH.Add(fDYL.Get("SS55ggH/ZL"+post2[k]),-1)
        hSS_55jetggH.Add(fTTJ.Get("SS55ggH/TTJ"+post2[k]),-1)
        hSS_55jetggH.Add(fTTT.Get("SS55ggH/TTT"+post2[k]),-1)
        hSS_55jetggH.Add(fW.Get("SS55ggH/W"+postfix2[k]),-1)
        hSS_55jetggH.Add(fVV.Get("SS55ggH/VV"+post2[k]),-1)
        hSS_55jetggH.Add(fDYS.Get("SS55ggH/ZTT"+post2[k]),-1)
        hSS_55jetggH.SetName("QCD"+postfix2[k])
        hSS_55jetggH.Scale(factor2jet)
        for i in range(0,hSS_55jetggH.GetSize()-2):
            if hSS_55jetggH.GetBinContent(i)<0:
                hSS_55jetggH.SetBinError(i,max(0,hSS_55jetggH.GetBinError(i)+hSS_55jetggH.GetBinError(i)))
                hSS_55jetggH.SetBinContent(i,0)

        hQCD_55jetggH=fData.Get("QCD55ggH/data_obs")
        hQCD_55jetggH.Add(fDYJ.Get("QCD55ggH/ZJ"+post2[k]),-1)
        hQCD_55jetggH.Add(fDYL.Get("QCD55ggH/ZL"+post2[k]),-1)
        hQCD_55jetggH.Add(fTTJ.Get("QCD55ggH/TTJ"+post2[k]),-1)
        hQCD_55jetggH.Add(fTTT.Get("QCD55ggH/TTT"+post2[k]),-1)
        hQCD_55jetggH.Add(fW.Get("QCD55ggH/W"+postfix2[k]),-1)
        hQCD_55jetggH.Add(fVV.Get("QCD55ggH/VV"+post2[k]),-1)
        hQCD_55jetggH.Add(fDYS.Get("QCD55ggH/ZTT"+post2[k]),-1)
        hQCD_55jetggH.SetName("QCD"+postfix2[k])
        hQCD_55jetggH.Scale(factor2jet)
        for i in range(0,hQCD_55jetggH.GetSize()-2):
            if hQCD_55jetggH.GetBinContent(i)<0:
                hQCD_55jetggH.SetBinError(i,max(0,hQCD_55jetggH.GetBinError(i)+hQCD_55jetggH.GetBinError(i)))
                hQCD_55jetggH.SetBinContent(i,0)

        hSS_65jetggH=fData.Get("SS65ggH/data_obs")
        hSS_65jetggH.Add(fDYJ.Get("SS65ggH/ZJ"+post2[k]),-1)
        hSS_65jetggH.Add(fDYL.Get("SS65ggH/ZL"+post2[k]),-1)
        hSS_65jetggH.Add(fTTJ.Get("SS65ggH/TTJ"+post2[k]),-1)
        hSS_65jetggH.Add(fTTT.Get("SS65ggH/TTT"+post2[k]),-1)
        hSS_65jetggH.Add(fW.Get("SS65ggH/W"+postfix2[k]),-1)
        hSS_65jetggH.Add(fVV.Get("SS65ggH/VV"+post2[k]),-1)
        hSS_65jetggH.Add(fDYS.Get("SS65ggH/ZTT"+post2[k]),-1)
        hSS_65jetggH.SetName("QCD"+postfix2[k])
        hSS_65jetggH.Scale(factor2jet)
        for i in range(0,hSS_65jetggH.GetSize()-2):
            if hSS_65jetggH.GetBinContent(i)<0:
                hSS_65jetggH.SetBinError(i,max(0,hSS_65jetggH.GetBinError(i)+hSS_65jetggH.GetBinError(i)))
                hSS_65jetggH.SetBinContent(i,0)

        hQCD_65jetggH=fData.Get("QCD65ggH/data_obs")
        hQCD_65jetggH.Add(fDYJ.Get("QCD65ggH/ZJ"+post2[k]),-1)
        hQCD_65jetggH.Add(fDYL.Get("QCD65ggH/ZL"+post2[k]),-1)
        hQCD_65jetggH.Add(fTTJ.Get("QCD65ggH/TTJ"+post2[k]),-1)
        hQCD_65jetggH.Add(fTTT.Get("QCD65ggH/TTT"+post2[k]),-1)
        hQCD_65jetggH.Add(fW.Get("QCD65ggH/W"+postfix2[k]),-1)
        hQCD_65jetggH.Add(fVV.Get("QCD65ggH/VV"+post2[k]),-1)
        hQCD_65jetggH.Add(fDYS.Get("QCD65ggH/ZTT"+post2[k]),-1)
        hQCD_65jetggH.SetName("QCD"+postfix2[k])
        hQCD_65jetggH.Scale(factor2jet)
        for i in range(0,hQCD_65jetggH.GetSize()-2):
            if hQCD_65jetggH.GetBinContent(i)<0:
                hQCD_65jetggH.SetBinError(i,max(0,hQCD_65jetggH.GetBinError(i)+hQCD_65jetggH.GetBinError(i)))
                hQCD_65jetggH.SetBinContent(i,0)

        hSS_75jetggH=fData.Get("SS75ggH/data_obs")
        hSS_75jetggH.Add(fDYJ.Get("SS75ggH/ZJ"+post2[k]),-1)
        hSS_75jetggH.Add(fDYL.Get("SS75ggH/ZL"+post2[k]),-1)
        hSS_75jetggH.Add(fTTJ.Get("SS75ggH/TTJ"+post2[k]),-1)
        hSS_75jetggH.Add(fTTT.Get("SS75ggH/TTT"+post2[k]),-1)
        hSS_75jetggH.Add(fW.Get("SS75ggH/W"+postfix2[k]),-1)
        hSS_75jetggH.Add(fVV.Get("SS75ggH/VV"+post2[k]),-1)
        hSS_75jetggH.Add(fDYS.Get("SS75ggH/ZTT"+post2[k]),-1)
        hSS_75jetggH.SetName("SS"+postfix2[k])
        hSS_75jetggH.Scale(factor2jet)
        for i in range(0,hSS_75jetggH.GetSize()-2):
            if hSS_75jetggH.GetBinContent(i)<0:
                hSS_75jetggH.SetBinError(i,max(0,hSS_75jetggH.GetBinError(i)+hSS_75jetggH.GetBinError(i)))
                hSS_75jetggH.SetBinContent(i,0)

        hQCD_75jetggH=fData.Get("QCD75ggH/data_obs")
        hQCD_75jetggH.Add(fDYJ.Get("QCD75ggH/ZJ"+post2[k]),-1)
        hQCD_75jetggH.Add(fDYL.Get("QCD75ggH/ZL"+post2[k]),-1)
        hQCD_75jetggH.Add(fTTJ.Get("QCD75ggH/TTJ"+post2[k]),-1)
        hQCD_75jetggH.Add(fTTT.Get("QCD75ggH/TTT"+post2[k]),-1)
        hQCD_75jetggH.Add(fW.Get("QCD75ggH/W"+postfix2[k]),-1)
        hQCD_75jetggH.Add(fVV.Get("QCD75ggH/VV"+post2[k]),-1)
        hQCD_75jetggH.Add(fDYS.Get("QCD75ggH/ZTT"+post2[k]),-1)
        hQCD_75jetggH.SetName("QCD"+postfix2[k])
        hQCD_75jetggH.Scale(factor2jet)
        for i in range(0,hQCD_75jetggH.GetSize()-2):
            if hQCD_75jetggH.GetBinContent(i)<0:
                hQCD_75jetggH.SetBinError(i,max(0,hQCD_75jetggH.GetBinError(i)+hQCD_75jetggH.GetBinError(i)))
                hQCD_75jetggH.SetBinContent(i,0)






################


        hSS_5jetggH=fData.Get("SS3ggH/data_obs")
        hSS_5jetggH.Add(fDYJ.Get("SS3ggH/ZJ"+post2[k]),-1)
        hSS_5jetggH.Add(fDYL.Get("SS3ggH/ZL"+post2[k]),-1)
        hSS_5jetggH.Add(fTTJ.Get("SS3ggH/TTJ"+post2[k]),-1)
        hSS_5jetggH.Add(fTTT.Get("SS3ggH/TTT"+post2[k]),-1)
        hSS_5jetggH.Add(fW.Get("SS3ggH/W"+postfix2[k]),-1)
        hSS_5jetggH.Add(fVV.Get("SS3ggH/VV"+post2[k]),-1)
        hSS_5jetggH.Add(fDYS.Get("SS3ggH/ZTT"+post2[k]),-1)
        hSS_5jetggH.SetName("QCD"+postfix2[k])
        hSS_5jetggH.Scale(factor2jet)
        for i in range(0,hSS_5jetggH.GetSize()-2):
            if hSS_5jetggH.GetBinContent(i)<0:
                hSS_5jetggH.SetBinError(i,max(0,hSS_5jetggH.GetBinError(i)+hSS_5jetggH.GetBinError(i)))
                hSS_5jetggH.SetBinContent(i,0)

        hQCD_5jetggH=fData.Get("QCD3ggH/data_obs")
        hQCD_5jetggH.Add(fDYJ.Get("QCD3ggH/ZJ"+post2[k]),-1)
        hQCD_5jetggH.Add(fDYL.Get("QCD3ggH/ZL"+post2[k]),-1)
        hQCD_5jetggH.Add(fTTJ.Get("QCD3ggH/TTJ"+post2[k]),-1)
        hQCD_5jetggH.Add(fTTT.Get("QCD3ggH/TTT"+post2[k]),-1)
        hQCD_5jetggH.Add(fW.Get("QCD3ggH/W"+postfix2[k]),-1)
        hQCD_5jetggH.Add(fVV.Get("QCD3ggH/VV"+post2[k]),-1)
        hQCD_5jetggH.Add(fDYS.Get("QCD3ggH/ZTT"+post2[k]),-1)
        hQCD_5jetggH.SetName("QCD"+postfix2[k])
        hQCD_5jetggH.Scale(factor2jet)
        for i in range(0,hQCD_5jetggH.GetSize()-2):
            if hQCD_5jetggH.GetBinContent(i)<0:
                hQCD_5jetggH.SetBinError(i,max(0,hQCD_5jetggH.GetBinError(i)+hQCD_5jetggH.GetBinError(i)))
                hQCD_5jetggH.SetBinContent(i,0)


        hSS_35jetggH=fData.Get("SS33ggH/data_obs")
        hSS_35jetggH.Add(fDYJ.Get("SS33ggH/ZJ"+post2[k]),-1)
        hSS_35jetggH.Add(fDYL.Get("SS33ggH/ZL"+post2[k]),-1)
        hSS_35jetggH.Add(fTTJ.Get("SS33ggH/TTJ"+post2[k]),-1)
        hSS_35jetggH.Add(fTTT.Get("SS33ggH/TTT"+post2[k]),-1)
        hSS_35jetggH.Add(fW.Get("SS33ggH/W"+postfix2[k]),-1)
        hSS_35jetggH.Add(fVV.Get("SS33ggH/VV"+post2[k]),-1)
        hSS_35jetggH.Add(fDYS.Get("SS33ggH/ZTT"+post2[k]),-1)
        hSS_35jetggH.SetName("QCD"+postfix2[k])
        hSS_35jetggH.Scale(factor2jet)
        for i in range(0,hSS_35jetggH.GetSize()-2):
            if hSS_35jetggH.GetBinContent(i)<0:
                hSS_35jetggH.SetBinError(i,max(0,hSS_35jetggH.GetBinError(i)+hSS_35jetggH.GetBinError(i)))
                hSS_35jetggH.SetBinContent(i,0)

        hQCD_35jetggH=fData.Get("QCD33ggH/data_obs")
        hQCD_35jetggH.Add(fDYJ.Get("QCD33ggH/ZJ"+post2[k]),-1)
        hQCD_35jetggH.Add(fDYL.Get("QCD33ggH/ZL"+post2[k]),-1)
        hQCD_35jetggH.Add(fTTJ.Get("QCD33ggH/TTJ"+post2[k]),-1)
        hQCD_35jetggH.Add(fTTT.Get("QCD33ggH/TTT"+post2[k]),-1)
        hQCD_35jetggH.Add(fW.Get("QCD33ggH/W"+postfix2[k]),-1)
        hQCD_35jetggH.Add(fVV.Get("QCD33ggH/VV"+post2[k]),-1)
        hQCD_35jetggH.Add(fDYS.Get("QCD33ggH/ZTT"+post2[k]),-1)
        hQCD_35jetggH.SetName("QCD"+postfix2[k])
        hQCD_35jetggH.Scale(factor2jet)
        for i in range(0,hQCD_35jetggH.GetSize()-2):
            if hQCD_35jetggH.GetBinContent(i)<0:
                hQCD_35jetggH.SetBinError(i,max(0,hQCD_35jetggH.GetBinError(i)+hQCD_35jetggH.GetBinError(i)))
                hQCD_35jetggH.SetBinContent(i,0)


        hSS_45jetggH=fData.Get("SS43ggH/data_obs")
        hSS_45jetggH.Add(fDYJ.Get("SS43ggH/ZJ"+post2[k]),-1)
        hSS_45jetggH.Add(fDYL.Get("SS43ggH/ZL"+post2[k]),-1)
        hSS_45jetggH.Add(fTTJ.Get("SS43ggH/TTJ"+post2[k]),-1)
        hSS_45jetggH.Add(fTTT.Get("SS43ggH/TTT"+post2[k]),-1)
        hSS_45jetggH.Add(fW.Get("SS43ggH/W"+postfix2[k]),-1)
        hSS_45jetggH.Add(fVV.Get("SS43ggH/VV"+post2[k]),-1)
        hSS_45jetggH.Add(fDYS.Get("SS43ggH/ZTT"+post2[k]),-1)
        hSS_45jetggH.SetName("QCD"+postfix2[k])
        hSS_45jetggH.Scale(factor2jet)
        for i in range(0,hSS_45jetggH.GetSize()-2):
            if hSS_45jetggH.GetBinContent(i)<0:
                hSS_45jetggH.SetBinError(i,max(0,hSS_45jetggH.GetBinError(i)+hSS_45jetggH.GetBinError(i)))
                hSS_45jetggH.SetBinContent(i,0)

        hQCD_45jetggH=fData.Get("QCD43ggH/data_obs")
        hQCD_45jetggH.Add(fDYJ.Get("QCD43ggH/ZJ"+post2[k]),-1)
        hQCD_45jetggH.Add(fDYL.Get("QCD43ggH/ZL"+post2[k]),-1)
        hQCD_45jetggH.Add(fTTJ.Get("QCD43ggH/TTJ"+post2[k]),-1)
        hQCD_45jetggH.Add(fTTT.Get("QCD43ggH/TTT"+post2[k]),-1)
        hQCD_45jetggH.Add(fW.Get("QCD43ggH/W"+postfix2[k]),-1)
        hQCD_45jetggH.Add(fVV.Get("QCD43ggH/VV"+post2[k]),-1)
        hQCD_45jetggH.Add(fDYS.Get("QCD43ggH/ZTT"+post2[k]),-1)
        hQCD_45jetggH.SetName("QCD"+postfix2[k])
        hQCD_45jetggH.Scale(factor2jet)
        for i in range(0,hQCD_45jetggH.GetSize()-2):
            if hQCD_45jetggH.GetBinContent(i)<0:
                hQCD_45jetggH.SetBinError(i,max(0,hQCD_45jetggH.GetBinError(i)+hQCD_45jetggH.GetBinError(i)))
                hQCD_45jetggH.SetBinContent(i,0)



        hSS_55jetggH=fData.Get("SS53ggH/data_obs")
        hSS_55jetggH.Add(fDYJ.Get("SS53ggH/ZJ"+post2[k]),-1)
        hSS_55jetggH.Add(fDYL.Get("SS53ggH/ZL"+post2[k]),-1)
        hSS_55jetggH.Add(fTTJ.Get("SS53ggH/TTJ"+post2[k]),-1)
        hSS_55jetggH.Add(fTTT.Get("SS53ggH/TTT"+post2[k]),-1)
        hSS_55jetggH.Add(fW.Get("SS53ggH/W"+postfix2[k]),-1)
        hSS_55jetggH.Add(fVV.Get("SS53ggH/VV"+post2[k]),-1)
        hSS_55jetggH.Add(fDYS.Get("SS53ggH/ZTT"+post2[k]),-1)
        hSS_55jetggH.SetName("QCD"+postfix2[k])
        hSS_55jetggH.Scale(factor2jet)
        for i in range(0,hSS_55jetggH.GetSize()-2):
            if hSS_55jetggH.GetBinContent(i)<0:
                hSS_55jetggH.SetBinError(i,max(0,hSS_55jetggH.GetBinError(i)+hSS_55jetggH.GetBinError(i)))
                hSS_55jetggH.SetBinContent(i,0)

        hQCD_55jetggH=fData.Get("QCD53ggH/data_obs")
        hQCD_55jetggH.Add(fDYJ.Get("QCD53ggH/ZJ"+post2[k]),-1)
        hQCD_55jetggH.Add(fDYL.Get("QCD53ggH/ZL"+post2[k]),-1)
        hQCD_55jetggH.Add(fTTJ.Get("QCD53ggH/TTJ"+post2[k]),-1)
        hQCD_55jetggH.Add(fTTT.Get("QCD53ggH/TTT"+post2[k]),-1)
        hQCD_55jetggH.Add(fW.Get("QCD53ggH/W"+postfix2[k]),-1)
        hQCD_55jetggH.Add(fVV.Get("QCD53ggH/VV"+post2[k]),-1)
        hQCD_55jetggH.Add(fDYS.Get("QCD53ggH/ZTT"+post2[k]),-1)
        hQCD_55jetggH.SetName("QCD"+postfix2[k])
        hQCD_55jetggH.Scale(factor2jet)
        for i in range(0,hQCD_55jetggH.GetSize()-2):
            if hQCD_55jetggH.GetBinContent(i)<0:
                hQCD_55jetggH.SetBinError(i,max(0,hQCD_55jetggH.GetBinError(i)+hQCD_55jetggH.GetBinError(i)))
                hQCD_55jetggH.SetBinContent(i,0)

        hSS_65jetggH=fData.Get("SS63ggH/data_obs")
        hSS_65jetggH.Add(fDYJ.Get("SS63ggH/ZJ"+post2[k]),-1)
        hSS_65jetggH.Add(fDYL.Get("SS63ggH/ZL"+post2[k]),-1)
        hSS_65jetggH.Add(fTTJ.Get("SS63ggH/TTJ"+post2[k]),-1)
        hSS_65jetggH.Add(fTTT.Get("SS63ggH/TTT"+post2[k]),-1)
        hSS_65jetggH.Add(fW.Get("SS63ggH/W"+postfix2[k]),-1)
        hSS_65jetggH.Add(fVV.Get("SS63ggH/VV"+post2[k]),-1)
        hSS_65jetggH.Add(fDYS.Get("SS63ggH/ZTT"+post2[k]),-1)
        hSS_65jetggH.SetName("QCD"+postfix2[k])
        hSS_65jetggH.Scale(factor2jet)
        for i in range(0,hSS_65jetggH.GetSize()-2):
            if hSS_65jetggH.GetBinContent(i)<0:
                hSS_65jetggH.SetBinError(i,max(0,hSS_65jetggH.GetBinError(i)+hSS_65jetggH.GetBinError(i)))
                hSS_65jetggH.SetBinContent(i,0)

        hSS_75jetggH=fData.Get("SS63ggH/data_obs")
        hSS_75jetggH.Add(fDYJ.Get("SS63ggH/ZJ"+post2[k]),-1)
        hSS_75jetggH.Add(fDYL.Get("SS63ggH/ZL"+post2[k]),-1)
        hSS_75jetggH.Add(fTTJ.Get("SS63ggH/TTJ"+post2[k]),-1)
        hSS_75jetggH.Add(fTTT.Get("SS63ggH/TTT"+post2[k]),-1)
        hSS_75jetggH.Add(fW.Get("SS63ggH/W"+postfix2[k]),-1)
        hSS_75jetggH.Add(fVV.Get("SS63ggH/VV"+post2[k]),-1)
        hSS_75jetggH.Add(fDYS.Get("SS63ggH/ZTT"+post2[k]),-1)
        hSS_75jetggH.SetName("SS"+postfix2[k])
        hSS_75jetggH.Scale(factor2jet)
        for i in range(0,hSS_75jetggH.GetSize()-2):
            if hSS_75jetggH.GetBinContent(i)<0:
                hSS_75jetggH.SetBinError(i,max(0,hSS_65jetggH.GetBinError(i)+hSS_65jetggH.GetBinError(i)))
                hSS_75jetggH.SetBinContent(i,0)

        hQCD_75jetggH=fData.Get("QCD63ggH/data_obs")
        hQCD_75jetggH.Add(fDYJ.Get("QCD63ggH/ZJ"+post2[k]),-1)
        hQCD_75jetggH.Add(fDYL.Get("QCD63ggH/ZL"+post2[k]),-1)
        hQCD_75jetggH.Add(fTTJ.Get("QCD63ggH/TTJ"+post2[k]),-1)
        hQCD_75jetggH.Add(fTTT.Get("QCD63ggH/TTT"+post2[k]),-1)
        hQCD_75jetggH.Add(fW.Get("QCD63ggH/W"+postfix2[k]),-1)
        hQCD_75jetggH.Add(fVV.Get("QCD63ggH/VV"+post2[k]),-1)
        hQCD_75jetggH.Add(fDYS.Get("QCD63ggH/ZTT"+post2[k]),-1)
        hQCD_75jetggH.SetName("QCD"+postfix2[k])
        hQCD_75jetggH.Scale(factor2jet)
        for i in range(0,hQCD_75jetggH.GetSize()-2):
            if hQCD_75jetggH.GetBinContent(i)<0:
                hQCD_75jetggH.SetBinError(i,max(0,hQCD_65jetggH.GetBinError(i)+hQCD_65jetggH.GetBinError(i)))
                hQCD_75jetggH.SetBinContent(i,0)




####################

        hSS_7jetggH=fData.Get("SS3ggH/data_obs")
        hSS_7jetggH.Add(fDYJ.Get("SS3ggH/ZJ"+post2[k]),-1)
        hSS_7jetggH.Add(fDYL.Get("SS3ggH/ZL"+post2[k]),-1)
        hSS_7jetggH.Add(fTTJ.Get("SS3ggH/TTJ"+post2[k]),-1)
        hSS_7jetggH.Add(fTTT.Get("SS3ggH/TTT"+post2[k]),-1)
        hSS_7jetggH.Add(fW.Get("SS3ggH/W"+postfix2[k]),-1)
        hSS_7jetggH.Add(fVV.Get("SS3ggH/VV"+post2[k]),-1)
        hSS_7jetggH.Add(fDYS.Get("SS3ggH/ZTT"+post2[k]),-1)
        hSS_7jetggH.SetName("QCD"+postfix2[k])
        hSS_7jetggH.Scale(factor2jet)
        for i in range(0,hSS_7jetggH.GetSize()-2):
            if hSS_7jetggH.GetBinContent(i)<0:
                hSS_7jetggH.SetBinError(i,max(0,hSS_7jetggH.GetBinError(i)+hSS_7jetggH.GetBinError(i)))
                hSS_7jetggH.SetBinContent(i,0)

        hQCD_7jetggH=fData.Get("QCD3ggH/data_obs")
        hQCD_7jetggH.Add(fDYJ.Get("QCD3ggH/ZJ"+post2[k]),-1)
        hQCD_7jetggH.Add(fDYL.Get("QCD3ggH/ZL"+post2[k]),-1)
        hQCD_7jetggH.Add(fTTJ.Get("QCD3ggH/TTJ"+post2[k]),-1)
        hQCD_7jetggH.Add(fTTT.Get("QCD3ggH/TTT"+post2[k]),-1)
        hQCD_7jetggH.Add(fW.Get("QCD3ggH/W"+postfix2[k]),-1)
        hQCD_7jetggH.Add(fVV.Get("QCD3ggH/VV"+post2[k]),-1)
        hQCD_7jetggH.Add(fDYS.Get("QCD3ggH/ZTT"+post2[k]),-1)
        hQCD_7jetggH.SetName("QCD"+postfix2[k])
        hQCD_7jetggH.Scale(factor2jet)
        for i in range(0,hQCD_7jetggH.GetSize()-2):
            if hQCD_7jetggH.GetBinContent(i)<0:
                hQCD_7jetggH.SetBinError(i,max(0,hQCD_7jetggH.GetBinError(i)+hQCD_7jetggH.GetBinError(i)))
                hQCD_7jetggH.SetBinContent(i,0)


        hSS_37jetggH=fData.Get("SS33ggH/data_obs")
        hSS_37jetggH.Add(fDYJ.Get("SS33ggH/ZJ"+post2[k]),-1)
        hSS_37jetggH.Add(fDYL.Get("SS33ggH/ZL"+post2[k]),-1)
        hSS_37jetggH.Add(fTTJ.Get("SS33ggH/TTJ"+post2[k]),-1)
        hSS_37jetggH.Add(fTTT.Get("SS33ggH/TTT"+post2[k]),-1)
        hSS_37jetggH.Add(fW.Get("SS33ggH/W"+postfix2[k]),-1)
        hSS_37jetggH.Add(fVV.Get("SS33ggH/VV"+post2[k]),-1)
        hSS_37jetggH.Add(fDYS.Get("SS33ggH/ZTT"+post2[k]),-1)
        hSS_37jetggH.SetName("QCD"+postfix2[k])
        hSS_37jetggH.Scale(factor2jet)
        for i in range(0,hSS_37jetggH.GetSize()-2):
            if hSS_37jetggH.GetBinContent(i)<0:
                hSS_37jetggH.SetBinError(i,max(0,hSS_37jetggH.GetBinError(i)+hSS_37jetggH.GetBinError(i)))
                hSS_37jetggH.SetBinContent(i,0)

        hQCD_37jetggH=fData.Get("QCD33ggH/data_obs")
        hQCD_37jetggH.Add(fDYJ.Get("QCD33ggH/ZJ"+post2[k]),-1)
        hQCD_37jetggH.Add(fDYL.Get("QCD33ggH/ZL"+post2[k]),-1)
        hQCD_37jetggH.Add(fTTJ.Get("QCD33ggH/TTJ"+post2[k]),-1)
        hQCD_37jetggH.Add(fTTT.Get("QCD33ggH/TTT"+post2[k]),-1)
        hQCD_37jetggH.Add(fW.Get("QCD33ggH/W"+postfix2[k]),-1)
        hQCD_37jetggH.Add(fVV.Get("QCD33ggH/VV"+post2[k]),-1)
        hQCD_37jetggH.Add(fDYS.Get("QCD33ggH/ZTT"+post2[k]),-1)
        hQCD_37jetggH.SetName("QCD"+postfix2[k])
        hQCD_37jetggH.Scale(factor2jet)
        for i in range(0,hQCD_37jetggH.GetSize()-2):
            if hQCD_37jetggH.GetBinContent(i)<0:
                hQCD_37jetggH.SetBinError(i,max(0,hQCD_37jetggH.GetBinError(i)+hQCD_37jetggH.GetBinError(i)))
                hQCD_37jetggH.SetBinContent(i,0)


        hSS_47jetggH=fData.Get("SS43ggH/data_obs")
        hSS_47jetggH.Add(fDYJ.Get("SS43ggH/ZJ"+post2[k]),-1)
        hSS_47jetggH.Add(fDYL.Get("SS43ggH/ZL"+post2[k]),-1)
        hSS_47jetggH.Add(fTTJ.Get("SS43ggH/TTJ"+post2[k]),-1)
        hSS_47jetggH.Add(fTTT.Get("SS43ggH/TTT"+post2[k]),-1)
        hSS_47jetggH.Add(fW.Get("SS43ggH/W"+postfix2[k]),-1)
        hSS_47jetggH.Add(fVV.Get("SS43ggH/VV"+post2[k]),-1)
        hSS_47jetggH.Add(fDYS.Get("SS43ggH/ZTT"+post2[k]),-1)
        hSS_47jetggH.SetName("QCD"+postfix2[k])
        hSS_47jetggH.Scale(factor2jet)
        for i in range(0,hSS_47jetggH.GetSize()-2):
            if hSS_47jetggH.GetBinContent(i)<0:
                hSS_47jetggH.SetBinError(i,max(0,hSS_47jetggH.GetBinError(i)+hSS_47jetggH.GetBinError(i)))
                hSS_47jetggH.SetBinContent(i,0)

        hQCD_47jetggH=fData.Get("QCD43ggH/data_obs")
        hQCD_47jetggH.Add(fDYJ.Get("QCD43ggH/ZJ"+post2[k]),-1)
        hQCD_47jetggH.Add(fDYL.Get("QCD43ggH/ZL"+post2[k]),-1)
        hQCD_47jetggH.Add(fTTJ.Get("QCD43ggH/TTJ"+post2[k]),-1)
        hQCD_47jetggH.Add(fTTT.Get("QCD43ggH/TTT"+post2[k]),-1)
        hQCD_47jetggH.Add(fW.Get("QCD43ggH/W"+postfix2[k]),-1)
        hQCD_47jetggH.Add(fVV.Get("QCD43ggH/VV"+post2[k]),-1)
        hQCD_47jetggH.Add(fDYS.Get("QCD43ggH/ZTT"+post2[k]),-1)
        hQCD_47jetggH.SetName("QCD"+postfix2[k])
        hQCD_47jetggH.Scale(factor2jet)
        for i in range(0,hQCD_47jetggH.GetSize()-2):
            if hQCD_47jetggH.GetBinContent(i)<0:
                hQCD_47jetggH.SetBinError(i,max(0,hQCD_47jetggH.GetBinError(i)+hQCD_47jetggH.GetBinError(i)))
                hQCD_47jetggH.SetBinContent(i,0)



        hSS_57jetggH=fData.Get("SS53ggH/data_obs")
        hSS_57jetggH.Add(fDYJ.Get("SS53ggH/ZJ"+post2[k]),-1)
        hSS_57jetggH.Add(fDYL.Get("SS53ggH/ZL"+post2[k]),-1)
        hSS_57jetggH.Add(fTTJ.Get("SS53ggH/TTJ"+post2[k]),-1)
        hSS_57jetggH.Add(fTTT.Get("SS53ggH/TTT"+post2[k]),-1)
        hSS_57jetggH.Add(fW.Get("SS53ggH/W"+postfix2[k]),-1)
        hSS_57jetggH.Add(fVV.Get("SS53ggH/VV"+post2[k]),-1)
        hSS_57jetggH.Add(fDYS.Get("SS53ggH/ZTT"+post2[k]),-1)
        hSS_57jetggH.SetName("QCD"+postfix2[k])
        hSS_57jetggH.Scale(factor2jet)
        for i in range(0,hSS_57jetggH.GetSize()-2):
            if hSS_57jetggH.GetBinContent(i)<0:
                hSS_57jetggH.SetBinError(i,max(0,hSS_57jetggH.GetBinError(i)+hSS_57jetggH.GetBinError(i)))
                hSS_57jetggH.SetBinContent(i,0)

        hQCD_57jetggH=fData.Get("QCD53ggH/data_obs")
        hQCD_57jetggH.Add(fDYJ.Get("QCD53ggH/ZJ"+post2[k]),-1)
        hQCD_57jetggH.Add(fDYL.Get("QCD53ggH/ZL"+post2[k]),-1)
        hQCD_57jetggH.Add(fTTJ.Get("QCD53ggH/TTJ"+post2[k]),-1)
        hQCD_57jetggH.Add(fTTT.Get("QCD53ggH/TTT"+post2[k]),-1)
        hQCD_57jetggH.Add(fW.Get("QCD53ggH/W"+postfix2[k]),-1)
        hQCD_57jetggH.Add(fVV.Get("QCD53ggH/VV"+post2[k]),-1)
        hQCD_57jetggH.Add(fDYS.Get("QCD53ggH/ZTT"+post2[k]),-1)
        hQCD_57jetggH.SetName("QCD"+postfix2[k])
        hQCD_57jetggH.Scale(factor2jet)
        for i in range(0,hQCD_57jetggH.GetSize()-2):
            if hQCD_57jetggH.GetBinContent(i)<0:
                hQCD_57jetggH.SetBinError(i,max(0,hQCD_57jetggH.GetBinError(i)+hQCD_57jetggH.GetBinError(i)))
                hQCD_57jetggH.SetBinContent(i,0)

        hSS_67jetggH=fData.Get("SS63ggH/data_obs")
        hSS_67jetggH.Add(fDYJ.Get("SS63ggH/ZJ"+post2[k]),-1)
        hSS_67jetggH.Add(fDYL.Get("SS63ggH/ZL"+post2[k]),-1)
        hSS_67jetggH.Add(fTTJ.Get("SS63ggH/TTJ"+post2[k]),-1)
        hSS_67jetggH.Add(fTTT.Get("SS63ggH/TTT"+post2[k]),-1)
        hSS_67jetggH.Add(fW.Get("SS63ggH/W"+postfix2[k]),-1)
        hSS_67jetggH.Add(fVV.Get("SS63ggH/VV"+post2[k]),-1)
        hSS_67jetggH.Add(fDYS.Get("SS63ggH/ZTT"+post2[k]),-1)
        hSS_67jetggH.SetName("QCD"+postfix2[k])
        hSS_67jetggH.Scale(factor2jet)
        for i in range(0,hSS_67jetggH.GetSize()-2):
            if hSS_67jetggH.GetBinContent(i)<0:
                hSS_67jetggH.SetBinError(i,max(0,hSS_67jetggH.GetBinError(i)+hSS_67jetggH.GetBinError(i)))
                hSS_67jetggH.SetBinContent(i,0)

        hQCD_67jetggH=fData.Get("QCD63ggH/data_obs")
        hQCD_67jetggH.Add(fDYJ.Get("QCD63ggH/ZJ"+post2[k]),-1)
        hQCD_67jetggH.Add(fDYL.Get("QCD63ggH/ZL"+post2[k]),-1)
        hQCD_67jetggH.Add(fTTJ.Get("QCD63ggH/TTJ"+post2[k]),-1)
        hQCD_67jetggH.Add(fTTT.Get("QCD63ggH/TTT"+post2[k]),-1)
        hQCD_67jetggH.Add(fW.Get("QCD63ggH/W"+postfix2[k]),-1)
        hQCD_67jetggH.Add(fVV.Get("QCD63ggH/VV"+post2[k]),-1)
        hQCD_67jetggH.Add(fDYS.Get("QCD63ggH/ZTT"+post2[k]),-1)
        hQCD_67jetggH.SetName("QCD"+postfix2[k])
        hQCD_67jetggH.Scale(factor2jet)
        for i in range(0,hQCD_67jetggH.GetSize()-2):
            if hQCD_67jetggH.GetBinContent(i)<0:
                hQCD_67jetggH.SetBinError(i,max(0,hQCD_67jetggH.GetBinError(i)+hQCD_67jetggH.GetBinError(i)))
                hQCD_67jetggH.SetBinContent(i,0)



        hSS_77jetggH=fData.Get("SS63ggH/data_obs")
        hSS_77jetggH.Add(fDYJ.Get("SS63ggH/ZJ"+post2[k]),-1)
        hSS_77jetggH.Add(fDYL.Get("SS63ggH/ZL"+post2[k]),-1)
        hSS_77jetggH.Add(fTTJ.Get("SS63ggH/TTJ"+post2[k]),-1)
        hSS_77jetggH.Add(fTTT.Get("SS63ggH/TTT"+post2[k]),-1)
        hSS_77jetggH.Add(fW.Get("SS63ggH/W"+postfix2[k]),-1)
        hSS_77jetggH.Add(fVV.Get("SS63ggH/VV"+post2[k]),-1)
        hSS_77jetggH.Add(fDYS.Get("SS63ggH/ZTT"+post2[k]),-1)
        hSS_77jetggH.SetName("SS"+postfix2[k])
        hSS_77jetggH.Scale(factor2jet)
        for i in range(0,hSS_77jetggH.GetSize()-2):
            if hSS_77jetggH.GetBinContent(i)<0:
                hSS_77jetggH.SetBinError(i,max(0,hSS_77jetggH.GetBinError(i)+hSS_77jetggH.GetBinError(i)))
                hSS_77jetggH.SetBinContent(i,0)

        hQCD_77jetggH=fData.Get("QCD63ggH/data_obs")
        hQCD_77jetggH.Add(fDYJ.Get("QCD63ggH/ZJ"+post2[k]),-1)
        hQCD_77jetggH.Add(fDYL.Get("QCD63ggH/ZL"+post2[k]),-1)
        hQCD_77jetggH.Add(fTTJ.Get("QCD63ggH/TTJ"+post2[k]),-1)
        hQCD_77jetggH.Add(fTTT.Get("QCD63ggH/TTT"+post2[k]),-1)
        hQCD_77jetggH.Add(fW.Get("QCD63ggH/W"+postfix2[k]),-1)
        hQCD_77jetggH.Add(fVV.Get("QCD63ggH/VV"+post2[k]),-1)
        hQCD_77jetggH.Add(fDYS.Get("QCD63ggH/ZTT"+post2[k]),-1)
        hQCD_77jetggH.SetName("QCD"+postfix2[k])
        hQCD_77jetggH.Scale(factor2jet)
        for i in range(0,hQCD_77jetggH.GetSize()-2):
            if hQCD_77jetggH.GetBinContent(i)<0:
                hQCD_77jetggH.SetBinError(i,max(0,hQCD_77jetggH.GetBinError(i)+hQCD_77jetggH.GetBinError(i)))
                hQCD_77jetggH.SetBinContent(i,0)





###################### end of ggH block
######################################



        hantiCR_0jet=fData.Get("et_antiiso_0jet_crSS/data_obs")
        hantiCR_0jet.Add(fDYJ.Get("et_antiiso_0jet_crSS/ZJ"+post2[k]),-1)
        hantiCR_0jet.Add(fDYL.Get("et_antiiso_0jet_crSS/ZL"+post2[k]),-1)
        hantiCR_0jet.Add(fTTJ.Get("et_antiiso_0jet_crSS/TTJ"+post2[k]),-1)
        hantiCR_0jet.Add(fTTT.Get("et_antiiso_0jet_crSS/TTT"+post2[k]),-1)
        hantiCR_0jet.Add(fW.Get("et_antiiso_0jet_crSS/W"+postfix0[k]),-1)
        hantiCR_0jet.Add(fVV.Get("et_antiiso_0jet_crSS/VV"+post2[k]),-1)
        hantiCR_0jet.Add(fDYS.Get("et_antiiso_0jet_crSS/ZTT"+post2[k]),-1)
        hantiCR_0jet.SetName("QCD"+postfix2[k])
        hantiCR_0jet.Scale(factor0jet)
        for i in range(0,hantiCR_0jet.GetSize()-2):
            if hantiCR_0jet.GetBinContent(i)<0:
                hantiCR_0jet.SetBinError(i,max(0,hantiCR_0jet.GetBinError(i)+hantiCR_0jet.GetBinError(i)))
                hantiCR_0jet.SetBinContent(i,0)

        hantiCR_1jet=fData.Get("et_antiiso_boosted_crSS/data_obs")
        hantiCR_1jet.Add(fDYJ.Get("et_antiiso_boosted_crSS/ZJ"+post2[k]),-1)
        hantiCR_1jet.Add(fDYL.Get("et_antiiso_boosted_crSS/ZL"+post2[k]),-1)
        hantiCR_1jet.Add(fTTJ.Get("et_antiiso_boosted_crSS/TTJ"+post2[k]),-1)
        hantiCR_1jet.Add(fTTT.Get("et_antiiso_boosted_crSS/TTT"+post2[k]),-1)
        hantiCR_1jet.Add(fW.Get("et_antiiso_boosted_crSS/W"+postfix1[k]),-1)
        hantiCR_1jet.Add(fVV.Get("et_antiiso_boosted_crSS/VV"+post2[k]),-1)
        hantiCR_1jet.Add(fDYS.Get("et_antiiso_boosted_crSS/ZTT"+post2[k]),-1)
        hantiCR_1jet.SetName("QCD"+postfix2[k])
        hantiCR_1jet.Scale(factor1jet)
        for i in range(0,hantiCR_1jet.GetSize()-2):
            if hantiCR_1jet.GetBinContent(i)<0:
                hantiCR_1jet.SetBinError(i,max(0,hantiCR_1jet.GetBinError(i)+hantiCR_1jet.GetBinError(i)))
                hantiCR_1jet.SetBinContent(i,0)

        hantiCR_2jet=fData.Get("et_antiiso_vbf_crSS/data_obs")
        hantiCR_2jet.Add(fDYJ.Get("et_antiiso_vbf_crSS/ZJ"+post2[k]),-1)
        hantiCR_2jet.Add(fDYL.Get("et_antiiso_vbf_crSS/ZL"+post2[k]),-1)
        hantiCR_2jet.Add(fTTJ.Get("et_antiiso_vbf_crSS/TTJ"+post2[k]),-1)
        hantiCR_2jet.Add(fTTT.Get("et_antiiso_vbf_crSS/TTT"+post2[k]),-1)
        hantiCR_2jet.Add(fW.Get("et_antiiso_vbf_crSS/W"+postfix2[k]),-1)
        hantiCR_2jet.Add(fVV.Get("et_antiiso_vbf_crSS/VV"+post2[k]),-1)
        hantiCR_2jet.Add(fDYS.Get("et_antiiso_vbf_crSS/ZTT"+post2[k]),-1)
        hantiCR_2jet.SetName("QCD"+postfix2[k])
        hantiCR_2jet.Scale(factor2jet)
        for i in range(0,hantiCR_2jet.GetSize()-2):
            if hantiCR_2jet.GetBinContent(i)<0:
                hantiCR_2jet.SetBinError(i,max(0,hantiCR_2jet.GetBinError(i)+hantiCR_2jet.GetBinError(i)))
                hantiCR_2jet.SetBinContent(i,0)

        hwjetsCR_0jet=fData.Get("et_wjets_0jet_crSS/data_obs")
        hwjetsCR_0jet.Add(fDYJ.Get("et_wjets_0jet_crSS/ZJ"+post2[k]),-1)
        hwjetsCR_0jet.Add(fDYL.Get("et_wjets_0jet_crSS/ZL"+post2[k]),-1)
        hwjetsCR_0jet.Add(fTTJ.Get("et_wjets_0jet_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_0jet.Add(fTTT.Get("et_wjets_0jet_crSS/TTT"+post2[k]),-1)
        hwjetsCR_0jet.Add(fW.Get("et_wjets_0jet_crSS/W"+postfix0[k]),-1)
        hwjetsCR_0jet.Add(fVV.Get("et_wjets_0jet_crSS/VV"+post2[k]),-1)
        hwjetsCR_0jet.Add(fDYS.Get("et_wjets_0jet_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_0jet.SetName("QCD"+postfix2[k])
        hwjetsCR_0jet.Scale(factor0jet)
        for i in range(0,hwjetsCR_0jet.GetSize()-2):
            if hwjetsCR_0jet.GetBinContent(i)<0:
                hwjetsCR_0jet.SetBinError(i,max(0,hwjetsCR_0jet.GetBinError(i)+hwjetsCR_0jet.GetBinError(i)))
                hwjetsCR_0jet.SetBinContent(i,0)

        hwjetsCR_1jet=fData.Get("et_wjets_boosted_crSS/data_obs")
        hwjetsCR_1jet.Add(fDYJ.Get("et_wjets_boosted_crSS/ZJ"+post2[k]),-1)
        hwjetsCR_1jet.Add(fDYL.Get("et_wjets_boosted_crSS/ZL"+post2[k]),-1)
        hwjetsCR_1jet.Add(fTTJ.Get("et_wjets_boosted_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_1jet.Add(fTTT.Get("et_wjets_boosted_crSS/TTT"+post2[k]),-1)
        hwjetsCR_1jet.Add(fW.Get("et_wjets_boosted_crSS/W"+postfix1[k]),-1)
        hwjetsCR_1jet.Add(fVV.Get("et_wjets_boosted_crSS/VV"+post2[k]),-1)
        hwjetsCR_1jet.Add(fDYS.Get("et_wjets_boosted_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_1jet.SetName("QCD"+postfix2[k])
        hwjetsCR_1jet.Scale(factor1jet)
        for i in range(0,hwjetsCR_1jet.GetSize()-2):
            if hwjetsCR_1jet.GetBinContent(i)<0:
                hwjetsCR_1jet.SetBinError(i,max(0,hwjetsCR_1jet.GetBinError(i)+hwjetsCR_1jet.GetBinError(i)))
                hwjetsCR_1jet.SetBinContent(i,0)

        hwjetsCR_2jet=fData.Get("et_wjets_vbf_crSS/data_obs")
        hwjetsCR_2jet.Add(fDYJ.Get("et_wjets_vbf_crSS/ZJ"+post2[k]),-1)
        hwjetsCR_2jet.Add(fDYL.Get("et_wjets_vbf_crSS/ZL"+post2[k]),-1)
        hwjetsCR_2jet.Add(fTTJ.Get("et_wjets_vbf_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_2jet.Add(fTTT.Get("et_wjets_vbf_crSS/TTT"+post2[k]),-1)
        hwjetsCR_2jet.Add(fW.Get("et_wjets_vbf_crSS/W"+postfix2[k]),-1)
        hwjetsCR_2jet.Add(fVV.Get("et_wjets_vbf_crSS/VV"+post2[k]),-1)
        hwjetsCR_2jet.Add(fDYS.Get("et_wjets_vbf_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_2jet.SetName("QCD"+postfix2[k])
        hwjetsCR_2jet.Scale(factor2jet)
        for i in range(0,hwjetsCR_2jet.GetSize()-2):
            if hwjetsCR_2jet.GetBinContent(i)<0:
                hwjetsCR_2jet.SetBinError(i,max(0,hwjetsCR_2jet.GetBinError(i)+hwjetsCR_2jet.GetBinError(i)))
                hwjetsCR_2jet.SetBinContent(i,0)

        print hQCD_3jet.Integral()+hQCD_4jet.Integral()+hQCD_5jet.Integral()+hQCD_7jet.Integral()
        print hQCD_53jet.Integral()+hQCD_54jet.Integral()+hQCD_55jet.Integral()+hQCD_57jet.Integral()
        print hQCD_63jet.Integral()+hQCD_64jet.Integral()+hQCD_65jet.Integral()+hQCD_67jet.Integral()
        print hQCD_73jet.Integral()+hQCD_74jet.Integral()+hQCD_75jet.Integral()+hQCD_77jet.Integral()

        print hSS_3jet.Integral()+hSS_4jet.Integral()+hSS_5jet.Integral()+hSS_7jet.Integral()
        print hSS_53jet.Integral()+hSS_54jet.Integral()+hSS_55jet.Integral()+hSS_57jet.Integral()
        print hSS_63jet.Integral()+hSS_64jet.Integral()+hSS_65jet.Integral()+hSS_67jet.Integral()
        print hSS_73jet.Integral()+hSS_74jet.Integral()+hSS_75jet.Integral()+hSS_77jet.Integral()

        fout.cd()
        dir0jet.cd()
        hQCD_0jet.Scale(hSS_0jet.Integral()/hQCD_0jet.Integral())
        hQCD_0jet.Write()

        dir1jet.cd()
        hQCD_1jet.Scale(hSS_1jet.Integral()/(hQCD_1jet.Integral()+0.00001))
        hQCD_1jet.Write()

        dir2jet.cd()
        hQCD_2jet.Scale(hSS_2jet.Integral()/(hQCD_2jet.Integral()+0.00001))
        hQCD_2jet.Write()


######################
        dir3jetggH.cd()
        hQCD_3jetggH.Scale(hSS_3jetggH.Integral()/(hQCD_3jetggH.Integral()+0.00001))
        hQCD_3jetggH.Write()

        dir4jetggH.cd()
        hQCD_4jetggH.Scale(hSS_4jetggH.Integral()/(hQCD_4jetggH.Integral()+0.00001))
        hQCD_4jetggH.Write()

        dir5jetggH.cd()
        hQCD_5jetggH.Scale(hSS_5jetggH.Integral()/(hQCD_5jetggH.Integral()+0.00001))
        hQCD_5jetggH.Write()

        dir7jetggH.cd()
        hQCD_7jetggH.Scale(hSS_7jetggH.Integral()/(hQCD_7jetggH.Integral()+0.00001))
        hQCD_7jetggH.Write()

        dir33jetggH.cd()
        hQCD_33jetggH.Scale(hSS_33jetggH.Integral()/(hQCD_33jetggH.Integral()+0.00001))
        hQCD_33jetggH.Write()

        dir34jetggH.cd()
        hQCD_34jetggH.Scale(hSS_34jetggH.Integral()/(hQCD_34jetggH.Integral()+0.00001))
        hQCD_34jetggH.Write()

        dir35jetggH.cd()
        hQCD_35jetggH.Scale(hSS_35jetggH.Integral()/(hQCD_35jetggH.Integral()+0.00001))
        hQCD_35jetggH.Write()

        dir37jetggH.cd()
        hQCD_37jetggH.Scale(hSS_37jetggH.Integral()/(hQCD_37jetggH.Integral()+0.00001))
        hQCD_37jetggH.Write()

        dir43jetggH.cd()
        hQCD_33jetggH.Scale(hSS_33jetggH.Integral()/(hQCD_33jetggH.Integral()+0.00001))
        hQCD_33jetggH.Write()

        dir44jetggH.cd()
        hQCD_34jetggH.Scale(hSS_34jetggH.Integral()/(hQCD_34jetggH.Integral()+0.00001))
        hQCD_34jetggH.Write()

        dir45jetggH.cd()
        hQCD_35jetggH.Scale(hSS_35jetggH.Integral()/(hQCD_35jetggH.Integral()+0.00001))
        hQCD_35jetggH.Write()

        dir47jetggH.cd()
        hQCD_37jetggH.Scale(hSS_37jetggH.Integral()/(hQCD_37jetggH.Integral()+0.00001))
        hQCD_37jetggH.Write()


        dir53jetggH.cd()
        hQCD_53jetggH.Scale(hSS_53jetggH.Integral()/(hQCD_53jetggH.Integral()+0.00001))
        hQCD_53jetggH.Write()

        dir54jetggH.cd()
        hQCD_54jetggH.Scale(hSS_54jetggH.Integral()/(hQCD_54jetggH.Integral()+0.00001))
        hQCD_54jetggH.Write()

        dir55jetggH.cd()
        hQCD_55jetggH.Scale(hSS_55jetggH.Integral()/(hQCD_55jetggH.Integral()+0.00001))
        hQCD_55jetggH.Write()

        dir57jetggH.cd()
        hQCD_57jetggH.Scale(hSS_57jetggH.Integral()/(hQCD_57jetggH.Integral()+0.00001))
        hQCD_57jetggH.Write()

        dir63jetggH.cd()
        hQCD_63jetggH.Scale(hSS_63jetggH.Integral()/(hQCD_63jetggH.Integral()+0.00001))
        hQCD_63jetggH.Write()

        dir64jetggH.cd()
        hQCD_64jetggH.Scale(hSS_64jetggH.Integral()/(hQCD_64jetggH.Integral()+0.00001))
        hQCD_64jetggH.Write()

        dir65jetggH.cd()
        hQCD_65jetggH.Scale(hSS_65jetggH.Integral()/(hQCD_65jetggH.Integral()+0.00001))
        hQCD_65jetggH.Write()

        dir67jetggH.cd()
        hQCD_67jetggH.Scale(hSS_67jetggH.Integral()/(hQCD_67jetggH.Integral()+0.00001))
        hQCD_67jetggH.Write()

        dir73jetggH.cd()
        hQCD_73jetggH.Scale(hSS_73jetggH.Integral()/(hQCD_73jetggH.Integral()+0.00001))
        hQCD_73jetggH.Write()

        dir74jetggH.cd()
        hQCD_74jetggH.Scale(hSS_74jetggH.Integral()/(hQCD_74jetggH.Integral()+0.00001))
        hQCD_74jetggH.Write()

        dir75jetggH.cd()
        hQCD_75jetggH.Scale(hSS_75jetggH.Integral()/(hQCD_75jetggH.Integral()+0.00001))
        hQCD_75jetggH.Write()

        dir77jetggH.cd()
        hQCD_77jetggH.Scale(hSS_77jetggH.Integral()/(hQCD_77jetggH.Integral()+0.00001))
        hQCD_77jetggH.Write()


######################## ggh block



        dir3jet.cd()
        hQCD_3jet.Scale(hSS_3jet.Integral()/(hQCD_3jet.Integral()+0.00001))
        hQCD_3jet.Write()

        dir4jet.cd()
        hQCD_4jet.Scale(hSS_4jet.Integral()/(hQCD_4jet.Integral()+0.00001))
        hQCD_4jet.Write()

        dir5jet.cd()
        hQCD_5jet.Scale(hSS_5jet.Integral()/(hQCD_5jet.Integral()+0.00001))
        hQCD_5jet.Write()

        dir7jet.cd()
        hQCD_7jet.Scale(hSS_7jet.Integral()/(hQCD_7jet.Integral()+0.00001))
        hQCD_7jet.Write()

        dir53jet.cd()
        hQCD_53jet.Scale(hSS_53jet.Integral()/(hQCD_53jet.Integral()+0.00001))
        hQCD_53jet.Write()

        dir54jet.cd()
        hQCD_54jet.Scale(hSS_54jet.Integral()/(hQCD_54jet.Integral()+0.00001))
        hQCD_54jet.Write()

        dir55jet.cd()
        hQCD_55jet.Scale(hSS_55jet.Integral()/(hQCD_55jet.Integral()+0.00001))
        hQCD_55jet.Write()

        dir57jet.cd()
        hQCD_57jet.Scale(hSS_57jet.Integral()/(hQCD_57jet.Integral()+0.00001))
        hQCD_57jet.Write()

        dir63jet.cd()
        hQCD_63jet.Scale(hSS_63jet.Integral()/(hQCD_63jet.Integral()+0.00001))
        hQCD_63jet.Write()

        dir64jet.cd()
        hQCD_64jet.Scale(hSS_64jet.Integral()/(hQCD_64jet.Integral()+0.00001))
        hQCD_64jet.Write()

        dir65jet.cd()
        hQCD_65jet.Scale(hSS_65jet.Integral()/(hQCD_65jet.Integral()+0.00001))
        hQCD_65jet.Write()

        dir67jet.cd()
        hQCD_67jet.Scale(hSS_67jet.Integral()/(hQCD_67jet.Integral()+0.00001))
        hQCD_67jet.Write()

        dir73jet.cd()
        hQCD_73jet.Scale(hSS_73jet.Integral()/(hQCD_73jet.Integral()+0.00001))
        hQCD_73jet.Write()

        dir74jet.cd()
        hQCD_74jet.Scale(hSS_74jet.Integral()/(hQCD_74jet.Integral()+0.00001))
        hQCD_74jet.Write()

        dir75jet.cd()
        hQCD_75jet.Scale(hSS_75jet.Integral()/(hQCD_75jet.Integral()+0.00001))
        hQCD_75jet.Write()

        dir77jet.cd()
        hQCD_77jet.Scale(hSS_77jet.Integral()/(hQCD_77jet.Integral()+0.00001))
        hQCD_77jet.Write()


        dirWCR0jet.cd()
        hwjetsCR_0jet.Write()

        dirWCR1jet.cd()
        hwjetsCR_1jet.Write()

        dirWCR2jet.cd()
        hwjetsCR_2jet.Write()

        dirQCDCR0jet.cd()
        hantiCR_0jet.Write()

        dirQCDCR1jet.cd()
        hantiCR_1jet.Write()

        dirQCDCR2jet.cd()
        hantiCR_2jet.Write()

