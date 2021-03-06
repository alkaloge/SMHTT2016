//

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
//#include "../interface/Mela.h"
//#include "MELA/interface/Mela.h"
#include "ZZMatrixElement/MELA/interface/Mela.h"
#include "ZZMatrixElement/MELA/interface/TUtil.hh"
#include "TMath.h"
#include "TLorentzVector.h"
#include "TLorentzRotation.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TString.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"


using namespace RooFit;
using namespace std;

//void anaHTT(TString InFile, TString OutFile)
void anaHTT()
{
	int erg_tev=13;
	float mPOLE=125.6;
	float wPOLE=4.07e-3;
	TString InFile="/afs/cern.ch/user/a/alkaloge/work/CP/CMSSW_8_0_25/src/SMHTT2016/Tools/FILEIN";
	TString OutFile="/afs/cern.ch/user/a/alkaloge/work/CP/CMSSW_8_0_25/src/SMHTT2016/Tools/FILEOUT";
	TVar::VerbosityLevel verbosity = TVar::ERROR;
	Mela mela(erg_tev, mPOLE, verbosity);
	std::cout << "Starting!!!" << std::endl;
	std::cout << InFile << std::endl;


	TFile *finput = new TFile(InFile);//"TauTau_13_SKMD-skmd_mrgd_VBFHIGGS0M.root");//
	//  TFile *finput = new TFile("all1234tmpOut2.root");
	TTree *tree = (TTree*) finput->Get("CHANNEL_tree");
	TH1F *nevents = (TH1F*) finput->Get("nevents");

	//save SumOfWeights ?


	float ME_sm, ME_bsm, ME_bsm_mlt, KD_sm, KD_bsm, melaD0minus, ME_int, melaDCP,
	      ME_sm_ggH, ME_bsm_ggH, ME_int_ggH,
	      melaD0hplus, melaDint, melaDL1, melaDL1int, melaDL1Zg, melaDL1Zgint,
	      melaD0minusggH, melaDCPggH,
	      dPhi_jj, dPhiUnsigned_jj, dEta_jj,
	      costhetastar, costheta1, costheta2, melaPhi, melaPhi1, Q2V1, Q2V2,
	      sqrtQ2V1, sqrtQ2V2, avgSqrtQ2V12;

	Float_t         m_sv;
	Float_t         pt_sv;
	Float_t         eta_sv;
	Float_t         phi_sv;
	Int_t           njets;
	float jmass_1, jpt_1, jeta_1, jphi_1;
	float jmass_2, jpt_2, jeta_2, jphi_2;
	Float_t         pt_2;
	Float_t         phi_2;
	Float_t         eta_2;
	Float_t         m_2;
	Float_t         pt_1;
	Float_t         phi_1;
	Float_t         eta_1;
	Float_t         m_1;
	Float_t         met;
	Float_t         metphi;  

	TBranch        *b_njets;   //!
	TBranch        *b_jpt_1;   //!
	TBranch        *b_jeta_1;   //!
	TBranch        *b_jphi_1;   //!
	TBranch        *b_jpt_2;   //!
	TBranch        *b_jeta_2;   //!
	TBranch        *b_jphi_2;   //!
	TBranch        *b_m_sv;   //!
	TBranch        *b_pt_sv;   //!
	TBranch        *b_eta_sv;   //!
	TBranch        *b_phi_sv;   //!
	TBranch        *b_pt_2;   //!
	TBranch        *b_phi_2;   //!
	TBranch        *b_eta_2;   //!
	TBranch        *b_m_2;   //!
	TBranch        *b_pt_1;   //!
	TBranch        *b_phi_1;   //!
	TBranch        *b_eta_1;   //!
	TBranch        *b_m_1;   //!
	TBranch        *b_metphi;   //!
	TBranch        *b_met;   //!  

	tree->SetBranchAddress("njets", &njets, &b_njets);
	tree->SetBranchAddress("jpt_1", &jpt_1, &b_jpt_1);
	tree->SetBranchAddress("jeta_1", &jeta_1, &b_jeta_1);
	tree->SetBranchAddress("jphi_1", &jphi_1, &b_jphi_1);
	tree->SetBranchAddress("jpt_2", &jpt_2, &b_jpt_2);
	tree->SetBranchAddress("jeta_2", &jeta_2, &b_jeta_2);
	tree->SetBranchAddress("jphi_2", &jphi_2, &b_jphi_2);
	tree->SetBranchAddress("m_sv", &m_sv, &b_m_sv);
	tree->SetBranchAddress("pt_sv", &pt_sv, &b_pt_sv);
	tree->SetBranchAddress("eta_sv", &eta_sv, &b_eta_sv);
	tree->SetBranchAddress("phi_sv", &phi_sv, &b_phi_sv);
	tree->SetBranchAddress("pt_1", &pt_1, &b_pt_1);
	tree->SetBranchAddress("phi_1", &phi_1, &b_phi_1);
	tree->SetBranchAddress("eta_1", &eta_1, &b_eta_1);
	tree->SetBranchAddress("m_1", &m_1, &b_m_1);
	tree->SetBranchAddress("pt_2", &pt_2, &b_pt_2);
	tree->SetBranchAddress("phi_2", &phi_2, &b_phi_2);
	tree->SetBranchAddress("eta_2", &eta_2, &b_eta_2);
	tree->SetBranchAddress("m_2", &m_2, &b_m_2);
	tree->SetBranchAddress("metphi", &metphi, &b_metphi);
	tree->SetBranchAddress("met", &met, &b_met);

	TFile* foutput = new TFile(OutFile, "recreate");

	TTree* newtree = new TTree("TestTree", "");
	newtree = tree->CloneTree(0);
	newtree->Branch("melaD0minus", &melaD0minus); //
	newtree->Branch("melaDCP", &melaDCP);
	newtree->Branch("melaD0hplus", &melaD0hplus);
	newtree->Branch("melaDint", &melaDint);
	newtree->Branch("melaDL1", &melaDL1);
	newtree->Branch("melaDL1int", &melaDL1int);
	newtree->Branch("melaDL1Zg", &melaDL1Zg);
	newtree->Branch("melaDL1Zgint", &melaDL1Zgint);


	newtree->Branch("melaD0minusggH", &melaD0minusggH);
	newtree->Branch("melaDCPggH", &melaDCPggH);
	newtree->Branch("melaDPhijj", &dPhi_jj);
	newtree->Branch("melaDPhiUnsignedjj", &dPhiUnsigned_jj);
	newtree->Branch("melaDEtajj", &dEta_jj);
	newtree->Branch("melacosthetastar", &costhetastar);
	newtree->Branch("melacostheta1", &costheta1);
	newtree->Branch("melacostheta2", &costheta2);

	newtree->Branch("melaPhi", &melaPhi);
	newtree->Branch("melaPhi1", &melaPhi1);
	newtree->Branch("melaQ2V1", &Q2V1);
	newtree->Branch("melaQ2V2", &Q2V2);
	newtree->Branch("melaSqrtQ2V1", &sqrtQ2V1);
	newtree->Branch("melaSqrtQ2V2", &sqrtQ2V2);
	newtree->Branch("melaAvgSqrtQ2V12", &avgSqrtQ2V12);

	mela.setCandidateDecayMode(TVar::CandidateDecay_Stable);

	Long64_t nentries = tree->GetEntries();
	int recorded=0;

	Long64_t nbytes = 0, nb = 0;
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		if ( jentry % 10000 == 0 ) std::cout << jentry << std::endl;
		nb = tree->GetEntry(jentry);   nbytes += nb;

		tree->GetEntry(jentry);
		melaD0hplus = -9;
		melaDint = -9;
		melaDL1 = -9;
		melaDL1int = -9;
		melaDL1Zg = -9;
		melaDL1Zgint = -9;
		melaD0minus = -9;
		melaDCP = -9;
		melaD0minusggH = -9;
		melaDCPggH = -9;
		dPhi_jj = -9;
		dPhiUnsigned_jj = -9;
		dEta_jj = -19;
		costhetastar = -9;
		costheta1 = -9;
		costheta2 = -9;
		melaPhi = -9;
		melaPhi1 = -9;
		Q2V1 = -9;
		Q2V2 = -9;
		sqrtQ2V1 = -9;
		sqrtQ2V2 = -9;
		avgSqrtQ2V12 = -9;



		TLorentzVector mytau;
		mytau.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
		TLorentzVector mymu;
		mymu.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
		TLorentzVector mymet;
		mymet.SetPtEtaPhiM(met,0,metphi,0);

		pt_sv=(mymu+mytau+mymet).Pt();
		phi_sv=(mymu+mytau+mymet).Phi();
		eta_sv=(mymu+mytau+mymet).Eta(); /////////this is actually not correct

		if (njets>=2){
			TLorentzVector jet1(0, 0, 1e-3, 1e-3), jet2(0, 0, 1e-3, 1e-3), higgs(0, 0, 0, 0), blank1(0, 0, 0, 0);
			jet1.SetPtEtaPhiM(jpt_1, jeta_1, jphi_1, 0);
			jet2.SetPtEtaPhiM(jpt_2, jeta_2, jphi_2, 0);
			higgs.SetPtEtaPhiM(pt_sv, eta_sv, phi_sv, m_sv);
			TVector3 boostH = higgs.BoostVector();

			SimpleParticleCollection_t associated;
			associated.push_back(SimpleParticle_t(0, jet1));
			associated.push_back(SimpleParticle_t(0, jet2));

			TLorentzVector pDaughters1, pDaughters2;
			//     std::vector<TLorentzVector> daus = mela.calculate4Momentum(m_sv, m1, m2, acos(hs), acos(h1), acos(h2), phi1, phi);
			pDaughters1.SetPtEtaPhiM(pt_1, eta_1, phi_1, m_1);
			pDaughters1.SetPtEtaPhiM(pt_2, eta_2, phi_2, m_2);

			SimpleParticleCollection_t daughters_ZZ;
			daughters_ZZ.push_back(SimpleParticle_t(25, higgs));
			// daughters_ZZ.push_back(SimpleParticle_t(13, pDaughters1));
			// daughters_ZZ.push_back(SimpleParticle_t(15, pDaughters2));
			mela.setInputEvent(&daughters_ZZ, &associated, (SimpleParticleCollection_t*)0, false);

			//get ME scalar
			mela.setProcess(TVar::HSMHiggs, TVar::JHUGen, TVar::JJVBF);
			mela.computeProdP(ME_sm, false);

			//get ME bsm
			mela.setProcess(TVar::H0minus, TVar::JHUGen, TVar::JJVBF);
			mela.computeProdP(ME_bsm, false);
			ME_bsm_mlt = ME_bsm*pow(0.297979, 2);
			//compute D_BSM (eq.5 of HIG-17-011)
			KD_bsm = ME_sm / (ME_sm + ME_bsm);
			melaD0minus = ME_sm / (ME_sm + ME_bsm_mlt);


			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJVBF);
			mela.selfDHzzcoupl[0][gHIGGS_VV_4][0]=1;
			mela.selfDHzzcoupl[0][gHIGGS_VV_1][0]=1;
			mela.computeProdP(ME_int, false);

			//define D_CP
			melaDCP = (0.297979*(ME_int-(ME_sm + ME_bsm)))/(ME_sm + (pow(0.297979, 2)*ME_bsm));

			// New from Heshy: 22, Nov 2017
			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJVBF);
			mela.selfDHzzcoupl[0][gHIGGS_VV_2][0]=1;
			mela.computeProdP(ME_bsm, false);
			ME_bsm_mlt = ME_bsm*pow(0.271899, 2);
			melaD0hplus = ME_sm / (ME_sm + ME_bsm_mlt);

			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJVBF);
			mela.selfDHzzcoupl[0][gHIGGS_VV_2][0]=1;
			mela.selfDHzzcoupl[0][gHIGGS_VV_1][0]=1;
			mela.computeProdP(ME_int, false);
			melaDint = (0.271899*(ME_int-(ME_sm + ME_bsm)))/(ME_sm + (pow(0.271899, 2)*ME_bsm));


			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJVBF);
			mela.selfDHzzcoupl[0][gHIGGS_VV_1_PRIME2][0]=1;
			mela.computeProdP(ME_bsm, false);
			ME_bsm_mlt = ME_bsm*pow(2156.43, 2);
			melaDL1 = ME_sm / (ME_sm + ME_bsm_mlt);

			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJVBF);
			mela.selfDHzzcoupl[0][gHIGGS_VV_1_PRIME2][0]=1;
			mela.selfDHzzcoupl[0][gHIGGS_VV_1][0]=1;
			mela.computeProdP(ME_int, false);
			melaDL1int = (2156.43*(ME_int-(ME_sm + ME_bsm)))/(ME_sm + (pow(2156.43, 2)*ME_bsm));

			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJVBF);
			mela.selfDHzzcoupl[0][gHIGGS_ZA_1_PRIME2][0]=1;
			mela.computeProdP(ME_bsm, false);
			ME_bsm_mlt = ME_bsm*pow(4091.0, 2);
			melaDL1Zg = ME_sm / (ME_sm + ME_bsm_mlt);

			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJVBF);
			mela.selfDHzzcoupl[0][gHIGGS_ZA_1_PRIME2][0]=1;
			mela.selfDHzzcoupl[0][gHIGGS_VV_1][0]=1;
			mela.computeProdP(ME_int, false);
			melaDL1Zgint = (4091.0*(ME_int-(ME_sm + ME_bsm)))/(ME_sm + (pow(4091.0, 2)*ME_bsm));

			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJQCD);
			mela.selfDHggcoupl[0][gHIGGS_GG_2][0]=1;
			mela.computeProdP(ME_sm_ggH, false);

			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJQCD);
			mela.selfDHggcoupl[0][gHIGGS_GG_4][0]=1;
			mela.computeProdP(ME_bsm_ggH, false);

			melaD0minusggH = ME_sm_ggH / (ME_sm_ggH + ME_bsm_ggH);

			mela.setProcess(TVar::SelfDefine_spin0, TVar::JHUGen, TVar::JJQCD);
			mela.selfDHggcoupl[0][gHIGGS_GG_2][0]=1;
			mela.selfDHggcoupl[0][gHIGGS_GG_4][0]=1;
			mela.computeProdP(ME_int_ggH, false);

			melaDCPggH = (ME_int_ggH-(ME_sm_ggH + ME_bsm_ggH))/(ME_sm_ggH + ME_bsm_ggH);



			if (jet1.Pz() <= jet2.Pz()) {
				dPhi_jj = jet1.DeltaPhi(jet2);
			}
			else {
				dPhi_jj = jet2.DeltaPhi(jet1);
			}
			dPhiUnsigned_jj = jet1.DeltaPhi(jet2);
			dEta_jj = jet1.Eta()-jet2.Eta();

			// See: https://github.com/usarica/HiggsAnalysis-ZZMatrixElement/blob/newVH/MELA/interface/TUtil.hh#L106-L122
			TUtil::computeVBFAngles( 
					costhetastar, costheta1, costheta2, melaPhi, melaPhi1, Q2V1, Q2V2,
					higgs, 25,
					blank1, -9000,
					blank1, -9000,
					blank1, -9000,
					jet1, 0,
					jet2, 0
					);

			sqrtQ2V1 = TMath::Sqrt( Q2V1 );
			sqrtQ2V2 = TMath::Sqrt( Q2V2 );
			avgSqrtQ2V12 = (sqrtQ2V1 + sqrtQ2V2) / 2.;
			// if (Cut(ientry) < 0) continue;
		}
		newtree->Fill();
		recorded++;
		mela.resetInputEvent();
	}
	foutput->WriteTObject(newtree);
	foutput->cd();
	nevents->Write();
	delete newtree;
	foutput->Close();
	finput->Close();
}

