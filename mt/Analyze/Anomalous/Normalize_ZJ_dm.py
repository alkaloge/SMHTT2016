if __name__ == "__main__":

    import ROOT
    import argparse

    fcentral=ROOT.TFile("files_nominal/ZJ.root","r")
    fshifted=ROOT.TFile("files_nominal/ZJ_dm.root","r")
    fnormalized=ROOT.TFile("files_nominal/ZJ_dm_norm.root","recreate")

    h0=fcentral.Get("mt_vbf_D0_0p0to0p2/ZJ")
    h0_1=fshifted.Get("mt_vbf_D0_0p0to0p2/ZJ_CMS_jetToTauDMReco_1prong_13TeVUp")
    h0_1.Scale(h0.Integral()/h0_1.Integral())
    h0_2=fshifted.Get("mt_vbf_D0_0p0to0p2/ZJ_CMS_jetToTauDMReco_1prong_13TeVDown")
    h0_2.Scale(h0.Integral()/h0_2.Integral())
    h0_3=fshifted.Get("mt_vbf_D0_0p0to0p2/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVUp")
    h0_3.Scale(h0.Integral()/h0_3.Integral())
    h0_4=fshifted.Get("mt_vbf_D0_0p0to0p2/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVDown")
    h0_4.Scale(h0.Integral()/h0_4.Integral())
    h0_5=fshifted.Get("mt_vbf_D0_0p0to0p2/ZJ_CMS_jetToTauDMReco_3prong_13TeVUp")
    h0_5.Scale(h0.Integral()/h0_5.Integral())
    h0_6=fshifted.Get("mt_vbf_D0_0p0to0p2/ZJ_CMS_jetToTauDMReco_3prong_13TeVDown")
    h0_6.Scale(h0.Integral()/h0_6.Integral())

    h1=fcentral.Get("mt_vbf_D0_0p2to0p4/ZJ")
    h1_1=fshifted.Get("mt_vbf_D0_0p2to0p4/ZJ_CMS_jetToTauDMReco_1prong_13TeVUp")
    h1_1.Scale(h1.Integral()/h1_1.Integral())
    h1_2=fshifted.Get("mt_vbf_D0_0p2to0p4/ZJ_CMS_jetToTauDMReco_1prong_13TeVDown")
    h1_2.Scale(h1.Integral()/h1_2.Integral())
    h1_3=fshifted.Get("mt_vbf_D0_0p2to0p4/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVUp")
    h1_3.Scale(h1.Integral()/h1_3.Integral())
    h1_4=fshifted.Get("mt_vbf_D0_0p2to0p4/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVDown")
    h1_4.Scale(h1.Integral()/h1_4.Integral())
    h1_5=fshifted.Get("mt_vbf_D0_0p2to0p4/ZJ_CMS_jetToTauDMReco_3prong_13TeVUp")
    h1_5.Scale(h1.Integral()/h1_5.Integral())
    h1_6=fshifted.Get("mt_vbf_D0_0p2to0p4/ZJ_CMS_jetToTauDMReco_3prong_13TeVDown")
    h1_6.Scale(h1.Integral()/h1_6.Integral())

    h2=fcentral.Get("mt_vbf_D0_0p4to0p6/ZJ")
    h2_1=fshifted.Get("mt_vbf_D0_0p4to0p6/ZJ_CMS_jetToTauDMReco_1prong_13TeVUp")
    h2_1.Scale(h2.Integral()/h2_1.Integral())
    h2_2=fshifted.Get("mt_vbf_D0_0p4to0p6/ZJ_CMS_jetToTauDMReco_1prong_13TeVDown")
    h2_2.Scale(h2.Integral()/h2_2.Integral())
    h2_3=fshifted.Get("mt_vbf_D0_0p4to0p6/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVUp")
    h2_3.Scale(h2.Integral()/h2_3.Integral())
    h2_4=fshifted.Get("mt_vbf_D0_0p4to0p6/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVDown")
    h2_4.Scale(h2.Integral()/h2_4.Integral())
    h2_5=fshifted.Get("mt_vbf_D0_0p4to0p6/ZJ_CMS_jetToTauDMReco_3prong_13TeVUp")
    h2_5.Scale(h2.Integral()/h2_5.Integral())
    h2_6=fshifted.Get("mt_vbf_D0_0p4to0p6/ZJ_CMS_jetToTauDMReco_3prong_13TeVDown")
    h2_6.Scale(h2.Integral()/h2_6.Integral())

    h3=fcentral.Get("mt_vbf_D0_0p6to0p8/ZJ")
    h3_1=fshifted.Get("mt_vbf_D0_0p6to0p8/ZJ_CMS_jetToTauDMReco_1prong_13TeVUp")
    h3_1.Scale(h3.Integral()/h3_1.Integral())
    h3_2=fshifted.Get("mt_vbf_D0_0p6to0p8/ZJ_CMS_jetToTauDMReco_1prong_13TeVDown")
    h3_2.Scale(h3.Integral()/h3_2.Integral())
    h3_3=fshifted.Get("mt_vbf_D0_0p6to0p8/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVUp")
    h3_3.Scale(h3.Integral()/h3_3.Integral())
    h3_4=fshifted.Get("mt_vbf_D0_0p6to0p8/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVDown")
    h3_4.Scale(h3.Integral()/h3_4.Integral())
    h3_5=fshifted.Get("mt_vbf_D0_0p6to0p8/ZJ_CMS_jetToTauDMReco_3prong_13TeVUp")
    h3_5.Scale(h3.Integral()/h3_5.Integral())
    h3_6=fshifted.Get("mt_vbf_D0_0p6to0p8/ZJ_CMS_jetToTauDMReco_3prong_13TeVDown")
    h3_6.Scale(h3.Integral()/h3_6.Integral())

    h4=fcentral.Get("mt_vbf_D0_0p8to1p0/ZJ")
    h4_1=fshifted.Get("mt_vbf_D0_0p8to1p0/ZJ_CMS_jetToTauDMReco_1prong_13TeVUp")
    h4_1.Scale(h4.Integral()/h4_1.Integral())
    h4_2=fshifted.Get("mt_vbf_D0_0p8to1p0/ZJ_CMS_jetToTauDMReco_1prong_13TeVDown")
    h4_2.Scale(h4.Integral()/h4_2.Integral())
    h4_3=fshifted.Get("mt_vbf_D0_0p8to1p0/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVUp")
    h4_3.Scale(h4.Integral()/h4_3.Integral())
    h4_4=fshifted.Get("mt_vbf_D0_0p8to1p0/ZJ_CMS_jetToTauDMReco_1prong1pizero_13TeVDown")
    h4_4.Scale(h4.Integral()/h4_4.Integral())
    h4_5=fshifted.Get("mt_vbf_D0_0p8to1p0/ZJ_CMS_jetToTauDMReco_3prong_13TeVUp")
    h4_5.Scale(h4.Integral()/h4_5.Integral())
    h4_6=fshifted.Get("mt_vbf_D0_0p8to1p0/ZJ_CMS_jetToTauDMReco_3prong_13TeVDown")
    h4_6.Scale(h4.Integral()/h4_6.Integral())

    fnormalized.cd()
    dir0OS=fnormalized.mkdir("mt_vbf_D0_0p0to0p2")
    dir0OS.cd()
    h0_1.Write()
    h0_2.Write()
    h0_3.Write()
    h0_4.Write()
    h0_5.Write()
    h0_6.Write()

    dir1OS=fnormalized.mkdir("mt_vbf_D0_0p2to0p4")
    dir1OS.cd()
    h1_1.Write()
    h1_2.Write()
    h1_3.Write()
    h1_4.Write()
    h1_5.Write()
    h1_6.Write()

    dir2OS=fnormalized.mkdir("mt_vbf_D0_0p4to0p6")
    dir2OS.cd()
    h2_1.Write()
    h2_2.Write()
    h2_3.Write()
    h2_4.Write()
    h2_5.Write()
    h2_6.Write()

    dir3OS=fnormalized.mkdir("mt_vbf_D0_0p6to0p8")
    dir3OS.cd()
    h3_1.Write()
    h3_2.Write()
    h3_3.Write()
    h3_4.Write()
    h3_5.Write()
    h3_6.Write()

    dir4OS=fnormalized.mkdir("mt_vbf_D0_0p8to1p0")
    dir4OS.cd()
    h4_1.Write()
    h4_2.Write()
    h4_3.Write()
    h4_4.Write()
    h4_5.Write()
    h4_6.Write()
