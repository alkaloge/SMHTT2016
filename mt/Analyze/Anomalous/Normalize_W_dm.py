if __name__ == "__main__":

    import ROOT
    import argparse

    fcentral=ROOT.TFile("files_nominal/W.root","r")
    fshifted=ROOT.TFile("files_nominal/Wunscaled_dm.root","r")
    fnormalized=ROOT.TFile("files_nominal/W_dm.root","recreate")

    h0=fcentral.Get("mt_0jet/W")
    h0_1=fshifted.Get("mt_0jet/W_CMS_jetToTauDMReco_1prong_13TeVUp")
    h0_1.Scale(h0.Integral()/h0_1.Integral())
    h0_2=fshifted.Get("mt_0jet/W_CMS_jetToTauDMReco_1prong_13TeVDown")
    h0_2.Scale(h0.Integral()/h0_2.Integral())
    h0_3=fshifted.Get("mt_0jet/W_CMS_jetToTauDMReco_1prong1pizero_13TeVUp")
    h0_3.Scale(h0.Integral()/h0_3.Integral())
    h0_4=fshifted.Get("mt_0jet/W_CMS_jetToTauDMReco_1prong1pizero_13TeVDown")
    h0_4.Scale(h0.Integral()/h0_4.Integral())
    h0_5=fshifted.Get("mt_0jet/W_CMS_jetToTauDMReco_3prong_13TeVUp")
    h0_5.Scale(h0.Integral()/h0_5.Integral())
    h0_6=fshifted.Get("mt_0jet/W_CMS_jetToTauDMReco_3prong_13TeVDown")
    h0_6.Scale(h0.Integral()/h0_6.Integral())

    h1=fcentral.Get("mt_boosted/W")
    h1_1=fshifted.Get("mt_boosted/W_CMS_jetToTauDMReco_1prong_13TeVUp")
    h1_1.Scale(h1.Integral()/h1_1.Integral())
    h1_2=fshifted.Get("mt_boosted/W_CMS_jetToTauDMReco_1prong_13TeVDown")
    h1_2.Scale(h1.Integral()/h1_2.Integral())
    h1_3=fshifted.Get("mt_boosted/W_CMS_jetToTauDMReco_1prong1pizero_13TeVUp")
    h1_3.Scale(h1.Integral()/h1_3.Integral())
    h1_4=fshifted.Get("mt_boosted/W_CMS_jetToTauDMReco_1prong1pizero_13TeVDown")
    h1_4.Scale(h1.Integral()/h1_4.Integral())
    h1_5=fshifted.Get("mt_boosted/W_CMS_jetToTauDMReco_3prong_13TeVUp")
    h1_5.Scale(h1.Integral()/h1_5.Integral())
    h1_6=fshifted.Get("mt_boosted/W_CMS_jetToTauDMReco_3prong_13TeVDown")
    h1_6.Scale(h1.Integral()/h1_6.Integral())

    fnormalized.cd()
    dir0OS=fnormalized.mkdir("mt_0jet")
    dir0OS.cd()
    h0_1.Write()
    h0_2.Write()
    h0_3.Write()
    h0_4.Write()
    h0_5.Write()
    h0_6.Write()

    dir1OS=fnormalized.mkdir("mt_boosted")
    dir1OS.cd()
    h1_1.Write()
    h1_2.Write()
    h1_3.Write()
    h1_4.Write()
    h1_5.Write()
    h1_6.Write()


