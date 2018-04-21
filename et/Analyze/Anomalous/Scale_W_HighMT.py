if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal','allJES','qcdup','qcddown','wup','wdown','up', 'down','JESup','JESdown','allTES'], help="Which TES?")
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
    factor1jet=1.15
    factor2jet=1.20

    factor0jet_u=1.15
    factor1jet_u=1.30
    factor2jet_u=1.50

    factor0jet_d=0.85
    factor1jet_d=1.00
    factor2jet_d=0.90

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
    postfixTES=["_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"]

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

    if options.scale=="allTES":
      for j in range(0,12):
         post2[j]=postfixTES[j]
         postfix0[j]=postfixTES[j]
         postfix1[j]=postfixTES[j]
         postfix2[j]=postfixTES[j]

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
         mydir="JESup"

    if (options.scale=="wdown"):
       fout=ROOT.TFile("files_nominal/W_wdown.root","recreate")
    elif (options.scale=="wup"):
       fout=ROOT.TFile("files_nominal/W_wup.root","recreate")
    elif (options.scale=="qcddown"):
       fout=ROOT.TFile("files_nominal/W_qcddown.root","recreate")
    elif (options.scale=="qcdup"):
       fout=ROOT.TFile("files_nominal/W_qcdup.root","recreate")
    elif (options.scale=="up" or options.scale=="down" or options.scale=="JESdown" or options.scale=="JESup" or options.scale=="nominal" or options.scale=="allJES" or options.scale=="allTES"):
       fDYS=ROOT.TFile("files_"+mydir+"/ZTT.root","r")
       fDYJ=ROOT.TFile("files_"+mydir+"/ZJ.root","r")
       fDYL=ROOT.TFile("files_"+mydir+"/ZL.root","r")
       fW=ROOT.TFile("files_"+mydir+"/Wunscaled.root","r")
       fTTT=ROOT.TFile("files_"+mydir+"/TTT.root","r")
       fTTJ=ROOT.TFile("files_"+mydir+"/TTJ.root","r")
       fVV=ROOT.TFile("files_"+mydir+"/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_"+mydir+"/W.root","recreate")

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

    #ggH
    dir3OSggH=fout.mkdir("et_vbf_D0_0p0to0p2_ggH")
    dir4OSggH=fout.mkdir("et_vbf_D0_0p2to0p4_ggH")
    dir5OSggH=fout.mkdir("et_vbf_D0_0p4to0p8_ggH")
    dir7OSggH=fout.mkdir("et_vbf_D0_0p8to1p0_ggH")
    dir33OSggH=fout.mkdir("et_vbf_D0_0p0to0p2_DCPm_ggH")
    dir34OSggH=fout.mkdir("et_vbf_D0_0p2to0p4_DCPm_ggH")
    dir35OSggH=fout.mkdir("et_vbf_D0_0p4to0p8_DCPm_ggH")
    dir37OSggH=fout.mkdir("et_vbf_D0_0p8to1p0_DCPm_ggH")

    dPhiajetggH =fout.mkdir("et_vbf_D0_Pito2p5m_ggH");
    dPhibjetggH =fout.mkdir("et_vbf_D0_2p5to2pm_ggH");
    dPhicjetggH =fout.mkdir("et_vbf_D0_2to1p5m_ggH");
    dPhidjetggH =fout.mkdir("et_vbf_D0_1p5to1m_ggH");
    dPhiejetggH =fout.mkdir("et_vbf_D0_1to0p5m_ggH");
    dPhifjetggH =fout.mkdir("et_vbf_D0_0p5to0m_ggH");

    dPhigjetggH =fout.mkdir("et_vbf_D0_0to0p5p_ggH");
    dPhihjetggH =fout.mkdir("et_vbf_D0_0p5to1p_ggH");
    dPhiijetggH =fout.mkdir("et_vbf_D0_1to1p5p_ggH");
    dPhijjetggH =fout.mkdir("et_vbf_D0_1p5to2p_ggH");
    dPhikjetggH =fout.mkdir("et_vbf_D0_2to2p5_ggH");
    dPhiljetggH =fout.mkdir("et_vbf_D0_2p5toPip_ggH");


    dir3OS=fout.mkdir("et_vbf_D0_0p0to0p2")
    dir3SS=fout.mkdir("SS3")
    dir3QCD=fout.mkdir("QCD3")
    dir4OS=fout.mkdir("et_vbf_D0_0p2to0p4")
    dir4SS=fout.mkdir("SS4")
    dir4QCD=fout.mkdir("QCD4")
    dir5OS=fout.mkdir("et_vbf_D0_0p4to0p8")
    dir5SS=fout.mkdir("SS5")
    dir5QCD=fout.mkdir("QCD5")
    dir7OS=fout.mkdir("et_vbf_D0_0p8to1p0")
    dir7SS=fout.mkdir("SS7")
    dir7QCD=fout.mkdir("QCD7")

    dir33OS=fout.mkdir("et_vbf_D0_0p0to0p2_DCPm")
    dir33SS=fout.mkdir("SS33")
    dir33QCD=fout.mkdir("QCD33")
    dir34OS=fout.mkdir("et_vbf_D0_0p2to0p4_DCPm")
    dir34SS=fout.mkdir("SS34")
    dir34QCD=fout.mkdir("QCD34")
    dir35OS=fout.mkdir("et_vbf_D0_0p4to0p8_DCPm")
    dir35SS=fout.mkdir("SS35")
    dir35QCD=fout.mkdir("QCD35")
    dir37OS=fout.mkdir("et_vbf_D0_0p8to1p0_DCPm")
    dir37SS=fout.mkdir("SS37")
    dir37QCD=fout.mkdir("QCD37")

    dir43OS=fout.mkdir("et_vbf_D0_0p0to0p2_DCPp")
    dir43SS=fout.mkdir("SS43")
    dir43QCD=fout.mkdir("QCD43")
    dir44OS=fout.mkdir("et_vbf_D0_0p2to0p4_DCPp")
    dir44SS=fout.mkdir("SS44")
    dir44QCD=fout.mkdir("QCD44")
    dir45OS=fout.mkdir("et_vbf_D0_0p4to0p8_DCPp")
    dir45SS=fout.mkdir("SS45")
    dir45QCD=fout.mkdir("QCD45")
    dir47OS=fout.mkdir("et_vbf_D0_0p8to1p0_DCPp")
    dir47SS=fout.mkdir("SS47")
    dir47QCD=fout.mkdir("QCD47")

    dir53OS=fout.mkdir("et_vbf_D0hplus_0p0to0p2")
    dir53SS=fout.mkdir("SS53")
    dir53QCD=fout.mkdir("QCD53")
    dir54OS=fout.mkdir("et_vbf_D0hplus_0p2to0p4")
    dir54SS=fout.mkdir("SS54")
    dir54QCD=fout.mkdir("QCD54")
    dir55OS=fout.mkdir("et_vbf_D0hplus_0p4to0p8")
    dir55SS=fout.mkdir("SS55")
    dir55QCD=fout.mkdir("QCD55")
    dir57OS=fout.mkdir("et_vbf_D0hplus_0p8to1p0")
    dir57SS=fout.mkdir("SS57")
    dir57QCD=fout.mkdir("QCD57")

    dir63OS=fout.mkdir("et_vbf_DL1_0p0to0p2")
    dir63SS=fout.mkdir("SS63")
    dir63QCD=fout.mkdir("QCD63")
    dir64OS=fout.mkdir("et_vbf_DL1_0p2to0p4")
    dir64SS=fout.mkdir("SS64")
    dir64QCD=fout.mkdir("QCD64")
    dir65OS=fout.mkdir("et_vbf_DL1_0p4to0p8")
    dir65SS=fout.mkdir("SS65")
    dir65QCD=fout.mkdir("QCD65")
    dir67OS=fout.mkdir("et_vbf_DL1_0p8to1p0")
    dir67SS=fout.mkdir("SS67")
    dir67QCD=fout.mkdir("QCD67")

    dir73OS=fout.mkdir("et_vbf_DL1Zg_0p0to0p2")
    dir73SS=fout.mkdir("SS73")
    dir73QCD=fout.mkdir("QCD73")
    dir74OS=fout.mkdir("et_vbf_DL1Zg_0p2to0p4")
    dir74SS=fout.mkdir("SS74")
    dir74QCD=fout.mkdir("QCD74")
    dir75OS=fout.mkdir("et_vbf_DL1Zg_0p4to0p8")
    dir75SS=fout.mkdir("SS75")
    dir75QCD=fout.mkdir("QCD75")
    dir77OS=fout.mkdir("et_vbf_DL1Zg_0p8to1p0")
    dir77SS=fout.mkdir("SS77")
    dir77QCD=fout.mkdir("QCD77")


    nbhist=1
    if options.scale=="allJES":
      nbhist=56
    if options.scale=="allTES":
      nbhist=12
    #QCDpassSS0=[0]
    #QCDpassSS1=[0]
    #QCDpassSS2=[0]
    #SFpassOS0=[0]
    #SFpassOS1=[0]
    #SFpassOS2=[0]
    for k in range(0,nbhist):
        #print fDYS.Get("n70"+post2[k]).GetBinContent(4)
        QCDpassSS0=(fData.Get("n70SS").GetBinContent(2)-fDYJ.Get("n70SS"+post2[k]).GetBinContent(2)-fDYL.Get("n70SS"+post2[k]).GetBinContent(2)-fDYS.Get("n70SS"+post2[k]).GetBinContent(2)-fTTJ.Get("n70SS"+post2[k]).GetBinContent(2)-fTTT.Get("n70SS"+post2[k]).GetBinContent(2)-fW.Get("n70SS"+post2[k]).GetBinContent(2)-fVV.Get("n70SS"+post2[k]).GetBinContent(2))
        SFpassOS0=((fData.Get("n70").GetBinContent(2)-fDYJ.Get("n70"+post2[k]).GetBinContent(2)-fDYL.Get("n70"+post2[k]).GetBinContent(2)-fDYS.Get("n70"+post2[k]).GetBinContent(2)-fTTJ.Get("n70"+post2[k]).GetBinContent(2)-fTTT.Get("n70"+post2[k]).GetBinContent(2)-fVV.Get("n70"+post2[k]).GetBinContent(2)-factor0jet*QCDpassSS0)/fW.Get("n70"+post2[k]).GetBinContent(2))
        QCDpassSS1=(fData.Get("n70SS").GetBinContent(3)-fDYJ.Get("n70SS"+post2[k]).GetBinContent(3)-fDYL.Get("n70SS"+post2[k]).GetBinContent(3)-fDYS.Get("n70SS"+post2[k]).GetBinContent(3)-fTTJ.Get("n70SS"+post2[k]).GetBinContent(3)-fTTT.Get("n70SS"+post2[k]).GetBinContent(3)-fW.Get("n70SS"+post2[k]).GetBinContent(3)-fVV.Get("n70SS"+post2[k]).GetBinContent(3))
        SFpassOS1=((fData.Get("n70").GetBinContent(3)-fDYJ.Get("n70"+post2[k]).GetBinContent(3)-fDYL.Get("n70"+post2[k]).GetBinContent(3)-fDYS.Get("n70"+post2[k]).GetBinContent(3)-fTTJ.Get("n70"+post2[k]).GetBinContent(3)-fTTT.Get("n70"+post2[k]).GetBinContent(3)-fVV.Get("n70"+post2[k]).GetBinContent(3)-factor1jet*QCDpassSS1)/fW.Get("n70"+post2[k]).GetBinContent(3))
        QCDpassSS2=(fData.Get("n70SS").GetBinContent(4)-fDYJ.Get("n70SS"+post2[k]).GetBinContent(4)-fDYL.Get("n70SS"+post2[k]).GetBinContent(4)-fDYS.Get("n70SS"+post2[k]).GetBinContent(4)-fTTJ.Get("n70SS"+post2[k]).GetBinContent(4)-fTTT.Get("n70SS"+post2[k]).GetBinContent(4)-fW.Get("n70SS"+post2[k]).GetBinContent(4)-fVV.Get("n70SS"+post2[k]).GetBinContent(4))
        SFpassOS2=((fData.Get("n70").GetBinContent(4)-fDYJ.Get("n70"+post2[k]).GetBinContent(4)-fDYL.Get("n70"+post2[k]).GetBinContent(4)-fDYS.Get("n70"+post2[k]).GetBinContent(4)-fTTJ.Get("n70"+post2[k]).GetBinContent(4)-fTTT.Get("n70"+post2[k]).GetBinContent(4)-fVV.Get("n70"+post2[k]).GetBinContent(4)-factor2jet*QCDpassSS2)/fW.Get("n70"+post2[k]).GetBinContent(4))
	#print SFpassOS2[k-1],fData.Get("n70").GetBinContent(4),fDYJ.Get("n70"+post2[k]).GetBinContent(4),fDYL.Get("n70"+post2[k]).GetBinContent(4),fDYS.Get("n70"+post2[k]).GetBinContent(4),fTTJ.Get("n70"+post2[k]).GetBinContent(4),fTTT.Get("n70"+post2[k]).GetBinContent(4),fVV.Get("n70"+post2[k]).GetBinContent(4),factor2jet*QCDpassSS2[k-1],fW.Get("n70"+post2[k]).GetBinContent(4)
	#print "Data VBF: ",fData.Get("n70").GetBinContent(4)
        #print "ZJ VBF: ",fDYJ.Get("n70").GetBinContent(4)
        #print "ZL VBF: ",fDYL.Get("n70").GetBinContent(4)
        #print "TTT VBF: ",fTTT.Get("n70").GetBinContent(4)
        #print "TTJ VBF: ",fTTJ.Get("n70").GetBinContent(4)
        #print "VV VBF: ",fVV.Get("n70").GetBinContent(4)
        #print "ZTT VBF: ",fDYS.Get("n70").GetBinContent(4)
        #print "QCD VBF: ",factor2jet*QCDpassSS2
        #print "W unscaled: ",fW.Get("n70").GetBinContent(4)
	#print "Scale factor VBF: ",SFpassOS2

        #print "Data boosted: ",fData.Get("n70").GetBinContent(3)
        #print "ZJ boosted: ",fDYJ.Get("n70").GetBinContent(3)
        #print "ZL boosted: ",fDYL.Get("n70").GetBinContent(3)
        #print "TTT boosted: ",fTTT.Get("n70").GetBinContent(3)
        #print "TTJ boosted: ",fTTJ.Get("n70").GetBinContent(3)
        #print "VV boosted: ",fVV.Get("n70").GetBinContent(3)
        #print "ZTT boosted: ",fDYS.Get("n70").GetBinContent(3)
        #print "QCD boosted: ",factor1jet*QCDpassSS1
        #print "W unscaled boosted: ",fW.Get("n70").GetBinContent(3)
        #print "Scale factor Boosted: ",SFpassOS1

	#print fDYS.Get("n70"+post2[k]).GetBinContent(4)
	print post2[k],SFpassOS0,SFpassOS1,SFpassOS2
        SFpassOS2=SFpassOS1
        hW0jet=fW.Get("et_0jet/W"+post2[k])
        hW0jet.Scale(SFpassOS0*factorw0jet)
        hW1jet=fW.Get("et_boosted/W"+post2[k])
        hW1jet.Scale(SFpassOS1*factorw1jet)
        hW2jet=fW.Get("et_vbf/W"+post2[k])
        hW2jet.Scale(SFpassOS1*factorw2jet)


        hW3jet=fW.Get("et_vbf_D0_0p0to0p2/W"+post2[k])
        hW3jet.Scale(SFpassOS1*factorw2jet)
        hW4jet=fW.Get("et_vbf_D0_0p2to0p4/W"+post2[k])
        hW4jet.Scale(SFpassOS1*factorw2jet)
        hW5jet=fW.Get("et_vbf_D0_0p4to0p8/W"+post2[k])
        hW5jet.Scale(SFpassOS1*factorw2jet)
        hW7jet=fW.Get("et_vbf_D0_0p8to1p0/W"+post2[k])
        hW7jet.Scale(SFpassOS1*factorw2jet)
        hW33jet=fW.Get("et_vbf_D0_0p0to0p2_DCPm/W"+post2[k])
        hW33jet.Scale(SFpassOS1*factorw2jet)
        hW34jet=fW.Get("et_vbf_D0_0p2to0p4_DCPm/W"+post2[k])
        hW34jet.Scale(SFpassOS1*factorw2jet)
        hW35jet=fW.Get("et_vbf_D0_0p4to0p8_DCPm/W"+post2[k])
        hW35jet.Scale(SFpassOS1*factorw2jet)
        hW37jet=fW.Get("et_vbf_D0_0p8to1p0_DCPm/W"+post2[k])
        hW37jet.Scale(SFpassOS1*factorw2jet)
        hW43jet=fW.Get("et_vbf_D0_0p0to0p2_DCPp/W"+post2[k])
        hW43jet.Scale(SFpassOS1*factorw2jet)
        hW44jet=fW.Get("et_vbf_D0_0p2to0p4_DCPp/W"+post2[k])
        hW44jet.Scale(SFpassOS1*factorw2jet)
        hW45jet=fW.Get("et_vbf_D0_0p4to0p8_DCPp/W"+post2[k])
        hW45jet.Scale(SFpassOS1*factorw2jet)
        hW47jet=fW.Get("et_vbf_D0_0p8to1p0_DCPp/W"+post2[k])
        hW47jet.Scale(SFpassOS1*factorw2jet)

	#ggH clone
        hW3jetggH=fW.Get("et_vbf_D0_0p0to0p2_ggH/W"+post2[k])
        hW3jetggH.Scale(SFpassOS1*factorw2jet)
        hW4jetggH=fW.Get("et_vbf_D0_0p2to0p4_ggH//W"+post2[k])
        hW4jetggH.Scale(SFpassOS1*factorw2jet)
        hW5jetggH=fW.Get("et_vbf_D0_0p4to0p8_ggH//W"+post2[k])
        hW5jetggH.Scale(SFpassOS1*factorw2jet)
        hW7jetggH=fW.Get("et_vbf_D0_0p8to1p0_ggH//W"+post2[k])
        hW7jetggH.Scale(SFpassOS1*factorw2jet)
        hW33jetggH=fW.Get("et_vbf_D0_0p0to0p2_DCPm_ggH/W"+post2[k])
        hW33jetggH.Scale(SFpassOS1*factorw2jet)
        hW34jetggH=fW.Get("et_vbf_D0_0p2to0p4_DCPm_ggH/W"+post2[k])
        hW34jetggH.Scale(SFpassOS1*factorw2jet)
        hW35jetggH=fW.Get("et_vbf_D0_0p4to0p8_DCPm_ggH/W"+post2[k])
        hW35jetggH.Scale(SFpassOS1*factorw2jet)
        hW37jetggH=fW.Get("et_vbf_D0_0p8to1p0_DCPm_ggH/W"+post2[k])
        hW37jetggH.Scale(SFpassOS1*factorw2jet)


        hW53jet=fW.Get("et_vbf_D0hplus_0p0to0p2/W"+post2[k])
        hW53jet.Scale(SFpassOS1*factorw2jet)
        hW54jet=fW.Get("et_vbf_D0hplus_0p2to0p4/W"+post2[k])
        hW54jet.Scale(SFpassOS1*factorw2jet)
        hW55jet=fW.Get("et_vbf_D0hplus_0p4to0p8/W"+post2[k])
        hW55jet.Scale(SFpassOS1*factorw2jet)
        hW57jet=fW.Get("et_vbf_D0hplus_0p8to1p0/W"+post2[k])
        hW57jet.Scale(SFpassOS1*factorw2jet)

        hW63jet=fW.Get("et_vbf_DL1_0p0to0p2/W"+post2[k])
        hW63jet.Scale(SFpassOS1*factorw2jet)
        hW64jet=fW.Get("et_vbf_DL1_0p2to0p4/W"+post2[k])
        hW64jet.Scale(SFpassOS1*factorw2jet)
        hW65jet=fW.Get("et_vbf_DL1_0p4to0p8/W"+post2[k])
        hW65jet.Scale(SFpassOS1*factorw2jet)
        hW67jet=fW.Get("et_vbf_DL1_0p8to1p0/W"+post2[k])
        hW67jet.Scale(SFpassOS1*factorw2jet)

        hW73jet=fW.Get("et_vbf_DL1Zg_0p0to0p2/W"+post2[k])
        hW73jet.Scale(SFpassOS1*factorw2jet)
        hW74jet=fW.Get("et_vbf_DL1Zg_0p2to0p4/W"+post2[k])
        hW74jet.Scale(SFpassOS1*factorw2jet)
        hW75jet=fW.Get("et_vbf_DL1Zg_0p4to0p8/W"+post2[k])
        hW75jet.Scale(SFpassOS1*factorw2jet)
        hW77jet=fW.Get("et_vbf_DL1Zg_0p8to1p0/W"+post2[k])
        hW77jet.Scale(SFpassOS1*factorw2jet)

	print hW73jet.Integral()+hW74jet.Integral()+hW75jet.Integral()+hW77jet.Integral()
        print hW53jet.Integral()+hW54jet.Integral()+hW55jet.Integral()+hW57jet.Integral()
        print hW63jet.Integral()+hW64jet.Integral()+hW65jet.Integral()+hW67jet.Integral()
        print hW3jet.Integral()+hW4jet.Integral()+hW5jet.Integral()+hW7jet.Integral()
        print hW3jet.Integral(),hW4jet.Integral(),hW5jet.Integral(),hW7jet.Integral()

        hW0jet_SS=fW.Get("SS0jet/W"+post2[k])
        hW0jet_SS.Scale(SFpassOS1*factorw0jet)
        hW1jet_SS=fW.Get("SS1jet/W"+post2[k])
        hW1jet_SS.Scale(SFpassOS1*factorw1jet)
        hW2jet_SS=fW.Get("SSvbf/W"+post2[k])
        hW2jet_SS.Scale(SFpassOS1*factorw2jet)
        hW3jet_SS=fW.Get("SS3/W"+post2[k])
        hW3jet_SS.Scale(SFpassOS1*factorw2jet)
        hW4jet_SS=fW.Get("SS4/W"+post2[k])
        hW4jet_SS.Scale(SFpassOS1*factorw2jet)
        hW5jet_SS=fW.Get("SS5/W"+post2[k])
        hW5jet_SS.Scale(SFpassOS1*factorw2jet)
        hW7jet_SS=fW.Get("SS7/W"+post2[k])
        hW7jet_SS.Scale(SFpassOS1*factorw2jet)

        hW33jet_SS=fW.Get("SS33/W"+post2[k])
        hW33jet_SS.Scale(SFpassOS1*factorw2jet)
        hW34jet_SS=fW.Get("SS34/W"+post2[k])
        hW34jet_SS.Scale(SFpassOS1*factorw2jet)
        hW35jet_SS=fW.Get("SS35/W"+post2[k])
        hW35jet_SS.Scale(SFpassOS1*factorw2jet)
        hW37jet_SS=fW.Get("SS37/W"+post2[k])
        hW37jet_SS.Scale(SFpassOS1*factorw2jet)

        hW43jet_SS=fW.Get("SS43/W"+post2[k])
        hW43jet_SS.Scale(SFpassOS1*factorw2jet)
        hW44jet_SS=fW.Get("SS44/W"+post2[k])
        hW44jet_SS.Scale(SFpassOS1*factorw2jet)
        hW45jet_SS=fW.Get("SS45/W"+post2[k])
        hW45jet_SS.Scale(SFpassOS1*factorw2jet)
        hW47jet_SS=fW.Get("SS47/W"+post2[k])
        hW47jet_SS.Scale(SFpassOS1*factorw2jet)

        hW53jet_SS=fW.Get("SS53/W"+post2[k])
        hW53jet_SS.Scale(SFpassOS1*factorw2jet)
        hW54jet_SS=fW.Get("SS54/W"+post2[k])
        hW54jet_SS.Scale(SFpassOS1*factorw2jet)
        hW55jet_SS=fW.Get("SS55/W"+post2[k])
        hW55jet_SS.Scale(SFpassOS1*factorw2jet)
        hW57jet_SS=fW.Get("SS57/W"+post2[k])
        hW57jet_SS.Scale(SFpassOS1*factorw2jet)

        hW63jet_SS=fW.Get("SS63/W"+post2[k])
        hW63jet_SS.Scale(SFpassOS1*factorw2jet)
        hW64jet_SS=fW.Get("SS64/W"+post2[k])
        hW64jet_SS.Scale(SFpassOS1*factorw2jet)
        hW65jet_SS=fW.Get("SS65/W"+post2[k])
        hW65jet_SS.Scale(SFpassOS1*factorw2jet)
        hW67jet_SS=fW.Get("SS67/W"+post2[k])
        hW67jet_SS.Scale(SFpassOS1*factorw2jet)

        hW73jet_SS=fW.Get("SS73/W"+post2[k])
        hW73jet_SS.Scale(SFpassOS1*factorw2jet)
        hW74jet_SS=fW.Get("SS74/W"+post2[k])
        hW74jet_SS.Scale(SFpassOS1*factorw2jet)
        hW75jet_SS=fW.Get("SS75/W"+post2[k])
        hW75jet_SS.Scale(SFpassOS1*factorw2jet)
        hW77jet_SS=fW.Get("SS77/W"+post2[k])
        hW77jet_SS.Scale(SFpassOS1*factorw2jet)

        hW0jet_QCD=fW.Get("QCD0jet/W"+post2[k])
        hW0jet_QCD.Scale(SFpassOS0*factorw0jet)
        hW1jet_QCD=fW.Get("QCD1jet/W"+post2[k])
        hW1jet_QCD.Scale(SFpassOS1*factorw1jet)
        hW2jet_QCD=fW.Get("QCDvbf/W"+post2[k])
        hW2jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW3jet_QCD=fW.Get("QCD3/W"+post2[k])
        hW3jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW4jet_QCD=fW.Get("QCD4/W"+post2[k])
        hW4jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW5jet_QCD=fW.Get("QCD5/W"+post2[k])
        hW5jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW7jet_QCD=fW.Get("QCD7/W"+post2[k])
        hW7jet_QCD.Scale(SFpassOS1*factorw2jet)

        hW33jet_QCD=fW.Get("QCD33/W"+post2[k])
        hW33jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW34jet_QCD=fW.Get("QCD34/W"+post2[k])
        hW34jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW35jet_QCD=fW.Get("QCD35/W"+post2[k])
        hW35jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW37jet_QCD=fW.Get("QCD37/W"+post2[k])
        hW37jet_QCD.Scale(SFpassOS1*factorw2jet)

        hW43jet_QCD=fW.Get("QCD43/W"+post2[k])
        hW43jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW44jet_QCD=fW.Get("QCD44/W"+post2[k])
        hW44jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW45jet_QCD=fW.Get("QCD45/W"+post2[k])
        hW45jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW47jet_QCD=fW.Get("QCD47/W"+post2[k])
        hW47jet_QCD.Scale(SFpassOS1*factorw2jet)

        hW53jet_QCD=fW.Get("QCD53/W"+post2[k])
        hW53jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW54jet_QCD=fW.Get("QCD54/W"+post2[k])
        hW54jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW55jet_QCD=fW.Get("QCD55/W"+post2[k])
        hW55jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW57jet_QCD=fW.Get("QCD57/W"+post2[k])
        hW57jet_QCD.Scale(SFpassOS1*factorw2jet)

        hW63jet_QCD=fW.Get("QCD63/W"+post2[k])
        hW63jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW64jet_QCD=fW.Get("QCD64/W"+post2[k])
        hW64jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW65jet_QCD=fW.Get("QCD65/W"+post2[k])
        hW65jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW67jet_QCD=fW.Get("QCD67/W"+post2[k])
        hW67jet_QCD.Scale(SFpassOS1*factorw2jet)

        hW73jet_QCD=fW.Get("QCD73/W"+post2[k])
        hW73jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW74jet_QCD=fW.Get("QCD74/W"+post2[k])
        hW74jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW75jet_QCD=fW.Get("QCD75/W"+post2[k])
        hW75jet_QCD.Scale(SFpassOS1*factorw2jet)
        hW77jet_QCD=fW.Get("QCD77/W"+post2[k])
        hW77jet_QCD.Scale(SFpassOS1*factorw2jet)


        hWCR0jet=fW.Get("et_wjets_0jet_cr/W"+post2[k])
        hWCR0jet.Scale(SFpassOS0*factorw0jet)
        hWCR1jet=fW.Get("et_wjets_boosted_cr/W"+post2[k])
        hWCR1jet.Scale(SFpassOS1*factorw1jet)
        hWCR2jet=fW.Get("et_wjets_vbf_cr/W"+post2[k])
        hWCR2jet.Scale(SFpassOS1*factorw2jet)

        hQCDCR0jet=fW.Get("et_antiiso_0jet_cr/W"+post2[k])
        hQCDCR0jet.Scale(SFpassOS0*factorw0jet)
        hQCDCR1jet=fW.Get("et_antiiso_boosted_cr/W"+post2[k])
        hQCDCR1jet.Scale(SFpassOS1*factorw1jet)
        hQCDCR2jet=fW.Get("et_antiiso_vbf_cr/W"+post2[k])
        hQCDCR2jet.Scale(SFpassOS1*factorw2jet)

        hWCRSS0jet=fW.Get("et_wjets_0jet_crSS/W"+post2[k])
        hWCRSS0jet.Scale(SFpassOS0*factorw0jet)
        hWCRSS1jet=fW.Get("et_wjets_boosted_crSS/W"+post2[k])
        hWCRSS1jet.Scale(SFpassOS1*factorw1jet)
        hWCRSS2jet=fW.Get("et_wjets_vbf_crSS/W"+post2[k])
        hWCRSS2jet.Scale(SFpassOS1*factorw2jet)

        hQCDCRSS0jet=fW.Get("et_antiiso_0jet_crSS/W"+post2[k])
        hQCDCRSS0jet.Scale(SFpassOS0*factorw0jet)
        hQCDCRSS1jet=fW.Get("et_antiiso_boosted_crSS/W"+post2[k])
        hQCDCRSS1jet.Scale(SFpassOS1*factorw1jet)
        hQCDCRSS2jet=fW.Get("et_antiiso_vbf_crSS/W"+post2[k])
        hQCDCRSS2jet.Scale(SFpassOS1*factorw2jet)

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
        dir3OS.cd()
        hW3jet.SetName("W"+postfix2[k])
        hW3jet.Write()
        dir4OS.cd()
        hW4jet.SetName("W"+postfix2[k])
        hW4jet.Write()
        dir5OS.cd()
        hW5jet.SetName("W"+postfix2[k])
        hW5jet.Write()
        dir7OS.cd()
        hW7jet.SetName("W"+postfix2[k])
        hW7jet.Write()
        dir33OS.cd()
        hW33jet.SetName("W"+postfix2[k])
        hW33jet.Write()
        dir34OS.cd()
        hW34jet.SetName("W"+postfix2[k])
        hW34jet.Write()
        dir35OS.cd()
        hW35jet.SetName("W"+postfix2[k])
        hW35jet.Write()
        dir37OS.cd()
        hW37jet.SetName("W"+postfix2[k])
        hW37jet.Write()
	#ggH clone
        dir3OSggH.cd()
        hW3jetggH.SetName("W"+postfix2[k])
        hW3jetggH.Write()
        dir4OSggH.cd()
        hW4jetggH.SetName("W"+postfix2[k])
        hW4jetggH.Write()
        dir5OSggH.cd()
        hW5jetggH.SetName("W"+postfix2[k])
        hW5jetggH.Write()
        dir7OSggH.cd()
        hW7jetggH.SetName("W"+postfix2[k])
        hW7jetggH.Write()
        dir33OSggH.cd()
        hW33jetggH.SetName("W"+postfix2[k])
        hW33jetggH.Write()
        dir34OSggH.cd()
        hW34jetggH.SetName("W"+postfix2[k])
        hW34jetggH.Write()
        dir35OSggH.cd()
        hW35jetggH.SetName("W"+postfix2[k])
        hW35jetggH.Write()
        dir37OSggH.cd()
        hW37jetggH.SetName("W"+postfix2[k])
        hW37jetggH.Write()








        dir43OS.cd()
        hW43jet.SetName("W"+postfix2[k])
        hW43jet.Write()
        dir44OS.cd()
        hW44jet.SetName("W"+postfix2[k])
        hW44jet.Write()
        dir45OS.cd()
        hW45jet.SetName("W"+postfix2[k])
        hW45jet.Write()
        dir47OS.cd()
        hW47jet.SetName("W"+postfix2[k])
        hW47jet.Write()

        dir53OS.cd()
        hW53jet.SetName("W"+postfix2[k])
        hW53jet.Write()
        dir54OS.cd()
        hW54jet.SetName("W"+postfix2[k])
        hW54jet.Write()
        dir55OS.cd()
        hW55jet.SetName("W"+postfix2[k])
        hW55jet.Write()
        dir57OS.cd()
        hW57jet.SetName("W"+postfix2[k])
        hW57jet.Write()

        dir63OS.cd()
        hW63jet.SetName("W"+postfix2[k])
        hW63jet.Write()
        dir64OS.cd()
        hW64jet.SetName("W"+postfix2[k])
        hW64jet.Write()
        dir65OS.cd()
        hW65jet.SetName("W"+postfix2[k])
        hW65jet.Write()
        dir67OS.cd()
        hW67jet.SetName("W"+postfix2[k])
        hW67jet.Write()

        dir73OS.cd()
        hW73jet.SetName("W"+postfix2[k])
        hW73jet.Write()
        dir74OS.cd()
        hW74jet.SetName("W"+postfix2[k])
        hW74jet.Write()
        dir75OS.cd()
        hW75jet.SetName("W"+postfix2[k])
        hW75jet.Write()
        dir77OS.cd()
        hW77jet.SetName("W"+postfix2[k])
        hW77jet.Write()

        dir0QCDCROS.cd()
        hQCDCR0jet.SetName("W"+postfix0[k])
        hQCDCR0jet.Write()
        dir1QCDCROS.cd()
        hQCDCR1jet.SetName("W"+postfix1[k])
        hQCDCR1jet.Write()
        dir2QCDCROS.cd()
        hQCDCR2jet.SetName("W"+postfix2[k])
        hQCDCR2jet.Write()

        dir0WCROS.cd()
        hWCR0jet.SetName("W"+postfix0[k])
        hWCR0jet.Write()
        dir1WCROS.cd()
        hWCR1jet.SetName("W"+postfix1[k])
        hWCR1jet.Write()
        dir2WCROS.cd()
        hWCR2jet.SetName("W"+postfix2[k])
        hWCR2jet.Write()

        dir0QCDCRSSOS.cd()
        hQCDCRSS0jet.SetName("W"+postfix0[k])
        hQCDCRSS0jet.Write()
        dir1QCDCRSSOS.cd()
        hQCDCRSS1jet.SetName("W"+postfix1[k])
        hQCDCRSS1jet.Write()
        dir2QCDCRSSOS.cd()
        hQCDCRSS2jet.SetName("W"+postfix2[k])
        hQCDCRSS2jet.Write()

        dir0WCRSSOS.cd()
        hWCRSS0jet.SetName("W"+postfix0[k])
        hWCRSS0jet.Write()
        dir1WCRSSOS.cd()
        hWCRSS1jet.SetName("W"+postfix1[k])
        hWCRSS1jet.Write()
        dir2WCRSSOS.cd()
        hWCRSS2jet.SetName("W"+postfix2[k])
        hWCRSS2jet.Write()

        dir0SS.cd()
        hW0jet_SS.SetName("W"+postfix0[k])
        hW0jet_SS.Write()
        dir1SS.cd()
        hW1jet_SS.SetName("W"+postfix1[k])
        hW1jet_SS.Write()
        dir2SS.cd()
        hW2jet_SS.SetName("W"+postfix2[k])
        hW2jet_SS.Write()
        dir3SS.cd()
        hW3jet_SS.SetName("W"+postfix2[k])
        hW3jet_SS.Write()
        dir4SS.cd()
        hW4jet_SS.SetName("W"+postfix2[k])
        hW4jet_SS.Write()
        dir5SS.cd()
        hW5jet_SS.SetName("W"+postfix2[k])
        hW5jet_SS.Write()
        dir7SS.cd()
        hW7jet_SS.SetName("W"+postfix2[k])
        hW7jet_SS.Write()
        dir33SS.cd()
        hW33jet_SS.SetName("W"+postfix2[k])
        hW33jet_SS.Write()
        dir34SS.cd()
        hW34jet_SS.SetName("W"+postfix2[k])
        hW34jet_SS.Write()
        dir35SS.cd()
        hW35jet_SS.SetName("W"+postfix2[k])
        hW35jet_SS.Write()
        dir37SS.cd()
        hW37jet_SS.SetName("W"+postfix2[k])
        hW37jet_SS.Write()
        dir43SS.cd()
        hW43jet_SS.SetName("W"+postfix2[k])
        hW43jet_SS.Write()
        dir44SS.cd()
        hW44jet_SS.SetName("W"+postfix2[k])
        hW44jet_SS.Write()
        dir45SS.cd()
        hW45jet_SS.SetName("W"+postfix2[k])
        hW45jet_SS.Write()
        dir47SS.cd()
        hW47jet_SS.SetName("W"+postfix2[k])
        hW47jet_SS.Write()

        dir53SS.cd()
        hW53jet_SS.SetName("W"+postfix2[k])
        hW53jet_SS.Write()
        dir54SS.cd()
        hW54jet_SS.SetName("W"+postfix2[k])
        hW54jet_SS.Write()
        dir55SS.cd()
        hW55jet_SS.SetName("W"+postfix2[k])
        hW55jet_SS.Write()
        dir57SS.cd()
        hW57jet_SS.SetName("W"+postfix2[k])
        hW57jet_SS.Write()

        dir63SS.cd()
        hW63jet_SS.SetName("W"+postfix2[k])
        hW63jet_SS.Write()
        dir64SS.cd()
        hW64jet_SS.SetName("W"+postfix2[k])
        hW64jet_SS.Write()
        dir65SS.cd()
        hW65jet_SS.SetName("W"+postfix2[k])
        hW65jet_SS.Write()
        dir67SS.cd()
        hW67jet_SS.SetName("W"+postfix2[k])
        hW67jet_SS.Write()

        dir73SS.cd()
        hW73jet_SS.SetName("W"+postfix2[k])
        hW73jet_SS.Write()
        dir74SS.cd()
        hW74jet_SS.SetName("W"+postfix2[k])
        hW74jet_SS.Write()
        dir75SS.cd()
        hW75jet_SS.SetName("W"+postfix2[k])
        hW75jet_SS.Write()
        dir77SS.cd()
        hW77jet_SS.SetName("W"+postfix2[k])
        hW77jet_SS.Write()


        dir0QCD.cd()
        hW0jet_QCD.SetName("W"+postfix0[k])
        hW0jet_QCD.Write()
        dir1QCD.cd()
        hW1jet_QCD.SetName("W"+postfix1[k])
        hW1jet_QCD.Write()
        dir2QCD.cd()
        hW2jet_QCD.SetName("W"+postfix2[k])
        hW2jet_QCD.Write()
        dir3QCD.cd()
        hW3jet_QCD.SetName("W"+postfix2[k])
        hW3jet_QCD.Write()
        dir4QCD.cd()
        hW4jet_QCD.SetName("W"+postfix2[k])
        hW4jet_QCD.Write()
        dir5QCD.cd()
        hW5jet_QCD.SetName("W"+postfix2[k])
        hW5jet_QCD.Write()
        dir7QCD.cd()
        hW7jet_QCD.SetName("W"+postfix2[k])
        hW7jet_QCD.Write()
        dir33QCD.cd()
        hW33jet_QCD.SetName("W"+postfix2[k])
        hW33jet_QCD.Write()
        dir34QCD.cd()
        hW34jet_QCD.SetName("W"+postfix2[k])
        hW34jet_QCD.Write()
        dir35QCD.cd()
        hW35jet_QCD.SetName("W"+postfix2[k])
        hW35jet_QCD.Write()
        dir37QCD.cd()
        hW37jet_QCD.SetName("W"+postfix2[k])
        hW37jet_QCD.Write()
        dir43QCD.cd()
        hW43jet_QCD.SetName("W"+postfix2[k])
        hW43jet_QCD.Write()
        dir44QCD.cd()
        hW44jet_QCD.SetName("W"+postfix2[k])
        hW44jet_QCD.Write()
        dir45QCD.cd()
        hW45jet_QCD.SetName("W"+postfix2[k])
        hW45jet_QCD.Write()
        dir47QCD.cd()
        hW47jet_QCD.SetName("W"+postfix2[k])
        hW47jet_QCD.Write()

        dir53QCD.cd()
        hW53jet_QCD.SetName("W"+postfix2[k])
        hW53jet_QCD.Write()
        dir54QCD.cd()
        hW54jet_QCD.SetName("W"+postfix2[k])
        hW54jet_QCD.Write()
        dir55QCD.cd()
        hW55jet_QCD.SetName("W"+postfix2[k])
        hW55jet_QCD.Write()
        dir57QCD.cd()
        hW57jet_QCD.SetName("W"+postfix2[k])
        hW57jet_QCD.Write()

        dir63QCD.cd()
        hW63jet_QCD.SetName("W"+postfix2[k])
        hW63jet_QCD.Write()
        dir64QCD.cd()
        hW64jet_QCD.SetName("W"+postfix2[k])
        hW64jet_QCD.Write()
        dir65QCD.cd()
        hW65jet_QCD.SetName("W"+postfix2[k])
        hW65jet_QCD.Write()
        dir67QCD.cd()
        hW67jet_QCD.SetName("W"+postfix2[k])
        hW67jet_QCD.Write()

        dir73QCD.cd()
        hW73jet_QCD.SetName("W"+postfix2[k])
        hW73jet_QCD.Write()
        dir74QCD.cd()
        hW74jet_QCD.SetName("W"+postfix2[k])
        hW74jet_QCD.Write()
        dir75QCD.cd()
        hW75jet_QCD.SetName("W"+postfix2[k])
        hW75jet_QCD.Write()
        dir77QCD.cd()
        hW77jet_QCD.SetName("W"+postfix2[k])
        hW77jet_QCD.Write()


        print postfix0[k],postfix1[k],postfix2[k]

