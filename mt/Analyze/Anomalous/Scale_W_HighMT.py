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

    factorw0jmt_u=1.10
    factorw1jmt_u=1.10
    factorw2jmt_u=1.30

    factorw0jmt_d=0.90
    factorw1jmt_d=0.90
    factorw2jmt_d=0.70

    if (options.scale=="wup"):
        factorw0jet=factorw0jmt_u
        factorw1jet=factorw1jmt_u
        factorw2jet=factorw2jmt_u
    if (options.scale=="wdown"):
        factorw0jet=factorw0jmt_d
        factorw1jet=factorw1jmt_d
        factorw2jet=factorw2jmt_d

    factor0jet=1.00
    factor1jet=1.15
    factor2jet=1.20

    factor0jmt_u=1.15
    factor1jmt_u=1.30
    factor2jmt_u=1.50

    factor0jmt_d=0.85
    factor1jmt_d=1.00
    factor2jmt_d=0.90

    if (options.scale=="qcdup"):
        factor0jet=factor0jmt_u
        factor1jet=factor1jmt_u
        factor2jet=factor2jmt_u
    if (options.scale=="qcddown"):
        factor0jet=factor0jmt_d
        factor1jet=factor1jmt_d
        factor2jet=factor2jmt_d

    postfix=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix0=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix1=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfixTES=["_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_mmt_unclustered_13TeVDown","_CMS_scale_mmt_unclustered_13TeVUp","_CMS_scale_mmt_clustered_13TeVDown","_CMS_scale_mmt_clustered_13TeVUp"]

    if (options.scale!="allJES"):
        postfix[0]=""
        postfix0[0]=""
        postfix1[0]=""
        postfix2[0]=""
    if (options.scale=="up"):
        postfix[0]="_CMS_scale_t_mt_13TeVUp"
        postfix0[0]="_CMS_scale_t_mt_13TeVUp"
        postfix1[0]="_CMS_scale_t_mt_13TeVUp"
        postfix2[0]="_CMS_scale_t_mt_13TeVUp"
    if (options.scale=="down"):
        postfix[0]="_CMS_scale_t_mt_13TeVDown"
        postfix0[0]="_CMS_scale_t_mt_13TeVDown"
        postfix1[0]="_CMS_scale_t_mt_13TeVDown"
        postfix2[0]="_CMS_scale_t_mt_13TeVDown"
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
        postfix0[0]="QCD.FUncert_mt_0jmt_13TeVUp"
        postfix1[0]="QCD.FUncert_mt_boosted_13TeVUp"
        postfix2[0]="QCD.FUncert_mt_vbf_13TeVUp"
    if (options.scale=="qcddown"):
        postfix0[0]="QCD.FUncert_mt_0jmt_13TeVDown"
        postfix1[0]="QCD.FUncert_mt_boosted_13TeVDown"
        postfix2[0]="QCD.FUncert_mt_vbf_13TeVDown"
    if (options.scale=="wup"):
        postfix0[0]="_WSFUncert_mt_0jmt_13TeVUp"
        postfix1[0]="_WSFUncert_mt_boosted_13TeVUp"
        postfix2[0]="_WSFUncert_mt_vbf_13TeVUp"
    if (options.scale=="wdown"):
        postfix0[0]="_WSFUncert_mt_0jmt_13TeVDown"
        postfix1[0]="_WSFUncert_mt_boosted_13TeVDown"
        postfix2[0]="_WSFUncert_mt_vbf_13TeVDown"

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

    dir20OS=fout.mkdir("mt_vbf_D0_0p0to0p2")
    dir21OS=fout.mkdir("mt_vbf_D0_0p2to0p4")
    dir22OS=fout.mkdir("mt_vbf_D0_0p4to0p8")
    dir23OS=fout.mkdir("mt_vbf_D0_0p8to1p0")
    dir20SS=fout.mkdir("SS20")
    dir21SS=fout.mkdir("SS21")
    dir22SS=fout.mkdir("SS22")
    dir23SS=fout.mkdir("SS23")
    dir20QCD=fout.mkdir("QCD20")
    dir21QCD=fout.mkdir("QCD21")
    dir22QCD=fout.mkdir("QCD22")
    dir23QCD=fout.mkdir("QCD23")

    dir30OS=fout.mkdir("mt_vbf_D0_0p0to0p2_DCPm")
    dir31OS=fout.mkdir("mt_vbf_D0_0p2to0p4_DCPm")
    dir32OS=fout.mkdir("mt_vbf_D0_0p4to0p8_DCPm")
    dir33OS=fout.mkdir("mt_vbf_D0_0p8to1p0_DCPm")
    dir30SS=fout.mkdir("SS30")
    dir31SS=fout.mkdir("SS31")
    dir32SS=fout.mkdir("SS32")
    dir33SS=fout.mkdir("SS33")
    dir30QCD=fout.mkdir("QCD30")
    dir31QCD=fout.mkdir("QCD31")
    dir32QCD=fout.mkdir("QCD32")
    dir33QCD=fout.mkdir("QCD33")

    dir40OS=fout.mkdir("mt_vbf_D0_0p0to0p2_DCPp")
    dir41OS=fout.mkdir("mt_vbf_D0_0p2to0p4_DCPp")
    dir42OS=fout.mkdir("mt_vbf_D0_0p4to0p8_DCPp")
    dir43OS=fout.mkdir("mt_vbf_D0_0p8to1p0_DCPp")
    dir40SS=fout.mkdir("SS40")
    dir41SS=fout.mkdir("SS41")
    dir42SS=fout.mkdir("SS42")
    dir43SS=fout.mkdir("SS43")
    dir40QCD=fout.mkdir("QCD40")
    dir41QCD=fout.mkdir("QCD41")
    dir42QCD=fout.mkdir("QCD42")
    dir43QCD=fout.mkdir("QCD43")

    dir50OS=fout.mkdir("mt_vbf_D0hplus_0p0to0p2")
    dir51OS=fout.mkdir("mt_vbf_D0hplus_0p2to0p4")
    dir52OS=fout.mkdir("mt_vbf_D0hplus_0p4to0p8")
    dir53OS=fout.mkdir("mt_vbf_D0hplus_0p8to1p0")
    dir50SS=fout.mkdir("SS50")
    dir51SS=fout.mkdir("SS51")
    dir52SS=fout.mkdir("SS52")
    dir53SS=fout.mkdir("SS53")
    dir50QCD=fout.mkdir("QCD50")
    dir51QCD=fout.mkdir("QCD51")
    dir52QCD=fout.mkdir("QCD52")
    dir53QCD=fout.mkdir("QCD53")

    dir60OS=fout.mkdir("mt_vbf_DL1_0p0to0p2")
    dir61OS=fout.mkdir("mt_vbf_DL1_0p2to0p4")
    dir62OS=fout.mkdir("mt_vbf_DL1_0p4to0p8")
    dir63OS=fout.mkdir("mt_vbf_DL1_0p8to1p0")
    dir60SS=fout.mkdir("SS60")
    dir61SS=fout.mkdir("SS61")
    dir62SS=fout.mkdir("SS62")
    dir63SS=fout.mkdir("SS63")
    dir60QCD=fout.mkdir("QCD60")
    dir61QCD=fout.mkdir("QCD61")
    dir62QCD=fout.mkdir("QCD62")
    dir63QCD=fout.mkdir("QCD63")

    dir70OS=fout.mkdir("mt_vbf_DL1Zg_0p0to0p2")
    dir71OS=fout.mkdir("mt_vbf_DL1Zg_0p2to0p4")
    dir72OS=fout.mkdir("mt_vbf_DL1Zg_0p4to0p8")
    dir73OS=fout.mkdir("mt_vbf_DL1Zg_0p8to1p0")
    dir70SS=fout.mkdir("SS70")
    dir71SS=fout.mkdir("SS71")
    dir72SS=fout.mkdir("SS72")
    dir73SS=fout.mkdir("SS73")
    dir70QCD=fout.mkdir("QCD70")
    dir71QCD=fout.mkdir("QCD71")
    dir72QCD=fout.mkdir("QCD72")
    dir73QCD=fout.mkdir("QCD73")

    dir0OS=fout.mkdir("mt_0jet")
    dir1OS=fout.mkdir("mt_boosted")
    dir2OS=fout.mkdir("mt_vbf")
    dir0QCDCROS=fout.mkdir("mt_antiiso_0jet_cr")
    dir1QCDCROS=fout.mkdir("mt_antiiso_boosted_cr")
    dir2QCDCROS=fout.mkdir("mt_antiiso_vbf_cr")
    dir0WCROS=fout.mkdir("mt_wjets_0jet_cr")
    dir1WCROS=fout.mkdir("mt_wjets_boosted_cr")
    dir2WCROS=fout.mkdir("mt_wjets_vbf_cr")
    dir0QCDCRSSOS=fout.mkdir("mt_antiiso_0jet_crSS")
    dir1QCDCRSSOS=fout.mkdir("mt_antiiso_boosted_crSS")
    dir2QCDCRSSOS=fout.mkdir("mt_antiiso_vbf_crSS")
    dir0WCRSSOS=fout.mkdir("mt_wjets_0jet_crSS")
    dir1WCRSSOS=fout.mkdir("mt_wjets_boosted_crSS")
    dir2WCRSSOS=fout.mkdir("mt_wjets_vbf_crSS")
    dir0SS=fout.mkdir("SS0jet")
    dir1SS=fout.mkdir("SS1jet")
    dir2SS=fout.mkdir("SSvbf")
    dir0QCD=fout.mkdir("QCD0jet")
    dir1QCD=fout.mkdir("QCD1jet")
    dir2QCD=fout.mkdir("QCDvbf")


###ggHblock
    list2=["mt_vbf_D0_0p0to0p2_ggH","mt_vbf_D0_0p2to0p4_ggH","mt_vbf_D0_0p4to0p8_ggH","mt_vbf_D0_0p8to1p0_ggH"]
    list3=["mt_vbf_D0_0p0to0p2_DCPm_ggH","mt_vbf_D0_0p2to0p4_DCPm_ggH","mt_vbf_D0_0p4to0p8_DCPm_ggH","mt_vbf_D0_0p8to1p0_DCPm_ggH"]
    list4=["mt_vbf_D0_Pito1p5m_ggH","mt_vbf_D0_1p5to0_ggH","mt_vbf_D0_0to1p5p_ggH","mt_vbf_D0_1p5toPi_ggH"]
    list5=["mt_vbf_Pito1p6m_ggH","mt_vbf_1p6to0_ggH","mt_vbf_0to1p6p_ggH","mt_vbf_1p6toPi_ggH"]
    list6=["mt_vbf_Pito1p6m_ggH_Uns","mt_vbf_1p6to0_ggH_Uns","mt_vbf_0to1p6p_ggH_Uns","mt_vbf_1p6toPi_ggH_Uns"]
    list7=["mt_vbf_dPhia_ggH","mt_vbf_dPhib_ggH","mt_vbf_dPhic_ggH","mt_vbf_dPhid_ggH"]

    dir20ggH=fout.mkdir("mt_vbf_D0_0p0to0p2_ggH")
    dir21ggH=fout.mkdir("mt_vbf_D0_0p2to0p4_ggH")
    dir22ggH=fout.mkdir("mt_vbf_D0_0p4to0p8_ggH")
    dir23ggH=fout.mkdir("mt_vbf_D0_0p8to1p0_ggH")
    dir20SSggH=fout.mkdir("SS20ggH")
    dir21SSggH=fout.mkdir("SS21ggH")
    dir22SSggH=fout.mkdir("SS22ggH")
    dir23SSggH=fout.mkdir("SS23ggH")
    dir20QCDggH=fout.mkdir("QCD20ggH")
    dir21QCDggH=fout.mkdir("QCD21ggH")
    dir22QCDggH=fout.mkdir("QCD22ggH")
    dir23QCDggH=fout.mkdir("QCD23ggH")

    dir30ggH=fout.mkdir("mt_vbf_D0_0p0to0p2_DCPm_ggH")
    dir31ggH=fout.mkdir("mt_vbf_D0_0p2to0p4_DCPm_ggH")
    dir32ggH=fout.mkdir("mt_vbf_D0_0p4to0p8_DCPm_ggH")
    dir33ggH=fout.mkdir("mt_vbf_D0_0p8to1p0_DCPm_ggH")
    dir30SSggH=fout.mkdir("SS30ggH")
    dir31SSggH=fout.mkdir("SS31ggH")
    dir32SSggH=fout.mkdir("SS32ggH")
    dir33SSggH=fout.mkdir("SS33ggH")
    dir30QCDggH=fout.mkdir("QCD30ggH")
    dir31QCDggH=fout.mkdir("QCD31ggH")
    dir32QCDggH=fout.mkdir("QCD32ggH")
    dir33QCDggH=fout.mkdir("QCD33ggH")

    dir40ggH=fout.mkdir("mt_vbf_D0_Pito1p5m_ggH")
    dir41ggH=fout.mkdir("mt_vbf_D0_1p5to0_ggH")
    dir42ggH=fout.mkdir("mt_vbf_D0_0to1p5p_ggH")
    dir43ggH=fout.mkdir("mt_vbf_D0_1p5toPi_ggH")
    dir40SSggH=fout.mkdir("SS40ggH")
    dir41SSggH=fout.mkdir("SS41ggH")
    dir42SSggH=fout.mkdir("SS42ggH")
    dir43SSggH=fout.mkdir("SS43ggH")
    dir40QCDggH=fout.mkdir("QCD40ggH")
    dir41QCDggH=fout.mkdir("QCD41ggH")
    dir42QCDggH=fout.mkdir("QCD42ggH")
    dir43QCDggH=fout.mkdir("QCD43ggH")

    dir50ggH=fout.mkdir("mt_vbf_Pito1p6m_ggH")
    dir51ggH=fout.mkdir("mt_vbf_1p6to0_ggH")
    dir52ggH=fout.mkdir("mt_vbf_0to1p6p_ggH")
    dir53ggH=fout.mkdir("mt_vbf_1p6toPi_ggH")
    dir50SSggH=fout.mkdir("SS50ggH")
    dir51SSggH=fout.mkdir("SS51ggH")
    dir52SSggH=fout.mkdir("SS52ggH")
    dir53SSggH=fout.mkdir("SS53ggH")
    dir50QCDggH=fout.mkdir("QCD50ggH")
    dir51QCDggH=fout.mkdir("QCD51ggH")
    dir52QCDggH=fout.mkdir("QCD52ggH")
    dir53QCDggH=fout.mkdir("QCD53ggH")

    dir60ggH=fout.mkdir("mt_vbf_Pito1p6m_ggH_Uns")
    dir61ggH=fout.mkdir("mt_vbf_1p6to0_ggH_Uns")
    dir62ggH=fout.mkdir("mt_vbf_0to1p6p_ggH_Uns")
    dir63ggH=fout.mkdir("mt_vbf_1p6toPi_ggH_Uns")
    dir60SSggH=fout.mkdir("SS60ggH")
    dir61SSggH=fout.mkdir("SS61ggH")
    dir62SSggH=fout.mkdir("SS62ggH")
    dir63SSggH=fout.mkdir("SS63ggH")
    dir60QCDggH=fout.mkdir("QCD60ggH")
    dir61QCDggH=fout.mkdir("QCD61ggH")
    dir62QCDggH=fout.mkdir("QCD62ggH")
    dir63QCDggH=fout.mkdir("QCD63ggH")

    dir70ggH=fout.mkdir("mt_vbf_dPhia_ggH")
    dir71ggH=fout.mkdir("mt_vbf_dPhib_ggH")
    dir72ggH=fout.mkdir("mt_vbf_dPhic_ggH")
    dir73ggH=fout.mkdir("mt_vbf_dPhid_ggH")
    dir70SSggH=fout.mkdir("SS70ggH")
    dir71SSggH=fout.mkdir("SS71ggH")
    dir72SSggH=fout.mkdir("SS72ggH")
    dir73SSggH=fout.mkdir("SS73ggH")
    dir70QCDggH=fout.mkdir("QCD70ggH")
    dir71QCDggH=fout.mkdir("QCD71ggH")
    dir72QCDggH=fout.mkdir("QCD72ggH")
    dir73QCDggH=fout.mkdir("QCD73ggH")


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
    	#print "reading now  ",post2[k]
	#print " some info  ",fData.Get("n70SS").GetBinContent(2),fDYJ.Get("n70SS"+post2[k]).GetBinContent(2),fDYL.Get("n70SS"+post2[k]).GetBinContent(2),fDYS.Get("n70SS"+post2[k]).GetBinContent(2),fTTJ.Get("n70SS"+post2[k]).GetBinContent(2),fTTT.Get("n70SS"+post2[k]).GetBinContent(2),fVV.Get("n70SS"+post2[k]).GetBinContent(2)#,factor2jet*QCDpassSS2[k-1],fW.Get("n70SS"+post2[k]).GetBinContent(2)

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

        hW0jet=fW.Get("mt_0jet/W"+post2[k])
        hW0jet.Scale(SFpassOS0*factorw0jet)
        hW1jet=fW.Get("mt_boosted/W"+post2[k])
        hW1jet.Scale(SFpassOS1*factorw1jet)
        hW0jetSS=fW.Get("SS0jet/W"+post2[k])
        hW0jetSS.Scale(SFpassOS0*factorw0jet)
        hW1jetSS=fW.Get("SS1jet/W"+post2[k])
        hW1jetSS.Scale(SFpassOS1*factorw1jet)
        hW0jetQCD=fW.Get("QCD0jet/W"+post2[k])
        hW0jetQCD.Scale(SFpassOS0*factorw0jet)
        hW1jetQCD=fW.Get("QCD1jet/W"+post2[k])
        hW1jetQCD.Scale(SFpassOS1*factorw1jet)

        hW2jet=fW.Get("mt_vbf/W"+post2[k])
        hW2jet.Scale(SFpassOS1*factorw2jet)
        hW2jetSS=fW.Get("SSvbf/W"+post2[k])
        hW2jetSS.Scale(SFpassOS1*factorw2jet)
        hW2jetQCD=fW.Get("QCDvbf/W"+post2[k])
        hW2jetQCD.Scale(SFpassOS1*factorw2jet)

        hWCR0jet=fW.Get("mt_wjets_0jet_cr/W"+post2[k])
        hWCR0jet.Scale(SFpassOS0*factorw0jet)
        hWCR1jet=fW.Get("mt_wjets_boosted_cr/W"+post2[k])
        hWCR1jet.Scale(SFpassOS1*factorw1jet)
        hWCR2jet=fW.Get("mt_wjets_vbf_cr/W"+post2[k])
        hWCR2jet.Scale(SFpassOS2*factorw2jet)

        hQCDCR0jet=fW.Get("mt_antiiso_0jet_cr/W"+post2[k])
        hQCDCR0jet.Scale(SFpassOS0*factorw0jet)
        hQCDCR1jet=fW.Get("mt_antiiso_boosted_cr/W"+post2[k])
        hQCDCR1jet.Scale(SFpassOS1*factorw1jet)
        hQCDCR2jet=fW.Get("mt_antiiso_vbf_cr/W"+post2[k])
        hQCDCR2jet.Scale(SFpassOS2*factorw2jet)

        hWCRSS0jet=fW.Get("mt_wjets_0jet_crSS/W"+post2[k])
        hWCRSS0jet.Scale(SFpassOS0*factorw0jet)
        hWCRSS1jet=fW.Get("mt_wjets_boosted_crSS/W"+post2[k])
        hWCRSS1jet.Scale(SFpassOS1*factorw1jet)
        hWCRSS2jet=fW.Get("mt_wjets_vbf_crSS/W"+post2[k])
        hWCRSS2jet.Scale(SFpassOS2*factorw2jet)

        hQCDCRSS0jet=fW.Get("mt_antiiso_0jet_crSS/W"+post2[k])
        hQCDCRSS0jet.Scale(SFpassOS0*factorw0jet)
        hQCDCRSS1jet=fW.Get("mt_antiiso_boosted_crSS/W"+post2[k])
        hQCDCRSS1jet.Scale(SFpassOS1*factorw1jet)
        hQCDCRSS2jet=fW.Get("mt_antiiso_vbf_crSS/W"+post2[k])
        hQCDCRSS2jet.Scale(SFpassOS2*factorw2jet)

        hW20=fW.Get("mt_vbf_D0_0p0to0p2/W"+post2[k])
        hW20.Scale(SFpassOS2*factorw2jet)
        hW21=fW.Get("mt_vbf_D0_0p2to0p4/W"+post2[k])
        hW21.Scale(SFpassOS2*factorw2jet)
        hW22=fW.Get("mt_vbf_D0_0p4to0p8/W"+post2[k])
        hW22.Scale(SFpassOS2*factorw2jet)
        hW23=fW.Get("mt_vbf_D0_0p8to1p0/W"+post2[k])
        hW23.Scale(SFpassOS2*factorw2jet)
        hW20SS=fW.Get("SS20/W"+post2[k])
        hW20SS.Scale(SFpassOS2*factorw2jet)
        hW21SS=fW.Get("SS21/W"+post2[k])
        hW21SS.Scale(SFpassOS2*factorw2jet)
        hW22SS=fW.Get("SS22/W"+post2[k])
        hW22SS.Scale(SFpassOS2*factorw2jet)
        hW23SS=fW.Get("SS23/W"+post2[k])
        hW23SS.Scale(SFpassOS2*factorw2jet)
        hW20QCD=fW.Get("QCD20/W"+post2[k])
        hW20QCD.Scale(SFpassOS2*factorw2jet)
        hW21QCD=fW.Get("QCD21/W"+post2[k])
        hW21QCD.Scale(SFpassOS2*factorw2jet)
        hW22QCD=fW.Get("QCD22/W"+post2[k])
        hW22QCD.Scale(SFpassOS2*factorw2jet)
        hW23QCD=fW.Get("QCD23/W"+post2[k])
        hW23QCD.Scale(SFpassOS2*factorw2jet)

        hW30=fW.Get("mt_vbf_D0_0p0to0p2_DCPm/W"+post2[k])
        hW30.Scale(SFpassOS2*factorw2jet)
        hW31=fW.Get("mt_vbf_D0_0p2to0p4_DCPm/W"+post2[k])
        hW31.Scale(SFpassOS2*factorw2jet)
        hW32=fW.Get("mt_vbf_D0_0p4to0p8_DCPm/W"+post2[k])
        hW32.Scale(SFpassOS2*factorw2jet)
        hW33=fW.Get("mt_vbf_D0_0p8to1p0_DCPm/W"+post2[k])
        hW33.Scale(SFpassOS2*factorw2jet)
        hW30SS=fW.Get("SS30/W"+post2[k])
        hW30SS.Scale(SFpassOS2*factorw2jet)
        hW31SS=fW.Get("SS31/W"+post2[k])
        hW31SS.Scale(SFpassOS2*factorw2jet)
        hW32SS=fW.Get("SS32/W"+post2[k])
        hW32SS.Scale(SFpassOS2*factorw2jet)
        hW33SS=fW.Get("SS33/W"+post2[k])
        hW33SS.Scale(SFpassOS2*factorw2jet)
        hW30QCD=fW.Get("QCD30/W"+post2[k])
        hW30QCD.Scale(SFpassOS2*factorw2jet)
        hW31QCD=fW.Get("QCD31/W"+post2[k])
        hW31QCD.Scale(SFpassOS2*factorw2jet)
        hW32QCD=fW.Get("QCD32/W"+post2[k])
        hW32QCD.Scale(SFpassOS2*factorw2jet)
        hW33QCD=fW.Get("QCD33/W"+post2[k])
        hW33QCD.Scale(SFpassOS2*factorw2jet)

        hW40=fW.Get("mt_vbf_D0_0p0to0p2_DCPp/W"+post2[k])
        hW40.Scale(SFpassOS2*factorw2jet)
        hW41=fW.Get("mt_vbf_D0_0p2to0p4_DCPp/W"+post2[k])
        hW41.Scale(SFpassOS2*factorw2jet)
        hW42=fW.Get("mt_vbf_D0_0p4to0p8_DCPp/W"+post2[k])
        hW42.Scale(SFpassOS2*factorw2jet)
        hW43=fW.Get("mt_vbf_D0_0p8to1p0_DCPp/W"+post2[k])
        hW43.Scale(SFpassOS2*factorw2jet)
        hW40SS=fW.Get("SS40/W"+post2[k])
        hW40SS.Scale(SFpassOS2*factorw2jet)
        hW41SS=fW.Get("SS41/W"+post2[k])
        hW41SS.Scale(SFpassOS2*factorw2jet)
        hW42SS=fW.Get("SS42/W"+post2[k])
        hW42SS.Scale(SFpassOS2*factorw2jet)
        hW43SS=fW.Get("SS43/W"+post2[k])
        hW43SS.Scale(SFpassOS2*factorw2jet)
        hW40QCD=fW.Get("QCD40/W"+post2[k])
        hW40QCD.Scale(SFpassOS2*factorw2jet)
        hW41QCD=fW.Get("QCD41/W"+post2[k])
        hW41QCD.Scale(SFpassOS2*factorw2jet)
        hW42QCD=fW.Get("QCD42/W"+post2[k])
        hW42QCD.Scale(SFpassOS2*factorw2jet)
        hW43QCD=fW.Get("QCD43/W"+post2[k])
        hW43QCD.Scale(SFpassOS2*factorw2jet)

        hW50=fW.Get("mt_vbf_D0hplus_0p0to0p2/W"+post2[k])
        hW50.Scale(SFpassOS2*factorw2jet)
        hW51=fW.Get("mt_vbf_D0hplus_0p2to0p4/W"+post2[k])
        hW51.Scale(SFpassOS2*factorw2jet)
        hW52=fW.Get("mt_vbf_D0hplus_0p4to0p8/W"+post2[k])
        hW52.Scale(SFpassOS2*factorw2jet)
        hW53=fW.Get("mt_vbf_D0hplus_0p8to1p0/W"+post2[k])
        hW53.Scale(SFpassOS2*factorw2jet)
        hW50SS=fW.Get("SS50/W"+post2[k])
        hW50SS.Scale(SFpassOS2*factorw2jet)
        hW51SS=fW.Get("SS51/W"+post2[k])
        hW51SS.Scale(SFpassOS2*factorw2jet)
        hW52SS=fW.Get("SS52/W"+post2[k])
        hW52SS.Scale(SFpassOS2*factorw2jet)
        hW53SS=fW.Get("SS53/W"+post2[k])
        hW53SS.Scale(SFpassOS2*factorw2jet)
        hW50QCD=fW.Get("QCD50/W"+post2[k])
        hW50QCD.Scale(SFpassOS2*factorw2jet)
        hW51QCD=fW.Get("QCD51/W"+post2[k])
        hW51QCD.Scale(SFpassOS2*factorw2jet)
        hW52QCD=fW.Get("QCD52/W"+post2[k])
        hW52QCD.Scale(SFpassOS2*factorw2jet)
        hW53QCD=fW.Get("QCD53/W"+post2[k])
        hW53QCD.Scale(SFpassOS2*factorw2jet)

        hW60=fW.Get("mt_vbf_DL1_0p0to0p2/W"+post2[k])
        hW60.Scale(SFpassOS2*factorw2jet)
        hW61=fW.Get("mt_vbf_DL1_0p2to0p4/W"+post2[k])
        hW61.Scale(SFpassOS2*factorw2jet)
        hW62=fW.Get("mt_vbf_DL1_0p4to0p8/W"+post2[k])
        hW62.Scale(SFpassOS2*factorw2jet)
        hW63=fW.Get("mt_vbf_DL1_0p8to1p0/W"+post2[k])
        hW63.Scale(SFpassOS2*factorw2jet)
        hW60SS=fW.Get("SS60/W"+post2[k])
        hW60SS.Scale(SFpassOS2*factorw2jet)
        hW61SS=fW.Get("SS61/W"+post2[k])
        hW61SS.Scale(SFpassOS2*factorw2jet)
        hW62SS=fW.Get("SS62/W"+post2[k])
        hW62SS.Scale(SFpassOS2*factorw2jet)
        hW63SS=fW.Get("SS63/W"+post2[k])
        hW63SS.Scale(SFpassOS2*factorw2jet)
        hW60QCD=fW.Get("QCD60/W"+post2[k])
        hW60QCD.Scale(SFpassOS2*factorw2jet)
        hW61QCD=fW.Get("QCD61/W"+post2[k])
        hW61QCD.Scale(SFpassOS2*factorw2jet)
        hW62QCD=fW.Get("QCD62/W"+post2[k])
        hW62QCD.Scale(SFpassOS2*factorw2jet)
        hW63QCD=fW.Get("QCD63/W"+post2[k])
        hW63QCD.Scale(SFpassOS2*factorw2jet)

        hW70=fW.Get("mt_vbf_DL1Zg_0p0to0p2/W"+post2[k])
        hW70.Scale(SFpassOS2*factorw2jet)
        hW71=fW.Get("mt_vbf_DL1Zg_0p2to0p4/W"+post2[k])
        hW71.Scale(SFpassOS2*factorw2jet)
        hW72=fW.Get("mt_vbf_DL1Zg_0p4to0p8/W"+post2[k])
        hW72.Scale(SFpassOS2*factorw2jet)
        hW73=fW.Get("mt_vbf_DL1Zg_0p8to1p0/W"+post2[k])
        hW73.Scale(SFpassOS2*factorw2jet)
        hW70SS=fW.Get("SS70/W"+post2[k])
        hW70SS.Scale(SFpassOS2*factorw2jet)
        hW71SS=fW.Get("SS71/W"+post2[k])
        hW71SS.Scale(SFpassOS2*factorw2jet)
        hW72SS=fW.Get("SS72/W"+post2[k])
        hW72SS.Scale(SFpassOS2*factorw2jet)
        hW73SS=fW.Get("SS73/W"+post2[k])
        hW73SS.Scale(SFpassOS2*factorw2jet)
        hW70QCD=fW.Get("QCD70/W"+post2[k])
        hW70QCD.Scale(SFpassOS2*factorw2jet)
        hW71QCD=fW.Get("QCD71/W"+post2[k])
        hW71QCD.Scale(SFpassOS2*factorw2jet)
        hW72QCD=fW.Get("QCD72/W"+post2[k])
        hW72QCD.Scale(SFpassOS2*factorw2jet)
        hW73QCD=fW.Get("QCD73/W"+post2[k])
        hW73QCD.Scale(SFpassOS2*factorw2jet)

	##################### ggH


        hW20ggH=fW.Get("mt_vbf_D0_0p0to0p2_ggH/W"+post2[k])
        hW20ggH.Scale(SFpassOS2*factorw2jet)
        hW21ggH=fW.Get("mt_vbf_D0_0p2to0p4_ggH/W"+post2[k])
        hW21ggH.Scale(SFpassOS2*factorw2jet)
        hW22ggH=fW.Get("mt_vbf_D0_0p4to0p8_ggH/W"+post2[k])
        hW22ggH.Scale(SFpassOS2*factorw2jet)
        hW23ggH=fW.Get("mt_vbf_D0_0p8to1p0_ggH/W"+post2[k])
        hW23ggH.Scale(SFpassOS2*factorw2jet)
        hW20SSggH=fW.Get("SS20ggH/W"+post2[k])
        hW20SSggH.Scale(SFpassOS2*factorw2jet)
        hW21SSggH=fW.Get("SS21ggH/W"+post2[k])
        hW21SSggH.Scale(SFpassOS2*factorw2jet)
        hW22SSggH=fW.Get("SS22ggH/W"+post2[k])
        hW22SSggH.Scale(SFpassOS2*factorw2jet)
        hW23SSggH=fW.Get("SS23ggH/W"+post2[k])
        hW23SSggH.Scale(SFpassOS2*factorw2jet)
        hW20QCDggH=fW.Get("QCD20ggH/W"+post2[k])
        hW20QCDggH.Scale(SFpassOS2*factorw2jet)
        hW21QCDggH=fW.Get("QCD21ggH/W"+post2[k])
        hW21QCDggH.Scale(SFpassOS2*factorw2jet)
        hW22QCDggH=fW.Get("QCD22ggH/W"+post2[k])
        hW22QCDggH.Scale(SFpassOS2*factorw2jet)
        hW23QCDggH=fW.Get("QCD23ggH/W"+post2[k])
        hW23QCDggH.Scale(SFpassOS2*factorw2jet)

        hW30ggH=fW.Get("mt_vbf_D0_0p0to0p2_DCPm_ggH/W"+post2[k])
        hW30ggH.Scale(SFpassOS2*factorw2jet)
        hW31ggH=fW.Get("mt_vbf_D0_0p2to0p4_DCPm_ggH/W"+post2[k])
        hW31ggH.Scale(SFpassOS2*factorw2jet)
        hW32ggH=fW.Get("mt_vbf_D0_0p4to0p8_DCPm_ggH/W"+post2[k])
        hW32ggH.Scale(SFpassOS2*factorw2jet)
        hW33ggH=fW.Get("mt_vbf_D0_0p8to1p0_DCPm_ggH/W"+post2[k])
        hW33ggH.Scale(SFpassOS2*factorw2jet)
        hW30SSggH=fW.Get("SS30ggH/W"+post2[k])
        hW30SSggH.Scale(SFpassOS2*factorw2jet)
        hW31SSggH=fW.Get("SS31ggH/W"+post2[k])
        hW31SSggH.Scale(SFpassOS2*factorw2jet)
        hW32SSggH=fW.Get("SS32ggH/W"+post2[k])
        hW32SSggH.Scale(SFpassOS2*factorw2jet)
        hW33SSggH=fW.Get("SS33ggH/W"+post2[k])
        hW33SSggH.Scale(SFpassOS2*factorw2jet)
        hW30QCDggH=fW.Get("QCD30ggH/W"+post2[k])
        hW30QCDggH.Scale(SFpassOS2*factorw2jet)
        hW31QCDggH=fW.Get("QCD31ggH/W"+post2[k])
        hW31QCDggH.Scale(SFpassOS2*factorw2jet)
        hW32QCDggH=fW.Get("QCD32ggH/W"+post2[k])
        hW32QCDggH.Scale(SFpassOS2*factorw2jet)
        hW33QCDggH=fW.Get("QCD33ggH/W"+post2[k])
        hW33QCDggH.Scale(SFpassOS2*factorw2jet)

        hW40ggH=fW.Get(list4[0]+"/W"+post2[k])
        hW40ggH.Scale(SFpassOS2*factorw2jet)
        hW41ggH=fW.Get(list4[1]+"/W"+post2[k])
        hW41ggH.Scale(SFpassOS2*factorw2jet)
        hW42ggH=fW.Get(list4[2]+"/W"+post2[k])
        hW42ggH.Scale(SFpassOS2*factorw2jet)
        hW43ggH=fW.Get(list4[3]+"/W"+post2[k])
        hW43ggH.Scale(SFpassOS2*factorw2jet)
        hW40SSggH=fW.Get("SS40ggH/W"+post2[k])
        hW40SSggH.Scale(SFpassOS2*factorw2jet)
        hW41SSggH=fW.Get("SS41ggH/W"+post2[k])
        hW41SSggH.Scale(SFpassOS2*factorw2jet)
        hW42SSggH=fW.Get("SS42ggH/W"+post2[k])
        hW42SSggH.Scale(SFpassOS2*factorw2jet)
        hW43SSggH=fW.Get("SS43ggH/W"+post2[k])
        hW43SSggH.Scale(SFpassOS2*factorw2jet)
        hW40QCDggH=fW.Get("QCD40ggH/W"+post2[k])
        hW40QCDggH.Scale(SFpassOS2*factorw2jet)
        hW41QCDggH=fW.Get("QCD41ggH/W"+post2[k])
        hW41QCDggH.Scale(SFpassOS2*factorw2jet)
        hW42QCDggH=fW.Get("QCD42ggH/W"+post2[k])
        hW42QCDggH.Scale(SFpassOS2*factorw2jet)
        hW43QCDggH=fW.Get("QCD43ggH/W"+post2[k])
        hW43QCDggH.Scale(SFpassOS2*factorw2jet)


        hW50ggH=fW.Get(list5[0]+"/W"+post2[k])
        hW50ggH.Scale(SFpassOS2*factorw2jet)
        hW51ggH=fW.Get(list5[1]+"/W"+post2[k])
        hW51ggH.Scale(SFpassOS2*factorw2jet)
        hW52ggH=fW.Get(list5[2]+"/W"+post2[k])
        hW52ggH.Scale(SFpassOS2*factorw2jet)
        hW53ggH=fW.Get(list5[3]+"/W"+post2[k])
        hW53ggH.Scale(SFpassOS2*factorw2jet)
        hW50SSggH=fW.Get("SS50ggH/W"+post2[k])
        hW50SSggH.Scale(SFpassOS2*factorw2jet)
        hW51SSggH=fW.Get("SS51ggH/W"+post2[k])
        hW51SSggH.Scale(SFpassOS2*factorw2jet)
        hW52SSggH=fW.Get("SS52ggH/W"+post2[k])
        hW52SSggH.Scale(SFpassOS2*factorw2jet)
        hW53SSggH=fW.Get("SS53ggH/W"+post2[k])
        hW53SSggH.Scale(SFpassOS2*factorw2jet)
        hW50QCDggH=fW.Get("QCD50ggH/W"+post2[k])
        hW50QCDggH.Scale(SFpassOS2*factorw2jet)
        hW51QCDggH=fW.Get("QCD51ggH/W"+post2[k])
        hW51QCDggH.Scale(SFpassOS2*factorw2jet)
        hW52QCDggH=fW.Get("QCD52ggH/W"+post2[k])
        hW52QCDggH.Scale(SFpassOS2*factorw2jet)
        hW53QCDggH=fW.Get("QCD53ggH/W"+post2[k])
        hW53QCDggH.Scale(SFpassOS2*factorw2jet)


        hW60ggH=fW.Get(list6[0]+"/W"+post2[k])
        hW60ggH.Scale(SFpassOS2*factorw2jet)
        hW61ggH=fW.Get(list6[1]+"/W"+post2[k])
        hW61ggH.Scale(SFpassOS2*factorw2jet)
        hW62ggH=fW.Get(list6[2]+"/W"+post2[k])
        hW62ggH.Scale(SFpassOS2*factorw2jet)
        hW63ggH=fW.Get(list6[3]+"/W"+post2[k])
        hW63ggH.Scale(SFpassOS2*factorw2jet)
        hW60SSggH=fW.Get("SS60ggH/W"+post2[k])
        hW60SSggH.Scale(SFpassOS2*factorw2jet)
        hW61SSggH=fW.Get("SS61ggH/W"+post2[k])
        hW61SSggH.Scale(SFpassOS2*factorw2jet)
        hW62SSggH=fW.Get("SS62ggH/W"+post2[k])
        hW62SSggH.Scale(SFpassOS2*factorw2jet)
        hW63SSggH=fW.Get("SS63ggH/W"+post2[k])
        hW63SSggH.Scale(SFpassOS2*factorw2jet)
        hW60QCDggH=fW.Get("QCD60ggH/W"+post2[k])
        hW60QCDggH.Scale(SFpassOS2*factorw2jet)
        hW61QCDggH=fW.Get("QCD61ggH/W"+post2[k])
        hW61QCDggH.Scale(SFpassOS2*factorw2jet)
        hW62QCDggH=fW.Get("QCD62ggH/W"+post2[k])
        hW62QCDggH.Scale(SFpassOS2*factorw2jet)
        hW63QCDggH=fW.Get("QCD63ggH/W"+post2[k])
        hW63QCDggH.Scale(SFpassOS2*factorw2jet)


        hW70ggH=fW.Get(list7[0]+"/W"+post2[k])
        hW70ggH.Scale(SFpassOS2*factorw2jet)
        hW71ggH=fW.Get(list7[1]+"/W"+post2[k])
        hW71ggH.Scale(SFpassOS2*factorw2jet)
        hW72ggH=fW.Get(list7[2]+"/W"+post2[k])
        hW72ggH.Scale(SFpassOS2*factorw2jet)
        hW73ggH=fW.Get(list7[3]+"/W"+post2[k])
        hW73ggH.Scale(SFpassOS2*factorw2jet)
        hW70SSggH=fW.Get("SS70ggH/W"+post2[k])
        hW70SSggH.Scale(SFpassOS2*factorw2jet)
        hW71SSggH=fW.Get("SS71ggH/W"+post2[k])
        hW71SSggH.Scale(SFpassOS2*factorw2jet)
        hW72SSggH=fW.Get("SS72ggH/W"+post2[k])
        hW72SSggH.Scale(SFpassOS2*factorw2jet)
        hW73SSggH=fW.Get("SS73ggH/W"+post2[k])
        hW73SSggH.Scale(SFpassOS2*factorw2jet)
        hW70QCDggH=fW.Get("QCD70ggH/W"+post2[k])
        hW70QCDggH.Scale(SFpassOS2*factorw2jet)
        hW71QCDggH=fW.Get("QCD71ggH/W"+post2[k])
        hW71QCDggH.Scale(SFpassOS2*factorw2jet)
        hW72QCDggH=fW.Get("QCD72ggH/W"+post2[k])
        hW72QCDggH.Scale(SFpassOS2*factorw2jet)
        hW73QCDggH=fW.Get("QCD73ggH/W"+post2[k])
        hW73QCDggH.Scale(SFpassOS2*factorw2jet)





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
        dir0SS.cd()
        hW0jetSS.SetName("W"+postfix0[k])
        hW0jetSS.Write()
        dir1SS.cd()
        hW1jetSS.SetName("W"+postfix1[k])
        hW1jetSS.Write()
        dir2SS.cd()
        hW2jetSS.SetName("W"+postfix2[k])
        hW2jetSS.Write()

        dir0QCD.cd()
        hW0jetQCD.SetName("W"+postfix0[k])
        hW0jetQCD.Write()
        dir1QCD.cd()
        hW1jetQCD.SetName("W"+postfix1[k])
        hW1jetQCD.Write()
        dir2QCD.cd()
        hW2jetQCD.SetName("W"+postfix2[k])
        hW2jetQCD.Write()



        dir20OS.cd()
        hW20.SetName("W"+postfix2[k])
        hW20.Write()
        dir21OS.cd()
        hW21.SetName("W"+postfix2[k])
        hW21.Write()
        dir22OS.cd()
        hW22.SetName("W"+postfix2[k])
        hW22.Write()
        dir23OS.cd()
        hW23.SetName("W"+postfix2[k])
        hW23.Write()

        dir30OS.cd()
        hW30.SetName("W"+postfix2[k])
        hW30.Write()
        dir31OS.cd()
        hW31.SetName("W"+postfix2[k])
        hW31.Write()
        dir32OS.cd()
        hW32.SetName("W"+postfix2[k])
        hW32.Write()
        dir33OS.cd()
        hW33.SetName("W"+postfix2[k])
        hW33.Write()

        dir40OS.cd()
        hW40.SetName("W"+postfix2[k])
        hW40.Write()
        dir41OS.cd()
        hW41.SetName("W"+postfix2[k])
        hW41.Write()
        dir42OS.cd()
        hW42.SetName("W"+postfix2[k])
        hW42.Write()
        dir43OS.cd()
        hW43.SetName("W"+postfix2[k])
        hW43.Write()


        dir50OS.cd()
        hW50.SetName("W"+postfix2[k])
        hW50.Write()
        dir51OS.cd()
        hW51.SetName("W"+postfix2[k])
        hW51.Write()
        dir52OS.cd()
        hW52.SetName("W"+postfix2[k])
        hW52.Write()
        dir53OS.cd()
        hW53.SetName("W"+postfix2[k])
        hW53.Write()


        dir60OS.cd()
        hW60.SetName("W"+postfix2[k])
        hW60.Write()
        dir61OS.cd()
        hW61.SetName("W"+postfix2[k])
        hW61.Write()
        dir62OS.cd()
        hW62.SetName("W"+postfix2[k])
        hW62.Write()
        dir63OS.cd()
        hW63.SetName("W"+postfix2[k])
        hW63.Write()


        dir70OS.cd()
        hW70.SetName("W"+postfix2[k])
        hW70.Write()
        dir71OS.cd()
        hW71.SetName("W"+postfix2[k])
        hW71.Write()
        dir72OS.cd()
        hW72.SetName("W"+postfix2[k])
        hW72.Write()
        dir73OS.cd()
        hW73.SetName("W"+postfix2[k])
        hW73.Write()

        dir20ggH.cd()
        hW20ggH.SetName("W"+postfix2[k])
        hW20ggH.Write()
        dir21ggH.cd()
        hW21ggH.SetName("W"+postfix2[k])
        hW21ggH.Write()
        dir22ggH.cd()
        hW22ggH.SetName("W"+postfix2[k])
        hW22ggH.Write()
        dir23ggH.cd()
        hW23ggH.SetName("W"+postfix2[k])
        hW23ggH.Write()

        dir30ggH.cd()
        hW30ggH.SetName("W"+postfix2[k])
        hW30ggH.Write()
        dir31ggH.cd()
        hW31ggH.SetName("W"+postfix2[k])
        hW31ggH.Write()
        dir32ggH.cd()
        hW32ggH.SetName("W"+postfix2[k])
        hW32ggH.Write()
        dir33ggH.cd()
        hW33ggH.SetName("W"+postfix2[k])
        hW33ggH.Write()


        dir40ggH.cd()
        hW40ggH.SetName("W"+postfix2[k])
        hW40ggH.Write()
        dir41ggH.cd()
        hW41ggH.SetName("W"+postfix2[k])
        hW41ggH.Write()
        dir42ggH.cd()
        hW42ggH.SetName("W"+postfix2[k])
        hW42ggH.Write()
        dir43ggH.cd()
        hW43ggH.SetName("W"+postfix2[k])
        hW43ggH.Write()

        dir50ggH.cd()
        hW50ggH.SetName("W"+postfix2[k])
        hW50ggH.Write()
        dir51ggH.cd()
        hW51ggH.SetName("W"+postfix2[k])
        hW51ggH.Write()
        dir52ggH.cd()
        hW52ggH.SetName("W"+postfix2[k])
        hW52ggH.Write()
        dir53ggH.cd()
        hW53ggH.SetName("W"+postfix2[k])
        hW53ggH.Write()



        dir60ggH.cd()
        hW60ggH.SetName("W"+postfix2[k])
        hW60ggH.Write()
        dir61ggH.cd()
        hW61ggH.SetName("W"+postfix2[k])
        hW61ggH.Write()
        dir62ggH.cd()
        hW62ggH.SetName("W"+postfix2[k])
        hW62ggH.Write()
        dir63ggH.cd()
        hW63ggH.SetName("W"+postfix2[k])
        hW63ggH.Write()


        dir70ggH.cd()
        hW70ggH.SetName("W"+postfix2[k])
        hW70ggH.Write()
        dir71ggH.cd()
        hW71ggH.SetName("W"+postfix2[k])
        hW71ggH.Write()
        dir72ggH.cd()
        hW72ggH.SetName("W"+postfix2[k])
        hW72ggH.Write()
        dir73ggH.cd()
        hW73ggH.SetName("W"+postfix2[k])
        hW73ggH.Write()
        
	######SS

        dir20SS.cd()
        hW20.SetName("W"+postfix2[k])
        hW20.Write()
        dir21SS.cd()
        hW21.SetName("W"+postfix2[k])
        hW21.Write()
        dir22SS.cd()
        hW22.SetName("W"+postfix2[k])
        hW22.Write()
        dir23SS.cd()
        hW23.SetName("W"+postfix2[k])
        hW23.Write()

        dir30SS.cd()
        hW30.SetName("W"+postfix2[k])
        hW30.Write()
        dir31SS.cd()
        hW31.SetName("W"+postfix2[k])
        hW31.Write()
        dir32SS.cd()
        hW32.SetName("W"+postfix2[k])
        hW32.Write()
        dir33SS.cd()
        hW33.SetName("W"+postfix2[k])
        hW33.Write()

        dir40SS.cd()
        hW40.SetName("W"+postfix2[k])
        hW40.Write()
        dir41SS.cd()
        hW41.SetName("W"+postfix2[k])
        hW41.Write()
        dir42SS.cd()
        hW42.SetName("W"+postfix2[k])
        hW42.Write()
        dir43SS.cd()
        hW43.SetName("W"+postfix2[k])
        hW43.Write()


        dir50SS.cd()
        hW50.SetName("W"+postfix2[k])
        hW50.Write()
        dir51SS.cd()
        hW51.SetName("W"+postfix2[k])
        hW51.Write()
        dir52SS.cd()
        hW52.SetName("W"+postfix2[k])
        hW52.Write()
        dir53SS.cd()
        hW53.SetName("W"+postfix2[k])
        hW53.Write()


        dir60SS.cd()
        hW60.SetName("W"+postfix2[k])
        hW60.Write()
        dir61SS.cd()
        hW61.SetName("W"+postfix2[k])
        hW61.Write()
        dir62SS.cd()
        hW62.SetName("W"+postfix2[k])
        hW62.Write()
        dir63SS.cd()
        hW63.SetName("W"+postfix2[k])
        hW63.Write()


        dir70SS.cd()
        hW70.SetName("W"+postfix2[k])
        hW70.Write()
        dir71SS.cd()
        hW71.SetName("W"+postfix2[k])
        hW71.Write()
        dir72SS.cd()
        hW72.SetName("W"+postfix2[k])
        hW72.Write()
        dir73SS.cd()
        hW73.SetName("W"+postfix2[k])
        hW73.Write()


        dir20SSggH.cd()
        hW20SSggH.SetName("W"+postfix2[k])
        hW20SSggH.Write()
        dir21SSggH.cd()
        hW21SSggH.SetName("W"+postfix2[k])
        hW21SSggH.Write()
        dir22SSggH.cd()
        hW22SSggH.SetName("W"+postfix2[k])
        hW22SSggH.Write()
        dir23SSggH.cd()
        hW23SSggH.SetName("W"+postfix2[k])
        hW23SSggH.Write()



        dir30SSggH.cd()
        hW30SSggH.SetName("W"+postfix2[k])
        hW30SSggH.Write()
        dir31SSggH.cd()
        hW31SSggH.SetName("W"+postfix2[k])
        hW31SSggH.Write()
        dir32SSggH.cd()
        hW32SSggH.SetName("W"+postfix2[k])
        hW32SSggH.Write()
        dir33SSggH.cd()
        hW33SSggH.SetName("W"+postfix2[k])
        hW33SSggH.Write()


        dir40SSggH.cd()
        hW40SSggH.SetName("W"+postfix2[k])
        hW40SSggH.Write()
        dir41SSggH.cd()
        hW41SSggH.SetName("W"+postfix2[k])
        hW41SSggH.Write()
        dir42SSggH.cd()
        hW42SSggH.SetName("W"+postfix2[k])
        hW42SSggH.Write()
        dir43SSggH.cd()
        hW43SSggH.SetName("W"+postfix2[k])
        hW43SSggH.Write()

        dir50SSggH.cd()
        hW50SSggH.SetName("W"+postfix2[k])
        hW50SSggH.Write()
        dir51SSggH.cd()
        hW51SSggH.SetName("W"+postfix2[k])
        hW51SSggH.Write()
        dir52SSggH.cd()
        hW52SSggH.SetName("W"+postfix2[k])
        hW52SSggH.Write()
        dir53SSggH.cd()
        hW53SSggH.SetName("W"+postfix2[k])
        hW53SSggH.Write()



        dir60SSggH.cd()
        hW60SSggH.SetName("W"+postfix2[k])
        hW60SSggH.Write()
        dir61SSggH.cd()
        hW61SSggH.SetName("W"+postfix2[k])
        hW61SSggH.Write()
        dir62SSggH.cd()
        hW62SSggH.SetName("W"+postfix2[k])
        hW62SSggH.Write()
        dir63SSggH.cd()
        hW63SSggH.SetName("W"+postfix2[k])
        hW63SSggH.Write()


        dir70SSggH.cd()
        hW70SSggH.SetName("W"+postfix2[k])
        hW70SSggH.Write()
        dir71SSggH.cd()
        hW71SSggH.SetName("W"+postfix2[k])
        hW71SSggH.Write()
        dir72SSggH.cd()
        hW72SSggH.SetName("W"+postfix2[k])
        hW72SSggH.Write()
        dir73SSggH.cd()
        hW73SSggH.SetName("W"+postfix2[k])
        hW73SSggH.Write()
        

        dir20QCD.cd()
        hW20.SetName("W"+postfix2[k])
        hW20.Write()
        dir21QCD.cd()
        hW21.SetName("W"+postfix2[k])
        hW21.Write()
        dir22QCD.cd()
        hW22.SetName("W"+postfix2[k])
        hW22.Write()
        dir23QCD.cd()
        hW23.SetName("W"+postfix2[k])
        hW23.Write()


        dir30QCD.cd()
        hW30.SetName("W"+postfix2[k])
        hW30.Write()
        dir31QCD.cd()
        hW31.SetName("W"+postfix2[k])
        hW31.Write()
        dir32QCD.cd()
        hW32.SetName("W"+postfix2[k])
        hW32.Write()
        dir33QCD.cd()
        hW33.SetName("W"+postfix2[k])
        hW33.Write()

        dir40QCD.cd()
        hW40.SetName("W"+postfix2[k])
        hW40.Write()
        dir41QCD.cd()
        hW41.SetName("W"+postfix2[k])
        hW41.Write()
        dir42QCD.cd()
        hW42.SetName("W"+postfix2[k])
        hW42.Write()
        dir43QCD.cd()
        hW43.SetName("W"+postfix2[k])
        hW43.Write()


        dir50QCD.cd()
        hW50.SetName("W"+postfix2[k])
        hW50.Write()
        dir51QCD.cd()
        hW51.SetName("W"+postfix2[k])
        hW51.Write()
        dir52QCD.cd()
        hW52.SetName("W"+postfix2[k])
        hW52.Write()
        dir53QCD.cd()
        hW53.SetName("W"+postfix2[k])
        hW53.Write()


        dir60QCD.cd()
        hW60.SetName("W"+postfix2[k])
        hW60.Write()
        dir61QCD.cd()
        hW61.SetName("W"+postfix2[k])
        hW61.Write()
        dir62QCD.cd()
        hW62.SetName("W"+postfix2[k])
        hW62.Write()
        dir63QCD.cd()
        hW63.SetName("W"+postfix2[k])
        hW63.Write()


        dir70QCD.cd()
        hW70.SetName("W"+postfix2[k])
        hW70.Write()
        dir71QCD.cd()
        hW71.SetName("W"+postfix2[k])
        hW71.Write()
        dir72QCD.cd()
        hW72.SetName("W"+postfix2[k])
        hW72.Write()
        dir73QCD.cd()
        hW73.SetName("W"+postfix2[k])
        hW73.Write()


        dir20QCDggH.cd()
        hW20QCDggH.SetName("W"+postfix2[k])
        hW20QCDggH.Write()
        dir21QCDggH.cd()
        hW21QCDggH.SetName("W"+postfix2[k])
        hW21QCDggH.Write()
        dir22QCDggH.cd()
        hW22QCDggH.SetName("W"+postfix2[k])
        hW22QCDggH.Write()
        dir23QCDggH.cd()
        hW23QCDggH.SetName("W"+postfix2[k])
        hW23QCDggH.Write()


        dir30QCDggH.cd()
        hW30QCDggH.SetName("W"+postfix2[k])
        hW30QCDggH.Write()
        dir31QCDggH.cd()
        hW31QCDggH.SetName("W"+postfix2[k])
        hW31QCDggH.Write()
        dir32QCDggH.cd()
        hW32QCDggH.SetName("W"+postfix2[k])
        hW32QCDggH.Write()
        dir33QCDggH.cd()
        hW33QCDggH.SetName("W"+postfix2[k])
        hW33QCDggH.Write()


        dir40QCDggH.cd()
        hW40QCDggH.SetName("W"+postfix2[k])
        hW40QCDggH.Write()
        dir41QCDggH.cd()
        hW41QCDggH.SetName("W"+postfix2[k])
        hW41QCDggH.Write()
        dir42QCDggH.cd()
        hW42QCDggH.SetName("W"+postfix2[k])
        hW42QCDggH.Write()
        dir43QCDggH.cd()
        hW43QCDggH.SetName("W"+postfix2[k])
        hW43QCDggH.Write()

        dir50QCDggH.cd()
        hW50QCDggH.SetName("W"+postfix2[k])
        hW50QCDggH.Write()
        dir51QCDggH.cd()
        hW51QCDggH.SetName("W"+postfix2[k])
        hW51QCDggH.Write()
        dir52QCDggH.cd()
        hW52QCDggH.SetName("W"+postfix2[k])
        hW52QCDggH.Write()
        dir53QCDggH.cd()
        hW53QCDggH.SetName("W"+postfix2[k])
        hW53QCDggH.Write()



        dir60QCDggH.cd()
        hW60QCDggH.SetName("W"+postfix2[k])
        hW60QCDggH.Write()
        dir61QCDggH.cd()
        hW61QCDggH.SetName("W"+postfix2[k])
        hW61QCDggH.Write()
        dir62QCDggH.cd()
        hW62QCDggH.SetName("W"+postfix2[k])
        hW62QCDggH.Write()
        dir63QCDggH.cd()
        hW63QCDggH.SetName("W"+postfix2[k])
        hW63QCDggH.Write()


        dir70QCDggH.cd()
        hW70QCDggH.SetName("W"+postfix2[k])
        hW70QCDggH.Write()
        dir71QCDggH.cd()
        hW71QCDggH.SetName("W"+postfix2[k])
        hW71QCDggH.Write()
        dir72QCDggH.cd()
        hW72QCDggH.SetName("W"+postfix2[k])
        hW72QCDggH.Write()
        dir73QCDggH.cd()
        hW73QCDggH.SetName("W"+postfix2[k])
        hW73QCDggH.Write()
        







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
        hW0jetSS.SetName("W"+postfix0[k])
        hW0jetSS.Write()
        dir1SS.cd()
        hW1jetSS.SetName("W"+postfix1[k])
        hW1jetSS.Write()
        dir2SS.cd()
        hW2jetSS.SetName("W"+postfix2[k])
        hW2jetSS.Write()

        dir0QCD.cd()
        hW0jetQCD.SetName("W"+postfix0[k])
        hW0jetQCD.Write()
        dir1QCD.cd()
        hW1jetQCD.SetName("W"+postfix1[k])
        hW1jetQCD.Write()
        dir2QCD.cd()
        hW2jetQCD.SetName("W"+postfix2[k])
        hW2jetQCD.Write()











        print postfix0[k],postfix1[k],postfix2[k]

