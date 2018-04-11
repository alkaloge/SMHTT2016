#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <TF1.h>
#include <TDirectoryFile.h>
#include <TRandom3.h>
#include "TLorentzVector.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "myHelper.h"
#include "tr_Tree.h"
#include "ScaleFactor.h"
#include "LumiReweightingStandAlone.h"
#include "ZmmSF.h"
#include "btagSF.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"

using namespace std;

int main(int argc, char** argv) {

    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string name = *(argv + 4);

    float tes=0;
    if (argc > 1) {
        tes = atof(argv[5]);
    }

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("etau_tree");
cout<<"avant"<<endl;
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);
cout<<"test"<<endl;

    TFile *f_eTrk=new TFile("etracking.root");
    TH2F *h_eTrk=(TH2F*) f_eTrk->Get("EGamma_SF2D");

    reweight::LumiReWeighting* LumiWeights_12;
    LumiWeights_12 = new reweight::LumiReWeighting("MC_Moriond17_PU25ns_V1.root", "Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");

    TFile *fZ=new TFile("zpt_weights_2016_BtoH.root");
    TH2F *histZ=(TH2F*) fZ->Get("zptmass_histo");

    TFile *fM=new TFile("mjj_detajj_weights_2016_BtoH.root");
    TH2F *histM=(TH2F*) fM->Get("detajjmjj_histo");

    TFile fw("htt_scalefactors_v16_3.root");
    RooWorkspace *w = (RooWorkspace*)fw.Get("w");
    fw.Close();

    float xs=1.0; float weight=1.0; float luminosity=35870.0;
    if (sample=="ZL" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL"){ xs=5765.4; weight=luminosity*xs/ngen;}
    else if (sample=="TT" or sample=="TTT" or sample=="TTJ") {xs=831.76; weight=luminosity*xs/ngen;}
    else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}
    else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
    else if (sample=="data_obs"){weight=1.0;}
    else if (sample=="WZ1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
    else if (sample=="WZ1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
    else if (sample=="WZJets") {xs=5.26; weight=luminosity*xs/ngen;}
    else if (sample=="WZLLLNu") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="WZ2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
    else if (sample=="WW1L1Nu2Q") {xs=49.997; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.212; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_antitop") {xs=26.23; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_top") {xs=44.07; weight=luminosity*xs/ngen;}
    else if (sample=="ggh") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH125") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH120") {xs=52.22*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="VBF120") {xs=3.935*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ggH130") {xs=45.31*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="VBF130") {xs=3.637*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ggH110") {xs=57.90*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="VBF110") {xs=4.434*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ggH140") {xs=36.00*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="VBF140") {xs=3.492*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW125") {xs=48.58*0.2137*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBF_WW125") {xs=3.782*0.2137*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW120") {xs=52.22*0.1405*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBF_WW120") {xs=3.935*0.1405*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW130") {xs=45.31*0.3021*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBF_WW130") {xs=3.637*0.3021*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH120") {xs=0.9558*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH125") {xs=0.840*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH130") {xs=0.7414*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH140") {xs=0.6308*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH110") {xs=1.335*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH120") {xs=0.6092*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=0.5328*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH130") {xs=0.4676*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH110") {xs=0.8587*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH140") {xs=0.3940*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WH125") {xs=(0.840+0.5328)*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ZH120") {xs=0.9939*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ZH125") {xs=0.8839*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ZH130") {xs=0.7899*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ZH110") {xs=1.309*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ZH140") {xs=0.6514*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WGLNu") {xs=489.0; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarMuMu") {xs=2.793; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarEE") {xs=3.526; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWminus") {xs=20.25; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWplus") {xs=25.62; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZLL" or sample=="EWKZLL_TT" or sample=="EWKZLL_J" or sample=="EWKZLL_L" or sample=="EWKZLL_LL") {xs=3.987; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZNuNu" or sample=="EWKZNuNu_TT" or sample=="EWKZNuNu_J" or sample=="EWKZNuNu_L" or sample=="EWKZNuNu_LL") {xs=10.01; weight=luminosity*xs/ngen;}
    else cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("jhuw_a1", &jhuw_a1);
    arbre->SetBranchAddress("jhuw_a2", &jhuw_a2);
    arbre->SetBranchAddress("jhuw_a3", &jhuw_a3);
    arbre->SetBranchAddress("jhuw_l1", &jhuw_l1);
    arbre->SetBranchAddress("jhuw_l1Zg", &jhuw_l1Zg);
    arbre->SetBranchAddress("jhuw_a2int", &jhuw_a2int);
    arbre->SetBranchAddress("jhuw_a3int", &jhuw_a3int);
    arbre->SetBranchAddress("jhuw_l1int", &jhuw_l1int);
    arbre->SetBranchAddress("jhuw_l1Zgint", &jhuw_l1Zgint);
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("NUP", &NUP);
    arbre->SetBranchAddress("npv", &npv);
    arbre->SetBranchAddress("bpt_1", &bpt_1);
    arbre->SetBranchAddress("bpt_2", &bpt_2);
    arbre->SetBranchAddress("bflavor_1", &bflavor_1);
    arbre->SetBranchAddress("bflavor_2", &bflavor_2);
    arbre->SetBranchAddress("px_1", &px_1);
    arbre->SetBranchAddress("py_1", &py_1);
    arbre->SetBranchAddress("pz_1", &pz_1);
    arbre->SetBranchAddress("pt_1", &pt_1);
    arbre->SetBranchAddress("phi_1", &phi_1);
    arbre->SetBranchAddress("eta_1", &eta_1);
    arbre->SetBranchAddress("iso_1", &iso_1);
    arbre->SetBranchAddress("m_1", &m_1);
    arbre->SetBranchAddress("q_1", &q_1);
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("px_2", &px_2);
    arbre->SetBranchAddress("py_2", &py_2);
    arbre->SetBranchAddress("pz_2", &pz_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("mt_2", &mt_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("m_sv", &m_sv);
    arbre->SetBranchAddress("m_sv_DOWN", &m_sv_DOWN);
    arbre->SetBranchAddress("m_sv_UP", &m_sv_UP);
    arbre->SetBranchAddress("m_sv_UESDown", &m_sv_UESDown);
    arbre->SetBranchAddress("m_sv_UESUp", &m_sv_UESUp);
    arbre->SetBranchAddress("m_sv_JESDown", &m_sv_JESDown);
    arbre->SetBranchAddress("m_sv_JESUp", &m_sv_JESUp);
    arbre->SetBranchAddress("pt_sv", &pt_sv);
    arbre->SetBranchAddress("pt_sv_DOWN", &pt_sv_DOWN);
    arbre->SetBranchAddress("pt_sv_UP", &pt_sv_UP);
    arbre->SetBranchAddress("pt_sv_UESDown", &pt_sv_UESDown);
    arbre->SetBranchAddress("pt_sv_UESUp", &pt_sv_UESUp);
    arbre->SetBranchAddress("pt_sv_JESDown", &pt_sv_JESDown);
    arbre->SetBranchAddress("pt_sv_JESUp", &pt_sv_JESUp);
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("jpt_2", &jpt_2);
    arbre->SetBranchAddress("jeta_1", &jeta_1);
    arbre->SetBranchAddress("jeta_2", &jeta_2);
    arbre->SetBranchAddress("jphi_1", &jphi_1);
    arbre->SetBranchAddress("jphi_2", &jphi_2);
    arbre->SetBranchAddress("jdeta", &jdeta);
    arbre->SetBranchAddress("mjj", &mjj);
    arbre->SetBranchAddress("genweight", &genweight);
    arbre->SetBranchAddress("mjj_JESDown", &mjj_JESDown);
    arbre->SetBranchAddress("mjj_JESUp", &mjj_JESUp);
    arbre->SetBranchAddress("jdeta_JESDown", &jdeta_JESDown);
    arbre->SetBranchAddress("jdeta_JESUp", &jdeta_JESUp);
    arbre->SetBranchAddress("njets_JESDown", &njets_JESDown);
    arbre->SetBranchAddress("njets_JESUp", &njets_JESUp);
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_2",&byVLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_2",&byLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_2",&byMediumIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_2",&byTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_2",&byVTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byIsolationMVA3oldDMwLTraw_2",&byIsolationMVA3oldDMwLTraw_2);
    arbre->SetBranchAddress("byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2", &byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationRerunMVArun2v1DBoldDMwLT_2", &byLooseIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationRerunMVArun2v1DBoldDMwLT_2", &byMediumIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationRerunMVArun2v1DBoldDMwLT_2", &byTightIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationRerunMVArun2v1DBoldDMwLT_2", &byVTightIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2", &byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2);

    arbre->SetBranchAddress("passEle25eta2p1Tight", &passEle25eta2p1Tight);
    arbre->SetBranchAddress("passEle27eta2p1Loose", &passEle27eta2p1Loose);
    arbre->SetBranchAddress("passEle24Tau20sL1", &passEle24Tau20sL1);
    arbre->SetBranchAddress("passEle24Tau20", &passEle24Tau20);
    arbre->SetBranchAddress("passEle24Tau30", &passEle24Tau30);
    arbre->SetBranchAddress("matchEle25eta2p1Tight_1", &matchEle25eta2p1Tight_1);
    arbre->SetBranchAddress("matchEle27eta2p1Loose_1", &matchEle27eta2p1Loose_1);
    arbre->SetBranchAddress("matchEle24Tau20sL1_1", &matchEle24Tau20sL1_1);
    arbre->SetBranchAddress("matchEle24Tau20_1", &matchEle24Tau20_1);
    arbre->SetBranchAddress("matchEle24Tau30_1", &matchEle24Tau30_1);
    arbre->SetBranchAddress("filterEle25eta2p1Tight_1", &filterEle25eta2p1Tight_1);
    arbre->SetBranchAddress("filterEle27eta2p1Loose_1", &filterEle27eta2p1Loose_1);
    arbre->SetBranchAddress("filterEle24Tau20sL1_1", &filterEle24Tau20sL1_1);
    arbre->SetBranchAddress("filterEle24Tau20_1", &filterEle24Tau20_1);
    arbre->SetBranchAddress("filterEle24Tau30_1", &filterEle24Tau30_1);
    arbre->SetBranchAddress("matchEle24Tau20sL1_2", &matchEle24Tau20sL1_2);
    arbre->SetBranchAddress("matchEle24Tau20_2", &matchEle24Tau20_2);
    arbre->SetBranchAddress("matchEle24Tau30_2", &matchEle24Tau30_2);
    arbre->SetBranchAddress("filterEle24Tau20sL1_2", &filterEle24Tau20sL1_2);
    arbre->SetBranchAddress("filterEle24Tau20_2", &filterEle24Tau20_2);
    arbre->SetBranchAddress("filterEle24Tau30_2", &filterEle24Tau30_2);

    //arbre->SetBranchAddress("e_2",&e_2);
    arbre->SetBranchAddress("decayModeFindingNewDMs_2",&decayModeFindingNewDMs_2);
    arbre->SetBranchAddress("decayModeFinding_2",&decayModeFinding_2);
    arbre->SetBranchAddress("l2_decayMode",&l2_decayMode);
    arbre->SetBranchAddress("againstElectronTightMVA6_2",&againstElectronTightMVA6_2);
    arbre->SetBranchAddress("againstMuonLoose3_2",&againstMuonLoose3_2);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    arbre->SetBranchAddress("m_vis",&m_vis);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    arbre->SetBranchAddress("numGenJets",&numGenJets);

    //arbre->SetBranchAddress("melaD0minus", &melaD0minus);
    //arbre->SetBranchAddress("melaDCP", &melaDCP);
    arbre->SetBranchAddress("melaDL1Zgint", &melaDL1Zgint);
    arbre->SetBranchAddress("melaDL1Zg", &melaDL1Zg);
    arbre->SetBranchAddress("melaDCP", &melaDCP);
    arbre->SetBranchAddress("melaD0minus", &melaD0minus);
    arbre->SetBranchAddress("melaD0hplus", &melaD0hplus);
    arbre->SetBranchAddress("melaDint", &melaDint);
    arbre->SetBranchAddress("melaDL1", &melaDL1);
    arbre->SetBranchAddress("melaDL1int", &melaDL1int);


    arbre->SetBranchAddress("melaD0minusggH", &melaD0minusggH);
    arbre->SetBranchAddress("melaDCPggH", &melaDCPggH);
    arbre->SetBranchAddress("melaDPhijj", &melaDPhijj);
    arbre->SetBranchAddress("melaDPhiUnsignedjj", &melaDPhiUnsignedjj);
    arbre->SetBranchAddress("melaDEtajj", &dEta_jj);
    arbre->SetBranchAddress("melacosthetastar", &costhetastar);
    arbre->SetBranchAddress("melacostheta1", &costheta1);
    arbre->SetBranchAddress("melacostheta2", &costheta2);
    arbre->SetBranchAddress("melaPhi", &melaPhi);
    arbre->SetBranchAddress("melaPhi1", &melaPhi1);
    arbre->SetBranchAddress("melaQ2V1", &Q2V1);
    arbre->SetBranchAddress("melaQ2V2", &Q2V2);
    arbre->SetBranchAddress("melaSqrtQ2V1", &sqrtQ2V1);
    arbre->SetBranchAddress("melaSqrtQ2V2", &sqrtQ2V2);
    arbre->SetBranchAddress("melaAvgSqrtQ2V12", &avgSqrtQ2V12);

    arbre->SetBranchAddress("njets_JetAbsoluteFlavMapDown",&njets_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("njets_JetAbsoluteFlavMapUp",&njets_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("njets_JetAbsoluteMPFBiasDown",&njets_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("njets_JetAbsoluteMPFBiasUp",&njets_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("njets_JetAbsoluteScaleDown",&njets_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("njets_JetAbsoluteScaleUp",&njets_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("njets_JetAbsoluteStatDown",&njets_JetAbsoluteStatDown);
    arbre->SetBranchAddress("njets_JetAbsoluteStatUp",&njets_JetAbsoluteStatUp);
    arbre->SetBranchAddress("njets_JetFlavorQCDDown",&njets_JetFlavorQCDDown);
    arbre->SetBranchAddress("njets_JetFlavorQCDUp",&njets_JetFlavorQCDUp);
    arbre->SetBranchAddress("njets_JetFragmentationDown",&njets_JetFragmentationDown);
    arbre->SetBranchAddress("njets_JetFragmentationUp",&njets_JetFragmentationUp);
    arbre->SetBranchAddress("njets_JetPileUpDataMCDown",&njets_JetPileUpDataMCDown);
    arbre->SetBranchAddress("njets_JetPileUpDataMCUp",&njets_JetPileUpDataMCUp);
    arbre->SetBranchAddress("njets_JetPileUpPtBBDown",&njets_JetPileUpPtBBDown);
    arbre->SetBranchAddress("njets_JetPileUpPtBBUp",&njets_JetPileUpPtBBUp);
    arbre->SetBranchAddress("njets_JetPileUpPtEC1Down",&njets_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("njets_JetPileUpPtEC1Up",&njets_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("njets_JetPileUpPtEC2Down",&njets_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("njets_JetPileUpPtEC2Up",&njets_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("njets_JetPileUpPtHFDown",&njets_JetPileUpPtHFDown);
    arbre->SetBranchAddress("njets_JetPileUpPtHFUp",&njets_JetPileUpPtHFUp);
    arbre->SetBranchAddress("njets_JetPileUpPtRefDown",&njets_JetPileUpPtRefDown);
    arbre->SetBranchAddress("njets_JetPileUpPtRefUp",&njets_JetPileUpPtRefUp);
    arbre->SetBranchAddress("njets_JetRelativeBalDown",&njets_JetRelativeBalDown);
    arbre->SetBranchAddress("njets_JetRelativeBalUp",&njets_JetRelativeBalUp);
    arbre->SetBranchAddress("njets_JetRelativeFSRDown",&njets_JetRelativeFSRDown);
    arbre->SetBranchAddress("njets_JetRelativeFSRUp",&njets_JetRelativeFSRUp);
    arbre->SetBranchAddress("njets_JetRelativeJEREC1Down",&njets_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("njets_JetRelativeJEREC1Up",&njets_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("njets_JetRelativeJEREC2Down",&njets_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("njets_JetRelativeJEREC2Up",&njets_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("njets_JetRelativeJERHFDown",&njets_JetRelativeJERHFDown);
    arbre->SetBranchAddress("njets_JetRelativeJERHFUp",&njets_JetRelativeJERHFUp);
    arbre->SetBranchAddress("njets_JetRelativePtBBDown",&njets_JetRelativePtBBDown);
    arbre->SetBranchAddress("njets_JetRelativePtBBUp",&njets_JetRelativePtBBUp);
    arbre->SetBranchAddress("njets_JetRelativePtEC1Down",&njets_JetRelativePtEC1Down);
    arbre->SetBranchAddress("njets_JetRelativePtEC1Up",&njets_JetRelativePtEC1Up);
    arbre->SetBranchAddress("njets_JetRelativePtEC2Down",&njets_JetRelativePtEC2Down);
    arbre->SetBranchAddress("njets_JetRelativePtEC2Up",&njets_JetRelativePtEC2Up);
    arbre->SetBranchAddress("njets_JetRelativePtHFDown",&njets_JetRelativePtHFDown);
    arbre->SetBranchAddress("njets_JetRelativePtHFUp",&njets_JetRelativePtHFUp);
    arbre->SetBranchAddress("njets_JetRelativeStatECDown",&njets_JetRelativeStatECDown);
    arbre->SetBranchAddress("njets_JetRelativeStatECUp",&njets_JetRelativeStatECUp);
    arbre->SetBranchAddress("njets_JetRelativeStatFSRDown",&njets_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("njets_JetRelativeStatFSRUp",&njets_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("njets_JetRelativeStatHFDown",&njets_JetRelativeStatHFDown);
    arbre->SetBranchAddress("njets_JetRelativeStatHFUp",&njets_JetRelativeStatHFUp);
    arbre->SetBranchAddress("njets_JetSinglePionECALDown",&njets_JetSinglePionECALDown);
    arbre->SetBranchAddress("njets_JetSinglePionECALUp",&njets_JetSinglePionECALUp);
    arbre->SetBranchAddress("njets_JetSinglePionHCALDown",&njets_JetSinglePionHCALDown);
    arbre->SetBranchAddress("njets_JetSinglePionHCALUp",&njets_JetSinglePionHCALUp);
    arbre->SetBranchAddress("njets_JetTimePtEtaDown",&njets_JetTimePtEtaDown);
    arbre->SetBranchAddress("njets_JetTimePtEtaUp",&njets_JetTimePtEtaUp);

    arbre->SetBranchAddress("mjj_JetAbsoluteFlavMapDown",&mjj_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteFlavMapUp",&mjj_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteMPFBiasDown",&mjj_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteMPFBiasUp",&mjj_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteScaleDown",&mjj_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteScaleUp",&mjj_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteStatDown",&mjj_JetAbsoluteStatDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteStatUp",&mjj_JetAbsoluteStatUp);
    arbre->SetBranchAddress("mjj_JetFlavorQCDDown",&mjj_JetFlavorQCDDown);
    arbre->SetBranchAddress("mjj_JetFlavorQCDUp",&mjj_JetFlavorQCDUp);
    arbre->SetBranchAddress("mjj_JetFragmentationDown",&mjj_JetFragmentationDown);
    arbre->SetBranchAddress("mjj_JetFragmentationUp",&mjj_JetFragmentationUp);
    arbre->SetBranchAddress("mjj_JetPileUpDataMCDown",&mjj_JetPileUpDataMCDown);
    arbre->SetBranchAddress("mjj_JetPileUpDataMCUp",&mjj_JetPileUpDataMCUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtBBDown",&mjj_JetPileUpPtBBDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtBBUp",&mjj_JetPileUpPtBBUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC1Down",&mjj_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC1Up",&mjj_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC2Down",&mjj_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC2Up",&mjj_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("mjj_JetPileUpPtHFDown",&mjj_JetPileUpPtHFDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtHFUp",&mjj_JetPileUpPtHFUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtRefDown",&mjj_JetPileUpPtRefDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtRefUp",&mjj_JetPileUpPtRefUp);
    arbre->SetBranchAddress("mjj_JetRelativeBalDown",&mjj_JetRelativeBalDown);
    arbre->SetBranchAddress("mjj_JetRelativeBalUp",&mjj_JetRelativeBalUp);
    arbre->SetBranchAddress("mjj_JetRelativeFSRDown",&mjj_JetRelativeFSRDown);
    arbre->SetBranchAddress("mjj_JetRelativeFSRUp",&mjj_JetRelativeFSRUp);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC1Down",&mjj_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC1Up",&mjj_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC2Down",&mjj_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC2Up",&mjj_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("mjj_JetRelativeJERHFDown",&mjj_JetRelativeJERHFDown);
    arbre->SetBranchAddress("mjj_JetRelativeJERHFUp",&mjj_JetRelativeJERHFUp);
    arbre->SetBranchAddress("mjj_JetRelativePtBBDown",&mjj_JetRelativePtBBDown);
    arbre->SetBranchAddress("mjj_JetRelativePtBBUp",&mjj_JetRelativePtBBUp);
    arbre->SetBranchAddress("mjj_JetRelativePtEC1Down",&mjj_JetRelativePtEC1Down);
    arbre->SetBranchAddress("mjj_JetRelativePtEC1Up",&mjj_JetRelativePtEC1Up);
    arbre->SetBranchAddress("mjj_JetRelativePtEC2Down",&mjj_JetRelativePtEC2Down);
    arbre->SetBranchAddress("mjj_JetRelativePtEC2Up",&mjj_JetRelativePtEC2Up);
    arbre->SetBranchAddress("mjj_JetRelativePtHFDown",&mjj_JetRelativePtHFDown);
    arbre->SetBranchAddress("mjj_JetRelativePtHFUp",&mjj_JetRelativePtHFUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatECDown",&mjj_JetRelativeStatECDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatECUp",&mjj_JetRelativeStatECUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatFSRDown",&mjj_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatFSRUp",&mjj_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatHFDown",&mjj_JetRelativeStatHFDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatHFUp",&mjj_JetRelativeStatHFUp);
    arbre->SetBranchAddress("mjj_JetSinglePionECALDown",&mjj_JetSinglePionECALDown);
    arbre->SetBranchAddress("mjj_JetSinglePionECALUp",&mjj_JetSinglePionECALUp);
    arbre->SetBranchAddress("mjj_JetSinglePionHCALDown",&mjj_JetSinglePionHCALDown);
    arbre->SetBranchAddress("mjj_JetSinglePionHCALUp",&mjj_JetSinglePionHCALUp);
    arbre->SetBranchAddress("mjj_JetTimePtEtaDown",&mjj_JetTimePtEtaDown);
    arbre->SetBranchAddress("mjj_JetTimePtEtaUp",&mjj_JetTimePtEtaUp);

   float bins0[] = {0,60,65,70,75,80,85,90,95,100,105,110,400};
   //float bins0[] = {0,60,70,80,90,100,110,400};
   float bins1[] = {0,80,90,100,110,120,130,140,150,160,300};
   //float bins2[] = {0,95,115,135,155,400};
   float bins2[] = {0,95,115,155,400};

   float bins_pth[] = {0,100,150,200,250,300,5000};
   //float bins_mjj[] = {300,700,1100,1500,10000};
   float bins_mjj[] = {300,800,1300,10000};
   float pI = TMath::Pi();
   float bins_dphijj[]={-pI, -3, -2.5, -2, -1.5, -1, -0.5, 0 , 0.5, 1, 1.5, 2, 2.5, pI};
   //float bins_dphijj[]={};
 
 /*	for (int ij=0;ij<=64;ij++){

         bins_dphijj[ij]=-3+ij*0.1;
	}
*/
   //float bins_taupt[] = {30,35,40,45,50,55,300};
   //float bins_taupt[] = {30,35,40,300};
   float bins_taupt[] = {0,1,10,11};

   int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;
   int  binnum2 = sizeof(bins2)/sizeof(Float_t) - 1;
   int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
   int  binnum_pth = sizeof(bins_pth)/sizeof(Float_t) - 1;
   int  binnum_taupt = sizeof(bins_taupt)/sizeof(Float_t) - 1;
   int  binnum_mjj = sizeof(bins_mjj)/sizeof(Float_t) - 1;
   int  binnum_dphijj = sizeof(bins_dphijj)/sizeof(Float_t) - 1;

for (int j=0;j<binnum_dphijj+1;j++)cout<<" bins "<<bins_dphijj[j]<<endl;

   TH1F *nlowhigh=new TH1F ("nlowhigh", "nlowhigh", 6,0,6);nlowhigh->Sumw2();

   std::vector<TH1F*> n70;
   std::vector<TH1F*> n70SS;

   std::vector<TH1F*> h0_CR_W;
   std::vector<TH1F*> h0_CR_QCD;
   std::vector<TH1F*> h0_CRSS_W;
   std::vector<TH1F*> h0_CRSS_QCD;
   std::vector<TH1F*> h1_CR_W;
   std::vector<TH1F*> h1_CR_QCD;
   std::vector<TH1F*> h1_CRSS_W;
   std::vector<TH1F*> h1_CRSS_QCD;
   std::vector<TH1F*> h2_CR_W;
   std::vector<TH1F*> h2_CR_QCD;
   std::vector<TH1F*> h2_CRSS_W;
   std::vector<TH1F*> h2_CRSS_QCD;
   
    std::vector<TH2F*> h3a_dphi_OS;
    std::vector<TH2F*> h3b_dphi_OS;
    std::vector<TH2F*> h3c_dphi_OS;
    std::vector<TH2F*> h3d_dphi_OS;
    std::vector<TH2F*> h3e_dphi_OS;
    std::vector<TH2F*> h3f_dphi_OS;
    std::vector<TH2F*> h3g_dphi_OS;
    std::vector<TH2F*> h3h_dphi_OS;
    std::vector<TH2F*> h3i_dphi_OS;
    std::vector<TH2F*> h3j_dphi_OS;
    std::vector<TH2F*> h3k_dphi_OS;
    std::vector<TH2F*> h3l_dphi_OS;
 //   std::vector<TH2F*> h3m_dphi_OS;
 //   std::vector<TH1F*> h3n_dphi_OS;

   std::vector<TH1F*> h3_CR_W;
   std::vector<TH1F*> h3_CR_QCD;
   std::vector<TH1F*> h3_CRSS_W;
   std::vector<TH1F*> h3_CRSS_QCD;
   std::vector<TH1F*> h4_CR_W;
   std::vector<TH1F*> h4_CR_QCD;
   std::vector<TH1F*> h4_CRSS_W;
   std::vector<TH1F*> h4_CRSS_QCD;
   std::vector<TH1F*> h5_CR_W;
   std::vector<TH1F*> h5_CR_QCD;
   std::vector<TH1F*> h5_CRSS_W;
   std::vector<TH1F*> h5_CRSS_QCD;
   std::vector<TH1F*> h6_CR_W;
   std::vector<TH1F*> h6_CR_QCD;
   std::vector<TH1F*> h6_CRSS_W;
   std::vector<TH1F*> h6_CRSS_QCD;
   std::vector<TH1F*> h7_CR_W;
   std::vector<TH1F*> h7_CR_QCD;
   std::vector<TH1F*> h7_CRSS_W;
   std::vector<TH1F*> h7_CRSS_QCD;

   std::vector<TH2F*> h0_OS;
   std::vector<TH2F*> h1_OS;
   std::vector<TH2F*> h2_OS;
   std::vector<TH2F*> h0_SS;
   std::vector<TH2F*> h1_SS;
   std::vector<TH2F*> h2_SS;
   std::vector<TH2F*> h0_QCD;
   std::vector<TH2F*> h1_QCD;
   std::vector<TH2F*> h2_QCD;
   std::vector<TH2F*> h0_WOS;
   std::vector<TH2F*> h1_WOS;
   std::vector<TH2F*> h2_WOS;
   std::vector<TH2F*> h0_WSS;
   std::vector<TH2F*> h1_WSS;
   std::vector<TH2F*> h2_WSS;

   std::vector<TH2F*> h3_OS;
   std::vector<TH2F*> h3_SS;
   std::vector<TH2F*> h3_QCD;
   std::vector<TH2F*> h3_WOS;
   std::vector<TH2F*> h3_WSS;
   std::vector<TH2F*> h4_OS;
   std::vector<TH2F*> h4_SS;
   std::vector<TH2F*> h4_QCD;
   std::vector<TH2F*> h4_WOS;
   std::vector<TH2F*> h4_WSS;
   std::vector<TH2F*> h5_OS;
   std::vector<TH2F*> h5_SS;
   std::vector<TH2F*> h5_QCD;
   std::vector<TH2F*> h5_WOS;
   std::vector<TH2F*> h5_WSS;
   std::vector<TH2F*> h7_OS;
   std::vector<TH2F*> h7_SS;
   std::vector<TH2F*> h7_QCD;
   std::vector<TH2F*> h7_WOS;
   std::vector<TH2F*> h7_WSS;

   std::vector<TH2F*> h33_OS;
   std::vector<TH2F*> h33_SS;
   std::vector<TH2F*> h33_QCD;
   std::vector<TH2F*> h33_WOS;
   std::vector<TH2F*> h33_WSS;
   std::vector<TH2F*> h34_OS;
   std::vector<TH2F*> h34_SS;
   std::vector<TH2F*> h34_QCD;
   std::vector<TH2F*> h34_WOS;
   std::vector<TH2F*> h34_WSS;
   std::vector<TH2F*> h35_OS;
   std::vector<TH2F*> h35_SS;
   std::vector<TH2F*> h35_QCD;
   std::vector<TH2F*> h35_WOS;
   std::vector<TH2F*> h35_WSS;
   std::vector<TH2F*> h37_OS;
   std::vector<TH2F*> h37_SS;
   std::vector<TH2F*> h37_QCD;
   std::vector<TH2F*> h37_WOS;
   std::vector<TH2F*> h37_WSS;

   std::vector<TH2F*> h43_OS;
   std::vector<TH2F*> h43_SS;
   std::vector<TH2F*> h43_QCD;
   std::vector<TH2F*> h43_WOS;
   std::vector<TH2F*> h43_WSS;
   std::vector<TH2F*> h44_OS;
   std::vector<TH2F*> h44_SS;
   std::vector<TH2F*> h44_QCD;
   std::vector<TH2F*> h44_WOS;
   std::vector<TH2F*> h44_WSS;
   std::vector<TH2F*> h45_OS;
   std::vector<TH2F*> h45_SS;
   std::vector<TH2F*> h45_QCD;
   std::vector<TH2F*> h45_WOS;
   std::vector<TH2F*> h45_WSS;
   std::vector<TH2F*> h47_OS;
   std::vector<TH2F*> h47_SS;
   std::vector<TH2F*> h47_QCD;
   std::vector<TH2F*> h47_WOS;
   std::vector<TH2F*> h47_WSS;

   std::vector<TH2F*> h63_OS;
   std::vector<TH2F*> h63_SS;
   std::vector<TH2F*> h63_QCD;
   std::vector<TH2F*> h63_WOS;
   std::vector<TH2F*> h63_WSS;
   std::vector<TH2F*> h64_OS;
   std::vector<TH2F*> h64_SS;
   std::vector<TH2F*> h64_QCD;
   std::vector<TH2F*> h64_WOS;
   std::vector<TH2F*> h64_WSS;
   std::vector<TH2F*> h65_OS;
   std::vector<TH2F*> h65_SS;
   std::vector<TH2F*> h65_QCD;
   std::vector<TH2F*> h65_WOS;
   std::vector<TH2F*> h65_WSS;
   std::vector<TH2F*> h67_OS;
   std::vector<TH2F*> h67_SS;
   std::vector<TH2F*> h67_QCD;
   std::vector<TH2F*> h67_WOS;
   std::vector<TH2F*> h67_WSS;

   std::vector<TH2F*> h53_OS;
   std::vector<TH2F*> h53_SS;
   std::vector<TH2F*> h53_QCD;
   std::vector<TH2F*> h53_WOS;
   std::vector<TH2F*> h53_WSS;
   std::vector<TH2F*> h54_OS;
   std::vector<TH2F*> h54_SS;
   std::vector<TH2F*> h54_QCD;
   std::vector<TH2F*> h54_WOS;
   std::vector<TH2F*> h54_WSS;
   std::vector<TH2F*> h55_OS;
   std::vector<TH2F*> h55_SS;
   std::vector<TH2F*> h55_QCD;
   std::vector<TH2F*> h55_WOS;
   std::vector<TH2F*> h55_WSS;
   std::vector<TH2F*> h57_OS;
   std::vector<TH2F*> h57_SS;
   std::vector<TH2F*> h57_QCD;
   std::vector<TH2F*> h57_WOS;
   std::vector<TH2F*> h57_WSS;

   std::vector<TH2F*> h73_OS;
   std::vector<TH2F*> h73_SS;
   std::vector<TH2F*> h73_QCD;
   std::vector<TH2F*> h73_WOS;
   std::vector<TH2F*> h73_WSS;
   std::vector<TH2F*> h74_OS;
   std::vector<TH2F*> h74_SS;
   std::vector<TH2F*> h74_QCD;
   std::vector<TH2F*> h74_WOS;
   std::vector<TH2F*> h74_WSS;
   std::vector<TH2F*> h75_OS;
   std::vector<TH2F*> h75_SS;
   std::vector<TH2F*> h75_QCD;
   std::vector<TH2F*> h75_WOS;
   std::vector<TH2F*> h75_WSS;
   std::vector<TH2F*> h77_OS;
   std::vector<TH2F*> h77_SS;
   std::vector<TH2F*> h77_QCD;
   std::vector<TH2F*> h77_WOS;
   std::vector<TH2F*> h77_WSS;


   std::vector<TH2F*> h0_ggHOS;
   std::vector<TH2F*> h0_ggHSS;
   std::vector<TH2F*> h0_ggHQCD;
   std::vector<TH2F*> h0_ggHWOS;
   std::vector<TH2F*> h0_ggHWSS;
   std::vector<TH2F*> h1_ggHOS;
   std::vector<TH2F*> h1_ggHSS;
   std::vector<TH2F*> h1_ggHQCD;
   std::vector<TH2F*> h1_ggHWOS;
   std::vector<TH2F*> h1_ggHWSS;
   /*
   std::vector<TH2F*> h2_dPhi_mvOS;
   std::vector<TH2F*> h2_dPhi_mvSS;
   std::vector<TH2F*> h2_dPhi_mvQCD;
   std::vector<TH2F*> h2_dPhi_mvWOS;
   std::vector<TH2F*> h2_dPhi_mvWSS;
   */
   std::vector<TH2F*> h3_ggHOS;
   std::vector<TH2F*> h3_ggHSS;
   std::vector<TH2F*> h3_ggHQCD;
   std::vector<TH2F*> h3_ggHWOS;
   std::vector<TH2F*> h3_ggHWSS;
   std::vector<TH2F*> h4_ggHOS;
   std::vector<TH2F*> h4_ggHSS;
   std::vector<TH2F*> h4_ggHQCD;
   std::vector<TH2F*> h4_ggHWOS;
   std::vector<TH2F*> h4_ggHWSS;
   std::vector<TH2F*> h5_ggHOS;
   std::vector<TH2F*> h5_ggHSS;
   std::vector<TH2F*> h5_ggHQCD;
   std::vector<TH2F*> h5_ggHWOS;
   std::vector<TH2F*> h5_ggHWSS;
   std::vector<TH2F*> h7_ggHOS;
   std::vector<TH2F*> h7_ggHSS;
   std::vector<TH2F*> h7_ggHQCD;
   std::vector<TH2F*> h7_ggHWOS;
   std::vector<TH2F*> h7_ggHWSS;

   std::vector<TH2F*> h33_ggHOS;
   std::vector<TH2F*> h33_ggHSS;
   std::vector<TH2F*> h33_ggHQCD;
   std::vector<TH2F*> h33_ggHWOS;
   std::vector<TH2F*> h33_ggHWSS;
   std::vector<TH2F*> h34_ggHOS;
   std::vector<TH2F*> h34_ggHSS;
   std::vector<TH2F*> h34_ggHQCD;
   std::vector<TH2F*> h34_ggHWOS;
   std::vector<TH2F*> h34_ggHWSS;
   std::vector<TH2F*> h35_ggHOS;
   std::vector<TH2F*> h35_ggHSS;
   std::vector<TH2F*> h35_ggHQCD;
   std::vector<TH2F*> h35_ggHWOS;
   std::vector<TH2F*> h35_ggHWSS;
   std::vector<TH2F*> h37_ggHOS;
   std::vector<TH2F*> h37_ggHSS;
   std::vector<TH2F*> h37_ggHQCD;
   std::vector<TH2F*> h37_ggHWOS;
   std::vector<TH2F*> h37_ggHWSS;

   std::vector<TH2F*> h43_ggHOS;
   std::vector<TH2F*> h43_ggHSS;
   std::vector<TH2F*> h43_ggHQCD;
   std::vector<TH2F*> h43_ggHWOS;
   std::vector<TH2F*> h43_ggHWSS;
   std::vector<TH2F*> h44_ggHOS;
   std::vector<TH2F*> h44_ggHSS;
   std::vector<TH2F*> h44_ggHQCD;
   std::vector<TH2F*> h44_ggHWOS;
   std::vector<TH2F*> h44_ggHWSS;
   std::vector<TH2F*> h45_ggHOS;
   std::vector<TH2F*> h45_ggHSS;
   std::vector<TH2F*> h45_ggHQCD;
   std::vector<TH2F*> h45_ggHWOS;
   std::vector<TH2F*> h45_ggHWSS;
   std::vector<TH2F*> h47_ggHOS;
   std::vector<TH2F*> h47_ggHSS;
   std::vector<TH2F*> h47_ggHQCD;
   std::vector<TH2F*> h47_ggHWOS;
   std::vector<TH2F*> h47_ggHWSS;

   std::vector<TH2F*> h63_ggHOS;
   std::vector<TH2F*> h63_ggHSS;
   std::vector<TH2F*> h63_ggHQCD;
   std::vector<TH2F*> h63_ggHWOS;
   std::vector<TH2F*> h63_ggHWSS;
   std::vector<TH2F*> h64_ggHOS;
   std::vector<TH2F*> h64_ggHSS;
   std::vector<TH2F*> h64_ggHQCD;
   std::vector<TH2F*> h64_ggHWOS;
   std::vector<TH2F*> h64_ggHWSS;
   std::vector<TH2F*> h65_ggHOS;
   std::vector<TH2F*> h65_ggHSS;
   std::vector<TH2F*> h65_ggHQCD;
   std::vector<TH2F*> h65_ggHWOS;
   std::vector<TH2F*> h65_ggHWSS;
   std::vector<TH2F*> h67_ggHOS;
   std::vector<TH2F*> h67_ggHSS;
   std::vector<TH2F*> h67_ggHQCD;
   std::vector<TH2F*> h67_ggHWOS;
   std::vector<TH2F*> h67_ggHWSS;

   std::vector<TH2F*> h53_ggHOS;
   std::vector<TH2F*> h53_ggHSS;
   std::vector<TH2F*> h53_ggHQCD;
   std::vector<TH2F*> h53_ggHWOS;
   std::vector<TH2F*> h53_ggHWSS;
   std::vector<TH2F*> h54_ggHOS;
   std::vector<TH2F*> h54_ggHSS;
   std::vector<TH2F*> h54_ggHQCD;
   std::vector<TH2F*> h54_ggHWOS;
   std::vector<TH2F*> h54_ggHWSS;
   std::vector<TH2F*> h55_ggHOS;
   std::vector<TH2F*> h55_ggHSS;
   std::vector<TH2F*> h55_ggHQCD;
   std::vector<TH2F*> h55_ggHWOS;
   std::vector<TH2F*> h55_ggHWSS;
   std::vector<TH2F*> h57_ggHOS;
   std::vector<TH2F*> h57_ggHSS;
   std::vector<TH2F*> h57_ggHQCD;
   std::vector<TH2F*> h57_ggHWOS;
   std::vector<TH2F*> h57_ggHWSS;


   std::vector<TH1F*> h1D_OS;
   std::vector<TH1F*> h1D_SS;
   std::vector<TH1F*> h1D_QCD;
   std::vector<TH1F*> h1D_WOS;
   std::vector<TH1F*> h1D_WSS;


   std::vector<TH1F*> h1D_jpt1_OS;
   std::vector<TH1F*> h1D_jeta1_OS;
   std::vector<TH1F*> h1D_phi1_OS;
   std::vector<TH1F*> h1D_jpt2_OS;
   std::vector<TH1F*> h1D_jeta2_OS;
   std::vector<TH1F*> h1D_phi2_OS;
   std::vector<TH1F*> h1D_mjj_OS;
   std::vector<TH1F*> h1D_met_OS;


   std::vector<TH1F*> h1D_jpt1_SS;
   std::vector<TH1F*> h1D_jeta1_SS;
   std::vector<TH1F*> h1D_phi1_SS;
   std::vector<TH1F*> h1D_jpt2_SS;
   std::vector<TH1F*> h1D_jeta2_SS;
   std::vector<TH1F*> h1D_phi2_SS;
   std::vector<TH1F*> h1D_mjj_SS;
   std::vector<TH1F*> h1D_met_SS;


   std::vector<TH1F*> h1D_jpt1_WSS;
   std::vector<TH1F*> h1D_jeta1_WSS;
   std::vector<TH1F*> h1D_phi1_WSS;
   std::vector<TH1F*> h1D_jpt2_WSS;
   std::vector<TH1F*> h1D_jeta2_WSS;
   std::vector<TH1F*> h1D_phi2_WSS;
   std::vector<TH1F*> h1D_mjj_WSS;
   std::vector<TH1F*> h1D_met_WSS;


   std::vector<TH1F*> h1D_jpt1_WOS;
   std::vector<TH1F*> h1D_jeta1_WOS;
   std::vector<TH1F*> h1D_phi1_WOS;
   std::vector<TH1F*> h1D_jpt2_WOS;
   std::vector<TH1F*> h1D_jeta2_WOS;
   std::vector<TH1F*> h1D_phi2_WOS;
   std::vector<TH1F*> h1D_mjj_WOS;
   std::vector<TH1F*> h1D_met_WOS;

   std::vector<TH1F*> h1D_jpt1_QCD;
   std::vector<TH1F*> h1D_jeta1_QCD;
   std::vector<TH1F*> h1D_phi1_QCD;
   std::vector<TH1F*> h1D_jpt2_QCD;
   std::vector<TH1F*> h1D_jeta2_QCD;
   std::vector<TH1F*> h1D_phi2_QCD;
   std::vector<TH1F*> h1D_mjj_QCD;
   std::vector<TH1F*> h1D_met_QCD;


   std::vector<TH1F*> hmelaDCP_OS_0jet;
   std::vector<TH1F*> hmelaDCP_SS_0jet;
   std::vector<TH1F*> hmelaDCP_QCD_0jet;
   std::vector<TH1F*> hmelaDCP_WOS_0jet;
   std::vector<TH1F*> hmelaDCP_WSS_0jet;

   std::vector<TH1F*> hmelaDCPggH_OS_0jet;
   std::vector<TH1F*> hmelaDCPggH_SS_0jet;
   std::vector<TH1F*> hmelaDCPggH_QCD_0jet;
   std::vector<TH1F*> hmelaDCPggH_WOS_0jet;
   std::vector<TH1F*> hmelaDCPggH_WSS_0jet;

   std::vector<TH1F*> hmelaD0minusggH_OS_0jet;
   std::vector<TH1F*> hmelaD0minusggH_SS_0jet;
   std::vector<TH1F*> hmelaD0minusggH_QCD_0jet;
   std::vector<TH1F*> hmelaD0minusggH_WOS_0jet;
   std::vector<TH1F*> hmelaD0minusggH_WSS_0jet;

   std::vector<TH1F*> hmelaD0minus_OS_0jet;
   std::vector<TH1F*> hmelaD0minus_SS_0jet;
   std::vector<TH1F*> hmelaD0minus_QCD_0jet;
   std::vector<TH1F*> hmelaD0minus_WOS_0jet;
   std::vector<TH1F*> hmelaD0minus_WSS_0jet;


   std::vector<TH1F*> hmelaDPhijj_OS_0jet;
   std::vector<TH1F*> hmelaDPhijj_SS_0jet;
   std::vector<TH1F*> hmelaDPhijj_QCD_0jet;
   std::vector<TH1F*> hmelaDPhijj_WOS_0jet;
   std::vector<TH1F*> hmelaDPhijj_WSS_0jet;

   std::vector<TH1F*> hmelaDPhiUnsignedjj_OS_0jet;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_SS_0jet;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_QCD_0jet;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_WOS_0jet;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_WSS_0jet;



   std::vector<TH1F*> hmelaDCP_OS_VBF;
   std::vector<TH1F*> hmelaDCP_SS_VBF;
   std::vector<TH1F*> hmelaDCP_QCD_VBF;
   std::vector<TH1F*> hmelaDCP_WOS_VBF;
   std::vector<TH1F*> hmelaDCP_WSS_VBF;

   std::vector<TH1F*> hmelaDCPggH_OS_VBF;
   std::vector<TH1F*> hmelaDCPggH_SS_VBF;
   std::vector<TH1F*> hmelaDCPggH_QCD_VBF;
   std::vector<TH1F*> hmelaDCPggH_WOS_VBF;
   std::vector<TH1F*> hmelaDCPggH_WSS_VBF;

   std::vector<TH1F*> hmelaD0minusggH_OS_VBF;
   std::vector<TH1F*> hmelaD0minusggH_SS_VBF;
   std::vector<TH1F*> hmelaD0minusggH_QCD_VBF;
   std::vector<TH1F*> hmelaD0minusggH_WOS_VBF;
   std::vector<TH1F*> hmelaD0minusggH_WSS_VBF;

   std::vector<TH1F*> hmelaD0minus_OS_VBF;
   std::vector<TH1F*> hmelaD0minus_SS_VBF;
   std::vector<TH1F*> hmelaD0minus_QCD_VBF;
   std::vector<TH1F*> hmelaD0minus_WOS_VBF;
   std::vector<TH1F*> hmelaD0minus_WSS_VBF;


   std::vector<TH1F*> hmelaDPhijj_OS_VBF;
   std::vector<TH1F*> hmelaDPhijj_SS_VBF;
   std::vector<TH1F*> hmelaDPhijj_QCD_VBF;
   std::vector<TH1F*> hmelaDPhijj_WOS_VBF;
   std::vector<TH1F*> hmelaDPhijj_WSS_VBF;

   std::vector<TH1F*> hmelaDPhiUnsignedjj_OS_VBF;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_SS_VBF;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_QCD_VBF;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_WOS_VBF;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_WSS_VBF;


   std::vector<TH1F*> hmelaDCP_OS_boosted;
   std::vector<TH1F*> hmelaDCP_SS_boosted;
   std::vector<TH1F*> hmelaDCP_QCD_boosted;
   std::vector<TH1F*> hmelaDCP_WOS_boosted;
   std::vector<TH1F*> hmelaDCP_WSS_boosted;

   std::vector<TH1F*> hmelaDCPggH_OS_boosted;
   std::vector<TH1F*> hmelaDCPggH_SS_boosted;
   std::vector<TH1F*> hmelaDCPggH_QCD_boosted;
   std::vector<TH1F*> hmelaDCPggH_WOS_boosted;
   std::vector<TH1F*> hmelaDCPggH_WSS_boosted;

   std::vector<TH1F*> hmelaD0minusggH_OS_boosted;
   std::vector<TH1F*> hmelaD0minusggH_SS_boosted;
   std::vector<TH1F*> hmelaD0minusggH_QCD_boosted;
   std::vector<TH1F*> hmelaD0minusggH_WOS_boosted;
   std::vector<TH1F*> hmelaD0minusggH_WSS_boosted;

   std::vector<TH1F*> hmelaD0minus_OS_boosted;
   std::vector<TH1F*> hmelaD0minus_SS_boosted;
   std::vector<TH1F*> hmelaD0minus_QCD_boosted;
   std::vector<TH1F*> hmelaD0minus_WOS_boosted;
   std::vector<TH1F*> hmelaD0minus_WSS_boosted;


   std::vector<TH1F*> hmelaDPhijj_OS_boosted;
   std::vector<TH1F*> hmelaDPhijj_SS_boosted;
   std::vector<TH1F*> hmelaDPhijj_QCD_boosted;
   std::vector<TH1F*> hmelaDPhijj_WOS_boosted;
   std::vector<TH1F*> hmelaDPhijj_WSS_boosted;

   std::vector<TH1F*> hmelaDPhiUnsignedjj_OS_boosted;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_SS_boosted;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_QCD_boosted;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_WOS_boosted;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_WSS_boosted;



   int nbhist=1;
   if (tes==100) nbhist=56;
   if (tes==1) nbhist=12;
   if (tes==16) nbhist=6;// Tau DM uncert
   if (tes==17) nbhist=10;// ZL shape
   if (tes==18) nbhist=4;

   for (int k=0; k<nbhist; ++k){
        ostringstream HNn70; HNn70 << "n70" << k;
        ostringstream HNn70SS; HNn70SS << "n70SS" << k;
        n70.push_back(new TH1F (HNn70.str().c_str(),"InvMa",18,0,18)); n70[k]->Sumw2();
        n70SS.push_back(new TH1F (HNn70SS.str().c_str(),"InvMa",18,0,18)); n70SS[k]->Sumw2();

        ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
        ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
        ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
        ostringstream HNS3OS; HNS3OS << "h3_OS" << k;
        ostringstream HNS4OS; HNS4OS << "h4_OS" << k;
        ostringstream HNS5OS; HNS5OS << "h5_OS" << k;
        ostringstream HNS7OS; HNS7OS << "h7_OS" << k;
        h0_OS.push_back(new TH2F (HNS0OS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_OS[k]->Sumw2();
        h1_OS.push_back(new TH2F (HNS1OS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_OS[k]->Sumw2();
        h2_OS.push_back(new TH2F (HNS2OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_OS[k]->Sumw2();
        h3_OS.push_back(new TH2F (HNS3OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_OS[k]->Sumw2();
        h4_OS.push_back(new TH2F (HNS4OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_OS[k]->Sumw2();
        h5_OS.push_back(new TH2F (HNS5OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_OS[k]->Sumw2();
        h7_OS.push_back(new TH2F (HNS7OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_OS[k]->Sumw2();

        ostringstream HNS33OS; HNS33OS << "h33_OS" << k;
        ostringstream HNS34OS; HNS34OS << "h34_OS" << k;
        ostringstream HNS35OS; HNS35OS << "h35_OS" << k;
        ostringstream HNS37OS; HNS37OS << "h37_OS" << k;
        h33_OS.push_back(new TH2F (HNS33OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_OS[k]->Sumw2();
        h34_OS.push_back(new TH2F (HNS34OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_OS[k]->Sumw2();
        h35_OS.push_back(new TH2F (HNS35OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_OS[k]->Sumw2();
        h37_OS.push_back(new TH2F (HNS37OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_OS[k]->Sumw2();

        ostringstream HNS43OS; HNS43OS << "h43_OS" << k;
        ostringstream HNS44OS; HNS44OS << "h44_OS" << k;
        ostringstream HNS45OS; HNS45OS << "h45_OS" << k;
        ostringstream HNS47OS; HNS47OS << "h47_OS" << k;
        h43_OS.push_back(new TH2F (HNS43OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_OS[k]->Sumw2();
        h44_OS.push_back(new TH2F (HNS44OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_OS[k]->Sumw2();
        h45_OS.push_back(new TH2F (HNS45OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_OS[k]->Sumw2();
        h47_OS.push_back(new TH2F (HNS47OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_OS[k]->Sumw2();

        ostringstream HNS53OS; HNS53OS << "h53_OS" << k;
        ostringstream HNS54OS; HNS54OS << "h54_OS" << k;
        ostringstream HNS55OS; HNS55OS << "h55_OS" << k;
        ostringstream HNS57OS; HNS57OS << "h57_OS" << k;
        h53_OS.push_back(new TH2F (HNS53OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_OS[k]->Sumw2();
        h54_OS.push_back(new TH2F (HNS54OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_OS[k]->Sumw2();
        h55_OS.push_back(new TH2F (HNS55OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_OS[k]->Sumw2();
        h57_OS.push_back(new TH2F (HNS57OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_OS[k]->Sumw2();

        ostringstream HNS63OS; HNS63OS << "h63_OS" << k;
        ostringstream HNS64OS; HNS64OS << "h64_OS" << k;
        ostringstream HNS65OS; HNS65OS << "h65_OS" << k;
        ostringstream HNS67OS; HNS67OS << "h67_OS" << k;
        h63_OS.push_back(new TH2F (HNS63OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_OS[k]->Sumw2();
        h64_OS.push_back(new TH2F (HNS64OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_OS[k]->Sumw2();
        h65_OS.push_back(new TH2F (HNS65OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_OS[k]->Sumw2();
        h67_OS.push_back(new TH2F (HNS67OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_OS[k]->Sumw2();

        ostringstream HNS73OS; HNS73OS << "h73_OS" << k;
        ostringstream HNS74OS; HNS74OS << "h74_OS" << k;
        ostringstream HNS75OS; HNS75OS << "h75_OS" << k;
        ostringstream HNS77OS; HNS77OS << "h77_OS" << k;
        h73_OS.push_back(new TH2F (HNS73OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_OS[k]->Sumw2();
        h74_OS.push_back(new TH2F (HNS74OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h74_OS[k]->Sumw2();
        h75_OS.push_back(new TH2F (HNS75OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h75_OS[k]->Sumw2();
        h77_OS.push_back(new TH2F (HNS77OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h77_OS[k]->Sumw2();

        ostringstream HNS0SS; HNS0SS << "h0_SS" << k;
        ostringstream HNS1SS; HNS1SS << "h1_SS" << k;
        ostringstream HNS2SS; HNS2SS << "h2_SS" << k;
        ostringstream HNS3SS; HNS3SS << "h3_SS" << k;
        ostringstream HNS4SS; HNS4SS << "h4_SS" << k;
        ostringstream HNS5SS; HNS5SS << "h5_SS" << k;
        ostringstream HNS7SS; HNS7SS << "h7_SS" << k;
        h0_SS.push_back(new TH2F (HNS0SS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_SS[k]->Sumw2();
        h1_SS.push_back(new TH2F (HNS1SS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_SS[k]->Sumw2();
        h2_SS.push_back(new TH2F (HNS2SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_SS[k]->Sumw2();
        h3_SS.push_back(new TH2F (HNS3SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_SS[k]->Sumw2();
        h4_SS.push_back(new TH2F (HNS4SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_SS[k]->Sumw2();
        h5_SS.push_back(new TH2F (HNS5SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_SS[k]->Sumw2();
        h7_SS.push_back(new TH2F (HNS7SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_SS[k]->Sumw2();

        ostringstream HNS33SS; HNS33SS << "h33_SS" << k;
        ostringstream HNS34SS; HNS34SS << "h34_SS" << k;
        ostringstream HNS35SS; HNS35SS << "h35_SS" << k;
        ostringstream HNS37SS; HNS37SS << "h37_SS" << k;
        h33_SS.push_back(new TH2F (HNS33SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_SS[k]->Sumw2();
        h34_SS.push_back(new TH2F (HNS34SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_SS[k]->Sumw2();
        h35_SS.push_back(new TH2F (HNS35SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_SS[k]->Sumw2();
        h37_SS.push_back(new TH2F (HNS37SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_SS[k]->Sumw2();

        ostringstream HNS43SS; HNS43SS << "h43_SS" << k;
        ostringstream HNS44SS; HNS44SS << "h44_SS" << k;
        ostringstream HNS45SS; HNS45SS << "h45_SS" << k;
        ostringstream HNS47SS; HNS47SS << "h47_SS" << k;
        h43_SS.push_back(new TH2F (HNS43SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_SS[k]->Sumw2();
        h44_SS.push_back(new TH2F (HNS44SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_SS[k]->Sumw2();
        h45_SS.push_back(new TH2F (HNS45SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_SS[k]->Sumw2();
        h47_SS.push_back(new TH2F (HNS47SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_SS[k]->Sumw2();

        ostringstream HNS53SS; HNS53SS << "h53_SS" << k;
        ostringstream HNS54SS; HNS54SS << "h54_SS" << k;
        ostringstream HNS55SS; HNS55SS << "h55_SS" << k;
        ostringstream HNS57SS; HNS57SS << "h57_SS" << k;
        h53_SS.push_back(new TH2F (HNS53SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_SS[k]->Sumw2();
        h54_SS.push_back(new TH2F (HNS54SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_SS[k]->Sumw2();
        h55_SS.push_back(new TH2F (HNS55SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_SS[k]->Sumw2();
        h57_SS.push_back(new TH2F (HNS57SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_SS[k]->Sumw2();

        ostringstream HNS63SS; HNS63SS << "h63_SS" << k;
        ostringstream HNS64SS; HNS64SS << "h64_SS" << k;
        ostringstream HNS65SS; HNS65SS << "h65_SS" << k;
        ostringstream HNS67SS; HNS67SS << "h67_SS" << k;
        h63_SS.push_back(new TH2F (HNS63SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_SS[k]->Sumw2();
        h64_SS.push_back(new TH2F (HNS64SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_SS[k]->Sumw2();
        h65_SS.push_back(new TH2F (HNS65SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_SS[k]->Sumw2();
        h67_SS.push_back(new TH2F (HNS67SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_SS[k]->Sumw2();

        ostringstream HNS73SS; HNS73SS << "h73_SS" << k;
        ostringstream HNS74SS; HNS74SS << "h74_SS" << k;
        ostringstream HNS75SS; HNS75SS << "h75_SS" << k;
        ostringstream HNS77SS; HNS77SS << "h77_SS" << k;
        h73_SS.push_back(new TH2F (HNS73SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_SS[k]->Sumw2();
        h74_SS.push_back(new TH2F (HNS74SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h74_SS[k]->Sumw2();
        h75_SS.push_back(new TH2F (HNS75SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h75_SS[k]->Sumw2();
        h77_SS.push_back(new TH2F (HNS77SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h77_SS[k]->Sumw2();

        ostringstream HNS0QCD; HNS0QCD << "h0_QCD" << k;
        ostringstream HNS1QCD; HNS1QCD << "h1_QCD" << k;
        ostringstream HNS2QCD; HNS2QCD << "h2_QCD" << k;
        ostringstream HNS3QCD; HNS3QCD << "h3_QCD" << k;
        ostringstream HNS4QCD; HNS4QCD << "h4_QCD" << k;
        ostringstream HNS5QCD; HNS5QCD << "h5_QCD" << k;
        ostringstream HNS7QCD; HNS7QCD << "h7_QCD" << k;
        h0_QCD.push_back(new TH2F (HNS0QCD.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_QCD[k]->Sumw2();
        h1_QCD.push_back(new TH2F (HNS1QCD.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_QCD[k]->Sumw2();
        h2_QCD.push_back(new TH2F (HNS2QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_QCD[k]->Sumw2();
        h3_QCD.push_back(new TH2F (HNS3QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_QCD[k]->Sumw2();
        h4_QCD.push_back(new TH2F (HNS4QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_QCD[k]->Sumw2();
        h5_QCD.push_back(new TH2F (HNS5QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_QCD[k]->Sumw2();
        h7_QCD.push_back(new TH2F (HNS7QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_QCD[k]->Sumw2();

        ostringstream HNS33QCD; HNS33QCD << "h33_QCD" << k;
        ostringstream HNS34QCD; HNS34QCD << "h34_QCD" << k;
        ostringstream HNS35QCD; HNS35QCD << "h35_QCD" << k;
        ostringstream HNS37QCD; HNS37QCD << "h37_QCD" << k;
        h33_QCD.push_back(new TH2F (HNS33QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_QCD[k]->Sumw2();
        h34_QCD.push_back(new TH2F (HNS34QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_QCD[k]->Sumw2();
        h35_QCD.push_back(new TH2F (HNS35QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_QCD[k]->Sumw2();
        h37_QCD.push_back(new TH2F (HNS37QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_QCD[k]->Sumw2();

        ostringstream HNS43QCD; HNS43QCD << "h43_QCD" << k;
        ostringstream HNS44QCD; HNS44QCD << "h44_QCD" << k;
        ostringstream HNS45QCD; HNS45QCD << "h45_QCD" << k;
        ostringstream HNS47QCD; HNS47QCD << "h47_QCD" << k;
        h43_QCD.push_back(new TH2F (HNS43QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_QCD[k]->Sumw2();
        h44_QCD.push_back(new TH2F (HNS44QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_QCD[k]->Sumw2();
        h45_QCD.push_back(new TH2F (HNS45QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_QCD[k]->Sumw2();
        h47_QCD.push_back(new TH2F (HNS47QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_QCD[k]->Sumw2();

        ostringstream HNS53QCD; HNS53QCD << "h53_QCD" << k;
        ostringstream HNS54QCD; HNS54QCD << "h54_QCD" << k;
        ostringstream HNS55QCD; HNS55QCD << "h55_QCD" << k;
        ostringstream HNS57QCD; HNS57QCD << "h57_QCD" << k;
        h53_QCD.push_back(new TH2F (HNS53QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_QCD[k]->Sumw2();
        h54_QCD.push_back(new TH2F (HNS54QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_QCD[k]->Sumw2();
        h55_QCD.push_back(new TH2F (HNS55QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_QCD[k]->Sumw2();
        h57_QCD.push_back(new TH2F (HNS57QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_QCD[k]->Sumw2();

        ostringstream HNS63QCD; HNS63QCD << "h63_QCD" << k;
        ostringstream HNS64QCD; HNS64QCD << "h64_QCD" << k;
        ostringstream HNS65QCD; HNS65QCD << "h65_QCD" << k;
        ostringstream HNS67QCD; HNS67QCD << "h67_QCD" << k;
        h63_QCD.push_back(new TH2F (HNS63QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_QCD[k]->Sumw2();
        h64_QCD.push_back(new TH2F (HNS64QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_QCD[k]->Sumw2();
        h65_QCD.push_back(new TH2F (HNS65QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_QCD[k]->Sumw2();
        h67_QCD.push_back(new TH2F (HNS67QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_QCD[k]->Sumw2();

        ostringstream HNS73QCD; HNS73QCD << "h73_QCD" << k;
        ostringstream HNS74QCD; HNS74QCD << "h74_QCD" << k;
        ostringstream HNS75QCD; HNS75QCD << "h75_QCD" << k;
        ostringstream HNS77QCD; HNS77QCD << "h77_QCD" << k;
        h73_QCD.push_back(new TH2F (HNS73QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_QCD[k]->Sumw2();
        h74_QCD.push_back(new TH2F (HNS74QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h74_QCD[k]->Sumw2();
        h75_QCD.push_back(new TH2F (HNS75QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h75_QCD[k]->Sumw2();
        h77_QCD.push_back(new TH2F (HNS77QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h77_QCD[k]->Sumw2();

        ostringstream HNS0WSS; HNS0WSS << "h0_WSS" << k;
        ostringstream HNS1WSS; HNS1WSS << "h1_WSS" << k;
        ostringstream HNS2WSS; HNS2WSS << "h2_WSS" << k;
        ostringstream HNS3WSS; HNS3WSS << "h3_WSS" << k;
        ostringstream HNS4WSS; HNS4WSS << "h4_WSS" << k;
        ostringstream HNS5WSS; HNS5WSS << "h5_WSS" << k;
        ostringstream HNS7WSS; HNS7WSS << "h7_WSS" << k;
        h0_WSS.push_back(new TH2F (HNS0WSS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_WSS[k]->Sumw2();
        h1_WSS.push_back(new TH2F (HNS1WSS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1));h1_WSS[k]->Sumw2();
        h2_WSS.push_back(new TH2F (HNS2WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h2_WSS[k]->Sumw2();
        h3_WSS.push_back(new TH2F (HNS3WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h3_WSS[k]->Sumw2();
        h4_WSS.push_back(new TH2F (HNS4WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h4_WSS[k]->Sumw2();
        h5_WSS.push_back(new TH2F (HNS5WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h5_WSS[k]->Sumw2();
        h7_WSS.push_back(new TH2F (HNS7WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h7_WSS[k]->Sumw2();

        ostringstream HNS33WSS; HNS33WSS << "h33_WSS" << k;
        ostringstream HNS34WSS; HNS34WSS << "h34_WSS" << k;
        ostringstream HNS35WSS; HNS35WSS << "h35_WSS" << k;
        ostringstream HNS37WSS; HNS37WSS << "h37_WSS" << k;
        h33_WSS.push_back(new TH2F (HNS33WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h33_WSS[k]->Sumw2();
        h34_WSS.push_back(new TH2F (HNS34WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h34_WSS[k]->Sumw2();
        h35_WSS.push_back(new TH2F (HNS35WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h35_WSS[k]->Sumw2();
        h37_WSS.push_back(new TH2F (HNS37WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h37_WSS[k]->Sumw2();

        ostringstream HNS43WSS; HNS43WSS << "h43_WSS" << k;
        ostringstream HNS44WSS; HNS44WSS << "h44_WSS" << k;
        ostringstream HNS45WSS; HNS45WSS << "h45_WSS" << k;
        ostringstream HNS47WSS; HNS47WSS << "h47_WSS" << k;
        h43_WSS.push_back(new TH2F (HNS43WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h43_WSS[k]->Sumw2();
        h44_WSS.push_back(new TH2F (HNS44WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h44_WSS[k]->Sumw2();
        h45_WSS.push_back(new TH2F (HNS45WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h45_WSS[k]->Sumw2();
        h47_WSS.push_back(new TH2F (HNS47WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h47_WSS[k]->Sumw2();

        ostringstream HNS53WSS; HNS53WSS << "h53_WSS" << k;
        ostringstream HNS54WSS; HNS54WSS << "h54_WSS" << k;
        ostringstream HNS55WSS; HNS55WSS << "h55_WSS" << k;
        ostringstream HNS57WSS; HNS57WSS << "h57_WSS" << k;
        h53_WSS.push_back(new TH2F (HNS53WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h53_WSS[k]->Sumw2();
        h54_WSS.push_back(new TH2F (HNS54WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h54_WSS[k]->Sumw2();
        h55_WSS.push_back(new TH2F (HNS55WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h55_WSS[k]->Sumw2();
        h57_WSS.push_back(new TH2F (HNS57WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h57_WSS[k]->Sumw2();

        ostringstream HNS63WSS; HNS63WSS << "h63_WSS" << k;
        ostringstream HNS64WSS; HNS64WSS << "h64_WSS" << k;
        ostringstream HNS65WSS; HNS65WSS << "h65_WSS" << k;
        ostringstream HNS67WSS; HNS67WSS << "h67_WSS" << k;
        h63_WSS.push_back(new TH2F (HNS63WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h63_WSS[k]->Sumw2();
        h64_WSS.push_back(new TH2F (HNS64WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h64_WSS[k]->Sumw2();
        h65_WSS.push_back(new TH2F (HNS65WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h65_WSS[k]->Sumw2();
        h67_WSS.push_back(new TH2F (HNS67WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h67_WSS[k]->Sumw2();

        ostringstream HNS73WSS; HNS73WSS << "h73_WSS" << k;
        ostringstream HNS74WSS; HNS74WSS << "h74_WSS" << k;
        ostringstream HNS75WSS; HNS75WSS << "h75_WSS" << k;
        ostringstream HNS77WSS; HNS77WSS << "h77_WSS" << k;
        h73_WSS.push_back(new TH2F (HNS73WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h73_WSS[k]->Sumw2();
        h74_WSS.push_back(new TH2F (HNS74WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h74_WSS[k]->Sumw2();
        h75_WSS.push_back(new TH2F (HNS75WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h75_WSS[k]->Sumw2();
        h77_WSS.push_back(new TH2F (HNS77WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h77_WSS[k]->Sumw2();

        ostringstream HNS0WOS; HNS0WOS << "h0_WOS" << k;
        ostringstream HNS1WOS; HNS1WOS << "h1_WOS" << k;
        ostringstream HNS2WOS; HNS2WOS << "h2_WOS" << k;
        ostringstream HNS3WOS; HNS3WOS << "h3_WOS" << k;
        ostringstream HNS4WOS; HNS4WOS << "h4_WOS" << k;
        ostringstream HNS5WOS; HNS5WOS << "h5_WOS" << k;
        ostringstream HNS7WOS; HNS7WOS << "h7_WOS" << k;
        h0_WOS.push_back(new TH2F (HNS0WOS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_WOS[k]->Sumw2();
        h1_WOS.push_back(new TH2F (HNS1WOS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_WOS[k]->Sumw2();
        h2_WOS.push_back(new TH2F (HNS2WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_WOS[k]->Sumw2();
        h3_WOS.push_back(new TH2F (HNS3WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_WOS[k]->Sumw2();
        h4_WOS.push_back(new TH2F (HNS4WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_WOS[k]->Sumw2();
        h5_WOS.push_back(new TH2F (HNS5WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_WOS[k]->Sumw2();
        h7_WOS.push_back(new TH2F (HNS7WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_WOS[k]->Sumw2();

        ostringstream HNS33WOS; HNS33WOS << "h33_WOS" << k;
        ostringstream HNS34WOS; HNS34WOS << "h34_WOS" << k;
        ostringstream HNS35WOS; HNS35WOS << "h35_WOS" << k;
        ostringstream HNS37WOS; HNS37WOS << "h37_WOS" << k;
        h33_WOS.push_back(new TH2F (HNS33WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_WOS[k]->Sumw2();
        h34_WOS.push_back(new TH2F (HNS34WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_WOS[k]->Sumw2();
        h35_WOS.push_back(new TH2F (HNS35WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_WOS[k]->Sumw2();
        h37_WOS.push_back(new TH2F (HNS37WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_WOS[k]->Sumw2();

        ostringstream HNS43WOS; HNS43WOS << "h43_WOS" << k;
        ostringstream HNS44WOS; HNS44WOS << "h44_WOS" << k;
        ostringstream HNS45WOS; HNS45WOS << "h45_WOS" << k;
        ostringstream HNS47WOS; HNS47WOS << "h47_WOS" << k;
        h43_WOS.push_back(new TH2F (HNS43WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_WOS[k]->Sumw2();
        h44_WOS.push_back(new TH2F (HNS44WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_WOS[k]->Sumw2();
        h45_WOS.push_back(new TH2F (HNS45WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_WOS[k]->Sumw2();
        h47_WOS.push_back(new TH2F (HNS47WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_WOS[k]->Sumw2();

        ostringstream HNS53WOS; HNS53WOS << "h53_WOS" << k;
        ostringstream HNS54WOS; HNS54WOS << "h54_WOS" << k;
        ostringstream HNS55WOS; HNS55WOS << "h55_WOS" << k;
        ostringstream HNS57WOS; HNS57WOS << "h57_WOS" << k;
        h53_WOS.push_back(new TH2F (HNS53WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_WOS[k]->Sumw2();
        h54_WOS.push_back(new TH2F (HNS54WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_WOS[k]->Sumw2();
        h55_WOS.push_back(new TH2F (HNS55WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_WOS[k]->Sumw2();
        h57_WOS.push_back(new TH2F (HNS57WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_WOS[k]->Sumw2();

        ostringstream HNS63WOS; HNS63WOS << "h63_WOS" << k;
        ostringstream HNS64WOS; HNS64WOS << "h64_WOS" << k;
        ostringstream HNS65WOS; HNS65WOS << "h65_WOS" << k;
        ostringstream HNS67WOS; HNS67WOS << "h67_WOS" << k;
        h63_WOS.push_back(new TH2F (HNS63WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_WOS[k]->Sumw2();
        h64_WOS.push_back(new TH2F (HNS64WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_WOS[k]->Sumw2();
        h65_WOS.push_back(new TH2F (HNS65WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_WOS[k]->Sumw2();
        h67_WOS.push_back(new TH2F (HNS67WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_WOS[k]->Sumw2();

        ostringstream HNS73WOS; HNS73WOS << "h73_WOS" << k;
        ostringstream HNS74WOS; HNS74WOS << "h74_WOS" << k;
        ostringstream HNS75WOS; HNS75WOS << "h75_WOS" << k;
        ostringstream HNS77WOS; HNS77WOS << "h77_WOS" << k;
        h73_WOS.push_back(new TH2F (HNS73WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_WOS[k]->Sumw2();
        h74_WOS.push_back(new TH2F (HNS74WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h74_WOS[k]->Sumw2();
        h75_WOS.push_back(new TH2F (HNS75WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h75_WOS[k]->Sumw2();
        h77_WOS.push_back(new TH2F (HNS77WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h77_WOS[k]->Sumw2();

////////////ggH
        ostringstream HNggHS0OS; HNggHS0OS << "h0_ggHOS" << k;
        ostringstream HNggHS1OS; HNggHS1OS << "h1_ggHOS" << k;
//        ostringstream HNggHS2OS; HNggHS2OS << "h2_dPhi_mvOS" << k;
        ostringstream HNggHS3OS; HNggHS3OS << "h3_ggHOS" << k;
        ostringstream HNggHS4OS; HNggHS4OS << "h4_ggHOS" << k;
        ostringstream HNggHS5OS; HNggHS5OS << "h5_ggHOS" << k;
        ostringstream HNggHS7OS; HNggHS7OS << "h7_ggHOS" << k;
        h0_ggHOS.push_back(new TH2F (HNggHS0OS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_ggHOS[k]->Sumw2();
        h1_ggHOS.push_back(new TH2F (HNggHS1OS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_ggHOS[k]->Sumw2();
  //      h2_dPhi_mvOS.push_back(new TH2F (HNggHS2OS.str().c_str(),"DPhi",binnum_dphijj,bins_dphijj,binnum2,bins2)); h2_dPhi_mvOS[k]->Sumw2();
        h3_ggHOS.push_back(new TH2F (HNggHS3OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_ggHOS[k]->Sumw2();
        h4_ggHOS.push_back(new TH2F (HNggHS4OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_ggHOS[k]->Sumw2();
        h5_ggHOS.push_back(new TH2F (HNggHS5OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_ggHOS[k]->Sumw2();
        h7_ggHOS.push_back(new TH2F (HNggHS7OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_ggHOS[k]->Sumw2();

        ostringstream HNggHS33OS; HNggHS33OS << "h33_ggHOS" << k;
        ostringstream HNggHS34OS; HNggHS34OS << "h34_ggHOS" << k;
        ostringstream HNggHS35OS; HNggHS35OS << "h35_ggHOS" << k;
        ostringstream HNggHS37OS; HNggHS37OS << "h37_ggHOS" << k;
        h33_ggHOS.push_back(new TH2F (HNggHS33OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_ggHOS[k]->Sumw2();
        h34_ggHOS.push_back(new TH2F (HNggHS34OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_ggHOS[k]->Sumw2();
        h35_ggHOS.push_back(new TH2F (HNggHS35OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_ggHOS[k]->Sumw2();
        h37_ggHOS.push_back(new TH2F (HNggHS37OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_ggHOS[k]->Sumw2();

        ostringstream HNggHS43OS; HNggHS43OS << "h43_ggHOS" << k;
        ostringstream HNggHS44OS; HNggHS44OS << "h44_ggHOS" << k;
        ostringstream HNggHS45OS; HNggHS45OS << "h45_ggHOS" << k;
        ostringstream HNggHS47OS; HNggHS47OS << "h47_ggHOS" << k;
        h43_ggHOS.push_back(new TH2F (HNggHS43OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_ggHOS[k]->Sumw2();
        h44_ggHOS.push_back(new TH2F (HNggHS44OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_ggHOS[k]->Sumw2();
        h45_ggHOS.push_back(new TH2F (HNggHS45OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_ggHOS[k]->Sumw2();
        h47_ggHOS.push_back(new TH2F (HNggHS47OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_ggHOS[k]->Sumw2();

        ostringstream HNggHS53OS; HNggHS53OS << "h53_ggHOS" << k;
        ostringstream HNggHS54OS; HNggHS54OS << "h54_ggHOS" << k;
        ostringstream HNggHS55OS; HNggHS55OS << "h55_ggHOS" << k;
        ostringstream HNggHS57OS; HNggHS57OS << "h57_ggHOS" << k;
        h53_ggHOS.push_back(new TH2F (HNggHS53OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_ggHOS[k]->Sumw2();
        h54_ggHOS.push_back(new TH2F (HNggHS54OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_ggHOS[k]->Sumw2();
        h55_ggHOS.push_back(new TH2F (HNggHS55OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_ggHOS[k]->Sumw2();
        h57_ggHOS.push_back(new TH2F (HNggHS57OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_ggHOS[k]->Sumw2();

        ostringstream HNggHS63OS; HNggHS63OS << "h63_ggHOS" << k;
        ostringstream HNggHS64OS; HNggHS64OS << "h64_ggHOS" << k;
        ostringstream HNggHS65OS; HNggHS65OS << "h65_ggHOS" << k;
        ostringstream HNggHS67OS; HNggHS67OS << "h67_ggHOS" << k;
        h63_ggHOS.push_back(new TH2F (HNggHS63OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_ggHOS[k]->Sumw2();
        h64_ggHOS.push_back(new TH2F (HNggHS64OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_ggHOS[k]->Sumw2();
        h65_ggHOS.push_back(new TH2F (HNggHS65OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_ggHOS[k]->Sumw2();
        h67_ggHOS.push_back(new TH2F (HNggHS67OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_ggHOS[k]->Sumw2();


        ostringstream HNggHS0SS; HNggHS0SS << "h0_ggHSS" << k;
        ostringstream HNggHS1SS; HNggHS1SS << "h1_ggHSS" << k;
 //       ostringstream HNggHS2SS; HNggHS2SS << "h2_dPhi_mvSS" << k;
        ostringstream HNggHS3SS; HNggHS3SS << "h3_ggHSS" << k;
        ostringstream HNggHS4SS; HNggHS4SS << "h4_ggHSS" << k;
        ostringstream HNggHS5SS; HNggHS5SS << "h5_ggHSS" << k;
        ostringstream HNggHS7SS; HNggHS7SS << "h7_ggHSS" << k;
        h0_ggHSS.push_back(new TH2F (HNggHS0SS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_ggHSS[k]->Sumw2();
        h1_ggHSS.push_back(new TH2F (HNggHS1SS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_ggHSS[k]->Sumw2();
//        h2_dPhi_mvSS.push_back(new TH2F (HNggHS2SS.str().c_str(),"DPhi",binnum_dphijj,bins_dphijj,binnum2,bins2)); h2_dPhi_mvSS[k]->Sumw2();
        h3_ggHSS.push_back(new TH2F (HNggHS3SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_ggHSS[k]->Sumw2();
        h4_ggHSS.push_back(new TH2F (HNggHS4SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_ggHSS[k]->Sumw2();
        h5_ggHSS.push_back(new TH2F (HNggHS5SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_ggHSS[k]->Sumw2();
        h7_ggHSS.push_back(new TH2F (HNggHS7SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_ggHSS[k]->Sumw2();

        ostringstream HNggHS33SS; HNggHS33SS << "h33_ggHSS" << k;
        ostringstream HNggHS34SS; HNggHS34SS << "h34_ggHSS" << k;
        ostringstream HNggHS35SS; HNggHS35SS << "h35_ggHSS" << k;
        ostringstream HNggHS37SS; HNggHS37SS << "h37_ggHSS" << k;
        h33_ggHSS.push_back(new TH2F (HNggHS33SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_ggHSS[k]->Sumw2();
        h34_ggHSS.push_back(new TH2F (HNggHS34SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_ggHSS[k]->Sumw2();
        h35_ggHSS.push_back(new TH2F (HNggHS35SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_ggHSS[k]->Sumw2();
        h37_ggHSS.push_back(new TH2F (HNggHS37SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_ggHSS[k]->Sumw2();

        ostringstream HNggHS43SS; HNggHS43SS << "h43_ggHSS" << k;
        ostringstream HNggHS44SS; HNggHS44SS << "h44_ggHSS" << k;
        ostringstream HNggHS45SS; HNggHS45SS << "h45_ggHSS" << k;
        ostringstream HNggHS47SS; HNggHS47SS << "h47_ggHSS" << k;
        h43_ggHSS.push_back(new TH2F (HNggHS43SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_ggHSS[k]->Sumw2();
        h44_ggHSS.push_back(new TH2F (HNggHS44SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_ggHSS[k]->Sumw2();
        h45_ggHSS.push_back(new TH2F (HNggHS45SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_ggHSS[k]->Sumw2();
        h47_ggHSS.push_back(new TH2F (HNggHS47SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_ggHSS[k]->Sumw2();

        ostringstream HNggHS53SS; HNggHS53SS << "h53_ggHSS" << k;
        ostringstream HNggHS54SS; HNggHS54SS << "h54_ggHSS" << k;
        ostringstream HNggHS55SS; HNggHS55SS << "h55_ggHSS" << k;
        ostringstream HNggHS57SS; HNggHS57SS << "h57_ggHSS" << k;
        h53_ggHSS.push_back(new TH2F (HNggHS53SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_ggHSS[k]->Sumw2();
        h54_ggHSS.push_back(new TH2F (HNggHS54SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_ggHSS[k]->Sumw2();
        h55_ggHSS.push_back(new TH2F (HNggHS55SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_ggHSS[k]->Sumw2();
        h57_ggHSS.push_back(new TH2F (HNggHS57SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_ggHSS[k]->Sumw2();

        ostringstream HNggHS63SS; HNggHS63SS << "h63_ggHSS" << k;
        ostringstream HNggHS64SS; HNggHS64SS << "h64_ggHSS" << k;
        ostringstream HNggHS65SS; HNggHS65SS << "h65_ggHSS" << k;
        ostringstream HNggHS67SS; HNggHS67SS << "h67_ggHSS" << k;
        h63_ggHSS.push_back(new TH2F (HNggHS63SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_ggHSS[k]->Sumw2();
        h64_ggHSS.push_back(new TH2F (HNggHS64SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_ggHSS[k]->Sumw2();
        h65_ggHSS.push_back(new TH2F (HNggHS65SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_ggHSS[k]->Sumw2();
        h67_ggHSS.push_back(new TH2F (HNggHS67SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_ggHSS[k]->Sumw2();


        ostringstream HNggHS0QCD; HNggHS0QCD << "h0_ggHQCD" << k;
        ostringstream HNggHS1QCD; HNggHS1QCD << "h1_ggHQCD" << k;
//        ostringstream HNggHS2QCD; HNggHS2QCD << "h2_dPhi_mvQCD" << k;
        ostringstream HNggHS3QCD; HNggHS3QCD << "h3_ggHQCD" << k;
        ostringstream HNggHS4QCD; HNggHS4QCD << "h4_ggHQCD" << k;
        ostringstream HNggHS5QCD; HNggHS5QCD << "h5_ggHQCD" << k;
        ostringstream HNggHS7QCD; HNggHS7QCD << "h7_ggHQCD" << k;
        h0_ggHQCD.push_back(new TH2F (HNggHS0QCD.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_ggHQCD[k]->Sumw2();
        h1_ggHQCD.push_back(new TH2F (HNggHS1QCD.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_ggHQCD[k]->Sumw2();
  //      h2_dPhi_mvQCD.push_back(new TH2F (HNggHS2QCD.str().c_str(),"DPhi",binnum_dphijj,bins_dphijj,binnum2,bins2)); h2_dPhi_mvQCD[k]->Sumw2();
        h3_ggHQCD.push_back(new TH2F (HNggHS3QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_ggHQCD[k]->Sumw2();
        h4_ggHQCD.push_back(new TH2F (HNggHS4QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_ggHQCD[k]->Sumw2();
        h5_ggHQCD.push_back(new TH2F (HNggHS5QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_ggHQCD[k]->Sumw2();
        h7_ggHQCD.push_back(new TH2F (HNggHS7QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_ggHQCD[k]->Sumw2();

        ostringstream HNggHS33QCD; HNggHS33QCD << "h33_ggHQCD" << k;
        ostringstream HNggHS34QCD; HNggHS34QCD << "h34_ggHQCD" << k;
        ostringstream HNggHS35QCD; HNggHS35QCD << "h35_ggHQCD" << k;
        ostringstream HNggHS37QCD; HNggHS37QCD << "h37_ggHQCD" << k;
        h33_ggHQCD.push_back(new TH2F (HNggHS33QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_ggHQCD[k]->Sumw2();
        h34_ggHQCD.push_back(new TH2F (HNggHS34QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_ggHQCD[k]->Sumw2();
        h35_ggHQCD.push_back(new TH2F (HNggHS35QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_ggHQCD[k]->Sumw2();
        h37_ggHQCD.push_back(new TH2F (HNggHS37QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_ggHQCD[k]->Sumw2();

        ostringstream HNggHS43QCD; HNggHS43QCD << "h43_ggHQCD" << k;
        ostringstream HNggHS44QCD; HNggHS44QCD << "h44_ggHQCD" << k;
        ostringstream HNggHS45QCD; HNggHS45QCD << "h45_ggHQCD" << k;
        ostringstream HNggHS47QCD; HNggHS47QCD << "h47_ggHQCD" << k;
        h43_ggHQCD.push_back(new TH2F (HNggHS43QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_ggHQCD[k]->Sumw2();
        h44_ggHQCD.push_back(new TH2F (HNggHS44QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_ggHQCD[k]->Sumw2();
        h45_ggHQCD.push_back(new TH2F (HNggHS45QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_ggHQCD[k]->Sumw2();
        h47_ggHQCD.push_back(new TH2F (HNggHS47QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_ggHQCD[k]->Sumw2();

        ostringstream HNggHS53QCD; HNggHS53QCD << "h53_ggHQCD" << k;
        ostringstream HNggHS54QCD; HNggHS54QCD << "h54_ggHQCD" << k;
        ostringstream HNggHS55QCD; HNggHS55QCD << "h55_ggHQCD" << k;
        ostringstream HNggHS57QCD; HNggHS57QCD << "h57_ggHQCD" << k;
        h53_ggHQCD.push_back(new TH2F (HNggHS53QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_ggHQCD[k]->Sumw2();
        h54_ggHQCD.push_back(new TH2F (HNggHS54QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_ggHQCD[k]->Sumw2();
        h55_ggHQCD.push_back(new TH2F (HNggHS55QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_ggHQCD[k]->Sumw2();
        h57_ggHQCD.push_back(new TH2F (HNggHS57QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_ggHQCD[k]->Sumw2();

        ostringstream HNggHS63QCD; HNggHS63QCD << "h63_ggHQCD" << k;
        ostringstream HNggHS64QCD; HNggHS64QCD << "h64_ggHQCD" << k;
        ostringstream HNggHS65QCD; HNggHS65QCD << "h65_ggHQCD" << k;
        ostringstream HNggHS67QCD; HNggHS67QCD << "h67_ggHQCD" << k;
        h63_ggHQCD.push_back(new TH2F (HNggHS63QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_ggHQCD[k]->Sumw2();
        h64_ggHQCD.push_back(new TH2F (HNggHS64QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_ggHQCD[k]->Sumw2();
        h65_ggHQCD.push_back(new TH2F (HNggHS65QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_ggHQCD[k]->Sumw2();
        h67_ggHQCD.push_back(new TH2F (HNggHS67QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_ggHQCD[k]->Sumw2();

        ostringstream HNggHS0WSS; HNggHS0WSS << "h0_ggHWSS" << k;
        ostringstream HNggHS1WSS; HNggHS1WSS << "h1_ggHWSS" << k;
//       ostringstream HNggHS2WSS; HNggHS2WSS << "h2_dPhi_mvWSS" << k;
        ostringstream HNggHS3WSS; HNggHS3WSS << "h3_ggHWSS" << k;
        ostringstream HNggHS4WSS; HNggHS4WSS << "h4_ggHWSS" << k;
        ostringstream HNggHS5WSS; HNggHS5WSS << "h5_ggHWSS" << k;
        ostringstream HNggHS7WSS; HNggHS7WSS << "h7_ggHWSS" << k;
        h0_ggHWSS.push_back(new TH2F (HNggHS0WSS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_ggHWSS[k]->Sumw2();
        h1_ggHWSS.push_back(new TH2F (HNggHS1WSS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1));h1_ggHWSS[k]->Sumw2();
  //      h2_dPhi_mvWSS.push_back(new TH2F (HNggHS2WSS.str().c_str(),"DPhi",binnum_dphijj,bins_dphijj,binnum2,bins2));h2_dPhi_mvWSS[k]->Sumw2();
        h3_ggHWSS.push_back(new TH2F (HNggHS3WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h3_ggHWSS[k]->Sumw2();
        h4_ggHWSS.push_back(new TH2F (HNggHS4WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h4_ggHWSS[k]->Sumw2();
        h5_ggHWSS.push_back(new TH2F (HNggHS5WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h5_ggHWSS[k]->Sumw2();
        h7_ggHWSS.push_back(new TH2F (HNggHS7WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h7_ggHWSS[k]->Sumw2();

        ostringstream HNggHS33WSS; HNggHS33WSS << "h33_ggHWSS" << k;
        ostringstream HNggHS34WSS; HNggHS34WSS << "h34_ggHWSS" << k;
        ostringstream HNggHS35WSS; HNggHS35WSS << "h35_ggHWSS" << k;
        ostringstream HNggHS37WSS; HNggHS37WSS << "h37_ggHWSS" << k;
        h33_ggHWSS.push_back(new TH2F (HNggHS33WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h33_ggHWSS[k]->Sumw2();
        h34_ggHWSS.push_back(new TH2F (HNggHS34WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h34_ggHWSS[k]->Sumw2();
        h35_ggHWSS.push_back(new TH2F (HNggHS35WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h35_ggHWSS[k]->Sumw2();
        h37_ggHWSS.push_back(new TH2F (HNggHS37WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h37_ggHWSS[k]->Sumw2();

        ostringstream HNggHS43WSS; HNggHS43WSS << "h43_ggHWSS" << k;
        ostringstream HNggHS44WSS; HNggHS44WSS << "h44_ggHWSS" << k;
        ostringstream HNggHS45WSS; HNggHS45WSS << "h45_ggHWSS" << k;
        ostringstream HNggHS47WSS; HNggHS47WSS << "h47_ggHWSS" << k;
        h43_ggHWSS.push_back(new TH2F (HNggHS43WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h43_ggHWSS[k]->Sumw2();
        h44_ggHWSS.push_back(new TH2F (HNggHS44WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h44_ggHWSS[k]->Sumw2();
        h45_ggHWSS.push_back(new TH2F (HNggHS45WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h45_ggHWSS[k]->Sumw2();
        h47_ggHWSS.push_back(new TH2F (HNggHS47WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h47_ggHWSS[k]->Sumw2();

        ostringstream HNggHS53WSS; HNggHS53WSS << "h53_ggHWSS" << k;
        ostringstream HNggHS54WSS; HNggHS54WSS << "h54_ggHWSS" << k;
        ostringstream HNggHS55WSS; HNggHS55WSS << "h55_ggHWSS" << k;
        ostringstream HNggHS57WSS; HNggHS57WSS << "h57_ggHWSS" << k;
        h53_ggHWSS.push_back(new TH2F (HNggHS53WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h53_ggHWSS[k]->Sumw2();
        h54_ggHWSS.push_back(new TH2F (HNggHS54WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h54_ggHWSS[k]->Sumw2();
        h55_ggHWSS.push_back(new TH2F (HNggHS55WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h55_ggHWSS[k]->Sumw2();
        h57_ggHWSS.push_back(new TH2F (HNggHS57WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h57_ggHWSS[k]->Sumw2();

        ostringstream HNggHS63WSS; HNggHS63WSS << "h63_ggHWSS" << k;
        ostringstream HNggHS64WSS; HNggHS64WSS << "h64_ggHWSS" << k;
        ostringstream HNggHS65WSS; HNggHS65WSS << "h65_ggHWSS" << k;
        ostringstream HNggHS67WSS; HNggHS67WSS << "h67_ggHWSS" << k;
        h63_ggHWSS.push_back(new TH2F (HNggHS63WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h63_ggHWSS[k]->Sumw2();
        h64_ggHWSS.push_back(new TH2F (HNggHS64WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h64_ggHWSS[k]->Sumw2();
        h65_ggHWSS.push_back(new TH2F (HNggHS65WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h65_ggHWSS[k]->Sumw2();
        h67_ggHWSS.push_back(new TH2F (HNggHS67WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2));h67_ggHWSS[k]->Sumw2();

        ostringstream HNggHS0WOS; HNggHS0WOS << "h0_ggHWOS" << k;
        ostringstream HNggHS1WOS; HNggHS1WOS << "h1_ggHWOS" << k;
//        ostringstream HNggHS2WOS; HNggHS2WOS << "h2_dPhi_mvWOS" << k;
        ostringstream HNggHS3WOS; HNggHS3WOS << "h3_ggHWOS" << k;
        ostringstream HNggHS4WOS; HNggHS4WOS << "h4_ggHWOS" << k;
        ostringstream HNggHS5WOS; HNggHS5WOS << "h5_ggHWOS" << k;
        ostringstream HNggHS7WOS; HNggHS7WOS << "h7_ggHWOS" << k;
        h0_ggHWOS.push_back(new TH2F (HNggHS0WOS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_ggHWOS[k]->Sumw2();
        h1_ggHWOS.push_back(new TH2F (HNggHS1WOS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_ggHWOS[k]->Sumw2();
  //      h2_dPhi_mvWOS.push_back(new TH2F (HNggHS2WOS.str().c_str(),"DPhi",binnum_dphijj,bins_dphijj,binnum2,bins2)); h2_dPhi_mvWOS[k]->Sumw2();
        h3_ggHWOS.push_back(new TH2F (HNggHS3WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h3_ggHWOS[k]->Sumw2();
        h4_ggHWOS.push_back(new TH2F (HNggHS4WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h4_ggHWOS[k]->Sumw2();
        h5_ggHWOS.push_back(new TH2F (HNggHS5WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h5_ggHWOS[k]->Sumw2();
        h7_ggHWOS.push_back(new TH2F (HNggHS7WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h7_ggHWOS[k]->Sumw2();

        ostringstream HNggHS33WOS; HNggHS33WOS << "h33_ggHWOS" << k;
        ostringstream HNggHS34WOS; HNggHS34WOS << "h34_ggHWOS" << k;
        ostringstream HNggHS35WOS; HNggHS35WOS << "h35_ggHWOS" << k;
        ostringstream HNggHS37WOS; HNggHS37WOS << "h37_ggHWOS" << k;
        h33_ggHWOS.push_back(new TH2F (HNggHS33WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_ggHWOS[k]->Sumw2();
        h34_ggHWOS.push_back(new TH2F (HNggHS34WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h34_ggHWOS[k]->Sumw2();
        h35_ggHWOS.push_back(new TH2F (HNggHS35WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h35_ggHWOS[k]->Sumw2();
        h37_ggHWOS.push_back(new TH2F (HNggHS37WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h37_ggHWOS[k]->Sumw2();

        ostringstream HNggHS43WOS; HNggHS43WOS << "h43_ggHWOS" << k;
        ostringstream HNggHS44WOS; HNggHS44WOS << "h44_ggHWOS" << k;
        ostringstream HNggHS45WOS; HNggHS45WOS << "h45_ggHWOS" << k;
        ostringstream HNggHS47WOS; HNggHS47WOS << "h47_ggHWOS" << k;
        h43_ggHWOS.push_back(new TH2F (HNggHS43WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_ggHWOS[k]->Sumw2();
        h44_ggHWOS.push_back(new TH2F (HNggHS44WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h44_ggHWOS[k]->Sumw2();
        h45_ggHWOS.push_back(new TH2F (HNggHS45WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h45_ggHWOS[k]->Sumw2();
        h47_ggHWOS.push_back(new TH2F (HNggHS47WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h47_ggHWOS[k]->Sumw2();

        ostringstream HNggHS53WOS; HNggHS53WOS << "h53_ggHWOS" << k;
        ostringstream HNggHS54WOS; HNggHS54WOS << "h54_ggHWOS" << k;
        ostringstream HNggHS55WOS; HNggHS55WOS << "h55_ggHWOS" << k;
        ostringstream HNggHS57WOS; HNggHS57WOS << "h57_ggHWOS" << k;
        h53_ggHWOS.push_back(new TH2F (HNggHS53WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_ggHWOS[k]->Sumw2();
        h54_ggHWOS.push_back(new TH2F (HNggHS54WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h54_ggHWOS[k]->Sumw2();
        h55_ggHWOS.push_back(new TH2F (HNggHS55WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h55_ggHWOS[k]->Sumw2();
        h57_ggHWOS.push_back(new TH2F (HNggHS57WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h57_ggHWOS[k]->Sumw2();

        ostringstream HNggHS63WOS; HNggHS63WOS << "h63_ggHWOS" << k;
        ostringstream HNggHS64WOS; HNggHS64WOS << "h64_ggHWOS" << k;
        ostringstream HNggHS65WOS; HNggHS65WOS << "h65_ggHWOS" << k;
        ostringstream HNggHS67WOS; HNggHS67WOS << "h67_ggHWOS" << k;
        h63_ggHWOS.push_back(new TH2F (HNggHS63WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_ggHWOS[k]->Sumw2();
        h64_ggHWOS.push_back(new TH2F (HNggHS64WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h64_ggHWOS[k]->Sumw2();
        h65_ggHWOS.push_back(new TH2F (HNggHS65WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h65_ggHWOS[k]->Sumw2();
        h67_ggHWOS.push_back(new TH2F (HNggHS67WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h67_ggHWOS[k]->Sumw2();


///////////dPhi

        h3a_dphi_OS.push_back(new TH2F ("h3a_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3a_dphi_OS[k]->Sumw2();
        h3b_dphi_OS.push_back(new TH2F ("h3b_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3b_dphi_OS[k]->Sumw2();
        h3c_dphi_OS.push_back(new TH2F ("h3c_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3c_dphi_OS[k]->Sumw2();
        h3d_dphi_OS.push_back(new TH2F ("h3d_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3d_dphi_OS[k]->Sumw2();
        h3e_dphi_OS.push_back(new TH2F ("h3e_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3e_dphi_OS[k]->Sumw2();
        h3f_dphi_OS.push_back(new TH2F ("h3f_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3f_dphi_OS[k]->Sumw2();
        h3g_dphi_OS.push_back(new TH2F ("h3g_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3g_dphi_OS[k]->Sumw2();
        h3h_dphi_OS.push_back(new TH2F ("h3h_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3h_dphi_OS[k]->Sumw2();
        h3i_dphi_OS.push_back(new TH2F ("h3i_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3i_dphi_OS[k]->Sumw2();
        h3j_dphi_OS.push_back(new TH2F ("h3j_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3j_dphi_OS[k]->Sumw2();
        h3k_dphi_OS.push_back(new TH2F ("h3k_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3k_dphi_OS[k]->Sumw2();
        h3l_dphi_OS.push_back(new TH2F ("h3l_dphi_OS","dPhijj",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3l_dphi_OS[k]->Sumw2();
        //h3m_dphi_OS.push_back(new TH2F ("h3m_dphi_OS","InvMa",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3m_dphi_OS[k]->Sumw2();
//        h3n_dphi_OS.push_back(new TH2F ("h3n_dphi_OS","InvMa",binnum_dphijj,bins_dphijj,binnum0,bins0)); h3n_dphi_OS[k]->Sumw2();


   }

   for (int k=0; k<nbhist; ++k){
//booking histos
        hmelaDCP_OS_0jet.push_back(new TH1F ("hmelaDCP_OS_0jet","DCP",10,0,1)); hmelaDCP_OS_0jet[k]->Sumw2();
        hmelaDCPggH_OS_0jet.push_back(new TH1F ("hmelaDCPggH_OS_0jet","DCPggH",10,0,1)); hmelaDCPggH_OS_0jet[k]->Sumw2();
        hmelaD0minusggH_OS_0jet.push_back(new TH1F ("hmelaD0minusggH_OS_0jet","D0minusggH",10,0,1)); hmelaD0minusggH_OS_0jet[k]->Sumw2();
        hmelaD0minus_OS_0jet.push_back(new TH1F ("hmelaD0minus_OS_0jet","D0minus",10,0,1)); hmelaD0minus_OS_0jet[k]->Sumw2();
        hmelaDPhijj_OS_0jet.push_back(new TH1F ("hmelaDPhijj_OS_0jet","DPhijj",64,-3.2,3.2)); hmelaDPhijj_OS_0jet[k]->Sumw2();
        hmelaDPhiUnsignedjj_OS_0jet.push_back(new TH1F ("hmelaDPhiUnsignedjj_OS_0jet","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_OS_0jet[k]->Sumw2();

        hmelaDCP_OS_VBF.push_back(new TH1F ("hmelaDCP_OS_VBF","DCP",10,0,1)); hmelaDCP_OS_VBF[k]->Sumw2();
        hmelaDCPggH_OS_VBF.push_back(new TH1F ("hmelaDCPggH_OS_VBF","DCPggH",10,0,1)); hmelaDCPggH_OS_VBF[k]->Sumw2();
        hmelaD0minusggH_OS_VBF.push_back(new TH1F ("hmelaD0minusggH_OS_VBF","D0minusggH",10,0,1)); hmelaD0minusggH_OS_VBF[k]->Sumw2();
        hmelaD0minus_OS_VBF.push_back(new TH1F ("hmelaD0minus_OS_VBF","D0minus",10,0,1)); hmelaD0minus_OS_VBF[k]->Sumw2();
        hmelaDPhijj_OS_VBF.push_back(new TH1F ("hmelaDPhijj_OS_VBF","DPhijj",64,-3.2,3.2)); hmelaDPhijj_OS_VBF[k]->Sumw2();
        hmelaDPhiUnsignedjj_OS_VBF.push_back(new TH1F ("hmelaDPhiUnsignedjj_OS_VBF","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_OS_VBF[k]->Sumw2();


        hmelaDCP_OS_boosted.push_back(new TH1F ("hmelaDCP_OS_boosted","DCP",10,0,1)); hmelaDCP_OS_boosted[k]->Sumw2();
        hmelaDCPggH_OS_boosted.push_back(new TH1F ("hmelaDCPggH_OS_boosted","DCPggH",10,0,1)); hmelaDCPggH_OS_boosted[k]->Sumw2();
        hmelaD0minusggH_OS_boosted.push_back(new TH1F ("hmelaD0minusggH_OS_boosted","D0minusggH",10,0,1)); hmelaD0minusggH_OS_boosted[k]->Sumw2();
        hmelaD0minus_OS_boosted.push_back(new TH1F ("hmelaD0minus_OS_boosted","D0minus",10,0,1)); hmelaD0minus_OS_boosted[k]->Sumw2();
        hmelaDPhijj_OS_boosted.push_back(new TH1F ("hmelaDPhijj_OS_boosted","DPhijj",64,-3.2,3.2)); hmelaDPhijj_OS_boosted[k]->Sumw2();
        hmelaDPhiUnsignedjj_OS_boosted.push_back(new TH1F ("hmelaDPhiUnsignedjj_OS_boosted","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_OS_boosted[k]->Sumw2();

///SS
        hmelaDCP_SS_0jet.push_back(new TH1F ("hmelaDCP_SS_0jet","DCP",10,0,1)); hmelaDCP_SS_0jet[k]->Sumw2();
        hmelaDCPggH_SS_0jet.push_back(new TH1F ("hmelaDCPggH_SS_0jet","DCPggH",10,0,1)); hmelaDCPggH_SS_0jet[k]->Sumw2();
        hmelaD0minusggH_SS_0jet.push_back(new TH1F ("hmelaD0minusggH_SS_0jet","D0minusggH",10,0,1)); hmelaD0minusggH_SS_0jet[k]->Sumw2();
        hmelaD0minus_SS_0jet.push_back(new TH1F ("hmelaD0minus_SS_0jet","D0minus",10,0,1)); hmelaD0minus_SS_0jet[k]->Sumw2();
        hmelaDPhijj_SS_0jet.push_back(new TH1F ("hmelaDPhijj_SS_0jet","DPhijj",64,-3.2,3.2)); hmelaDPhijj_SS_0jet[k]->Sumw2();
        hmelaDPhiUnsignedjj_SS_0jet.push_back(new TH1F ("hmelaDPhiUnsignedjj_SS_0jet","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_SS_0jet[k]->Sumw2();

        hmelaDCP_SS_VBF.push_back(new TH1F ("hmelaDCP_SS_VBF","DCP",10,0,1)); hmelaDCP_SS_VBF[k]->Sumw2();
        hmelaDCPggH_SS_VBF.push_back(new TH1F ("hmelaDCPggH_SS_VBF","DCPggH",10,0,1)); hmelaDCPggH_SS_VBF[k]->Sumw2();
        hmelaD0minusggH_SS_VBF.push_back(new TH1F ("hmelaD0minusggH_SS_VBF","D0minusggH",10,0,1)); hmelaD0minusggH_SS_VBF[k]->Sumw2();
        hmelaD0minus_SS_VBF.push_back(new TH1F ("hmelaD0minus_SS_VBF","D0minus",10,0,1)); hmelaD0minus_SS_VBF[k]->Sumw2();
        hmelaDPhijj_SS_VBF.push_back(new TH1F ("hmelaDPhijj_SS_VBF","DPhijj",64,-3.2,3.2)); hmelaDPhijj_SS_VBF[k]->Sumw2();
        hmelaDPhiUnsignedjj_SS_VBF.push_back(new TH1F ("hmelaDPhiUnsignedjj_SS_VBF","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_SS_VBF[k]->Sumw2();


        hmelaDCP_SS_boosted.push_back(new TH1F ("hmelaDCP_SS_boosted","DCP",10,0,1)); hmelaDCP_SS_boosted[k]->Sumw2();
        hmelaDCPggH_SS_boosted.push_back(new TH1F ("hmelaDCPggH_SS_boosted","DCPggH",10,0,1)); hmelaDCPggH_SS_boosted[k]->Sumw2();
        hmelaD0minusggH_SS_boosted.push_back(new TH1F ("hmelaD0minusggH_SS_boosted","D0minusggH",10,0,1)); hmelaD0minusggH_SS_boosted[k]->Sumw2();
        hmelaD0minus_SS_boosted.push_back(new TH1F ("hmelaD0minus_SS_boosted","D0minus",10,0,1)); hmelaD0minus_SS_boosted[k]->Sumw2();
        hmelaDPhijj_SS_boosted.push_back(new TH1F ("hmelaDPhijj_SS_boosted","DPhijj",64,-3.2,3.2)); hmelaDPhijj_SS_boosted[k]->Sumw2();
        hmelaDPhiUnsignedjj_SS_boosted.push_back(new TH1F ("hmelaDPhiUnsignedjj_SS_boosted","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_SS_boosted[k]->Sumw2();

//QCD
        hmelaDCP_QCD_0jet.push_back(new TH1F ("hmelaDCP_QCD_0jet","DCP",10,0,1)); hmelaDCP_QCD_0jet[k]->Sumw2();
        hmelaDCPggH_QCD_0jet.push_back(new TH1F ("hmelaDCPggH_QCD_0jet","DCPggH",10,0,1)); hmelaDCPggH_QCD_0jet[k]->Sumw2();
        hmelaD0minusggH_QCD_0jet.push_back(new TH1F ("hmelaD0minusggH_QCD_0jet","D0minusggH",10,0,1)); hmelaD0minusggH_QCD_0jet[k]->Sumw2();
        hmelaD0minus_QCD_0jet.push_back(new TH1F ("hmelaD0minus_QCD_0jet","D0minus",10,0,1)); hmelaD0minus_QCD_0jet[k]->Sumw2();
        hmelaDPhijj_QCD_0jet.push_back(new TH1F ("hmelaDPhijj_QCD_0jet","DPhijj",64,-3.2,3.2)); hmelaDPhijj_QCD_0jet[k]->Sumw2();
        hmelaDPhiUnsignedjj_QCD_0jet.push_back(new TH1F ("hmelaDPhiUnsignedjj_QCD_0jet","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_QCD_0jet[k]->Sumw2();

        hmelaDCP_QCD_VBF.push_back(new TH1F ("hmelaDCP_QCD_VBF","DCP",10,0,1)); hmelaDCP_QCD_VBF[k]->Sumw2();
        hmelaDCPggH_QCD_VBF.push_back(new TH1F ("hmelaDCPggH_QCD_VBF","DCPggH",10,0,1)); hmelaDCPggH_QCD_VBF[k]->Sumw2();
        hmelaD0minusggH_QCD_VBF.push_back(new TH1F ("hmelaD0minusggH_QCD_VBF","D0minusggH",10,0,1)); hmelaD0minusggH_QCD_VBF[k]->Sumw2();
        hmelaD0minus_QCD_VBF.push_back(new TH1F ("hmelaD0minus_QCD_VBF","D0minus",10,0,1)); hmelaD0minus_QCD_VBF[k]->Sumw2();
        hmelaDPhijj_QCD_VBF.push_back(new TH1F ("hmelaDPhijj_QCD_VBF","DPhijj",64,-3.2,3.2)); hmelaDPhijj_QCD_VBF[k]->Sumw2();
        hmelaDPhiUnsignedjj_QCD_VBF.push_back(new TH1F ("hmelaDPhiUnsignedjj_QCD_VBF","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_QCD_VBF[k]->Sumw2();


        hmelaDCP_QCD_boosted.push_back(new TH1F ("hmelaDCP_QCD_boosted","DCP",10,0,1)); hmelaDCP_QCD_boosted[k]->Sumw2();
        hmelaDCPggH_QCD_boosted.push_back(new TH1F ("hmelaDCPggH_QCD_boosted","DCPggH",10,0,1)); hmelaDCPggH_QCD_boosted[k]->Sumw2();
        hmelaD0minusggH_QCD_boosted.push_back(new TH1F ("hmelaD0minusggH_QCD_boosted","D0minusggH",10,0,1)); hmelaD0minusggH_QCD_boosted[k]->Sumw2();
        hmelaD0minus_QCD_boosted.push_back(new TH1F ("hmelaD0minus_QCD_boosted","D0minus",10,0,1)); hmelaD0minus_QCD_boosted[k]->Sumw2();
        hmelaDPhijj_QCD_boosted.push_back(new TH1F ("hmelaDPhijj_QCD_boosted","DPhijj",64,-3.2,3.2)); hmelaDPhijj_QCD_boosted[k]->Sumw2();
        hmelaDPhiUnsignedjj_QCD_boosted.push_back(new TH1F ("hmelaDPhiUnsignedjj_QCD_boosted","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_QCD_boosted[k]->Sumw2();


        hmelaDCP_WOS_0jet.push_back(new TH1F ("hmelaDCP_WOS_0jet","DCP",10,0,1)); hmelaDCP_WOS_0jet[k]->Sumw2();
        hmelaDCPggH_WOS_0jet.push_back(new TH1F ("hmelaDCPggH_WOS_0jet","DCPggH",10,0,1)); hmelaDCPggH_WOS_0jet[k]->Sumw2();
        hmelaD0minusggH_WOS_0jet.push_back(new TH1F ("hmelaD0minusggH_WOS_0jet","D0minusggH",10,0,1)); hmelaD0minusggH_WOS_0jet[k]->Sumw2();
        hmelaD0minus_WOS_0jet.push_back(new TH1F ("hmelaD0minus_WOS_0jet","D0minus",10,0,1)); hmelaD0minus_WOS_0jet[k]->Sumw2();
        hmelaDPhijj_WOS_0jet.push_back(new TH1F ("hmelaDPhijj_WOS_0jet","DPhijj",64,-3.2,3.2)); hmelaDPhijj_WOS_0jet[k]->Sumw2();
        hmelaDPhiUnsignedjj_WOS_0jet.push_back(new TH1F ("hmelaDPhiUnsignedjj_WOS_0jet","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_WOS_0jet[k]->Sumw2();

        hmelaDCP_WOS_VBF.push_back(new TH1F ("hmelaDCP_WOS_VBF","DCP",10,0,1)); hmelaDCP_WOS_VBF[k]->Sumw2();
        hmelaDCPggH_WOS_VBF.push_back(new TH1F ("hmelaDCPggH_WOS_VBF","DCPggH",10,0,1)); hmelaDCPggH_WOS_VBF[k]->Sumw2();
        hmelaD0minusggH_WOS_VBF.push_back(new TH1F ("hmelaD0minusggH_WOS_VBF","D0minusggH",10,0,1)); hmelaD0minusggH_WOS_VBF[k]->Sumw2();
        hmelaD0minus_WOS_VBF.push_back(new TH1F ("hmelaD0minus_WOS_VBF","D0minus",10,0,1)); hmelaD0minus_WOS_VBF[k]->Sumw2();
        hmelaDPhijj_WOS_VBF.push_back(new TH1F ("hmelaDPhijj_WOS_VBF","DPhijj",64,-3.2,3.2)); hmelaDPhijj_WOS_VBF[k]->Sumw2();
        hmelaDPhiUnsignedjj_WOS_VBF.push_back(new TH1F ("hmelaDPhiUnsignedjj_WOS_VBF","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_WOS_VBF[k]->Sumw2();


        hmelaDCP_WOS_boosted.push_back(new TH1F ("hmelaDCP_WOS_boosted","DCP",10,0,1)); hmelaDCP_WOS_boosted[k]->Sumw2();
        hmelaDCPggH_WOS_boosted.push_back(new TH1F ("hmelaDCPggH_WOS_boosted","DCPggH",10,0,1)); hmelaDCPggH_WOS_boosted[k]->Sumw2();
        hmelaD0minusggH_WOS_boosted.push_back(new TH1F ("hmelaD0minusggH_WOS_boosted","D0minusggH",10,0,1)); hmelaD0minusggH_WOS_boosted[k]->Sumw2();
        hmelaD0minus_WOS_boosted.push_back(new TH1F ("hmelaD0minus_WOS_boosted","D0minus",10,0,1)); hmelaD0minus_WOS_boosted[k]->Sumw2();
        hmelaDPhijj_WOS_boosted.push_back(new TH1F ("hmelaDPhijj_WOS_boosted","DPhijj",64,-3.2,3.2)); hmelaDPhijj_WOS_boosted[k]->Sumw2();
        hmelaDPhiUnsignedjj_WOS_boosted.push_back(new TH1F ("hmelaDPhiUnsignedjj_WOS_boosted","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_WOS_boosted[k]->Sumw2();


        hmelaDCP_WSS_0jet.push_back(new TH1F ("hmelaDCP_WSS_0jet","DCP",10,0,1)); hmelaDCP_WSS_0jet[k]->Sumw2();
        hmelaDCPggH_WSS_0jet.push_back(new TH1F ("hmelaDCPggH_WSS_0jet","DCPggH",10,0,1)); hmelaDCPggH_WSS_0jet[k]->Sumw2();
        hmelaD0minusggH_WSS_0jet.push_back(new TH1F ("hmelaD0minusggH_WSS_0jet","D0minusggH",10,0,1)); hmelaD0minusggH_WSS_0jet[k]->Sumw2();
        hmelaD0minus_WSS_0jet.push_back(new TH1F ("hmelaD0minus_WSS_0jet","D0minus",10,0,1)); hmelaD0minus_WSS_0jet[k]->Sumw2();
        hmelaDPhijj_WSS_0jet.push_back(new TH1F ("hmelaDPhijj_WSS_0jet","DPhijj",64,-3.2,3.2)); hmelaDPhijj_WSS_0jet[k]->Sumw2();
        hmelaDPhiUnsignedjj_WSS_0jet.push_back(new TH1F ("hmelaDPhiUnsignedjj_WSS_0jet","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_WSS_0jet[k]->Sumw2();

        hmelaDCP_WSS_VBF.push_back(new TH1F ("hmelaDCP_WSS_VBF","DCP",10,0,1)); hmelaDCP_WSS_VBF[k]->Sumw2();
        hmelaDCPggH_WSS_VBF.push_back(new TH1F ("hmelaDCPggH_WSS_VBF","DCPggH",10,0,1)); hmelaDCPggH_WSS_VBF[k]->Sumw2();
        hmelaD0minusggH_WSS_VBF.push_back(new TH1F ("hmelaD0minusggH_WSS_VBF","D0minusggH",10,0,1)); hmelaD0minusggH_WSS_VBF[k]->Sumw2();
        hmelaD0minus_WSS_VBF.push_back(new TH1F ("hmelaD0minus_WSS_VBF","D0minus",10,0,1)); hmelaD0minus_WSS_VBF[k]->Sumw2();
        hmelaDPhijj_WSS_VBF.push_back(new TH1F ("hmelaDPhijj_WSS_VBF","DPhijj",64,-3.2,3.2)); hmelaDPhijj_WSS_VBF[k]->Sumw2();
        hmelaDPhiUnsignedjj_WSS_VBF.push_back(new TH1F ("hmelaDPhiUnsignedjj_WSS_VBF","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_WSS_VBF[k]->Sumw2();


        hmelaDCP_WSS_boosted.push_back(new TH1F ("hmelaDCP_WSS_boosted","DCP",10,0,1)); hmelaDCP_WSS_boosted[k]->Sumw2();
        hmelaDCPggH_WSS_boosted.push_back(new TH1F ("hmelaDCPggH_WSS_boosted","DCPggH",10,0,1)); hmelaDCPggH_WSS_boosted[k]->Sumw2();
        hmelaD0minusggH_WSS_boosted.push_back(new TH1F ("hmelaD0minusggH_WSS_boosted","D0minusggH",10,0,1)); hmelaD0minusggH_WSS_boosted[k]->Sumw2();
        hmelaD0minus_WSS_boosted.push_back(new TH1F ("hmelaD0minus_WSS_boosted","D0minus",10,0,1)); hmelaD0minus_WSS_boosted[k]->Sumw2();
        hmelaDPhijj_WSS_boosted.push_back(new TH1F ("hmelaDPhijj_WSS_boosted","DPhijj",64,-3.2,3.2)); hmelaDPhijj_WSS_boosted[k]->Sumw2();
        hmelaDPhiUnsignedjj_WSS_boosted.push_back(new TH1F ("hmelaDPhiUnsignedjj_WSS_boosted","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_WSS_boosted[k]->Sumw2();




        ostringstream H1D1; H1D1 << "h1D_OS" << k;
        h1D_OS.push_back(new TH1F (H1D1.str().c_str(),"InvMa",10,0,400)); h1D_OS[k]->Sumw2();


        h1D_jpt1_OS.push_back(new TH1F ("h1D_jpt1_OS","pT",40,0,400)); h1D_jpt1_OS[k]->Sumw2();
        h1D_jpt2_OS.push_back(new TH1F ("h1D_jpt2_OS","pT",40,0,400)); h1D_jpt2_OS[k]->Sumw2();
        h1D_jeta1_OS.push_back(new TH1F ("h1D_jeta1_OS","eta",50,-2.5,2.5)); h1D_jeta1_OS[k]->Sumw2();
        h1D_jeta2_OS.push_back(new TH1F ("h1D_jeta2_OS","eta",50,-2.5,2.5)); h1D_jeta2_OS[k]->Sumw2();
        h1D_phi1_OS.push_back(new TH1F ("h1D_phi1_OS","phi",40,-4,4)); h1D_phi1_OS[k]->Sumw2();
        h1D_phi2_OS.push_back(new TH1F ("h1D_phi2_OS","phi",40,-4,4)); h1D_phi2_OS[k]->Sumw2();
        h1D_mjj_OS.push_back(new TH1F ("h1D_mjj_OS","Mass_jj",100,0,1000)); h1D_mjj_OS[k]->Sumw2();
        h1D_met_OS.push_back(new TH1F ("h1D_met_OS","MET",50,0,500)); h1D_met_OS[k]->Sumw2();



        h1D_jpt1_SS.push_back(new TH1F ("h1D_jpt1_SS","pT",40,0,400)); h1D_jpt1_SS[k]->Sumw2();
        h1D_jpt2_SS.push_back(new TH1F ("h1D_jpt2_SS","pT",40,0,400)); h1D_jpt2_SS[k]->Sumw2();
        h1D_jeta1_SS.push_back(new TH1F ("h1D_jeta1_SS","eta",50,-2.5,2.5)); h1D_jeta1_SS[k]->Sumw2();
        h1D_jeta2_SS.push_back(new TH1F ("h1D_jeta2_SS","eta",50,-2.5,2.5)); h1D_jeta2_SS[k]->Sumw2();
        h1D_phi1_SS.push_back(new TH1F ("h1D_phi1_SS","phi",40,-4,4)); h1D_phi1_SS[k]->Sumw2();
        h1D_phi2_SS.push_back(new TH1F ("h1D_phi2_SS","phi",40,-4,4)); h1D_phi2_SS[k]->Sumw2();
        h1D_mjj_SS.push_back(new TH1F ("h1D_mjj_SS","Mass_jj",100,0,1000)); h1D_mjj_SS[k]->Sumw2();
        h1D_met_SS.push_back(new TH1F ("h1D_met_SS","MET",50,0,500)); h1D_met_SS[k]->Sumw2();

        h1D_jpt1_QCD.push_back(new TH1F ("h1D_jpt1_QCD","pT",40,0,400)); h1D_jpt1_QCD[k]->Sumw2();
        h1D_jpt2_QCD.push_back(new TH1F ("h1D_jpt2_QCD","pT",40,0,400)); h1D_jpt2_QCD[k]->Sumw2();
        h1D_jeta1_QCD.push_back(new TH1F ("h1D_jeta1_QCD","eta",50,-2.5,2.5)); h1D_jeta1_QCD[k]->Sumw2();
        h1D_jeta2_QCD.push_back(new TH1F ("h1D_jeta2_QCD","eta",50,-2.5,2.5)); h1D_jeta2_QCD[k]->Sumw2();
        h1D_phi1_QCD.push_back(new TH1F ("h1D_phi1_QCD","phi",40,-4,4)); h1D_phi1_QCD[k]->Sumw2();
        h1D_phi2_QCD.push_back(new TH1F ("h1D_phi2_QCD","phi",40,-4,4)); h1D_phi2_QCD[k]->Sumw2();
        h1D_mjj_QCD.push_back(new TH1F ("h1D_mjj_QCD","Mass_jj",100,0,1000)); h1D_mjj_QCD[k]->Sumw2();
        h1D_met_QCD.push_back(new TH1F ("h1D_met_QCD","MET",50,0,500)); h1D_met_QCD[k]->Sumw2();


        h1D_jpt1_WOS.push_back(new TH1F ("h1D_jpt1_WOS","pT",40,0,400)); h1D_jpt1_WOS[k]->Sumw2();
        h1D_jpt2_WOS.push_back(new TH1F ("h1D_jpt2_WOS","pT",40,0,400)); h1D_jpt2_WOS[k]->Sumw2();
        h1D_jeta1_WOS.push_back(new TH1F ("h1D_jeta1_WOS","eta",50,-2.5,2.5)); h1D_jeta1_WOS[k]->Sumw2();
        h1D_jeta2_WOS.push_back(new TH1F ("h1D_jeta2_WOS","eta",50,-2.5,2.5)); h1D_jeta2_WOS[k]->Sumw2();
        h1D_phi1_WOS.push_back(new TH1F ("h1D_phi1_WOS","phi",40,-4,4)); h1D_phi1_WOS[k]->Sumw2();
        h1D_phi2_WOS.push_back(new TH1F ("h1D_phi2_WOS","phi",40,-4,4)); h1D_phi2_WOS[k]->Sumw2();
        h1D_mjj_WOS.push_back(new TH1F ("h1D_mjj_WOS","Mass_jj",100,0,1000)); h1D_mjj_WOS[k]->Sumw2();
        h1D_met_WOS.push_back(new TH1F ("h1D_met_WOS","MET",50,0,500)); h1D_met_WOS[k]->Sumw2();

        h1D_jpt1_WSS.push_back(new TH1F ("h1D_jpt1_WSS","pT",40,0,400)); h1D_jpt1_WSS[k]->Sumw2();
        h1D_jpt2_WSS.push_back(new TH1F ("h1D_jpt2_WSS","pT",40,0,400)); h1D_jpt2_WSS[k]->Sumw2();
        h1D_jeta1_WSS.push_back(new TH1F ("h1D_jeta1_WSS","eta",50,-2.5,2.5)); h1D_jeta1_WSS[k]->Sumw2();
        h1D_jeta2_WSS.push_back(new TH1F ("h1D_jeta2_WSS","eta",50,-2.5,2.5)); h1D_jeta2_WSS[k]->Sumw2();
        h1D_phi1_WSS.push_back(new TH1F ("h1D_phi1_WSS","phi",40,-4,4)); h1D_phi1_WSS[k]->Sumw2();
        h1D_phi2_WSS.push_back(new TH1F ("h1D_phi2_WSS","phi",40,-4,4)); h1D_phi2_WSS[k]->Sumw2();
        h1D_mjj_WSS.push_back(new TH1F ("h1D_mjj_WSS","Mass_jj",100,0,1000)); h1D_mjj_WSS[k]->Sumw2();
        h1D_met_WSS.push_back(new TH1F ("h1D_met_WSS","MET",50,0,500)); h1D_met_WSS[k]->Sumw2();


        ostringstream H1D2; H1D2 << "h1D_SS" << k;
        h1D_SS.push_back(new TH1F (H1D2.str().c_str(),"InvMa",10,0,400)); h1D_SS[k]->Sumw2();
        ostringstream H1D3; H1D3 << "h1D_QCD" << k;
        h1D_QCD.push_back(new TH1F (H1D3.str().c_str(),"InvMa",10,0,400)); h1D_QCD[k]->Sumw2();
        ostringstream H1D4; H1D4 << "h1D_WOS" << k;
        h1D_WOS.push_back(new TH1F (H1D4.str().c_str(),"InvMa",10,0,400)); h1D_WOS[k]->Sumw2();
        ostringstream H1D5; H1D5 << "h1D_WSS" << k;
        h1D_WSS.push_back(new TH1F (H1D5.str().c_str(),"InvMa",10,0,400)); h1D_WSS[k]->Sumw2();

        ostringstream HNS0CRQCD; HNS0CRQCD << "h0_CR_QCD" << k;
        ostringstream HNS1CRQCD; HNS1CRQCD << "h1_CR_QCD" << k;
        ostringstream HNS2CRQCD; HNS2CRQCD << "h2_CR_QCD" << k;
        h0_CR_QCD.push_back(new TH1F (HNS0CRQCD.str().c_str(),"I",4,40,200)); h0_CR_QCD[k]->Sumw2();
        h1_CR_QCD.push_back(new TH1F (HNS1CRQCD.str().c_str(),"I",4,40,200)); h1_CR_QCD[k]->Sumw2();
        h2_CR_QCD.push_back(new TH1F (HNS2CRQCD.str().c_str(),"I",4,40,200)); h2_CR_QCD[k]->Sumw2();

        ostringstream HNS0CRW; HNS0CRW << "h0_CR_W" << k;
        ostringstream HNS1CRW; HNS1CRW << "h1_CR_W" << k;
        ostringstream HNS2CRW; HNS2CRW << "h2_CR_W" << k;
        h0_CR_W.push_back(new TH1F (HNS0CRW.str().c_str(),"I",1,80,200)); h0_CR_W[k]->Sumw2();
        h1_CR_W.push_back(new TH1F (HNS1CRW.str().c_str(),"I",1,80,200)); h1_CR_W[k]->Sumw2();
        h2_CR_W.push_back(new TH1F (HNS2CRW.str().c_str(),"I",1,80,200)); h2_CR_W[k]->Sumw2();

        ostringstream HNS0CRSSQCD; HNS0CRSSQCD << "h0_CRSS_QCD" << k;
        ostringstream HNS1CRSSQCD; HNS1CRSSQCD << "h1_CRSS_QCD" << k;
        ostringstream HNS2CRSSQCD; HNS2CRSSQCD << "h2_CRSS_QCD" << k;
        h0_CRSS_QCD.push_back(new TH1F (HNS0CRSSQCD.str().c_str(),"I",4,40,200)); h0_CRSS_QCD[k]->Sumw2();
        h1_CRSS_QCD.push_back(new TH1F (HNS1CRSSQCD.str().c_str(),"I",4,40,200)); h1_CRSS_QCD[k]->Sumw2();
        h2_CRSS_QCD.push_back(new TH1F (HNS2CRSSQCD.str().c_str(),"I",4,40,200)); h2_CRSS_QCD[k]->Sumw2();

        ostringstream HNS0CRSSW; HNS0CRSSW << "h0_CRSS_W" << k;
        ostringstream HNS1CRSSW; HNS1CRSSW << "h1_CRSS_W" << k;
        ostringstream HNS2CRSSW; HNS2CRSSW << "h2_CRSS_W" << k;
        h0_CRSS_W.push_back(new TH1F (HNS0CRSSW.str().c_str(),"I",1,80,200)); h0_CRSS_W[k]->Sumw2();
        h1_CRSS_W.push_back(new TH1F (HNS1CRSSW.str().c_str(),"I",1,80,200)); h1_CRSS_W[k]->Sumw2();
        h2_CRSS_W.push_back(new TH1F (HNS2CRSSW.str().c_str(),"I",1,80,200)); h2_CRSS_W[k]->Sumw2();
   }


    TFile *fEleRec=new TFile("EGammaRec.root");
    TH2F *histEleRec=(TH2F*) fEleRec->Get("EGamma_SF2D");

    TFile *fEleWP80=new TFile("EGammaWP80.root");
    TH2F *histEleWP80=(TH2F*) fEleWP80->Get("EGamma_SF2D");

    TFile *fEleWP90=new TFile("EGammaWP90.root");
    TH2F *histEleWP90=(TH2F*) fEleWP90->Get("EGamma_SF2D");

   ScaleFactor * myScaleFactor_trgEle25 = new ScaleFactor();
   myScaleFactor_trgEle25->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele25WPTight_eff.root");
   ScaleFactor * myScaleFactor_trgEle24Leg = new ScaleFactor();
   myScaleFactor_trgEle24Leg->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele24_eff.root");
   ScaleFactor * myScaleFactor_id = new ScaleFactor();
   myScaleFactor_id->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_IdIso_IsoLt0p1_eff.root");
   ScaleFactor * myScaleFactor_trgEle25Anti = new ScaleFactor();
   myScaleFactor_trgEle25Anti->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele25WPTight_antiisolated_Iso0p1to0p3_eff_rb.root");
   ScaleFactor * myScaleFactor_trgEle24LegAnti = new ScaleFactor();
   myScaleFactor_trgEle24LegAnti->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele24_antiisolated_Iso0p1to0p3_eff_rb.root");
   ScaleFactor * myScaleFactor_idAnti = new ScaleFactor();
   myScaleFactor_idAnti->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_IdIso_antiisolated_Iso0p1to0p3_eff.root");

   TString postfixTES[12]={"_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"};
   TString postfixDM[6]={"_CMS_tauDMReco_1prong_13TeVUp","_CMS_tauDMReco_1prong_13TeVDown","_CMS_tauDMReco_1prong1pizero_13TeVUp","_CMS_tauDMReco_1prong1pizero_13TeVDown","_CMS_tauDMReco_3prong_13TeVUp","_CMS_tauDMReco_3prong_13TeVDown"};
   TString postfixFakeDM[6]={"_CMS_jetToTauDMReco_1prong_13TeVUp","_CMS_jetToTauDMReco_1prong_13TeVDown","_CMS_jetToTauDMReco_1prong1pizero_13TeVUp","_CMS_jetToTauDMReco_1prong1pizero_13TeVDown","_CMS_jetToTauDMReco_3prong_13TeVUp","_CMS_jetToTauDMReco_3prong_13TeVDown"};
   TString postfixZLshape[12]={"_CMS_htt_ZLShape_et_13TeVUp","_CMS_htt_ZLShape_et_13TeVDown","_CMS_ZLShape_et_0jet_1prong_13TeVUp","_CMS_ZLShape_et_0jet_1prong_13TeVDown","_CMS_ZLShape_et_0jet_1prong1pizero_13TeVUp","_CMS_ZLShape_et_0jet_1prong1pizero_13TeVDown", "_CMS_ZLShape_et_1prong_13TeVUp","_CMS_ZLShape_et_1prong_13TeVDown", "_CMS_ZLShape_et_1prong1pizero_13TeVUp","_CMS_ZLShape_et_1prong1pizero_13TeVDown","_CMS_ZLShape_et_3prong_13TeVUp","_CMS_ZLShape_et_3prong_13TeVDown"};
   TString postfixZLnorm[4]={"_CMS_eFakeTau_1prong_13TeVUp","_CMS_eFakeTau_1prong_13TeVDown","_CMS_eFakeTau_1prong1pizero_13TeVUp","_CMS_eFakeTau_1prong1pizero_13TeVDown"};
   TString postfixJES[56]={"_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"};

   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 25000 == 0 or i == nentries_wtn-1 ) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);
//if (evt==315090045 or evt==451961707 or evt==514710233 or evt==512106324) cout<<evt<<" "<<pt_2<<" "<<m_sv<<" "<<m_sv_UP<<" "<<m_sv_DOWN<<" "<<met<<endl;
	if (fabs(eta_1)>2.1) continue;

	bool isSingleLep=passEle25eta2p1Tight && matchEle25eta2p1Tight_1 && filterEle25eta2p1Tight_1;
	//bool isCrossTrigger = ((passEle24Tau20sL1 && matchEle24Tau20sL1_1 && filterEle24Tau20sL1_1 && filterEle24Tau20sL1_2) or (passEle24Tau20 && matchEle24Tau20_1 && filterEle24Tau20_1 && filterEle24Tau20_2) or (passEle24Tau30 && matchEle24Tau30_1 && filterEle24Tau30_1 && filterEle24Tau30_2));
	if (!isSingleLep or pt_1<26) continue;

        if ((sample=="ZL" or sample=="EWKZNuNu_L" or sample=="EWKZLL_L") && gen_match_2>4) continue;
        if ((sample=="TTT" or sample=="ZTT" or sample=="EWKZNuNu_TT" or sample=="EWKZLL_TT") && gen_match_2!=5) continue;
        if ((sample=="TTJ" or sample=="ZLL" or sample=="ZL" or sample=="EWKZNuNu_LL" or sample=="EWKZLL_LL") && gen_match_2==5) continue;
        if ((sample=="ZJ" or sample=="EWKZNuNu_J" or sample=="EWKZLL_J") && gen_match_2!=6) continue;

	if (!againstElectronTightMVA6_2 or !againstMuonLoose3_2) continue;

        float sf_trg=1.0;
        float sf_id=1.0;
	float sf_id_anti=1.0;
	float sf_trg_anti=1.0;
	float eff_tau=1.0;

        if (sample!="data_obs"){ //Ele25 only
           sf_trg=myScaleFactor_trgEle25->get_ScaleFactor(pt_1,eta_1);
           sf_trg_anti=myScaleFactor_trgEle25Anti->get_ScaleFactor(pt_1,eta_1);
           sf_id=myScaleFactor_id->get_ScaleFactor(pt_1,eta_1);
	   sf_id_anti=myScaleFactor_idAnti->get_ScaleFactor(pt_1,eta_1);
        }

	float signalRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.10);
	float qcdRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30);
        float wRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30);
        float wsfRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.10);
        float qcdCR=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30 && iso_1>0.10);

	TLorentzVector mytau; 
	mytau.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
        TLorentzVector myele;
        myele.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);

	//***************** Visible mass between the muon and the tau **************
        
        if (sample=="W"){
            weight=25.44;
            if (numGenJets==1) weight=6.82;
            else if (numGenJets==2) weight=2.099;
            else if (numGenJets==3) weight=0.689;
            else if (numGenJets==4) weight=0.690;
        }

        if (sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            weight=1.418;
            if (numGenJets==1)
                weight=0.457;
            else if (numGenJets==2)
                weight=0.467;
            else if (numGenJets==3)
                weight=0.480;
            else if (numGenJets==4)
                weight=0.393;
        }

	float correction=sf_trg*sf_id*LumiWeights_12->weight(npu);

	float aweight=genweight*weight*correction;
	if (gen_match_2==5) aweight=aweight*0.95;

	if (sample!="data_obs"){
           w->var("e_pt")->setVal(myele.Pt());
           w->var("e_eta")->setVal(myele.Eta());
           aweight=aweight*w->function("e_trk_ratio")->getVal();
        }

        if (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(genM),histZ->GetYaxis()->FindBin(genpT));
            if (fabs(tes)!=10) //nominal
                 aweight=aweight*zpt_corr;
            else if (tes==10) // up
                 aweight=aweight*(1+1.10*(zpt_corr-1));
            else if (tes==-10) // down
                 aweight=aweight*(1+0.90*(zpt_corr-1));
        }

        if (njets>=2 && (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ")){
            float mjj_corr=histM->GetBinContent(histM->GetXaxis()->FindBin(fabs(jeta_1-jeta_2)),histM->GetYaxis()->FindBin(mjj));
            if (fabs(tes)!=20) //nominal
                 aweight=aweight*mjj_corr;
            else if (tes==20) // up
                 aweight=aweight*(1+2.00*(mjj_corr-1));
            else if (tes==-20) // down
                 aweight=aweight*(1+0.00*(mjj_corr-1));
        }

	//************************ Jet to tau FR shape **************************
	if (tes==14 && (sample=="TTJ" or sample=="ZJ" or sample=="W") && gen_match_2==6){
	    float jtotau=1-(0.2*mytau.Pt()/100);
	    if (mytau.Pt()>200) jtotau=1-(0.2*200.0/100);
	    aweight=aweight*jtotau;
	}
        if (tes==-14 && (sample=="TTJ" or sample=="ZJ" or sample=="W") && gen_match_2==6){
            float jtotau=1+(0.2*mytau.Pt()/100);
            if (mytau.Pt()>200) jtotau=1+(0.2*200.0/100);
            aweight=aweight*jtotau;
        }

	//*********************** Definition of fit variables *******************
        int numberJets=njets;
        float massJets=mjj;
        float var2=m_sv;
        float var1_1=pt_sv;
        float var1_0=mytau.Pt();
        float var1_2=massJets;
        float var1_3=dPhi_jj;
        float var1_4=dPhiUnsigned_jj;

        if (name=="reweighted_qqH_htt_0M125" or name=="reweighted_WH_htt_0M125" or name=="reweighted_ZH_htt_0M125" or name=="reweighted_GGH2Jets_0M125") aweight=aweight*jhuw_a3;
        if (name=="reweighted_qqH_htt_0PH125" or name=="reweighted_WH_htt_0PH125" or name=="reweighted_ZH_htt_0PH125" or name=="reweighted_GGH2Jets_0PH125") aweight=aweight*jhuw_a2;
        if (name=="reweighted_qqH_htt_0PM125" or name=="reweighted_WH_htt_0PM125" or name=="reweighted_ZH_htt_0PM125" or name=="reweighted_GGH2Jets_0PM125") aweight=aweight*jhuw_a1;
        if (name=="reweighted_qqH_htt_0L1125" or name=="reweighted_WH_htt_0L1125" or name=="reweighted_ZH_htt_0L1125" or name=="reweighted_GGH2Jets_0L1125") aweight=aweight*jhuw_l1;
        if (name=="reweighted_qqH_htt_0L1Zg125" or name=="reweighted_WH_htt_0L1Zg125" or name=="reweighted_ZH_htt_0L1Zg125" or name=="reweighted_GGH2Jets_0L1Zg125") aweight=aweight*jhuw_l1Zg;
        if (name=="reweighted_qqH_htt_0Mf05ph0125" or name=="reweighted_WH_htt_0Mf05ph0125" or name=="reweighted_ZH_htt_0Mf05ph0125" or name=="reweighted_GGH2Jets_0Mf05ph0125") aweight=aweight*jhuw_a3int;
        if (name=="reweighted_qqH_htt_0PHf05ph0125" or name=="reweighted_WH_htt_0PHf05ph0125" or name=="reweighted_ZH_htt_0PHf05ph0125" or name=="reweighted_GGH2Jets_0PHf05ph0125") aweight=aweight*jhuw_a2int;
        if (name=="reweighted_qqH_htt_0L1f05ph0125" or name=="reweighted_WH_htt_0L1f05ph0125" or name=="reweighted_ZH_htt_0L1f05ph0125" or name=="reweighted_GGH2Jets_0L1f05ph0125") aweight=aweight*jhuw_l1int;
        if (name=="reweighted_qqH_htt_0L1Zgf05ph0125" or name=="reweighted_WH_htt_0L1Zgf05ph0125" or name=="reweighted_ZH_htt_0L1Zgf05ph0125" or name=="reweighted_GGH2Jets_0L1Zgf05ph0125") aweight=aweight*jhuw_l1Zgint;


	//*********************** Top pT reweighting ****************************
        float pttop1=pt_top1;
        if (pttop1>400) pttop1=400;
        float pttop2=pt_top2;
        if (pttop2>400) pttop2=400;

        if ((sample=="TT" or sample=="TTT" or sample=="TTJ") && fabs(tes)==11) aweight*=sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2));
        if ((sample=="TT" or sample=="TTT" or sample=="TTJ") && tes==11) aweight*=(1+2*(sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2))-1));


	if (gen_match_2==1 or gen_match_2==3){
            if (fabs(mytau.Eta())<1.460) aweight=aweight*1.402;
            else if (fabs(mytau.Eta())>1.558) aweight=aweight*1.900;
	    if (sample=="ZL" && l2_decayMode==0) aweight=aweight*0.98;
  	    else if (sample=="ZL" && l2_decayMode==1) aweight=aweight*1.20;
        }

        else if (gen_match_2==2 or gen_match_2==4){
            if (fabs(mytau.Eta())<0.4) aweight=aweight*1.012;
            else if (fabs(mytau.Eta())<0.8) aweight=aweight*1.007;
            else if (fabs(mytau.Eta())<1.2) aweight=aweight*0.870;
            else if (fabs(mytau.Eta())<1.7) aweight=aweight*1.154;
            else aweight=aweight*2.281;
        }

        if (sample=="data_obs") aweight=1.0;

        float weight_btag=1.0;
        if (sample!="data_obs"){
            int nbtagged=nbtag;
            if (nbtagged>2) nbtagged=2;
            weight_btag=bTagEventWeight(nbtagged,bpt_1,bflavor_1,bpt_2,bflavor_2,1,0,0);
            if (nbtagged>2) weight_btag=0;
        }
        bool is_bveto=(sample!="data_obs" or nbtag==0);

	//************************* Fill histograms **********************
        int nombrejets[56]={njets_JESDown,njets_JESUp,njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleDown,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatDown,njets_JetAbsoluteStatUp,njets_JetFlavorQCDDown,njets_JetFlavorQCDUp,njets_JetFragmentationDown,njets_JetFragmentationUp,njets_JetPileUpDataMCDown,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBDown,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Down,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFDown,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefDown,njets_JetPileUpPtRefUp,njets_JetRelativeBalDown,njets_JetRelativeBalUp,njets_JetRelativeFSRDown,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Down,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFDown,njets_JetRelativeJERHFUp,njets_JetRelativePtBBDown,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Down,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Down,njets_JetRelativePtEC2Up,njets_JetRelativePtHFDown,njets_JetRelativePtHFUp,njets_JetRelativeStatECDown,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRDown,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFDown,njets_JetRelativeStatHFUp,njets_JetSinglePionECALDown,njets_JetSinglePionECALUp,njets_JetSinglePionHCALDown,njets_JetSinglePionHCALUp,njets_JetTimePtEtaDown,njets_JetTimePtEtaUp};

        float massejets[56]={mjj_JESDown,mjj_JESUp,mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatDown,mjj_JetAbsoluteStatUp,mjj_JetFlavorQCDDown,mjj_JetFlavorQCDUp,mjj_JetFragmentationDown,mjj_JetFragmentationUp,mjj_JetPileUpDataMCDown,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefDown,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalDown,mjj_JetRelativeBalUp,mjj_JetRelativeFSRDown,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFDown,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBDown,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Down,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFDown,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECDown,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFDown,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALDown,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALDown,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaDown,mjj_JetTimePtEtaUp};

        if (sample=="data_obs") aweight=1.0;

        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector myrawtau=mytau;

        for (int k=0; k<nbhist; ++k){
	    TLorentzVector mymet=myrawmet;
	    mytau=myrawtau;
            if (tes==100) numberJets=nombrejets[k];
            if (tes==100) massJets=massejets[k];
	    var1_1=pt_sv;
	    var2=m_sv;
            float var1_2=massJets;
	    ///needed for ggH
            float var1_3=dPhi_jj;
            float var1_4=dPhiUnsigned_jj;
	    float weight2=1.0;

            if (tes==1 && gen_match_2==5){
               if (k==0){ var2=m_sv_DOWN; var1_1=pt_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==1){ var2=m_sv_UP; var1_1=pt_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               if (k==2 && l2_decayMode==0){ var2=m_sv_DOWN; var1_1=pt_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==3 && l2_decayMode==0){ var2=m_sv_UP; var1_1=pt_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               if (k==4 && l2_decayMode==1){ var2=m_sv_DOWN; var1_1=pt_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==5 && l2_decayMode==1){ var2=m_sv_UP;var1_1=pt_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               if (k==6 && l2_decayMode==10){ var2=m_sv_DOWN; var1_1=pt_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==7 && l2_decayMode==10){ var2=m_sv_UP; var1_1=pt_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
            }

            if (tes==1){
	       if (k==8){ var2=m_sv_UESDown; var1_1=pt_sv_UESDown; mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
               else if (k==9){ var2=m_sv_UESUp; var1_1=pt_sv_UESUp; mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
               else if (k==10){ var2=m_sv_JESDown; var1_1=pt_sv_JESDown; mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
               else if (k==11){ var2=m_sv_JESUp; var1_1=pt_sv_JESUp; mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
	    }
	    /*if (tes==1){
               if (k==8){ var2=m_sv_UESDown; var1_1=pt_sv_UESDown;}
               else if (k==9){ var2=m_sv_UESUp; var1_1=pt_sv_UESUp;}
               else if (k==10){ var2=m_sv_JESDown; var1_1=pt_sv_JESDown;}
               else if (k==11){ var2=m_sv_JESUp; var1_1=pt_sv_JESUp;}
            }*/

            if (numberJets==0) var2=(myele+mytau).M();

            if (tes==17 && sample=="ZL"){
                if (k==0){ 
		    var2=m_sv_UP; 
		    var1_1=pt_sv_UP; 
		    mytau*=1.030; 
		    mymet=mymet-(0.030/1.030)*mytau;
		    if (numberJets==0) var2=(myele+mytau).M();
		}
                else if (k==1) { 
		    var2=m_sv_DOWN; 
		    var1_1=pt_sv_DOWN; 
		    mytau*=0.97; 
		    mymet=mymet+(0.030/0.97)*mytau;
                    if (numberJets==0) var2=(myele+mytau).M();
		}
                else if (k==2 && l2_decayMode==0 && numberJets==0) var2=var2*1.005; 
                else if (k==3 && l2_decayMode==0 && numberJets==0) var2=var2*0.995; 
                else if (k==4 && l2_decayMode==1 && numberJets==0) var2=var2*1.005; 
                else if (k==5 && l2_decayMode==1 && numberJets==0) var2=var2*0.995;
                else if (k==6 && l2_decayMode==0){ 
                    var2=m_sv_UP; 
                    var1_1=pt_sv_UP;
                    mytau*=1.030; 
                    mymet=mymet-(0.030/1.030)*mytau;
                    if (numberJets==0)var2=(myele+mytau).M();
                }
                else if (k==7 && l2_decayMode==0) { 
                    var2=m_sv_DOWN; 
                    var1_1=pt_sv_DOWN;
                    mytau*=0.97; 
                    mymet=mymet+(0.030/0.97)*mytau;
                    if (numberJets==0) var2=(myele+mytau).M();
                }
                else if (k==8 && l2_decayMode==1){ 
                    var2=m_sv_UP;
                    var1_1=pt_sv_UP;
                    mytau*=1.030; 
                    mymet=mymet-(0.030/1.030)*mytau;
                    if (numberJets==0) var2=(myele+mytau).M();
                } 
                else if (k==9 && l2_decayMode==1) {
                    var2=m_sv_DOWN; 
                    var1_1=pt_sv_DOWN;
                    mytau*=0.97;
                    mymet=mymet+(0.030/0.97)*mytau;
                    if (numberJets==0) var2=(myele+mytau).M();
                }
                else if (k==9 && l2_decayMode==10){
                    var2=m_sv_UP;
                    var1_1=pt_sv_UP;
                    mytau*=1.030;
                    mymet=mymet-(0.030/1.030)*mytau;
                    if (numberJets==0) var2=(myele+mytau).M();
                }
                else if (k==11 && l2_decayMode==10) {
                    var2=m_sv_DOWN;
                    var1_1=pt_sv_DOWN;
                    mytau*=0.97;
                    mymet=mymet+(0.030/0.97)*mytau;
                    if (numberJets==0) var2=(myele+mytau).M();
                }

	    }

            if (mytau.Pt()<30) continue; 
            var1_0=l2_decayMode; 
	    var1_1=(myele+mytau+mymet).Pt();

            float mt=TMass_F(myele.Pt(),mymet.Pt(),myele.Px(),mymet.Px(),myele.Py(),mymet.Py());

            //************************ Z mumu scale factors **************************
            /*if (fabs(tes)!=13 && (sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL" or sample=="EWKZLL" or sample=="EWKZNuNu")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),0);
            if (tes==13 && (sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL" or sample=="EWKZLL" or sample=="EWKZNuNu")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),1);
            if (tes==-13 && (sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL" or sample=="EWKZLL" or sample=="EWKZNuNu")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),-1);*/

	    if (tes==16 && gen_match_2==5){
		if (k==0 && l2_decayMode==0) weight2=weight2*1.03;
	        else if (k==1 && l2_decayMode==0) weight2=weight2*0.97;
                else if (k==2 && l2_decayMode==1) weight2=weight2*1.03;
                else if (k==3 && l2_decayMode==1) weight2=weight2*0.97;
                else if (k==4 && l2_decayMode==10) weight2=weight2*1.03;
                else if (k==5 && l2_decayMode==10) weight2=weight2*0.97;
	    }

            if (tes==18 && sample=="ZL"){
                if (k==0 && l2_decayMode==0) weight2=weight2*1.12;
                else if (k==1 && l2_decayMode==0) weight2=weight2*0.88;
                else if (k==2 && l2_decayMode==1) weight2=weight2*1.12;
                else if (k==3 && l2_decayMode==1) weight2=weight2*0.88;
            }

            if (sample=="data_obs") aweight=1.0;

	    bool is_0jet=(numberJets==0);
	    bool is_boosted=(numberJets==1 or (numberJets>=2 && (massJets<=300 or var1_1<=50 or mytau.Pt()<=30)));
	    bool is_VBF=(massJets > 300 && numberJets>=2 && var1_1>50 && mytau.Pt()>30);// && var2>60 && var2<90);

	    //********************** High mT *************************

            if (q_1*q_2<0 && mt>80 && signalRegion){
                n70[k]->Fill(0.1,aweight*weight2);
                if (is_bveto && var2<400 && is_0jet) n70[k]->Fill(1.1,aweight*weight2*weight_btag);
                if (is_bveto && var2<300 && is_boosted) n70[k]->Fill(2.1,aweight*weight2*weight_btag);
                if (is_bveto && var2<400 && is_VBF) n70[k]->Fill(3.1,aweight*weight2*weight_btag);

            }

            if (q_1*q_2>0 && mt>80 && signalRegion){
                n70SS[k]->Fill(0.1,aweight*weight2);
                if (is_bveto && var2<400 && is_0jet) n70SS[k]->Fill(1.1,aweight*weight2*weight_btag);
                if (is_bveto && var2<300 && is_boosted) n70SS[k]->Fill(2.1,aweight*weight2*weight_btag);
                if (is_bveto && var2<400 && is_VBF) n70SS[k]->Fill(3.1,aweight*weight2*weight_btag);
            }
//cout<<weight_btag<<endl;
	    //************************** Actual filling *******************************
	    float antiratio=(sf_id_anti*sf_trg_anti)/(sf_id*sf_trg);

            if (qcdCR && q_1*q_2<0 && mt<50){
                if (is_0jet) h0_CR_QCD[k]->Fill(var2,aweight*weight2*antiratio);
                if (is_boosted) h1_CR_QCD[k]->Fill(var2,aweight*weight2*antiratio);
                if (is_VBF) h2_CR_QCD[k]->Fill(var2,aweight*weight2*antiratio);
            }

            if (signalRegion && q_1*q_2<0){
                if (is_bveto && var2<400 && is_0jet) h0_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_bveto && var2<300 && is_boosted) h1_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_bveto && var2<400 && is_VBF) h2_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
            }

            if (qcdCR && q_1*q_2>0 && mt<50){
                if (is_0jet) h0_CRSS_QCD[k]->Fill(var2,weight2*aweight*antiratio);
                if (is_boosted) h1_CRSS_QCD[k]->Fill(var2,weight2*aweight*antiratio);
                if (is_VBF) h2_CRSS_QCD[k]->Fill(var2,weight2*aweight*antiratio);
            }

            if (signalRegion && q_1*q_2>0){
                if (is_bveto && var2<400 && is_0jet) h0_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_bveto && var2<300 && is_boosted) h1_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_bveto && var2<400 && is_VBF) h2_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
            }

	    if (is_0jet && mt<50){
                if (tes==12) weight2=weight2*(0.9289 + 0.00017022*var1_0);
                if (tes==-12) weight2=weight2*(2-(0.9289 + 0.00017022*var1_0));
                if (genpT>150 and tes==22) weight2=weight2*(1+0.01*(0.114*genpT -17.14));
                if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
                if (signalRegion && q_1*q_2<0){
                    h0_OS[k]->Fill(var1_0,var2,aweight*weight2);

		   hmelaDCP_OS_0jet[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_OS_0jet[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_OS_0jet[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_OS_0jet[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_OS_0jet[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_OS_0jet[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);


		}

                if (signalRegion && q_1*q_2>0)
                    h0_SS[k]->Fill(var1_0,var2,aweight*weight2);
                if (wRegion && q_1*q_2<0)
                    h0_WOS[k]->Fill(var1_0,var2,aweight*weight2);
                if (wRegion && q_1*q_2>0)
                    h0_WSS[k]->Fill(var1_0,var2,aweight*weight2);
                if (qcdRegion && q_1*q_2>0)
                    h0_QCD[k]->Fill(var1_0,var2,aweight*weight2);

	    }

            if (is_boosted && mt<50){
                if (tes==12) weight2=weight2*(0.9195 + 0.0010055*var1_1);
                if (tes==-12) weight2=weight2*(2-(0.9195 + 0.0010055*var1_1));
                if (genpT>150 and tes==22) weight2=weight2*(1+0.01*(0.114*genpT -17.14));
                if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
                if (signalRegion && q_1*q_2<0){
                   h1_OS[k]->Fill(var1_1,var2,aweight*weight2);

		   hmelaDCP_OS_boosted[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_OS_boosted[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_OS_boosted[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_OS_boosted[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_OS_boosted[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_OS_boosted[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);

		}
                if (signalRegion && q_1*q_2>0)
                    h1_SS[k]->Fill(var1_1,var2,aweight*weight2);
                if (wRegion && q_1*q_2<0)
                    h1_WOS[k]->Fill(var1_1,var2,aweight*weight2);
                if (wRegion && q_1*q_2>0)
                    h1_WSS[k]->Fill(var1_1,var2,aweight*weight2);
                if (qcdRegion && q_1*q_2>0)
                    h1_QCD[k]->Fill(var1_1,var2,aweight*weight2);
            }
	    /*TLorentzVector myjet1;
            myjet1.SetPtEtaPhiM(jpt_1, jeta_1, jphi_1, 0);
            TLorentzVector myjet2;
            myjet2.SetPtEtaPhiM(jpt_2, jeta_2, jphi_2, 0);*/
	    float var_1D=(myele+mytau+mymet).Pt();
            if (is_VBF && mt<50){
                if (tes==12) weight2=weight2*(1.0258 + 0.00006596*var1_2);
                if (tes==-12) weight2=weight2*(2-(1.0258 + 0.00006596*var1_2));
                if (genpT>150 and tes==22) weight2=weight2*(1+0.01*(0.114*genpT -17.14));
                if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
                if (signalRegion && q_1*q_2<0){
                    h1D_OS[k]->Fill(var_1D,weight2*aweight);
                    h2_OS[k]->Fill(var1_2,var2,aweight*weight2);

		    hmelaDCP_OS_VBF[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_OS_VBF[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_OS_VBF[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_OS_VBF[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_OS_VBF[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_OS_VBF[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_OS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_OS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_OS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_OS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_OS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_OS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_OS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_OS[k]->Fill(mymet.Pt(),weight2*aweight);
		    
		
                    if (melaD0minus>=0.0 and melaD0minus<0.2)
                       h3_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.2 and melaD0minus<0.4)
                       h4_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.4 and melaD0minus<0.8)
                       h5_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.8 and melaD0minus<1.0)
                       h7_OS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCP<0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h33_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h34_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h35_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h37_OS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCP>=0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h43_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h44_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h45_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h47_OS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h53_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h54_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h55_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h57_OS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h63_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h64_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h65_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h67_OS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h73_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h74_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h75_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h77_OS[k]->Fill(var1_2,var2,weight2*aweight);

///////////////////ggH
//
                    //h2_dPhi_mvOS[k]->Fill(var1_3,var2,aweight*weight2);

                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h3_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h4_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h5_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h7_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h33_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h34_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h35_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h37_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h43_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h44_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h45_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h47_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h53_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h54_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h55_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h57_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h63_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h64_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h65_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h67_ggHOS[k]->Fill(var1_2,var2,weight2*aweight);


		  if (jphi_1>-pI-.05 && jphi_2>-pI-0.5){
                   double dPhi=  jphi_1 - jphi_2; //dPhiFrom2P( LeptV1.Px(), LeptV1.Py(), METV.Px(),  METV.Py() );
		if (dPhi > TMath::Pi()) dPhi -= 2*TMath::Pi();
  		if (dPhi <= -TMath::Pi()) dPhi += 2*TMath::Pi();
		//	cout<<" dPhi plain  "<<jphi_1-jphi_2<<"  "<<dPhi<<"  "<<fabs(dPhi)<<endl;
		if (dPhi>-TMath::Pi() && dPhi<-2.5)
			h3a_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-2.5 && dPhi<-2.)
			h3b_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-2 && dPhi<-1.5)
			h3c_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-1.5 && dPhi<-1.)
			h3d_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-1. && dPhi<-0.5)
			h3e_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-0.5 && dPhi<0.)
			h3f_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>0 && dPhi<0.5)
			h3g_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>0.5 && dPhi<1)
			h3h_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>1 && dPhi<1.5)
			h3i_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>1.5 && dPhi<2)
			h3j_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>2 && dPhi<2.5)
			h3k_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>2.5 && dPhi<TMath::Pi())
			h3l_dphi_OS[k]->Fill(var1_2,var2,weight2*aweight);
		  }

/////////////////

		}
                if (signalRegion && q_1*q_2>0){
                    h1D_SS[k]->Fill(var_1D,weight2*aweight);
                    h2_SS[k]->Fill(var1_2,var2,aweight*weight2);


		    hmelaDCP_SS_VBF[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_SS_VBF[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_SS_VBF[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_SS_VBF[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_SS_VBF[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_SS_VBF[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_SS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_SS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_SS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_SS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_SS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_SS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_SS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_SS[k]->Fill(mymet.Pt(),weight2*aweight);



                    if (melaD0minus>=0.0 and melaD0minus<0.2)
                       h3_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.2 and melaD0minus<0.4)
                       h4_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.4 and melaD0minus<0.8)
                       h5_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.8 and melaD0minus<1.0)
                       h7_SS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCP<0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h33_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h34_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h35_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h37_SS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCP>=0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h43_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h44_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h45_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h47_SS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h53_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h54_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h55_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h57_SS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h63_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h64_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h65_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h67_SS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h73_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h74_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h75_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h77_SS[k]->Fill(var1_2,var2,weight2*aweight);
//////////////ggH
//
                    //h2_dPhi_mvSS[k]->Fill(var1_3,var2,aweight*weight2);

                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h3_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h4_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h5_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h7_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h33_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h34_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h35_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h37_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h43_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h44_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h45_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h47_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h53_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h54_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h55_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h57_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h63_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h64_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h65_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h67_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);

		}
                if (wRegion && q_1*q_2<0){
                    h2_WOS[k]->Fill(var1_2,var2,aweight*weight2);
                    h1D_WOS[k]->Fill(var_1D,weight2*aweight);

		    hmelaDCP_WOS_VBF[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_WOS_VBF[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_WOS_VBF[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_WOS_VBF[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_WOS_VBF[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_WOS_VBF[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_WOS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_WOS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_WOS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_WOS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_WOS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_WOS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_WOS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_WOS[k]->Fill(mymet.Pt(),weight2*aweight);


                    if (melaD0minus>=0.0 and melaD0minus<0.2)
                       h3_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.2 and melaD0minus<0.4)
                       h4_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.4 and melaD0minus<0.8)
                       h5_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.8 and melaD0minus<1.0)
                       h7_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCP<0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h33_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h34_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h35_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h37_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCP>=0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h43_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h44_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h45_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h47_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h53_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h54_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h55_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h57_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h63_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h64_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h65_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h67_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h73_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h74_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h75_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h77_WOS[k]->Fill(var1_2,var2,weight2*aweight);

//////////ggH
//			
                    //h2_dPhi_mvWOS[k]->Fill(var1_3,var2,aweight*weight2);
                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h3_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h4_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h5_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h7_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h33_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h34_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h35_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h37_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h43_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h44_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h45_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h47_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h53_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h54_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h55_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h57_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h63_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h64_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h65_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h67_ggHWOS[k]->Fill(var1_2,var2,weight2*aweight);


		}
                if (wRegion && q_1*q_2>0){
                    h2_WSS[k]->Fill(var1_2,var2,aweight*weight2);
                    h1D_WSS[k]->Fill(var_1D,weight2*aweight);

		    hmelaDCP_WSS_VBF[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_WSS_VBF[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_WSS_VBF[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_WSS_VBF[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_WSS_VBF[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_WSS_VBF[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_WSS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_WSS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_WSS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_WSS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_WSS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_WSS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_WSS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_WSS[k]->Fill(mymet.Pt(),weight2*aweight);




                    if (melaD0minus>=0.0 and melaD0minus<0.2)
                       h3_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.2 and melaD0minus<0.4)
                       h4_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.4 and melaD0minus<0.8)
                       h5_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.8 and melaD0minus<1.0)
                       h7_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCP<0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h33_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h34_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h35_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h37_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCP>=0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h43_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h44_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h45_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h47_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h53_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h54_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h55_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h57_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h63_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h64_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h65_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h67_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h73_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h74_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h75_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h77_WSS[k]->Fill(var1_2,var2,weight2*aweight);

//////////////////
                    //h2_dPhi_mvWSS[k]->Fill(var1_3,var2,aweight*weight2);
                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h3_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h4_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h5_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h7_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h33_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h34_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h35_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h37_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h43_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h44_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h45_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h47_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h53_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h54_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h55_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h57_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h63_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h64_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h65_ggHWSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h67_ggHSS[k]->Fill(var1_2,var2,weight2*aweight);


		}
                if (qcdRegion && q_1*q_2>0){
                    h2_QCD[k]->Fill(var1_2,var2,aweight*weight2);
                    h1D_QCD[k]->Fill(var_1D,weight2*aweight);

		    hmelaDCP_QCD_VBF[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_QCD_VBF[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_QCD_VBF[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_QCD_VBF[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_QCD_VBF[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_QCD_VBF[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_QCD[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_QCD[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_QCD[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_QCD[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_QCD[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_QCD[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_QCD[k]->Fill(mjj,weight2*aweight);
		    h1D_met_QCD[k]->Fill(mymet.Pt(),weight2*aweight);





                    if (melaD0minus>=0.0 and melaD0minus<0.2)
                       h3_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.2 and melaD0minus<0.4)
                       h4_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.4 and melaD0minus<0.8)
                       h5_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minus>=0.8 and melaD0minus<1.0)
                       h7_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCP<0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h33_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h34_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h35_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP<0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h37_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCP>=0 and melaD0minus>=0.0 and melaD0minus<0.2)
                       h43_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.2 and melaD0minus<0.4)
                       h44_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.4 and melaD0minus<0.8)
                       h45_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCP>=0 and melaD0minus>=0.8 and melaD0minus<1.0)
                       h47_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h53_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h54_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h55_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h57_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0minus>=0.0 and melaDL1<0.2)
                       h63_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h64_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h65_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h67_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h73_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h74_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h75_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h77_QCD[k]->Fill(var1_2,var2,weight2*aweight);

/////////ggH
                    //h2_dPhi_mvQCD[k]->Fill(var1_3,var2,aweight*weight2);

                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h3_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h4_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h5_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h7_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h33_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h34_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h35_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h37_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h43_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h44_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h45_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h47_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h53_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h54_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h55_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h57_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h63_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h64_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h65_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h67_ggHQCD[k]->Fill(var1_2,var2,weight2*aweight);


		}
            }
	}
    } // end of loop over events

    for (int k=0; k<nbhist; ++k){



       h0_WOS[k]->Scale(h0_OS[k]->Integral()/h0_WOS[k]->Integral());
       h1_WOS[k]->Scale(h1_OS[k]->Integral()/h1_WOS[k]->Integral());
       h2_WOS[k]->Scale(h2_OS[k]->Integral()/h2_WOS[k]->Integral());
       h3_WOS[k]->Scale(h3_OS[k]->Integral()/h3_WOS[k]->Integral());
       h4_WOS[k]->Scale(h4_OS[k]->Integral()/h4_WOS[k]->Integral());
       h5_WOS[k]->Scale((0.000000001+h5_OS[k]->Integral())/(0.00000001+h5_WOS[k]->Integral()));
       h7_WOS[k]->Scale(h7_OS[k]->Integral()/h7_WOS[k]->Integral());
       h0_WSS[k]->Scale(h0_SS[k]->Integral()/h0_WSS[k]->Integral());
       h1_WSS[k]->Scale(h1_SS[k]->Integral()/h1_WSS[k]->Integral());
       h2_WSS[k]->Scale(h2_SS[k]->Integral()/h2_WSS[k]->Integral());
       h3_WSS[k]->Scale(h3_SS[k]->Integral()/h3_WSS[k]->Integral());
       h4_WSS[k]->Scale(h4_SS[k]->Integral()/h4_WSS[k]->Integral());
       h5_WSS[k]->Scale(h5_SS[k]->Integral()/h5_WSS[k]->Integral());
       h7_WSS[k]->Scale(h7_SS[k]->Integral()/h7_WSS[k]->Integral());

       h73_WOS[k]->Scale(h73_OS[k]->Integral()/(0.0000000001+h73_WOS[k]->Integral()));
       h74_WOS[k]->Scale(h74_OS[k]->Integral()/(0.0000000001+h74_WOS[k]->Integral()));
       h75_WOS[k]->Scale(h75_OS[k]->Integral()/(0.0000000001+h75_WOS[k]->Integral()));
       h77_WOS[k]->Scale(h77_OS[k]->Integral()/(0.0000000001+h77_WOS[k]->Integral()));
       h73_WSS[k]->Scale(h73_SS[k]->Integral()/(0.0000000001+h73_WSS[k]->Integral()));
       h74_WSS[k]->Scale(h74_SS[k]->Integral()/(0.0000000001+h74_WSS[k]->Integral()));
       h75_WSS[k]->Scale(h75_SS[k]->Integral()/(0.0000000001+h75_WSS[k]->Integral()));
       h77_WSS[k]->Scale(h77_SS[k]->Integral()/(0.0000000001+h77_WSS[k]->Integral()));

       h63_WOS[k]->Scale(h63_OS[k]->Integral()/(0.0000000001+h63_WOS[k]->Integral()));
       h64_WOS[k]->Scale(h64_OS[k]->Integral()/(0.0000000001+h64_WOS[k]->Integral()));
       h65_WOS[k]->Scale(h65_OS[k]->Integral()/(0.0000000001+h65_WOS[k]->Integral()));
       h67_WOS[k]->Scale(h67_OS[k]->Integral()/(0.0000000001+h67_WOS[k]->Integral()));
       h63_WSS[k]->Scale(h63_SS[k]->Integral()/(0.0000000001+h63_WSS[k]->Integral()));
       h64_WSS[k]->Scale(h64_SS[k]->Integral()/(0.0000000001+h64_WSS[k]->Integral()));
       h65_WSS[k]->Scale(h65_SS[k]->Integral()/(0.0000000001+h65_WSS[k]->Integral()));
       h67_WSS[k]->Scale(h67_SS[k]->Integral()/(0.0000000001+h67_WSS[k]->Integral()));

       h53_WOS[k]->Scale(h53_OS[k]->Integral()/(0.0000000001+h53_WOS[k]->Integral()));
       h54_WOS[k]->Scale(h54_OS[k]->Integral()/(0.0000000001+h54_WOS[k]->Integral()));
       h55_WOS[k]->Scale(h55_OS[k]->Integral()/(0.0000000001+h55_WOS[k]->Integral()));
       h57_WOS[k]->Scale(h57_OS[k]->Integral()/(0.0000000001+h57_WOS[k]->Integral()));
       h53_WSS[k]->Scale(h53_SS[k]->Integral()/(0.0000000001+h53_WSS[k]->Integral()));
       h54_WSS[k]->Scale(h54_SS[k]->Integral()/(0.0000000001+h54_WSS[k]->Integral()));
       h55_WSS[k]->Scale(h55_SS[k]->Integral()/(0.0000000001+h55_WSS[k]->Integral()));
       h57_WSS[k]->Scale(h57_SS[k]->Integral()/(0.0000000001+h57_WSS[k]->Integral()));

       h43_WOS[k]->Scale(h43_OS[k]->Integral()/(0.0000000001+h43_WOS[k]->Integral()));
       h44_WOS[k]->Scale(h44_OS[k]->Integral()/(0.0000000001+h44_WOS[k]->Integral()));
       h45_WOS[k]->Scale(h45_OS[k]->Integral()/(0.0000000001+h45_WOS[k]->Integral()));
       h47_WOS[k]->Scale(h47_OS[k]->Integral()/(0.0000000001+h47_WOS[k]->Integral()));
       h43_WSS[k]->Scale(h43_SS[k]->Integral()/(0.0000000001+h43_WSS[k]->Integral()));
       h44_WSS[k]->Scale(h44_SS[k]->Integral()/(0.0000000001+h44_WSS[k]->Integral()));
       h45_WSS[k]->Scale(h45_SS[k]->Integral()/(0.0000000001+h45_WSS[k]->Integral()));
       h47_WSS[k]->Scale(h47_SS[k]->Integral()/(0.0000000001+h47_WSS[k]->Integral()));

       h33_WOS[k]->Scale(h33_OS[k]->Integral()/(0.0000000001+h33_WOS[k]->Integral()));
       h34_WOS[k]->Scale(h34_OS[k]->Integral()/(0.0000000001+h34_WOS[k]->Integral()));
       h35_WOS[k]->Scale(h35_OS[k]->Integral()/(0.0000000001+h35_WOS[k]->Integral()));
       h37_WOS[k]->Scale(h37_OS[k]->Integral()/(0.0000000001+h37_WOS[k]->Integral()));
       h33_WSS[k]->Scale(h33_SS[k]->Integral()/(0.0000000001+h33_WSS[k]->Integral()));
       h34_WSS[k]->Scale(h34_SS[k]->Integral()/(0.0000000001+h34_WSS[k]->Integral()));
       h35_WSS[k]->Scale(h35_SS[k]->Integral()/(0.0000000001+h35_WSS[k]->Integral()));
       h37_WSS[k]->Scale(h37_SS[k]->Integral()/(0.0000000001+h37_WSS[k]->Integral()));

///ggH
       h0_ggHWOS[k]->Scale(h0_ggHOS[k]->Integral()/h0_ggHWOS[k]->Integral());
       h1_ggHWOS[k]->Scale(h1_ggHOS[k]->Integral()/h1_ggHWOS[k]->Integral());
//       h2_dPhi_mvWOS[k]->Scale(h2_dPhi_mvOS[k]->Integral()/h2_dPhi_mvWOS[k]->Integral());
       h3_ggHWOS[k]->Scale(h3_ggHOS[k]->Integral()/h3_ggHWOS[k]->Integral());
       h4_ggHWOS[k]->Scale(h4_ggHOS[k]->Integral()/h4_ggHWOS[k]->Integral());
       h5_ggHWOS[k]->Scale((0.000000001+h5_ggHOS[k]->Integral())/(0.00000001+h5_ggHWOS[k]->Integral()));
       h7_ggHWOS[k]->Scale(h7_ggHOS[k]->Integral()/h7_ggHWOS[k]->Integral());
       h0_ggHWSS[k]->Scale(h0_ggHSS[k]->Integral()/h0_ggHWSS[k]->Integral());
       h1_ggHWSS[k]->Scale(h1_ggHSS[k]->Integral()/h1_ggHWSS[k]->Integral());
//       h2_dPhi_mvWSS[k]->Scale(h2_dPhi_mvSS[k]->Integral()/h2_dPhi_mvWSS[k]->Integral());
       h3_ggHWSS[k]->Scale(h3_ggHSS[k]->Integral()/h3_ggHWSS[k]->Integral());
       h4_ggHWSS[k]->Scale(h4_ggHSS[k]->Integral()/h4_ggHWSS[k]->Integral());
       h5_ggHWSS[k]->Scale(h5_ggHSS[k]->Integral()/h5_ggHWSS[k]->Integral());
       h7_ggHWSS[k]->Scale(h7_ggHSS[k]->Integral()/h7_ggHWSS[k]->Integral());


       h63_ggHWOS[k]->Scale(h63_ggHOS[k]->Integral()/(0.0000000001+h63_ggHWOS[k]->Integral()));
       h64_ggHWOS[k]->Scale(h64_ggHOS[k]->Integral()/(0.0000000001+h64_ggHWOS[k]->Integral()));
       h65_ggHWOS[k]->Scale(h65_ggHOS[k]->Integral()/(0.0000000001+h65_ggHWOS[k]->Integral()));
       h67_ggHWOS[k]->Scale(h67_ggHOS[k]->Integral()/(0.0000000001+h67_ggHWOS[k]->Integral()));
       h63_ggHWSS[k]->Scale(h63_ggHSS[k]->Integral()/(0.0000000001+h63_ggHWSS[k]->Integral()));
       h64_ggHWSS[k]->Scale(h64_ggHSS[k]->Integral()/(0.0000000001+h64_ggHWSS[k]->Integral()));
       h65_ggHWSS[k]->Scale(h65_ggHSS[k]->Integral()/(0.0000000001+h65_ggHWSS[k]->Integral()));
       h67_ggHWSS[k]->Scale(h67_ggHSS[k]->Integral()/(0.0000000001+h67_ggHWSS[k]->Integral()));

       h53_ggHWOS[k]->Scale(h53_ggHOS[k]->Integral()/(0.0000000001+h53_ggHWOS[k]->Integral()));
       h54_ggHWOS[k]->Scale(h54_ggHOS[k]->Integral()/(0.0000000001+h54_ggHWOS[k]->Integral()));
       h55_ggHWOS[k]->Scale(h55_ggHOS[k]->Integral()/(0.0000000001+h55_ggHWOS[k]->Integral()));
       h57_ggHWOS[k]->Scale(h57_ggHOS[k]->Integral()/(0.0000000001+h57_ggHWOS[k]->Integral()));
       h53_ggHWSS[k]->Scale(h53_ggHSS[k]->Integral()/(0.0000000001+h53_ggHWSS[k]->Integral()));
       h54_ggHWSS[k]->Scale(h54_ggHSS[k]->Integral()/(0.0000000001+h54_ggHWSS[k]->Integral()));
       h55_ggHWSS[k]->Scale(h55_ggHSS[k]->Integral()/(0.0000000001+h55_ggHWSS[k]->Integral()));
       h57_ggHWSS[k]->Scale(h57_ggHSS[k]->Integral()/(0.0000000001+h57_ggHWSS[k]->Integral()));

       h43_ggHWOS[k]->Scale(h43_ggHOS[k]->Integral()/(0.0000000001+h43_ggHWOS[k]->Integral()));
       h44_ggHWOS[k]->Scale(h44_ggHOS[k]->Integral()/(0.0000000001+h44_ggHWOS[k]->Integral()));
       h45_ggHWOS[k]->Scale(h45_ggHOS[k]->Integral()/(0.0000000001+h45_ggHWOS[k]->Integral()));
       h47_ggHWOS[k]->Scale(h47_ggHOS[k]->Integral()/(0.0000000001+h47_ggHWOS[k]->Integral()));
       h43_ggHWSS[k]->Scale(h43_ggHSS[k]->Integral()/(0.0000000001+h43_ggHWSS[k]->Integral()));
       h44_ggHWSS[k]->Scale(h44_ggHSS[k]->Integral()/(0.0000000001+h44_ggHWSS[k]->Integral()));
       h45_ggHWSS[k]->Scale(h45_ggHSS[k]->Integral()/(0.0000000001+h45_ggHWSS[k]->Integral()));
       h47_ggHWSS[k]->Scale(h47_ggHSS[k]->Integral()/(0.0000000001+h47_ggHWSS[k]->Integral()));

       h33_ggHWOS[k]->Scale(h33_ggHOS[k]->Integral()/(0.0000000001+h33_ggHWOS[k]->Integral()));
       h34_ggHWOS[k]->Scale(h34_ggHOS[k]->Integral()/(0.0000000001+h34_ggHWOS[k]->Integral()));
       h35_ggHWOS[k]->Scale(h35_ggHOS[k]->Integral()/(0.0000000001+h35_ggHWOS[k]->Integral()));
       h37_ggHWOS[k]->Scale(h37_ggHOS[k]->Integral()/(0.0000000001+h37_ggHWOS[k]->Integral()));
       h33_ggHWSS[k]->Scale(h33_ggHSS[k]->Integral()/(0.0000000001+h33_ggHWSS[k]->Integral()));
       h34_ggHWSS[k]->Scale(h34_ggHSS[k]->Integral()/(0.0000000001+h34_ggHWSS[k]->Integral()));
       h35_ggHWSS[k]->Scale(h35_ggHSS[k]->Integral()/(0.0000000001+h35_ggHWSS[k]->Integral()));
       h37_ggHWSS[k]->Scale(h37_ggHSS[k]->Integral()/(0.0000000001+h37_ggHWSS[k]->Integral()));
////////
///dPhi
/*

       h3a_dphi_WOS[k]->Scale(h3a_dphi_OS[k]->Integral()/h3a_dphi_WOS[k]->Integral());
       h3b_dphi_WOS[k]->Scale(h3b_dphi_OS[k]->Integral()/h3b_dphi_WOS[k]->Integral());
       h3c_dphi_WOS[k]->Scale(h3c_dphi_OS[k]->Integral()/h3c_dphi_WOS[k]->Integral());
       h3d_dphi_WOS[k]->Scale(h3d_dphi_OS[k]->Integral()/h3d_dphi_WOS[k]->Integral());
       h3e_dphi_WOS[k]->Scale(h3e_dphi_OS[k]->Integral()/h3e_dphi_WOS[k]->Integral());
       h3f_dphi_WOS[k]->Scale(h3f_dphi_OS[k]->Integral()/h3f_dphi_WOS[k]->Integral());
       h3g_dphi_WOS[k]->Scale(h3g_dphi_OS[k]->Integral()/h3g_dphi_WOS[k]->Integral());
       h3h_dphi_WOS[k]->Scale(h3h_dphi_OS[k]->Integral()/h3h_dphi_WOS[k]->Integral());
       h3i_dphi_WOS[k]->Scale(h3u_dphi_OS[k]->Integral()/h3i_dphi_WOS[k]->Integral());
       h3j_dphi_WOS[k]->Scale(h3j_dphi_OS[k]->Integral()/h3j_dphi_WOS[k]->Integral());
       h3k_dphi_WOS[k]->Scale(h3k_dphi_OS[k]->Integral()/h3k_dphi_WOS[k]->Integral());
       h3l_dphi_WOS[k]->Scale(h3l_dphi_OS[k]->Integral()/h3l_dphi_WOS[k]->Integral());
       h3m_dphi_WOS[k]->Scale(h3m_dphi_OS[k]->Integral()/h3m_dphi_WOS[k]->Integral());
       h3n_dphi_WOS[k]->Scale(h3n_dphi_OS[k]->Integral()/h3n_dphi_WOS[k]->Integral());
*/


    }

    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    //n70->Write();
    //n70SS->Write();
    nlowhigh->Write();

    TString postfix="";
    if (tes==1)
	postfix="_CMS_scale_t_et_13TeVUp";
    if (tes==-1)
        postfix="_CMS_scale_t_et_13TeVDown";
    if (tes==15)
        postfix="_CMS_htt_ZLShape_et_13TeVUp";
    if (tes==-15)
        postfix="_CMS_htt_ZLShape_et_13TeVDown";
    if (tes==3)
        postfix="_CMS_scale_met_13TeVUp";
    if (tes==-3)
        postfix="_CMS_scale_met_13TeVDown";
    if (tes==100)
        postfix="_CMS_scale_j_13TeVUp";
    if (tes==-100)
        postfix="_CMS_scale_j_13TeVDown";
    if (tes==12)
        postfix="_CMS_scale_gg_13TeVUp";
    if (tes==-12)
        postfix="_CMS_scale_gg_13TeVDown";
    if (tes==22)
        postfix="_TopMassTreatment_13TeVUp";
    if (tes==-22)
        postfix="_TopMassTreatment_13TeVDown";
    if (tes==11)
        postfix="_CMS_htt_ttbarShape_13TeVUp";
    if (tes==-11)
        postfix="_CMS_htt_ttbarShape_13TeVDown";
    if (tes==-13)
        postfix="_CMS_htt_zmumuShape_VBF_13TeVDown";
    if (tes==13)
        postfix="_CMS_htt_zmumuShape_VBF_13TeVUp";
    if (tes==-20)
        postfix="_CMS_htt_zmumuShape_VBF_13TeVDown";
    if (tes==20)
        postfix="_CMS_htt_zmumuShape_VBF_13TeVUp";
    if (tes==10)
        postfix="_CMS_htt_dyShape_13TeVUp";
    if (tes==-10)
        postfix="_CMS_htt_dyShape_13TeVDown";
    if (tes==-14)
        postfix="_CMS_htt_jetToTauFake_13TeVDown";
    if (tes==14)
        postfix="_CMS_htt_jetToTauFake_13TeVUp";

    TDirectory *CRQCD0jet =fout->mkdir("et_antiiso_0jet_cr");
    TDirectory *CRQCD1jet =fout->mkdir("et_antiiso_boosted_cr");
    TDirectory *CRQCD2jet =fout->mkdir("et_antiiso_vbf_cr");
    TDirectory *CRW0jet =fout->mkdir("et_wjets_0jet_cr");
    TDirectory *CRW1jet =fout->mkdir("et_wjets_boosted_cr");
    TDirectory *CRW2jet =fout->mkdir("et_wjets_vbf_cr");
    TDirectory *CRSSQCD0jet =fout->mkdir("et_antiiso_0jet_crSS");
    TDirectory *CRSSQCD1jet =fout->mkdir("et_antiiso_boosted_crSS");
    TDirectory *CRSSQCD2jet =fout->mkdir("et_antiiso_vbf_crSS");
    TDirectory *CRSSW0jet =fout->mkdir("et_wjets_0jet_crSS");
    TDirectory *CRSSW1jet =fout->mkdir("et_wjets_boosted_crSS");
    TDirectory *CRSSW2jet =fout->mkdir("et_wjets_vbf_crSS");
    TDirectory *OS0jet =fout->mkdir("et_0jet");
    TDirectory *SS0jet =fout->mkdir("SS0jet");
    TDirectory *QCD0jet =fout->mkdir("QCD0jet");
    TDirectory *OS1jet =fout->mkdir("et_boosted");
    TDirectory *SS1jet =fout->mkdir("SS1jet");
    TDirectory *QCD1jet =fout->mkdir("QCD1jet");
    TDirectory *OS2jet =fout->mkdir("et_vbf");
    TDirectory *SS2jet =fout->mkdir("SSvbf");
    TDirectory *QCD2jet =fout->mkdir("QCDvbf");

    TDirectory *OS3jet =fout->mkdir("et_vbf_D0_0p0to0p2");
    TDirectory *SS3jet =fout->mkdir("SS3");
    TDirectory *QCD3jet =fout->mkdir("QCD3");
    TDirectory *OS4jet =fout->mkdir("et_vbf_D0_0p2to0p4");
    TDirectory *SS4jet =fout->mkdir("SS4");
    TDirectory *QCD4jet =fout->mkdir("QCD4");
    TDirectory *OS5jet =fout->mkdir("et_vbf_D0_0p4to0p8");
    TDirectory *SS5jet =fout->mkdir("SS5");
    TDirectory *QCD5jet =fout->mkdir("QCD5");
    TDirectory *OS7jet =fout->mkdir("et_vbf_D0_0p8to1p0");
    TDirectory *SS7jet =fout->mkdir("SS7");
    TDirectory *QCD7jet =fout->mkdir("QCD7");

    TDirectory *OS33jet =fout->mkdir("et_vbf_D0_0p0to0p2_DCPm");
    TDirectory *SS33jet =fout->mkdir("SS33");
    TDirectory *QCD33jet =fout->mkdir("QCD33");
    TDirectory *OS34jet =fout->mkdir("et_vbf_D0_0p2to0p4_DCPm");
    TDirectory *SS34jet =fout->mkdir("SS34");
    TDirectory *QCD34jet =fout->mkdir("QCD34");
    TDirectory *OS35jet =fout->mkdir("et_vbf_D0_0p4to0p8_DCPm");
    TDirectory *SS35jet =fout->mkdir("SS35");
    TDirectory *QCD35jet =fout->mkdir("QCD35");
    TDirectory *OS37jet =fout->mkdir("et_vbf_D0_0p8to1p0_DCPm");
    TDirectory *SS37jet =fout->mkdir("SS37");
    TDirectory *QCD37jet =fout->mkdir("QCD37");

    TDirectory *OS43jet =fout->mkdir("et_vbf_D0_0p0to0p2_DCPp");
    TDirectory *SS43jet =fout->mkdir("SS43");
    TDirectory *QCD43jet =fout->mkdir("QCD43");
    TDirectory *OS44jet =fout->mkdir("et_vbf_D0_0p2to0p4_DCPp");
    TDirectory *SS44jet =fout->mkdir("SS44");
    TDirectory *QCD44jet =fout->mkdir("QCD44");
    TDirectory *OS45jet =fout->mkdir("et_vbf_D0_0p4to0p8_DCPp");
    TDirectory *SS45jet =fout->mkdir("SS45");
    TDirectory *QCD45jet =fout->mkdir("QCD45");
    TDirectory *OS47jet =fout->mkdir("et_vbf_D0_0p8to1p0_DCPp");
    TDirectory *SS47jet =fout->mkdir("SS47");
    TDirectory *QCD47jet =fout->mkdir("QCD47");

    TDirectory *OS53jet =fout->mkdir("et_vbf_D0hplus_0p0to0p2");
    TDirectory *SS53jet =fout->mkdir("SS53");
    TDirectory *QCD53jet =fout->mkdir("QCD53");
    TDirectory *OS54jet =fout->mkdir("et_vbf_D0hplus_0p2to0p4");
    TDirectory *SS54jet =fout->mkdir("SS54");
    TDirectory *QCD54jet =fout->mkdir("QCD54");
    TDirectory *OS55jet =fout->mkdir("et_vbf_D0hplus_0p4to0p8");
    TDirectory *SS55jet =fout->mkdir("SS55");
    TDirectory *QCD55jet =fout->mkdir("QCD55");
    TDirectory *OS57jet =fout->mkdir("et_vbf_D0hplus_0p8to1p0");
    TDirectory *SS57jet =fout->mkdir("SS57");
    TDirectory *QCD57jet =fout->mkdir("QCD57");

    TDirectory *OS63jet =fout->mkdir("et_vbf_DL1_0p0to0p2");
    TDirectory *SS63jet =fout->mkdir("SS63");
    TDirectory *QCD63jet =fout->mkdir("QCD63");
    TDirectory *OS64jet =fout->mkdir("et_vbf_DL1_0p2to0p4");
    TDirectory *SS64jet =fout->mkdir("SS64");
    TDirectory *QCD64jet =fout->mkdir("QCD64");
    TDirectory *OS65jet =fout->mkdir("et_vbf_DL1_0p4to0p8");
    TDirectory *SS65jet =fout->mkdir("SS65");
    TDirectory *QCD65jet =fout->mkdir("QCD65");
    TDirectory *OS67jet =fout->mkdir("et_vbf_DL1_0p8to1p0");
    TDirectory *SS67jet =fout->mkdir("SS67");
    TDirectory *QCD67jet =fout->mkdir("QCD67");

    TDirectory *OS73jet =fout->mkdir("et_vbf_DL1Zg_0p0to0p2");
    TDirectory *SS73jet =fout->mkdir("SS73");
    TDirectory *QCD73jet =fout->mkdir("QCD73");
    TDirectory *OS74jet =fout->mkdir("et_vbf_DL1Zg_0p2to0p4");
    TDirectory *SS74jet =fout->mkdir("SS74");
    TDirectory *QCD74jet =fout->mkdir("QCD74");
    TDirectory *OS75jet =fout->mkdir("et_vbf_DL1Zg_0p4to0p8");
    TDirectory *SS75jet =fout->mkdir("SS75");
    TDirectory *QCD75jet =fout->mkdir("QCD75");
    TDirectory *OS77jet =fout->mkdir("et_vbf_DL1Zg_0p8to1p0");
    TDirectory *SS77jet =fout->mkdir("SS77");
    TDirectory *QCD77jet =fout->mkdir("QCD77");

    TDirectory *OScontrol = fout->mkdir("OS_control");
    TDirectory *SScontrol = fout->mkdir("SScontrol");
    TDirectory *QCDcontrol = fout->mkdir("QCDcontrol");

    for (int k=0; k<nbhist; ++k){
	if (tes==100) postfix=postfixJES[k];
        if (tes==1) postfix=postfixTES[k];
        if (tes==16) postfix=postfixDM[k];
        if (tes==17) postfix=postfixZLshape[k];
        if (tes==18) postfix=postfixZLnorm[k];
	fout->cd();
	n70[k]->SetName("n70"+postfix);
        n70[k]->Write();
        n70SS[k]->SetName("n70SS"+postfix);
        n70SS[k]->Write();
    }

    for (int k=0; k<nbhist; ++k){

       if (tes==100) postfix=postfixJES[k];
       if (tes==1) postfix=postfixTES[k];
       if (tes==16) postfix=postfixDM[k];
       if (tes==17) postfix=postfixZLshape[k];
       if (tes==18) postfix=postfixZLnorm[k];

       CRQCD0jet->cd();
       h0_CR_QCD[k]->SetName(name.c_str()+postfix);
       h0_CR_QCD[k]->Write();

       CRQCD1jet->cd();
       h1_CR_QCD[k]->SetName(name.c_str()+postfix);
       h1_CR_QCD[k]->Write();

       CRQCD2jet->cd();
       h2_CR_QCD[k]->SetName(name.c_str()+postfix);
       h2_CR_QCD[k]->Write();

       CRW0jet->cd();
       h0_CR_W[k]->SetName(name.c_str()+postfix);
       h0_CR_W[k]->Write();

       CRW1jet->cd();
       h1_CR_W[k]->SetName(name.c_str()+postfix);
       h1_CR_W[k]->Write();

       CRW2jet->cd();
       h2_CR_W[k]->SetName(name.c_str()+postfix);
       h2_CR_W[k]->Write();

       CRSSQCD0jet->cd();
       h0_CRSS_QCD[k]->SetName(name.c_str()+postfix);
       h0_CRSS_QCD[k]->Write();

       CRSSQCD1jet->cd();
       h1_CRSS_QCD[k]->SetName(name.c_str()+postfix);
       h1_CRSS_QCD[k]->Write();

       CRSSQCD2jet->cd();
       h2_CRSS_QCD[k]->SetName(name.c_str()+postfix);
       h2_CRSS_QCD[k]->Write();

       CRSSW0jet->cd();
       h0_CRSS_W[k]->SetName(name.c_str()+postfix);
       h0_CRSS_W[k]->Write();

       CRSSW1jet->cd();
       h1_CRSS_W[k]->SetName(name.c_str()+postfix);
       h1_CRSS_W[k]->Write();

       CRSSW2jet->cd();
       h2_CRSS_W[k]->SetName(name.c_str()+postfix);
       h2_CRSS_W[k]->Write();
    }

    for (int k=0; k<nbhist; ++k){
        if (tes==100) postfix=postfixJES[k];
        if (tes==1) postfix=postfixTES[k];
        if (tes==16) postfix=postfixDM[k];
        if (tes==17) postfix=postfixZLshape[k];
        if (tes==18) postfix=postfixZLnorm[k];

        for (int nn=1; nn<h0_OS[k]->GetSize()-1; ++nn){
           if (h0_OS[k]->GetBinContent(nn)<0) h0_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_OS_0jet[k]->GetBinContent(nn)<0) hmelaDCP_OS_0jet[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_OS_0jet[k]->GetBinContent(nn)<0) hmelaDCPggH_OS_0jet[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_OS_0jet[k]->GetBinContent(nn)<0) hmelaD0minus_OS_0jet[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_OS_0jet[k]->GetBinContent(nn)<0) hmelaD0minusggH_OS_0jet[k]->SetBinContent(nn,0.00001);

           if (h0_SS[k]->GetBinContent(nn)<0) h0_SS[k]->SetBinContent(nn,0.00001);
           if (h0_QCD[k]->GetBinContent(nn)<0) h0_QCD[k]->SetBinContent(nn,0.00001);
           if (h0_WOS[k]->GetBinContent(nn)<0) h0_WOS[k]->SetBinContent(nn,0.00001);
           if (h0_WSS[k]->GetBinContent(nn)<0) h0_WSS[k]->SetBinContent(nn,0.00001);

           if (h1_OS[k]->GetBinContent(nn)<0) h1_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_OS_boosted[k]->GetBinContent(nn)<0) hmelaDCP_OS_boosted[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_OS_boosted[k]->GetBinContent(nn)<0) hmelaDCPggH_OS_boosted[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_OS_boosted[k]->GetBinContent(nn)<0) hmelaD0minus_OS_boosted[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_OS_boosted[k]->GetBinContent(nn)<0) hmelaD0minusggH_OS_boosted[k]->SetBinContent(nn,0.00001);

           if (h1_SS[k]->GetBinContent(nn)<0) h1_SS[k]->SetBinContent(nn,0.00001);
           if (h1_QCD[k]->GetBinContent(nn)<0) h1_QCD[k]->SetBinContent(nn,0.00001);
           if (h1_WOS[k]->GetBinContent(nn)<0) h1_WOS[k]->SetBinContent(nn,0.00001);
           if (h1_WSS[k]->GetBinContent(nn)<0) h1_WSS[k]->SetBinContent(nn,0.00001);

           if (h2_OS[k]->GetBinContent(nn)<0) h2_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_OS_VBF[k]->GetBinContent(nn)<0) hmelaDCP_OS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_OS_VBF[k]->GetBinContent(nn)<0) hmelaDCPggH_OS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_OS_VBF[k]->GetBinContent(nn)<0) hmelaD0minus_OS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_OS_VBF[k]->GetBinContent(nn)<0) hmelaD0minusggH_OS_VBF[k]->SetBinContent(nn,0.00001);

           if (h2_SS[k]->GetBinContent(nn)<0) h2_SS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_SS_VBF[k]->GetBinContent(nn)<0) hmelaDCP_SS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_SS_VBF[k]->GetBinContent(nn)<0) hmelaDCPggH_SS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_SS_VBF[k]->GetBinContent(nn)<0) hmelaD0minus_SS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_SS_VBF[k]->GetBinContent(nn)<0) hmelaD0minusggH_SS_VBF[k]->SetBinContent(nn,0.00001);

           if (h2_QCD[k]->GetBinContent(nn)<0) h2_QCD[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_QCD_VBF[k]->GetBinContent(nn)<0) hmelaDCP_QCD_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_QCD_VBF[k]->GetBinContent(nn)<0) hmelaDCPggH_QCD_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_QCD_VBF[k]->GetBinContent(nn)<0) hmelaD0minus_QCD_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_QCD_VBF[k]->GetBinContent(nn)<0) hmelaD0minusggH_QCD_VBF[k]->SetBinContent(nn,0.00001);
           
	   if (h2_WOS[k]->GetBinContent(nn)<0) h2_WOS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_WOS_VBF[k]->GetBinContent(nn)<0) hmelaDCP_WOS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_WOS_VBF[k]->GetBinContent(nn)<0) hmelaDCPggH_WOS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_WOS_VBF[k]->GetBinContent(nn)<0) hmelaD0minus_WOS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_WOS_VBF[k]->GetBinContent(nn)<0) hmelaD0minusggH_WOS_VBF[k]->SetBinContent(nn,0.00001);
           
	   if (h2_WSS[k]->GetBinContent(nn)<0) h2_WSS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_WSS_VBF[k]->GetBinContent(nn)<0) hmelaDCP_WSS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_WSS_VBF[k]->GetBinContent(nn)<0) hmelaDCPggH_WSS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_WSS_VBF[k]->GetBinContent(nn)<0) hmelaD0minus_WSS_VBF[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_WSS_VBF[k]->GetBinContent(nn)<0) hmelaD0minusggH_WSS_VBF[k]->SetBinContent(nn,0.00001);

           if (h3_OS[k]->GetBinContent(nn)<0) h3_OS[k]->SetBinContent(nn,0.00001);
           if (h3_SS[k]->GetBinContent(nn)<0) h3_SS[k]->SetBinContent(nn,0.00001);
           if (h3_QCD[k]->GetBinContent(nn)<0) h3_QCD[k]->SetBinContent(nn,0.00001);
           if (h3_WOS[k]->GetBinContent(nn)<0) h3_WOS[k]->SetBinContent(nn,0.00001);
           if (h3_WSS[k]->GetBinContent(nn)<0) h3_WSS[k]->SetBinContent(nn,0.00001);
           if (h4_OS[k]->GetBinContent(nn)<0) h4_OS[k]->SetBinContent(nn,0.00001);
           if (h4_SS[k]->GetBinContent(nn)<0) h4_SS[k]->SetBinContent(nn,0.00001);
           if (h4_QCD[k]->GetBinContent(nn)<0) h4_QCD[k]->SetBinContent(nn,0.00001);
           if (h4_WOS[k]->GetBinContent(nn)<0) h4_WOS[k]->SetBinContent(nn,0.00001);
           if (h4_WSS[k]->GetBinContent(nn)<0) h4_WSS[k]->SetBinContent(nn,0.00001);
           if (h5_OS[k]->GetBinContent(nn)<0) h5_OS[k]->SetBinContent(nn,0.00001);
           if (h5_SS[k]->GetBinContent(nn)<0) h5_SS[k]->SetBinContent(nn,0.00001);
           if (h5_QCD[k]->GetBinContent(nn)<0) h5_QCD[k]->SetBinContent(nn,0.00001);
           if (h5_WOS[k]->GetBinContent(nn)<0) h5_WOS[k]->SetBinContent(nn,0.00001);
           if (h5_WSS[k]->GetBinContent(nn)<0) h5_WSS[k]->SetBinContent(nn,0.00001);
           if (h7_OS[k]->GetBinContent(nn)<0) h7_OS[k]->SetBinContent(nn,0.00001);
           if (h7_SS[k]->GetBinContent(nn)<0) h7_SS[k]->SetBinContent(nn,0.00001);
           if (h7_QCD[k]->GetBinContent(nn)<0) h7_QCD[k]->SetBinContent(nn,0.00001);
           if (h7_WOS[k]->GetBinContent(nn)<0) h7_WOS[k]->SetBinContent(nn,0.00001);
           if (h7_WSS[k]->GetBinContent(nn)<0) h7_WSS[k]->SetBinContent(nn,0.00001);

           if (h33_OS[k]->GetBinContent(nn)<0) h33_OS[k]->SetBinContent(nn,0.00001);
           if (h33_SS[k]->GetBinContent(nn)<0) h33_SS[k]->SetBinContent(nn,0.00001);
           if (h33_QCD[k]->GetBinContent(nn)<0) h33_QCD[k]->SetBinContent(nn,0.00001);
           if (h33_WOS[k]->GetBinContent(nn)<0) h33_WOS[k]->SetBinContent(nn,0.00001);
           if (h33_WSS[k]->GetBinContent(nn)<0) h33_WSS[k]->SetBinContent(nn,0.00001);
           if (h34_OS[k]->GetBinContent(nn)<0) h34_OS[k]->SetBinContent(nn,0.00001);
           if (h34_SS[k]->GetBinContent(nn)<0) h34_SS[k]->SetBinContent(nn,0.00001);
           if (h34_QCD[k]->GetBinContent(nn)<0) h34_QCD[k]->SetBinContent(nn,0.00001);
           if (h34_WOS[k]->GetBinContent(nn)<0) h34_WOS[k]->SetBinContent(nn,0.00001);
           if (h34_WSS[k]->GetBinContent(nn)<0) h34_WSS[k]->SetBinContent(nn,0.00001);
           if (h35_OS[k]->GetBinContent(nn)<0) h35_OS[k]->SetBinContent(nn,0.00001);
           if (h35_SS[k]->GetBinContent(nn)<0) h35_SS[k]->SetBinContent(nn,0.00001);
           if (h35_QCD[k]->GetBinContent(nn)<0) h35_QCD[k]->SetBinContent(nn,0.00001);
           if (h35_WOS[k]->GetBinContent(nn)<0) h35_WOS[k]->SetBinContent(nn,0.00001);
           if (h35_WSS[k]->GetBinContent(nn)<0) h35_WSS[k]->SetBinContent(nn,0.00001);
           if (h37_OS[k]->GetBinContent(nn)<0) h37_OS[k]->SetBinContent(nn,0.00001);
           if (h37_SS[k]->GetBinContent(nn)<0) h37_SS[k]->SetBinContent(nn,0.00001);
           if (h37_QCD[k]->GetBinContent(nn)<0) h37_QCD[k]->SetBinContent(nn,0.00001);
           if (h37_WOS[k]->GetBinContent(nn)<0) h37_WOS[k]->SetBinContent(nn,0.00001);
           if (h37_WSS[k]->GetBinContent(nn)<0) h37_WSS[k]->SetBinContent(nn,0.00001);

           if (h43_OS[k]->GetBinContent(nn)<0) h43_OS[k]->SetBinContent(nn,0.00001);
           if (h43_SS[k]->GetBinContent(nn)<0) h43_SS[k]->SetBinContent(nn,0.00001);
           if (h43_QCD[k]->GetBinContent(nn)<0) h43_QCD[k]->SetBinContent(nn,0.00001);
           if (h43_WOS[k]->GetBinContent(nn)<0) h43_WOS[k]->SetBinContent(nn,0.00001);
           if (h43_WSS[k]->GetBinContent(nn)<0) h43_WSS[k]->SetBinContent(nn,0.00001);
           if (h44_OS[k]->GetBinContent(nn)<0) h44_OS[k]->SetBinContent(nn,0.00001);
           if (h44_SS[k]->GetBinContent(nn)<0) h44_SS[k]->SetBinContent(nn,0.00001);
           if (h44_QCD[k]->GetBinContent(nn)<0) h44_QCD[k]->SetBinContent(nn,0.00001);
           if (h44_WOS[k]->GetBinContent(nn)<0) h44_WOS[k]->SetBinContent(nn,0.00001);
           if (h44_WSS[k]->GetBinContent(nn)<0) h44_WSS[k]->SetBinContent(nn,0.00001);
           if (h45_OS[k]->GetBinContent(nn)<0) h45_OS[k]->SetBinContent(nn,0.00001);
           if (h45_SS[k]->GetBinContent(nn)<0) h45_SS[k]->SetBinContent(nn,0.00001);
           if (h45_QCD[k]->GetBinContent(nn)<0) h45_QCD[k]->SetBinContent(nn,0.00001);
           if (h45_WOS[k]->GetBinContent(nn)<0) h45_WOS[k]->SetBinContent(nn,0.00001);
           if (h45_WSS[k]->GetBinContent(nn)<0) h45_WSS[k]->SetBinContent(nn,0.00001);
           if (h47_OS[k]->GetBinContent(nn)<0) h47_OS[k]->SetBinContent(nn,0.00001);
           if (h47_SS[k]->GetBinContent(nn)<0) h47_SS[k]->SetBinContent(nn,0.00001);
           if (h47_QCD[k]->GetBinContent(nn)<0) h47_QCD[k]->SetBinContent(nn,0.00001);
           if (h47_WOS[k]->GetBinContent(nn)<0) h47_WOS[k]->SetBinContent(nn,0.00001);
           if (h47_WSS[k]->GetBinContent(nn)<0) h47_WSS[k]->SetBinContent(nn,0.00001);

          if (h53_OS[k]->GetBinContent(nn)<0) h53_OS[k]->SetBinContent(nn,0.00001);
           if (h53_SS[k]->GetBinContent(nn)<0) h53_SS[k]->SetBinContent(nn,0.00001);
           if (h53_QCD[k]->GetBinContent(nn)<0) h53_QCD[k]->SetBinContent(nn,0.00001);
           if (h53_WOS[k]->GetBinContent(nn)<0) h53_WOS[k]->SetBinContent(nn,0.00001);
           if (h53_WSS[k]->GetBinContent(nn)<0) h53_WSS[k]->SetBinContent(nn,0.00001);
           if (h54_OS[k]->GetBinContent(nn)<0) h54_OS[k]->SetBinContent(nn,0.00001);
           if (h54_SS[k]->GetBinContent(nn)<0) h54_SS[k]->SetBinContent(nn,0.00001);
           if (h54_QCD[k]->GetBinContent(nn)<0) h54_QCD[k]->SetBinContent(nn,0.00001);
           if (h54_WOS[k]->GetBinContent(nn)<0) h54_WOS[k]->SetBinContent(nn,0.00001);
           if (h54_WSS[k]->GetBinContent(nn)<0) h54_WSS[k]->SetBinContent(nn,0.00001);
           if (h55_OS[k]->GetBinContent(nn)<0) h55_OS[k]->SetBinContent(nn,0.00001);
           if (h55_SS[k]->GetBinContent(nn)<0) h55_SS[k]->SetBinContent(nn,0.00001);
           if (h55_QCD[k]->GetBinContent(nn)<0) h55_QCD[k]->SetBinContent(nn,0.00001);
           if (h55_WOS[k]->GetBinContent(nn)<0) h55_WOS[k]->SetBinContent(nn,0.00001);
           if (h55_WSS[k]->GetBinContent(nn)<0) h55_WSS[k]->SetBinContent(nn,0.00001);
           if (h57_OS[k]->GetBinContent(nn)<0) h57_OS[k]->SetBinContent(nn,0.00001);
           if (h57_SS[k]->GetBinContent(nn)<0) h57_SS[k]->SetBinContent(nn,0.00001);
           if (h57_QCD[k]->GetBinContent(nn)<0) h57_QCD[k]->SetBinContent(nn,0.00001);
           if (h57_WOS[k]->GetBinContent(nn)<0) h57_WOS[k]->SetBinContent(nn,0.00001);
           if (h57_WSS[k]->GetBinContent(nn)<0) h57_WSS[k]->SetBinContent(nn,0.00001);

          if (h63_OS[k]->GetBinContent(nn)<0) h63_OS[k]->SetBinContent(nn,0.00001);
           if (h63_SS[k]->GetBinContent(nn)<0) h63_SS[k]->SetBinContent(nn,0.00001);
           if (h63_QCD[k]->GetBinContent(nn)<0) h63_QCD[k]->SetBinContent(nn,0.00001);
           if (h63_WOS[k]->GetBinContent(nn)<0) h63_WOS[k]->SetBinContent(nn,0.00001);
           if (h63_WSS[k]->GetBinContent(nn)<0) h63_WSS[k]->SetBinContent(nn,0.00001);
           if (h64_OS[k]->GetBinContent(nn)<0) h64_OS[k]->SetBinContent(nn,0.00001);
           if (h64_SS[k]->GetBinContent(nn)<0) h64_SS[k]->SetBinContent(nn,0.00001);
           if (h64_QCD[k]->GetBinContent(nn)<0) h64_QCD[k]->SetBinContent(nn,0.00001);
           if (h64_WOS[k]->GetBinContent(nn)<0) h64_WOS[k]->SetBinContent(nn,0.00001);
           if (h64_WSS[k]->GetBinContent(nn)<0) h64_WSS[k]->SetBinContent(nn,0.00001);
           if (h65_OS[k]->GetBinContent(nn)<0) h65_OS[k]->SetBinContent(nn,0.00001);
           if (h65_SS[k]->GetBinContent(nn)<0) h65_SS[k]->SetBinContent(nn,0.00001);
           if (h65_QCD[k]->GetBinContent(nn)<0) h65_QCD[k]->SetBinContent(nn,0.00001);
           if (h65_WOS[k]->GetBinContent(nn)<0) h65_WOS[k]->SetBinContent(nn,0.00001);
           if (h65_WSS[k]->GetBinContent(nn)<0) h65_WSS[k]->SetBinContent(nn,0.00001);
           if (h67_OS[k]->GetBinContent(nn)<0) h67_OS[k]->SetBinContent(nn,0.00001);
           if (h67_SS[k]->GetBinContent(nn)<0) h67_SS[k]->SetBinContent(nn,0.00001);
           if (h67_QCD[k]->GetBinContent(nn)<0) h67_QCD[k]->SetBinContent(nn,0.00001);
           if (h67_WOS[k]->GetBinContent(nn)<0) h67_WOS[k]->SetBinContent(nn,0.00001);
           if (h67_WSS[k]->GetBinContent(nn)<0) h67_WSS[k]->SetBinContent(nn,0.00001);

          if (h73_OS[k]->GetBinContent(nn)<0) h73_OS[k]->SetBinContent(nn,0.00001);
           if (h73_SS[k]->GetBinContent(nn)<0) h73_SS[k]->SetBinContent(nn,0.00001);
           if (h73_QCD[k]->GetBinContent(nn)<0) h73_QCD[k]->SetBinContent(nn,0.00001);
           if (h73_WOS[k]->GetBinContent(nn)<0) h73_WOS[k]->SetBinContent(nn,0.00001);
           if (h73_WSS[k]->GetBinContent(nn)<0) h73_WSS[k]->SetBinContent(nn,0.00001);
           if (h74_OS[k]->GetBinContent(nn)<0) h74_OS[k]->SetBinContent(nn,0.00001);
           if (h74_SS[k]->GetBinContent(nn)<0) h74_SS[k]->SetBinContent(nn,0.00001);
           if (h74_QCD[k]->GetBinContent(nn)<0) h74_QCD[k]->SetBinContent(nn,0.00001);
           if (h74_WOS[k]->GetBinContent(nn)<0) h74_WOS[k]->SetBinContent(nn,0.00001);
           if (h74_WSS[k]->GetBinContent(nn)<0) h74_WSS[k]->SetBinContent(nn,0.00001);
           if (h75_OS[k]->GetBinContent(nn)<0) h75_OS[k]->SetBinContent(nn,0.00001);
           if (h75_SS[k]->GetBinContent(nn)<0) h75_SS[k]->SetBinContent(nn,0.00001);
           if (h75_QCD[k]->GetBinContent(nn)<0) h75_QCD[k]->SetBinContent(nn,0.00001);
           if (h75_WOS[k]->GetBinContent(nn)<0) h75_WOS[k]->SetBinContent(nn,0.00001);
           if (h75_WSS[k]->GetBinContent(nn)<0) h75_WSS[k]->SetBinContent(nn,0.00001);
           if (h77_OS[k]->GetBinContent(nn)<0) h77_OS[k]->SetBinContent(nn,0.00001);
           if (h77_SS[k]->GetBinContent(nn)<0) h77_SS[k]->SetBinContent(nn,0.00001);
           if (h77_QCD[k]->GetBinContent(nn)<0) h77_QCD[k]->SetBinContent(nn,0.00001);
           if (h77_WOS[k]->GetBinContent(nn)<0) h77_WOS[k]->SetBinContent(nn,0.00001);
           if (h77_WSS[k]->GetBinContent(nn)<0) h77_WSS[k]->SetBinContent(nn,0.00001);

	   //// make copy for ggH

           if (h0_ggHOS[k]->GetBinContent(nn)<0) h0_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h0_ggHSS[k]->GetBinContent(nn)<0) h0_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h0_ggHQCD[k]->GetBinContent(nn)<0) h0_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h0_ggHWOS[k]->GetBinContent(nn)<0) h0_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h0_ggHWSS[k]->GetBinContent(nn)<0) h0_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h1_ggHOS[k]->GetBinContent(nn)<0) h1_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h1_ggHSS[k]->GetBinContent(nn)<0) h1_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h1_ggHQCD[k]->GetBinContent(nn)<0) h1_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h1_ggHWOS[k]->GetBinContent(nn)<0) h1_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h1_ggHWSS[k]->GetBinContent(nn)<0) h1_ggHWSS[k]->SetBinContent(nn,0.00001);
/*
           if (h2_dPhi_mvOS[k]->GetBinContent(nn)<0) h2_dPhi_mvOS[k]->SetBinContent(nn,0.00001);
           if (h2_dPhi_mvSS[k]->GetBinContent(nn)<0) h2_dPhi_mvSS[k]->SetBinContent(nn,0.00001);
           if (h2_dPhi_mvQCD[k]->GetBinContent(nn)<0) h2_dPhi_mvQCD[k]->SetBinContent(nn,0.00001);
           if (h2_dPhi_mvWOS[k]->GetBinContent(nn)<0) h2_dPhi_mvWOS[k]->SetBinContent(nn,0.00001);
           if (h2_dPhi_mvWSS[k]->GetBinContent(nn)<0) h2_dPhi_mvWSS[k]->SetBinContent(nn,0.00001);
*/
           if (h3_ggHOS[k]->GetBinContent(nn)<0) h3_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h3_ggHSS[k]->GetBinContent(nn)<0) h3_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h3_ggHQCD[k]->GetBinContent(nn)<0) h3_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h3_ggHWOS[k]->GetBinContent(nn)<0) h3_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h3_ggHWSS[k]->GetBinContent(nn)<0) h3_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h4_ggHOS[k]->GetBinContent(nn)<0) h4_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h4_ggHSS[k]->GetBinContent(nn)<0) h4_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h4_ggHQCD[k]->GetBinContent(nn)<0) h4_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h4_ggHWOS[k]->GetBinContent(nn)<0) h4_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h4_ggHWSS[k]->GetBinContent(nn)<0) h4_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h5_ggHOS[k]->GetBinContent(nn)<0) h5_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h5_ggHSS[k]->GetBinContent(nn)<0) h5_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h5_ggHQCD[k]->GetBinContent(nn)<0) h5_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h5_ggHWOS[k]->GetBinContent(nn)<0) h5_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h5_ggHWSS[k]->GetBinContent(nn)<0) h5_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h7_ggHOS[k]->GetBinContent(nn)<0) h7_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h7_ggHSS[k]->GetBinContent(nn)<0) h7_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h7_ggHQCD[k]->GetBinContent(nn)<0) h7_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h7_ggHWOS[k]->GetBinContent(nn)<0) h7_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h7_ggHWSS[k]->GetBinContent(nn)<0) h7_ggHWSS[k]->SetBinContent(nn,0.00001);

           if (h33_ggHOS[k]->GetBinContent(nn)<0) h33_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h33_ggHSS[k]->GetBinContent(nn)<0) h33_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h33_ggHQCD[k]->GetBinContent(nn)<0) h33_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h33_ggHWOS[k]->GetBinContent(nn)<0) h33_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h33_ggHWSS[k]->GetBinContent(nn)<0) h33_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h34_ggHOS[k]->GetBinContent(nn)<0) h34_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h34_ggHSS[k]->GetBinContent(nn)<0) h34_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h34_ggHQCD[k]->GetBinContent(nn)<0) h34_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h34_ggHWOS[k]->GetBinContent(nn)<0) h34_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h34_ggHWSS[k]->GetBinContent(nn)<0) h34_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h35_ggHOS[k]->GetBinContent(nn)<0) h35_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h35_ggHSS[k]->GetBinContent(nn)<0) h35_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h35_ggHQCD[k]->GetBinContent(nn)<0) h35_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h35_ggHWOS[k]->GetBinContent(nn)<0) h35_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h35_ggHWSS[k]->GetBinContent(nn)<0) h35_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h37_ggHOS[k]->GetBinContent(nn)<0) h37_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h37_ggHSS[k]->GetBinContent(nn)<0) h37_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h37_ggHQCD[k]->GetBinContent(nn)<0) h37_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h37_ggHWOS[k]->GetBinContent(nn)<0) h37_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h37_ggHWSS[k]->GetBinContent(nn)<0) h37_ggHWSS[k]->SetBinContent(nn,0.00001);

           if (h43_ggHOS[k]->GetBinContent(nn)<0) h43_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h43_ggHSS[k]->GetBinContent(nn)<0) h43_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h43_ggHQCD[k]->GetBinContent(nn)<0) h43_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h43_ggHWOS[k]->GetBinContent(nn)<0) h43_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h43_ggHWSS[k]->GetBinContent(nn)<0) h43_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h44_ggHOS[k]->GetBinContent(nn)<0) h44_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h44_ggHSS[k]->GetBinContent(nn)<0) h44_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h44_ggHQCD[k]->GetBinContent(nn)<0) h44_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h44_ggHWOS[k]->GetBinContent(nn)<0) h44_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h44_ggHWSS[k]->GetBinContent(nn)<0) h44_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h45_ggHOS[k]->GetBinContent(nn)<0) h45_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h45_ggHSS[k]->GetBinContent(nn)<0) h45_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h45_ggHQCD[k]->GetBinContent(nn)<0) h45_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h45_ggHWOS[k]->GetBinContent(nn)<0) h45_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h45_ggHWSS[k]->GetBinContent(nn)<0) h45_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h47_ggHOS[k]->GetBinContent(nn)<0) h47_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h47_ggHSS[k]->GetBinContent(nn)<0) h47_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h47_ggHQCD[k]->GetBinContent(nn)<0) h47_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h47_ggHWOS[k]->GetBinContent(nn)<0) h47_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h47_ggHWSS[k]->GetBinContent(nn)<0) h47_ggHWSS[k]->SetBinContent(nn,0.00001);

          if (h53_ggHOS[k]->GetBinContent(nn)<0) h53_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h53_ggHSS[k]->GetBinContent(nn)<0) h53_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h53_ggHQCD[k]->GetBinContent(nn)<0) h53_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h53_ggHWOS[k]->GetBinContent(nn)<0) h53_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h53_ggHWSS[k]->GetBinContent(nn)<0) h53_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h54_ggHOS[k]->GetBinContent(nn)<0) h54_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h54_ggHSS[k]->GetBinContent(nn)<0) h54_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h54_ggHQCD[k]->GetBinContent(nn)<0) h54_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h54_ggHWOS[k]->GetBinContent(nn)<0) h54_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h54_ggHWSS[k]->GetBinContent(nn)<0) h54_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h55_ggHOS[k]->GetBinContent(nn)<0) h55_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h55_ggHSS[k]->GetBinContent(nn)<0) h55_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h55_ggHQCD[k]->GetBinContent(nn)<0) h55_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h55_ggHWOS[k]->GetBinContent(nn)<0) h55_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h55_ggHWSS[k]->GetBinContent(nn)<0) h55_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h57_ggHOS[k]->GetBinContent(nn)<0) h57_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h57_ggHSS[k]->GetBinContent(nn)<0) h57_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h57_ggHQCD[k]->GetBinContent(nn)<0) h57_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h57_ggHWOS[k]->GetBinContent(nn)<0) h57_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h57_ggHWSS[k]->GetBinContent(nn)<0) h57_ggHWSS[k]->SetBinContent(nn,0.00001);

          if (h63_ggHOS[k]->GetBinContent(nn)<0) h63_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h63_ggHSS[k]->GetBinContent(nn)<0) h63_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h63_ggHQCD[k]->GetBinContent(nn)<0) h63_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h63_ggHWOS[k]->GetBinContent(nn)<0) h63_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h63_ggHWSS[k]->GetBinContent(nn)<0) h63_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h64_ggHOS[k]->GetBinContent(nn)<0) h64_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h64_ggHSS[k]->GetBinContent(nn)<0) h64_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h64_ggHQCD[k]->GetBinContent(nn)<0) h64_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h64_ggHWOS[k]->GetBinContent(nn)<0) h64_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h64_ggHWSS[k]->GetBinContent(nn)<0) h64_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h65_ggHOS[k]->GetBinContent(nn)<0) h65_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h65_ggHSS[k]->GetBinContent(nn)<0) h65_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h65_ggHQCD[k]->GetBinContent(nn)<0) h65_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h65_ggHWOS[k]->GetBinContent(nn)<0) h65_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h65_ggHWSS[k]->GetBinContent(nn)<0) h65_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h67_ggHOS[k]->GetBinContent(nn)<0) h67_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h67_ggHSS[k]->GetBinContent(nn)<0) h67_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h67_ggHQCD[k]->GetBinContent(nn)<0) h67_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h67_ggHWOS[k]->GetBinContent(nn)<0) h67_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h67_ggHWSS[k]->GetBinContent(nn)<0) h67_ggHWSS[k]->SetBinContent(nn,0.00001);
/*
          if (h73_ggHOS[k]->GetBinContent(nn)<0) h73_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h73_ggHSS[k]->GetBinContent(nn)<0) h73_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h73_ggHQCD[k]->GetBinContent(nn)<0) h73_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h73_ggHWOS[k]->GetBinContent(nn)<0) h73_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h73_ggHWSS[k]->GetBinContent(nn)<0) h73_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h74_ggHOS[k]->GetBinContent(nn)<0) h74_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h74_ggHSS[k]->GetBinContent(nn)<0) h74_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h74_ggHQCD[k]->GetBinContent(nn)<0) h74_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h74_ggHWOS[k]->GetBinContent(nn)<0) h74_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h74_ggHWSS[k]->GetBinContent(nn)<0) h74_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h75_ggHOS[k]->GetBinContent(nn)<0) h75_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h75_ggHSS[k]->GetBinContent(nn)<0) h75_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h75_ggHQCD[k]->GetBinContent(nn)<0) h75_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h75_ggHWOS[k]->GetBinContent(nn)<0) h75_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h75_ggHWSS[k]->GetBinContent(nn)<0) h75_ggHWSS[k]->SetBinContent(nn,0.00001);
           if (h77_ggHOS[k]->GetBinContent(nn)<0) h77_ggHOS[k]->SetBinContent(nn,0.00001);
           if (h77_ggHSS[k]->GetBinContent(nn)<0) h77_ggHSS[k]->SetBinContent(nn,0.00001);
           if (h77_ggHQCD[k]->GetBinContent(nn)<0) h77_ggHQCD[k]->SetBinContent(nn,0.00001);
           if (h77_ggHWOS[k]->GetBinContent(nn)<0) h77_ggHWOS[k]->SetBinContent(nn,0.00001);
           if (h77_ggHWSS[k]->GetBinContent(nn)<0) h77_ggHWSS[k]->SetBinContent(nn,0.00001);
*/

        }

	const char * namee ; namee = postfix;
//0jet
        OS0jet->cd();
        h0_OS[k]->SetName(name.c_str()+postfix);
        h0_WOS[k]->SetName(name.c_str()+postfix);
        h0_OS[k]->Write();
	
	char name_[100];

	sprintf(name_,"%s_%s%s",hmelaDCP_OS_0jet[k]->GetName(),name.c_str(),namee);
        hmelaDCP_OS_0jet[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_OS_0jet[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_OS_0jet[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_OS_0jet[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_OS_0jet[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_OS_0jet[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_OS_0jet[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_OS_0jet[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_OS_0jet[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_OS_0jet[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_OS_0jet[k]->SetName(name_);

        hmelaDCP_OS_0jet[k]->Write();
        hmelaDCPggH_OS_0jet[k]->Write();
        hmelaD0minus_OS_0jet[k]->Write();
        hmelaD0minusggH_OS_0jet[k]->Write();
        hmelaDPhijj_OS_0jet[k]->Write();
        hmelaDPhiUnsignedjj_OS_0jet[k]->Write();


        SS0jet->cd();
        h0_SS[k]->SetName(name.c_str()+postfix);
        h0_SS[k]->Write();
        h0_WSS[k]->SetName(name.c_str()+postfix);
        h0_WSS[k]->Write();

        QCD0jet->cd();
        h0_QCD[k]->SetName(name.c_str()+postfix);
        h0_QCD[k]->Write();
        h0_ggHQCD[k]->SetName(h0_ggHQCD[k]->GetName()+postfix);
        h0_ggHQCD[k]->Write();

//Control Region / signal region
        OScontrol->cd();
        h1D_OS[k]->SetName(name.c_str()+postfix);
        h1D_WOS[k]->SetName(name.c_str()+postfix);
		  

       if (sample=="W"){
         h1D_WOS[k]->Write();
	sprintf(name_,"%s_%s%s",h1D_jpt1_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_WOS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_WOS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_WOS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_WOS[k]->GetName(),name.c_str(),namee);
	h1D_met_WOS[k]->SetName(name_);

	h1D_jpt1_WOS[k]->Write();
	h1D_jpt2_WOS[k]->Write();
	h1D_jeta1_WOS[k]->Write();
	h1D_jeta2_WOS[k]->Write();
	h1D_phi1_WOS[k]->Write();
	h1D_phi2_WOS[k]->Write();
	h1D_mjj_WOS[k]->Write();
	h1D_met_WOS[k]->Write();


	sprintf(name_,"%s_%s%s",hmelaDCP_WOS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCP_WOS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_WOS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_WOS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_WOS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_WOS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_WOS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_WOS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_WOS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_WOS_VBF[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_WOS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_WOS_VBF[k]->SetName(name_);

	   hmelaDCP_WOS_VBF[k]->Write();
	   hmelaDCPggH_WOS_VBF[k]->Write();
	   hmelaD0minus_WOS_VBF[k]->Write();
	   hmelaD0minusggH_WOS_VBF[k]->Write();
	   hmelaDPhijj_WOS_VBF[k]->Write();
	   hmelaDPhiUnsignedjj_WOS_VBF[k]->Write();


       }
       else{
         h1D_OS[k]->Write();
	sprintf(name_,"%s_%s%s",h1D_jpt1_OS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_OS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_OS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_OS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_OS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_OS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_OS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_OS[k]->GetName(),name.c_str(),namee);
	h1D_met_OS[k]->SetName(name_);

	h1D_jpt1_OS[k]->Write();
	h1D_jpt2_OS[k]->Write();
	h1D_jeta1_OS[k]->Write();
	h1D_jeta2_OS[k]->Write();
	h1D_phi1_OS[k]->Write();
	h1D_phi2_OS[k]->Write();
	h1D_mjj_OS[k]->Write();
	h1D_met_OS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_OS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCP_OS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_OS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_OS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_OS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_OS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_OS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_OS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_OS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_OS_VBF[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_OS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_OS_VBF[k]->SetName(name_);



	   hmelaDCP_OS_VBF[k]->Write();
	   hmelaDCPggH_OS_VBF[k]->Write();
	   hmelaD0minus_OS_VBF[k]->Write();
	   hmelaD0minusggH_OS_VBF[k]->Write();
	   hmelaDPhijj_OS_VBF[k]->Write();
	   hmelaDPhiUnsignedjj_OS_VBF[k]->Write();

       }

       SScontrol->cd();
       h1D_SS[k]->SetName(name.c_str()+postfix);
       h1D_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W"){
         h1D_WSS[k]->Write();

	sprintf(name_,"%s_%s%s",h1D_jpt1_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_WSS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_WSS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_WSS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_WSS[k]->GetName(),name.c_str(),namee);
	h1D_met_WSS[k]->SetName(name_);

	h1D_jpt1_WSS[k]->Write();
	h1D_jpt2_WSS[k]->Write();
	h1D_jeta1_WSS[k]->Write();
	h1D_jeta2_WSS[k]->Write();
	h1D_phi1_WSS[k]->Write();
	h1D_phi2_WSS[k]->Write();
	h1D_mjj_WSS[k]->Write();
	h1D_met_WSS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_WSS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCP_WSS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_WSS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_WSS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_WSS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_WSS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_WSS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_WSS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_WSS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_WSS_VBF[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_WSS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_WSS_VBF[k]->SetName(name_);

	   hmelaDCP_WSS_VBF[k]->Write();
	   hmelaDCPggH_WSS_VBF[k]->Write();
	   hmelaD0minus_WSS_VBF[k]->Write();
	   hmelaD0minusggH_WSS_VBF[k]->Write();
	   hmelaDPhijj_WSS_VBF[k]->Write();
	   hmelaDPhiUnsignedjj_WSS_VBF[k]->Write();

       }
       else{
         h1D_SS[k]->Write();
	sprintf(name_,"%s_%s%s",h1D_jpt1_SS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_SS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_SS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_SS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_SS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_SS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_SS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_SS[k]->GetName(),name.c_str(),namee);
	h1D_met_SS[k]->SetName(name_);

	h1D_jpt1_SS[k]->Write();
	h1D_jpt2_SS[k]->Write();
	h1D_jeta1_SS[k]->Write();
	h1D_jeta2_SS[k]->Write();
	h1D_phi1_SS[k]->Write();
	h1D_phi2_SS[k]->Write();
	h1D_mjj_SS[k]->Write();
	h1D_met_SS[k]->Write();


	sprintf(name_,"%s_%s%s",hmelaDCP_SS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCP_SS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_SS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_SS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_SS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_SS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_SS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_SS_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_SS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_SS_VBF[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_SS_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_SS_VBF[k]->SetName(name_);

	   hmelaDCP_SS_VBF[k]->Write();
	   hmelaDCPggH_SS_VBF[k]->Write();
	   hmelaD0minus_SS_VBF[k]->Write();
	   hmelaD0minusggH_SS_VBF[k]->Write();
	   hmelaDPhijj_SS_VBF[k]->Write();
	   hmelaDPhiUnsignedjj_SS_VBF[k]->Write();


       }




       QCDcontrol->cd();
       h1D_QCD[k]->SetName(name.c_str()+postfix);
       h1D_QCD[k]->Write();

	sprintf(name_,"%s_%s%s",h1D_jpt1_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_QCD[k]->GetName(),name.c_str(),namee);
	h1D_phi1_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_QCD[k]->GetName(),name.c_str(),namee);
	h1D_phi2_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_QCD[k]->GetName(),name.c_str(),namee);
	h1D_mjj_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_QCD[k]->GetName(),name.c_str(),namee);
	h1D_met_QCD[k]->SetName(name_);

	h1D_jpt1_QCD[k]->Write();
	h1D_jpt2_QCD[k]->Write();
	h1D_jeta1_QCD[k]->Write();
	h1D_jeta2_QCD[k]->Write();
	h1D_phi1_QCD[k]->Write();
	h1D_phi2_QCD[k]->Write();
	h1D_mjj_QCD[k]->Write();
	h1D_met_QCD[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_QCD_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCP_QCD_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_QCD_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_QCD_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_QCD_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_QCD_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_QCD_VBF[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_QCD_VBF[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_QCD_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_QCD_VBF[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_QCD_VBF[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_QCD_VBF[k]->SetName(name_);

	   hmelaDCP_QCD_VBF[k]->Write();
	   hmelaDCPggH_QCD_VBF[k]->Write();
	   hmelaD0minus_QCD_VBF[k]->Write();
	   hmelaD0minusggH_QCD_VBF[k]->Write();
	   hmelaDPhijj_QCD_VBF[k]->Write();
	   hmelaDPhiUnsignedjj_QCD_VBF[k]->Write();

///boosted
        OS1jet->cd();
        h1_OS[k]->SetName(name.c_str()+postfix);
        h1_WOS[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h1_WOS[k]->Write();
	}
	
	else{
           h1_OS[k]->Write();

	}


	

        SS1jet->cd();
        h1_SS[k]->SetName(name.c_str()+postfix);
        h1_WSS[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h1_WSS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCP_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_WSS_boosted[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_WSS_boosted[k]->SetName(name_);

	   hmelaDCP_WSS_boosted[k]->Write();
	   hmelaDCPggH_WSS_boosted[k]->Write();
	   hmelaD0minus_WSS_boosted[k]->Write();
	   hmelaD0minusggH_WSS_boosted[k]->Write();
	   hmelaDPhijj_WSS_boosted[k]->Write();
	   hmelaDPhiUnsignedjj_WSS_boosted[k]->Write();

	}
        else{
           h1_SS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCP_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_SS_boosted[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_SS_boosted[k]->SetName(name_);

	   hmelaDCP_SS_boosted[k]->Write();
	   hmelaDCPggH_SS_boosted[k]->Write();
	   hmelaD0minus_SS_boosted[k]->Write();
	   hmelaD0minusggH_SS_boosted[k]->Write();
	   hmelaDPhijj_SS_boosted[k]->Write();
	   hmelaDPhiUnsignedjj_SS_boosted[k]->Write();

	}

        QCD1jet->cd();
        h1_QCD[k]->SetName(name.c_str()+postfix);
        h1_QCD[k]->Write();

        OS2jet->cd();
        h2_OS[k]->SetName(name.c_str()+postfix);
        h2_WOS[k]->SetName(name.c_str()+postfix);
	

        if (sample=="W"){
           h2_WOS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_WOS_boosted[k]->GetName(),name.c_str(),namee);
	hmelaDCP_WOS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_WOS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_WOS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_WOS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_WOS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_WOS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_WOS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_WOS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_WOS_boosted[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_WOS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_WOS_boosted[k]->SetName(name_);

	hmelaDCP_WOS_boosted[k]->Write();
	hmelaDCPggH_WOS_boosted[k]->Write();
	hmelaD0minus_WOS_boosted[k]->Write();
	hmelaD0minusggH_WOS_boosted[k]->Write();
	hmelaDPhijj_WOS_boosted[k]->Write();
	hmelaDPhiUnsignedjj_WOS_boosted[k]->Write();


	}
        else 
		{
           h2_OS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_OS_boosted[k]->GetName(),name.c_str(),namee);
	hmelaDCP_OS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_OS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_OS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_OS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_OS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_OS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_OS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_OS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_OS_boosted[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_OS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_OS_boosted[k]->SetName(name_);


	hmelaDCP_OS_boosted[k]->Write();
	hmelaDCPggH_OS_boosted[k]->Write();
	hmelaD0minus_OS_boosted[k]->Write();
	hmelaD0minusggH_OS_boosted[k]->Write();
	hmelaDPhijj_OS_boosted[k]->Write();
	hmelaDPhiUnsignedjj_OS_boosted[k]->Write();
		}



	sprintf(name_,"%s_%s%s",h3a_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3a_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3b_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3b_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3c_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3c_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3d_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3d_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3e_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3e_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3f_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3f_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3g_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3g_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3h_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3h_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3i_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3i_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3j_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3j_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3k_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3k_dphi_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h3l_dphi_OS[k]->GetName(),name.c_str(),namee);
	h3l_dphi_OS[k]->SetName(name_);
//	sprintf(name_,"%s_%s%s",h3m_dphi_OS[k]->GetName(),name.c_str(),namee);
//	h3m_dphi_OS[k]->SetName(name_);
//	sprintf(name_,"%s_%s%s",h3n_dphi_OS[k]->GetName(),name.c_str(),namee);
//	h3n_dphi_OS[k]->SetName(name_);

	  h3a_dphi_OS[k]->Write();
	  h3b_dphi_OS[k]->Write();
	  h3c_dphi_OS[k]->Write();
	  h3d_dphi_OS[k]->Write();
	  h3e_dphi_OS[k]->Write();
	  h3f_dphi_OS[k]->Write();
	  h3g_dphi_OS[k]->Write();
	  h3h_dphi_OS[k]->Write();
	  h3i_dphi_OS[k]->Write();
	  h3j_dphi_OS[k]->Write();
	  h3k_dphi_OS[k]->Write();
	  h3l_dphi_OS[k]->Write();
	 // h3m_dphi_OS[k]->Write();
	  //h3n_dphi_OS[k]->Write();

	
        SS2jet->cd();
        h2_SS[k]->SetName(name.c_str()+postfix);
        h2_WSS[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h2_WSS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_WSS_boosted[k]->GetName(),name.c_str(),namee);
	hmelaDCP_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_WSS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_WSS_boosted[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_WSS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_WSS_boosted[k]->SetName(name_);

	hmelaDCP_WSS_boosted[k]->Write();
	hmelaDCPggH_WSS_boosted[k]->Write();
	hmelaD0minus_WSS_boosted[k]->Write();
	hmelaD0minusggH_WSS_boosted[k]->Write();
	hmelaDPhijj_WSS_boosted[k]->Write();
	hmelaDPhiUnsignedjj_WSS_boosted[k]->Write();

	}
        else{
           h2_SS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_SS_boosted[k]->GetName(),name.c_str(),namee);
	hmelaDCP_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_SS_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_SS_boosted[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_SS_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_SS_boosted[k]->SetName(name_);

	hmelaDCP_SS_boosted[k]->Write();
	hmelaDCPggH_SS_boosted[k]->Write();
	hmelaD0minus_SS_boosted[k]->Write();
	hmelaD0minusggH_SS_boosted[k]->Write();
	hmelaDPhijj_SS_boosted[k]->Write();
	hmelaDPhiUnsignedjj_SS_boosted[k]->Write();

	}

        QCD2jet->cd();
        h2_QCD[k]->SetName(name.c_str()+postfix);
        h2_QCD[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_QCD_boosted[k]->GetName(),name.c_str(),namee);
	hmelaDCP_QCD_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_QCD_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_QCD_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_QCD_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_QCD_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_QCD_boosted[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_QCD_boosted[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_QCD_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_QCD_boosted[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_QCD_boosted[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_QCD_boosted[k]->SetName(name_);




        OS3jet->cd();
        h3_OS[k]->SetName(name.c_str()+postfix);
        h3_WOS[k]->SetName(name.c_str()+postfix);
        h3_ggHOS[k]->SetName(h3_ggHOS[k]->GetName()+postfix);
        h3_ggHWOS[k]->SetName(h3_ggHWOS[k]->GetName()+postfix);


        if (sample=="W"){
           h3_WOS[k]->Write();
           h3_ggHWOS[k]->Write();
	}
        else{
           h3_OS[k]->Write();
           h3_ggHOS[k]->Write();
	}
        SS3jet->cd();
        h3_SS[k]->SetName(name.c_str()+postfix);
        h3_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h3_WSS[k]->Write();
        else
           h3_SS[k]->Write();
        QCD3jet->cd();
        h3_QCD[k]->SetName(name.c_str()+postfix);
        h3_QCD[k]->Write();

        OS33jet->cd();
        h33_OS[k]->SetName(name.c_str()+postfix);
        h33_WOS[k]->SetName(name.c_str()+postfix);
        h33_ggHOS[k]->SetName(h33_ggHOS[k]->GetName()+postfix);
        h33_ggHWOS[k]->SetName(h33_ggHWOS[k]->GetName()+postfix);

        if (sample=="W"){
           h33_WOS[k]->Write();
           h33_ggHWOS[k]->Write();
	}
        else{
           h33_OS[k]->Write();
           h33_ggHOS[k]->Write();
	}

        SS33jet->cd();
        h33_SS[k]->SetName(name.c_str()+postfix);
        h33_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h33_WSS[k]->Write();
        else
           h33_SS[k]->Write();
        QCD33jet->cd();
        h33_QCD[k]->SetName(name.c_str()+postfix);
        h33_QCD[k]->Write();

        OS43jet->cd();
        h43_OS[k]->SetName(name.c_str()+postfix);
        h43_WOS[k]->SetName(name.c_str()+postfix);
        h43_ggHOS[k]->SetName(h43_ggHOS[k]->GetName()+postfix);
        h43_ggHWOS[k]->SetName(h43_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h43_WOS[k]->Write();
           h43_ggHWOS[k]->Write();
	}
        else{
           h43_OS[k]->Write();
           h43_ggHOS[k]->Write();
	}

        SS43jet->cd();
        h43_SS[k]->SetName(name.c_str()+postfix);
        h43_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h43_WSS[k]->Write();
        else
           h43_SS[k]->Write();
        QCD43jet->cd();
        h43_QCD[k]->SetName(name.c_str()+postfix);
        h43_QCD[k]->Write();

        OS53jet->cd();
        h53_OS[k]->SetName(name.c_str()+postfix);
        h53_WOS[k]->SetName(name.c_str()+postfix);
        h53_ggHOS[k]->SetName(h53_ggHOS[k]->GetName()+postfix);
        h53_ggHWOS[k]->SetName(h53_ggHWOS[k]->GetName()+postfix);

        if (sample=="W"){
           h53_WOS[k]->Write();
           h53_ggHWOS[k]->Write();
	}
        else {
           h53_OS[k]->Write();
           h53_ggHOS[k]->Write();
	}
        SS53jet->cd();
        h53_SS[k]->SetName(name.c_str()+postfix);
        h53_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h53_WSS[k]->Write();
        else
           h53_SS[k]->Write();
        QCD53jet->cd();
        h53_QCD[k]->SetName(name.c_str()+postfix);
        h53_QCD[k]->Write();

        OS63jet->cd();
        h63_OS[k]->SetName(name.c_str()+postfix);
        h63_WOS[k]->SetName(name.c_str()+postfix);
        h63_ggHOS[k]->SetName(h63_ggHOS[k]->GetName()+postfix);
        h63_ggHWOS[k]->SetName(h63_ggHWOS[k]->GetName()+postfix);

        if (sample=="W"){
           h63_WOS[k]->Write();
           h63_ggHWOS[k]->Write();
	}
        else{
           h63_OS[k]->Write();
           h63_ggHOS[k]->Write();
	}

        SS63jet->cd();
        h63_SS[k]->SetName(name.c_str()+postfix);
        h63_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h63_WSS[k]->Write();
        else
           h63_SS[k]->Write();
        QCD63jet->cd();
        h63_QCD[k]->SetName(name.c_str()+postfix);
        h63_QCD[k]->Write();

        OS73jet->cd();
        h73_OS[k]->SetName(name.c_str()+postfix);
        h73_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h73_WOS[k]->Write();
        else
           h73_OS[k]->Write();
        SS73jet->cd();
        h73_SS[k]->SetName(name.c_str()+postfix);
        h73_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h73_WSS[k]->Write();
        else
           h73_SS[k]->Write();
        QCD73jet->cd();
        h73_QCD[k]->SetName(name.c_str()+postfix);
        h73_QCD[k]->Write();


        OS4jet->cd();
        h4_OS[k]->SetName(name.c_str()+postfix);
        h4_WOS[k]->SetName(name.c_str()+postfix);
        h4_ggHOS[k]->SetName(h4_ggHOS[k]->GetName()+postfix);
        h4_ggHWOS[k]->SetName(h4_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h4_WOS[k]->Write();
           h4_ggHWOS[k]->Write();
	}
        else{
           h4_OS[k]->Write();
           h4_ggHOS[k]->Write();
	}

        SS4jet->cd();
        h4_SS[k]->SetName(name.c_str()+postfix);
        h4_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h4_WSS[k]->Write();
        else
           h4_SS[k]->Write();
        QCD4jet->cd();
        h4_QCD[k]->SetName(name.c_str()+postfix);
        h4_QCD[k]->Write();

        OS34jet->cd();
        h34_OS[k]->SetName(name.c_str()+postfix);
        h34_WOS[k]->SetName(name.c_str()+postfix);
        h34_ggHOS[k]->SetName(h34_ggHOS[k]->GetName()+postfix);
        h34_ggHWOS[k]->SetName(h34_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h34_WOS[k]->Write();
           h34_ggHWOS[k]->Write();
	}
        else{
           h34_OS[k]->Write();
           h34_ggHOS[k]->Write();
	}

        SS34jet->cd();
        h34_SS[k]->SetName(name.c_str()+postfix);
        h34_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h34_WSS[k]->Write();
        else
           h34_SS[k]->Write();
        QCD34jet->cd();
        h34_QCD[k]->SetName(name.c_str()+postfix);
        h34_QCD[k]->Write();

        OS44jet->cd();
        h44_OS[k]->SetName(name.c_str()+postfix);
        h44_WOS[k]->SetName(name.c_str()+postfix);
        h44_ggHOS[k]->SetName(h44_ggHOS[k]->GetName()+postfix);
        h44_ggHWOS[k]->SetName(h44_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h44_WOS[k]->Write();
           h44_ggHWOS[k]->Write();
	}
        else{
           h44_OS[k]->Write();
           h44_ggHOS[k]->Write();
	}

        SS44jet->cd();
        h44_SS[k]->SetName(name.c_str()+postfix);
        h44_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h44_WSS[k]->Write();
        else
           h44_SS[k]->Write();
        QCD44jet->cd();
        h44_QCD[k]->SetName(name.c_str()+postfix);
        h44_QCD[k]->Write();

        OS54jet->cd();
        h54_OS[k]->SetName(name.c_str()+postfix);
        h54_WOS[k]->SetName(name.c_str()+postfix);
        h54_ggHOS[k]->SetName(h54_ggHOS[k]->GetName()+postfix);
        h54_ggHWOS[k]->SetName(h54_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h54_WOS[k]->Write();
           h54_ggHWOS[k]->Write();
	}
        else{
           h54_OS[k]->Write();
           h54_ggHOS[k]->Write();
	}

        SS54jet->cd();
        h54_SS[k]->SetName(name.c_str()+postfix);
        h54_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h54_WSS[k]->Write();
        else
           h54_SS[k]->Write();
        QCD54jet->cd();
        h54_QCD[k]->SetName(name.c_str()+postfix);
        h54_QCD[k]->Write();

        OS64jet->cd();
        h64_OS[k]->SetName(name.c_str()+postfix);
        h64_WOS[k]->SetName(name.c_str()+postfix);
        h64_ggHOS[k]->SetName(h64_ggHOS[k]->GetName()+postfix);
        h64_ggHWOS[k]->SetName(h64_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h64_WOS[k]->Write();
           h64_ggHWOS[k]->Write();
	}
        else{
           h64_OS[k]->Write();
           h64_ggHOS[k]->Write();
	}

        SS64jet->cd();
        h64_SS[k]->SetName(name.c_str()+postfix);
        h64_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h64_WSS[k]->Write();
        else
           h64_SS[k]->Write();
        QCD64jet->cd();
        h64_QCD[k]->SetName(name.c_str()+postfix);
        h64_QCD[k]->Write();

        OS74jet->cd();
        h74_OS[k]->SetName(name.c_str()+postfix);
        h74_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h74_WOS[k]->Write();
        else
           h74_OS[k]->Write();
        SS74jet->cd();
        h74_SS[k]->SetName(name.c_str()+postfix);
        h74_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h74_WSS[k]->Write();
        else
           h74_SS[k]->Write();
        QCD74jet->cd();
        h74_QCD[k]->SetName(name.c_str()+postfix);
        h74_QCD[k]->Write();


        OS5jet->cd();
        h5_OS[k]->SetName(name.c_str()+postfix);
        h5_WOS[k]->SetName(name.c_str()+postfix);
        h5_ggHOS[k]->SetName(h5_ggHOS[k]->GetName()+postfix);
        h5_ggHWOS[k]->SetName(h5_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h5_WOS[k]->Write();
           h5_ggHWOS[k]->Write();
	}
        else{
           h5_OS[k]->Write();
           h5_ggHOS[k]->Write();
	}
        SS5jet->cd();
        h5_SS[k]->SetName(name.c_str()+postfix);
        h5_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h5_WSS[k]->Write();
        else
           h5_SS[k]->Write();
        QCD5jet->cd();
        h5_QCD[k]->SetName(name.c_str()+postfix);
        h5_QCD[k]->Write();

        OS35jet->cd();
        h35_OS[k]->SetName(name.c_str()+postfix);
        h35_WOS[k]->SetName(name.c_str()+postfix);
        h35_ggHOS[k]->SetName(h35_ggHOS[k]->GetName()+postfix);
        h35_ggHWOS[k]->SetName(h35_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h35_WOS[k]->Write();
           h35_ggHWOS[k]->Write();
	}
        else{
           h35_OS[k]->Write();
           h35_ggHOS[k]->Write();
	}

        SS35jet->cd();
        h35_SS[k]->SetName(name.c_str()+postfix);
        h35_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h35_WSS[k]->Write();
        else
           h35_SS[k]->Write();
        QCD35jet->cd();
        h35_QCD[k]->SetName(name.c_str()+postfix);
        h35_QCD[k]->Write();

        OS45jet->cd();
        h45_OS[k]->SetName(name.c_str()+postfix);
        h45_WOS[k]->SetName(name.c_str()+postfix);
        h45_ggHOS[k]->SetName(h45_ggHOS[k]->GetName()+postfix);
        h45_ggHWOS[k]->SetName(h45_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h45_WOS[k]->Write();
           h45_ggHWOS[k]->Write();
	}
        else{
           h45_OS[k]->Write();
           h45_ggHOS[k]->Write();
	}

        SS45jet->cd();
        h45_SS[k]->SetName(name.c_str()+postfix);
        h45_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h45_WSS[k]->Write();
        else
           h45_SS[k]->Write();
        QCD45jet->cd();
        h45_QCD[k]->SetName(name.c_str()+postfix);
        h45_QCD[k]->Write();

        OS55jet->cd();
        h55_OS[k]->SetName(name.c_str()+postfix);
        h55_WOS[k]->SetName(name.c_str()+postfix);
        h55_ggHOS[k]->SetName(h55_ggHOS[k]->GetName()+postfix);
        h55_ggHWOS[k]->SetName(h55_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h55_WOS[k]->Write();
           h55_ggHWOS[k]->Write();
	}
        else{
           h55_OS[k]->Write();
           h55_ggHOS[k]->Write();
	}

        SS55jet->cd();
        h55_SS[k]->SetName(name.c_str()+postfix);
        h55_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h55_WSS[k]->Write();
        else
           h55_SS[k]->Write();
        QCD55jet->cd();
        h55_QCD[k]->SetName(name.c_str()+postfix);
        h55_QCD[k]->Write();

        OS65jet->cd();
        h65_OS[k]->SetName(name.c_str()+postfix);
        h65_WOS[k]->SetName(name.c_str()+postfix);
        h65_ggHOS[k]->SetName(h65_ggHOS[k]->GetName()+postfix);
        h65_ggHWOS[k]->SetName(h65_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h65_WOS[k]->Write();
           h65_ggHWOS[k]->Write();
	}
        else{
           h65_OS[k]->Write();
           h65_ggHOS[k]->Write();
	}

        SS65jet->cd();
        h65_SS[k]->SetName(name.c_str()+postfix);
        h65_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h65_WSS[k]->Write();
        else
           h65_SS[k]->Write();
        QCD65jet->cd();
        h65_QCD[k]->SetName(name.c_str()+postfix);
        h65_QCD[k]->Write();

        OS75jet->cd();
        h75_OS[k]->SetName(name.c_str()+postfix);
        h75_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h75_WOS[k]->Write();
        else
           h75_OS[k]->Write();
        SS75jet->cd();
        h75_SS[k]->SetName(name.c_str()+postfix);
        h75_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h75_WSS[k]->Write();
        else
           h75_SS[k]->Write();
        QCD75jet->cd();
        h75_QCD[k]->SetName(name.c_str()+postfix);
        h75_QCD[k]->Write();



        OS7jet->cd();
        h7_OS[k]->SetName(name.c_str()+postfix);
        h7_WOS[k]->SetName(name.c_str()+postfix);
        h7_ggHOS[k]->SetName(h7_ggHOS[k]->GetName()+postfix);
        h7_ggHWOS[k]->SetName(h7_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h7_WOS[k]->Write();
           h7_ggHWOS[k]->Write();
	}
        else{
           h7_OS[k]->Write();
           h7_ggHOS[k]->Write();
	}

        SS7jet->cd();
        h7_SS[k]->SetName(name.c_str()+postfix);
        h7_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h7_WSS[k]->Write();
        else
           h7_SS[k]->Write();
        QCD7jet->cd();
        h7_QCD[k]->SetName(name.c_str()+postfix);
        h7_QCD[k]->Write();

        OS37jet->cd();
        h37_OS[k]->SetName(name.c_str()+postfix);
        h37_WOS[k]->SetName(name.c_str()+postfix);
        h37_ggHOS[k]->SetName(h37_ggHOS[k]->GetName()+postfix);
        h37_ggHWOS[k]->SetName(h37_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h37_WOS[k]->Write();
           h37_ggHWOS[k]->Write();
	}
        else{
           h37_OS[k]->Write();
           h37_ggHOS[k]->Write();
	}

        SS37jet->cd();
        h37_SS[k]->SetName(name.c_str()+postfix);
        h37_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h37_WSS[k]->Write();
        else
           h37_SS[k]->Write();
        QCD37jet->cd();
        h37_QCD[k]->SetName(name.c_str()+postfix);
        h37_QCD[k]->Write();

        OS47jet->cd();
        h47_OS[k]->SetName(name.c_str()+postfix);
        h47_WOS[k]->SetName(name.c_str()+postfix);
        h47_ggHOS[k]->SetName(h47_ggHOS[k]->GetName()+postfix);
        h47_ggHWOS[k]->SetName(h47_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h47_WOS[k]->Write();
           h47_ggHWOS[k]->Write();
	}
        else{
           h47_OS[k]->Write();
           h47_ggHOS[k]->Write();
	}

        SS47jet->cd();
        h47_SS[k]->SetName(name.c_str()+postfix);
        h47_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W"){
           h47_WSS[k]->Write();
           h47_ggHWSS[k]->Write();
	}
        else{
           h47_SS[k]->Write();
           h47_ggHSS[k]->Write();
	}

        QCD47jet->cd();
        h47_QCD[k]->SetName(name.c_str()+postfix);
        h47_QCD[k]->Write();

        OS57jet->cd();
        h57_OS[k]->SetName(name.c_str()+postfix);
        h57_WOS[k]->SetName(name.c_str()+postfix);
        h57_ggHOS[k]->SetName(h57_ggHOS[k]->GetName()+postfix);
        h57_ggHWOS[k]->SetName(h57_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h57_WOS[k]->Write();
           h57_ggHWOS[k]->Write();
	}
        else{
           h57_OS[k]->Write();
           h57_ggHOS[k]->Write();
	}
        SS57jet->cd();
        h57_SS[k]->SetName(name.c_str()+postfix);
        h57_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h57_WSS[k]->Write();
        else
           h57_SS[k]->Write();
        QCD57jet->cd();
        h57_QCD[k]->SetName(name.c_str()+postfix);
        h57_QCD[k]->Write();

        OS67jet->cd();
        h67_OS[k]->SetName(name.c_str()+postfix);
        h67_WOS[k]->SetName(name.c_str()+postfix);
        h67_ggHOS[k]->SetName(h67_ggHOS[k]->GetName()+postfix);
        h67_ggHWOS[k]->SetName(h67_ggHWOS[k]->GetName()+postfix);
        if (sample=="W"){
           h67_WOS[k]->Write();
           h67_ggHWOS[k]->Write();
	}
        else{
           h67_OS[k]->Write();
           h67_ggHOS[k]->Write();
	}

        SS67jet->cd();
        h67_SS[k]->SetName(name.c_str()+postfix);
        h67_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h67_WSS[k]->Write();
        else
           h67_SS[k]->Write();
        QCD67jet->cd();
        h67_QCD[k]->SetName(name.c_str()+postfix);
        h67_QCD[k]->Write();


        OS77jet->cd();
        h77_OS[k]->SetName(name.c_str()+postfix);
        h77_WOS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h77_WOS[k]->Write();
        else
           h77_OS[k]->Write();
        SS77jet->cd();
        h77_SS[k]->SetName(name.c_str()+postfix);
        h77_WSS[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h77_WSS[k]->Write();
        else
           h77_SS[k]->Write();
        QCD77jet->cd();
        h77_QCD[k]->SetName(name.c_str()+postfix);
        h77_QCD[k]->Write();

    }

cout<<h0_OS[0]->Integral()<<" "<<h1_OS[0]->Integral()<<" "<<h2_OS[0]->Integral()<<endl;

    fout->Close();
} 


