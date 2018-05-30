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
    dir0jet=fout.mkdir("mt_0jet")
    dir1jet=fout.mkdir("mt_boosted")
    dir2jet=fout.mkdir("et_vbf")
    dirWCR0jet=fout.mkdir("mt_wjets_0jet_cr")
    dirWCR1jet=fout.mkdir("mt_wjets_boosted_cr")
    dirWCR2jet=fout.mkdir("mt_wjets_vbf_cr")
    dirQCDCR0jet=fout.mkdir("mt_antiiso_0jet_cr")
    dirQCDCR1jet=fout.mkdir("mt_antiiso_boosted_cr")
    dirQCDCR2jet=fout.mkdir("mt_antiiso_vbf_cr")
    
    

    dir20jetggH=fout.mkdir("mt_vbf_D0_0p0to0p2_ggH")
    dir21jetggH=fout.mkdir("mt_vbf_D0_0p2to0p4_ggH")
    dir22jetggH=fout.mkdir("mt_vbf_D0_0p4to0p8_ggH")
    dir23jetggH=fout.mkdir("mt_vbf_D0_0p8to1p0_ggH")


    dir30jetggH=fout.mkdir("mt_vbf_D0_0p0to0p2_DCPm_ggH")
    dir31jetggH=fout.mkdir("mt_vbf_D0_0p2to0p4_DCPm_ggH")
    dir32jetggH=fout.mkdir("mt_vbf_D0_0p4to0p8_DCPm_ggH")
    dir33jetggH=fout.mkdir("mt_vbf_D0_0p8to1p0_DCPm_ggH")

    dir40jetggH =fout.mkdir("mt_vbf_D0_Pito1p5m_ggH");
    dir41jetggH =fout.mkdir("mt_vbf_D0_1p5to0_ggH");
    dir42jetggH =fout.mkdir("mt_vbf_D0_0to1p5p_ggH");
    dir43jetggH =fout.mkdir("mt_vbf_D0_1p5toPi_ggH");

    dir50jetggH =fout.mkdir("mt_vbf_Pito1p6m_ggH");
    dir51jetggH =fout.mkdir("mt_vbf_1p6to0_ggH");
    dir52jetggH =fout.mkdir("mt_vbf_0to1p6p_ggH");
    dir53jetggH =fout.mkdir("mt_vbf_1p6toPi_ggH");

    dir60jetggH =fout.mkdir("mt_vbf_Pito1p6m_ggH_Uns");
    dir61jetggH =fout.mkdir("mt_vbf_1p6to0_ggH_Uns");
    dir62jetggH =fout.mkdir("mt_vbf_0to1p6p_ggH_Uns");
    dir63jetggH =fout.mkdir("mt_vbf_1p6toPi_ggH_Uns");

    dir70jetggH =fout.mkdir("mt_vbf_dPhia_ggH");
    dir71jetggH =fout.mkdir("mt_vbf_dPhib_ggH");
    dir72jetggH =fout.mkdir("mt_vbf_dPhic_ggH");
    dir73jetggH =fout.mkdir("mt_vbf_dPhid_ggH");

    dir20jet=fout.mkdir("mt_vbf_D0_0p0to0p2")
    dir21jet=fout.mkdir("mt_vbf_D0_0p2to0p4")
    dir22jet=fout.mkdir("mt_vbf_D0_0p4to0p8")
    dir23jet=fout.mkdir("mt_vbf_D0_0p8to1p0")

    dir30jet=fout.mkdir("mt_vbf_D0hplus_0p0to0p2")
    dir31jet=fout.mkdir("mt_vbf_D0hplus_0p2to0p4")
    dir32jet=fout.mkdir("mt_vbf_D0hplus_0p4to0p8")
    dir33jet=fout.mkdir("mt_vbf_D0hplus_0p8to1p0")

    dir40jet=fout.mkdir("mt_vbf_DL1_0p0to0p2")
    dir41jet=fout.mkdir("mt_vbf_DL1_0p2to0p4")
    dir42jet=fout.mkdir("mt_vbf_DL1_0p4to0p8")
    dir43jet=fout.mkdir("mt_vbf_DL1_0p8to1p0")

    dir50jet=fout.mkdir("mt_vbf_DL1Zg_0p0to0p2")
    dir51jet=fout.mkdir("mt_vbf_DL1Zg_0p2to0p4")
    dir52jet=fout.mkdir("mt_vbf_DL1Zg_0p4to0p8")
    dir53jet=fout.mkdir("mt_vbf_DL1Zg_0p8to1p0")


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










        hSS_20jet=fData.Get("SS20/data_obs")
        hSS_20jet.Add(fDYJ.Get("SS20/ZJ"+post2[k]),-1)
        hSS_20jet.Add(fDYL.Get("SS20/ZL"+post2[k]),-1)
        hSS_20jet.Add(fTTJ.Get("SS20/TTJ"+post2[k]),-1)
        hSS_20jet.Add(fTTT.Get("SS20/TTT"+post2[k]),-1)
        hSS_20jet.Add(fW.Get("SS20/W"+postfix2[k]),-1)
        hSS_20jet.Add(fVV.Get("SS20/VV"+post2[k]),-1)
        hSS_20jet.Add(fDYS.Get("SS20/ZTT"+post2[k]),-1)
        hSS_20jet.SetName("QCD"+postfix2[k])
        hSS_20jet.Scale(factor2jet)
        for i in range(0,hSS_20jet.GetSize()-2):
            if hSS_20jet.GetBinContent(i)<0:
                hSS_20jet.SetBinError(i,max(0,hSS_20jet.GetBinError(i)+hSS_20jet.GetBinError(i)))
                hSS_20jet.SetBinContent(i,0)

        hQCD_20jet=fData.Get("QCD20/data_obs")
        hQCD_20jet.Add(fDYJ.Get("QCD20/ZJ"+post2[k]),-1)
        hQCD_20jet.Add(fDYL.Get("QCD20/ZL"+post2[k]),-1)
        hQCD_20jet.Add(fTTJ.Get("QCD20/TTJ"+post2[k]),-1)
        hQCD_20jet.Add(fTTT.Get("QCD20/TTT"+post2[k]),-1)
        hQCD_20jet.Add(fW.Get("QCD20/W"+postfix2[k]),-1)
        hQCD_20jet.Add(fVV.Get("QCD20/VV"+post2[k]),-1)
        hQCD_20jet.Add(fDYS.Get("QCD20/ZTT"+post2[k]),-1)
        hQCD_20jet.SetName("QCD"+postfix2[k])
        hQCD_20jet.Scale(factor2jet)
        for i in range(0,hQCD_20jet.GetSize()-2):
            if hQCD_20jet.GetBinContent(i)<0:
                hQCD_20jet.SetBinError(i,max(0,hQCD_20jet.GetBinError(i)+hQCD_20jet.GetBinError(i)))
                hQCD_20jet.SetBinContent(i,0)

        hSS_21jet=fData.Get("SS21/data_obs")
        hSS_21jet.Add(fDYJ.Get("SS21/ZJ"+post2[k]),-1)
        hSS_21jet.Add(fDYL.Get("SS21/ZL"+post2[k]),-1)
        hSS_21jet.Add(fTTJ.Get("SS21/TTJ"+post2[k]),-1)
        hSS_21jet.Add(fTTT.Get("SS21/TTT"+post2[k]),-1)
        hSS_21jet.Add(fW.Get("SS21/W"+postfix2[k]),-1)
        hSS_21jet.Add(fVV.Get("SS21/VV"+post2[k]),-1)
        hSS_21jet.Add(fDYS.Get("SS21/ZTT"+post2[k]),-1)
        hSS_21jet.SetName("QCD"+postfix2[k])
        hSS_21jet.Scale(factor2jet)
        for i in range(0,hSS_21jet.GetSize()-2):
            if hSS_21jet.GetBinContent(i)<0:
                hSS_21jet.SetBinError(i,max(0,hSS_21jet.GetBinError(i)+hSS_21jet.GetBinError(i)))
                hSS_21jet.SetBinContent(i,0)

        hQCD_21jet=fData.Get("QCD21/data_obs")
        hQCD_21jet.Add(fDYJ.Get("QCD21/ZJ"+post2[k]),-1)
        hQCD_21jet.Add(fDYL.Get("QCD21/ZL"+post2[k]),-1)
        hQCD_21jet.Add(fTTJ.Get("QCD21/TTJ"+post2[k]),-1)
        hQCD_21jet.Add(fTTT.Get("QCD21/TTT"+post2[k]),-1)
        hQCD_21jet.Add(fW.Get("QCD21/W"+postfix2[k]),-1)
        hQCD_21jet.Add(fVV.Get("QCD21/VV"+post2[k]),-1)
        hQCD_21jet.Add(fDYS.Get("QCD21/ZTT"+post2[k]),-1)
        hQCD_21jet.SetName("QCD"+postfix2[k])
        hQCD_21jet.Scale(factor2jet)
        for i in range(0,hQCD_21jet.GetSize()-2):
            if hQCD_21jet.GetBinContent(i)<0:
                hQCD_21jet.SetBinError(i,max(0,hQCD_21jet.GetBinError(i)+hQCD_21jet.GetBinError(i)))
                hQCD_21jet.SetBinContent(i,0)


        hSS_22jet=fData.Get("SS22/data_obs")
        hSS_22jet.Add(fDYJ.Get("SS22/ZJ"+post2[k]),-1)
        hSS_22jet.Add(fDYL.Get("SS22/ZL"+post2[k]),-1)
        hSS_22jet.Add(fTTJ.Get("SS22/TTJ"+post2[k]),-1)
        hSS_22jet.Add(fTTT.Get("SS22/TTT"+post2[k]),-1)
        hSS_22jet.Add(fW.Get("SS22/W"+postfix2[k]),-1)
        hSS_22jet.Add(fVV.Get("SS22/VV"+post2[k]),-1)
        hSS_22jet.Add(fDYS.Get("SS22/ZTT"+post2[k]),-1)
        hSS_22jet.SetName("QCD"+postfix2[k])
        hSS_22jet.Scale(factor2jet)
        for i in range(0,hSS_22jet.GetSize()-2):
            if hSS_22jet.GetBinContent(i)<0:
                hSS_22jet.SetBinError(i,max(0,hSS_22jet.GetBinError(i)+hSS_22jet.GetBinError(i)))
                hSS_22jet.SetBinContent(i,0)

        hQCD_22jet=fData.Get("QCD22/data_obs")
        hQCD_22jet.Add(fDYJ.Get("QCD22/ZJ"+post2[k]),-1)
        hQCD_22jet.Add(fDYL.Get("QCD22/ZL"+post2[k]),-1)
        hQCD_22jet.Add(fTTJ.Get("QCD22/TTJ"+post2[k]),-1)
        hQCD_22jet.Add(fTTT.Get("QCD22/TTT"+post2[k]),-1)
        hQCD_22jet.Add(fW.Get("QCD22/W"+postfix2[k]),-1)
        hQCD_22jet.Add(fVV.Get("QCD22/VV"+post2[k]),-1)
        hQCD_22jet.Add(fDYS.Get("QCD22/ZTT"+post2[k]),-1)
        hQCD_22jet.SetName("QCD"+postfix2[k])
        hQCD_22jet.Scale(factor2jet)
        for i in range(0,hQCD_22jet.GetSize()-2):
            if hQCD_22jet.GetBinContent(i)<0:
                hQCD_22jet.SetBinError(i,max(0,hQCD_22jet.GetBinError(i)+hQCD_22jet.GetBinError(i)))
                hQCD_22jet.SetBinContent(i,0)


        hSS_23jet=fData.Get("SS23/data_obs")
        hSS_23jet.Add(fDYJ.Get("SS23/ZJ"+post2[k]),-1)
        hSS_23jet.Add(fDYL.Get("SS23/ZL"+post2[k]),-1)
        hSS_23jet.Add(fTTJ.Get("SS23/TTJ"+post2[k]),-1)
        hSS_23jet.Add(fTTT.Get("SS23/TTT"+post2[k]),-1)
        hSS_23jet.Add(fW.Get("SS23/W"+postfix2[k]),-1)
        hSS_23jet.Add(fVV.Get("SS23/VV"+post2[k]),-1)
        hSS_23jet.Add(fDYS.Get("SS23/ZTT"+post2[k]),-1)
        hSS_23jet.SetName("QCD"+postfix2[k])
        hSS_23jet.Scale(factor2jet)
        for i in range(0,hSS_23jet.GetSize()-2):
            if hSS_23jet.GetBinContent(i)<0:
                hSS_23jet.SetBinError(i,max(0,hSS_23jet.GetBinError(i)+hSS_23jet.GetBinError(i)))
                hSS_23jet.SetBinContent(i,0)

        hQCD_23jet=fData.Get("QCD23/data_obs")
        hQCD_23jet.Add(fDYJ.Get("QCD23/ZJ"+post2[k]),-1)
        hQCD_23jet.Add(fDYL.Get("QCD23/ZL"+post2[k]),-1)
        hQCD_23jet.Add(fTTJ.Get("QCD23/TTJ"+post2[k]),-1)
        hQCD_23jet.Add(fTTT.Get("QCD23/TTT"+post2[k]),-1)
        hQCD_23jet.Add(fW.Get("QCD23/W"+postfix2[k]),-1)
        hQCD_23jet.Add(fVV.Get("QCD23/VV"+post2[k]),-1)
        hQCD_23jet.Add(fDYS.Get("QCD23/ZTT"+post2[k]),-1)
        hQCD_23jet.SetName("QCD"+postfix2[k])
        hQCD_23jet.Scale(factor2jet)
        for i in range(0,hQCD_23jet.GetSize()-2):
            if hQCD_23jet.GetBinContent(i)<0:
                hQCD_23jet.SetBinError(i,max(0,hQCD_23jet.GetBinError(i)+hQCD_23jet.GetBinError(i)))
                hQCD_23jet.SetBinContent(i,0)




        hSS_30jet=fData.Get("SS30/data_obs")
        hSS_30jet.Add(fDYJ.Get("SS30/ZJ"+post2[k]),-1)
        hSS_30jet.Add(fDYL.Get("SS30/ZL"+post2[k]),-1)
        hSS_30jet.Add(fTTJ.Get("SS30/TTJ"+post2[k]),-1)
        hSS_30jet.Add(fTTT.Get("SS30/TTT"+post2[k]),-1)
        hSS_30jet.Add(fW.Get("SS30/W"+postfix2[k]),-1)
        hSS_30jet.Add(fVV.Get("SS30/VV"+post2[k]),-1)
        hSS_30jet.Add(fDYS.Get("SS30/ZTT"+post2[k]),-1)
        hSS_30jet.SetName("QCD"+postfix2[k])
        hSS_30jet.Scale(factor2jet)
        for i in range(0,hSS_30jet.GetSize()-2):
            if hSS_30jet.GetBinContent(i)<0:
                hSS_30jet.SetBinError(i,max(0,hSS_30jet.GetBinError(i)+hSS_30jet.GetBinError(i)))
                hSS_30jet.SetBinContent(i,0)

        hQCD_30jet=fData.Get("QCD30/data_obs")
        hQCD_30jet.Add(fDYJ.Get("QCD30/ZJ"+post2[k]),-1)
        hQCD_30jet.Add(fDYL.Get("QCD30/ZL"+post2[k]),-1)
        hQCD_30jet.Add(fTTJ.Get("QCD30/TTJ"+post2[k]),-1)
        hQCD_30jet.Add(fTTT.Get("QCD30/TTT"+post2[k]),-1)
        hQCD_30jet.Add(fW.Get("QCD30/W"+postfix2[k]),-1)
        hQCD_30jet.Add(fVV.Get("QCD30/VV"+post2[k]),-1)
        hQCD_30jet.Add(fDYS.Get("QCD30/ZTT"+post2[k]),-1)
        hQCD_30jet.SetName("QCD"+postfix2[k])
        hQCD_30jet.Scale(factor2jet)
        for i in range(0,hQCD_30jet.GetSize()-2):
            if hQCD_30jet.GetBinContent(i)<0:
                hQCD_30jet.SetBinError(i,max(0,hQCD_30jet.GetBinError(i)+hQCD_30jet.GetBinError(i)))
                hQCD_30jet.SetBinContent(i,0)

        hSS_31jet=fData.Get("SS31/data_obs")
        hSS_31jet.Add(fDYJ.Get("SS31/ZJ"+post2[k]),-1)
        hSS_31jet.Add(fDYL.Get("SS31/ZL"+post2[k]),-1)
        hSS_31jet.Add(fTTJ.Get("SS31/TTJ"+post2[k]),-1)
        hSS_31jet.Add(fTTT.Get("SS31/TTT"+post2[k]),-1)
        hSS_31jet.Add(fW.Get("SS31/W"+postfix2[k]),-1)
        hSS_31jet.Add(fVV.Get("SS31/VV"+post2[k]),-1)
        hSS_31jet.Add(fDYS.Get("SS31/ZTT"+post2[k]),-1)
        hSS_31jet.SetName("QCD"+postfix2[k])
        hSS_31jet.Scale(factor2jet)
        for i in range(0,hSS_31jet.GetSize()-2):
            if hSS_31jet.GetBinContent(i)<0:
                hSS_31jet.SetBinError(i,max(0,hSS_31jet.GetBinError(i)+hSS_31jet.GetBinError(i)))
                hSS_31jet.SetBinContent(i,0)

        hQCD_31jet=fData.Get("QCD31/data_obs")
        hQCD_31jet.Add(fDYJ.Get("QCD31/ZJ"+post2[k]),-1)
        hQCD_31jet.Add(fDYL.Get("QCD31/ZL"+post2[k]),-1)
        hQCD_31jet.Add(fTTJ.Get("QCD31/TTJ"+post2[k]),-1)
        hQCD_31jet.Add(fTTT.Get("QCD31/TTT"+post2[k]),-1)
        hQCD_31jet.Add(fW.Get("QCD31/W"+postfix2[k]),-1)
        hQCD_31jet.Add(fVV.Get("QCD31/VV"+post2[k]),-1)
        hQCD_31jet.Add(fDYS.Get("QCD31/ZTT"+post2[k]),-1)
        hQCD_31jet.SetName("QCD"+postfix2[k])
        hQCD_31jet.Scale(factor2jet)
        for i in range(0,hQCD_31jet.GetSize()-2):
            if hQCD_31jet.GetBinContent(i)<0:
                hQCD_31jet.SetBinError(i,max(0,hQCD_31jet.GetBinError(i)+hQCD_31jet.GetBinError(i)))
                hQCD_31jet.SetBinContent(i,0)


        hSS_32jet=fData.Get("SS32/data_obs")
        hSS_32jet.Add(fDYJ.Get("SS32/ZJ"+post2[k]),-1)
        hSS_32jet.Add(fDYL.Get("SS32/ZL"+post2[k]),-1)
        hSS_32jet.Add(fTTJ.Get("SS32/TTJ"+post2[k]),-1)
        hSS_32jet.Add(fTTT.Get("SS32/TTT"+post2[k]),-1)
        hSS_32jet.Add(fW.Get("SS32/W"+postfix2[k]),-1)
        hSS_32jet.Add(fVV.Get("SS32/VV"+post2[k]),-1)
        hSS_32jet.Add(fDYS.Get("SS32/ZTT"+post2[k]),-1)
        hSS_32jet.SetName("QCD"+postfix2[k])
        hSS_32jet.Scale(factor2jet)
        for i in range(0,hSS_32jet.GetSize()-2):
            if hSS_32jet.GetBinContent(i)<0:
                hSS_32jet.SetBinError(i,max(0,hSS_32jet.GetBinError(i)+hSS_32jet.GetBinError(i)))
                hSS_32jet.SetBinContent(i,0)

        hQCD_32jet=fData.Get("QCD32/data_obs")
        hQCD_32jet.Add(fDYJ.Get("QCD32/ZJ"+post2[k]),-1)
        hQCD_32jet.Add(fDYL.Get("QCD32/ZL"+post2[k]),-1)
        hQCD_32jet.Add(fTTJ.Get("QCD32/TTJ"+post2[k]),-1)
        hQCD_32jet.Add(fTTT.Get("QCD32/TTT"+post2[k]),-1)
        hQCD_32jet.Add(fW.Get("QCD32/W"+postfix2[k]),-1)
        hQCD_32jet.Add(fVV.Get("QCD32/VV"+post2[k]),-1)
        hQCD_32jet.Add(fDYS.Get("QCD32/ZTT"+post2[k]),-1)
        hQCD_32jet.SetName("QCD"+postfix2[k])
        hQCD_32jet.Scale(factor2jet)
        for i in range(0,hQCD_32jet.GetSize()-2):
            if hQCD_32jet.GetBinContent(i)<0:
                hQCD_32jet.SetBinError(i,max(0,hQCD_32jet.GetBinError(i)+hQCD_32jet.GetBinError(i)))
                hQCD_32jet.SetBinContent(i,0)


        hSS_33jet=fData.Get("SS33/data_obs")
        hSS_33jet.Add(fDYJ.Get("SS33/ZJ"+post2[k]),-1)
        hSS_33jet.Add(fDYL.Get("SS33/ZL"+post2[k]),-1)
        hSS_33jet.Add(fTTJ.Get("SS33/TTJ"+post2[k]),-1)
        hSS_33jet.Add(fTTT.Get("SS33/TTT"+post2[k]),-1)
        hSS_33jet.Add(fW.Get("SS33/W"+postfix2[k]),-1)
        hSS_33jet.Add(fVV.Get("SS33/VV"+post2[k]),-1)
        hSS_33jet.Add(fDYS.Get("SS33/ZTT"+post2[k]),-1)
        hSS_33jet.SetName("QCD"+postfix2[k])
        hSS_33jet.Scale(factor2jet)
        for i in range(0,hSS_33jet.GetSize()-2):
            if hSS_33jet.GetBinContent(i)<0:
                hSS_33jet.SetBinError(i,max(0,hSS_33jet.GetBinError(i)+hSS_33jet.GetBinError(i)))
                hSS_33jet.SetBinContent(i,0)

        hQCD_33jet=fData.Get("QCD33/data_obs")
        hQCD_33jet.Add(fDYJ.Get("QCD33/ZJ"+post2[k]),-1)
        hQCD_33jet.Add(fDYL.Get("QCD33/ZL"+post2[k]),-1)
        hQCD_33jet.Add(fTTJ.Get("QCD23/TTJ"+post2[k]),-1)
        hQCD_33jet.Add(fTTT.Get("QCD33/TTT"+post2[k]),-1)
        hQCD_33jet.Add(fW.Get("QCD33/W"+postfix2[k]),-1)
        hQCD_33jet.Add(fVV.Get("QCD33/VV"+post2[k]),-1)
        hQCD_33jet.Add(fDYS.Get("QCD33/ZTT"+post2[k]),-1)
        hQCD_33jet.SetName("QCD"+postfix2[k])
        hQCD_33jet.Scale(factor2jet)
        for i in range(0,hQCD_33jet.GetSize()-2):
            if hQCD_33jet.GetBinContent(i)<0:
                hQCD_33jet.SetBinError(i,max(0,hQCD_33jet.GetBinError(i)+hQCD_33jet.GetBinError(i)))
                hQCD_33jet.SetBinContent(i,0)



        hSS_40jet=fData.Get("SS40/data_obs")
        hSS_40jet.Add(fDYJ.Get("SS40/ZJ"+post2[k]),-1)
        hSS_40jet.Add(fDYL.Get("SS40/ZL"+post2[k]),-1)
        hSS_40jet.Add(fTTJ.Get("SS40/TTJ"+post2[k]),-1)
        hSS_40jet.Add(fTTT.Get("SS40/TTT"+post2[k]),-1)
        hSS_40jet.Add(fW.Get("SS40/W"+postfix2[k]),-1)
        hSS_40jet.Add(fVV.Get("SS40/VV"+post2[k]),-1)
        hSS_40jet.Add(fDYS.Get("SS40/ZTT"+post2[k]),-1)
        hSS_40jet.SetName("QCD"+postfix2[k])
        hSS_40jet.Scale(factor2jet)
        for i in range(0,hSS_40jet.GetSize()-2):
            if hSS_40jet.GetBinContent(i)<0:
                hSS_40jet.SetBinError(i,max(0,hSS_40jet.GetBinError(i)+hSS_40jet.GetBinError(i)))
                hSS_40jet.SetBinContent(i,0)

        hQCD_40jet=fData.Get("QCD40/data_obs")
        hQCD_40jet.Add(fDYJ.Get("QCD40/ZJ"+post2[k]),-1)
        hQCD_40jet.Add(fDYL.Get("QCD40/ZL"+post2[k]),-1)
        hQCD_40jet.Add(fTTJ.Get("QCD40/TTJ"+post2[k]),-1)
        hQCD_40jet.Add(fTTT.Get("QCD40/TTT"+post2[k]),-1)
        hQCD_40jet.Add(fW.Get("QCD40/W"+postfix2[k]),-1)
        hQCD_40jet.Add(fVV.Get("QCD40/VV"+post2[k]),-1)
        hQCD_40jet.Add(fDYS.Get("QCD40/ZTT"+post2[k]),-1)
        hQCD_40jet.SetName("QCD"+postfix2[k])
        hQCD_40jet.Scale(factor2jet)
        for i in range(0,hQCD_40jet.GetSize()-2):
            if hQCD_40jet.GetBinContent(i)<0:
                hQCD_40jet.SetBinError(i,max(0,hQCD_40jet.GetBinError(i)+hQCD_40jet.GetBinError(i)))
                hQCD_40jet.SetBinContent(i,0)

        hSS_41jet=fData.Get("SS41/data_obs")
        hSS_41jet.Add(fDYJ.Get("SS41/ZJ"+post2[k]),-1)
        hSS_41jet.Add(fDYL.Get("SS41/ZL"+post2[k]),-1)
        hSS_41jet.Add(fTTJ.Get("SS41/TTJ"+post2[k]),-1)
        hSS_41jet.Add(fTTT.Get("SS41/TTT"+post2[k]),-1)
        hSS_41jet.Add(fW.Get("SS41/W"+postfix2[k]),-1)
        hSS_41jet.Add(fVV.Get("SS41/VV"+post2[k]),-1)
        hSS_41jet.Add(fDYS.Get("SS41/ZTT"+post2[k]),-1)
        hSS_41jet.SetName("QCD"+postfix2[k])
        hSS_41jet.Scale(factor2jet)
        for i in range(0,hSS_41jet.GetSize()-2):
            if hSS_41jet.GetBinContent(i)<0:
                hSS_41jet.SetBinError(i,max(0,hSS_41jet.GetBinError(i)+hSS_41jet.GetBinError(i)))
                hSS_41jet.SetBinContent(i,0)

        hQCD_41jet=fData.Get("QCD41/data_obs")
        hQCD_41jet.Add(fDYJ.Get("QCD41/ZJ"+post2[k]),-1)
        hQCD_41jet.Add(fDYL.Get("QCD41/ZL"+post2[k]),-1)
        hQCD_41jet.Add(fTTJ.Get("QCD41/TTJ"+post2[k]),-1)
        hQCD_41jet.Add(fTTT.Get("QCD41/TTT"+post2[k]),-1)
        hQCD_41jet.Add(fW.Get("QCD41/W"+postfix2[k]),-1)
        hQCD_41jet.Add(fVV.Get("QCD41/VV"+post2[k]),-1)
        hQCD_41jet.Add(fDYS.Get("QCD41/ZTT"+post2[k]),-1)
        hQCD_41jet.SetName("QCD"+postfix2[k])
        hQCD_41jet.Scale(factor2jet)
        for i in range(0,hQCD_41jet.GetSize()-2):
            if hQCD_41jet.GetBinContent(i)<0:
                hQCD_41jet.SetBinError(i,max(0,hQCD_41jet.GetBinError(i)+hQCD_41jet.GetBinError(i)))
                hQCD_41jet.SetBinContent(i,0)


        hSS_42jet=fData.Get("SS42/data_obs")
        hSS_42jet.Add(fDYJ.Get("SS42/ZJ"+post2[k]),-1)
        hSS_42jet.Add(fDYL.Get("SS42/ZL"+post2[k]),-1)
        hSS_42jet.Add(fTTJ.Get("SS42/TTJ"+post2[k]),-1)
        hSS_42jet.Add(fTTT.Get("SS42/TTT"+post2[k]),-1)
        hSS_42jet.Add(fW.Get("SS42/W"+postfix2[k]),-1)
        hSS_42jet.Add(fVV.Get("SS42/VV"+post2[k]),-1)
        hSS_42jet.Add(fDYS.Get("SS42/ZTT"+post2[k]),-1)
        hSS_42jet.SetName("QCD"+postfix2[k])
        hSS_42jet.Scale(factor2jet)
        for i in range(0,hSS_42jet.GetSize()-2):
            if hSS_42jet.GetBinContent(i)<0:
                hSS_42jet.SetBinError(i,max(0,hSS_42jet.GetBinError(i)+hSS_42jet.GetBinError(i)))
                hSS_42jet.SetBinContent(i,0)

        hQCD_42jet=fData.Get("QCD42/data_obs")
        hQCD_42jet.Add(fDYJ.Get("QCD42/ZJ"+post2[k]),-1)
        hQCD_42jet.Add(fDYL.Get("QCD42/ZL"+post2[k]),-1)
        hQCD_42jet.Add(fTTJ.Get("QCD42/TTJ"+post2[k]),-1)
        hQCD_42jet.Add(fTTT.Get("QCD42/TTT"+post2[k]),-1)
        hQCD_42jet.Add(fW.Get("QCD42/W"+postfix2[k]),-1)
        hQCD_42jet.Add(fVV.Get("QCD42/VV"+post2[k]),-1)
        hQCD_42jet.Add(fDYS.Get("QCD42/ZTT"+post2[k]),-1)
        hQCD_42jet.SetName("QCD"+postfix2[k])
        hQCD_42jet.Scale(factor2jet)
        for i in range(0,hQCD_42jet.GetSize()-2):
            if hQCD_42jet.GetBinContent(i)<0:
                hQCD_42jet.SetBinError(i,max(0,hQCD_42jet.GetBinError(i)+hQCD_42jet.GetBinError(i)))
                hQCD_42jet.SetBinContent(i,0)


        hSS_43jet=fData.Get("SS43/data_obs")
        hSS_43jet.Add(fDYJ.Get("SS43/ZJ"+post2[k]),-1)
        hSS_43jet.Add(fDYL.Get("SS43/ZL"+post2[k]),-1)
        hSS_43jet.Add(fTTJ.Get("SS43/TTJ"+post2[k]),-1)
        hSS_43jet.Add(fTTT.Get("SS43/TTT"+post2[k]),-1)
        hSS_43jet.Add(fW.Get("SS43/W"+postfix2[k]),-1)
        hSS_43jet.Add(fVV.Get("SS43/VV"+post2[k]),-1)
        hSS_43jet.Add(fDYS.Get("SS43/ZTT"+post2[k]),-1)
        hSS_43jet.SetName("QCD"+postfix2[k])
        hSS_43jet.Scale(factor2jet)
        for i in range(0,hSS_43jet.GetSize()-2):
            if hSS_43jet.GetBinContent(i)<0:
                hSS_43jet.SetBinError(i,max(0,hSS_43jet.GetBinError(i)+hSS_43jet.GetBinError(i)))
                hSS_43jet.SetBinContent(i,0)

        hQCD_43jet=fData.Get("QCD43/data_obs")
        hQCD_43jet.Add(fDYJ.Get("QCD43/ZJ"+post2[k]),-1)
        hQCD_43jet.Add(fDYL.Get("QCD43/ZL"+post2[k]),-1)
        hQCD_43jet.Add(fTTJ.Get("QCD23/TTJ"+post2[k]),-1)
        hQCD_43jet.Add(fTTT.Get("QCD43/TTT"+post2[k]),-1)
        hQCD_43jet.Add(fW.Get("QCD43/W"+postfix2[k]),-1)
        hQCD_43jet.Add(fVV.Get("QCD43/VV"+post2[k]),-1)
        hQCD_43jet.Add(fDYS.Get("QCD43/ZTT"+post2[k]),-1)
        hQCD_43jet.SetName("QCD"+postfix2[k])
        hQCD_43jet.Scale(factor2jet)
        for i in range(0,hQCD_43jet.GetSize()-2):
            if hQCD_43jet.GetBinContent(i)<0:
                hQCD_43jet.SetBinError(i,max(0,hQCD_43jet.GetBinError(i)+hQCD_43jet.GetBinError(i)))
                hQCD_43jet.SetBinContent(i,0)


        hSS_50jet=fData.Get("SS50/data_obs")
        hSS_50jet.Add(fDYJ.Get("SS50/ZJ"+post2[k]),-1)
        hSS_50jet.Add(fDYL.Get("SS50/ZL"+post2[k]),-1)
        hSS_50jet.Add(fTTJ.Get("SS50/TTJ"+post2[k]),-1)
        hSS_50jet.Add(fTTT.Get("SS50/TTT"+post2[k]),-1)
        hSS_50jet.Add(fW.Get("SS50/W"+postfix2[k]),-1)
        hSS_50jet.Add(fVV.Get("SS50/VV"+post2[k]),-1)
        hSS_50jet.Add(fDYS.Get("SS50/ZTT"+post2[k]),-1)
        hSS_50jet.SetName("QCD"+postfix2[k])
        hSS_50jet.Scale(factor2jet)
        for i in range(0,hSS_50jet.GetSize()-2):
            if hSS_50jet.GetBinContent(i)<0:
                hSS_50jet.SetBinError(i,max(0,hSS_50jet.GetBinError(i)+hSS_50jet.GetBinError(i)))
                hSS_50jet.SetBinContent(i,0)

        hQCD_50jet=fData.Get("QCD50/data_obs")
        hQCD_50jet.Add(fDYJ.Get("QCD50/ZJ"+post2[k]),-1)
        hQCD_50jet.Add(fDYL.Get("QCD50/ZL"+post2[k]),-1)
        hQCD_50jet.Add(fTTJ.Get("QCD50/TTJ"+post2[k]),-1)
        hQCD_50jet.Add(fTTT.Get("QCD50/TTT"+post2[k]),-1)
        hQCD_50jet.Add(fW.Get("QCD50/W"+postfix2[k]),-1)
        hQCD_50jet.Add(fVV.Get("QCD50/VV"+post2[k]),-1)
        hQCD_50jet.Add(fDYS.Get("QCD50/ZTT"+post2[k]),-1)
        hQCD_50jet.SetName("QCD"+postfix2[k])
        hQCD_50jet.Scale(factor2jet)
        for i in range(0,hQCD_50jet.GetSize()-2):
            if hQCD_50jet.GetBinContent(i)<0:
                hQCD_50jet.SetBinError(i,max(0,hQCD_50jet.GetBinError(i)+hQCD_50jet.GetBinError(i)))
                hQCD_50jet.SetBinContent(i,0)

        hSS_51jet=fData.Get("SS51/data_obs")
        hSS_51jet.Add(fDYJ.Get("SS51/ZJ"+post2[k]),-1)
        hSS_51jet.Add(fDYL.Get("SS51/ZL"+post2[k]),-1)
        hSS_51jet.Add(fTTJ.Get("SS51/TTJ"+post2[k]),-1)
        hSS_51jet.Add(fTTT.Get("SS51/TTT"+post2[k]),-1)
        hSS_51jet.Add(fW.Get("SS51/W"+postfix2[k]),-1)
        hSS_51jet.Add(fVV.Get("SS51/VV"+post2[k]),-1)
        hSS_51jet.Add(fDYS.Get("SS51/ZTT"+post2[k]),-1)
        hSS_51jet.SetName("QCD"+postfix2[k])
        hSS_51jet.Scale(factor2jet)
        for i in range(0,hSS_51jet.GetSize()-2):
            if hSS_51jet.GetBinContent(i)<0:
                hSS_51jet.SetBinError(i,max(0,hSS_51jet.GetBinError(i)+hSS_51jet.GetBinError(i)))
                hSS_51jet.SetBinContent(i,0)

        hQCD_51jet=fData.Get("QCD51/data_obs")
        hQCD_51jet.Add(fDYJ.Get("QCD51/ZJ"+post2[k]),-1)
        hQCD_51jet.Add(fDYL.Get("QCD51/ZL"+post2[k]),-1)
        hQCD_51jet.Add(fTTJ.Get("QCD51/TTJ"+post2[k]),-1)
        hQCD_51jet.Add(fTTT.Get("QCD51/TTT"+post2[k]),-1)
        hQCD_51jet.Add(fW.Get("QCD51/W"+postfix2[k]),-1)
        hQCD_51jet.Add(fVV.Get("QCD51/VV"+post2[k]),-1)
        hQCD_51jet.Add(fDYS.Get("QCD51/ZTT"+post2[k]),-1)
        hQCD_51jet.SetName("QCD"+postfix2[k])
        hQCD_51jet.Scale(factor2jet)
        for i in range(0,hQCD_51jet.GetSize()-2):
            if hQCD_51jet.GetBinContent(i)<0:
                hQCD_51jet.SetBinError(i,max(0,hQCD_51jet.GetBinError(i)+hQCD_51jet.GetBinError(i)))
                hQCD_51jet.SetBinContent(i,0)


        hSS_52jet=fData.Get("SS52/data_obs")
        hSS_52jet.Add(fDYJ.Get("SS52/ZJ"+post2[k]),-1)
        hSS_52jet.Add(fDYL.Get("SS52/ZL"+post2[k]),-1)
        hSS_52jet.Add(fTTJ.Get("SS52/TTJ"+post2[k]),-1)
        hSS_52jet.Add(fTTT.Get("SS52/TTT"+post2[k]),-1)
        hSS_52jet.Add(fW.Get("SS52/W"+postfix2[k]),-1)
        hSS_52jet.Add(fVV.Get("SS52/VV"+post2[k]),-1)
        hSS_52jet.Add(fDYS.Get("SS52/ZTT"+post2[k]),-1)
        hSS_52jet.SetName("QCD"+postfix2[k])
        hSS_52jet.Scale(factor2jet)
        for i in range(0,hSS_52jet.GetSize()-2):
            if hSS_52jet.GetBinContent(i)<0:
                hSS_52jet.SetBinError(i,max(0,hSS_52jet.GetBinError(i)+hSS_52jet.GetBinError(i)))
                hSS_52jet.SetBinContent(i,0)

        hQCD_52jet=fData.Get("QCD52/data_obs")
        hQCD_52jet.Add(fDYJ.Get("QCD52/ZJ"+post2[k]),-1)
        hQCD_52jet.Add(fDYL.Get("QCD52/ZL"+post2[k]),-1)
        hQCD_52jet.Add(fTTJ.Get("QCD52/TTJ"+post2[k]),-1)
        hQCD_52jet.Add(fTTT.Get("QCD52/TTT"+post2[k]),-1)
        hQCD_52jet.Add(fW.Get("QCD52/W"+postfix2[k]),-1)
        hQCD_52jet.Add(fVV.Get("QCD52/VV"+post2[k]),-1)
        hQCD_52jet.Add(fDYS.Get("QCD52/ZTT"+post2[k]),-1)
        hQCD_52jet.SetName("QCD"+postfix2[k])
        hQCD_52jet.Scale(factor2jet)
        for i in range(0,hQCD_52jet.GetSize()-2):
            if hQCD_52jet.GetBinContent(i)<0:
                hQCD_52jet.SetBinError(i,max(0,hQCD_52jet.GetBinError(i)+hQCD_52jet.GetBinError(i)))
                hQCD_52jet.SetBinContent(i,0)


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
        hQCD_53jet.Add(fTTJ.Get("QCD23/TTJ"+post2[k]),-1)
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



##################3#ggH


        hSS_20jetggH=fData.Get("SS20ggH/data_obs")
        hSS_20jetggH.Add(fDYJ.Get("SS20ggH/ZJ"+post2[k]),-1)
        hSS_20jetggH.Add(fDYL.Get("SS20ggH/ZL"+post2[k]),-1)
        hSS_20jetggH.Add(fTTJ.Get("SS20ggH/TTJ"+post2[k]),-1)
        hSS_20jetggH.Add(fTTT.Get("SS20ggH/TTT"+post2[k]),-1)
        hSS_20jetggH.Add(fW.Get("SS20ggH/W"+postfix2[k]),-1)
        hSS_20jetggH.Add(fVV.Get("SS20ggH/VV"+post2[k]),-1)
        hSS_20jetggH.Add(fDYS.Get("SS20ggH/ZTT"+post2[k]),-1)
        hSS_20jetggH.SetName("QCD"+postfix2[k])
        hSS_20jetggH.Scale(factor2jet)
        for i in range(0,hSS_20jetggH.GetSize()-2):
            if hSS_20jetggH.GetBinContent(i)<0:
                hSS_20jetggH.SetBinError(i,max(0,hSS_20jetggH.GetBinError(i)+hSS_20jetggH.GetBinError(i)))
                hSS_20jetggH.SetBinContent(i,0)

        hQCD_20jetggH=fData.Get("QCD20ggH/data_obs")
        hQCD_20jetggH.Add(fDYJ.Get("QCD20ggH/ZJ"+post2[k]),-1)
        hQCD_20jetggH.Add(fDYL.Get("QCD20ggH/ZL"+post2[k]),-1)
        hQCD_20jetggH.Add(fTTJ.Get("QCD20ggH/TTJ"+post2[k]),-1)
        hQCD_20jetggH.Add(fTTT.Get("QCD20ggH/TTT"+post2[k]),-1)
        hQCD_20jetggH.Add(fW.Get("QCD20ggH/W"+postfix2[k]),-1)
        hQCD_20jetggH.Add(fVV.Get("QCD20ggH/VV"+post2[k]),-1)
        hQCD_20jetggH.Add(fDYS.Get("QCD20ggH/ZTT"+post2[k]),-1)
        hQCD_20jetggH.SetName("QCD"+postfix2[k])
        hQCD_20jetggH.Scale(factor2jet)
        for i in range(0,hQCD_20jetggH.GetSize()-2):
            if hQCD_20jetggH.GetBinContent(i)<0:
                hQCD_20jetggH.SetBinError(i,max(0,hQCD_20jetggH.GetBinError(i)+hQCD_20jetggH.GetBinError(i)))
                hQCD_20jetggH.SetBinContent(i,0)

        hSS_21jetggH=fData.Get("SS21ggH/data_obs")
        hSS_21jetggH.Add(fDYJ.Get("SS21ggH/ZJ"+post2[k]),-1)
        hSS_21jetggH.Add(fDYL.Get("SS21ggH/ZL"+post2[k]),-1)
        hSS_21jetggH.Add(fTTJ.Get("SS21ggH/TTJ"+post2[k]),-1)
        hSS_21jetggH.Add(fTTT.Get("SS21ggH/TTT"+post2[k]),-1)
        hSS_21jetggH.Add(fW.Get("SS21ggH/W"+postfix2[k]),-1)
        hSS_21jetggH.Add(fVV.Get("SS21ggH/VV"+post2[k]),-1)
        hSS_21jetggH.Add(fDYS.Get("SS21ggH/ZTT"+post2[k]),-1)
        hSS_21jetggH.SetName("QCD"+postfix2[k])
        hSS_21jetggH.Scale(factor2jet)
        for i in range(0,hSS_21jetggH.GetSize()-2):
            if hSS_21jetggH.GetBinContent(i)<0:
                hSS_21jetggH.SetBinError(i,max(0,hSS_21jetggH.GetBinError(i)+hSS_21jetggH.GetBinError(i)))
                hSS_21jetggH.SetBinContent(i,0)

        hQCD_21jetggH=fData.Get("QCD21ggH/data_obs")
        hQCD_21jetggH.Add(fDYJ.Get("QCD21ggH/ZJ"+post2[k]),-1)
        hQCD_21jetggH.Add(fDYL.Get("QCD21ggH/ZL"+post2[k]),-1)
        hQCD_21jetggH.Add(fTTJ.Get("QCD21ggH/TTJ"+post2[k]),-1)
        hQCD_21jetggH.Add(fTTT.Get("QCD21ggH/TTT"+post2[k]),-1)
        hQCD_21jetggH.Add(fW.Get("QCD21ggH/W"+postfix2[k]),-1)
        hQCD_21jetggH.Add(fVV.Get("QCD21ggH/VV"+post2[k]),-1)
        hQCD_21jetggH.Add(fDYS.Get("QCD21ggH/ZTT"+post2[k]),-1)
        hQCD_21jetggH.SetName("QCD"+postfix2[k])
        hQCD_21jetggH.Scale(factor2jet)
        for i in range(0,hQCD_21jetggH.GetSize()-2):
            if hQCD_21jetggH.GetBinContent(i)<0:
                hQCD_21jetggH.SetBinError(i,max(0,hQCD_21jetggH.GetBinError(i)+hQCD_21jetggH.GetBinError(i)))
                hQCD_21jetggH.SetBinContent(i,0)


        hSS_22jetggH=fData.Get("SS22ggH/data_obs")
        hSS_22jetggH.Add(fDYJ.Get("SS22ggH/ZJ"+post2[k]),-1)
        hSS_22jetggH.Add(fDYL.Get("SS22ggH/ZL"+post2[k]),-1)
        hSS_22jetggH.Add(fTTJ.Get("SS22ggH/TTJ"+post2[k]),-1)
        hSS_22jetggH.Add(fTTT.Get("SS22ggH/TTT"+post2[k]),-1)
        hSS_22jetggH.Add(fW.Get("SS22ggH/W"+postfix2[k]),-1)
        hSS_22jetggH.Add(fVV.Get("SS22ggH/VV"+post2[k]),-1)
        hSS_22jetggH.Add(fDYS.Get("SS22ggH/ZTT"+post2[k]),-1)
        hSS_22jetggH.SetName("QCD"+postfix2[k])
        hSS_22jetggH.Scale(factor2jet)
        for i in range(0,hSS_22jetggH.GetSize()-2):
            if hSS_22jetggH.GetBinContent(i)<0:
                hSS_22jetggH.SetBinError(i,max(0,hSS_22jetggH.GetBinError(i)+hSS_22jetggH.GetBinError(i)))
                hSS_22jetggH.SetBinContent(i,0)

        hQCD_22jetggH=fData.Get("QCD22ggH/data_obs")
        hQCD_22jetggH.Add(fDYJ.Get("QCD22ggH/ZJ"+post2[k]),-1)
        hQCD_22jetggH.Add(fDYL.Get("QCD22ggH/ZL"+post2[k]),-1)
        hQCD_22jetggH.Add(fTTJ.Get("QCD22ggH/TTJ"+post2[k]),-1)
        hQCD_22jetggH.Add(fTTT.Get("QCD22ggH/TTT"+post2[k]),-1)
        hQCD_22jetggH.Add(fW.Get("QCD22ggH/W"+postfix2[k]),-1)
        hQCD_22jetggH.Add(fVV.Get("QCD22ggH/VV"+post2[k]),-1)
        hQCD_22jetggH.Add(fDYS.Get("QCD22ggH/ZTT"+post2[k]),-1)
        hQCD_22jetggH.SetName("QCD"+postfix2[k])
        hQCD_22jetggH.Scale(factor2jet)
        for i in range(0,hQCD_22jetggH.GetSize()-2):
            if hQCD_22jetggH.GetBinContent(i)<0:
                hQCD_22jetggH.SetBinError(i,max(0,hQCD_22jetggH.GetBinError(i)+hQCD_22jetggH.GetBinError(i)))
                hQCD_22jetggH.SetBinContent(i,0)


        hSS_23jetggH=fData.Get("SS23ggH/data_obs")
        hSS_23jetggH.Add(fDYJ.Get("SS23ggH/ZJ"+post2[k]),-1)
        hSS_23jetggH.Add(fDYL.Get("SS23ggH/ZL"+post2[k]),-1)
        hSS_23jetggH.Add(fTTJ.Get("SS23ggH/TTJ"+post2[k]),-1)
        hSS_23jetggH.Add(fTTT.Get("SS23ggH/TTT"+post2[k]),-1)
        hSS_23jetggH.Add(fW.Get("SS23ggH/W"+postfix2[k]),-1)
        hSS_23jetggH.Add(fVV.Get("SS23ggH/VV"+post2[k]),-1)
        hSS_23jetggH.Add(fDYS.Get("SS23ggH/ZTT"+post2[k]),-1)
        hSS_23jetggH.SetName("QCD"+postfix2[k])
        hSS_23jetggH.Scale(factor2jet)
        for i in range(0,hSS_23jetggH.GetSize()-2):
            if hSS_23jetggH.GetBinContent(i)<0:
                hSS_23jetggH.SetBinError(i,max(0,hSS_23jetggH.GetBinError(i)+hSS_23jetggH.GetBinError(i)))
                hSS_23jetggH.SetBinContent(i,0)

        hQCD_23jetggH=fData.Get("QCD23ggH/data_obs")
        hQCD_23jetggH.Add(fDYJ.Get("QCD23ggH/ZJ"+post2[k]),-1)
        hQCD_23jetggH.Add(fDYL.Get("QCD23ggH/ZL"+post2[k]),-1)
        hQCD_23jetggH.Add(fTTJ.Get("QCD23ggH/TTJ"+post2[k]),-1)
        hQCD_23jetggH.Add(fTTT.Get("QCD23ggH/TTT"+post2[k]),-1)
        hQCD_23jetggH.Add(fW.Get("QCD23ggH/W"+postfix2[k]),-1)
        hQCD_23jetggH.Add(fVV.Get("QCD23ggH/VV"+post2[k]),-1)
        hQCD_23jetggH.Add(fDYS.Get("QCD23ggH/ZTT"+post2[k]),-1)
        hQCD_23jetggH.SetName("QCD"+postfix2[k])
        hQCD_23jetggH.Scale(factor2jet)
        for i in range(0,hQCD_23jetggH.GetSize()-2):
            if hQCD_23jetggH.GetBinContent(i)<0:
                hQCD_23jetggH.SetBinError(i,max(0,hQCD_23jetggH.GetBinError(i)+hQCD_23jetggH.GetBinError(i)))
                hQCD_23jetggH.SetBinContent(i,0)




        hSS_30jetggH=fData.Get("SS30ggH/data_obs")
        hSS_30jetggH.Add(fDYJ.Get("SS30ggH/ZJ"+post2[k]),-1)
        hSS_30jetggH.Add(fDYL.Get("SS30ggH/ZL"+post2[k]),-1)
        hSS_30jetggH.Add(fTTJ.Get("SS30ggH/TTJ"+post2[k]),-1)
        hSS_30jetggH.Add(fTTT.Get("SS30ggH/TTT"+post2[k]),-1)
        hSS_30jetggH.Add(fW.Get("SS30ggH/W"+postfix2[k]),-1)
        hSS_30jetggH.Add(fVV.Get("SS30ggH/VV"+post2[k]),-1)
        hSS_30jetggH.Add(fDYS.Get("SS30ggH/ZTT"+post2[k]),-1)
        hSS_30jetggH.SetName("QCD"+postfix2[k])
        hSS_30jetggH.Scale(factor2jet)
        for i in range(0,hSS_30jetggH.GetSize()-2):
            if hSS_30jetggH.GetBinContent(i)<0:
                hSS_30jetggH.SetBinError(i,max(0,hSS_30jetggH.GetBinError(i)+hSS_30jetggH.GetBinError(i)))
                hSS_30jetggH.SetBinContent(i,0)

        hQCD_30jetggH=fData.Get("QCD30ggH/data_obs")
        hQCD_30jetggH.Add(fDYJ.Get("QCD30ggH/ZJ"+post2[k]),-1)
        hQCD_30jetggH.Add(fDYL.Get("QCD30ggH/ZL"+post2[k]),-1)
        hQCD_30jetggH.Add(fTTJ.Get("QCD30ggH/TTJ"+post2[k]),-1)
        hQCD_30jetggH.Add(fTTT.Get("QCD30ggH/TTT"+post2[k]),-1)
        hQCD_30jetggH.Add(fW.Get("QCD30ggH/W"+postfix2[k]),-1)
        hQCD_30jetggH.Add(fVV.Get("QCD30ggH/VV"+post2[k]),-1)
        hQCD_30jetggH.Add(fDYS.Get("QCD30ggH/ZTT"+post2[k]),-1)
        hQCD_30jetggH.SetName("QCD"+postfix2[k])
        hQCD_30jetggH.Scale(factor2jet)
        for i in range(0,hQCD_30jetggH.GetSize()-2):
            if hQCD_30jetggH.GetBinContent(i)<0:
                hQCD_30jetggH.SetBinError(i,max(0,hQCD_30jetggH.GetBinError(i)+hQCD_30jetggH.GetBinError(i)))
                hQCD_30jetggH.SetBinContent(i,0)

        hSS_31jetggH=fData.Get("SS31ggH/data_obs")
        hSS_31jetggH.Add(fDYJ.Get("SS31ggH/ZJ"+post2[k]),-1)
        hSS_31jetggH.Add(fDYL.Get("SS31ggH/ZL"+post2[k]),-1)
        hSS_31jetggH.Add(fTTJ.Get("SS31ggH/TTJ"+post2[k]),-1)
        hSS_31jetggH.Add(fTTT.Get("SS31ggH/TTT"+post2[k]),-1)
        hSS_31jetggH.Add(fW.Get("SS31ggH/W"+postfix2[k]),-1)
        hSS_31jetggH.Add(fVV.Get("SS31ggH/VV"+post2[k]),-1)
        hSS_31jetggH.Add(fDYS.Get("SS31ggH/ZTT"+post2[k]),-1)
        hSS_31jetggH.SetName("QCD"+postfix2[k])
        hSS_31jetggH.Scale(factor2jet)
        for i in range(0,hSS_31jetggH.GetSize()-2):
            if hSS_31jetggH.GetBinContent(i)<0:
                hSS_31jetggH.SetBinError(i,max(0,hSS_31jetggH.GetBinError(i)+hSS_31jetggH.GetBinError(i)))
                hSS_31jetggH.SetBinContent(i,0)

        hQCD_31jetggH=fData.Get("QCD31ggH/data_obs")
        hQCD_31jetggH.Add(fDYJ.Get("QCD31ggH/ZJ"+post2[k]),-1)
        hQCD_31jetggH.Add(fDYL.Get("QCD31ggH/ZL"+post2[k]),-1)
        hQCD_31jetggH.Add(fTTJ.Get("QCD31ggH/TTJ"+post2[k]),-1)
        hQCD_31jetggH.Add(fTTT.Get("QCD31ggH/TTT"+post2[k]),-1)
        hQCD_31jetggH.Add(fW.Get("QCD31ggH/W"+postfix2[k]),-1)
        hQCD_31jetggH.Add(fVV.Get("QCD31ggH/VV"+post2[k]),-1)
        hQCD_31jetggH.Add(fDYS.Get("QCD31ggH/ZTT"+post2[k]),-1)
        hQCD_31jetggH.SetName("QCD"+postfix2[k])
        hQCD_31jetggH.Scale(factor2jet)
        for i in range(0,hQCD_31jetggH.GetSize()-2):
            if hQCD_31jetggH.GetBinContent(i)<0:
                hQCD_31jetggH.SetBinError(i,max(0,hQCD_31jetggH.GetBinError(i)+hQCD_31jetggH.GetBinError(i)))
                hQCD_31jetggH.SetBinContent(i,0)


        hSS_32jetggH=fData.Get("SS32ggH/data_obs")
        hSS_32jetggH.Add(fDYJ.Get("SS32ggH/ZJ"+post2[k]),-1)
        hSS_32jetggH.Add(fDYL.Get("SS32ggH/ZL"+post2[k]),-1)
        hSS_32jetggH.Add(fTTJ.Get("SS32ggH/TTJ"+post2[k]),-1)
        hSS_32jetggH.Add(fTTT.Get("SS32ggH/TTT"+post2[k]),-1)
        hSS_32jetggH.Add(fW.Get("SS32ggH/W"+postfix2[k]),-1)
        hSS_32jetggH.Add(fVV.Get("SS32ggH/VV"+post2[k]),-1)
        hSS_32jetggH.Add(fDYS.Get("SS32ggH/ZTT"+post2[k]),-1)
        hSS_32jetggH.SetName("QCD"+postfix2[k])
        hSS_32jetggH.Scale(factor2jet)
        for i in range(0,hSS_32jetggH.GetSize()-2):
            if hSS_32jetggH.GetBinContent(i)<0:
                hSS_32jetggH.SetBinError(i,max(0,hSS_32jetggH.GetBinError(i)+hSS_32jetggH.GetBinError(i)))
                hSS_32jetggH.SetBinContent(i,0)

        hQCD_32jetggH=fData.Get("QCD32ggH/data_obs")
        hQCD_32jetggH.Add(fDYJ.Get("QCD32ggH/ZJ"+post2[k]),-1)
        hQCD_32jetggH.Add(fDYL.Get("QCD32ggH/ZL"+post2[k]),-1)
        hQCD_32jetggH.Add(fTTJ.Get("QCD32ggH/TTJ"+post2[k]),-1)
        hQCD_32jetggH.Add(fTTT.Get("QCD32ggH/TTT"+post2[k]),-1)
        hQCD_32jetggH.Add(fW.Get("QCD32ggH/W"+postfix2[k]),-1)
        hQCD_32jetggH.Add(fVV.Get("QCD32ggH/VV"+post2[k]),-1)
        hQCD_32jetggH.Add(fDYS.Get("QCD32ggH/ZTT"+post2[k]),-1)
        hQCD_32jetggH.SetName("QCD"+postfix2[k])
        hQCD_32jetggH.Scale(factor2jet)
        for i in range(0,hQCD_32jetggH.GetSize()-2):
            if hQCD_32jetggH.GetBinContent(i)<0:
                hQCD_32jetggH.SetBinError(i,max(0,hQCD_32jetggH.GetBinError(i)+hQCD_32jetggH.GetBinError(i)))
                hQCD_32jetggH.SetBinContent(i,0)


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
        hQCD_33jetggH.Add(fTTJ.Get("QCD23ggH/TTJ"+post2[k]),-1)
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



        hSS_40jetggH=fData.Get("SS40ggH/data_obs")
        hSS_40jetggH.Add(fDYJ.Get("SS40ggH/ZJ"+post2[k]),-1)
        hSS_40jetggH.Add(fDYL.Get("SS40ggH/ZL"+post2[k]),-1)
        hSS_40jetggH.Add(fTTJ.Get("SS40ggH/TTJ"+post2[k]),-1)
        hSS_40jetggH.Add(fTTT.Get("SS40ggH/TTT"+post2[k]),-1)
        hSS_40jetggH.Add(fW.Get("SS40ggH/W"+postfix2[k]),-1)
        hSS_40jetggH.Add(fVV.Get("SS40ggH/VV"+post2[k]),-1)
        hSS_40jetggH.Add(fDYS.Get("SS40ggH/ZTT"+post2[k]),-1)
        hSS_40jetggH.SetName("QCD"+postfix2[k])
        hSS_40jetggH.Scale(factor2jet)
        for i in range(0,hSS_40jetggH.GetSize()-2):
            if hSS_40jetggH.GetBinContent(i)<0:
                hSS_40jetggH.SetBinError(i,max(0,hSS_40jetggH.GetBinError(i)+hSS_40jetggH.GetBinError(i)))
                hSS_40jetggH.SetBinContent(i,0)

        hQCD_40jetggH=fData.Get("QCD40ggH/data_obs")
        hQCD_40jetggH.Add(fDYJ.Get("QCD40ggH/ZJ"+post2[k]),-1)
        hQCD_40jetggH.Add(fDYL.Get("QCD40ggH/ZL"+post2[k]),-1)
        hQCD_40jetggH.Add(fTTJ.Get("QCD40ggH/TTJ"+post2[k]),-1)
        hQCD_40jetggH.Add(fTTT.Get("QCD40ggH/TTT"+post2[k]),-1)
        hQCD_40jetggH.Add(fW.Get("QCD40ggH/W"+postfix2[k]),-1)
        hQCD_40jetggH.Add(fVV.Get("QCD40ggH/VV"+post2[k]),-1)
        hQCD_40jetggH.Add(fDYS.Get("QCD40ggH/ZTT"+post2[k]),-1)
        hQCD_40jetggH.SetName("QCD"+postfix2[k])
        hQCD_40jetggH.Scale(factor2jet)
        for i in range(0,hQCD_40jetggH.GetSize()-2):
            if hQCD_40jetggH.GetBinContent(i)<0:
                hQCD_40jetggH.SetBinError(i,max(0,hQCD_40jetggH.GetBinError(i)+hQCD_40jetggH.GetBinError(i)))
                hQCD_40jetggH.SetBinContent(i,0)

        hSS_41jetggH=fData.Get("SS41ggH/data_obs")
        hSS_41jetggH.Add(fDYJ.Get("SS41ggH/ZJ"+post2[k]),-1)
        hSS_41jetggH.Add(fDYL.Get("SS41ggH/ZL"+post2[k]),-1)
        hSS_41jetggH.Add(fTTJ.Get("SS41ggH/TTJ"+post2[k]),-1)
        hSS_41jetggH.Add(fTTT.Get("SS41ggH/TTT"+post2[k]),-1)
        hSS_41jetggH.Add(fW.Get("SS41ggH/W"+postfix2[k]),-1)
        hSS_41jetggH.Add(fVV.Get("SS41ggH/VV"+post2[k]),-1)
        hSS_41jetggH.Add(fDYS.Get("SS41ggH/ZTT"+post2[k]),-1)
        hSS_41jetggH.SetName("QCD"+postfix2[k])
        hSS_41jetggH.Scale(factor2jet)
        for i in range(0,hSS_41jetggH.GetSize()-2):
            if hSS_41jetggH.GetBinContent(i)<0:
                hSS_41jetggH.SetBinError(i,max(0,hSS_41jetggH.GetBinError(i)+hSS_41jetggH.GetBinError(i)))
                hSS_41jetggH.SetBinContent(i,0)

        hQCD_41jetggH=fData.Get("QCD41ggH/data_obs")
        hQCD_41jetggH.Add(fDYJ.Get("QCD41ggH/ZJ"+post2[k]),-1)
        hQCD_41jetggH.Add(fDYL.Get("QCD41ggH/ZL"+post2[k]),-1)
        hQCD_41jetggH.Add(fTTJ.Get("QCD41ggH/TTJ"+post2[k]),-1)
        hQCD_41jetggH.Add(fTTT.Get("QCD41ggH/TTT"+post2[k]),-1)
        hQCD_41jetggH.Add(fW.Get("QCD41ggH/W"+postfix2[k]),-1)
        hQCD_41jetggH.Add(fVV.Get("QCD41ggH/VV"+post2[k]),-1)
        hQCD_41jetggH.Add(fDYS.Get("QCD41ggH/ZTT"+post2[k]),-1)
        hQCD_41jetggH.SetName("QCD"+postfix2[k])
        hQCD_41jetggH.Scale(factor2jet)
        for i in range(0,hQCD_41jetggH.GetSize()-2):
            if hQCD_41jetggH.GetBinContent(i)<0:
                hQCD_41jetggH.SetBinError(i,max(0,hQCD_41jetggH.GetBinError(i)+hQCD_41jetggH.GetBinError(i)))
                hQCD_41jetggH.SetBinContent(i,0)


        hSS_42jetggH=fData.Get("SS42ggH/data_obs")
        hSS_42jetggH.Add(fDYJ.Get("SS42ggH/ZJ"+post2[k]),-1)
        hSS_42jetggH.Add(fDYL.Get("SS42ggH/ZL"+post2[k]),-1)
        hSS_42jetggH.Add(fTTJ.Get("SS42ggH/TTJ"+post2[k]),-1)
        hSS_42jetggH.Add(fTTT.Get("SS42ggH/TTT"+post2[k]),-1)
        hSS_42jetggH.Add(fW.Get("SS42ggH/W"+postfix2[k]),-1)
        hSS_42jetggH.Add(fVV.Get("SS42ggH/VV"+post2[k]),-1)
        hSS_42jetggH.Add(fDYS.Get("SS42ggH/ZTT"+post2[k]),-1)
        hSS_42jetggH.SetName("QCD"+postfix2[k])
        hSS_42jetggH.Scale(factor2jet)
        for i in range(0,hSS_42jetggH.GetSize()-2):
            if hSS_42jetggH.GetBinContent(i)<0:
                hSS_42jetggH.SetBinError(i,max(0,hSS_42jetggH.GetBinError(i)+hSS_42jetggH.GetBinError(i)))
                hSS_42jetggH.SetBinContent(i,0)

        hQCD_42jetggH=fData.Get("QCD42ggH/data_obs")
        hQCD_42jetggH.Add(fDYJ.Get("QCD42ggH/ZJ"+post2[k]),-1)
        hQCD_42jetggH.Add(fDYL.Get("QCD42ggH/ZL"+post2[k]),-1)
        hQCD_42jetggH.Add(fTTJ.Get("QCD42ggH/TTJ"+post2[k]),-1)
        hQCD_42jetggH.Add(fTTT.Get("QCD42ggH/TTT"+post2[k]),-1)
        hQCD_42jetggH.Add(fW.Get("QCD42ggH/W"+postfix2[k]),-1)
        hQCD_42jetggH.Add(fVV.Get("QCD42ggH/VV"+post2[k]),-1)
        hQCD_42jetggH.Add(fDYS.Get("QCD42ggH/ZTT"+post2[k]),-1)
        hQCD_42jetggH.SetName("QCD"+postfix2[k])
        hQCD_42jetggH.Scale(factor2jet)
        for i in range(0,hQCD_42jetggH.GetSize()-2):
            if hQCD_42jetggH.GetBinContent(i)<0:
                hQCD_42jetggH.SetBinError(i,max(0,hQCD_42jetggH.GetBinError(i)+hQCD_42jetggH.GetBinError(i)))
                hQCD_42jetggH.SetBinContent(i,0)


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
        hQCD_43jetggH.Add(fTTJ.Get("QCD23ggH/TTJ"+post2[k]),-1)
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


        hSS_50jetggH=fData.Get("SS50ggH/data_obs")
        hSS_50jetggH.Add(fDYJ.Get("SS50ggH/ZJ"+post2[k]),-1)
        hSS_50jetggH.Add(fDYL.Get("SS50ggH/ZL"+post2[k]),-1)
        hSS_50jetggH.Add(fTTJ.Get("SS50ggH/TTJ"+post2[k]),-1)
        hSS_50jetggH.Add(fTTT.Get("SS50ggH/TTT"+post2[k]),-1)
        hSS_50jetggH.Add(fW.Get("SS50ggH/W"+postfix2[k]),-1)
        hSS_50jetggH.Add(fVV.Get("SS50ggH/VV"+post2[k]),-1)
        hSS_50jetggH.Add(fDYS.Get("SS50ggH/ZTT"+post2[k]),-1)
        hSS_50jetggH.SetName("QCD"+postfix2[k])
        hSS_50jetggH.Scale(factor2jet)
        for i in range(0,hSS_50jetggH.GetSize()-2):
            if hSS_50jetggH.GetBinContent(i)<0:
                hSS_50jetggH.SetBinError(i,max(0,hSS_50jetggH.GetBinError(i)+hSS_50jetggH.GetBinError(i)))
                hSS_50jetggH.SetBinContent(i,0)

        hQCD_50jetggH=fData.Get("QCD50ggH/data_obs")
        hQCD_50jetggH.Add(fDYJ.Get("QCD50ggH/ZJ"+post2[k]),-1)
        hQCD_50jetggH.Add(fDYL.Get("QCD50ggH/ZL"+post2[k]),-1)
        hQCD_50jetggH.Add(fTTJ.Get("QCD50ggH/TTJ"+post2[k]),-1)
        hQCD_50jetggH.Add(fTTT.Get("QCD50ggH/TTT"+post2[k]),-1)
        hQCD_50jetggH.Add(fW.Get("QCD50ggH/W"+postfix2[k]),-1)
        hQCD_50jetggH.Add(fVV.Get("QCD50ggH/VV"+post2[k]),-1)
        hQCD_50jetggH.Add(fDYS.Get("QCD50ggH/ZTT"+post2[k]),-1)
        hQCD_50jetggH.SetName("QCD"+postfix2[k])
        hQCD_50jetggH.Scale(factor2jet)
        for i in range(0,hQCD_50jetggH.GetSize()-2):
            if hQCD_50jetggH.GetBinContent(i)<0:
                hQCD_50jetggH.SetBinError(i,max(0,hQCD_50jetggH.GetBinError(i)+hQCD_50jetggH.GetBinError(i)))
                hQCD_50jetggH.SetBinContent(i,0)

        hSS_51jetggH=fData.Get("SS51ggH/data_obs")
        hSS_51jetggH.Add(fDYJ.Get("SS51ggH/ZJ"+post2[k]),-1)
        hSS_51jetggH.Add(fDYL.Get("SS51ggH/ZL"+post2[k]),-1)
        hSS_51jetggH.Add(fTTJ.Get("SS51ggH/TTJ"+post2[k]),-1)
        hSS_51jetggH.Add(fTTT.Get("SS51ggH/TTT"+post2[k]),-1)
        hSS_51jetggH.Add(fW.Get("SS51ggH/W"+postfix2[k]),-1)
        hSS_51jetggH.Add(fVV.Get("SS51ggH/VV"+post2[k]),-1)
        hSS_51jetggH.Add(fDYS.Get("SS51ggH/ZTT"+post2[k]),-1)
        hSS_51jetggH.SetName("QCD"+postfix2[k])
        hSS_51jetggH.Scale(factor2jet)
        for i in range(0,hSS_51jetggH.GetSize()-2):
            if hSS_51jetggH.GetBinContent(i)<0:
                hSS_51jetggH.SetBinError(i,max(0,hSS_51jetggH.GetBinError(i)+hSS_51jetggH.GetBinError(i)))
                hSS_51jetggH.SetBinContent(i,0)

        hQCD_51jetggH=fData.Get("QCD51ggH/data_obs")
        hQCD_51jetggH.Add(fDYJ.Get("QCD51ggH/ZJ"+post2[k]),-1)
        hQCD_51jetggH.Add(fDYL.Get("QCD51ggH/ZL"+post2[k]),-1)
        hQCD_51jetggH.Add(fTTJ.Get("QCD51ggH/TTJ"+post2[k]),-1)
        hQCD_51jetggH.Add(fTTT.Get("QCD51ggH/TTT"+post2[k]),-1)
        hQCD_51jetggH.Add(fW.Get("QCD51ggH/W"+postfix2[k]),-1)
        hQCD_51jetggH.Add(fVV.Get("QCD51ggH/VV"+post2[k]),-1)
        hQCD_51jetggH.Add(fDYS.Get("QCD51ggH/ZTT"+post2[k]),-1)
        hQCD_51jetggH.SetName("QCD"+postfix2[k])
        hQCD_51jetggH.Scale(factor2jet)
        for i in range(0,hQCD_51jetggH.GetSize()-2):
            if hQCD_51jetggH.GetBinContent(i)<0:
                hQCD_51jetggH.SetBinError(i,max(0,hQCD_51jetggH.GetBinError(i)+hQCD_51jetggH.GetBinError(i)))
                hQCD_51jetggH.SetBinContent(i,0)


        hSS_52jetggH=fData.Get("SS52ggH/data_obs")
        hSS_52jetggH.Add(fDYJ.Get("SS52ggH/ZJ"+post2[k]),-1)
        hSS_52jetggH.Add(fDYL.Get("SS52ggH/ZL"+post2[k]),-1)
        hSS_52jetggH.Add(fTTJ.Get("SS52ggH/TTJ"+post2[k]),-1)
        hSS_52jetggH.Add(fTTT.Get("SS52ggH/TTT"+post2[k]),-1)
        hSS_52jetggH.Add(fW.Get("SS52ggH/W"+postfix2[k]),-1)
        hSS_52jetggH.Add(fVV.Get("SS52ggH/VV"+post2[k]),-1)
        hSS_52jetggH.Add(fDYS.Get("SS52ggH/ZTT"+post2[k]),-1)
        hSS_52jetggH.SetName("QCD"+postfix2[k])
        hSS_52jetggH.Scale(factor2jet)
        for i in range(0,hSS_52jetggH.GetSize()-2):
            if hSS_52jetggH.GetBinContent(i)<0:
                hSS_52jetggH.SetBinError(i,max(0,hSS_52jetggH.GetBinError(i)+hSS_52jetggH.GetBinError(i)))
                hSS_52jetggH.SetBinContent(i,0)

        hQCD_52jetggH=fData.Get("QCD52ggH/data_obs")
        hQCD_52jetggH.Add(fDYJ.Get("QCD52ggH/ZJ"+post2[k]),-1)
        hQCD_52jetggH.Add(fDYL.Get("QCD52ggH/ZL"+post2[k]),-1)
        hQCD_52jetggH.Add(fTTJ.Get("QCD52ggH/TTJ"+post2[k]),-1)
        hQCD_52jetggH.Add(fTTT.Get("QCD52ggH/TTT"+post2[k]),-1)
        hQCD_52jetggH.Add(fW.Get("QCD52ggH/W"+postfix2[k]),-1)
        hQCD_52jetggH.Add(fVV.Get("QCD52ggH/VV"+post2[k]),-1)
        hQCD_52jetggH.Add(fDYS.Get("QCD52ggH/ZTT"+post2[k]),-1)
        hQCD_52jetggH.SetName("QCD"+postfix2[k])
        hQCD_52jetggH.Scale(factor2jet)
        for i in range(0,hQCD_52jetggH.GetSize()-2):
            if hQCD_52jetggH.GetBinContent(i)<0:
                hQCD_52jetggH.SetBinError(i,max(0,hQCD_52jetggH.GetBinError(i)+hQCD_52jetggH.GetBinError(i)))
                hQCD_52jetggH.SetBinContent(i,0)


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
        hQCD_53jetggH.Add(fTTJ.Get("QCD23ggH/TTJ"+post2[k]),-1)
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




        hSS_60jetggH=fData.Get("SS60ggH/data_obs")
        hSS_60jetggH.Add(fDYJ.Get("SS60ggH/ZJ"+post2[k]),-1)
        hSS_60jetggH.Add(fDYL.Get("SS60ggH/ZL"+post2[k]),-1)
        hSS_60jetggH.Add(fTTJ.Get("SS60ggH/TTJ"+post2[k]),-1)
        hSS_60jetggH.Add(fTTT.Get("SS60ggH/TTT"+post2[k]),-1)
        hSS_60jetggH.Add(fW.Get("SS60ggH/W"+postfix2[k]),-1)
        hSS_60jetggH.Add(fVV.Get("SS60ggH/VV"+post2[k]),-1)
        hSS_60jetggH.Add(fDYS.Get("SS60ggH/ZTT"+post2[k]),-1)
        hSS_60jetggH.SetName("QCD"+postfix2[k])
        hSS_60jetggH.Scale(factor2jet)
        for i in range(0,hSS_60jetggH.GetSize()-2):
            if hSS_60jetggH.GetBinContent(i)<0:
                hSS_60jetggH.SetBinError(i,max(0,hSS_60jetggH.GetBinError(i)+hSS_60jetggH.GetBinError(i)))
                hSS_60jetggH.SetBinContent(i,0)

        hQCD_60jetggH=fData.Get("QCD60ggH/data_obs")
        hQCD_60jetggH.Add(fDYJ.Get("QCD60ggH/ZJ"+post2[k]),-1)
        hQCD_60jetggH.Add(fDYL.Get("QCD60ggH/ZL"+post2[k]),-1)
        hQCD_60jetggH.Add(fTTJ.Get("QCD60ggH/TTJ"+post2[k]),-1)
        hQCD_60jetggH.Add(fTTT.Get("QCD60ggH/TTT"+post2[k]),-1)
        hQCD_60jetggH.Add(fW.Get("QCD60ggH/W"+postfix2[k]),-1)
        hQCD_60jetggH.Add(fVV.Get("QCD60ggH/VV"+post2[k]),-1)
        hQCD_60jetggH.Add(fDYS.Get("QCD60ggH/ZTT"+post2[k]),-1)
        hQCD_60jetggH.SetName("QCD"+postfix2[k])
        hQCD_60jetggH.Scale(factor2jet)
        for i in range(0,hQCD_60jetggH.GetSize()-2):
            if hQCD_60jetggH.GetBinContent(i)<0:
                hQCD_60jetggH.SetBinError(i,max(0,hQCD_60jetggH.GetBinError(i)+hQCD_60jetggH.GetBinError(i)))
                hQCD_60jetggH.SetBinContent(i,0)

        hSS_61jetggH=fData.Get("SS61ggH/data_obs")
        hSS_61jetggH.Add(fDYJ.Get("SS61ggH/ZJ"+post2[k]),-1)
        hSS_61jetggH.Add(fDYL.Get("SS61ggH/ZL"+post2[k]),-1)
        hSS_61jetggH.Add(fTTJ.Get("SS61ggH/TTJ"+post2[k]),-1)
        hSS_61jetggH.Add(fTTT.Get("SS61ggH/TTT"+post2[k]),-1)
        hSS_61jetggH.Add(fW.Get("SS61ggH/W"+postfix2[k]),-1)
        hSS_61jetggH.Add(fVV.Get("SS61ggH/VV"+post2[k]),-1)
        hSS_61jetggH.Add(fDYS.Get("SS61ggH/ZTT"+post2[k]),-1)
        hSS_61jetggH.SetName("QCD"+postfix2[k])
        hSS_61jetggH.Scale(factor2jet)
        for i in range(0,hSS_61jetggH.GetSize()-2):
            if hSS_61jetggH.GetBinContent(i)<0:
                hSS_61jetggH.SetBinError(i,max(0,hSS_61jetggH.GetBinError(i)+hSS_61jetggH.GetBinError(i)))
                hSS_61jetggH.SetBinContent(i,0)

        hQCD_61jetggH=fData.Get("QCD61ggH/data_obs")
        hQCD_61jetggH.Add(fDYJ.Get("QCD61ggH/ZJ"+post2[k]),-1)
        hQCD_61jetggH.Add(fDYL.Get("QCD61ggH/ZL"+post2[k]),-1)
        hQCD_61jetggH.Add(fTTJ.Get("QCD61ggH/TTJ"+post2[k]),-1)
        hQCD_61jetggH.Add(fTTT.Get("QCD61ggH/TTT"+post2[k]),-1)
        hQCD_61jetggH.Add(fW.Get("QCD61ggH/W"+postfix2[k]),-1)
        hQCD_61jetggH.Add(fVV.Get("QCD61ggH/VV"+post2[k]),-1)
        hQCD_61jetggH.Add(fDYS.Get("QCD61ggH/ZTT"+post2[k]),-1)
        hQCD_61jetggH.SetName("QCD"+postfix2[k])
        hQCD_61jetggH.Scale(factor2jet)
        for i in range(0,hQCD_61jetggH.GetSize()-2):
            if hQCD_61jetggH.GetBinContent(i)<0:
                hQCD_61jetggH.SetBinError(i,max(0,hQCD_61jetggH.GetBinError(i)+hQCD_61jetggH.GetBinError(i)))
                hQCD_61jetggH.SetBinContent(i,0)


        hSS_62jetggH=fData.Get("SS62ggH/data_obs")
        hSS_62jetggH.Add(fDYJ.Get("SS62ggH/ZJ"+post2[k]),-1)
        hSS_62jetggH.Add(fDYL.Get("SS62ggH/ZL"+post2[k]),-1)
        hSS_62jetggH.Add(fTTJ.Get("SS62ggH/TTJ"+post2[k]),-1)
        hSS_62jetggH.Add(fTTT.Get("SS62ggH/TTT"+post2[k]),-1)
        hSS_62jetggH.Add(fW.Get("SS62ggH/W"+postfix2[k]),-1)
        hSS_62jetggH.Add(fVV.Get("SS62ggH/VV"+post2[k]),-1)
        hSS_62jetggH.Add(fDYS.Get("SS62ggH/ZTT"+post2[k]),-1)
        hSS_62jetggH.SetName("QCD"+postfix2[k])
        hSS_62jetggH.Scale(factor2jet)
        for i in range(0,hSS_62jetggH.GetSize()-2):
            if hSS_62jetggH.GetBinContent(i)<0:
                hSS_62jetggH.SetBinError(i,max(0,hSS_62jetggH.GetBinError(i)+hSS_62jetggH.GetBinError(i)))
                hSS_62jetggH.SetBinContent(i,0)

        hQCD_62jetggH=fData.Get("QCD62ggH/data_obs")
        hQCD_62jetggH.Add(fDYJ.Get("QCD62ggH/ZJ"+post2[k]),-1)
        hQCD_62jetggH.Add(fDYL.Get("QCD62ggH/ZL"+post2[k]),-1)
        hQCD_62jetggH.Add(fTTJ.Get("QCD62ggH/TTJ"+post2[k]),-1)
        hQCD_62jetggH.Add(fTTT.Get("QCD62ggH/TTT"+post2[k]),-1)
        hQCD_62jetggH.Add(fW.Get("QCD62ggH/W"+postfix2[k]),-1)
        hQCD_62jetggH.Add(fVV.Get("QCD62ggH/VV"+post2[k]),-1)
        hQCD_62jetggH.Add(fDYS.Get("QCD62ggH/ZTT"+post2[k]),-1)
        hQCD_62jetggH.SetName("QCD"+postfix2[k])
        hQCD_62jetggH.Scale(factor2jet)
        for i in range(0,hQCD_62jetggH.GetSize()-2):
            if hQCD_62jetggH.GetBinContent(i)<0:
                hQCD_62jetggH.SetBinError(i,max(0,hQCD_62jetggH.GetBinError(i)+hQCD_62jetggH.GetBinError(i)))
                hQCD_62jetggH.SetBinContent(i,0)


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
        hQCD_63jetggH.Add(fTTJ.Get("QCD23ggH/TTJ"+post2[k]),-1)
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



        hSS_70jetggH=fData.Get("SS70ggH/data_obs")
        hSS_70jetggH.Add(fDYJ.Get("SS70ggH/ZJ"+post2[k]),-1)
        hSS_70jetggH.Add(fDYL.Get("SS70ggH/ZL"+post2[k]),-1)
        hSS_70jetggH.Add(fTTJ.Get("SS70ggH/TTJ"+post2[k]),-1)
        hSS_70jetggH.Add(fTTT.Get("SS70ggH/TTT"+post2[k]),-1)
        hSS_70jetggH.Add(fW.Get("SS70ggH/W"+postfix2[k]),-1)
        hSS_70jetggH.Add(fVV.Get("SS70ggH/VV"+post2[k]),-1)
        hSS_70jetggH.Add(fDYS.Get("SS70ggH/ZTT"+post2[k]),-1)
        hSS_70jetggH.SetName("QCD"+postfix2[k])
        hSS_70jetggH.Scale(factor2jet)
        for i in range(0,hSS_70jetggH.GetSize()-2):
            if hSS_70jetggH.GetBinContent(i)<0:
                hSS_70jetggH.SetBinError(i,max(0,hSS_70jetggH.GetBinError(i)+hSS_70jetggH.GetBinError(i)))
                hSS_70jetggH.SetBinContent(i,0)

        hQCD_70jetggH=fData.Get("QCD70ggH/data_obs")
        hQCD_70jetggH.Add(fDYJ.Get("QCD70ggH/ZJ"+post2[k]),-1)
        hQCD_70jetggH.Add(fDYL.Get("QCD70ggH/ZL"+post2[k]),-1)
        hQCD_70jetggH.Add(fTTJ.Get("QCD70ggH/TTJ"+post2[k]),-1)
        hQCD_70jetggH.Add(fTTT.Get("QCD70ggH/TTT"+post2[k]),-1)
        hQCD_70jetggH.Add(fW.Get("QCD70ggH/W"+postfix2[k]),-1)
        hQCD_70jetggH.Add(fVV.Get("QCD70ggH/VV"+post2[k]),-1)
        hQCD_70jetggH.Add(fDYS.Get("QCD70ggH/ZTT"+post2[k]),-1)
        hQCD_70jetggH.SetName("QCD"+postfix2[k])
        hQCD_70jetggH.Scale(factor2jet)
        for i in range(0,hQCD_70jetggH.GetSize()-2):
            if hQCD_70jetggH.GetBinContent(i)<0:
                hQCD_70jetggH.SetBinError(i,max(0,hQCD_70jetggH.GetBinError(i)+hQCD_70jetggH.GetBinError(i)))
                hQCD_70jetggH.SetBinContent(i,0)

        hSS_71jetggH=fData.Get("SS71ggH/data_obs")
        hSS_71jetggH.Add(fDYJ.Get("SS71ggH/ZJ"+post2[k]),-1)
        hSS_71jetggH.Add(fDYL.Get("SS71ggH/ZL"+post2[k]),-1)
        hSS_71jetggH.Add(fTTJ.Get("SS71ggH/TTJ"+post2[k]),-1)
        hSS_71jetggH.Add(fTTT.Get("SS71ggH/TTT"+post2[k]),-1)
        hSS_71jetggH.Add(fW.Get("SS71ggH/W"+postfix2[k]),-1)
        hSS_71jetggH.Add(fVV.Get("SS71ggH/VV"+post2[k]),-1)
        hSS_71jetggH.Add(fDYS.Get("SS71ggH/ZTT"+post2[k]),-1)
        hSS_71jetggH.SetName("QCD"+postfix2[k])
        hSS_71jetggH.Scale(factor2jet)
        for i in range(0,hSS_71jetggH.GetSize()-2):
            if hSS_71jetggH.GetBinContent(i)<0:
                hSS_71jetggH.SetBinError(i,max(0,hSS_71jetggH.GetBinError(i)+hSS_71jetggH.GetBinError(i)))
                hSS_71jetggH.SetBinContent(i,0)

        hQCD_71jetggH=fData.Get("QCD71ggH/data_obs")
        hQCD_71jetggH.Add(fDYJ.Get("QCD71ggH/ZJ"+post2[k]),-1)
        hQCD_71jetggH.Add(fDYL.Get("QCD71ggH/ZL"+post2[k]),-1)
        hQCD_71jetggH.Add(fTTJ.Get("QCD71ggH/TTJ"+post2[k]),-1)
        hQCD_71jetggH.Add(fTTT.Get("QCD71ggH/TTT"+post2[k]),-1)
        hQCD_71jetggH.Add(fW.Get("QCD71ggH/W"+postfix2[k]),-1)
        hQCD_71jetggH.Add(fVV.Get("QCD71ggH/VV"+post2[k]),-1)
        hQCD_71jetggH.Add(fDYS.Get("QCD71ggH/ZTT"+post2[k]),-1)
        hQCD_71jetggH.SetName("QCD"+postfix2[k])
        hQCD_71jetggH.Scale(factor2jet)
        for i in range(0,hQCD_71jetggH.GetSize()-2):
            if hQCD_71jetggH.GetBinContent(i)<0:
                hQCD_71jetggH.SetBinError(i,max(0,hQCD_71jetggH.GetBinError(i)+hQCD_71jetggH.GetBinError(i)))
                hQCD_71jetggH.SetBinContent(i,0)


        hSS_72jetggH=fData.Get("SS72ggH/data_obs")
        hSS_72jetggH.Add(fDYJ.Get("SS72ggH/ZJ"+post2[k]),-1)
        hSS_72jetggH.Add(fDYL.Get("SS72ggH/ZL"+post2[k]),-1)
        hSS_72jetggH.Add(fTTJ.Get("SS72ggH/TTJ"+post2[k]),-1)
        hSS_72jetggH.Add(fTTT.Get("SS72ggH/TTT"+post2[k]),-1)
        hSS_72jetggH.Add(fW.Get("SS72ggH/W"+postfix2[k]),-1)
        hSS_72jetggH.Add(fVV.Get("SS72ggH/VV"+post2[k]),-1)
        hSS_72jetggH.Add(fDYS.Get("SS72ggH/ZTT"+post2[k]),-1)
        hSS_72jetggH.SetName("QCD"+postfix2[k])
        hSS_72jetggH.Scale(factor2jet)
        for i in range(0,hSS_72jetggH.GetSize()-2):
            if hSS_72jetggH.GetBinContent(i)<0:
                hSS_72jetggH.SetBinError(i,max(0,hSS_72jetggH.GetBinError(i)+hSS_72jetggH.GetBinError(i)))
                hSS_72jetggH.SetBinContent(i,0)

        hQCD_72jetggH=fData.Get("QCD72ggH/data_obs")
        hQCD_72jetggH.Add(fDYJ.Get("QCD72ggH/ZJ"+post2[k]),-1)
        hQCD_72jetggH.Add(fDYL.Get("QCD72ggH/ZL"+post2[k]),-1)
        hQCD_72jetggH.Add(fTTJ.Get("QCD72ggH/TTJ"+post2[k]),-1)
        hQCD_72jetggH.Add(fTTT.Get("QCD72ggH/TTT"+post2[k]),-1)
        hQCD_72jetggH.Add(fW.Get("QCD72ggH/W"+postfix2[k]),-1)
        hQCD_72jetggH.Add(fVV.Get("QCD72ggH/VV"+post2[k]),-1)
        hQCD_72jetggH.Add(fDYS.Get("QCD72ggH/ZTT"+post2[k]),-1)
        hQCD_72jetggH.SetName("QCD"+postfix2[k])
        hQCD_72jetggH.Scale(factor2jet)
        for i in range(0,hQCD_72jetggH.GetSize()-2):
            if hQCD_72jetggH.GetBinContent(i)<0:
                hQCD_72jetggH.SetBinError(i,max(0,hQCD_72jetggH.GetBinError(i)+hQCD_72jetggH.GetBinError(i)))
                hQCD_72jetggH.SetBinContent(i,0)


        hSS_73jetggH=fData.Get("SS73ggH/data_obs")
        hSS_73jetggH.Add(fDYJ.Get("SS73ggH/ZJ"+post2[k]),-1)
        hSS_73jetggH.Add(fDYL.Get("SS73ggH/ZL"+post2[k]),-1)
        hSS_73jetggH.Add(fTTJ.Get("SS73ggH/TTJ"+post2[k]),-1)
        hSS_73jetggH.Add(fTTT.Get("SS73ggH/TTT"+post2[k]),-1)
        hSS_73jetggH.Add(fW.Get("SS73ggH/W"+postfix2[k]),-1)
        hSS_73jetggH.Add(fVV.Get("SS73ggH/VV"+post2[k]),-1)
        hSS_73jetggH.Add(fDYS.Get("SS73ggH/ZTT"+post2[k]),-1)
        hSS_73jetggH.SetName("QCD"+postfix2[k])
        hSS_73jetggH.Scale(factor2jet)
        for i in range(0,hSS_73jetggH.GetSize()-2):
            if hSS_73jetggH.GetBinContent(i)<0:
                hSS_73jetggH.SetBinError(i,max(0,hSS_73jetggH.GetBinError(i)+hSS_73jetggH.GetBinError(i)))
                hSS_73jetggH.SetBinContent(i,0)

        hQCD_73jetggH=fData.Get("QCD73ggH/data_obs")
        hQCD_73jetggH.Add(fDYJ.Get("QCD73ggH/ZJ"+post2[k]),-1)
        hQCD_73jetggH.Add(fDYL.Get("QCD73ggH/ZL"+post2[k]),-1)
        hQCD_73jetggH.Add(fTTJ.Get("QCD23ggH/TTJ"+post2[k]),-1)
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





###################### end of ggH block
######################################





        hantiCR_0jet=fData.Get("mt_antiiso_0jet_crSS/data_obs")
        hantiCR_0jet.Add(fDYJ.Get("mt_antiiso_0jet_crSS/ZJ"+post2[k]),-1)
        hantiCR_0jet.Add(fDYL.Get("mt_antiiso_0jet_crSS/ZL"+post2[k]),-1)
        hantiCR_0jet.Add(fTTJ.Get("mt_antiiso_0jet_crSS/TTJ"+post2[k]),-1)
        hantiCR_0jet.Add(fTTT.Get("mt_antiiso_0jet_crSS/TTT"+post2[k]),-1)
        hantiCR_0jet.Add(fW.Get("mt_antiiso_0jet_crSS/W"+postfix0[k]),-1)
        hantiCR_0jet.Add(fVV.Get("mt_antiiso_0jet_crSS/VV"+post2[k]),-1)
        hantiCR_0jet.Add(fDYS.Get("mt_antiiso_0jet_crSS/ZTT"+post2[k]),-1)
        hantiCR_0jet.SetName("QCD"+postfix2[k])
        hantiCR_0jet.Scale(factor0jet)
        for i in range(0,hantiCR_0jet.GetSize()-2):
            if hantiCR_0jet.GetBinContent(i)<0:
                hantiCR_0jet.SetBinError(i,max(0,hantiCR_0jet.GetBinError(i)+hantiCR_0jet.GetBinError(i)))
                hantiCR_0jet.SetBinContent(i,0)

        hantiCR_1jet=fData.Get("mt_antiiso_boosted_crSS/data_obs")
        hantiCR_1jet.Add(fDYJ.Get("mt_antiiso_boosted_crSS/ZJ"+post2[k]),-1)
        hantiCR_1jet.Add(fDYL.Get("mt_antiiso_boosted_crSS/ZL"+post2[k]),-1)
        hantiCR_1jet.Add(fTTJ.Get("mt_antiiso_boosted_crSS/TTJ"+post2[k]),-1)
        hantiCR_1jet.Add(fTTT.Get("mt_antiiso_boosted_crSS/TTT"+post2[k]),-1)
        hantiCR_1jet.Add(fW.Get("mt_antiiso_boosted_crSS/W"+postfix1[k]),-1)
        hantiCR_1jet.Add(fVV.Get("mt_antiiso_boosted_crSS/VV"+post2[k]),-1)
        hantiCR_1jet.Add(fDYS.Get("mt_antiiso_boosted_crSS/ZTT"+post2[k]),-1)
        hantiCR_1jet.SetName("QCD"+postfix2[k])
        hantiCR_1jet.Scale(factor1jet)
        for i in range(0,hantiCR_1jet.GetSize()-2):
            if hantiCR_1jet.GetBinContent(i)<0:
                hantiCR_1jet.SetBinError(i,max(0,hantiCR_1jet.GetBinError(i)+hantiCR_1jet.GetBinError(i)))
                hantiCR_1jet.SetBinContent(i,0)

        hantiCR_2jet=fData.Get("mt_antiiso_vbf_crSS/data_obs")
        hantiCR_2jet.Add(fDYJ.Get("mt_antiiso_vbf_crSS/ZJ"+post2[k]),-1)
        hantiCR_2jet.Add(fDYL.Get("mt_antiiso_vbf_crSS/ZL"+post2[k]),-1)
        hantiCR_2jet.Add(fTTJ.Get("mt_antiiso_vbf_crSS/TTJ"+post2[k]),-1)
        hantiCR_2jet.Add(fTTT.Get("mt_antiiso_vbf_crSS/TTT"+post2[k]),-1)
        hantiCR_2jet.Add(fW.Get("mt_antiiso_vbf_crSS/W"+postfix2[k]),-1)
        hantiCR_2jet.Add(fVV.Get("mt_antiiso_vbf_crSS/VV"+post2[k]),-1)
        hantiCR_2jet.Add(fDYS.Get("mt_antiiso_vbf_crSS/ZTT"+post2[k]),-1)
        hantiCR_2jet.SetName("QCD"+postfix2[k])
        hantiCR_2jet.Scale(factor2jet)
        for i in range(0,hantiCR_2jet.GetSize()-2):
            if hantiCR_2jet.GetBinContent(i)<0:
                hantiCR_2jet.SetBinError(i,max(0,hantiCR_2jet.GetBinError(i)+hantiCR_2jet.GetBinError(i)))
                hantiCR_2jet.SetBinContent(i,0)

        hwjetsCR_0jet=fData.Get("mt_wjets_0jet_crSS/data_obs")
        hwjetsCR_0jet.Add(fDYJ.Get("mt_wjets_0jet_crSS/ZJ"+post2[k]),-1)
        hwjetsCR_0jet.Add(fDYL.Get("mt_wjets_0jet_crSS/ZL"+post2[k]),-1)
        hwjetsCR_0jet.Add(fTTJ.Get("mt_wjets_0jet_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_0jet.Add(fTTT.Get("mt_wjets_0jet_crSS/TTT"+post2[k]),-1)
        hwjetsCR_0jet.Add(fW.Get("mt_wjets_0jet_crSS/W"+postfix0[k]),-1)
        hwjetsCR_0jet.Add(fVV.Get("mt_wjets_0jet_crSS/VV"+post2[k]),-1)
        hwjetsCR_0jet.Add(fDYS.Get("mt_wjets_0jet_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_0jet.SetName("QCD"+postfix2[k])
        hwjetsCR_0jet.Scale(factor0jet)
        for i in range(0,hwjetsCR_0jet.GetSize()-2):
            if hwjetsCR_0jet.GetBinContent(i)<0:
                hwjetsCR_0jet.SetBinError(i,max(0,hwjetsCR_0jet.GetBinError(i)+hwjetsCR_0jet.GetBinError(i)))
                hwjetsCR_0jet.SetBinContent(i,0)

        hwjetsCR_1jet=fData.Get("mt_wjets_boosted_crSS/data_obs")
        hwjetsCR_1jet.Add(fDYJ.Get("mt_wjets_boosted_crSS/ZJ"+post2[k]),-1)
        hwjetsCR_1jet.Add(fDYL.Get("mt_wjets_boosted_crSS/ZL"+post2[k]),-1)
        hwjetsCR_1jet.Add(fTTJ.Get("mt_wjets_boosted_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_1jet.Add(fTTT.Get("mt_wjets_boosted_crSS/TTT"+post2[k]),-1)
        hwjetsCR_1jet.Add(fW.Get("mt_wjets_boosted_crSS/W"+postfix1[k]),-1)
        hwjetsCR_1jet.Add(fVV.Get("mt_wjets_boosted_crSS/VV"+post2[k]),-1)
        hwjetsCR_1jet.Add(fDYS.Get("mt_wjets_boosted_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_1jet.SetName("QCD"+postfix2[k])
        hwjetsCR_1jet.Scale(factor1jet)
        for i in range(0,hwjetsCR_1jet.GetSize()-2):
            if hwjetsCR_1jet.GetBinContent(i)<0:
                hwjetsCR_1jet.SetBinError(i,max(0,hwjetsCR_1jet.GetBinError(i)+hwjetsCR_1jet.GetBinError(i)))
                hwjetsCR_1jet.SetBinContent(i,0)

        hwjetsCR_2jet=fData.Get("mt_wjets_vbf_crSS/data_obs")
        hwjetsCR_2jet.Add(fDYJ.Get("mt_wjets_vbf_crSS/ZJ"+post2[k]),-1)
        hwjetsCR_2jet.Add(fDYL.Get("mt_wjets_vbf_crSS/ZL"+post2[k]),-1)
        hwjetsCR_2jet.Add(fTTJ.Get("mt_wjets_vbf_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_2jet.Add(fTTT.Get("mt_wjets_vbf_crSS/TTT"+post2[k]),-1)
        hwjetsCR_2jet.Add(fW.Get("mt_wjets_vbf_crSS/W"+postfix2[k]),-1)
        hwjetsCR_2jet.Add(fVV.Get("mt_wjets_vbf_crSS/VV"+post2[k]),-1)
        hwjetsCR_2jet.Add(fDYS.Get("mt_wjets_vbf_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_2jet.SetName("QCD"+postfix2[k])
        hwjetsCR_2jet.Scale(factor2jet)
        for i in range(0,hwjetsCR_2jet.GetSize()-2):
            if hwjetsCR_2jet.GetBinContent(i)<0:
                hwjetsCR_2jet.SetBinError(i,max(0,hwjetsCR_2jet.GetBinError(i)+hwjetsCR_2jet.GetBinError(i)))
                hwjetsCR_2jet.SetBinContent(i,0)


        fout.cd()
        
	dir20jet.cd()
        hQCD_20jet.Scale(hSS_20jet.Integral()/(hQCD_20jet.Integral()+0.00001))
        hQCD_20jet.Write()

        dir21jet.cd()
        hQCD_21jet.Scale(hSS_21jet.Integral()/(hQCD_21jet.Integral()+0.00001))
        hQCD_21jet.Write()

        dir22jet.cd()
        hQCD_22jet.Scale(hSS_22jet.Integral()/(hQCD_22jet.Integral()+0.00001))
        hQCD_22jet.Write()

        dir23jet.cd()
        hQCD_23jet.Scale(hSS_23jet.Integral()/(hQCD_23jet.Integral()+0.00001))
        hQCD_23jet.Write()


        dir30jet.cd()
        hQCD_30jet.Scale(hSS_30jet.Integral()/(hQCD_30jet.Integral()+0.00001))
        hQCD_30jet.Write()

        dir31jet.cd()
        hQCD_31jet.Scale(hSS_31jet.Integral()/(hQCD_31jet.Integral()+0.00001))
        hQCD_31jet.Write()

        dir32jet.cd()
        hQCD_32jet.Scale(hSS_32jet.Integral()/(hQCD_32jet.Integral()+0.00001))
        hQCD_32jet.Write()

        dir33jet.cd()
        hQCD_33jet.Scale(hSS_33jet.Integral()/(hQCD_33jet.Integral()+0.00001))
        hQCD_33jet.Write()


        dir40jet.cd()
        hQCD_40jet.Scale(hSS_40jet.Integral()/(hQCD_40jet.Integral()+0.00001))
        hQCD_40jet.Write()

        dir41jet.cd()
        hQCD_41jet.Scale(hSS_41jet.Integral()/(hQCD_41jet.Integral()+0.00001))
        hQCD_41jet.Write()

        dir42jet.cd()
        hQCD_42jet.Scale(hSS_42jet.Integral()/(hQCD_42jet.Integral()+0.00001))
        hQCD_42jet.Write()

        dir43jet.cd()
        hQCD_43jet.Scale(hSS_43jet.Integral()/(hQCD_43jet.Integral()+0.00001))
        hQCD_43jet.Write()


        dir50jet.cd()
        hQCD_50jet.Scale(hSS_50jet.Integral()/(hQCD_50jet.Integral()+0.00001))
        hQCD_50jet.Write()

        dir51jet.cd()
        hQCD_51jet.Scale(hSS_51jet.Integral()/(hQCD_51jet.Integral()+0.00001))
        hQCD_51jet.Write()

        dir52jet.cd()
        hQCD_52jet.Scale(hSS_52jet.Integral()/(hQCD_52jet.Integral()+0.00001))
        hQCD_52jet.Write()

        dir53jet.cd()
        hQCD_53jet.Scale(hSS_53jet.Integral()/(hQCD_53jet.Integral()+0.00001))
        hQCD_53jet.Write()




######################ggH


        dir20jetggH.cd()
        hQCD_20jetggH.Scale(hSS_20jetggH.Integral()/(hQCD_20jetggH.Integral()+0.00001))
        hQCD_20jetggH.Write()

        dir21jetggH.cd()
        hQCD_21jetggH.Scale(hSS_21jetggH.Integral()/(hQCD_21jetggH.Integral()+0.00001))
        hQCD_21jetggH.Write()

        dir22jetggH.cd()
        hQCD_22jetggH.Scale(hSS_22jetggH.Integral()/(hQCD_22jetggH.Integral()+0.00001))
        hQCD_22jetggH.Write()

        dir23jetggH.cd()
        hQCD_23jetggH.Scale(hSS_23jetggH.Integral()/(hQCD_23jetggH.Integral()+0.00001))
        hQCD_23jetggH.Write()


        dir30jetggH.cd()
        hQCD_30jetggH.Scale(hSS_30jetggH.Integral()/(hQCD_30jetggH.Integral()+0.00001))
        hQCD_30jetggH.Write()

        dir31jetggH.cd()
        hQCD_31jetggH.Scale(hSS_31jetggH.Integral()/(hQCD_31jetggH.Integral()+0.00001))
        hQCD_31jetggH.Write()

        dir32jetggH.cd()
        hQCD_32jetggH.Scale(hSS_32jetggH.Integral()/(hQCD_32jetggH.Integral()+0.00001))
        hQCD_32jetggH.Write()

        dir33jetggH.cd()
        hQCD_33jetggH.Scale(hSS_33jetggH.Integral()/(hQCD_33jetggH.Integral()+0.00001))
        hQCD_33jetggH.Write()


        dir40jetggH.cd()
        hQCD_40jetggH.Scale(hSS_40jetggH.Integral()/(hQCD_40jetggH.Integral()+0.00001))
        hQCD_40jetggH.Write()

        dir41jetggH.cd()
        hQCD_41jetggH.Scale(hSS_41jetggH.Integral()/(hQCD_41jetggH.Integral()+0.00001))
        hQCD_41jetggH.Write()

        dir42jetggH.cd()
        hQCD_42jetggH.Scale(hSS_42jetggH.Integral()/(hQCD_42jetggH.Integral()+0.00001))
        hQCD_42jetggH.Write()

        dir43jetggH.cd()
        hQCD_43jetggH.Scale(hSS_43jetggH.Integral()/(hQCD_43jetggH.Integral()+0.00001))
        hQCD_43jetggH.Write()


        dir50jetggH.cd()
        hQCD_50jetggH.Scale(hSS_50jetggH.Integral()/(hQCD_50jetggH.Integral()+0.00001))
        hQCD_50jetggH.Write()

        dir51jetggH.cd()
        hQCD_51jetggH.Scale(hSS_51jetggH.Integral()/(hQCD_51jetggH.Integral()+0.00001))
        hQCD_51jetggH.Write()

        dir52jetggH.cd()
        hQCD_52jetggH.Scale(hSS_52jetggH.Integral()/(hQCD_52jetggH.Integral()+0.00001))
        hQCD_52jetggH.Write()

        dir53jetggH.cd()
        hQCD_53jetggH.Scale(hSS_53jetggH.Integral()/(hQCD_53jetggH.Integral()+0.00001))
        hQCD_53jetggH.Write()


        dir60jetggH.cd()
        hQCD_60jetggH.Scale(hSS_60jetggH.Integral()/(hQCD_60jetggH.Integral()+0.00001))
        hQCD_60jetggH.Write()

        dir61jetggH.cd()
        hQCD_61jetggH.Scale(hSS_61jetggH.Integral()/(hQCD_61jetggH.Integral()+0.00001))
        hQCD_61jetggH.Write()

        dir62jetggH.cd()
        hQCD_62jetggH.Scale(hSS_62jetggH.Integral()/(hQCD_62jetggH.Integral()+0.00001))
        hQCD_62jetggH.Write()

        dir63jetggH.cd()
        hQCD_63jetggH.Scale(hSS_63jetggH.Integral()/(hQCD_63jetggH.Integral()+0.00001))
        hQCD_63jetggH.Write()



        dir70jetggH.cd()
        hQCD_70jetggH.Scale(hSS_70jetggH.Integral()/(hQCD_70jetggH.Integral()+0.00001))
        hQCD_70jetggH.Write()

        dir71jetggH.cd()
        hQCD_71jetggH.Scale(hSS_71jetggH.Integral()/(hQCD_71jetggH.Integral()+0.00001))
        hQCD_71jetggH.Write()

        dir72jetggH.cd()
        hQCD_72jetggH.Scale(hSS_72jetggH.Integral()/(hQCD_72jetggH.Integral()+0.00001))
        hQCD_72jetggH.Write()

        dir73jetggH.cd()
        hQCD_73jetggH.Scale(hSS_73jetggH.Integral()/(hQCD_73jetggH.Integral()+0.00001))
        hQCD_73jetggH.Write()





######################## ggh block

        dir0jet.cd()
        hQCD_0jet.Scale(hSS_0jet.Integral()/hQCD_0jet.Integral())
        hQCD_0jet.Write()

        dir1jet.cd()
        hQCD_1jet.Scale(hSS_1jet.Integral()/(hQCD_1jet.Integral()+0.00001))
        hQCD_1jet.Write()


        dir2jet.cd()
        hQCD_2jet.Scale(hSS_2jet.Integral()/(hQCD_2jet.Integral()+0.00001))
        hQCD_2jet.Write()


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

