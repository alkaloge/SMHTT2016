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
#include "ZmmSF.h"
#include "LumiReweightingStandAlone.h"
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

    cout<<"XXXXXXXXXXXXX XXXXXXXXXXXX"<<endl;
    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);

//    TFile *f_Double2 = new TFile(input2.c_str());
//    cout<<"XXXXXXXXXXXXX "<<input2.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("mutau_tree");

    TFile *f_Trk=new TFile("Tracking_EfficienciesAndSF_BCDEFGH.root");
    TGraph *h_Trk=(TGraph*) f_Trk->Get("ratio_eff_eta3_dr030e030_corr");

    reweight::LumiReWeighting* LumiWeights_12;
    LumiWeights_12 = new reweight::LumiReWeighting("MC_Moriond17_PU25ns_V1.root", "Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");

    TFile *fZ=new TFile("zpt_weights_2016_BtoH.root");
    TH2F *histZ=(TH2F*) fZ->Get("zptmass_histo");

    TFile *fM=new TFile("mjj_detajj_weights_2016_BtoH.root");
    TH2F *histM=(TH2F*) fM->Get("detajjmjj_histo");

    //TFile fw("htt_scalefactors_v16_3.root");
    //RooWorkspace *w = (RooWorkspace*)fw.Get("w");
    //fw.Close();

    TFile fw2("htt_scalefactors_sm_moriond_v1.root");
    RooWorkspace *w2 = (RooWorkspace*)fw2.Get("w");
    fw2.Close();

    float xs=1.0; float weight=1.0; float luminosity=35870.0;
    if (sample=="ZL" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL"){ xs=5265.4; weight=luminosity*xs/ngen;}
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
    else if (sample=="VBF130") {xs=3.632*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ggH110") {xs=52.90*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="VBF110") {xs=4.434*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ggH140") {xs=36.0*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="VBF140") {xs=3.492*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW125") {xs=48.58*0.2132*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW120") {xs=52.22*0.1405*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBF_WW120") {xs=3.935*0.1405*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW130") {xs=45.31*0.3021*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBF_WW130") {xs=3.632*0.3021*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBF_WW125") {xs=3.782*0.2132*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH120") {xs=0.9558*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH125") {xs=0.840*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH130") {xs=0.7414*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH110") {xs=1.335*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH140") {xs=0.6308*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH120") {xs=0.6092*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=0.5328*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH130") {xs=0.4626*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH110") {xs=0.8587*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH140") {xs=0.394*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WH125") {xs=(0.5328+0.840)*0.0627; weight=luminosity*xs/ngen;}
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
    else cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);

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
    arbre->SetBranchAddress("npv", &npv);
    arbre->SetBranchAddress("px_1", &px_1);
    arbre->SetBranchAddress("py_1", &py_1);
    arbre->SetBranchAddress("pz_1", &pz_1);
    arbre->SetBranchAddress("pt_1", &pt_1);
    arbre->SetBranchAddress("phi_1", &phi_1);
    arbre->SetBranchAddress("eta_1", &eta_1);
    arbre->SetBranchAddress("iso_1", &iso_1);
    arbre->SetBranchAddress("m_1", &m_1);
    arbre->SetBranchAddress("q_1", &q_1);
    arbre->SetBranchAddress("id_m_medium_1", &id_m_medium_1);
    arbre->SetBranchAddress("id_m_medium2016_1", &id_m_medium2016_1);
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("KD_bsm_mlt", &KD_bsm_mlt);
    arbre->SetBranchAddress("KD_int", &KD_int);
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
    arbre->SetBranchAddress("m_sv", &m_sv);
    arbre->SetBranchAddress("m_sv_DOWN", &m_sv_DOWN);
    arbre->SetBranchAddress("m_sv_UP", &m_sv_UP);
    arbre->SetBranchAddress("pt_sv", &pt_sv);
    arbre->SetBranchAddress("pt_sv_DOWN", &pt_sv_DOWN);
    arbre->SetBranchAddress("pt_sv_UP", &pt_sv_UP);
    arbre->SetBranchAddress("m_sv_UESDown", &m_sv_UESDown);
    arbre->SetBranchAddress("m_sv_UESUp", &m_sv_UESUp);
    arbre->SetBranchAddress("m_sv_JESDown", &m_sv_JESDown);
    arbre->SetBranchAddress("m_sv_JESUp", &m_sv_JESUp);
    arbre->SetBranchAddress("pt_sv_UESDown", &pt_sv_UESDown);
    arbre->SetBranchAddress("pt_sv_UESUp", &pt_sv_UESUp);
    arbre->SetBranchAddress("pt_sv_JESDown", &pt_sv_JESDown);
    arbre->SetBranchAddress("pt_sv_JESUp", &pt_sv_JESUp);
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("jpt_2", &jpt_2);
    arbre->SetBranchAddress("jphi_1", &jphi_1);
    arbre->SetBranchAddress("jphi_2", &jphi_2);
    arbre->SetBranchAddress("jeta_1", &jeta_1);
    arbre->SetBranchAddress("jeta_2", &jeta_2);
    arbre->SetBranchAddress("mjj", &mjj);
    arbre->SetBranchAddress("amcatNLO_weight", &amcatNLO_weight);
    arbre->SetBranchAddress("mjj_JESDown", &mjj_JESDown);
    arbre->SetBranchAddress("mjj_JESUp", &mjj_JESUp);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
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
    arbre->SetBranchAddress("byIsolationRerunMVA3oldDMwLTraw_2", &byIsolationRerunMVA3oldDMwLTraw_2);

    arbre->SetBranchAddress("matchIsoMu22eta2p1_1", &matchIsoMu22eta2p1_1);
    arbre->SetBranchAddress("matchIsoTkMu22eta2p1_1", &matchIsoTkMu22eta2p1_1);
    arbre->SetBranchAddress("matchIsoMu22_1", &matchIsoMu22_1);
    arbre->SetBranchAddress("matchIsoTkMu22_1", &matchIsoTkMu22_1);
    arbre->SetBranchAddress("matchIsoMu24_1", &matchIsoMu24_1);
    arbre->SetBranchAddress("matchIsoTkMu24_1", &matchIsoTkMu24_1);
    arbre->SetBranchAddress("matchIsoMu19Tau20_1", &matchIsoMu19Tau20_1);
    arbre->SetBranchAddress("matchIsoMu21Tau20_1", &matchIsoMu21Tau20_1);
    arbre->SetBranchAddress("filterIsoMu22eta2p1_1", &filterIsoMu22eta2p1_1);
    arbre->SetBranchAddress("filterIsoTkMu22eta2p1_1", &filterIsoTkMu22eta2p1_1);
    arbre->SetBranchAddress("filterIsoMu22_1", &filterIsoMu22_1);
    arbre->SetBranchAddress("filterIsoTkMu22_1", &filterIsoTkMu22_1);
    arbre->SetBranchAddress("filterIsoMu24_1", &filterIsoMu24_1);
    arbre->SetBranchAddress("filterIsoTkMu24_1", &filterIsoTkMu24_1);
    arbre->SetBranchAddress("filterIsoMu19Tau20_1", &filterIsoMu19Tau20_1);
    arbre->SetBranchAddress("filterIsoMu21Tau20_1", &filterIsoMu21Tau20_1);
    arbre->SetBranchAddress("passIsoMu22eta2p1", &passIsoMu22eta2p1);
    arbre->SetBranchAddress("passIsoTkMu22eta2p1", &passIsoTkMu22eta2p1);
    arbre->SetBranchAddress("passIsoMu22", &passIsoMu22);
    arbre->SetBranchAddress("passIsoTkMu22", &passIsoTkMu22);
    arbre->SetBranchAddress("passIsoMu24", &passIsoMu24);
    arbre->SetBranchAddress("passIsoTkMu24", &passIsoTkMu24);
    arbre->SetBranchAddress("passIsoMu19Tau20", &passIsoMu19Tau20);
    arbre->SetBranchAddress("passIsoMu21Tau20", &passIsoMu21Tau20);
    arbre->SetBranchAddress("matchIsoMu19Tau20_2", &matchIsoMu19Tau20_2);
    arbre->SetBranchAddress("matchIsoMu21Tau20_2", &matchIsoMu21Tau20_2);
    arbre->SetBranchAddress("filterIsoMu19Tau20_2", &filterIsoMu19Tau20_2);
    arbre->SetBranchAddress("filterIsoMu21Tau20_2", &filterIsoMu21Tau20_2);

    arbre->SetBranchAddress("l2_decayMode",&l2_decayMode);
    arbre->SetBranchAddress("againstElectronVLooseMVA6_2",&againstElectronVLooseMVA6_2);
    arbre->SetBranchAddress("againstMuonTight3_2",&againstMuonTight3_2);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    arbre->SetBranchAddress("m_vis",&m_vis);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    arbre->SetBranchAddress("genDR_2",&genDR_2);
    arbre->SetBranchAddress("numGenJets",&numGenJets);
    arbre->SetBranchAddress("bpt_1",&bpt_1);
    arbre->SetBranchAddress("bpt_2",&bpt_2);
    arbre->SetBranchAddress("bflavor_1",&bflavor_1);
    arbre->SetBranchAddress("bflavor_2",&bflavor_2);

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
   float bins1[] = {0,80,90,100,110,120,130,140,150,160,300};
   //float bins2[] = {0,95,115,135,155,400};
   float bins2[] = {0,95,115,155,400};

   float bins_pth[] = {0,100,150,200,250,300,5000};
   //float bins_mjj[] = {300,700,1100,1500,10000};
   float bins_mjj[] = {300,800,1300,10000};
   float bins_taupt[] = {0,1,10,11};
   float pI = TMath::Pi();
   float bins_dphijj[]={-pI, -3, -2.5, -2, -1.5, -1, -0.5, 0 , 0.5, 1, 1.5, 2, 2.5, pI};

   int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;
   int  binnum2 = sizeof(bins2)/sizeof(Float_t) - 1;
   int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
   int  binnum_pth = sizeof(bins_pth)/sizeof(Float_t) - 1;
   int  binnum_taupt = sizeof(bins_taupt)/sizeof(Float_t) - 1;
   int  binnum_mjj = sizeof(bins_mjj)/sizeof(Float_t) - 1;
   int  binnum_dphijj = sizeof(bins_dphijj)/sizeof(Float_t) - 1;

   TH1F *hincl=new TH1F ("hincl", "hincl", 16,0,160); hincl->Sumw2();
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
   
      TH2F* hCorr_OS=new TH2F("hCorr_OS","hCorr_OS",10,0,1,10,0,1);

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

   std::vector<TH2F*> h20_OS;
   std::vector<TH2F*> h20_SS;
   std::vector<TH2F*> h20_QCD;
   std::vector<TH2F*> h20_WOS;
   std::vector<TH2F*> h20_WSS;
   std::vector<TH2F*> h21_OS;
   std::vector<TH2F*> h21_SS;
   std::vector<TH2F*> h21_QCD;
   std::vector<TH2F*> h21_WOS;
   std::vector<TH2F*> h21_WSS;
   std::vector<TH2F*> h22_OS;
   std::vector<TH2F*> h22_SS;
   std::vector<TH2F*> h22_QCD;
   std::vector<TH2F*> h22_WOS;
   std::vector<TH2F*> h22_WSS;
   std::vector<TH2F*> h23_OS;
   std::vector<TH2F*> h23_SS;
   std::vector<TH2F*> h23_QCD;
   std::vector<TH2F*> h23_WOS;
   std::vector<TH2F*> h23_WSS;

   std::vector<TH2F*> h30_OS;
   std::vector<TH2F*> h30_SS;
   std::vector<TH2F*> h30_QCD;
   std::vector<TH2F*> h30_WOS;
   std::vector<TH2F*> h30_WSS;
   std::vector<TH2F*> h31_OS;
   std::vector<TH2F*> h31_SS;
   std::vector<TH2F*> h31_QCD;
   std::vector<TH2F*> h31_WOS;
   std::vector<TH2F*> h31_WSS;
   std::vector<TH2F*> h32_OS;
   std::vector<TH2F*> h32_SS;
   std::vector<TH2F*> h32_QCD;
   std::vector<TH2F*> h32_WOS;
   std::vector<TH2F*> h32_WSS;
   std::vector<TH2F*> h33_OS;
   std::vector<TH2F*> h33_SS;
   std::vector<TH2F*> h33_QCD;
   std::vector<TH2F*> h33_WOS;
   std::vector<TH2F*> h33_WSS;

   std::vector<TH2F*> h40_OS;
   std::vector<TH2F*> h40_SS;
   std::vector<TH2F*> h40_QCD;
   std::vector<TH2F*> h40_WOS;
   std::vector<TH2F*> h40_WSS;
   std::vector<TH2F*> h41_OS;
   std::vector<TH2F*> h41_SS;
   std::vector<TH2F*> h41_QCD;
   std::vector<TH2F*> h41_WOS;
   std::vector<TH2F*> h41_WSS;
   std::vector<TH2F*> h42_OS;
   std::vector<TH2F*> h42_SS;
   std::vector<TH2F*> h42_QCD;
   std::vector<TH2F*> h42_WOS;
   std::vector<TH2F*> h42_WSS;
   std::vector<TH2F*> h43_OS;
   std::vector<TH2F*> h43_SS;
   std::vector<TH2F*> h43_QCD;
   std::vector<TH2F*> h43_WOS;
   std::vector<TH2F*> h43_WSS;


   std::vector<TH2F*> h50_OS;
   std::vector<TH2F*> h50_SS;
   std::vector<TH2F*> h50_QCD;
   std::vector<TH2F*> h50_WOS;
   std::vector<TH2F*> h50_WSS;
   std::vector<TH2F*> h51_OS;
   std::vector<TH2F*> h51_SS;
   std::vector<TH2F*> h51_QCD;
   std::vector<TH2F*> h51_WOS;
   std::vector<TH2F*> h51_WSS;
   std::vector<TH2F*> h52_OS;
   std::vector<TH2F*> h52_SS;
   std::vector<TH2F*> h52_QCD;
   std::vector<TH2F*> h52_WOS;
   std::vector<TH2F*> h52_WSS;
   std::vector<TH2F*> h53_OS;
   std::vector<TH2F*> h53_SS;
   std::vector<TH2F*> h53_QCD;
   std::vector<TH2F*> h53_WOS;
   std::vector<TH2F*> h53_WSS;


   std::vector<TH2F*> h60_OS;
   std::vector<TH2F*> h60_SS;
   std::vector<TH2F*> h60_QCD;
   std::vector<TH2F*> h60_WOS;
   std::vector<TH2F*> h60_WSS;
   std::vector<TH2F*> h61_OS;
   std::vector<TH2F*> h61_SS;
   std::vector<TH2F*> h61_QCD;
   std::vector<TH2F*> h61_WOS;
   std::vector<TH2F*> h61_WSS;
   std::vector<TH2F*> h62_OS;
   std::vector<TH2F*> h62_SS;
   std::vector<TH2F*> h62_QCD;
   std::vector<TH2F*> h62_WOS;
   std::vector<TH2F*> h62_WSS;
   std::vector<TH2F*> h63_OS;
   std::vector<TH2F*> h63_SS;
   std::vector<TH2F*> h63_QCD;
   std::vector<TH2F*> h63_WOS;
   std::vector<TH2F*> h63_WSS;


   std::vector<TH2F*> h70_OS;
   std::vector<TH2F*> h70_SS;
   std::vector<TH2F*> h70_QCD;
   std::vector<TH2F*> h70_WOS;
   std::vector<TH2F*> h70_WSS;
   std::vector<TH2F*> h71_OS;
   std::vector<TH2F*> h71_SS;
   std::vector<TH2F*> h71_QCD;
   std::vector<TH2F*> h71_WOS;
   std::vector<TH2F*> h71_WSS;
   std::vector<TH2F*> h72_OS;
   std::vector<TH2F*> h72_SS;
   std::vector<TH2F*> h72_QCD;
   std::vector<TH2F*> h72_WOS;
   std::vector<TH2F*> h72_WSS;
   std::vector<TH2F*> h73_OS;
   std::vector<TH2F*> h73_SS;
   std::vector<TH2F*> h73_QCD;
   std::vector<TH2F*> h73_WOS;
   std::vector<TH2F*> h73_WSS;







   std::vector<TH2F*> h20_OSggH;
   std::vector<TH2F*> h20_SSggH;
   std::vector<TH2F*> h20_QCDggH;
   std::vector<TH2F*> h20_WOSggH;
   std::vector<TH2F*> h20_WSSggH;
   std::vector<TH2F*> h21_OSggH;
   std::vector<TH2F*> h21_SSggH;
   std::vector<TH2F*> h21_QCDggH;
   std::vector<TH2F*> h21_WOSggH;
   std::vector<TH2F*> h21_WSSggH;
   std::vector<TH2F*> h22_OSggH;
   std::vector<TH2F*> h22_SSggH;
   std::vector<TH2F*> h22_QCDggH;
   std::vector<TH2F*> h22_WOSggH;
   std::vector<TH2F*> h22_WSSggH;
   std::vector<TH2F*> h23_OSggH;
   std::vector<TH2F*> h23_SSggH;
   std::vector<TH2F*> h23_QCDggH;
   std::vector<TH2F*> h23_WOSggH;
   std::vector<TH2F*> h23_WSSggH;

   std::vector<TH2F*> h30_OSggH;
   std::vector<TH2F*> h30_SSggH;
   std::vector<TH2F*> h30_QCDggH;
   std::vector<TH2F*> h30_WOSggH;
   std::vector<TH2F*> h30_WSSggH;
   std::vector<TH2F*> h31_OSggH;
   std::vector<TH2F*> h31_SSggH;
   std::vector<TH2F*> h31_QCDggH;
   std::vector<TH2F*> h31_WOSggH;
   std::vector<TH2F*> h31_WSSggH;
   std::vector<TH2F*> h32_OSggH;
   std::vector<TH2F*> h32_SSggH;
   std::vector<TH2F*> h32_QCDggH;
   std::vector<TH2F*> h32_WOSggH;
   std::vector<TH2F*> h32_WSSggH;
   std::vector<TH2F*> h33_OSggH;
   std::vector<TH2F*> h33_SSggH;
   std::vector<TH2F*> h33_QCDggH;
   std::vector<TH2F*> h33_WOSggH;
   std::vector<TH2F*> h33_WSSggH;

   std::vector<TH2F*> h40_OSggH;
   std::vector<TH2F*> h40_SSggH;
   std::vector<TH2F*> h40_QCDggH;
   std::vector<TH2F*> h40_WOSggH;
   std::vector<TH2F*> h40_WSSggH;
   std::vector<TH2F*> h41_OSggH;
   std::vector<TH2F*> h41_SSggH;
   std::vector<TH2F*> h41_QCDggH;
   std::vector<TH2F*> h41_WOSggH;
   std::vector<TH2F*> h41_WSSggH;
   std::vector<TH2F*> h42_OSggH;
   std::vector<TH2F*> h42_SSggH;
   std::vector<TH2F*> h42_QCDggH;
   std::vector<TH2F*> h42_WOSggH;
   std::vector<TH2F*> h42_WSSggH;
   std::vector<TH2F*> h43_OSggH;
   std::vector<TH2F*> h43_SSggH;
   std::vector<TH2F*> h43_QCDggH;
   std::vector<TH2F*> h43_WOSggH;
   std::vector<TH2F*> h43_WSSggH;


   std::vector<TH2F*> h50_OSggH;
   std::vector<TH2F*> h50_SSggH;
   std::vector<TH2F*> h50_QCDggH;
   std::vector<TH2F*> h50_WOSggH;
   std::vector<TH2F*> h50_WSSggH;
   std::vector<TH2F*> h51_OSggH;
   std::vector<TH2F*> h51_SSggH;
   std::vector<TH2F*> h51_QCDggH;
   std::vector<TH2F*> h51_WOSggH;
   std::vector<TH2F*> h51_WSSggH;
   std::vector<TH2F*> h52_OSggH;
   std::vector<TH2F*> h52_SSggH;
   std::vector<TH2F*> h52_QCDggH;
   std::vector<TH2F*> h52_WOSggH;
   std::vector<TH2F*> h52_WSSggH;
   std::vector<TH2F*> h53_OSggH;
   std::vector<TH2F*> h53_SSggH;
   std::vector<TH2F*> h53_QCDggH;
   std::vector<TH2F*> h53_WOSggH;
   std::vector<TH2F*> h53_WSSggH;


   std::vector<TH2F*> h60_OSggH;
   std::vector<TH2F*> h60_SSggH;
   std::vector<TH2F*> h60_QCDggH;
   std::vector<TH2F*> h60_WOSggH;
   std::vector<TH2F*> h60_WSSggH;
   std::vector<TH2F*> h61_OSggH;
   std::vector<TH2F*> h61_SSggH;
   std::vector<TH2F*> h61_QCDggH;
   std::vector<TH2F*> h61_WOSggH;
   std::vector<TH2F*> h61_WSSggH;
   std::vector<TH2F*> h62_OSggH;
   std::vector<TH2F*> h62_SSggH;
   std::vector<TH2F*> h62_QCDggH;
   std::vector<TH2F*> h62_WOSggH;
   std::vector<TH2F*> h62_WSSggH;
   std::vector<TH2F*> h63_OSggH;
   std::vector<TH2F*> h63_SSggH;
   std::vector<TH2F*> h63_QCDggH;
   std::vector<TH2F*> h63_WOSggH;
   std::vector<TH2F*> h63_WSSggH;


   std::vector<TH2F*> h70_OSggH;
   std::vector<TH2F*> h70_SSggH;
   std::vector<TH2F*> h70_QCDggH;
   std::vector<TH2F*> h70_WOSggH;
   std::vector<TH2F*> h70_WSSggH;
   std::vector<TH2F*> h71_OSggH;
   std::vector<TH2F*> h71_SSggH;
   std::vector<TH2F*> h71_QCDggH;
   std::vector<TH2F*> h71_WOSggH;
   std::vector<TH2F*> h71_WSSggH;
   std::vector<TH2F*> h72_OSggH;
   std::vector<TH2F*> h72_SSggH;
   std::vector<TH2F*> h72_QCDggH;
   std::vector<TH2F*> h72_WOSggH;
   std::vector<TH2F*> h72_WSSggH;
   std::vector<TH2F*> h73_OSggH;
   std::vector<TH2F*> h73_SSggH;
   std::vector<TH2F*> h73_QCDggH;
   std::vector<TH2F*> h73_WOSggH;
   std::vector<TH2F*> h73_WSSggH;





   std::vector<TH1F*> h1D_OS;
   std::vector<TH1F*> h1D_SS;
   std::vector<TH1F*> h1D_QCD;
   std::vector<TH1F*> h1D_WOS;
   std::vector<TH1F*> h1D_WSS;


   std::vector<TH1F*> h1D_jpt1_VBF_OS;
   std::vector<TH1F*> h1D_jeta1_VBF_OS;
   std::vector<TH1F*> h1D_phi1_VBF_OS;
   std::vector<TH1F*> h1D_jpt2_VBF_OS;
   std::vector<TH1F*> h1D_jeta2_VBF_OS;
   std::vector<TH1F*> h1D_phi2_VBF_OS;
   std::vector<TH1F*> h1D_mjj_VBF_OS;
   std::vector<TH1F*> h1D_met_VBF_OS;


   std::vector<TH1F*> h1D_jpt1_VBF_SS;
   std::vector<TH1F*> h1D_jeta1_VBF_SS;
   std::vector<TH1F*> h1D_phi1_VBF_SS;
   std::vector<TH1F*> h1D_jpt2_VBF_SS;
   std::vector<TH1F*> h1D_jeta2_VBF_SS;
   std::vector<TH1F*> h1D_phi2_VBF_SS;
   std::vector<TH1F*> h1D_mjj_VBF_SS;
   std::vector<TH1F*> h1D_met_VBF_SS;


   std::vector<TH1F*> h1D_jpt1_VBF_WSS;
   std::vector<TH1F*> h1D_jeta1_VBF_WSS;
   std::vector<TH1F*> h1D_phi1_VBF_WSS;
   std::vector<TH1F*> h1D_jpt2_VBF_WSS;
   std::vector<TH1F*> h1D_jeta2_VBF_WSS;
   std::vector<TH1F*> h1D_phi2_VBF_WSS;
   std::vector<TH1F*> h1D_mjj_VBF_WSS;
   std::vector<TH1F*> h1D_met_VBF_WSS;


   std::vector<TH1F*> h1D_jpt1_VBF_WOS;
   std::vector<TH1F*> h1D_jeta1_VBF_WOS;
   std::vector<TH1F*> h1D_phi1_VBF_WOS;
   std::vector<TH1F*> h1D_jpt2_VBF_WOS;
   std::vector<TH1F*> h1D_jeta2_VBF_WOS;
   std::vector<TH1F*> h1D_phi2_VBF_WOS;
   std::vector<TH1F*> h1D_mjj_VBF_WOS;
   std::vector<TH1F*> h1D_met_VBF_WOS;

   std::vector<TH1F*> h1D_jpt1_VBF_QCD;
   std::vector<TH1F*> h1D_jeta1_VBF_QCD;
   std::vector<TH1F*> h1D_phi1_VBF_QCD;
   std::vector<TH1F*> h1D_jpt2_VBF_QCD;
   std::vector<TH1F*> h1D_jeta2_VBF_QCD;
   std::vector<TH1F*> h1D_phi2_VBF_QCD;
   std::vector<TH1F*> h1D_mjj_VBF_QCD;
   std::vector<TH1F*> h1D_met_VBF_QCD;


   std::vector<TH1F*> hmelaDCP_0jet_OS;
   std::vector<TH1F*> hmelaDCP_0jet_SS;
   std::vector<TH1F*> hmelaDCP_0jet_QCD;
   std::vector<TH1F*> hmelaDCP_0jet_WOS;
   std::vector<TH1F*> hmelaDCP_0jet_WSS;

   std::vector<TH1F*> hmelaDCPggH_0jet_OS;
   std::vector<TH1F*> hmelaDCPggH_0jet_SS;
   std::vector<TH1F*> hmelaDCPggH_0jet_QCD;
   std::vector<TH1F*> hmelaDCPggH_0jet_WOS;
   std::vector<TH1F*> hmelaDCPggH_0jet_WSS;

   std::vector<TH1F*> hmelaD0minusggH_0jet_OS;
   std::vector<TH1F*> hmelaD0minusggH_0jet_SS;
   std::vector<TH1F*> hmelaD0minusggH_0jet_QCD;
   std::vector<TH1F*> hmelaD0minusggH_0jet_WOS;
   std::vector<TH1F*> hmelaD0minusggH_0jet_WSS;

   std::vector<TH1F*> hmelaD0minus_0jet_OS;
   std::vector<TH1F*> hmelaD0minus_0jet_SS;
   std::vector<TH1F*> hmelaD0minus_0jet_QCD;
   std::vector<TH1F*> hmelaD0minus_0jet_WOS;
   std::vector<TH1F*> hmelaD0minus_0jet_WSS;


   std::vector<TH1F*> hmelaDPhijj_0jet_OS;
   std::vector<TH1F*> hmelaDPhijj_0jet_SS;
   std::vector<TH1F*> hmelaDPhijj_0jet_QCD;
   std::vector<TH1F*> hmelaDPhijj_0jet_WOS;
   std::vector<TH1F*> hmelaDPhijj_0jet_WSS;

   std::vector<TH1F*> hmelaDPhiUnsignedjj_0jet_OS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_0jet_SS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_0jet_QCD;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_0jet_WOS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_0jet_WSS;



   std::vector<TH1F*> hmelaDCP_VBF_OS;
   std::vector<TH1F*> hmelaDCP_VBF_SS;
   std::vector<TH1F*> hmelaDCP_VBF_QCD;
   std::vector<TH1F*> hmelaDCP_VBF_WOS;
   std::vector<TH1F*> hmelaDCP_VBF_WSS;

   std::vector<TH1F*> hmelaDCPggH_VBF_OS;
   std::vector<TH1F*> hmelaDCPggH_VBF_SS;
   std::vector<TH1F*> hmelaDCPggH_VBF_QCD;
   std::vector<TH1F*> hmelaDCPggH_VBF_WOS;
   std::vector<TH1F*> hmelaDCPggH_VBF_WSS;

   std::vector<TH1F*> hmelaD0minusggH_VBF_OS;
   std::vector<TH1F*> hmelaD0minusggH_VBF_SS;
   std::vector<TH1F*> hmelaD0minusggH_VBF_QCD;
   std::vector<TH1F*> hmelaD0minusggH_VBF_WOS;
   std::vector<TH1F*> hmelaD0minusggH_VBF_WSS;

   std::vector<TH1F*> hmelaD0minus_VBF_OS;
   std::vector<TH1F*> hmelaD0minus_VBF_SS;
   std::vector<TH1F*> hmelaD0minus_VBF_QCD;
   std::vector<TH1F*> hmelaD0minus_VBF_WOS;
   std::vector<TH1F*> hmelaD0minus_VBF_WSS;


   std::vector<TH1F*> hmelaDPhijj_VBF_OS;
   std::vector<TH1F*> hmelaDPhijj_VBF_SS;
   std::vector<TH1F*> hmelaDPhijj_VBF_QCD;
   std::vector<TH1F*> hmelaDPhijj_VBF_WOS;
   std::vector<TH1F*> hmelaDPhijj_VBF_WSS;

   std::vector<TH1F*> hmelaDPhiUnsignedjj_VBF_OS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_VBF_SS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_VBF_QCD;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_VBF_WOS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_VBF_WSS;


   std::vector<TH1F*> hmelaDCP_boosted_OS;
   std::vector<TH1F*> hmelaDCP_boosted_SS;
   std::vector<TH1F*> hmelaDCP_boosted_QCD;
   std::vector<TH1F*> hmelaDCP_boosted_WOS;
   std::vector<TH1F*> hmelaDCP_boosted_WSS;

   std::vector<TH1F*> hmelaDCPggH_boosted_OS;
   std::vector<TH1F*> hmelaDCPggH_boosted_SS;
   std::vector<TH1F*> hmelaDCPggH_boosted_QCD;
   std::vector<TH1F*> hmelaDCPggH_boosted_WOS;
   std::vector<TH1F*> hmelaDCPggH_boosted_WSS;

   std::vector<TH1F*> hmelaD0minusggH_boosted_OS;
   std::vector<TH1F*> hmelaD0minusggH_boosted_SS;
   std::vector<TH1F*> hmelaD0minusggH_boosted_QCD;
   std::vector<TH1F*> hmelaD0minusggH_boosted_WOS;
   std::vector<TH1F*> hmelaD0minusggH_boosted_WSS;

   std::vector<TH1F*> hmelaD0minus_boosted_OS;
   std::vector<TH1F*> hmelaD0minus_boosted_SS;
   std::vector<TH1F*> hmelaD0minus_boosted_QCD;
   std::vector<TH1F*> hmelaD0minus_boosted_WOS;
   std::vector<TH1F*> hmelaD0minus_boosted_WSS;


   std::vector<TH1F*> hmelaDPhijj_boosted_OS;
   std::vector<TH1F*> hmelaDPhijj_boosted_SS;
   std::vector<TH1F*> hmelaDPhijj_boosted_QCD;
   std::vector<TH1F*> hmelaDPhijj_boosted_WOS;
   std::vector<TH1F*> hmelaDPhijj_boosted_WSS;

   std::vector<TH1F*> hmelaDPhiUnsignedjj_boosted_OS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_boosted_SS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_boosted_QCD;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_boosted_WOS;
   std::vector<TH1F*> hmelaDPhiUnsignedjj_boosted_WSS;





   int nbhist=1;
   if (tes==100) nbhist=56;
   if (tes==1) nbhist=12;
   if (tes==16) nbhist=6;
   if (tes==17) nbhist=12;
   if (tes==18) nbhist=4;
   if (tes==19) nbhist=6;

   for (int k=0; k<nbhist; ++k){
        ostringstream HNn70; HNn70 << "n70" << k;
        ostringstream HNn70SS; HNn70SS << "n70SS" << k;
        n70.push_back(new TH1F (HNn70.str().c_str(),"InvMa",18,0,18)); n70[k]->Sumw2();
        n70SS.push_back(new TH1F (HNn70SS.str().c_str(),"InvMa",18,0,18)); n70SS[k]->Sumw2();

        ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
        ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
        ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
        h0_OS.push_back(new TH2F (HNS0OS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_OS[k]->Sumw2();
        h1_OS.push_back(new TH2F (HNS1OS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_OS[k]->Sumw2();
        h2_OS.push_back(new TH2F (HNS2OS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_OS[k]->Sumw2();
   

        ostringstream HNS0SS; HNS0SS << "h0_SS" << k;
        ostringstream HNS1SS; HNS1SS << "h1_SS" << k;
        ostringstream HNS2SS; HNS2SS << "h2_SS" << k;
        h0_SS.push_back(new TH2F (HNS0SS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_SS[k]->Sumw2();
        h1_SS.push_back(new TH2F (HNS1SS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_SS[k]->Sumw2();
        h2_SS.push_back(new TH2F (HNS2SS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_SS[k]->Sumw2();



        ostringstream HNS0QCD; HNS0QCD << "h0_QCD" << k;
        ostringstream HNS1QCD; HNS1QCD << "h1_QCD" << k;
        ostringstream HNS2QCD; HNS2QCD << "h2_QCD" << k;
        h0_QCD.push_back(new TH2F (HNS0QCD.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_QCD[k]->Sumw2();
        h1_QCD.push_back(new TH2F (HNS1QCD.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_QCD[k]->Sumw2();
        h2_QCD.push_back(new TH2F (HNS2QCD.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_QCD[k]->Sumw2();



        ostringstream HNS0WOS; HNS0WOS << "h0_SS" << k;
        ostringstream HNS1WOS; HNS1WOS << "h1_SS" << k;
        ostringstream HNS2WOS; HNS2WOS << "h2_SS" << k;
        h0_WOS.push_back(new TH2F (HNS0WOS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_WOS[k]->Sumw2();
        h1_WOS.push_back(new TH2F (HNS1WOS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_WOS[k]->Sumw2();
        h2_WOS.push_back(new TH2F (HNS2WOS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_WOS[k]->Sumw2();

        ostringstream HNS0WSS; HNS0WSS << "h0_SS" << k;
        ostringstream HNS1WSS; HNS1WSS << "h1_SS" << k;
        ostringstream HNS2WSS; HNS2WSS << "h2_SS" << k;
        h0_WSS.push_back(new TH2F (HNS0WSS.str().c_str(),"InvMa",binnum_taupt,bins_taupt,binnum0,bins0)); h0_WSS[k]->Sumw2();
        h1_WSS.push_back(new TH2F (HNS1WSS.str().c_str(),"InvMa",binnum_pth,bins_pth,binnum1,bins1)); h1_WSS[k]->Sumw2();
        h2_WSS.push_back(new TH2F (HNS2WSS.str().c_str(),"InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h2_WSS[k]->Sumw2();


//////////////////////

	h20_OS.push_back(new TH2F ("h20_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_OS[k]->Sumw2();
        h21_OS.push_back(new TH2F ("h21_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_OS[k]->Sumw2();
        h22_OS.push_back(new TH2F ("h22_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_OS[k]->Sumw2();
        h23_OS.push_back(new TH2F ("h23_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_OS[k]->Sumw2();

   
	h20_SS.push_back(new TH2F ("h20_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_SS[k]->Sumw2();
        h21_SS.push_back(new TH2F ("h21_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_SS[k]->Sumw2();
        h22_SS.push_back(new TH2F ("h22_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_SS[k]->Sumw2();
        h23_SS.push_back(new TH2F ("h23_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_SS[k]->Sumw2();

	h20_QCD.push_back(new TH2F ("h20_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_QCD[k]->Sumw2();
        h21_QCD.push_back(new TH2F ("h21_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_QCD[k]->Sumw2();
        h22_QCD.push_back(new TH2F ("h22_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_QCD[k]->Sumw2();
        h23_QCD.push_back(new TH2F ("h23_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_QCD[k]->Sumw2();

	h20_WOS.push_back(new TH2F ("h20_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_WOS[k]->Sumw2();
        h21_WOS.push_back(new TH2F ("h21_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_WOS[k]->Sumw2();
        h22_WOS.push_back(new TH2F ("h22_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_WOS[k]->Sumw2();
        h23_WOS.push_back(new TH2F ("h23_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_WOS[k]->Sumw2();

	h20_WSS.push_back(new TH2F ("h20_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_WSS[k]->Sumw2();
        h21_WSS.push_back(new TH2F ("h21_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_WSS[k]->Sumw2();
        h22_WSS.push_back(new TH2F ("h22_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_WSS[k]->Sumw2();
        h23_WSS.push_back(new TH2F ("h23_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_WSS[k]->Sumw2();
///
	h30_OS.push_back(new TH2F ("h30_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_OS[k]->Sumw2();
        h31_OS.push_back(new TH2F ("h31_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_OS[k]->Sumw2();
        h32_OS.push_back(new TH2F ("h32_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_OS[k]->Sumw2();
        h33_OS.push_back(new TH2F ("h33_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_OS[k]->Sumw2();


	h30_SS.push_back(new TH2F ("h30_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_SS[k]->Sumw2();
        h31_SS.push_back(new TH2F ("h31_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_SS[k]->Sumw2();
        h32_SS.push_back(new TH2F ("h32_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_SS[k]->Sumw2();
        h33_SS.push_back(new TH2F ("h33_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_SS[k]->Sumw2();

	h30_QCD.push_back(new TH2F ("h30_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_QCD[k]->Sumw2();
        h31_QCD.push_back(new TH2F ("h31_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_QCD[k]->Sumw2();
        h32_QCD.push_back(new TH2F ("h32_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_QCD[k]->Sumw2();
        h33_QCD.push_back(new TH2F ("h33_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_QCD[k]->Sumw2();

	h30_WOS.push_back(new TH2F ("h30_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_WOS[k]->Sumw2();
        h31_WOS.push_back(new TH2F ("h31_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_WOS[k]->Sumw2();
        h32_WOS.push_back(new TH2F ("h32_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_WOS[k]->Sumw2();
        h33_WOS.push_back(new TH2F ("h33_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_WOS[k]->Sumw2();

	h30_WSS.push_back(new TH2F ("h30_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_WSS[k]->Sumw2();
        h31_WSS.push_back(new TH2F ("h31_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_WSS[k]->Sumw2();
        h32_WSS.push_back(new TH2F ("h32_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_WSS[k]->Sumw2();
        h33_WSS.push_back(new TH2F ("h33_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_WSS[k]->Sumw2();

//////
	h40_OS.push_back(new TH2F ("h40_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_OS[k]->Sumw2();
        h41_OS.push_back(new TH2F ("h41_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_OS[k]->Sumw2();
        h42_OS.push_back(new TH2F ("h42_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_OS[k]->Sumw2();
        h43_OS.push_back(new TH2F ("h43_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_OS[k]->Sumw2();

	h40_SS.push_back(new TH2F ("h40_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_SS[k]->Sumw2();
        h41_SS.push_back(new TH2F ("h41_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_SS[k]->Sumw2();
        h42_SS.push_back(new TH2F ("h42_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_SS[k]->Sumw2();
        h43_SS.push_back(new TH2F ("h43_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_SS[k]->Sumw2();

	h40_QCD.push_back(new TH2F ("h40_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_QCD[k]->Sumw2();
        h41_QCD.push_back(new TH2F ("h41_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_QCD[k]->Sumw2();
        h42_QCD.push_back(new TH2F ("h42_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_QCD[k]->Sumw2();
        h43_QCD.push_back(new TH2F ("h43_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_QCD[k]->Sumw2();

	h40_WOS.push_back(new TH2F ("h40_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_WOS[k]->Sumw2();
        h41_WOS.push_back(new TH2F ("h41_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_WOS[k]->Sumw2();
        h42_WOS.push_back(new TH2F ("h42_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_WOS[k]->Sumw2();
        h43_WOS.push_back(new TH2F ("h43_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_WOS[k]->Sumw2();

	h40_WSS.push_back(new TH2F ("h40_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_WSS[k]->Sumw2();
        h41_WSS.push_back(new TH2F ("h41_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_WSS[k]->Sumw2();
        h42_WSS.push_back(new TH2F ("h42_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_WSS[k]->Sumw2();
        h43_WSS.push_back(new TH2F ("h43_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_WSS[k]->Sumw2();

//////////
	
	h50_OS.push_back(new TH2F ("h50_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_OS[k]->Sumw2();
        h51_OS.push_back(new TH2F ("h51_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_OS[k]->Sumw2();
        h52_OS.push_back(new TH2F ("h52_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_OS[k]->Sumw2();
        h53_OS.push_back(new TH2F ("h53_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_OS[k]->Sumw2();
	
	h50_SS.push_back(new TH2F ("h50_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_SS[k]->Sumw2();
        h51_SS.push_back(new TH2F ("h51_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_SS[k]->Sumw2();
        h52_SS.push_back(new TH2F ("h52_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_SS[k]->Sumw2();
        h53_SS.push_back(new TH2F ("h53_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_SS[k]->Sumw2();

	h50_QCD.push_back(new TH2F ("h50_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_QCD[k]->Sumw2();
        h51_QCD.push_back(new TH2F ("h51_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_QCD[k]->Sumw2();
        h52_QCD.push_back(new TH2F ("h52_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_QCD[k]->Sumw2();
        h53_QCD.push_back(new TH2F ("h53_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_QCD[k]->Sumw2();

	h50_WOS.push_back(new TH2F ("h50_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_WOS[k]->Sumw2();
        h51_WOS.push_back(new TH2F ("h51_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_WOS[k]->Sumw2();
        h52_WOS.push_back(new TH2F ("h52_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_WOS[k]->Sumw2();
        h53_WOS.push_back(new TH2F ("h53_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_WOS[k]->Sumw2();

	h50_WSS.push_back(new TH2F ("h50_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_WSS[k]->Sumw2();
        h51_WSS.push_back(new TH2F ("h51_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_WSS[k]->Sumw2();
        h52_WSS.push_back(new TH2F ("h52_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_WSS[k]->Sumw2();
        h53_WSS.push_back(new TH2F ("h53_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_WSS[k]->Sumw2();

//////
	h60_OS.push_back(new TH2F ("h60_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_OS[k]->Sumw2();
        h61_OS.push_back(new TH2F ("h61_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_OS[k]->Sumw2();
        h62_OS.push_back(new TH2F ("h62_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_OS[k]->Sumw2();
        h63_OS.push_back(new TH2F ("h63_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_OS[k]->Sumw2();

	h60_SS.push_back(new TH2F ("h60_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_SS[k]->Sumw2();
        h61_SS.push_back(new TH2F ("h61_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_SS[k]->Sumw2();
        h62_SS.push_back(new TH2F ("h62_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_SS[k]->Sumw2();
        h63_SS.push_back(new TH2F ("h63_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_SS[k]->Sumw2();

	h60_QCD.push_back(new TH2F ("h60_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_QCD[k]->Sumw2();
        h61_QCD.push_back(new TH2F ("h61_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_QCD[k]->Sumw2();
        h62_QCD.push_back(new TH2F ("h62_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_QCD[k]->Sumw2();
        h63_QCD.push_back(new TH2F ("h63_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_QCD[k]->Sumw2();

	h60_WOS.push_back(new TH2F ("h60_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_WOS[k]->Sumw2();
        h61_WOS.push_back(new TH2F ("h61_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_WOS[k]->Sumw2();
        h62_WOS.push_back(new TH2F ("h62_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_WOS[k]->Sumw2();
        h63_WOS.push_back(new TH2F ("h63_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_WOS[k]->Sumw2();

	h60_WSS.push_back(new TH2F ("h60_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_WSS[k]->Sumw2();
        h61_WSS.push_back(new TH2F ("h61_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_WSS[k]->Sumw2();
        h62_WSS.push_back(new TH2F ("h62_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_WSS[k]->Sumw2();
        h63_WSS.push_back(new TH2F ("h63_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_WSS[k]->Sumw2();
////////////

	h70_OS.push_back(new TH2F ("h70_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_OS[k]->Sumw2();
        h71_OS.push_back(new TH2F ("h71_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_OS[k]->Sumw2();
        h72_OS.push_back(new TH2F ("h72_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_OS[k]->Sumw2();
        h73_OS.push_back(new TH2F ("h73_OS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_OS[k]->Sumw2();

	h70_SS.push_back(new TH2F ("h70_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_SS[k]->Sumw2();
        h71_SS.push_back(new TH2F ("h71_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_SS[k]->Sumw2();
        h72_SS.push_back(new TH2F ("h72_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_SS[k]->Sumw2();
        h73_SS.push_back(new TH2F ("h73_SS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_SS[k]->Sumw2();

	h70_QCD.push_back(new TH2F ("h70_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_QCD[k]->Sumw2();
        h71_QCD.push_back(new TH2F ("h71_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_QCD[k]->Sumw2();
        h72_QCD.push_back(new TH2F ("h72_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_QCD[k]->Sumw2();
        h73_QCD.push_back(new TH2F ("h73_QCD","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_QCD[k]->Sumw2();

	h70_WOS.push_back(new TH2F ("h70_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_WOS[k]->Sumw2();
        h71_WOS.push_back(new TH2F ("h71_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_WOS[k]->Sumw2();
        h72_WOS.push_back(new TH2F ("h72_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_WOS[k]->Sumw2();
        h73_WOS.push_back(new TH2F ("h73_WOS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_WOS[k]->Sumw2();

	h70_WSS.push_back(new TH2F ("h70_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_WSS[k]->Sumw2();
        h71_WSS.push_back(new TH2F ("h71_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_WSS[k]->Sumw2();
        h72_WSS.push_back(new TH2F ("h72_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_WSS[k]->Sumw2();
        h73_WSS.push_back(new TH2F ("h73_WSS","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_WSS[k]->Sumw2();



   /////////////////////////////////
   //
   

	h20_OSggH.push_back(new TH2F ("h20_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_OSggH[k]->Sumw2();
        h21_OSggH.push_back(new TH2F ("h21_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_OSggH[k]->Sumw2();
        h22_OSggH.push_back(new TH2F ("h22_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_OSggH[k]->Sumw2();
        h23_OSggH.push_back(new TH2F ("h23_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_OSggH[k]->Sumw2();

	h20_SSggH.push_back(new TH2F ("h20_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_SSggH[k]->Sumw2();
        h21_SSggH.push_back(new TH2F ("h21_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_SSggH[k]->Sumw2();
        h22_SSggH.push_back(new TH2F ("h22_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_SSggH[k]->Sumw2();
        h23_SSggH.push_back(new TH2F ("h23_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_SSggH[k]->Sumw2();

	h20_QCDggH.push_back(new TH2F ("h20_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_QCDggH[k]->Sumw2();
        h21_QCDggH.push_back(new TH2F ("h21_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_QCDggH[k]->Sumw2();
        h22_QCDggH.push_back(new TH2F ("h22_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_QCDggH[k]->Sumw2();
        h23_QCDggH.push_back(new TH2F ("h23_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_QCDggH[k]->Sumw2();

	h20_WOSggH.push_back(new TH2F ("h20_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_WOSggH[k]->Sumw2();
        h21_WOSggH.push_back(new TH2F ("h21_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_WOSggH[k]->Sumw2();
        h22_WOSggH.push_back(new TH2F ("h22_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_WOSggH[k]->Sumw2();
        h23_WOSggH.push_back(new TH2F ("h23_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_WOSggH[k]->Sumw2();

	h20_WSSggH.push_back(new TH2F ("h20_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h20_WSSggH[k]->Sumw2();
        h21_WSSggH.push_back(new TH2F ("h21_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h21_WSSggH[k]->Sumw2();
        h22_WSSggH.push_back(new TH2F ("h22_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h22_WSSggH[k]->Sumw2();
        h23_WSSggH.push_back(new TH2F ("h23_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h23_WSSggH[k]->Sumw2();
///////

	h30_OSggH.push_back(new TH2F ("h30_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_OSggH[k]->Sumw2();
        h31_OSggH.push_back(new TH2F ("h31_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_OSggH[k]->Sumw2();
        h32_OSggH.push_back(new TH2F ("h32_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_OSggH[k]->Sumw2();
        h33_OSggH.push_back(new TH2F ("h33_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_OSggH[k]->Sumw2();
	
	h30_SSggH.push_back(new TH2F ("h30_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_SSggH[k]->Sumw2();
        h31_SSggH.push_back(new TH2F ("h31_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_SSggH[k]->Sumw2();
        h32_SSggH.push_back(new TH2F ("h32_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_SSggH[k]->Sumw2();
        h33_SSggH.push_back(new TH2F ("h33_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_SSggH[k]->Sumw2();

	h30_QCDggH.push_back(new TH2F ("h30_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_QCDggH[k]->Sumw2();
        h31_QCDggH.push_back(new TH2F ("h31_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_QCDggH[k]->Sumw2();
        h32_QCDggH.push_back(new TH2F ("h32_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_QCDggH[k]->Sumw2();
        h33_QCDggH.push_back(new TH2F ("h33_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_QCDggH[k]->Sumw2();

	h30_WOSggH.push_back(new TH2F ("h30_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_WOSggH[k]->Sumw2();
        h31_WOSggH.push_back(new TH2F ("h31_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_WOSggH[k]->Sumw2();
        h32_WOSggH.push_back(new TH2F ("h32_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_WOSggH[k]->Sumw2();
        h33_WOSggH.push_back(new TH2F ("h33_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_WOSggH[k]->Sumw2();

	h30_WSSggH.push_back(new TH2F ("h30_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h30_WSSggH[k]->Sumw2();
        h31_WSSggH.push_back(new TH2F ("h31_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h31_WSSggH[k]->Sumw2();
        h32_WSSggH.push_back(new TH2F ("h32_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h32_WSSggH[k]->Sumw2();
        h33_WSSggH.push_back(new TH2F ("h33_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h33_WSSggH[k]->Sumw2();
////////////////

	h40_OSggH.push_back(new TH2F ("h40_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_OSggH[k]->Sumw2();
        h41_OSggH.push_back(new TH2F ("h41_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_OSggH[k]->Sumw2();
        h42_OSggH.push_back(new TH2F ("h42_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_OSggH[k]->Sumw2();
        h43_OSggH.push_back(new TH2F ("h43_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_OSggH[k]->Sumw2();


	h40_SSggH.push_back(new TH2F ("h40_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_SSggH[k]->Sumw2();
        h41_SSggH.push_back(new TH2F ("h41_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_SSggH[k]->Sumw2();
        h42_SSggH.push_back(new TH2F ("h42_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_SSggH[k]->Sumw2();
        h43_SSggH.push_back(new TH2F ("h43_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_SSggH[k]->Sumw2();

	h40_QCDggH.push_back(new TH2F ("h40_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_QCDggH[k]->Sumw2();
        h41_QCDggH.push_back(new TH2F ("h41_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_QCDggH[k]->Sumw2();
        h42_QCDggH.push_back(new TH2F ("h42_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_QCDggH[k]->Sumw2();
        h43_QCDggH.push_back(new TH2F ("h43_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_QCDggH[k]->Sumw2();

	h40_WOSggH.push_back(new TH2F ("h40_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_WOSggH[k]->Sumw2();
        h41_WOSggH.push_back(new TH2F ("h41_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_WOSggH[k]->Sumw2();
        h42_WOSggH.push_back(new TH2F ("h42_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_WOSggH[k]->Sumw2();
        h43_WOSggH.push_back(new TH2F ("h43_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_WOSggH[k]->Sumw2();

	h40_WSSggH.push_back(new TH2F ("h40_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h40_WSSggH[k]->Sumw2();
        h41_WSSggH.push_back(new TH2F ("h41_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h41_WSSggH[k]->Sumw2();
        h42_WSSggH.push_back(new TH2F ("h42_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h42_WSSggH[k]->Sumw2();
        h43_WSSggH.push_back(new TH2F ("h43_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h43_WSSggH[k]->Sumw2();
///////////////

	h50_OSggH.push_back(new TH2F ("h50_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_OSggH[k]->Sumw2();
        h51_OSggH.push_back(new TH2F ("h51_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_OSggH[k]->Sumw2();
        h52_OSggH.push_back(new TH2F ("h52_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_OSggH[k]->Sumw2();
        h53_OSggH.push_back(new TH2F ("h53_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_OSggH[k]->Sumw2();


	h50_SSggH.push_back(new TH2F ("h50_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_SSggH[k]->Sumw2();
        h51_SSggH.push_back(new TH2F ("h51_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_SSggH[k]->Sumw2();
        h52_SSggH.push_back(new TH2F ("h52_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_SSggH[k]->Sumw2();
        h53_SSggH.push_back(new TH2F ("h53_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_SSggH[k]->Sumw2();

	h50_QCDggH.push_back(new TH2F ("h50_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_QCDggH[k]->Sumw2();
        h51_QCDggH.push_back(new TH2F ("h51_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_QCDggH[k]->Sumw2();
        h52_QCDggH.push_back(new TH2F ("h52_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_QCDggH[k]->Sumw2();
        h53_QCDggH.push_back(new TH2F ("h53_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_QCDggH[k]->Sumw2();

	h50_WOSggH.push_back(new TH2F ("h50_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_WOSggH[k]->Sumw2();
        h51_WOSggH.push_back(new TH2F ("h51_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_WOSggH[k]->Sumw2();
        h52_WOSggH.push_back(new TH2F ("h52_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_WOSggH[k]->Sumw2();
        h53_WOSggH.push_back(new TH2F ("h53_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_WOSggH[k]->Sumw2();

	h50_WSSggH.push_back(new TH2F ("h50_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h50_WSSggH[k]->Sumw2();
        h51_WSSggH.push_back(new TH2F ("h51_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h51_WSSggH[k]->Sumw2();
        h52_WSSggH.push_back(new TH2F ("h52_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h52_WSSggH[k]->Sumw2();
        h53_WSSggH.push_back(new TH2F ("h53_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h53_WSSggH[k]->Sumw2();

/////////////////


	h60_OSggH.push_back(new TH2F ("h60_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_OSggH[k]->Sumw2();
        h61_OSggH.push_back(new TH2F ("h61_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_OSggH[k]->Sumw2();
        h62_OSggH.push_back(new TH2F ("h62_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_OSggH[k]->Sumw2();
        h63_OSggH.push_back(new TH2F ("h63_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_OSggH[k]->Sumw2();


	h60_SSggH.push_back(new TH2F ("h60_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_SSggH[k]->Sumw2();
        h61_SSggH.push_back(new TH2F ("h61_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_SSggH[k]->Sumw2();
        h62_SSggH.push_back(new TH2F ("h62_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_SSggH[k]->Sumw2();
        h63_SSggH.push_back(new TH2F ("h63_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_SSggH[k]->Sumw2();

	h60_QCDggH.push_back(new TH2F ("h60_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_QCDggH[k]->Sumw2();
        h61_QCDggH.push_back(new TH2F ("h61_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_QCDggH[k]->Sumw2();
        h62_QCDggH.push_back(new TH2F ("h62_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_QCDggH[k]->Sumw2();
        h63_QCDggH.push_back(new TH2F ("h63_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_QCDggH[k]->Sumw2();

	h60_WOSggH.push_back(new TH2F ("h60_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_WOSggH[k]->Sumw2();
        h61_WOSggH.push_back(new TH2F ("h61_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_WOSggH[k]->Sumw2();
        h62_WOSggH.push_back(new TH2F ("h62_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_WOSggH[k]->Sumw2();
        h63_WOSggH.push_back(new TH2F ("h63_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_WOSggH[k]->Sumw2();

	h60_WSSggH.push_back(new TH2F ("h60_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h60_WSSggH[k]->Sumw2();
        h61_WSSggH.push_back(new TH2F ("h61_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h61_WSSggH[k]->Sumw2();
        h62_WSSggH.push_back(new TH2F ("h62_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h62_WSSggH[k]->Sumw2();
        h63_WSSggH.push_back(new TH2F ("h63_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h63_WSSggH[k]->Sumw2();

//////////////
	
	h70_OSggH.push_back(new TH2F ("h70_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_OSggH[k]->Sumw2();
        h71_OSggH.push_back(new TH2F ("h71_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_OSggH[k]->Sumw2();
        h72_OSggH.push_back(new TH2F ("h72_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_OSggH[k]->Sumw2();
        h73_OSggH.push_back(new TH2F ("h73_OSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_OSggH[k]->Sumw2();
	
	h70_SSggH.push_back(new TH2F ("h70_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_SSggH[k]->Sumw2();
        h71_SSggH.push_back(new TH2F ("h71_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_SSggH[k]->Sumw2();
        h72_SSggH.push_back(new TH2F ("h72_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_SSggH[k]->Sumw2();
        h73_SSggH.push_back(new TH2F ("h73_SSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_SSggH[k]->Sumw2();

	h70_QCDggH.push_back(new TH2F ("h70_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_QCDggH[k]->Sumw2();
        h71_QCDggH.push_back(new TH2F ("h71_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_QCDggH[k]->Sumw2();
        h72_QCDggH.push_back(new TH2F ("h72_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_QCDggH[k]->Sumw2();
        h73_QCDggH.push_back(new TH2F ("h73_QCDggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_QCDggH[k]->Sumw2();

	h70_WOSggH.push_back(new TH2F ("h70_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_WOSggH[k]->Sumw2();
        h71_WOSggH.push_back(new TH2F ("h71_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_WOSggH[k]->Sumw2();
        h72_WOSggH.push_back(new TH2F ("h72_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_WOSggH[k]->Sumw2();
        h73_WOSggH.push_back(new TH2F ("h73_WOSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_WOSggH[k]->Sumw2();

	h70_WSSggH.push_back(new TH2F ("h70_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h70_WSSggH[k]->Sumw2();
        h71_WSSggH.push_back(new TH2F ("h71_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h71_WSSggH[k]->Sumw2();
        h72_WSSggH.push_back(new TH2F ("h72_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h72_WSSggH[k]->Sumw2();
        h73_WSSggH.push_back(new TH2F ("h73_WSSggH","InvMa",binnum_mjj,bins_mjj,binnum2,bins2)); h73_WSSggH[k]->Sumw2();



   }


   for (int k=0; k<nbhist; ++k){
//booking histos
        hmelaDCP_0jet_OS.push_back(new TH1F ("hmelaDCP_0jet_OS","DCP",20,-1,1)); hmelaDCP_0jet_OS[k]->Sumw2();
        hmelaDCPggH_0jet_OS.push_back(new TH1F ("hmelaDCPggH_0jet_OS","DCPggH",20,-1,1)); hmelaDCPggH_0jet_OS[k]->Sumw2();
        hmelaD0minusggH_0jet_OS.push_back(new TH1F ("hmelaD0minusggH_0jet_OS","D0minusggH",10,0,1)); hmelaD0minusggH_0jet_OS[k]->Sumw2();
        hmelaD0minus_0jet_OS.push_back(new TH1F ("hmelaD0minus_0jet_OS","D0minus",10,0,1)); hmelaD0minus_0jet_OS[k]->Sumw2();
        hmelaDPhijj_0jet_OS.push_back(new TH1F ("hmelaDPhijj_0jet_OS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_0jet_OS[k]->Sumw2();
        hmelaDPhiUnsignedjj_0jet_OS.push_back(new TH1F ("hmelaDPhiUnsignedjj_0jet_OS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_0jet_OS[k]->Sumw2();

        hmelaDCP_VBF_OS.push_back(new TH1F ("hmelaDCP_VBF_OS","DCP",20,-1,1)); hmelaDCP_VBF_OS[k]->Sumw2();
        hmelaDCPggH_VBF_OS.push_back(new TH1F ("hmelaDCPggH_VBF_OS","DCPggH",20,-1,1)); hmelaDCPggH_VBF_OS[k]->Sumw2();
        hmelaD0minusggH_VBF_OS.push_back(new TH1F ("hmelaD0minusggH_VBF_OS","D0minusggH",10,0,1)); hmelaD0minusggH_VBF_OS[k]->Sumw2();
        hmelaD0minus_VBF_OS.push_back(new TH1F ("hmelaD0minus_VBF_OS","D0minus",10,0,1)); hmelaD0minus_VBF_OS[k]->Sumw2();
        hmelaDPhijj_VBF_OS.push_back(new TH1F ("hmelaDPhijj_VBF_OS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_VBF_OS[k]->Sumw2();
        hmelaDPhiUnsignedjj_VBF_OS.push_back(new TH1F ("hmelaDPhiUnsignedjj_VBF_OS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_VBF_OS[k]->Sumw2();


        hmelaDCP_boosted_OS.push_back(new TH1F ("hmelaDCP_boosted_OS","DCP",20,-1,1)); hmelaDCP_boosted_OS[k]->Sumw2();
        hmelaDCPggH_boosted_OS.push_back(new TH1F ("hmelaDCPggH_boosted_OS","DCPggH",20,-1,1)); hmelaDCPggH_boosted_OS[k]->Sumw2();
        hmelaD0minusggH_boosted_OS.push_back(new TH1F ("hmelaD0minusggH_boosted_OS","D0minusggH",10,0,1)); hmelaD0minusggH_boosted_OS[k]->Sumw2();
        hmelaD0minus_boosted_OS.push_back(new TH1F ("hmelaD0minus_boosted_OS","D0minus",10,0,1)); hmelaD0minus_boosted_OS[k]->Sumw2();
        hmelaDPhijj_boosted_OS.push_back(new TH1F ("hmelaDPhijj_boosted_OS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_boosted_OS[k]->Sumw2();
        hmelaDPhiUnsignedjj_boosted_OS.push_back(new TH1F ("hmelaDPhiUnsignedjj_boosted_OS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_boosted_OS[k]->Sumw2();

///SS
        hmelaDCP_0jet_SS.push_back(new TH1F ("hmelaDCP_0jet_SS","DCP",20,-1,1)); hmelaDCP_0jet_SS[k]->Sumw2();
        hmelaDCPggH_0jet_SS.push_back(new TH1F ("hmelaDCPggH_0jet_SS","DCPggH",20,-1,1)); hmelaDCPggH_0jet_SS[k]->Sumw2();
        hmelaD0minusggH_0jet_SS.push_back(new TH1F ("hmelaD0minusggH_0jet_SS","D0minusggH",10,0,1)); hmelaD0minusggH_0jet_SS[k]->Sumw2();
        hmelaD0minus_0jet_SS.push_back(new TH1F ("hmelaD0minus_0jet_SS","D0minus",10,0,1)); hmelaD0minus_0jet_SS[k]->Sumw2();
        hmelaDPhijj_0jet_SS.push_back(new TH1F ("hmelaDPhijj_0jet_SS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_0jet_SS[k]->Sumw2();
        hmelaDPhiUnsignedjj_0jet_SS.push_back(new TH1F ("hmelaDPhiUnsignedjj_0jet_SS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_0jet_SS[k]->Sumw2();

        hmelaDCP_VBF_SS.push_back(new TH1F ("hmelaDCP_VBF_SS","DCP",20,-1,1)); hmelaDCP_VBF_SS[k]->Sumw2();
        hmelaDCPggH_VBF_SS.push_back(new TH1F ("hmelaDCPggH_VBF_SS","DCPggH",20,-1,1)); hmelaDCPggH_VBF_SS[k]->Sumw2();
        hmelaD0minusggH_VBF_SS.push_back(new TH1F ("hmelaD0minusggH_VBF_SS","D0minusggH",10,0,1)); hmelaD0minusggH_VBF_SS[k]->Sumw2();
        hmelaD0minus_VBF_SS.push_back(new TH1F ("hmelaD0minus_VBF_SS","D0minus",10,0,1)); hmelaD0minus_VBF_SS[k]->Sumw2();
        hmelaDPhijj_VBF_SS.push_back(new TH1F ("hmelaDPhijj_VBF_SS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_VBF_SS[k]->Sumw2();
        hmelaDPhiUnsignedjj_VBF_SS.push_back(new TH1F ("hmelaDPhiUnsignedjj_VBF_SS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_VBF_SS[k]->Sumw2();


        hmelaDCP_boosted_SS.push_back(new TH1F ("hmelaDCP_boosted_SS","DCP",20,-1,1)); hmelaDCP_boosted_SS[k]->Sumw2();
        hmelaDCPggH_boosted_SS.push_back(new TH1F ("hmelaDCPggH_boosted_SS","DCPggH",20,-1,1)); hmelaDCPggH_boosted_SS[k]->Sumw2();
        hmelaD0minusggH_boosted_SS.push_back(new TH1F ("hmelaD0minusggH_boosted_SS","D0minusggH",10,0,1)); hmelaD0minusggH_boosted_SS[k]->Sumw2();
        hmelaD0minus_boosted_SS.push_back(new TH1F ("hmelaD0minus_boosted_SS","D0minus",10,0,1)); hmelaD0minus_boosted_SS[k]->Sumw2();
        hmelaDPhijj_boosted_SS.push_back(new TH1F ("hmelaDPhijj_boosted_SS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_boosted_SS[k]->Sumw2();
        hmelaDPhiUnsignedjj_boosted_SS.push_back(new TH1F ("hmelaDPhiUnsignedjj_boosted_SS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_boosted_SS[k]->Sumw2();

//QCD
        hmelaDCP_0jet_QCD.push_back(new TH1F ("hmelaDCP_0jet_QCD","DCP",20,-1,1)); hmelaDCP_0jet_QCD[k]->Sumw2();
        hmelaDCPggH_0jet_QCD.push_back(new TH1F ("hmelaDCPggH_0jet_QCD","DCPggH",20,-1,1)); hmelaDCPggH_0jet_QCD[k]->Sumw2();
        hmelaD0minusggH_0jet_QCD.push_back(new TH1F ("hmelaD0minusggH_0jet_QCD","D0minusggH",10,0,1)); hmelaD0minusggH_0jet_QCD[k]->Sumw2();
        hmelaD0minus_0jet_QCD.push_back(new TH1F ("hmelaD0minus_0jet_QCD","D0minus",10,0,1)); hmelaD0minus_0jet_QCD[k]->Sumw2();
        hmelaDPhijj_0jet_QCD.push_back(new TH1F ("hmelaDPhijj_0jet_QCD","DPhijj",64,-3.2,3.2)); hmelaDPhijj_0jet_QCD[k]->Sumw2();
        hmelaDPhiUnsignedjj_0jet_QCD.push_back(new TH1F ("hmelaDPhiUnsignedjj_0jet_QCD","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_0jet_QCD[k]->Sumw2();

        hmelaDCP_VBF_QCD.push_back(new TH1F ("hmelaDCP_VBF_QCD","DCP",20,-1,1)); hmelaDCP_VBF_QCD[k]->Sumw2();
        hmelaDCPggH_VBF_QCD.push_back(new TH1F ("hmelaDCPggH_VBF_QCD","DCPggH",20,-1,1)); hmelaDCPggH_VBF_QCD[k]->Sumw2();
        hmelaD0minusggH_VBF_QCD.push_back(new TH1F ("hmelaD0minusggH_VBF_QCD","D0minusggH",10,0,1)); hmelaD0minusggH_VBF_QCD[k]->Sumw2();
        hmelaD0minus_VBF_QCD.push_back(new TH1F ("hmelaD0minus_VBF_QCD","D0minus",10,0,1)); hmelaD0minus_VBF_QCD[k]->Sumw2();
        hmelaDPhijj_VBF_QCD.push_back(new TH1F ("hmelaDPhijj_VBF_QCD","DPhijj",64,-3.2,3.2)); hmelaDPhijj_VBF_QCD[k]->Sumw2();
        hmelaDPhiUnsignedjj_VBF_QCD.push_back(new TH1F ("hmelaDPhiUnsignedjj_VBF_QCD","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_VBF_QCD[k]->Sumw2();


        hmelaDCP_boosted_QCD.push_back(new TH1F ("hmelaDCP_boosted_QCD","DCP",20,-1,1)); hmelaDCP_boosted_QCD[k]->Sumw2();
        hmelaDCPggH_boosted_QCD.push_back(new TH1F ("hmelaDCPggH_boosted_QCD","DCPggH",20,-1,1)); hmelaDCPggH_boosted_QCD[k]->Sumw2();
        hmelaD0minusggH_boosted_QCD.push_back(new TH1F ("hmelaD0minusggH_boosted_QCD","D0minusggH",10,0,1)); hmelaD0minusggH_boosted_QCD[k]->Sumw2();
        hmelaD0minus_boosted_QCD.push_back(new TH1F ("hmelaD0minus_boosted_QCD","D0minus",10,0,1)); hmelaD0minus_boosted_QCD[k]->Sumw2();
        hmelaDPhijj_boosted_QCD.push_back(new TH1F ("hmelaDPhijj_boosted_QCD","DPhijj",64,-3.2,3.2)); hmelaDPhijj_boosted_QCD[k]->Sumw2();
        hmelaDPhiUnsignedjj_boosted_QCD.push_back(new TH1F ("hmelaDPhiUnsignedjj_boosted_QCD","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_boosted_QCD[k]->Sumw2();///////
///////

        hmelaDCP_0jet_WOS.push_back(new TH1F ("hmelaDCP_0jet_WOS","DCP",20,-1,1)); hmelaDCP_0jet_WOS[k]->Sumw2();
        hmelaDCPggH_0jet_WOS.push_back(new TH1F ("hmelaDCPggH_0jet_WOS","DCPggH",20,-1,1)); hmelaDCPggH_0jet_WOS[k]->Sumw2();
        hmelaD0minusggH_0jet_WOS.push_back(new TH1F ("hmelaD0minusggH_0jet_WOS","D0minusggH",10,0,1)); hmelaD0minusggH_0jet_WOS[k]->Sumw2();
        hmelaD0minus_0jet_WOS.push_back(new TH1F ("hmelaD0minus_0jet_WOS","D0minus",10,0,1)); hmelaD0minus_0jet_WOS[k]->Sumw2();
        hmelaDPhijj_0jet_WOS.push_back(new TH1F ("hmelaDPhijj_0jet_WOS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_0jet_WOS[k]->Sumw2();
        hmelaDPhiUnsignedjj_0jet_WOS.push_back(new TH1F ("hmelaDPhiUnsignedjj_0jet_WOS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_0jet_WOS[k]->Sumw2();

        hmelaDCP_VBF_WOS.push_back(new TH1F ("hmelaDCP_VBF_WOS","DCP",20,-1,1)); hmelaDCP_VBF_WOS[k]->Sumw2();
        hmelaDCPggH_VBF_WOS.push_back(new TH1F ("hmelaDCPggH_VBF_WOS","DCPggH",20,-1,1)); hmelaDCPggH_VBF_WOS[k]->Sumw2();
        hmelaD0minusggH_VBF_WOS.push_back(new TH1F ("hmelaD0minusggH_VBF_WOS","D0minusggH",10,0,1)); hmelaD0minusggH_VBF_WOS[k]->Sumw2();
        hmelaD0minus_VBF_WOS.push_back(new TH1F ("hmelaD0minus_VBF_WOS","D0minus",10,0,1)); hmelaD0minus_VBF_WOS[k]->Sumw2();
        hmelaDPhijj_VBF_WOS.push_back(new TH1F ("hmelaDPhijj_VBF_WOS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_VBF_WOS[k]->Sumw2();
        hmelaDPhiUnsignedjj_VBF_WOS.push_back(new TH1F ("hmelaDPhiUnsignedjj_VBF_WOS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_VBF_WOS[k]->Sumw2();


        hmelaDCP_boosted_WOS.push_back(new TH1F ("hmelaDCP_boosted_WOS","DCP",20,-1,1)); hmelaDCP_boosted_WOS[k]->Sumw2();
        hmelaDCPggH_boosted_WOS.push_back(new TH1F ("hmelaDCPggH_boosted_WOS","DCPggH",20,-1,1)); hmelaDCPggH_boosted_WOS[k]->Sumw2();
        hmelaD0minusggH_boosted_WOS.push_back(new TH1F ("hmelaD0minusggH_boosted_WOS","D0minusggH",10,0,1)); hmelaD0minusggH_boosted_WOS[k]->Sumw2();
        hmelaD0minus_boosted_WOS.push_back(new TH1F ("hmelaD0minus_boosted_WOS","D0minus",10,0,1)); hmelaD0minus_boosted_WOS[k]->Sumw2();
        hmelaDPhijj_boosted_WOS.push_back(new TH1F ("hmelaDPhijj_boosted_WOS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_boosted_WOS[k]->Sumw2();
        hmelaDPhiUnsignedjj_boosted_WOS.push_back(new TH1F ("hmelaDPhiUnsignedjj_boosted_WOS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_boosted_WOS[k]->Sumw2();
////////////
///////
        hmelaDCP_0jet_WSS.push_back(new TH1F ("hmelaDCP_0jet_WSS","DCP",20,-1,1)); hmelaDCP_0jet_WSS[k]->Sumw2();
        hmelaDCPggH_0jet_WSS.push_back(new TH1F ("hmelaDCPggH_0jet_WSS","DCPggH",20,-1,1)); hmelaDCPggH_0jet_WSS[k]->Sumw2();
        hmelaD0minusggH_0jet_WSS.push_back(new TH1F ("hmelaD0minusggH_0jet_WSS","D0minusggH",10,0,1)); hmelaD0minusggH_0jet_WSS[k]->Sumw2();
        hmelaD0minus_0jet_WSS.push_back(new TH1F ("hmelaD0minus_0jet_WSS","D0minus",10,0,1)); hmelaD0minus_0jet_WSS[k]->Sumw2();
        hmelaDPhijj_0jet_WSS.push_back(new TH1F ("hmelaDPhijj_0jet_WSS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_0jet_WSS[k]->Sumw2();
        hmelaDPhiUnsignedjj_0jet_WSS.push_back(new TH1F ("hmelaDPhiUnsignedjj_0jet_WSS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_0jet_WSS[k]->Sumw2();

        hmelaDCP_VBF_WSS.push_back(new TH1F ("hmelaDCP_VBF_WSS","DCP",20,-1,1)); hmelaDCP_VBF_WSS[k]->Sumw2();
        hmelaDCPggH_VBF_WSS.push_back(new TH1F ("hmelaDCPggH_VBF_WSS","DCPggH",20,-1,1)); hmelaDCPggH_VBF_WSS[k]->Sumw2();
        hmelaD0minusggH_VBF_WSS.push_back(new TH1F ("hmelaD0minusggH_VBF_WSS","D0minusggH",10,0,1)); hmelaD0minusggH_VBF_WSS[k]->Sumw2();
        hmelaD0minus_VBF_WSS.push_back(new TH1F ("hmelaD0minus_VBF_WSS","D0minus",10,0,1)); hmelaD0minus_VBF_WSS[k]->Sumw2();
        hmelaDPhijj_VBF_WSS.push_back(new TH1F ("hmelaDPhijj_VBF_WSS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_VBF_WSS[k]->Sumw2();
        hmelaDPhiUnsignedjj_VBF_WSS.push_back(new TH1F ("hmelaDPhiUnsignedjj_VBF_WSS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_VBF_WSS[k]->Sumw2();


        hmelaDCP_boosted_WSS.push_back(new TH1F ("hmelaDCP_boosted_WSS","DCP",20,-1,1)); hmelaDCP_boosted_WSS[k]->Sumw2();
        hmelaDCPggH_boosted_WSS.push_back(new TH1F ("hmelaDCPggH_boosted_WSS","DCPggH",20,-1,1)); hmelaDCPggH_boosted_WSS[k]->Sumw2();
        hmelaD0minusggH_boosted_WSS.push_back(new TH1F ("hmelaD0minusggH_boosted_WSS","D0minusggH",10,0,1)); hmelaD0minusggH_boosted_WSS[k]->Sumw2();
        hmelaD0minus_boosted_WSS.push_back(new TH1F ("hmelaD0minus_boosted_WSS","D0minus",10,0,1)); hmelaD0minus_boosted_WSS[k]->Sumw2();
        hmelaDPhijj_boosted_WSS.push_back(new TH1F ("hmelaDPhijj_boosted_WSS","DPhijj",64,-3.2,3.2)); hmelaDPhijj_boosted_WSS[k]->Sumw2();
        hmelaDPhiUnsignedjj_boosted_WSS.push_back(new TH1F ("hmelaDPhiUnsignedjj_boosted_WSS","DPhiUnsignedjj",64,-3.2,3.2)); hmelaDPhiUnsignedjj_boosted_WSS[k]->Sumw2();


        ostringstream H1D1; H1D1 << "h1D_OS" << k;
        h1D_OS.push_back(new TH1F (H1D1.str().c_str(),"InvMa",10,0,400)); h1D_OS[k]->Sumw2();


        h1D_jpt1_VBF_OS.push_back(new TH1F ("h1D_jpt1_VBF_OS","pT",40,0,400)); h1D_jpt1_VBF_OS[k]->Sumw2();
        h1D_jpt2_VBF_OS.push_back(new TH1F ("h1D_jpt2_VBF_OS","pT",40,0,400)); h1D_jpt2_VBF_OS[k]->Sumw2();
        h1D_jeta1_VBF_OS.push_back(new TH1F ("h1D_jeta1_VBF_OS","eta",50,-2.5,2.5)); h1D_jeta1_VBF_OS[k]->Sumw2();
        h1D_jeta2_VBF_OS.push_back(new TH1F ("h1D_jeta2_VBF_OS","eta",50,-2.5,2.5)); h1D_jeta2_VBF_OS[k]->Sumw2();
        h1D_phi1_VBF_OS.push_back(new TH1F ("h1D_phi1_VBF_OS","phi",40,-4,4)); h1D_phi1_VBF_OS[k]->Sumw2();
        h1D_phi2_VBF_OS.push_back(new TH1F ("h1D_phi2_VBF_OS","phi",40,-4,4)); h1D_phi2_VBF_OS[k]->Sumw2();
        h1D_mjj_VBF_OS.push_back(new TH1F ("h1D_mjj_VBF_OS","Mass_jj",100,0,1000)); h1D_mjj_VBF_OS[k]->Sumw2();
        h1D_met_VBF_OS.push_back(new TH1F ("h1D_met_VBF_OS","MET",50,0,500)); h1D_met_VBF_OS[k]->Sumw2();



        h1D_jpt1_VBF_SS.push_back(new TH1F ("h1D_jpt1_VBF_SS","pT",40,0,400)); h1D_jpt1_VBF_SS[k]->Sumw2();
        h1D_jpt2_VBF_SS.push_back(new TH1F ("h1D_jpt2_VBF_SS","pT",40,0,400)); h1D_jpt2_VBF_SS[k]->Sumw2();
        h1D_jeta1_VBF_SS.push_back(new TH1F ("h1D_jeta1_VBF_SS","eta",50,-2.5,2.5)); h1D_jeta1_VBF_SS[k]->Sumw2();
        h1D_jeta2_VBF_SS.push_back(new TH1F ("h1D_jeta2_VBF_SS","eta",50,-2.5,2.5)); h1D_jeta2_VBF_SS[k]->Sumw2();
        h1D_phi1_VBF_SS.push_back(new TH1F ("h1D_phi1_VBF_SS","phi",40,-4,4)); h1D_phi1_VBF_SS[k]->Sumw2();
        h1D_phi2_VBF_SS.push_back(new TH1F ("h1D_phi2_VBF_SS","phi",40,-4,4)); h1D_phi2_VBF_SS[k]->Sumw2();
        h1D_mjj_VBF_SS.push_back(new TH1F ("h1D_mjj_VBF_SS","Mass_jj",100,0,1000)); h1D_mjj_VBF_SS[k]->Sumw2();
        h1D_met_VBF_SS.push_back(new TH1F ("h1D_met_VBF_SS","MET",50,0,500)); h1D_met_VBF_SS[k]->Sumw2();

        h1D_jpt1_VBF_QCD.push_back(new TH1F ("h1D_jpt1_VBF_QCD","pT",40,0,400)); h1D_jpt1_VBF_QCD[k]->Sumw2();
        h1D_jpt2_VBF_QCD.push_back(new TH1F ("h1D_jpt2_VBF_QCD","pT",40,0,400)); h1D_jpt2_VBF_QCD[k]->Sumw2();
        h1D_jeta1_VBF_QCD.push_back(new TH1F ("h1D_jeta1_VBF_QCD","eta",50,-2.5,2.5)); h1D_jeta1_VBF_QCD[k]->Sumw2();
        h1D_jeta2_VBF_QCD.push_back(new TH1F ("h1D_jeta2_VBF_QCD","eta",50,-2.5,2.5)); h1D_jeta2_VBF_QCD[k]->Sumw2();
        h1D_phi1_VBF_QCD.push_back(new TH1F ("h1D_phi1_VBF_QCD","phi",40,-4,4)); h1D_phi1_VBF_QCD[k]->Sumw2();
        h1D_phi2_VBF_QCD.push_back(new TH1F ("h1D_phi2_VBF_QCD","phi",40,-4,4)); h1D_phi2_VBF_QCD[k]->Sumw2();
        h1D_mjj_VBF_QCD.push_back(new TH1F ("h1D_mjj_VBF_QCD","Mass_jj",100,0,1000)); h1D_mjj_VBF_QCD[k]->Sumw2();
        h1D_met_VBF_QCD.push_back(new TH1F ("h1D_met_VBF_QCD","MET",50,0,500)); h1D_met_VBF_QCD[k]->Sumw2();


        h1D_jpt1_VBF_WOS.push_back(new TH1F ("h1D_jpt1_VBF_WOS","pT",40,0,400)); h1D_jpt1_VBF_WOS[k]->Sumw2();
        h1D_jpt2_VBF_WOS.push_back(new TH1F ("h1D_jpt2_VBF_WOS","pT",40,0,400)); h1D_jpt2_VBF_WOS[k]->Sumw2();
        h1D_jeta1_VBF_WOS.push_back(new TH1F ("h1D_jeta1_VBF_WOS","eta",50,-2.5,2.5)); h1D_jeta1_VBF_WOS[k]->Sumw2();
        h1D_jeta2_VBF_WOS.push_back(new TH1F ("h1D_jeta2_VBF_WOS","eta",50,-2.5,2.5)); h1D_jeta2_VBF_WOS[k]->Sumw2();
        h1D_phi1_VBF_WOS.push_back(new TH1F ("h1D_phi1_VBF_WOS","phi",40,-4,4)); h1D_phi1_VBF_WOS[k]->Sumw2();
        h1D_phi2_VBF_WOS.push_back(new TH1F ("h1D_phi2_VBF_WOS","phi",40,-4,4)); h1D_phi2_VBF_WOS[k]->Sumw2();
        h1D_mjj_VBF_WOS.push_back(new TH1F ("h1D_mjj_VBF_WOS","Mass_jj",100,0,1000)); h1D_mjj_VBF_WOS[k]->Sumw2();
        h1D_met_VBF_WOS.push_back(new TH1F ("h1D_met_VBF_WOS","MET",50,0,500)); h1D_met_VBF_WOS[k]->Sumw2();

        h1D_jpt1_VBF_WSS.push_back(new TH1F ("h1D_jpt1_VBF_WSS","pT",40,0,400)); h1D_jpt1_VBF_WSS[k]->Sumw2();
        h1D_jpt2_VBF_WSS.push_back(new TH1F ("h1D_jpt2_VBF_WSS","pT",40,0,400)); h1D_jpt2_VBF_WSS[k]->Sumw2();
        h1D_jeta1_VBF_WSS.push_back(new TH1F ("h1D_jeta1_VBF_WSS","eta",50,-2.5,2.5)); h1D_jeta1_VBF_WSS[k]->Sumw2();
        h1D_jeta2_VBF_WSS.push_back(new TH1F ("h1D_jeta2_VBF_WSS","eta",50,-2.5,2.5)); h1D_jeta2_VBF_WSS[k]->Sumw2();
        h1D_phi1_VBF_WSS.push_back(new TH1F ("h1D_phi1_VBF_WSS","phi",40,-4,4)); h1D_phi1_VBF_WSS[k]->Sumw2();
        h1D_phi2_VBF_WSS.push_back(new TH1F ("h1D_phi2_VBF_WSS","phi",40,-4,4)); h1D_phi2_VBF_WSS[k]->Sumw2();
        h1D_mjj_VBF_WSS.push_back(new TH1F ("h1D_mjj_VBF_WSS","Mass_jj",100,0,1000)); h1D_mjj_VBF_WSS[k]->Sumw2();
        h1D_met_VBF_WSS.push_back(new TH1F ("h1D_met_VBF_WSS","MET",50,0,500)); h1D_met_VBF_WSS[k]->Sumw2();


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






   ScaleFactor * myScaleFactor_trgMu24 = new ScaleFactor();
   myScaleFactor_trgMu24->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IsoMu24_OR_TkIsoMu24_2016BtoH_eff.root");
   ScaleFactor * myScaleFactor_trgMu19Leg = new ScaleFactor();
   myScaleFactor_trgMu19Leg->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu19leg_2016BtoH_eff.root");
   ScaleFactor * myScaleFactor_trgMu22 = new ScaleFactor();
   myScaleFactor_trgMu22->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu22OR_eta2p1_eff.root");
   ScaleFactor * myScaleFactor_trgMu19LegAnti = new ScaleFactor();
   myScaleFactor_trgMu19LegAnti->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu19leg_eta2p1_antiisolated_Iso0p15to0p3_eff_rb.root");
   ScaleFactor * myScaleFactor_trgMu22Anti = new ScaleFactor();
   myScaleFactor_trgMu22Anti->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu22OR_eta2p1_antiisolated_Iso0p15to0p3_eff_rb.root");
   ScaleFactor * myScaleFactor_id = new ScaleFactor();
   myScaleFactor_id->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IdIso_IsoLt0p15_2016BtoH_eff.root");
   ScaleFactor * myScaleFactor_idAnti = new ScaleFactor();
   myScaleFactor_idAnti->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IdIso_antiisolated_Iso0p15to0p3_eff_rb.root");

   TString postfixTES[12]={"_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"};
   TString postfixDM[6]={"_CMS_tauDMReco_1prong_13TeVUp","_CMS_tauDMReco_1prong_13TeVDown","_CMS_tauDMReco_1prong1pizero_13TeVUp","_CMS_tauDMReco_1prong1pizero_13TeVDown","_CMS_tauDMReco_3prong_13TeVUp","_CMS_tauDMReco_3prong_13TeVDown"};
   TString postfixFakeDM[6]={"_CMS_jetToTauDMReco_1prong_13TeVUp","_CMS_jetToTauDMReco_1prong_13TeVDown","_CMS_jetToTauDMReco_1prong1pizero_13TeVUp","_CMS_jetToTauDMReco_1prong1pizero_13TeVDown","_CMS_jetToTauDMReco_3prong_13TeVUp","_CMS_jetToTauDMReco_3prong_13TeVDown"};
   TString postfixZLshape[12]={"_CMS_htt_ZLShape_mt_13TeVUp","_CMS_htt_ZLShape_mt_13TeVDown","_CMS_ZLShape_mt_0jet_1prong_13TeVUp","_CMS_ZLShape_mt_0jet_1prong_13TeVDown","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_1prong_13TeVUp","_CMS_ZLShape_mt_1prong_13TeVDown", "_CMS_ZLShape_mt_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_3prong_13TeVUp","_CMS_ZLShape_mt_3prong_13TeVDown"};
   TString postfixZLnorm[4]={"_CMS_mFakeTau_1prong_13TeVUp","_CMS_mFakeTau_1prong_13TeVDown","_CMS_mFakeTau_1prong1pizero_13TeVUp","_CMS_mFakeTau_1prong1pizero_13TeVDown"};
   TString postfixJES[56]={"_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"};

   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);

	bool isSingleLep = (passIsoMu22 && matchIsoMu22_1 && filterIsoMu22_1) or (passIsoTkMu22 && matchIsoTkMu22_1 && filterIsoTkMu22_1) or (passIsoMu22eta2p1 && matchIsoMu22eta2p1_1 && filterIsoMu22eta2p1_1) or (passIsoTkMu22eta2p1 && matchIsoTkMu22eta2p1_1 && filterIsoTkMu22eta2p1_1);
	bool isCrossTrigger = (passIsoMu19Tau20 && matchIsoMu19Tau20_1 && filterIsoMu19Tau20_1 && matchIsoMu19Tau20_2 && filterIsoMu19Tau20_2);

        if (sample=="data_obs" && run<278820 && !id_m_medium2016_1) continue;
        if (sample=="data_obs" && run>=278820 && !id_m_medium_1) continue;

        if (sample=="embedded" && genDR_2>0.2) continue;

	if (pt_1<20) continue;
        if (fabs(eta_1)>2.1) continue;
	if (sample!="embedded" && !isSingleLep && !isCrossTrigger) continue;
	if (sample!="embedded" && (!((isSingleLep && pt_1>23) or (isCrossTrigger && pt_1<=23)))) continue;

	if (!againstElectronVLooseMVA6_2 or !againstMuonTight3_2) continue;
        float sf_trg=1.0;
        float sf_id=1.0;
        float sf_id_anti=1.0;
	float sf_trg_anti=1.0;
	float eff_tau=1.0;
	float eff_tau_anti=1.0;

	if (sample!="data_obs"){
           sf_id=myScaleFactor_id->get_ScaleFactor(pt_1,eta_1);
           sf_id_anti=myScaleFactor_idAnti->get_ScaleFactor(pt_1,eta_1);
        }

	float ratioanti=(sf_id_anti)/(sf_id);

	float signalRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.15);
	float qcdRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30);
        float wRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30);
        float wsfRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.15);
        float qcdCR=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30 && iso_1>0.15);

	TLorentzVector mytau; 
	mytau.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
        TLorentzVector mymu;
        mymu.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);

	//***************** Weights **************

        if (sample=="W"){
            weight=25.446;
            if (numGenJets==1) weight=6.8176;
            else if (numGenJets==2) weight=2.1038;
            else if (numGenJets==3) weight=0.6889;
            else if (numGenJets==4) weight=0.6900;
        }

	/*if (sample=="W"){//Laura stat
            weight=25.446;
            if (numGenJets==1) weight=6.8176;
            else if (numGenJets==2) weight=3.90313;
            else if (numGenJets==3) weight=1.95115;
            else if (numGenJets==4) weight=0.68997;
        }*/

        if (sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            weight=1.4184;
            if (numGenJets==1)
                weight=0.45229;
            else if (numGenJets==2)
                weight=0.4668;
            else if (numGenJets==3)
                weight=0.42995;
            else if (numGenJets==4)
                weight=0.39349;
        }

	float correction=sf_id;
	if (sample!="embedded" && sample!="data_obs") correction=correction*LumiWeights_12->weight(npu);
        if (sample=="embedded" && amcatNLO_weight>1) amcatNLO_weight=0.10;
	float aweight=amcatNLO_weight*weight*correction;

        if (sample!="data_obs"){
           if (gen_match_2==5) aweight=aweight*0.95;
           if (gen_match_2==2 or gen_match_2==4){//Yiwen reminiaod
              if (fabs(eta_2)<0.4) aweight=aweight*1.263;
              else if (fabs(eta_2)<0.8) aweight=aweight*1.364;
              else if (fabs(eta_2)<1.2) aweight=aweight*0.854;
              else if (fabs(eta_2)<1.7) aweight=aweight*1.712;
              else if (fabs(eta_2)<2.3) aweight=aweight*2.324;
	      if (sample=="ZL" && l2_decayMode==0) aweight=aweight*0.74; //ZL corrections Laura
	      else if (sample=="ZL" && l2_decayMode==1) aweight=aweight*1.0;
           }
	   if (gen_match_2==1 or gen_match_2==3){//Yiwen
              if (fabs(eta_2)<1.460) aweight=aweight*1.213;
              else if (fabs(eta_2)>1.558) aweight=aweight*1.325;
           }
           //w->var("m_pt")->setVal(mymu.Pt());
           //w->var("m_eta")->setVal(mymu.Eta());
	   //aweight=aweight*w->function("m_trk_ratio")->getVal();
	   aweight=aweight*h_Trk->Eval(eta_1);
        }

        //if (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ") aweight=aweight*1.02; //Zmumu correction

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

	cout<<" lets check aweight  "<<aweight<<endl;

	if (name=="reweighted_qqH_htt_0M125" or name=="reweighted_WH_htt_0M125" or name=="reweighted_ZH_htt_0M125" or name=="reweighted_GGH2Jets_0M125") aweight=aweight*jhuw_a3;
        if (name=="reweighted_qqH_htt_0PH125" or name=="reweighted_WH_htt_0PH125" or name=="reweighted_ZH_htt_0PH125" or name=="reweighted_GGH2Jets_0PH125") aweight=aweight*jhuw_a2;
        if (name=="reweighted_qqH_htt_0PM125" or name=="reweighted_WH_htt_0PM125" or name=="reweighted_ZH_htt_0PM125" or name=="reweighted_GGH2Jets_0PM125") aweight=aweight*jhuw_a1;
        if (name=="reweighted_qqH_htt_0L1125" or name=="reweighted_WH_htt_0L1125" or name=="reweighted_ZH_htt_0L1125" or name=="reweighted_GGH2Jets_0L1125") aweight=aweight*jhuw_l1;
        if (name=="reweighted_qqH_htt_0L1Zg125" or name=="reweighted_WH_htt_0L1Zg125" or name=="reweighted_ZH_htt_0L1Zg125" or name=="reweighted_GGH2Jets_0L1Zg125") aweight=aweight*jhuw_l1Zg;
        if (name=="reweighted_qqH_htt_0Mf05ph0125" or name=="reweighted_WH_htt_0Mf05ph0125" or name=="reweighted_ZH_htt_0Mf05ph0125" or name=="reweighted_GGH2Jets_0Mf05ph0125") aweight=aweight*jhuw_a3int;
        if (name=="reweighted_qqH_htt_0PHf05ph0125" or name=="reweighted_WH_htt_0PHf05ph0125" or name=="reweighted_ZH_htt_0PHf05ph0125" or name=="reweighted_GGH2Jets_0PHf05ph0125") aweight=aweight*jhuw_a2int;
        if (name=="reweighted_qqH_htt_0L1f05ph0125" or name=="reweighted_WH_htt_0L1f05ph0125" or name=="reweighted_ZH_htt_0L1f05ph0125" or name=="reweighted_GGH2Jets_0L1f05ph0125") aweight=aweight*jhuw_l1int;
        if (name=="reweighted_qqH_htt_0L1Zgf05ph0125" or name=="reweighted_WH_htt_0L1Zgf05ph0125" or name=="reweighted_ZH_htt_0L1Zgf05ph0125" or name=="reweighted_GGH2Jets_0L1Zgf05ph0125") aweight=aweight*jhuw_l1Zgint;

	cout<<" lets check aweight  again "<<aweight<<"  "<<jhuw_a1<<endl;

	//*********************** Definition of fit variables *******************
        int numberJets=njets;
        float massJets=mjj;
        float var2=m_sv;
        float var1_1=pt_sv;
        float var1_0=mytau.Pt();
        float var1_2=massJets;
        float var1_3=dPhi_jj;
        float var1_4=dPhiUnsigned_jj;

	// ###########################################################
	// ######## Separation between L, T and J ####################
	// ###########################################################
	
        if (sample=="ZL" && gen_match_2>4) continue;
        if ((sample=="TTT" or sample=="ZTT") && gen_match_2!=5) continue;
        if ((sample=="TTJ" or sample=="ZLL") && gen_match_2==5) continue;
        if (sample=="ZJ" && gen_match_2!=6) continue;

	// #############################################################
     	// ################### Top pT reweighting ######################
     	// #############################################################
	float pttop1=pt_top1;
        if (pttop1>400) pttop1=400;
        float pttop2=pt_top2;
        if (pttop2>400) pttop2=400;
        if ((sample=="TTJ" or sample=="TTT" or sample=="TT") && fabs(tes)!=11) aweight*=sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2));
        if ((sample=="TTJ" or sample=="TTT" or sample=="TT") && tes==11) aweight*=(1+2*(sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2))-1));

	if (sample=="data_obs") aweight=1.0;

	float weight_btag=1.0;
        if (sample!="data_obs"){
            int nbtagged=nbtag;
            if (nbtagged>2) nbtagged=2;
            weight_btag=bTagEventWeight(nbtagged,bpt_1,bflavor_1,bpt_2,bflavor_2,1,0,0);
            if (nbtagged>2) weight_btag=0;
        }
	bool is_bveto=(sample!="data_obs" or nbtag==0);


	// ############################################################
	// ############### Loop over JES sources ######################
	// ############################################################
	//
	int nombrejets[56]={njets_JESDown,njets_JESUp,njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleDown,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatDown,njets_JetAbsoluteStatUp,njets_JetFlavorQCDDown,njets_JetFlavorQCDUp,njets_JetFragmentationDown,njets_JetFragmentationUp,njets_JetPileUpDataMCDown,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBDown,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Down,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFDown,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefDown,njets_JetPileUpPtRefUp,njets_JetRelativeBalDown,njets_JetRelativeBalUp,njets_JetRelativeFSRDown,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Down,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFDown,njets_JetRelativeJERHFUp,njets_JetRelativePtBBDown,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Down,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Down,njets_JetRelativePtEC2Up,njets_JetRelativePtHFDown,njets_JetRelativePtHFUp,njets_JetRelativeStatECDown,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRDown,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFDown,njets_JetRelativeStatHFUp,njets_JetSinglePionECALDown,njets_JetSinglePionECALUp,njets_JetSinglePionHCALDown,njets_JetSinglePionHCALUp,njets_JetTimePtEtaDown,njets_JetTimePtEtaUp};

	float massejets[56]={mjj_JESDown,mjj_JESUp,mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatDown,mjj_JetAbsoluteStatUp,mjj_JetFlavorQCDDown,mjj_JetFlavorQCDUp,mjj_JetFragmentationDown,mjj_JetFragmentationUp,mjj_JetPileUpDataMCDown,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefDown,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalDown,mjj_JetRelativeBalUp,mjj_JetRelativeFSRDown,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFDown,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBDown,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Down,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFDown,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECDown,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFDown,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALDown,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALDown,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaDown,mjj_JetTimePtEtaUp};
        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector myrawtau=mytau;
	float ratioantiraw=ratioanti;

	for (int k=0; k<nbhist; ++k){

            int numberJets=nombrejets[k];
            float massJets=massejets[k];
	    if (tes!=100) numberJets=njets;
            if (tes!=100) massJets=mjj;
	    float weight2=1.0;

	    TLorentzVector mymet=myrawmet;
	    mytau=myrawtau;
	    var1_1=pt_sv;
	    var2=m_sv;
            float var1_2=massJets;
	    ///needed for ggH
            float var1_3=dPhi_jj;
            float var1_4=dPhiUnsigned_jj;

	    if (tes==1 && gen_match_2==5){
	       if (k==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               if (k==2 && l2_decayMode==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==3 && l2_decayMode==0){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               if (k==4 && l2_decayMode==1){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==5 && l2_decayMode==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
               if (k==6 && l2_decayMode==10){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
               if (k==7 && l2_decayMode==10){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
	    }

            if (tes==1){
               if (k==8){ var2=m_sv_UESDown; var1_1=pt_sv_UESDown; mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
               else if (k==9){ var2=m_sv_UESUp; var1_1=pt_sv_UESUp; mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
               else if (k==10){ var2=m_sv_JESDown; var1_1=pt_sv_JESDown; mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
               else if (k==11){ var2=m_sv_JESUp; var1_1=pt_sv_JESUp; mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
            }

	   if (tes==15 && sample=="ZL"){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.015; mymet=mymet-(0.015/1.015)*mytau;}
           if (tes==-15 && sample=="ZL"){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.985; mymet=mymet+(0.015/0.985)*mytau;}
	    float dm_weight=1.0;
            if (tes==16 && gen_match_2==5){
                if (k==0 && l2_decayMode==0) dm_weight=1.03;
                else if (k==1 && l2_decayMode==0) dm_weight=0.97;
                else if (k==2 && l2_decayMode==1) dm_weight=1.03;
                else if (k==3 && l2_decayMode==1) dm_weight=0.97;
                else if (k==4 && l2_decayMode==10) dm_weight=1.03;
                else if (k==5 && l2_decayMode==10) dm_weight=0.97;
            }
            if (tes==19 && gen_match_2==6){
                if (k==0 && l2_decayMode==0) dm_weight=1.20;
                else if (k==1 && l2_decayMode==0) dm_weight=0.80;
                else if (k==2 && l2_decayMode==1) dm_weight=1.20;
                else if (k==3 && l2_decayMode==1) dm_weight=0.80;
                else if (k==4 && l2_decayMode==10) dm_weight=1.20;
                else if (k==5 && l2_decayMode==10) dm_weight=0.80;
            }

            if (tes==18 && sample=="ZL"){
                if (k==0 && l2_decayMode==0) dm_weight=1.25;
                else if (k==1 && l2_decayMode==0) dm_weight=0.75;
                else if (k==2 && l2_decayMode==1) dm_weight=1.25;
                else if (k==3 && l2_decayMode==1) dm_weight=0.75;
            }

            if (numberJets==0) var2=(mymu+mytau).M();

            if (tes==17 && sample=="ZL"){
                if (k==0){ 
		     var2=m_sv_UP; 
		     var1_1=pt_sv_UP; 
		     mytau*=1.015; 
		     mymet=mymet-(0.015/1.015)*mytau;
		     if (numberJets==0) var2=(mymu+mytau).M();
		}
                else if (k==1) { 
		     var2=m_sv_DOWN; 
		     var1_1=pt_sv_DOWN; 
		     mytau*=0.985; 
		     mymet=mymet+(0.015/0.985)*mytau;
                     if (numberJets==0) var2=(mymu+mytau).M();
		}
                else if (k==2 && l2_decayMode==0 && numberJets==0) var2=var2*1.003;
                else if (k==3 && l2_decayMode==0 && numberJets==0) var2=var2*0.997;
                else if (k==4 && l2_decayMode==1 && numberJets==0) var2=var2*1.004;
                else if (k==5 && l2_decayMode==1 && numberJets==0) var2=var2*0.996;
                if (k==6 && l2_decayMode==0){ 
                     var2=m_sv_UP; 
                     var1_1=pt_sv_UP;
                     mytau*=1.015; 
                     mymet=mymet-(0.015/1.015)*mytau;
                     if (numberJets==0) var2=(mymu+mytau).M();
                }
                else if (k==7 && l2_decayMode==0) { 
                     var2=m_sv_DOWN; 
                     var1_1=pt_sv_DOWN;
                     mytau*=0.985; 
                     mymet=mymet+(0.015/0.985)*mytau;
                     if (numberJets==0) var2=(mymu+mytau).M();
                }
                if (k==8 && l2_decayMode==1){ 
                     var2=m_sv_UP; 
                     var1_1=pt_sv_UP;
                     mytau*=1.015; 
                     mymet=mymet-(0.015/1.015)*mytau;
                     if (numberJets==0) var2=(mymu+mytau).M();
                }
                else if (k==9 && l2_decayMode==1) { 
                     var2=m_sv_DOWN; 
                     var1_1=pt_sv_DOWN;
                     mytau*=0.985; 
                     mymet=mymet+(0.015/0.985)*mytau;
                     if (numberJets==0) var2=(mymu+mytau).M();
                }
                if (k==10 && l2_decayMode==10){ 
                     var2=m_sv_UP; 
                     var1_1=pt_sv_UP;
                     mytau*=1.015; 
                     mymet=mymet-(0.015/1.015)*mytau;
                     if (numberJets==0) var2=(mymu+mytau).M();
                }
                else if (k==11 && l2_decayMode==10) { 
                     var2=m_sv_DOWN; 
                     var1_1=pt_sv_DOWN;
                     mytau*=0.985; 
                     mymet=mymet+(0.015/0.985)*mytau;
                     if (numberJets==0) var2=(mymu+mytau).M();
                }
            }

	    if (mytau.Pt()<30) continue;
	    //var1_0=mytau.Pt();
	    var1_0=l2_decayMode;//FIXME
	    var1_1=(mymu+mytau+mymet).Pt();//FIXME

            float mt=TMass_F(mymu.Pt(),mymet.Pt(),mymu.Px(),mymet.Px(),mymu.Py(),mymet.Py());

            if (sample!="embedded" && sample!="data_obs"){
	       if (mymu.Pt()<23){ 
                   w2->var("t_pt")->setVal(mytau.Pt());
                   w2->var("t_eta")->setVal(mytau.Eta());
                   w2->var("t_dm")->setVal(l2_decayMode);
                   float eff_tau_ratio = w2->function("t_genuine_TightIso_mt_ratio")->getVal();
		   sf_trg=myScaleFactor_trgMu19Leg->get_ScaleFactor(pt_1,eta_1)*eff_tau_ratio;
		   sf_trg_anti=myScaleFactor_trgMu19LegAnti->get_ScaleFactor(pt_1,eta_1)*eff_tau_ratio;
	       }
	       else{
		   sf_trg=myScaleFactor_trgMu22->get_ScaleFactor(pt_1,eta_1);
                   sf_trg_anti=myScaleFactor_trgMu22Anti->get_ScaleFactor(pt_1,eta_1);
	       }
	    }
            if (sample=="embedded"){
               if (mymu.Pt()<23){ 
                   float eff_tau_ratio = w2->function("t_genuine_TightIso_mt_data")->getVal();
                   sf_trg=myScaleFactor_trgMu19Leg->get_EfficiencyData(pt_1,eta_1)*eff_tau_ratio;
                   sf_trg_anti=myScaleFactor_trgMu19LegAnti->get_EfficiencyData(pt_1,eta_1)*eff_tau_ratio;
               }
               else{
                   sf_trg=myScaleFactor_trgMu22->get_EfficiencyData(pt_1,eta_1);
                   sf_trg_anti=myScaleFactor_trgMu22Anti->get_EfficiencyData(pt_1,eta_1);
               }
            }
            
	    //************************ Z mumu scale factors **************************
	    /*if (fabs(tes)!=13 && (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),0);
            if (tes==13 && (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),1);
            if (tes==-13 && (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),-1);*/

	    if (sample=="data_obs") {aweight=1.0; weight2=1.0;}
            weight2=weight2*sf_trg*dm_weight;
            ratioanti=ratioantiraw*sf_trg_anti/(sf_trg+0.000000001);

	    bool is_0jet=(numberJets==0);
	    bool is_boosted=(numberJets==1 or (numberJets>=2 && (massJets<=300 or var1_1<=50 or mytau.Pt()<=40)));
	    bool is_VBF=(massJets > 300 && numberJets>=2 && var1_1>50 && mytau.Pt()>40 && m_sv>60 && m_sv<90);

   	     //################ W+jets reweighting in high mT ###############

            if (q_1*q_2<0 && mt>80 && mt<200 && wsfRegion){
                n70[k]->Fill(0.1,aweight*weight2);
                if (is_bveto && is_0jet && var2<400) n70[k]->Fill(1.1,aweight*weight2*weight_btag);
                if (is_bveto && is_boosted && var2<300) n70[k]->Fill(2.1,aweight*weight2*weight_btag);
                if (is_bveto && is_VBF && var2<400) n70[k]->Fill(3.1,aweight*weight2*weight_btag);
            }

            if (q_1*q_2>0 && mt>80 && mt<200 && wsfRegion){
                n70SS[k]->Fill(0.1,aweight*weight2);
                if (is_bveto && is_0jet && var2<400) n70SS[k]->Fill(1.1,aweight*weight2*weight_btag);
                if (is_bveto && is_boosted && var2<300) n70SS[k]->Fill(2.1,aweight*weight2*weight_btag);
                if (is_bveto && is_VBF && var2<400) n70SS[k]->Fill(3.1,aweight*weight2*weight_btag);
            }


	    //************************* Fill histograms **********************
            if (qcdCR && q_1*q_2<0 && mt<50){
                if (is_0jet)
                    h0_CR_QCD[k]->Fill(var2,aweight*weight2*ratioanti);
                if (is_boosted)
                    h1_CR_QCD[k]->Fill(var2,aweight*weight2*ratioanti);
                if (is_VBF)
                    h2_CR_QCD[k]->Fill(var2,aweight*weight2*ratioanti);
            }

            if (signalRegion && q_1*q_2<0){
                if (is_0jet && is_bveto && var2<400)
                    h0_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_boosted && is_bveto && var2<300)
                    h1_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_VBF && is_bveto && var2<400)
                    h2_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
            }

            if (qcdCR && q_1*q_2>0 && mt<50){
                if (is_0jet)
                    h0_CRSS_QCD[k]->Fill(var2,weight2*aweight*ratioanti);
                if (is_boosted)
                    h1_CRSS_QCD[k]->Fill(var2,weight2*aweight*ratioanti);
                if (is_VBF)
                    h2_CRSS_QCD[k]->Fill(var2,weight2*aweight*ratioanti);
            }

            if (signalRegion && q_1*q_2>0){
                if (is_0jet && is_bveto && var2<400)
                    h0_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_boosted && is_bveto && var2<300)
                    h1_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
                if (is_VBF && is_bveto && var2<400)
                    h2_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
            }

            if (is_0jet && mt<50){
                if (tes==12) weight2=weight2*(0.9289 + 0.00017022*mytau.Pt());
                if (tes==-12) weight2=weight2*(2-(0.9289 + 0.00017022*mytau.Pt()));
                if (genpT>150 and tes==22) weight2=weight2*(1+0.01*(0.114*genpT -17.14));
                if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
                if (signalRegion && q_1*q_2<0){
                    h0_OS[k]->Fill(var1_0,var2,weight2*aweight);

		   hmelaDCP_0jet_OS[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_0jet_OS[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_0jet_OS[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_0jet_OS[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_0jet_OS[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_0jet_OS[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);



                }
                if (signalRegion && q_1*q_2>0)
                    h0_SS[k]->Fill(var1_0,var2,weight2*aweight);
                if (wRegion && q_1*q_2<0){
                    h0_WOS[k]->Fill(var1_0,var2,weight2*aweight);
		   hmelaDCP_0jet_WOS[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_0jet_WOS[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_0jet_WOS[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_0jet_WOS[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_0jet_WOS[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_0jet_WOS[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);
		}

                if (wRegion && q_1*q_2>0){
                    h0_WSS[k]->Fill(var1_0,var2,weight2*aweight);
		   hmelaDCP_0jet_WSS[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_0jet_WSS[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_0jet_WSS[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_0jet_WSS[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_0jet_WSS[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_0jet_WSS[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);

		}
                if (qcdRegion && q_1*q_2>0){
                    h0_QCD[k]->Fill(var1_0,var2,weight2*aweight);
		   hmelaDCP_0jet_QCD[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_0jet_QCD[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_0jet_QCD[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_0jet_QCD[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_0jet_QCD[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_0jet_QCD[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);
		}
            }
            if (is_boosted && mt<50){
                if (tes==12) weight2=weight2*(0.9195 + 0.0010055*var1_1);
                if (tes==-12) weight2=weight2*(2-(0.9195 + 0.0010055*var1_1));
                if (genpT>150 and tes==22) {weight2=weight2*(1+0.01*(0.114*genpT -17.14));}
                if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
                if (signalRegion && q_1*q_2<0){
                    h1_OS[k]->Fill(var1_1,var2,weight2*aweight);

		   hmelaDCP_boosted_OS[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_boosted_OS[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_boosted_OS[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_boosted_OS[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_boosted_OS[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_boosted_OS[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);
                }
                if (signalRegion && q_1*q_2>0){
                    h1_SS[k]->Fill(var1_1,var2,aweight*weight2);
		   hmelaDCP_boosted_SS[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_boosted_SS[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_boosted_SS[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_boosted_SS[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_boosted_SS[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_boosted_SS[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);


		}
                if (wRegion && q_1*q_2<0){
                    h1_WOS[k]->Fill(var1_1,var2,aweight*weight2);
		   hmelaDCP_boosted_WOS[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_boosted_WOS[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_boosted_WOS[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_boosted_WOS[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_boosted_WOS[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_boosted_WOS[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);

		}
                if (wRegion && q_1*q_2>0){
                    h1_WSS[k]->Fill(var1_1,var2,aweight*weight2);
		   hmelaDCP_boosted_WSS[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_boosted_WSS[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_boosted_WSS[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_boosted_WSS[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_boosted_OS[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_boosted_WSS[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);
		}
                if (qcdRegion && q_1*q_2>0){
                    h1_QCD[k]->Fill(var1_1,var2,aweight*weight2);
		   hmelaDCP_boosted_QCD[k]->Fill(melaDCP,aweight*weight2);
		   hmelaDCPggH_boosted_QCD[k]->Fill(melaDCPggH,aweight*weight2);
		   hmelaD0minusggH_boosted_QCD[k]->Fill(melaD0minusggH,aweight*weight2);
		   hmelaD0minus_boosted_QCD[k]->Fill(melaD0minus,aweight*weight2);
		   hmelaDPhijj_boosted_QCD[k]->Fill(melaDPhijj,aweight*weight2);
		   hmelaDPhiUnsignedjj_boosted_QCD[k]->Fill(melaDPhiUnsignedjj,aweight*weight2);

		}
            }

	    /*TLorentzVector myjet1;
	    myjet1.SetPtEtaPhiM(jpt_1, jeta_1, jphi_1, 0);
            TLorentzVector myjet2;
            myjet2.SetPtEtaPhiM(jpt_2, jeta_2, jphi_2, 0);*/
	    float var_1D=melaDL1;//(mymu+mytau+mymet).Pt();
            if (is_VBF && mt<50){
                if (tes==12) weight2=weight2*(1.0258 + 0.00006596*var1_2);
                if (tes==-12) weight2=weight2*(2-(1.0258 + 0.00006596*var1_2));
                if (genpT>150 and tes==22) weight2=weight2*(1+0.01*(0.114*genpT -17.14));
                if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
                if (signalRegion && q_1*q_2<0){
		    hCorr_OS->Fill(melaD0hplus,melaD0minus,weight2*aweight);
		    h1D_OS[k]->Fill(var_1D,weight2*aweight);

                    h2_OS[k]->Fill(var1_2,var2,aweight*weight2);

		    hmelaDCP_VBF_OS[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCP_VBF_OS[k]->Fill(melaDCP,weight2*aweight);
		    hmelaD0minus_VBF_OS[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minus_VBF_OS[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaDPhijj_VBF_OS[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_VBF_OS[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_VBF_OS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_VBF_OS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_VBF_OS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_VBF_OS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_VBF_OS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_VBF_OS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_VBF_OS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_VBF_OS[k]->Fill(mymet.Pt(),weight2*aweight);


		    if (KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2) 
                       h20_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h21_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h22_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h23_OS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int<0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h30_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h31_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h32_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h33_OS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int>=0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h40_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h41_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h42_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h43_OS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h50_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h51_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)//FIXME
                       h52_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h53_OS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h60_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h61_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)//FIXME
                       h62_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h63_OS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h70_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h71_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)//FIXME
                       h72_OS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h73_OS[k]->Fill(var1_2,var2,weight2*aweight);


///////////////////ggH
//

                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h20_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h21_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h22_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h23_OSggH[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h30_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h31_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h32_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h33_OSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h40_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h41_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h42_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h43_OSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h50_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h51_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h52_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h53_OSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h60_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h61_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h62_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h63_OSggH[k]->Fill(var1_2,var2,weight2*aweight);


		  if (jphi_1>=-pI && jphi_2>=-pI){
                   double dPhi=  jphi_1 - jphi_2; //dPhiFrom2P( LeptV1.Px(), LeptV1.Py(), METV.Px(),  METV.Py() );
		if (dPhi > TMath::Pi()) dPhi -= 2*TMath::Pi();
  		if (dPhi <= -TMath::Pi()) dPhi += 2*TMath::Pi();
		
		cout<<" dPhi plain  "<<jphi_1-jphi_2<<"  "<<dPhi<<"  "<<fabs(dPhi)<<" var1 "<<var1_2<<" var2 "<<var2<<" total"<<weight2*aweight<<" weight2 "<<weight2<<" aweight  "<<aweight<<endl;

		if (dPhi>-TMath::Pi() && dPhi<-1.5)
			h70_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-1.5 && dPhi<-0)
			h71_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>=0 && dPhi<1.5)
			h72_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>1.5 && dPhi<TMath::Pi())
			h73_OSggH[k]->Fill(var1_2,var2,weight2*aweight);
		  }


		}
                if (signalRegion && q_1*q_2>0){
                    h1D_SS[k]->Fill(var_1D,weight2*aweight);
                    h2_SS[k]->Fill(var1_2,var2,aweight*weight2);


		    hmelaDCP_VBF_SS[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_VBF_SS[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_VBF_SS[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_VBF_SS[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_VBF_SS[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_VBF_SS[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_VBF_SS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_VBF_SS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_VBF_SS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_VBF_SS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_VBF_SS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_VBF_SS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_VBF_SS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_VBF_SS[k]->Fill(mymet.Pt(),weight2*aweight);



                    if (KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h20_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h21_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)
                       h22_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h23_SS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int<0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h30_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h31_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h32_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h33_SS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int>=0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h40_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h41_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h42_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h43_SS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h50_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h51_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h52_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h53_SS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h60_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h61_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h62_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h63_SS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h70_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h71_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h72_SS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h73_SS[k]->Fill(var1_2,var2,weight2*aweight);


//////////////ggH
//
                    //h2_dPhi_mvSS[k]->Fill(var1_3,var2,aweight*weight2);

                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h20_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h21_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h23_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h23_SSggH[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h30_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h31_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h32_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h33_SSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h40_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h41_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h42_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h43_SSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h50_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h51_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h52_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h53_SSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h60_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h61_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h62_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h63_SSggH[k]->Fill(var1_2,var2,weight2*aweight);

		  if (jphi_1>=-pI && jphi_2>=-pI){
                   double dPhi=  jphi_1 - jphi_2; //dPhiFrom2P( LeptV1.Px(), LeptV1.Py(), METV.Px(),  METV.Py() );
		if (dPhi > TMath::Pi()) dPhi -= 2*TMath::Pi();
  		if (dPhi <= -TMath::Pi()) dPhi += 2*TMath::Pi();
		//	cout<<" dPhi plain  "<<jphi_1-jphi_2<<"  "<<dPhi<<"  "<<fabs(dPhi)<<endl;
		if (dPhi>-TMath::Pi() && dPhi<-1.5)
			h70_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-1.5 && dPhi<-0)
			h71_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>=0 && dPhi<1.5)
			h72_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>1.5 && dPhi<TMath::Pi())
			h73_SSggH[k]->Fill(var1_2,var2,weight2*aweight);
		  }


		}
                if (wRegion && q_1*q_2<0){
                    h1D_WOS[k]->Fill(var_1D,weight2*aweight);

                    h1D_WOS[k]->Fill(var_1D,weight2*aweight);

		    hmelaDCP_VBF_WOS[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_VBF_WOS[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_VBF_WOS[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_VBF_WOS[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_VBF_WOS[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_VBF_WOS[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_VBF_WOS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_VBF_WOS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_VBF_WOS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_VBF_WOS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_VBF_WOS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_VBF_WOS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_VBF_WOS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_VBF_WOS[k]->Fill(mymet.Pt(),weight2*aweight);



                    if (KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h20_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h21_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)
                       h22_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h23_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int<0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h30_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h31_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h32_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h33_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int>=0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h40_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h41_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h42_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h43_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h50_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h51_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h52_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h53_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h60_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h61_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h62_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h63_WOS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h70_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h71_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h72_WOS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h73_WOS[k]->Fill(var1_2,var2,weight2*aweight);

//////////ggH
//			
                    //h2_dPhi_mvWOS[k]->Fill(var1_3,var2,aweight*weight2);
                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h20_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h21_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h22_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h23_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h30_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h31_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h32_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h33_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h40_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h41_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h42_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h43_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h50_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h51_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h52_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h53_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h60_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h61_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h62_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h63_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);

		  if (jphi_1>=-pI && jphi_2>=-pI){
                   double dPhi=  jphi_1 - jphi_2; //dPhiFrom2P( LeptV1.Px(), LeptV1.Py(), METV.Px(),  METV.Py() );
		if (dPhi > TMath::Pi()) dPhi -= 2*TMath::Pi();
  		if (dPhi <= -TMath::Pi()) dPhi += 2*TMath::Pi();
		//	cout<<" dPhi plain  "<<jphi_1-jphi_2<<"  "<<dPhi<<"  "<<fabs(dPhi)<<endl;

		if (dPhi>-TMath::Pi() && dPhi<-1.5)
			h70_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-1.5 && dPhi<-0)
			h71_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>=0 && dPhi<1.5)
			h72_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>1.5 && dPhi<TMath::Pi())
			h73_WOSggH[k]->Fill(var1_2,var2,weight2*aweight);

		  }


		}
                if (wRegion && q_1*q_2>0){
                    h1D_WSS[k]->Fill(var_1D,weight2*aweight);


		    hmelaDCP_VBF_WSS[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_VBF_WSS[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_VBF_WSS[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_VBF_WSS[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_VBF_WSS[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_VBF_WSS[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);



		    h1D_jpt1_VBF_WSS[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_VBF_WSS[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_VBF_WSS[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_VBF_WSS[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_VBF_WSS[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_VBF_WSS[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_VBF_WSS[k]->Fill(mjj,weight2*aweight);
		    h1D_met_VBF_WSS[k]->Fill(mymet.Pt(),weight2*aweight);


                    if (KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h20_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h21_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)
                       h22_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h23_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int<0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h30_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h31_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h32_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h33_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int>=0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h40_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h41_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h42_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h43_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h50_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h51_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h52_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h53_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h60_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h61_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h62_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h63_WSS[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h70_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h71_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h72_WSS[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h73_WSS[k]->Fill(var1_2,var2,weight2*aweight);

//////////////////
                    //h2_dPhi_mvWSS[k]->Fill(var1_3,var2,aweight*weight2);
                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h20_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h21_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h22_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h23_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h30_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h31_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h32_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h33_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h40_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h41_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h42_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h43_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h50_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h51_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h52_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h53_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h60_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h61_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h62_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h63_SSggH[k]->Fill(var1_2,var2,weight2*aweight);

		  if (jphi_1>=-pI && jphi_2>=-pI){
                   double dPhi=  jphi_1 - jphi_2; //dPhiFrom2P( LeptV1.Px(), LeptV1.Py(), METV.Px(),  METV.Py() );
		if (dPhi > TMath::Pi()) dPhi -= 2*TMath::Pi();
  		if (dPhi <= -TMath::Pi()) dPhi += 2*TMath::Pi();
		//	cout<<" dPhi plain  "<<jphi_1-jphi_2<<"  "<<dPhi<<"  "<<fabs(dPhi)<<endl;
	
		if (dPhi>-TMath::Pi() && dPhi<-1.5)
			h70_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-1.5 && dPhi<-0)
			h71_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>=0 && dPhi<1.5)
			h72_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>1.5 && dPhi<TMath::Pi())
			h73_WSSggH[k]->Fill(var1_2,var2,weight2*aweight);
		  }


		}
                if (qcdRegion && q_1*q_2>0){
                    h1D_QCD[k]->Fill(var_1D,weight2*aweight);

                    h1D_QCD[k]->Fill(var_1D,weight2*aweight);

		    hmelaDCP_VBF_QCD[k]->Fill(melaDCP,weight2*aweight);
		    hmelaDCPggH_VBF_QCD[k]->Fill(melaDCPggH,weight2*aweight);
		    hmelaD0minus_VBF_QCD[k]->Fill(melaD0minus,weight2*aweight);
		    hmelaD0minusggH_VBF_QCD[k]->Fill(melaD0minusggH,weight2*aweight);
		    hmelaDPhijj_VBF_QCD[k]->Fill(melaDPhijj,weight2*aweight);
		    hmelaDPhiUnsignedjj_VBF_QCD[k]->Fill(melaDPhiUnsignedjj,weight2*aweight);
			
		    h1D_jpt1_VBF_QCD[k]->Fill(jpt_1,weight2*aweight);
		    h1D_jpt2_VBF_QCD[k]->Fill(jpt_2,weight2*aweight);
		    h1D_jeta1_VBF_QCD[k]->Fill(jeta_1,weight2*aweight);
		    h1D_jeta2_VBF_QCD[k]->Fill(jeta_2,weight2*aweight);
		    h1D_phi1_VBF_QCD[k]->Fill(jphi_1,weight2*aweight);
		    h1D_phi2_VBF_QCD[k]->Fill(jphi_2,weight2*aweight);
		    h1D_mjj_VBF_QCD[k]->Fill(mjj,weight2*aweight);
		    h1D_met_VBF_QCD[k]->Fill(mymet.Pt(),weight2*aweight);



                    if (KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h20_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h21_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)
                       h22_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h23_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int<0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h30_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h31_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h32_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int<0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h33_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (KD_int>=0.0 and KD_bsm_mlt>=0.0 and KD_bsm_mlt<0.2)
                       h40_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.2 and KD_bsm_mlt<0.4)
                       h41_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.4 and KD_bsm_mlt<0.8)//FIXME
                       h42_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (KD_int>=0.0 and KD_bsm_mlt>=0.8 and KD_bsm_mlt<1.0)
                       h43_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaD0hplus>=0.0 and melaD0hplus<0.2)
                       h50_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.2 and melaD0hplus<0.4)
                       h51_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.4 and melaD0hplus<0.8)
                       h52_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0hplus>=0.8 and melaD0hplus<1.0)
                       h53_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1>=0.0 and melaDL1<0.2)
                       h60_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.2 and melaDL1<0.4)
                       h61_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.4 and melaDL1<0.8)
                       h62_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1>=0.8 and melaDL1<1.0)
                       h63_QCD[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDL1Zg>=0.0 and melaDL1Zg<0.2)
                       h70_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.2 and melaDL1Zg<0.4)
                       h71_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.4 and melaDL1Zg<0.8)
                       h72_QCD[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDL1Zg>=0.8 and melaDL1Zg<1.0)
                       h73_QCD[k]->Fill(var1_2,var2,weight2*aweight);


/////////ggH
                    //h2_dPhi_mvQCD[k]->Fill(var1_3,var2,aweight*weight2);

                    if (melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h20_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h21_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h22_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h23_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);

                    if (melaDCPggH<0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h30_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h31_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h32_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH<0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h33_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDCPggH>=0 and melaD0minusggH>=0.0 and melaD0minusggH<0.2)
                       h40_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.2 and melaD0minusggH<0.4)
                       h41_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.4 and melaD0minusggH<0.8)
                       h42_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDCPggH>=0 and melaD0minusggH>=0.8 and melaD0minusggH<1.0)
                       h43_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhijj>=0.0 and melaDPhijj<0.2)
                       h50_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.2 and melaDPhijj<0.4)
                       h51_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.4 and melaDPhijj<0.8)
                       h52_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhijj>=0.8 and melaDPhijj<1.0)
                       h53_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);


                    if (melaDPhiUnsignedjj>=0.0 and melaDPhiUnsignedjj<0.2)
                       h60_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.2 and melaDPhiUnsignedjj<0.4)
                       h61_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.4 and melaDPhiUnsignedjj<0.8)
                       h62_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
                    else if (melaDPhiUnsignedjj>=0.8 and melaDPhiUnsignedjj<1.0)
                       h63_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);


		  if (jphi_1>=-pI && jphi_2>=-pI){
                   double dPhi=  jphi_1 - jphi_2; //dPhiFrom2P( LeptV1.Px(), LeptV1.Py(), METV.Px(),  METV.Py() );
		if (dPhi > TMath::Pi()) dPhi -= 2*TMath::Pi();
  		if (dPhi <= -TMath::Pi()) dPhi += 2*TMath::Pi();
		//	cout<<" dPhi plain  "<<jphi_1-jphi_2<<"  "<<dPhi<<"  "<<fabs(dPhi)<<endl;
	
		if (dPhi>-TMath::Pi() && dPhi<-1.5)
			h70_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>-1.5 && dPhi<-0)
			h71_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>=0 && dPhi<1.5)
			h72_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
		if (dPhi>1.5 && dPhi<TMath::Pi())
			h73_QCDggH[k]->Fill(var1_2,var2,weight2*aweight);
		  }



	 	}
            }
	}
				
    } // end of loop over events

    for (int k=0; k<nbhist; ++k){
       h20_WOS[k]->Scale(h20_OSggH[k]->Integral()/h20_WOS[k]->Integral());
       h21_WOS[k]->Scale(h21_OSggH[k]->Integral()/h21_WOS[k]->Integral());
       h22_WOS[k]->Scale(h22_OSggH[k]->Integral()/h22_WOS[k]->Integral());
       h23_WOS[k]->Scale(h23_OSggH[k]->Integral()/h23_WOS[k]->Integral());
       h20_WSS[k]->Scale(h20_SS[k]->Integral()/h20_WSS[k]->Integral());
       h21_WSS[k]->Scale(h21_SS[k]->Integral()/h21_WSS[k]->Integral());
       h22_WSS[k]->Scale(h22_SS[k]->Integral()/h22_WSS[k]->Integral());
       h23_WSS[k]->Scale(h23_SS[k]->Integral()/h23_WSS[k]->Integral());

       h30_WOS[k]->Scale(h30_OSggH[k]->Integral()/h30_WOS[k]->Integral());
       h31_WOS[k]->Scale(h31_OSggH[k]->Integral()/h31_WOS[k]->Integral());
       h32_WOS[k]->Scale(h32_OSggH[k]->Integral()/h32_WOS[k]->Integral());
       h33_WOS[k]->Scale(h33_OSggH[k]->Integral()/h33_WOS[k]->Integral());
       h30_WSS[k]->Scale(h30_SS[k]->Integral()/h30_WSS[k]->Integral());
       h31_WSS[k]->Scale(h31_SS[k]->Integral()/h31_WSS[k]->Integral());
       h32_WSS[k]->Scale(h32_SS[k]->Integral()/h32_WSS[k]->Integral());
       h33_WSS[k]->Scale(h33_SS[k]->Integral()/h33_WSS[k]->Integral());

       h40_WOS[k]->Scale(h40_OSggH[k]->Integral()/h40_WOS[k]->Integral());
       h41_WOS[k]->Scale(h41_OSggH[k]->Integral()/h41_WOS[k]->Integral());
       h42_WOS[k]->Scale(h42_OSggH[k]->Integral()/h42_WOS[k]->Integral());
       h43_WOS[k]->Scale(h43_OSggH[k]->Integral()/h43_WOS[k]->Integral());
       h40_WSS[k]->Scale(h40_SS[k]->Integral()/h40_WSS[k]->Integral());
       h41_WSS[k]->Scale(h41_SS[k]->Integral()/h41_WSS[k]->Integral());
       h42_WSS[k]->Scale(h42_SS[k]->Integral()/h42_WSS[k]->Integral());
       h43_WSS[k]->Scale(h43_SS[k]->Integral()/h43_WSS[k]->Integral());

       h50_WOS[k]->Scale(h50_OSggH[k]->Integral()/h50_WOS[k]->Integral());
       h51_WOS[k]->Scale(h51_OSggH[k]->Integral()/h51_WOS[k]->Integral());
       h52_WOS[k]->Scale(h52_OSggH[k]->Integral()/h52_WOS[k]->Integral());
       h53_WOS[k]->Scale(h53_OSggH[k]->Integral()/h53_WOS[k]->Integral());
       h50_WSS[k]->Scale(h50_SS[k]->Integral()/h50_WSS[k]->Integral());
       h51_WSS[k]->Scale(h51_SS[k]->Integral()/h51_WSS[k]->Integral());
       h52_WSS[k]->Scale(h52_SS[k]->Integral()/h52_WSS[k]->Integral());
       h53_WSS[k]->Scale(h53_SS[k]->Integral()/h53_WSS[k]->Integral());

       h60_WOS[k]->Scale(h60_OSggH[k]->Integral()/h60_WOS[k]->Integral());
       h61_WOS[k]->Scale(h61_OSggH[k]->Integral()/h61_WOS[k]->Integral());
       h62_WOS[k]->Scale(h62_OSggH[k]->Integral()/h62_WOS[k]->Integral());
       h63_WOS[k]->Scale(h63_OSggH[k]->Integral()/h63_WOS[k]->Integral());
       h60_WSS[k]->Scale(h60_SS[k]->Integral()/h60_WSS[k]->Integral());
       h61_WSS[k]->Scale(h61_SS[k]->Integral()/h61_WSS[k]->Integral());
       h62_WSS[k]->Scale(h62_SS[k]->Integral()/h62_WSS[k]->Integral());
       h63_WSS[k]->Scale(h63_SS[k]->Integral()/h63_WSS[k]->Integral());

       h70_WOS[k]->Scale(h70_OSggH[k]->Integral()/h70_WOS[k]->Integral());
       h71_WOS[k]->Scale(h71_OSggH[k]->Integral()/h71_WOS[k]->Integral());
       h72_WOS[k]->Scale(h72_OSggH[k]->Integral()/h72_WOS[k]->Integral());
       h73_WOS[k]->Scale(h73_OSggH[k]->Integral()/h73_WOS[k]->Integral());
       h70_WSS[k]->Scale(h70_SS[k]->Integral()/h70_WSS[k]->Integral());
       h71_WSS[k]->Scale(h71_SS[k]->Integral()/h71_WSS[k]->Integral());
       h72_WSS[k]->Scale(h72_SS[k]->Integral()/h72_WSS[k]->Integral());
       h73_WSS[k]->Scale(h73_SS[k]->Integral()/h73_WSS[k]->Integral());

////////////////////// ggH
       h20_WOSggH[k]->Scale(h20_OSggH[k]->Integral()/h20_WOSggH[k]->Integral());
       h21_WOSggH[k]->Scale(h21_OSggH[k]->Integral()/h21_WOSggH[k]->Integral());
       h22_WOSggH[k]->Scale(h22_OSggH[k]->Integral()/h22_WOSggH[k]->Integral());
       h23_WOSggH[k]->Scale(h23_OSggH[k]->Integral()/h23_WOSggH[k]->Integral());
       h20_WSSggH[k]->Scale(h20_SSggH[k]->Integral()/h20_WSSggH[k]->Integral());
       h21_WSSggH[k]->Scale(h21_SSggH[k]->Integral()/h21_WSSggH[k]->Integral());
       h22_WSSggH[k]->Scale(h22_SSggH[k]->Integral()/h22_WSSggH[k]->Integral());
       h23_WSSggH[k]->Scale(h23_SSggH[k]->Integral()/h23_WSSggH[k]->Integral());

       h30_WOSggH[k]->Scale(h30_OSggH[k]->Integral()/h30_WOSggH[k]->Integral());
       h31_WOSggH[k]->Scale(h31_OSggH[k]->Integral()/h31_WOSggH[k]->Integral());
       h32_WOSggH[k]->Scale(h32_OSggH[k]->Integral()/h32_WOSggH[k]->Integral());
       h33_WOSggH[k]->Scale(h33_OSggH[k]->Integral()/h33_WOSggH[k]->Integral());
       h30_WSSggH[k]->Scale(h30_SSggH[k]->Integral()/h30_WSSggH[k]->Integral());
       h31_WSSggH[k]->Scale(h31_SSggH[k]->Integral()/h31_WSSggH[k]->Integral());
       h32_WSSggH[k]->Scale(h32_SSggH[k]->Integral()/h32_WSSggH[k]->Integral());
       h33_WSSggH[k]->Scale(h33_SSggH[k]->Integral()/h33_WSSggH[k]->Integral());

       h40_WOSggH[k]->Scale(h40_OSggH[k]->Integral()/h40_WOSggH[k]->Integral());
       h41_WOSggH[k]->Scale(h41_OSggH[k]->Integral()/h41_WOSggH[k]->Integral());
       h42_WOSggH[k]->Scale(h42_OSggH[k]->Integral()/h42_WOSggH[k]->Integral());
       h43_WOSggH[k]->Scale(h43_OSggH[k]->Integral()/h43_WOSggH[k]->Integral());
       h40_WSSggH[k]->Scale(h40_SSggH[k]->Integral()/h40_WSSggH[k]->Integral());
       h41_WSSggH[k]->Scale(h41_SSggH[k]->Integral()/h41_WSSggH[k]->Integral());
       h42_WSSggH[k]->Scale(h42_SSggH[k]->Integral()/h42_WSSggH[k]->Integral());
       h43_WSSggH[k]->Scale(h43_SSggH[k]->Integral()/h43_WSSggH[k]->Integral());

       h50_WOSggH[k]->Scale(h50_OSggH[k]->Integral()/h50_WOSggH[k]->Integral());
       h51_WOSggH[k]->Scale(h51_OSggH[k]->Integral()/h51_WOSggH[k]->Integral());
       h52_WOSggH[k]->Scale(h52_OSggH[k]->Integral()/h52_WOSggH[k]->Integral());
       h53_WOSggH[k]->Scale(h53_OSggH[k]->Integral()/h53_WOSggH[k]->Integral());
       h50_WSSggH[k]->Scale(h50_SSggH[k]->Integral()/h50_WSSggH[k]->Integral());
       h51_WSSggH[k]->Scale(h51_SSggH[k]->Integral()/h51_WSSggH[k]->Integral());
       h52_WSSggH[k]->Scale(h52_SSggH[k]->Integral()/h52_WSSggH[k]->Integral());
       h53_WSSggH[k]->Scale(h53_SSggH[k]->Integral()/h53_WSSggH[k]->Integral());

       h60_WOSggH[k]->Scale(h60_OSggH[k]->Integral()/h60_WOSggH[k]->Integral());
       h61_WOSggH[k]->Scale(h61_OSggH[k]->Integral()/h61_WOSggH[k]->Integral());
       h62_WOSggH[k]->Scale(h62_OSggH[k]->Integral()/h62_WOSggH[k]->Integral());
       h63_WOSggH[k]->Scale(h63_OSggH[k]->Integral()/h63_WOSggH[k]->Integral());
       h60_WSSggH[k]->Scale(h60_SSggH[k]->Integral()/h60_WSSggH[k]->Integral());
       h61_WSSggH[k]->Scale(h61_SSggH[k]->Integral()/h61_WSSggH[k]->Integral());
       h62_WSSggH[k]->Scale(h62_SSggH[k]->Integral()/h62_WSSggH[k]->Integral());
       h63_WSSggH[k]->Scale(h63_SSggH[k]->Integral()/h63_WSSggH[k]->Integral());

       h70_WOSggH[k]->Scale(h70_OSggH[k]->Integral()/h70_WOSggH[k]->Integral());
       h71_WOSggH[k]->Scale(h71_OSggH[k]->Integral()/h71_WOSggH[k]->Integral());
       h72_WOSggH[k]->Scale(h72_OSggH[k]->Integral()/h72_WOSggH[k]->Integral());
       h73_WOSggH[k]->Scale(h73_OSggH[k]->Integral()/h73_WOSggH[k]->Integral());
       h70_WSSggH[k]->Scale(h70_SSggH[k]->Integral()/h70_WSSggH[k]->Integral());
       h71_WSSggH[k]->Scale(h71_SSggH[k]->Integral()/h71_WSSggH[k]->Integral());
       h72_WSSggH[k]->Scale(h72_SSggH[k]->Integral()/h72_WSSggH[k]->Integral());
       h73_WSSggH[k]->Scale(h73_SSggH[k]->Integral()/h73_WSSggH[k]->Integral());


    }

    for (int k=0; k<nbhist; ++k){
       h0_WOS[k]->Scale(h0_OS[k]->Integral()/h0_WOS[k]->Integral());
       h1_WOS[k]->Scale(h1_OS[k]->Integral()/h1_WOS[k]->Integral());
       h0_WSS[k]->Scale(h0_SS[k]->Integral()/h0_WSS[k]->Integral());
       h1_WSS[k]->Scale(h1_SS[k]->Integral()/h1_WSS[k]->Integral());
    }


    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    hincl->Write();

    TString postfix="";
    if (tes==1)
	postfix="_CMS_scale_t_mt_13TeVUp";
    if (tes==-1)
        postfix="_CMS_scale_t_mt_13TeVDown";
    if (tes==15)
        postfix="_CMS_htt_ZLShape_mt_13TeVUp";
    if (tes==-15)
        postfix="_CMS_htt_ZLShape_mt_13TeVDown";
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

    TDirectory *CRQCD0jet =fout->mkdir("mt_antiiso_0jet_cr");
    TDirectory *CRQCD1jet =fout->mkdir("mt_antiiso_boosted_cr");
    TDirectory *CRQCD2jet =fout->mkdir("mt_antiiso_vbf_cr");
    TDirectory *CRW0jet =fout->mkdir("mt_wjets_0jet_cr");
    TDirectory *CRW1jet =fout->mkdir("mt_wjets_boosted_cr");
    TDirectory *CRW2jet =fout->mkdir("mt_wjets_vbf_cr");
    TDirectory *CRSSQCD0jet =fout->mkdir("mt_antiiso_0jet_crSS");
    TDirectory *CRSSQCD1jet =fout->mkdir("mt_antiiso_boosted_crSS");
    TDirectory *CRSSQCD2jet =fout->mkdir("mt_antiiso_vbf_crSS");
    TDirectory *CRSSW0jet =fout->mkdir("mt_wjets_0jet_crSS");
    TDirectory *CRSSW1jet =fout->mkdir("mt_wjets_boosted_crSS");
    TDirectory *CRSSW2jet =fout->mkdir("mt_wjets_vbf_crSS");

    TDirectory *OScontrol = fout->mkdir("OS_control");
    TDirectory *SScontrol = fout->mkdir("SScontrol");
    TDirectory *QCDcontrol = fout->mkdir("QCDcontrol");

    TDirectory *OS0jet =fout->mkdir("mt_0jet");
    TDirectory *SS0jet =fout->mkdir("SS0jet");
    TDirectory *QCD0jet =fout->mkdir("QCD0jet");
    TDirectory *OS1jet =fout->mkdir("mt_boosted");
    TDirectory *SS1jet =fout->mkdir("SS1jet");
    TDirectory *QCD1jet =fout->mkdir("QCD1jet");
    TDirectory *OS2jet =fout->mkdir("mt_vbf");
    TDirectory *SS2jet =fout->mkdir("SSvbf");
    TDirectory *QCD2jet =fout->mkdir("QCDvbf");

    TDirectory *OS20jet =fout->mkdir("mt_vbf_D0_0p0to0p2");
    TDirectory *SS20jet =fout->mkdir("SS20");
    TDirectory *QCD20jet =fout->mkdir("QCD20");
    
    TDirectory *OS21jet =fout->mkdir("mt_vbf_D0_0p2to0p4");
    TDirectory *SS21jet =fout->mkdir("SS21");
    TDirectory *QCD21jet =fout->mkdir("QCD21");
    
    TDirectory *OS22jet =fout->mkdir("mt_vbf_D0_0p4to0p8");
    TDirectory *SS22jet =fout->mkdir("SS22");
    TDirectory *QCD22jet =fout->mkdir("QCD22");
    
    TDirectory *OS23jet =fout->mkdir("mt_vbf_D0_0p8to1p0");
    TDirectory *SS23jet =fout->mkdir("SS23");
    TDirectory *QCD23jet =fout->mkdir("QCD23");

    TDirectory *OS30jet =fout->mkdir("mt_vbf_D0_0p0to0p2_DCPm");
    TDirectory *SS30jet =fout->mkdir("SS30");
    TDirectory *QCD30jet =fout->mkdir("QCD30");
    
    TDirectory *OS31jet =fout->mkdir("mt_vbf_D0_0p2to0p4_DCPm");
    TDirectory *SS31jet =fout->mkdir("SS31");
    TDirectory *QCD31jet =fout->mkdir("QCD31");
    
    TDirectory *OS32jet =fout->mkdir("mt_vbf_D0_0p4to0p8_DCPm");
    TDirectory *SS32jet =fout->mkdir("SS32");
    TDirectory *QCD32jet =fout->mkdir("QCD32");
    
    TDirectory *OS33jet =fout->mkdir("mt_vbf_D0_0p8to1p0_DCPm");
    TDirectory *SS33jet =fout->mkdir("SS33");
    TDirectory *QCD33jet =fout->mkdir("QCD33");

    TDirectory *OS40jet =fout->mkdir("mt_vbf_D0_0p0to0p2_DCPp");
    TDirectory *SS40jet =fout->mkdir("SS40");
    TDirectory *QCD40jet =fout->mkdir("QCD40");
    
    TDirectory *OS41jet =fout->mkdir("mt_vbf_D0_0p2to0p4_DCPp");
    TDirectory *SS41jet =fout->mkdir("SS41");
    TDirectory *QCD41jet =fout->mkdir("QCD41");
    
    TDirectory *OS42jet =fout->mkdir("mt_vbf_D0_0p4to0p8_DCPp");
    TDirectory *SS42jet =fout->mkdir("SS42");
    TDirectory *QCD42jet =fout->mkdir("QCD42");
    
    TDirectory *OS43jet =fout->mkdir("mt_vbf_D0_0p8to1p0_DCPp");
    TDirectory *SS43jet =fout->mkdir("SS43");
    TDirectory *QCD43jet =fout->mkdir("QCD43");

    TDirectory *OS50jet =fout->mkdir("mt_vbf_D0hplus_0p0to0p2");
    TDirectory *SS50jet =fout->mkdir("SS50");
    TDirectory *QCD50jet =fout->mkdir("QCD50");
    
    TDirectory *OS51jet =fout->mkdir("mt_vbf_D0hplus_0p2to0p4");
    TDirectory *SS51jet =fout->mkdir("SS51");
    TDirectory *QCD51jet =fout->mkdir("QCD51");
    
    TDirectory *OS52jet =fout->mkdir("mt_vbf_D0hplus_0p4to0p8");
    TDirectory *SS52jet =fout->mkdir("SS52");
    TDirectory *QCD52jet =fout->mkdir("QCD52");
    
    TDirectory *OS53jet =fout->mkdir("mt_vbf_D0hplus_0p8to1p0");
    TDirectory *SS53jet =fout->mkdir("SS53");
    TDirectory *QCD53jet =fout->mkdir("QCD53");

    TDirectory *OS60jet =fout->mkdir("mt_vbf_DL1_0p0to0p2");
    TDirectory *SS60jet =fout->mkdir("SS60");
    TDirectory *QCD60jet =fout->mkdir("QCD60");
    
    TDirectory *OS61jet =fout->mkdir("mt_vbf_DL1_0p2to0p4");
    TDirectory *SS61jet =fout->mkdir("SS61");
    TDirectory *QCD61jet =fout->mkdir("QCD61");
    
    TDirectory *OS62jet =fout->mkdir("mt_vbf_DL1_0p4to0p8");
    TDirectory *SS62jet =fout->mkdir("SS62");
    TDirectory *QCD62jet =fout->mkdir("QCD62");
    
    TDirectory *OS63jet =fout->mkdir("mt_vbf_DL1_0p8to1p0");
    TDirectory *SS63jet =fout->mkdir("SS63");
    TDirectory *QCD63jet =fout->mkdir("QCD63");

    TDirectory *OS70jet =fout->mkdir("mt_vbf_DL1Zg_0p0to0p2");
    TDirectory *SS70jet =fout->mkdir("SS70");
    TDirectory *QCD70jet =fout->mkdir("QCD70");
    
    TDirectory *OS71jet =fout->mkdir("mt_vbf_DL1Zg_0p2to0p4");
    TDirectory *SS71jet =fout->mkdir("SS71");
    TDirectory *QCD71jet =fout->mkdir("QCD71");
    
    TDirectory *OS72jet =fout->mkdir("mt_vbf_DL1Zg_0p4to0p8");
    TDirectory *SS72jet =fout->mkdir("SS72");
    TDirectory *QCD72jet =fout->mkdir("QCD72");
    
    TDirectory *OS73jet =fout->mkdir("mt_vbf_DL1Zg_0p8to1p0");
    TDirectory *SS73jet =fout->mkdir("SS73");
    TDirectory *QCD73jet =fout->mkdir("QCD73");
 

/////////////////ggH block starts

    TDirectory *OS20jetggH =fout->mkdir("mt_vbf_D0_0p0to0p2_ggH");
    TDirectory *SS20jetggH =fout->mkdir("SS20ggH");
    TDirectory *QCD20jetggH =fout->mkdir("QCD20ggH");

    TDirectory *OS21jetggH =fout->mkdir("mt_vbf_D0_0p2to0p4_ggH");
    TDirectory *SS21jetggH =fout->mkdir("SS21ggH");
    TDirectory *QCD21jetggH =fout->mkdir("QCD21ggH");
    
    TDirectory *OS22jetggH =fout->mkdir("mt_vbf_D0_0p4to0p8_ggH");
    TDirectory *SS22jetggH =fout->mkdir("SS22ggH");
    TDirectory *QCD22jetggH =fout->mkdir("QCD22ggH");
    
    TDirectory *OS23jetggH =fout->mkdir("mt_vbf_D0_0p8to1p0_ggH");
    TDirectory *SS23jetggH =fout->mkdir("SS23ggH");
    TDirectory *QCD23jetggH =fout->mkdir("QCD23ggH");

    TDirectory *OS30jetggH =fout->mkdir("mt_vbf_D0_0p0to0p2_DCPm_ggH");
    TDirectory *SS30jetggH =fout->mkdir("SS30ggH");
    TDirectory *QCD30jetggH =fout->mkdir("QCD30ggH");

    TDirectory *OS31jetggH =fout->mkdir("mt_vbf_D0_0p2to0p4_DCPm_ggH");
    TDirectory *SS31jetggH =fout->mkdir("SS31ggH");
    TDirectory *QCD31jetggH =fout->mkdir("QCD31ggH");

    TDirectory *OS32jetggH =fout->mkdir("mt_vbf_D0_0p4to0p8_DCPm_ggH");
    TDirectory *SS32jetggH =fout->mkdir("SS32ggH");
    TDirectory *QCD32jetggH =fout->mkdir("QCD32ggH");

    TDirectory *OS33jetggH =fout->mkdir("mt_vbf_D0_0p8to1p0_DCPm_ggH");
    TDirectory *SS33jetggH =fout->mkdir("SS33ggH");
    TDirectory *QCD33jetggH =fout->mkdir("QCD33ggH");


    TDirectory *OS40jetggH =fout->mkdir("mt_vbf_D0_Pito1p5m_ggH");
    TDirectory *SS40jetggH =fout->mkdir("SS40ggH");
    TDirectory *QCD40jetggH =fout->mkdir("QCD40ggH");

    TDirectory *OS41jetggH =fout->mkdir("mt_vbf_D0_1p5to0_ggH");
    TDirectory *SS41jetggH =fout->mkdir("SS41ggH");
    TDirectory *QCD41jetggH =fout->mkdir("QCD41ggH");

    TDirectory *OS42jetggH =fout->mkdir("mt_vbf_D0_0to1p5p_ggH");
    TDirectory *SS42jetggH =fout->mkdir("SS42ggH");
    TDirectory *QCD42jetggH =fout->mkdir("QCD42ggH");

    TDirectory *OS43jetggH =fout->mkdir("mt_vbf_D0_1p5toPi_ggH");
    TDirectory *SS43jetggH =fout->mkdir("SS43ggH");
    TDirectory *QCD43jetggH =fout->mkdir("QCD43ggH");
    

    TDirectory *OS50jetggH =fout->mkdir("mt_vbf_Pito1p6m_ggH");
    TDirectory *SS50jetggH =fout->mkdir("SS50ggH");
    TDirectory *QCD50jetggH =fout->mkdir("QCD50ggH");

    TDirectory *OS51jetggH =fout->mkdir("mt_vbf_1p6to0_ggH");
    TDirectory *SS51jetggH =fout->mkdir("SS51ggH");
    TDirectory *QCD51jetggH =fout->mkdir("QCD51ggH");

    TDirectory *OS52jetggH =fout->mkdir("mt_vbf_0to1p6p_ggH");
    TDirectory *SS52jetggH =fout->mkdir("SS52ggH");
    TDirectory *QCD52jetggH =fout->mkdir("QCD52ggH");

    TDirectory *OS53jetggH =fout->mkdir("mt_vbf_1p6toPi_ggH");
    TDirectory *SS53jetggH =fout->mkdir("SS53ggH");
    TDirectory *QCD53jetggH =fout->mkdir("QCD53ggH");


    TDirectory *OS60jetggH =fout->mkdir("mt_vbf_Pito1p6m_ggH_Uns");
    TDirectory *SS60jetggH =fout->mkdir("SS60ggH");
    TDirectory *QCD60jetggH =fout->mkdir("QCD60ggH");

    TDirectory *OS61jetggH =fout->mkdir("mt_vbf_1p6to0_ggH_Uns");
    TDirectory *SS61jetggH =fout->mkdir("SS61ggH");
    TDirectory *QCD61jetggH =fout->mkdir("QCD61ggH");

    TDirectory *OS62jetggH =fout->mkdir("mt_vbf_0to1p6p_ggH_Uns");
    TDirectory *SS62jetggH =fout->mkdir("SS62ggH");
    TDirectory *QCD62jetggH =fout->mkdir("QCD62ggH");

    TDirectory *OS63jetggH =fout->mkdir("mt_vbf_1p6toPi_ggH_Uns");
    TDirectory *SS63jetggH =fout->mkdir("SS63ggH");
    TDirectory *QCD63jetggH =fout->mkdir("QCD63ggH");

    TDirectory *OS70jetggH =fout->mkdir("mt_vbf_dPhia_ggH");
    TDirectory *SS70jetggH =fout->mkdir("SS70ggH");
    TDirectory *QCD70jetggH =fout->mkdir("QCD70ggH");

    TDirectory *OS71jetggH =fout->mkdir("mt_vbf_dPhib_ggH");
    TDirectory *SS71jetggH =fout->mkdir("SS71ggH");
    TDirectory *QCD71jetggH =fout->mkdir("QCD71ggH");

    TDirectory *OS72jetggH =fout->mkdir("mt_vbf_dPhic_ggH");
    TDirectory *SS72jetggH =fout->mkdir("SS72ggH");
    TDirectory *QCD72jetggH =fout->mkdir("QCD72ggH");

    TDirectory *OS73jetggH =fout->mkdir("mt_vbf_dPhid_ggH");
    TDirectory *SS73jetggH =fout->mkdir("SS73ggH");
    TDirectory *QCD73jetggH =fout->mkdir("QCD73ggH");



/////////////ggH block end




    if (nbhist==1) postfixJES[0]=postfix;

    for (int k=0; k<nbhist; ++k){

        if (tes==100) postfix=postfixJES[k];
        if (tes==1) postfix=postfixTES[k];
        if (tes==16) postfix=postfixDM[k];
        if (tes==17) postfix=postfixZLshape[k];
        if (tes==18) postfix=postfixZLnorm[k];
        if (tes==19) postfix=postfixFakeDM[k];

        fout->cd();
        n70[k]->SetName("n70"+postfix);
        n70[k]->Write();
        n70SS[k]->SetName("n70SS"+postfix);
        n70SS[k]->Write();
	hCorr_OS->Write();
    }



    for (int k=0; k<nbhist; ++k){

       if (tes==100) postfix=postfixJES[k];
       if (tes==1) postfix=postfixTES[k];
       if (tes==16) postfix=postfixDM[k];
       if (tes==17) postfix=postfixZLshape[k];
       if (tes==18) postfix=postfixZLnorm[k];
       if (tes==19) postfix=postfixFakeDM[k];

       for (int nn=1; nn<h0_OS[k]->GetSize()-1; ++nn){
           if (h20_OS[k]->GetBinContent(nn)<0) h20_OS[k]->SetBinContent(nn,0.00001);
           if (h20_SS[k]->GetBinContent(nn)<0) h20_SS[k]->SetBinContent(nn,0.00001);
           if (h20_QCD[k]->GetBinContent(nn)<0) h20_QCD[k]->SetBinContent(nn,0.00001);
           if (h20_WOS[k]->GetBinContent(nn)<0) h20_WOS[k]->SetBinContent(nn,0.00001);
           if (h20_WSS[k]->GetBinContent(nn)<0) h20_WSS[k]->SetBinContent(nn,0.00001);
           if (h21_OS[k]->GetBinContent(nn)<0) h21_OS[k]->SetBinContent(nn,0.00001);
           if (h21_SS[k]->GetBinContent(nn)<0) h21_SS[k]->SetBinContent(nn,0.00001);
           if (h21_QCD[k]->GetBinContent(nn)<0) h21_QCD[k]->SetBinContent(nn,0.00001);
           if (h21_WOS[k]->GetBinContent(nn)<0) h21_WOS[k]->SetBinContent(nn,0.00001);
           if (h21_WSS[k]->GetBinContent(nn)<0) h21_WSS[k]->SetBinContent(nn,0.00001);
           if (h22_OS[k]->GetBinContent(nn)<0) h22_OS[k]->SetBinContent(nn,0.00001);
           if (h22_SS[k]->GetBinContent(nn)<0) h22_SS[k]->SetBinContent(nn,0.00001);
           if (h22_QCD[k]->GetBinContent(nn)<0) h22_QCD[k]->SetBinContent(nn,0.00001);
           if (h22_WOS[k]->GetBinContent(nn)<0) h22_WOS[k]->SetBinContent(nn,0.00001);
           if (h22_WSS[k]->GetBinContent(nn)<0) h22_WSS[k]->SetBinContent(nn,0.00001);
           if (h23_OS[k]->GetBinContent(nn)<0) h23_OS[k]->SetBinContent(nn,0.00001);
           if (h23_SS[k]->GetBinContent(nn)<0) h23_SS[k]->SetBinContent(nn,0.00001);
           if (h23_QCD[k]->GetBinContent(nn)<0) h23_QCD[k]->SetBinContent(nn,0.00001);
           if (h23_WOS[k]->GetBinContent(nn)<0) h23_WOS[k]->SetBinContent(nn,0.00001);
           if (h23_WSS[k]->GetBinContent(nn)<0) h23_WSS[k]->SetBinContent(nn,0.00001);

           if (h30_OS[k]->GetBinContent(nn)<0) h30_OS[k]->SetBinContent(nn,0.00001);
           if (h30_SS[k]->GetBinContent(nn)<0) h30_SS[k]->SetBinContent(nn,0.00001);
           if (h30_QCD[k]->GetBinContent(nn)<0) h30_QCD[k]->SetBinContent(nn,0.00001);
           if (h30_WOS[k]->GetBinContent(nn)<0) h30_WOS[k]->SetBinContent(nn,0.00001);
           if (h30_WSS[k]->GetBinContent(nn)<0) h30_WSS[k]->SetBinContent(nn,0.00001);
           if (h31_OS[k]->GetBinContent(nn)<0) h31_OS[k]->SetBinContent(nn,0.00001);
           if (h31_SS[k]->GetBinContent(nn)<0) h31_SS[k]->SetBinContent(nn,0.00001);
           if (h31_QCD[k]->GetBinContent(nn)<0) h31_QCD[k]->SetBinContent(nn,0.00001);
           if (h31_WOS[k]->GetBinContent(nn)<0) h31_WOS[k]->SetBinContent(nn,0.00001);
           if (h31_WSS[k]->GetBinContent(nn)<0) h31_WSS[k]->SetBinContent(nn,0.00001);
           if (h32_OS[k]->GetBinContent(nn)<0) h32_OS[k]->SetBinContent(nn,0.00001);
           if (h32_SS[k]->GetBinContent(nn)<0) h32_SS[k]->SetBinContent(nn,0.00001);
           if (h32_QCD[k]->GetBinContent(nn)<0) h32_QCD[k]->SetBinContent(nn,0.00001);
           if (h32_WOS[k]->GetBinContent(nn)<0) h32_WOS[k]->SetBinContent(nn,0.00001);
           if (h32_WSS[k]->GetBinContent(nn)<0) h32_WSS[k]->SetBinContent(nn,0.00001);
           if (h33_OS[k]->GetBinContent(nn)<0) h33_OS[k]->SetBinContent(nn,0.00001);
           if (h33_SS[k]->GetBinContent(nn)<0) h33_SS[k]->SetBinContent(nn,0.00001);
           if (h33_QCD[k]->GetBinContent(nn)<0) h33_QCD[k]->SetBinContent(nn,0.00001);
           if (h33_WOS[k]->GetBinContent(nn)<0) h33_WOS[k]->SetBinContent(nn,0.00001);
           if (h33_WSS[k]->GetBinContent(nn)<0) h33_WSS[k]->SetBinContent(nn,0.00001);

           if (h40_OS[k]->GetBinContent(nn)<0) h40_OS[k]->SetBinContent(nn,0.00001);
           if (h40_SS[k]->GetBinContent(nn)<0) h40_SS[k]->SetBinContent(nn,0.00001);
           if (h40_QCD[k]->GetBinContent(nn)<0) h40_QCD[k]->SetBinContent(nn,0.00001);
           if (h40_WOS[k]->GetBinContent(nn)<0) h40_WOS[k]->SetBinContent(nn,0.00001);
           if (h40_WSS[k]->GetBinContent(nn)<0) h40_WSS[k]->SetBinContent(nn,0.00001);
           if (h41_OS[k]->GetBinContent(nn)<0) h41_OS[k]->SetBinContent(nn,0.00001);
           if (h41_SS[k]->GetBinContent(nn)<0) h41_SS[k]->SetBinContent(nn,0.00001);
           if (h41_QCD[k]->GetBinContent(nn)<0) h41_QCD[k]->SetBinContent(nn,0.00001);
           if (h41_WOS[k]->GetBinContent(nn)<0) h41_WOS[k]->SetBinContent(nn,0.00001);
           if (h41_WSS[k]->GetBinContent(nn)<0) h41_WSS[k]->SetBinContent(nn,0.00001);
           if (h42_OS[k]->GetBinContent(nn)<0) h42_OS[k]->SetBinContent(nn,0.00001);
           if (h42_SS[k]->GetBinContent(nn)<0) h42_SS[k]->SetBinContent(nn,0.00001);
           if (h42_QCD[k]->GetBinContent(nn)<0) h42_QCD[k]->SetBinContent(nn,0.00001);
           if (h42_WOS[k]->GetBinContent(nn)<0) h42_WOS[k]->SetBinContent(nn,0.00001);
           if (h42_WSS[k]->GetBinContent(nn)<0) h42_WSS[k]->SetBinContent(nn,0.00001);
           if (h43_OS[k]->GetBinContent(nn)<0) h43_OS[k]->SetBinContent(nn,0.00001);
           if (h43_SS[k]->GetBinContent(nn)<0) h43_SS[k]->SetBinContent(nn,0.00001);
           if (h43_QCD[k]->GetBinContent(nn)<0) h43_QCD[k]->SetBinContent(nn,0.00001);
           if (h43_WOS[k]->GetBinContent(nn)<0) h43_WOS[k]->SetBinContent(nn,0.00001);
           if (h43_WSS[k]->GetBinContent(nn)<0) h43_WSS[k]->SetBinContent(nn,0.00001);

           if (h50_OS[k]->GetBinContent(nn)<0) h50_OS[k]->SetBinContent(nn,0.00001);
           if (h50_SS[k]->GetBinContent(nn)<0) h50_SS[k]->SetBinContent(nn,0.00001);
           if (h50_QCD[k]->GetBinContent(nn)<0) h50_QCD[k]->SetBinContent(nn,0.00001);
           if (h50_WOS[k]->GetBinContent(nn)<0) h50_WOS[k]->SetBinContent(nn,0.00001);
           if (h50_WSS[k]->GetBinContent(nn)<0) h50_WSS[k]->SetBinContent(nn,0.00001);
           if (h51_OS[k]->GetBinContent(nn)<0) h51_OS[k]->SetBinContent(nn,0.00001);
           if (h51_SS[k]->GetBinContent(nn)<0) h51_SS[k]->SetBinContent(nn,0.00001);
           if (h51_QCD[k]->GetBinContent(nn)<0) h51_QCD[k]->SetBinContent(nn,0.00001);
           if (h51_WOS[k]->GetBinContent(nn)<0) h51_WOS[k]->SetBinContent(nn,0.00001);
           if (h51_WSS[k]->GetBinContent(nn)<0) h51_WSS[k]->SetBinContent(nn,0.00001);
           if (h52_OS[k]->GetBinContent(nn)<0) h52_OS[k]->SetBinContent(nn,0.00001);
           if (h52_SS[k]->GetBinContent(nn)<0) h52_SS[k]->SetBinContent(nn,0.00001);
           if (h52_QCD[k]->GetBinContent(nn)<0) h52_QCD[k]->SetBinContent(nn,0.00001);
           if (h52_WOS[k]->GetBinContent(nn)<0) h52_WOS[k]->SetBinContent(nn,0.00001);
           if (h52_WSS[k]->GetBinContent(nn)<0) h52_WSS[k]->SetBinContent(nn,0.00001);
           if (h53_OS[k]->GetBinContent(nn)<0) h53_OS[k]->SetBinContent(nn,0.00001);
           if (h53_SS[k]->GetBinContent(nn)<0) h53_SS[k]->SetBinContent(nn,0.00001);
           if (h53_QCD[k]->GetBinContent(nn)<0) h53_QCD[k]->SetBinContent(nn,0.00001);
           if (h53_WOS[k]->GetBinContent(nn)<0) h53_WOS[k]->SetBinContent(nn,0.00001);
           if (h53_WSS[k]->GetBinContent(nn)<0) h53_WSS[k]->SetBinContent(nn,0.00001);

           if (h60_OS[k]->GetBinContent(nn)<0) h60_OS[k]->SetBinContent(nn,0.00001);
           if (h60_SS[k]->GetBinContent(nn)<0) h60_SS[k]->SetBinContent(nn,0.00001);
           if (h60_QCD[k]->GetBinContent(nn)<0) h60_QCD[k]->SetBinContent(nn,0.00001);
           if (h60_WOS[k]->GetBinContent(nn)<0) h60_WOS[k]->SetBinContent(nn,0.00001);
           if (h60_WSS[k]->GetBinContent(nn)<0) h60_WSS[k]->SetBinContent(nn,0.00001);
           if (h61_OS[k]->GetBinContent(nn)<0) h61_OS[k]->SetBinContent(nn,0.00001);
           if (h61_SS[k]->GetBinContent(nn)<0) h61_SS[k]->SetBinContent(nn,0.00001);
           if (h61_QCD[k]->GetBinContent(nn)<0) h61_QCD[k]->SetBinContent(nn,0.00001);
           if (h61_WOS[k]->GetBinContent(nn)<0) h61_WOS[k]->SetBinContent(nn,0.00001);
           if (h61_WSS[k]->GetBinContent(nn)<0) h61_WSS[k]->SetBinContent(nn,0.00001);
           if (h62_OS[k]->GetBinContent(nn)<0) h62_OS[k]->SetBinContent(nn,0.00001);
           if (h62_SS[k]->GetBinContent(nn)<0) h62_SS[k]->SetBinContent(nn,0.00001);
           if (h62_QCD[k]->GetBinContent(nn)<0) h62_QCD[k]->SetBinContent(nn,0.00001);
           if (h62_WOS[k]->GetBinContent(nn)<0) h62_WOS[k]->SetBinContent(nn,0.00001);
           if (h62_WSS[k]->GetBinContent(nn)<0) h62_WSS[k]->SetBinContent(nn,0.00001);
           if (h63_OS[k]->GetBinContent(nn)<0) h63_OS[k]->SetBinContent(nn,0.00001);
           if (h63_SS[k]->GetBinContent(nn)<0) h63_SS[k]->SetBinContent(nn,0.00001);
           if (h63_QCD[k]->GetBinContent(nn)<0) h63_QCD[k]->SetBinContent(nn,0.00001);
           if (h63_WOS[k]->GetBinContent(nn)<0) h63_WOS[k]->SetBinContent(nn,0.00001);
           if (h63_WSS[k]->GetBinContent(nn)<0) h63_WSS[k]->SetBinContent(nn,0.00001);

           if (h70_OS[k]->GetBinContent(nn)<0) h70_OS[k]->SetBinContent(nn,0.00001);
           if (h70_SS[k]->GetBinContent(nn)<0) h70_SS[k]->SetBinContent(nn,0.00001);
           if (h70_QCD[k]->GetBinContent(nn)<0) h70_QCD[k]->SetBinContent(nn,0.00001);
           if (h70_WOS[k]->GetBinContent(nn)<0) h70_WOS[k]->SetBinContent(nn,0.00001);
           if (h70_WSS[k]->GetBinContent(nn)<0) h70_WSS[k]->SetBinContent(nn,0.00001);
           if (h71_OS[k]->GetBinContent(nn)<0) h71_OS[k]->SetBinContent(nn,0.00001);
           if (h71_SS[k]->GetBinContent(nn)<0) h71_SS[k]->SetBinContent(nn,0.00001);
           if (h71_QCD[k]->GetBinContent(nn)<0) h71_QCD[k]->SetBinContent(nn,0.00001);
           if (h71_WOS[k]->GetBinContent(nn)<0) h71_WOS[k]->SetBinContent(nn,0.00001);
           if (h71_WSS[k]->GetBinContent(nn)<0) h71_WSS[k]->SetBinContent(nn,0.00001);
           if (h72_OS[k]->GetBinContent(nn)<0) h72_OS[k]->SetBinContent(nn,0.00001);
           if (h72_SS[k]->GetBinContent(nn)<0) h72_SS[k]->SetBinContent(nn,0.00001);
           if (h72_QCD[k]->GetBinContent(nn)<0) h72_QCD[k]->SetBinContent(nn,0.00001);
           if (h72_WOS[k]->GetBinContent(nn)<0) h72_WOS[k]->SetBinContent(nn,0.00001);
           if (h72_WSS[k]->GetBinContent(nn)<0) h72_WSS[k]->SetBinContent(nn,0.00001);
           if (h73_OS[k]->GetBinContent(nn)<0) h73_OS[k]->SetBinContent(nn,0.00001);
           if (h73_SS[k]->GetBinContent(nn)<0) h73_SS[k]->SetBinContent(nn,0.00001);
           if (h73_QCD[k]->GetBinContent(nn)<0) h73_QCD[k]->SetBinContent(nn,0.00001);
           if (h73_WOS[k]->GetBinContent(nn)<0) h73_WOS[k]->SetBinContent(nn,0.00001);
           if (h73_WSS[k]->GetBinContent(nn)<0) h73_WSS[k]->SetBinContent(nn,0.00001);

           if (h0_OS[k]->GetBinContent(nn)<0) h0_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_0jet_OS[k]->GetBinContent(nn)<0) hmelaDCP_0jet_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_0jet_OS[k]->GetBinContent(nn)<0) hmelaDCPggH_0jet_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_0jet_OS[k]->GetBinContent(nn)<0) hmelaD0minus_0jet_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_0jet_OS[k]->GetBinContent(nn)<0) hmelaD0minusggH_0jet_OS[k]->SetBinContent(nn,0.00001);

           if (h0_SS[k]->GetBinContent(nn)<0) h0_SS[k]->SetBinContent(nn,0.00001);
           if (h0_QCD[k]->GetBinContent(nn)<0) h0_QCD[k]->SetBinContent(nn,0.00001);
           if (h0_WOS[k]->GetBinContent(nn)<0) h0_WOS[k]->SetBinContent(nn,0.00001);
           if (h0_WSS[k]->GetBinContent(nn)<0) h0_WSS[k]->SetBinContent(nn,0.00001);

           if (h1_OS[k]->GetBinContent(nn)<0) h1_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_boosted_OS[k]->GetBinContent(nn)<0) hmelaDCP_boosted_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_boosted_OS[k]->GetBinContent(nn)<0) hmelaDCPggH_boosted_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_boosted_OS[k]->GetBinContent(nn)<0) hmelaD0minus_boosted_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_boosted_OS[k]->GetBinContent(nn)<0) hmelaD0minusggH_boosted_OS[k]->SetBinContent(nn,0.00001);


           if (h1_SS[k]->GetBinContent(nn)<0) h1_SS[k]->SetBinContent(nn,0.00001);
           if (h1_QCD[k]->GetBinContent(nn)<0) h1_QCD[k]->SetBinContent(nn,0.00001);
           if (h1_WOS[k]->GetBinContent(nn)<0) h1_WOS[k]->SetBinContent(nn,0.00001);
           if (h1_WSS[k]->GetBinContent(nn)<0) h1_WSS[k]->SetBinContent(nn,0.00001);

           if (h2_OS[k]->GetBinContent(nn)<0) h2_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_VBF_OS[k]->GetBinContent(nn)<0) hmelaDCP_VBF_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_VBF_OS[k]->GetBinContent(nn)<0) hmelaDCPggH_VBF_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_VBF_OS[k]->GetBinContent(nn)<0) hmelaD0minus_VBF_OS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_VBF_OS[k]->GetBinContent(nn)<0) hmelaD0minusggH_VBF_OS[k]->SetBinContent(nn,0.00001);

           if (h2_SS[k]->GetBinContent(nn)<0) h2_SS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_VBF_SS[k]->GetBinContent(nn)<0) hmelaDCP_VBF_SS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_VBF_SS[k]->GetBinContent(nn)<0) hmelaDCPggH_VBF_SS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_VBF_SS[k]->GetBinContent(nn)<0) hmelaD0minus_VBF_SS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_VBF_SS[k]->GetBinContent(nn)<0) hmelaD0minusggH_VBF_SS[k]->SetBinContent(nn,0.00001);

           if (h2_QCD[k]->GetBinContent(nn)<0) h2_QCD[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_VBF_QCD[k]->GetBinContent(nn)<0) hmelaDCP_VBF_QCD[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_VBF_QCD[k]->GetBinContent(nn)<0) hmelaDCPggH_VBF_QCD[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_VBF_QCD[k]->GetBinContent(nn)<0) hmelaD0minus_VBF_QCD[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_VBF_QCD[k]->GetBinContent(nn)<0) hmelaD0minusggH_VBF_QCD[k]->SetBinContent(nn,0.00001);
           
	   if (h2_WOS[k]->GetBinContent(nn)<0) h2_WOS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_VBF_WOS[k]->GetBinContent(nn)<0) hmelaDCP_VBF_WOS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_VBF_WOS[k]->GetBinContent(nn)<0) hmelaDCPggH_VBF_WOS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_VBF_WOS[k]->GetBinContent(nn)<0) hmelaD0minus_VBF_WOS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_VBF_WOS[k]->GetBinContent(nn)<0) hmelaD0minusggH_VBF_WOS[k]->SetBinContent(nn,0.00001);
           
	   if (h2_WSS[k]->GetBinContent(nn)<0) h2_WSS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCP_VBF_WSS[k]->GetBinContent(nn)<0) hmelaDCP_VBF_WSS[k]->SetBinContent(nn,0.00001);
           if (hmelaDCPggH_VBF_WSS[k]->GetBinContent(nn)<0) hmelaDCPggH_VBF_WSS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minus_VBF_WSS[k]->GetBinContent(nn)<0) hmelaD0minus_VBF_WSS[k]->SetBinContent(nn,0.00001);
           if (hmelaD0minusggH_VBF_WSS[k]->GetBinContent(nn)<0) hmelaD0minusggH_VBF_WSS[k]->SetBinContent(nn,0.00001);

	   //// make copy for ggH
           if (h20_OSggH[k]->GetBinContent(nn)<0) h20_OSggH[k]->SetBinContent(nn,0.00001);
           if (h20_SSggH[k]->GetBinContent(nn)<0) h20_SSggH[k]->SetBinContent(nn,0.00001);
           if (h20_QCDggH[k]->GetBinContent(nn)<0) h20_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h20_WOSggH[k]->GetBinContent(nn)<0) h20_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h20_WSSggH[k]->GetBinContent(nn)<0) h20_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h21_OSggH[k]->GetBinContent(nn)<0) h21_OSggH[k]->SetBinContent(nn,0.00001);
           if (h21_SSggH[k]->GetBinContent(nn)<0) h21_SSggH[k]->SetBinContent(nn,0.00001);
           if (h21_QCDggH[k]->GetBinContent(nn)<0) h21_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h21_WOSggH[k]->GetBinContent(nn)<0) h21_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h21_WSSggH[k]->GetBinContent(nn)<0) h21_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h22_OSggH[k]->GetBinContent(nn)<0) h22_OSggH[k]->SetBinContent(nn,0.00001);
           if (h22_SSggH[k]->GetBinContent(nn)<0) h22_SSggH[k]->SetBinContent(nn,0.00001);
           if (h22_QCDggH[k]->GetBinContent(nn)<0) h22_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h22_WOSggH[k]->GetBinContent(nn)<0) h22_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h22_WSSggH[k]->GetBinContent(nn)<0) h22_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h23_OSggH[k]->GetBinContent(nn)<0) h23_OSggH[k]->SetBinContent(nn,0.00001);
           if (h23_SSggH[k]->GetBinContent(nn)<0) h23_SSggH[k]->SetBinContent(nn,0.00001);
           if (h23_QCDggH[k]->GetBinContent(nn)<0) h23_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h23_WOSggH[k]->GetBinContent(nn)<0) h23_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h23_WSSggH[k]->GetBinContent(nn)<0) h23_WSSggH[k]->SetBinContent(nn,0.00001);

	   
           if (h30_OSggH[k]->GetBinContent(nn)<0) h30_OSggH[k]->SetBinContent(nn,0.00001);
           if (h30_SSggH[k]->GetBinContent(nn)<0) h30_SSggH[k]->SetBinContent(nn,0.00001);
           if (h30_QCDggH[k]->GetBinContent(nn)<0) h30_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h30_WOSggH[k]->GetBinContent(nn)<0) h30_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h30_WSSggH[k]->GetBinContent(nn)<0) h30_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h31_OSggH[k]->GetBinContent(nn)<0) h31_OSggH[k]->SetBinContent(nn,0.00001);
           if (h31_SSggH[k]->GetBinContent(nn)<0) h31_SSggH[k]->SetBinContent(nn,0.00001);
           if (h31_QCDggH[k]->GetBinContent(nn)<0) h31_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h31_WOSggH[k]->GetBinContent(nn)<0) h31_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h31_WSSggH[k]->GetBinContent(nn)<0) h31_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h32_OSggH[k]->GetBinContent(nn)<0) h32_OSggH[k]->SetBinContent(nn,0.00001);
           if (h32_SSggH[k]->GetBinContent(nn)<0) h32_SSggH[k]->SetBinContent(nn,0.00001);
           if (h32_QCDggH[k]->GetBinContent(nn)<0) h32_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h32_WOSggH[k]->GetBinContent(nn)<0) h32_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h32_WSSggH[k]->GetBinContent(nn)<0) h32_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h33_OSggH[k]->GetBinContent(nn)<0) h33_OSggH[k]->SetBinContent(nn,0.00001);
           if (h33_SSggH[k]->GetBinContent(nn)<0) h33_SSggH[k]->SetBinContent(nn,0.00001);
           if (h33_QCDggH[k]->GetBinContent(nn)<0) h33_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h33_WOSggH[k]->GetBinContent(nn)<0) h33_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h33_WSSggH[k]->GetBinContent(nn)<0) h33_WSSggH[k]->SetBinContent(nn,0.00001);

           if (h40_OSggH[k]->GetBinContent(nn)<0) h40_OSggH[k]->SetBinContent(nn,0.00001);
           if (h40_SSggH[k]->GetBinContent(nn)<0) h40_SSggH[k]->SetBinContent(nn,0.00001);
           if (h40_QCDggH[k]->GetBinContent(nn)<0) h40_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h40_WOSggH[k]->GetBinContent(nn)<0) h40_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h40_WSSggH[k]->GetBinContent(nn)<0) h40_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h41_OSggH[k]->GetBinContent(nn)<0) h41_OSggH[k]->SetBinContent(nn,0.00001);
           if (h41_SSggH[k]->GetBinContent(nn)<0) h41_SSggH[k]->SetBinContent(nn,0.00001);
           if (h41_QCDggH[k]->GetBinContent(nn)<0) h41_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h41_WOSggH[k]->GetBinContent(nn)<0) h41_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h41_WSSggH[k]->GetBinContent(nn)<0) h41_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h42_OSggH[k]->GetBinContent(nn)<0) h42_OSggH[k]->SetBinContent(nn,0.00001);
           if (h42_SSggH[k]->GetBinContent(nn)<0) h42_SSggH[k]->SetBinContent(nn,0.00001);
           if (h42_QCDggH[k]->GetBinContent(nn)<0) h42_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h42_WOSggH[k]->GetBinContent(nn)<0) h42_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h42_WSSggH[k]->GetBinContent(nn)<0) h42_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h43_OSggH[k]->GetBinContent(nn)<0) h43_OSggH[k]->SetBinContent(nn,0.00001);
           if (h43_SSggH[k]->GetBinContent(nn)<0) h43_SSggH[k]->SetBinContent(nn,0.00001);
           if (h43_QCDggH[k]->GetBinContent(nn)<0) h43_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h43_WOSggH[k]->GetBinContent(nn)<0) h43_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h43_WSSggH[k]->GetBinContent(nn)<0) h43_WSSggH[k]->SetBinContent(nn,0.00001);

           if (h50_OSggH[k]->GetBinContent(nn)<0) h50_OSggH[k]->SetBinContent(nn,0.00001);
           if (h50_SSggH[k]->GetBinContent(nn)<0) h50_SSggH[k]->SetBinContent(nn,0.00001);
           if (h50_QCDggH[k]->GetBinContent(nn)<0) h50_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h50_WOSggH[k]->GetBinContent(nn)<0) h50_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h50_WSSggH[k]->GetBinContent(nn)<0) h50_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h51_OSggH[k]->GetBinContent(nn)<0) h51_OSggH[k]->SetBinContent(nn,0.00001);
           if (h51_SSggH[k]->GetBinContent(nn)<0) h51_SSggH[k]->SetBinContent(nn,0.00001);
           if (h51_QCDggH[k]->GetBinContent(nn)<0) h51_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h51_WOSggH[k]->GetBinContent(nn)<0) h51_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h51_WSSggH[k]->GetBinContent(nn)<0) h51_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h52_OSggH[k]->GetBinContent(nn)<0) h52_OSggH[k]->SetBinContent(nn,0.00001);
           if (h52_SSggH[k]->GetBinContent(nn)<0) h52_SSggH[k]->SetBinContent(nn,0.00001);
           if (h52_QCDggH[k]->GetBinContent(nn)<0) h52_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h52_WOSggH[k]->GetBinContent(nn)<0) h52_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h52_WSSggH[k]->GetBinContent(nn)<0) h52_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h53_OSggH[k]->GetBinContent(nn)<0) h53_OSggH[k]->SetBinContent(nn,0.00001);
           if (h53_SSggH[k]->GetBinContent(nn)<0) h53_SSggH[k]->SetBinContent(nn,0.00001);
           if (h53_QCDggH[k]->GetBinContent(nn)<0) h53_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h53_WOSggH[k]->GetBinContent(nn)<0) h53_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h53_WSSggH[k]->GetBinContent(nn)<0) h53_WSSggH[k]->SetBinContent(nn,0.00001);

           if (h60_OSggH[k]->GetBinContent(nn)<0) h60_OSggH[k]->SetBinContent(nn,0.00001);
           if (h60_SSggH[k]->GetBinContent(nn)<0) h60_SSggH[k]->SetBinContent(nn,0.00001);
           if (h60_QCDggH[k]->GetBinContent(nn)<0) h60_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h60_WOSggH[k]->GetBinContent(nn)<0) h60_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h60_WSSggH[k]->GetBinContent(nn)<0) h60_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h61_OSggH[k]->GetBinContent(nn)<0) h61_OSggH[k]->SetBinContent(nn,0.00001);
           if (h61_SSggH[k]->GetBinContent(nn)<0) h61_SSggH[k]->SetBinContent(nn,0.00001);
           if (h61_QCDggH[k]->GetBinContent(nn)<0) h61_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h61_WOSggH[k]->GetBinContent(nn)<0) h61_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h61_WSSggH[k]->GetBinContent(nn)<0) h61_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h62_OSggH[k]->GetBinContent(nn)<0) h62_OSggH[k]->SetBinContent(nn,0.00001);
           if (h62_SSggH[k]->GetBinContent(nn)<0) h62_SSggH[k]->SetBinContent(nn,0.00001);
           if (h62_QCDggH[k]->GetBinContent(nn)<0) h62_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h62_WOSggH[k]->GetBinContent(nn)<0) h62_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h62_WSSggH[k]->GetBinContent(nn)<0) h62_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h63_OSggH[k]->GetBinContent(nn)<0) h63_OSggH[k]->SetBinContent(nn,0.00001);
           if (h63_SSggH[k]->GetBinContent(nn)<0) h63_SSggH[k]->SetBinContent(nn,0.00001);
           if (h63_QCDggH[k]->GetBinContent(nn)<0) h63_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h63_WOSggH[k]->GetBinContent(nn)<0) h63_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h63_WSSggH[k]->GetBinContent(nn)<0) h63_WSSggH[k]->SetBinContent(nn,0.00001);

           if (h70_OSggH[k]->GetBinContent(nn)<0) h70_OSggH[k]->SetBinContent(nn,0.00001);
           if (h70_SSggH[k]->GetBinContent(nn)<0) h70_SSggH[k]->SetBinContent(nn,0.00001);
           if (h70_QCDggH[k]->GetBinContent(nn)<0) h70_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h70_WOSggH[k]->GetBinContent(nn)<0) h70_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h70_WSSggH[k]->GetBinContent(nn)<0) h70_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h71_OSggH[k]->GetBinContent(nn)<0) h71_OSggH[k]->SetBinContent(nn,0.00001);
           if (h71_SSggH[k]->GetBinContent(nn)<0) h71_SSggH[k]->SetBinContent(nn,0.00001);
           if (h71_QCDggH[k]->GetBinContent(nn)<0) h71_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h71_WOSggH[k]->GetBinContent(nn)<0) h71_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h71_WSSggH[k]->GetBinContent(nn)<0) h71_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h72_OSggH[k]->GetBinContent(nn)<0) h72_OSggH[k]->SetBinContent(nn,0.00001);
           if (h72_SSggH[k]->GetBinContent(nn)<0) h72_SSggH[k]->SetBinContent(nn,0.00001);
           if (h72_QCDggH[k]->GetBinContent(nn)<0) h72_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h72_WOSggH[k]->GetBinContent(nn)<0) h72_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h72_WSSggH[k]->GetBinContent(nn)<0) h72_WSSggH[k]->SetBinContent(nn,0.00001);
           if (h73_OSggH[k]->GetBinContent(nn)<0) h73_OSggH[k]->SetBinContent(nn,0.00001);
           if (h73_SSggH[k]->GetBinContent(nn)<0) h73_SSggH[k]->SetBinContent(nn,0.00001);
           if (h73_QCDggH[k]->GetBinContent(nn)<0) h73_QCDggH[k]->SetBinContent(nn,0.00001);
           if (h73_WOSggH[k]->GetBinContent(nn)<0) h73_WOSggH[k]->SetBinContent(nn,0.00001);
           if (h73_WSSggH[k]->GetBinContent(nn)<0) h73_WSSggH[k]->SetBinContent(nn,0.00001);
	   

       }

	const char * namee ; namee = postfix;
	char name_[100];
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


//0jet
        OS0jet->cd();
        h0_OS[k]->SetName(name.c_str()+postfix);
        h0_WOS[k]->SetName(name.c_str()+postfix);
        h0_OS[k]->Write();
	


        SS0jet->cd();
        h0_SS[k]->SetName(name.c_str()+postfix);
        h0_SS[k]->Write();
        h0_WSS[k]->SetName(name.c_str()+postfix);
        h0_WSS[k]->Write();

        QCD0jet->cd();
        h0_QCD[k]->SetName(name.c_str()+postfix);
        h0_QCD[k]->Write();



        OScontrol->cd();
        h1D_OS[k]->SetName(name.c_str()+postfix);
        h1D_WOS[k]->SetName(name.c_str()+postfix);
		  
       if (sample=="W"){
         h1D_WOS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_0jet_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDCP_0jet_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_0jet_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_0jet_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_0jet_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_0jet_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_0jet_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_0jet_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_0jet_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_0jet_WOS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_0jet_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_0jet_WOS[k]->SetName(name_);

        hmelaDCP_0jet_WOS[k]->Write();
        hmelaDCPggH_0jet_WOS[k]->Write();
        hmelaD0minus_0jet_WOS[k]->Write();
        hmelaD0minusggH_0jet_WOS[k]->Write();
        hmelaDPhijj_0jet_WOS[k]->Write();
        hmelaDPhiUnsignedjj_0jet_WOS[k]->Write();


	sprintf(name_,"%s_%s%s",h1D_jpt1_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_VBF_WOS[k]->GetName(),name.c_str(),namee);
	h1D_met_VBF_WOS[k]->SetName(name_);

	h1D_jpt1_VBF_WOS[k]->Write();
	h1D_jpt2_VBF_WOS[k]->Write();
	h1D_jeta1_VBF_WOS[k]->Write();
	h1D_jeta2_VBF_WOS[k]->Write();
	h1D_phi1_VBF_WOS[k]->Write();
	h1D_phi2_VBF_WOS[k]->Write();
	h1D_mjj_VBF_WOS[k]->Write();
	h1D_met_VBF_WOS[k]->Write();


	sprintf(name_,"%s_%s%s",hmelaDCP_VBF_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDCP_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_VBF_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_VBF_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_VBF_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_VBF_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_VBF_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_VBF_WOS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_VBF_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_VBF_WOS[k]->SetName(name_);

	   hmelaDCP_VBF_WOS[k]->Write();
	   hmelaDCPggH_VBF_WOS[k]->Write();
	   hmelaD0minus_VBF_WOS[k]->Write();
	   hmelaD0minusggH_VBF_WOS[k]->Write();
	   hmelaDPhijj_VBF_WOS[k]->Write();
	   hmelaDPhiUnsignedjj_VBF_WOS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_WOS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_WOS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_WOS[k]->SetName(name_);

	hmelaDCP_boosted_WOS[k]->Write();
	hmelaDCPggH_boosted_WOS[k]->Write();
	hmelaD0minus_boosted_WOS[k]->Write();
	hmelaD0minusggH_boosted_WOS[k]->Write();
	hmelaDPhijj_boosted_WOS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_WOS[k]->Write();


       }
       else{
         h1D_OS[k]->Write();


	sprintf(name_,"%s_%s%s",hmelaDCP_0jet_OS[k]->GetName(),name.c_str(),namee);
        hmelaDCP_0jet_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_0jet_OS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_0jet_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_0jet_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_0jet_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_0jet_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_0jet_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_0jet_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_0jet_OS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_0jet_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_0jet_OS[k]->SetName(name_);

        hmelaDCP_0jet_OS[k]->Write();
        hmelaDCPggH_0jet_OS[k]->Write();
        hmelaD0minus_0jet_OS[k]->Write();
        hmelaD0minusggH_0jet_OS[k]->Write();
        hmelaDPhijj_0jet_OS[k]->Write();
        hmelaDPhiUnsignedjj_0jet_OS[k]->Write();


	sprintf(name_,"%s_%s%s",h1D_jpt1_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_VBF_OS[k]->GetName(),name.c_str(),namee);
	h1D_met_VBF_OS[k]->SetName(name_);

	h1D_jpt1_VBF_OS[k]->Write();
	h1D_jpt2_VBF_OS[k]->Write();
	h1D_jeta1_VBF_OS[k]->Write();
	h1D_jeta2_VBF_OS[k]->Write();
	h1D_phi1_VBF_OS[k]->Write();
	h1D_phi2_VBF_OS[k]->Write();
	h1D_mjj_VBF_OS[k]->Write();
	h1D_met_VBF_OS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_VBF_OS[k]->GetName(),name.c_str(),namee);
        hmelaDCP_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_VBF_OS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_VBF_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_VBF_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_VBF_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_VBF_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_VBF_OS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_VBF_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_VBF_OS[k]->SetName(name_);



	   hmelaDCP_VBF_OS[k]->Write();
	   hmelaDCPggH_VBF_OS[k]->Write();
	   hmelaD0minus_VBF_OS[k]->Write();
	   hmelaD0minusggH_VBF_OS[k]->Write();
	   hmelaDPhijj_VBF_OS[k]->Write();
	   hmelaDPhiUnsignedjj_VBF_OS[k]->Write();


	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_OS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_OS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_OS[k]->SetName(name_);


	hmelaDCP_boosted_OS[k]->Write();
	hmelaDCPggH_boosted_OS[k]->Write();
	hmelaD0minus_boosted_OS[k]->Write();
	hmelaD0minusggH_boosted_OS[k]->Write();
	hmelaDPhijj_boosted_OS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_OS[k]->Write();

       }


       SScontrol->cd();
       h1D_SS[k]->SetName(name.c_str()+postfix);
       h1D_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W"){
         h1D_WSS[k]->Write();

	sprintf(name_,"%s_%s%s",h1D_jpt1_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_VBF_WSS[k]->GetName(),name.c_str(),namee);
	h1D_met_VBF_WSS[k]->SetName(name_);

	h1D_jpt1_VBF_WSS[k]->Write();
	h1D_jpt2_VBF_WSS[k]->Write();
	h1D_jeta1_VBF_WSS[k]->Write();
	h1D_jeta2_VBF_WSS[k]->Write();
	h1D_phi1_VBF_WSS[k]->Write();
	h1D_phi2_VBF_WSS[k]->Write();
	h1D_mjj_VBF_WSS[k]->Write();
	h1D_met_VBF_WSS[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_VBF_WSS[k]->GetName(),name.c_str(),namee);
        hmelaDCP_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_VBF_WSS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_VBF_WSS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_VBF_WSS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_VBF_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_VBF_WSS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_VBF_WSS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_VBF_WSS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_VBF_WSS[k]->SetName(name_);

	   hmelaDCP_VBF_WSS[k]->Write();
	   hmelaDCPggH_VBF_WSS[k]->Write();
	   hmelaD0minus_VBF_WSS[k]->Write();
	   hmelaD0minusggH_VBF_WSS[k]->Write();
	   hmelaDPhijj_VBF_WSS[k]->Write();
	   hmelaDPhiUnsignedjj_VBF_WSS[k]->Write();

       }
       else{
         h1D_SS[k]->Write();
	sprintf(name_,"%s_%s%s",h1D_jpt1_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_phi1_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_phi2_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_mjj_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_VBF_SS[k]->GetName(),name.c_str(),namee);
	h1D_met_VBF_SS[k]->SetName(name_);

	h1D_jpt1_VBF_SS[k]->Write();
	h1D_jpt2_VBF_SS[k]->Write();
	h1D_jeta1_VBF_SS[k]->Write();
	h1D_jeta2_VBF_SS[k]->Write();
	h1D_phi1_VBF_SS[k]->Write();
	h1D_phi2_VBF_SS[k]->Write();
	h1D_mjj_VBF_SS[k]->Write();
	h1D_met_VBF_SS[k]->Write();


	sprintf(name_,"%s_%s%s",hmelaDCP_VBF_SS[k]->GetName(),name.c_str(),namee);
        hmelaDCP_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_VBF_SS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_VBF_SS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_VBF_SS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_VBF_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_VBF_SS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_VBF_SS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_VBF_SS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_VBF_SS[k]->SetName(name_);

	   hmelaDCP_VBF_SS[k]->Write();
	   hmelaDCPggH_VBF_SS[k]->Write();
	   hmelaD0minus_VBF_SS[k]->Write();
	   hmelaD0minusggH_VBF_SS[k]->Write();
	   hmelaDPhijj_VBF_SS[k]->Write();
	   hmelaDPhiUnsignedjj_VBF_SS[k]->Write();


       }


       QCDcontrol->cd();
       h1D_QCD[k]->SetName(name.c_str()+postfix);
       h1D_QCD[k]->Write();

	sprintf(name_,"%s_%s%s",h1D_jpt1_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jpt1_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta1_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jeta1_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi1_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_phi1_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jpt2_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jpt2_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_jeta2_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_jeta2_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_phi2_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_phi2_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_mjj_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_mjj_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",h1D_met_VBF_QCD[k]->GetName(),name.c_str(),namee);
	h1D_met_VBF_QCD[k]->SetName(name_);

	h1D_jpt1_VBF_QCD[k]->Write();
	h1D_jpt2_VBF_QCD[k]->Write();
	h1D_jeta1_VBF_QCD[k]->Write();
	h1D_jeta2_VBF_QCD[k]->Write();
	h1D_phi1_VBF_QCD[k]->Write();
	h1D_phi2_VBF_QCD[k]->Write();
	h1D_mjj_VBF_QCD[k]->Write();
	h1D_met_VBF_QCD[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_VBF_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDCP_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_VBF_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_VBF_QCD[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_VBF_QCD[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_VBF_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_VBF_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_VBF_QCD[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_VBF_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_VBF_QCD[k]->SetName(name_);

	   hmelaDCP_VBF_QCD[k]->Write();
	   hmelaDCPggH_VBF_QCD[k]->Write();
	   hmelaD0minus_VBF_QCD[k]->Write();
	   hmelaD0minusggH_VBF_QCD[k]->Write();
	   hmelaDPhijj_VBF_QCD[k]->Write();
	   hmelaDPhiUnsignedjj_VBF_QCD[k]->Write();

//boosted


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

	}
        else{
           h1_SS[k]->Write();

	}

        QCD1jet->cd();
        h1_QCD[k]->SetName(name.c_str()+postfix);
        h1_QCD[k]->Write();



        OS2jet->cd();
        h2_OS[k]->SetName(name.c_str()+postfix);
        h2_WOS[k]->SetName(name.c_str()+postfix);
	

        if (sample=="W"){
           h2_WOS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_WOS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_WOS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_WOS[k]->SetName(name_);

	hmelaDCP_boosted_WOS[k]->Write();
	hmelaDCPggH_boosted_WOS[k]->Write();
	hmelaD0minus_boosted_WOS[k]->Write();
	hmelaD0minusggH_boosted_WOS[k]->Write();
	hmelaDPhijj_boosted_WOS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_WOS[k]->Write();


	}
        else 
		{
           h2_OS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_OS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_OS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_OS[k]->SetName(name_);


	hmelaDCP_boosted_OS[k]->Write();
	hmelaDCPggH_boosted_OS[k]->Write();
	hmelaD0minus_boosted_OS[k]->Write();
	hmelaD0minusggH_boosted_OS[k]->Write();
	hmelaDPhijj_boosted_OS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_OS[k]->Write();
		}



	
        SS2jet->cd();
        h2_SS[k]->SetName(name.c_str()+postfix);
        h2_WSS[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h2_WSS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_WSS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_WSS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_WSS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_WSS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_WSS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_WSS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_WSS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_WSS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_WSS[k]->SetName(name_);

	hmelaDCP_boosted_WSS[k]->Write();
	hmelaDCPggH_boosted_WSS[k]->Write();
	hmelaD0minus_boosted_WSS[k]->Write();
	hmelaD0minusggH_boosted_WSS[k]->Write();
	hmelaDPhijj_boosted_WSS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_WSS[k]->Write();

	}
        else{
           h2_SS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_SS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_SS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_SS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_SS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_SS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_SS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_SS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_SS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_SS[k]->SetName(name_);

	hmelaDCP_boosted_SS[k]->Write();
	hmelaDCPggH_boosted_SS[k]->Write();
	hmelaD0minus_boosted_SS[k]->Write();
	hmelaD0minusggH_boosted_SS[k]->Write();
	hmelaDPhijj_boosted_SS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_SS[k]->Write();

	}

        QCD2jet->cd();
        h2_QCD[k]->SetName(name.c_str()+postfix);
        h2_QCD[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_QCD[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_QCD[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_QCD[k]->SetName(name_);
	//////////////////////






////ggH
       OS20jet->cd();
       h20_OS[k]->SetName(name.c_str()+postfix);
       h20_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h20_WOS[k]->Write();
       else
          h20_OS[k]->Write();
///////////
       SS20jet->cd();
       h20_SS[k]->SetName(name.c_str()+postfix);
       h20_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W"){
          h20_WSS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_WOS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_WOS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_WOS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_WOS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_WOS[k]->SetName(name_);

	hmelaDCP_boosted_WOS[k]->Write();
	hmelaDCPggH_boosted_WOS[k]->Write();
	hmelaD0minus_boosted_WOS[k]->Write();
	hmelaD0minusggH_boosted_WOS[k]->Write();
	hmelaDPhijj_boosted_WOS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_WOS[k]->Write();

       }

       else{
          h20_SS[k]->Write();
	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_OS[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_OS[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_OS[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_OS[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_OS[k]->SetName(name_);


	hmelaDCP_boosted_OS[k]->Write();
	hmelaDCPggH_boosted_OS[k]->Write();
	hmelaD0minus_boosted_OS[k]->Write();
	hmelaD0minusggH_boosted_OS[k]->Write();
	hmelaDPhijj_boosted_OS[k]->Write();
	hmelaDPhiUnsignedjj_boosted_OS[k]->Write();

       }

       

       QCD20jet->cd();
       h20_QCD[k]->SetName(name.c_str()+postfix);
       h20_QCD[k]->Write();

	sprintf(name_,"%s_%s%s",hmelaDCP_boosted_QCD[k]->GetName(),name.c_str(),namee);
	hmelaDCP_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDCPggH_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDCPggH_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minus_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaD0minus_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaD0minusggH_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaD0minusggH_boosted_QCD[k]->SetName(name_);
	sprintf(name_,"%s_%s%s",hmelaDPhijj_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDPhijj_boosted_QCD[k]->SetName(name_); 
	sprintf(name_,"%s_%s%s",hmelaDPhiUnsignedjj_boosted_QCD[k]->GetName(),name.c_str(),namee);
        hmelaDPhiUnsignedjj_boosted_QCD[k]->SetName(name_);
       
       ////////////////////

      OS30jet->cd();
       h30_OS[k]->SetName(name.c_str()+postfix);
       h30_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h30_WOS[k]->Write();
       else
          h30_OS[k]->Write();

       SS30jet->cd();
       h30_SS[k]->SetName(name.c_str()+postfix);
       h30_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h30_WSS[k]->Write();
       else
          h30_SS[k]->Write();

       QCD30jet->cd();
       h30_QCD[k]->SetName(name.c_str()+postfix);
       h30_QCD[k]->Write();

       
       
       /////////////////
      OS40jet->cd();
       h40_OS[k]->SetName(name.c_str()+postfix);
       h40_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h40_WOS[k]->Write();
       else
          h40_OS[k]->Write();

       SS40jet->cd();
       h40_SS[k]->SetName(name.c_str()+postfix);
       h40_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h40_WSS[k]->Write();
       else
          h40_SS[k]->Write();

       QCD40jet->cd();
       h40_QCD[k]->SetName(name.c_str()+postfix);
       h40_QCD[k]->Write();

      OS50jet->cd();
       h50_OS[k]->SetName(name.c_str()+postfix);
       h50_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h50_WOS[k]->Write();
       else
          h50_OS[k]->Write();

       SS50jet->cd();
       h50_SS[k]->SetName(name.c_str()+postfix);
       h50_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h50_WSS[k]->Write();
       else
          h50_SS[k]->Write();

       QCD50jet->cd();
       h50_QCD[k]->SetName(name.c_str()+postfix);
       h50_QCD[k]->Write();

      OS60jet->cd();
       h60_OS[k]->SetName(name.c_str()+postfix);
       h60_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h60_WOS[k]->Write();
       else
          h60_OS[k]->Write();

       SS60jet->cd();
       h60_SS[k]->SetName(name.c_str()+postfix);
       h60_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h60_WSS[k]->Write();
       else
          h60_SS[k]->Write();

       QCD60jet->cd();
       h60_QCD[k]->SetName(name.c_str()+postfix);
       h60_QCD[k]->Write();

      OS70jet->cd();
       h70_OS[k]->SetName(name.c_str()+postfix);
       h70_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h70_WOS[k]->Write();
       else
          h70_OS[k]->Write();

       SS70jet->cd();
       h70_SS[k]->SetName(name.c_str()+postfix);
       h70_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h70_WSS[k]->Write();
       else
          h70_SS[k]->Write();

       QCD70jet->cd();
       h70_QCD[k]->SetName(name.c_str()+postfix);
       h70_QCD[k]->Write();

//////////////
       OS21jet->cd();
       h21_OS[k]->SetName(name.c_str()+postfix);
       h21_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h21_WOS[k]->Write();
       else
          h21_OS[k]->Write();

       SS21jet->cd();
       h21_SS[k]->SetName(name.c_str()+postfix);
       h21_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h21_WSS[k]->Write();
       else
          h21_SS[k]->Write();

       QCD21jet->cd();
       h21_QCD[k]->SetName(name.c_str()+postfix);
       h21_QCD[k]->Write();

       OS31jet->cd();
       h31_OS[k]->SetName(name.c_str()+postfix);
       h31_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h31_WOS[k]->Write();
       else
          h31_OS[k]->Write();

       SS31jet->cd();
       h31_SS[k]->SetName(name.c_str()+postfix);
       h31_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h31_WSS[k]->Write();
       else
          h31_SS[k]->Write();

       QCD31jet->cd();
       h31_QCD[k]->SetName(name.c_str()+postfix);
       h31_QCD[k]->Write();

       OS41jet->cd();
       h41_OS[k]->SetName(name.c_str()+postfix);
       h41_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h41_WOS[k]->Write();
       else
          h41_OS[k]->Write();

       SS41jet->cd();
       h41_SS[k]->SetName(name.c_str()+postfix);
       h41_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h41_WSS[k]->Write();
       else
          h41_SS[k]->Write();

       QCD41jet->cd();
       h41_QCD[k]->SetName(name.c_str()+postfix);
       h41_QCD[k]->Write();

       OS51jet->cd();
       h51_OS[k]->SetName(name.c_str()+postfix);
       h51_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h51_WOS[k]->Write();
       else
          h51_OS[k]->Write();

       SS51jet->cd();
       h51_SS[k]->SetName(name.c_str()+postfix);
       h51_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h51_WSS[k]->Write();
       else
          h51_SS[k]->Write();

       QCD51jet->cd();
       h51_QCD[k]->SetName(name.c_str()+postfix);
       h51_QCD[k]->Write();

       OS61jet->cd();
       h61_OS[k]->SetName(name.c_str()+postfix);
       h61_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h61_WOS[k]->Write();
       else
          h61_OS[k]->Write();

       SS61jet->cd();
       h61_SS[k]->SetName(name.c_str()+postfix);
       h61_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h61_WSS[k]->Write();
       else
          h61_SS[k]->Write();

       QCD61jet->cd();
       h61_QCD[k]->SetName(name.c_str()+postfix);
       h61_QCD[k]->Write();

       OS71jet->cd();
       h71_OS[k]->SetName(name.c_str()+postfix);
       h71_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h71_WOS[k]->Write();
       else
          h71_OS[k]->Write();

       SS71jet->cd();
       h71_SS[k]->SetName(name.c_str()+postfix);
       h71_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h71_WSS[k]->Write();
       else
          h71_SS[k]->Write();

       QCD71jet->cd();
       h71_QCD[k]->SetName(name.c_str()+postfix);
       h71_QCD[k]->Write();


       OS22jet->cd();
       h22_OS[k]->SetName(name.c_str()+postfix);
       h22_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h22_WOS[k]->Write();
       else
          h22_OS[k]->Write();

       SS22jet->cd();
       h22_SS[k]->SetName(name.c_str()+postfix);
       h22_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h22_WSS[k]->Write();
       else
          h22_SS[k]->Write();

       QCD22jet->cd();
       h22_QCD[k]->SetName(name.c_str()+postfix);
       h22_QCD[k]->Write();

       OS32jet->cd();
       h32_OS[k]->SetName(name.c_str()+postfix);
       h32_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h32_WOS[k]->Write();
       else
          h32_OS[k]->Write();

       SS32jet->cd();
       h32_SS[k]->SetName(name.c_str()+postfix);
       h32_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h32_WSS[k]->Write();
       else
          h32_SS[k]->Write();

       QCD32jet->cd();
       h32_QCD[k]->SetName(name.c_str()+postfix);
       h32_QCD[k]->Write();

       OS42jet->cd();
       h42_OS[k]->SetName(name.c_str()+postfix);
       h42_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h42_WOS[k]->Write();
       else
          h42_OS[k]->Write();

       SS42jet->cd();
       h42_SS[k]->SetName(name.c_str()+postfix);
       h42_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h42_WSS[k]->Write();
       else
          h42_SS[k]->Write();

       QCD42jet->cd();
       h42_QCD[k]->SetName(name.c_str()+postfix);
       h42_QCD[k]->Write();

       OS52jet->cd();
       h52_OS[k]->SetName(name.c_str()+postfix);
       h52_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h52_WOS[k]->Write();
       else
          h52_OS[k]->Write();

       SS52jet->cd();
       h52_SS[k]->SetName(name.c_str()+postfix);
       h52_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h52_WSS[k]->Write();
       else
          h52_SS[k]->Write();

       QCD52jet->cd();
       h52_QCD[k]->SetName(name.c_str()+postfix);
       h52_QCD[k]->Write();

       OS62jet->cd();
       h62_OS[k]->SetName(name.c_str()+postfix);
       h62_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h62_WOS[k]->Write();
       else
          h62_OS[k]->Write();

       SS62jet->cd();
       h62_SS[k]->SetName(name.c_str()+postfix);
       h62_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h62_WSS[k]->Write();
       else
          h62_SS[k]->Write();

       QCD62jet->cd();
       h62_QCD[k]->SetName(name.c_str()+postfix);
       h62_QCD[k]->Write();

       OS72jet->cd();
       h72_OS[k]->SetName(name.c_str()+postfix);
       h72_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h72_WOS[k]->Write();
       else
          h72_OS[k]->Write();

       SS72jet->cd();
       h72_SS[k]->SetName(name.c_str()+postfix);
       h72_WSS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h72_WSS[k]->Write();
       else
          h72_SS[k]->Write();

       QCD72jet->cd();
       h72_QCD[k]->SetName(name.c_str()+postfix);
       h72_QCD[k]->Write();


       OS23jet->cd();
       h23_OS[k]->SetName(name.c_str()+postfix);
       h23_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h23_WOS[k]->Write();
       else
          h23_OS[k]->Write();

       SS23jet->cd();
       h23_SS[k]->SetName(name.c_str()+postfix);
       h23_WSS[k]->SetName(name.c_str()+postfix);
       h23_SS[k]->Write();

       QCD23jet->cd();
       h23_QCD[k]->SetName(name.c_str()+postfix);
       h23_QCD[k]->Write();

       OS33jet->cd();
       h33_OS[k]->SetName(name.c_str()+postfix);
       h33_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h33_WOS[k]->Write();
       else
          h33_OS[k]->Write();

       SS33jet->cd();
       h33_SS[k]->SetName(name.c_str()+postfix);
       h33_WSS[k]->SetName(name.c_str()+postfix);
       h33_SS[k]->Write();

       QCD33jet->cd();
       h33_QCD[k]->SetName(name.c_str()+postfix);
       h33_QCD[k]->Write();

       OS43jet->cd();
       h43_OS[k]->SetName(name.c_str()+postfix);
       h43_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h43_WOS[k]->Write();
       else
          h43_OS[k]->Write();

       SS43jet->cd();
       h43_SS[k]->SetName(name.c_str()+postfix);
       h43_WSS[k]->SetName(name.c_str()+postfix);
       h43_SS[k]->Write();

       QCD43jet->cd();
       h43_QCD[k]->SetName(name.c_str()+postfix);
       h43_QCD[k]->Write();

       OS53jet->cd();
       h53_OS[k]->SetName(name.c_str()+postfix);
       h53_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h53_WOS[k]->Write();
       else
          h53_OS[k]->Write();

       SS53jet->cd();
       h53_SS[k]->SetName(name.c_str()+postfix);
       h53_WSS[k]->SetName(name.c_str()+postfix);
       h53_SS[k]->Write();

       QCD53jet->cd();
       h53_QCD[k]->SetName(name.c_str()+postfix);
       h53_QCD[k]->Write();

       OS63jet->cd();
       h63_OS[k]->SetName(name.c_str()+postfix);
       h63_WOS[k]->SetName(name.c_str()+postfix);
       if (sample=="W")
          h63_WOS[k]->Write();
       else
          h63_OS[k]->Write();

       SS63jet->cd();
       h63_SS[k]->SetName(name.c_str()+postfix);
       h63_WSS[k]->SetName(name.c_str()+postfix);
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
       h73_SS[k]->Write();

       QCD73jet->cd();
       h73_QCD[k]->SetName(name.c_str()+postfix);
       h73_QCD[k]->Write();

       ///////////////////////////// ggH
	OS20jetggH->cd();
        h20_OSggH[k]->SetName(name.c_str()+postfix);
        h20_WOSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W"){
           h20_WOSggH[k]->Write();
	}
        else{
           h20_OSggH[k]->Write();
	}


        SS20jetggH->cd();
        h20_SSggH[k]->SetName(name.c_str()+postfix);
        h20_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h20_WSSggH[k]->Write();
        else
           h20_SSggH[k]->Write();
        
	QCD20jetggH->cd();
        h20_QCDggH[k]->SetName(name.c_str()+postfix);
        h20_QCDggH[k]->Write();


	OS21jetggH->cd();
        h21_OSggH[k]->SetName(name.c_str()+postfix);
        h21_WOSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W"){
           h21_WOSggH[k]->Write();
	}
        else{
           h21_OSggH[k]->Write();
	}


        SS21jetggH->cd();
        h21_SSggH[k]->SetName(name.c_str()+postfix);
        h21_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h21_WSSggH[k]->Write();
        else
           h21_SSggH[k]->Write();
        
	QCD21jetggH->cd();
        h21_QCDggH[k]->SetName(name.c_str()+postfix);
        h21_QCDggH[k]->Write();


	OS22jetggH->cd();
        h22_OSggH[k]->SetName(name.c_str()+postfix);
        h22_WOSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W"){
           h22_WOSggH[k]->Write();
	}
        else{
           h22_OSggH[k]->Write();
	}


        SS22jetggH->cd();
        h22_SSggH[k]->SetName(name.c_str()+postfix);
        h22_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h22_WSSggH[k]->Write();
        else
           h22_SSggH[k]->Write();
        
	QCD22jetggH->cd();
        h22_QCDggH[k]->SetName(name.c_str()+postfix);
        h22_QCDggH[k]->Write();


	OS23jetggH->cd();
        h23_OSggH[k]->SetName(name.c_str()+postfix);
        h23_WOSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W"){
           h23_WOSggH[k]->Write();
	}
        else{
           h23_OSggH[k]->Write();
	}


        SS23jetggH->cd();
        h23_SSggH[k]->SetName(name.c_str()+postfix);
        h23_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h23_WSSggH[k]->Write();
        else
           h23_SSggH[k]->Write();
        
	QCD23jetggH->cd();
        h23_QCDggH[k]->SetName(name.c_str()+postfix);
        h23_QCDggH[k]->Write();

////OS33,34,35,32



        OS30jetggH->cd();
        h30_OSggH[k]->SetName(name.c_str()+postfix);
        h30_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h30_WOSggH[k]->Write();
	}
        else{
           h30_OSggH[k]->Write();
	}


        SS30jetggH->cd();
        h30_SSggH[k]->SetName(name.c_str()+postfix);
        h30_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h30_WSSggH[k]->Write();
        else
           h30_SSggH[k]->Write();

        QCD30jetggH->cd();
        h30_QCDggH[k]->SetName(name.c_str()+postfix);
        h30_QCDggH[k]->Write();




        OS31jetggH->cd();
        h31_OSggH[k]->SetName(name.c_str()+postfix);
        h31_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h31_WOSggH[k]->Write();
	}
        else{
           h31_OSggH[k]->Write();
	}


        SS31jetggH->cd();
        h31_SSggH[k]->SetName(name.c_str()+postfix);
        h31_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h31_WSSggH[k]->Write();
        else
           h31_SSggH[k]->Write();

        QCD31jetggH->cd();
        h31_QCDggH[k]->SetName(name.c_str()+postfix);
        h31_QCDggH[k]->Write();


        OS32jetggH->cd();
        h32_OSggH[k]->SetName(name.c_str()+postfix);
        h32_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h32_WOSggH[k]->Write();
	}
        else{
           h32_OSggH[k]->Write();
	}


        SS32jetggH->cd();
        h32_SSggH[k]->SetName(name.c_str()+postfix);
        h32_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h32_WSSggH[k]->Write();
        else
           h32_SSggH[k]->Write();

        QCD32jetggH->cd();
        h32_QCDggH[k]->SetName(name.c_str()+postfix);
        h32_QCDggH[k]->Write();



        OS33jetggH->cd();
        h33_OSggH[k]->SetName(name.c_str()+postfix);
        h33_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h33_WOSggH[k]->Write();
	}
        else{
           h33_OSggH[k]->Write();
	}


        SS33jetggH->cd();
        h33_SSggH[k]->SetName(name.c_str()+postfix);
        h33_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h33_WSSggH[k]->Write();
        else
           h33_SSggH[k]->Write();

        QCD33jetggH->cd();
        h33_QCDggH[k]->SetName(name.c_str()+postfix);
        h33_QCDggH[k]->Write();



///////////////


        OS40jetggH->cd();
        h40_OSggH[k]->SetName(name.c_str()+postfix);
        h40_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h40_WOSggH[k]->Write();
	}
        else{
           h40_OSggH[k]->Write();
	}


        SS40jetggH->cd();
        h40_SSggH[k]->SetName(name.c_str()+postfix);
        h40_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h40_WSSggH[k]->Write();
        else
           h40_SSggH[k]->Write();

        QCD40jetggH->cd();
        h40_QCDggH[k]->SetName(name.c_str()+postfix);
        h40_QCDggH[k]->Write();



        OS33jetggH->cd();
        h33_OSggH[k]->SetName(name.c_str()+postfix);
        h33_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h33_WOSggH[k]->Write();
	}
        else{
           h33_OSggH[k]->Write();
	}


        SS33jetggH->cd();
        h33_SSggH[k]->SetName(name.c_str()+postfix);
        h33_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h33_WSSggH[k]->Write();
        else
           h33_SSggH[k]->Write();

        QCD33jetggH->cd();
        h33_QCDggH[k]->SetName(name.c_str()+postfix);
        h33_QCDggH[k]->Write();



        OS41jetggH->cd();
        h41_OSggH[k]->SetName(name.c_str()+postfix);
        h41_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h41_WOSggH[k]->Write();
	}
        else{
           h41_OSggH[k]->Write();
	}


        SS41jetggH->cd();
        h41_SSggH[k]->SetName(name.c_str()+postfix);
        h41_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h41_WSSggH[k]->Write();
        else
           h41_SSggH[k]->Write();

        QCD41jetggH->cd();
        h41_QCDggH[k]->SetName(name.c_str()+postfix);
        h41_QCDggH[k]->Write();



        OS42jetggH->cd();
        h42_OSggH[k]->SetName(name.c_str()+postfix);
        h42_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h42_WOSggH[k]->Write();
	}
        else{
           h42_OSggH[k]->Write();
	}


        SS42jetggH->cd();
        h42_SSggH[k]->SetName(name.c_str()+postfix);
        h42_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h42_WSSggH[k]->Write();
        else
           h42_SSggH[k]->Write();

        QCD42jetggH->cd();
        h42_QCDggH[k]->SetName(name.c_str()+postfix);
        h42_QCDggH[k]->Write();


        OS43jetggH->cd();
        h43_OSggH[k]->SetName(name.c_str()+postfix);
        h43_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h43_WOSggH[k]->Write();
	}
        else{
           h43_OSggH[k]->Write();
	}


        SS43jetggH->cd();
        h43_SSggH[k]->SetName(name.c_str()+postfix);
        h43_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h43_WSSggH[k]->Write();
        else
           h43_SSggH[k]->Write();

        QCD43jetggH->cd();
        h43_QCDggH[k]->SetName(name.c_str()+postfix);
        h43_QCDggH[k]->Write();


////////////////////////



 
	
	OS50jetggH->cd();
        h50_OSggH[k]->SetName(name.c_str()+postfix);
        h50_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h50_WOSggH[k]->Write();
	}
        else{
           h50_OSggH[k]->Write();
	}


        SS50jetggH->cd();
        h50_SSggH[k]->SetName(name.c_str()+postfix);
        h50_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h50_WSSggH[k]->Write();
        else
           h50_SSggH[k]->Write();

        QCD50jetggH->cd();
        h50_QCDggH[k]->SetName(name.c_str()+postfix);
        h50_QCDggH[k]->Write();



        OS33jetggH->cd();
        h33_OSggH[k]->SetName(name.c_str()+postfix);
        h33_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h33_WOSggH[k]->Write();
	}
        else{
           h33_OSggH[k]->Write();
	}


        SS33jetggH->cd();
        h33_SSggH[k]->SetName(name.c_str()+postfix);
        h33_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h33_WSSggH[k]->Write();
        else
           h33_SSggH[k]->Write();

        QCD33jetggH->cd();
        h33_QCDggH[k]->SetName(name.c_str()+postfix);
        h33_QCDggH[k]->Write();



        OS51jetggH->cd();
        h51_OSggH[k]->SetName(name.c_str()+postfix);
        h51_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h51_WOSggH[k]->Write();
	}
        else{
           h51_OSggH[k]->Write();
	}


        SS51jetggH->cd();
        h51_SSggH[k]->SetName(name.c_str()+postfix);
        h51_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h51_WSSggH[k]->Write();
        else
           h51_SSggH[k]->Write();

        QCD51jetggH->cd();
        h51_QCDggH[k]->SetName(name.c_str()+postfix);
        h51_QCDggH[k]->Write();



        OS52jetggH->cd();
        h52_OSggH[k]->SetName(name.c_str()+postfix);
        h52_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h52_WOSggH[k]->Write();
	}
        else{
           h52_OSggH[k]->Write();
	}


        SS52jetggH->cd();
        h52_SSggH[k]->SetName(name.c_str()+postfix);
        h52_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h52_WSSggH[k]->Write();
        else
           h52_SSggH[k]->Write();

        QCD52jetggH->cd();
        h52_QCDggH[k]->SetName(name.c_str()+postfix);
        h52_QCDggH[k]->Write();


        OS53jetggH->cd();
        h53_OSggH[k]->SetName(name.c_str()+postfix);
        h53_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h53_WOSggH[k]->Write();
	}
        else{
           h53_OSggH[k]->Write();
	}


        SS53jetggH->cd();
        h53_SSggH[k]->SetName(name.c_str()+postfix);
        h53_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h53_WSSggH[k]->Write();
        else
           h53_SSggH[k]->Write();

        QCD53jetggH->cd();
        h53_QCDggH[k]->SetName(name.c_str()+postfix);
        h53_QCDggH[k]->Write();


////////////////////////



        OS60jetggH->cd();
        h60_OSggH[k]->SetName(name.c_str()+postfix);
        h60_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h60_WOSggH[k]->Write();
	}
        else{
           h60_OSggH[k]->Write();
	}


        SS60jetggH->cd();
        h60_SSggH[k]->SetName(name.c_str()+postfix);
        h60_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h60_WSSggH[k]->Write();
        else
           h60_SSggH[k]->Write();

        QCD60jetggH->cd();
        h60_QCDggH[k]->SetName(name.c_str()+postfix);
        h60_QCDggH[k]->Write();



        OS33jetggH->cd();
        h33_OSggH[k]->SetName(name.c_str()+postfix);
        h33_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h33_WOSggH[k]->Write();
	}
        else{
           h33_OSggH[k]->Write();
	}


        SS33jetggH->cd();
        h33_SSggH[k]->SetName(name.c_str()+postfix);
        h33_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h33_WSSggH[k]->Write();
        else
           h33_SSggH[k]->Write();

        QCD33jetggH->cd();
        h33_QCDggH[k]->SetName(name.c_str()+postfix);
        h33_QCDggH[k]->Write();



        OS61jetggH->cd();
        h61_OSggH[k]->SetName(name.c_str()+postfix);
        h61_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h61_WOSggH[k]->Write();
	}
        else{
           h61_OSggH[k]->Write();
	}


        SS61jetggH->cd();
        h61_SSggH[k]->SetName(name.c_str()+postfix);
        h61_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h61_WSSggH[k]->Write();
        else
           h61_SSggH[k]->Write();

        QCD61jetggH->cd();
        h61_QCDggH[k]->SetName(name.c_str()+postfix);
        h61_QCDggH[k]->Write();



        OS62jetggH->cd();
        h62_OSggH[k]->SetName(name.c_str()+postfix);
        h62_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h62_WOSggH[k]->Write();
	}
        else{
           h62_OSggH[k]->Write();
	}


        SS62jetggH->cd();
        h62_SSggH[k]->SetName(name.c_str()+postfix);
        h62_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h62_WSSggH[k]->Write();
        else
           h62_SSggH[k]->Write();

        QCD62jetggH->cd();
        h62_QCDggH[k]->SetName(name.c_str()+postfix);
        h62_QCDggH[k]->Write();


        OS63jetggH->cd();
        h63_OSggH[k]->SetName(name.c_str()+postfix);
        h63_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h63_WOSggH[k]->Write();
	}
        else{
           h63_OSggH[k]->Write();
	}


        SS63jetggH->cd();
        h63_SSggH[k]->SetName(name.c_str()+postfix);
        h63_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h63_WSSggH[k]->Write();
        else
           h63_SSggH[k]->Write();

        QCD63jetggH->cd();
        h63_QCDggH[k]->SetName(name.c_str()+postfix);
        h63_QCDggH[k]->Write();


////////////////////////




        OS70jetggH->cd();
        h70_OSggH[k]->SetName(name.c_str()+postfix);
        h70_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h70_WOSggH[k]->Write();
	}
        else{
           h70_OSggH[k]->Write();
	}


        SS70jetggH->cd();
        h70_SSggH[k]->SetName(name.c_str()+postfix);
        h70_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h70_WSSggH[k]->Write();
        else
           h70_SSggH[k]->Write();

        QCD70jetggH->cd();
        h70_QCDggH[k]->SetName(name.c_str()+postfix);
        h70_QCDggH[k]->Write();



        OS33jetggH->cd();
        h33_OSggH[k]->SetName(name.c_str()+postfix);
        h33_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h33_WOSggH[k]->Write();
	}
        else{
           h33_OSggH[k]->Write();
	}


        SS33jetggH->cd();
        h33_SSggH[k]->SetName(name.c_str()+postfix);
        h33_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h33_WSSggH[k]->Write();
        else
           h33_SSggH[k]->Write();

        QCD33jetggH->cd();
        h33_QCDggH[k]->SetName(name.c_str()+postfix);
        h33_QCDggH[k]->Write();



        OS71jetggH->cd();
        h71_OSggH[k]->SetName(name.c_str()+postfix);
        h71_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h71_WOSggH[k]->Write();
	}
        else{
           h71_OSggH[k]->Write();
	}


        SS71jetggH->cd();
        h71_SSggH[k]->SetName(name.c_str()+postfix);
        h71_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h71_WSSggH[k]->Write();
        else
           h71_SSggH[k]->Write();

        QCD71jetggH->cd();
        h71_QCDggH[k]->SetName(name.c_str()+postfix);
        h71_QCDggH[k]->Write();



        OS72jetggH->cd();
        h72_OSggH[k]->SetName(name.c_str()+postfix);
        h72_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h72_WOSggH[k]->Write();
	}
        else{
           h72_OSggH[k]->Write();
	}


        SS72jetggH->cd();
        h72_SSggH[k]->SetName(name.c_str()+postfix);
        h72_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h72_WSSggH[k]->Write();
        else
           h72_SSggH[k]->Write();

        QCD72jetggH->cd();
        h72_QCDggH[k]->SetName(name.c_str()+postfix);
        h72_QCDggH[k]->Write();


        OS73jetggH->cd();
        h73_OSggH[k]->SetName(name.c_str()+postfix);
        h73_WOSggH[k]->SetName(name.c_str()+postfix);

        if (sample=="W"){
           h73_WOSggH[k]->Write();
	}
        else{
           h73_OSggH[k]->Write();
	}


        SS73jetggH->cd();
        h73_SSggH[k]->SetName(name.c_str()+postfix);
        h73_WSSggH[k]->SetName(name.c_str()+postfix);
        if (sample=="W")
           h73_WSSggH[k]->Write();
        else
           h73_SSggH[k]->Write();

        QCD73jetggH->cd();
        h73_QCDggH[k]->SetName(name.c_str()+postfix);
        h73_QCDggH[k]->Write();


////////////////////////




/////////////////////////////////

    }
    
    fout->Close();
} 


