if __name__ == "__main__":

    import ROOT
    import argparse

    fW=ROOT.TFile("files_nominal/W.root","r")
    fW_jfru=ROOT.TFile("files_nominal/Wunscaled_jfru.root","r")
    fW_jfrd=ROOT.TFile("files_nominal/Wunscaled_jfrd.root","r")
    fout_jfru=ROOT.TFile("files_nominal/W_jfru.root","recreate")
    fout_jfrd=ROOT.TFile("files_nominal/W_jfrd.root","recreate")

    hW0jet=fW.Get("et_0jet/W")
    hW0jet_u=fW_jfru.Get("et_0jet/W_CMS_htt_jetToTauFake_13TeVUp")
    hW0jet_d=fW_jfrd.Get("et_0jet/W_CMS_htt_jetToTauFake_13TeVDown")
    hW0jet_u.Scale(hW0jet.Integral()/hW0jet_u.Integral())
    hW0jet_d.Scale(hW0jet.Integral()/hW0jet_d.Integral())

    hW1jet=fW.Get("et_boosted/W")
    hW1jet_u=fW_jfru.Get("et_boosted/W_CMS_htt_jetToTauFake_13TeVUp")
    hW1jet_d=fW_jfrd.Get("et_boosted/W_CMS_htt_jetToTauFake_13TeVDown")
    hW1jet_u.Scale(hW1jet.Integral()/hW1jet_u.Integral())
    hW1jet_d.Scale(hW1jet.Integral()/hW1jet_d.Integral())

    hW2jet=fW.Get("et_vbf/W")
    hW2jet_u=fW_jfru.Get("et_vbf/W_CMS_htt_jetToTauFake_13TeVUp")
    hW2jet_d=fW_jfrd.Get("et_vbf/W_CMS_htt_jetToTauFake_13TeVDown")
    hW2jet_u.Scale(hW2jet.Integral()/hW2jet_u.Integral())
    hW2jet_d.Scale(hW2jet.Integral()/hW2jet_d.Integral())

    hW23jet=fW.Get("et_vbf_D0_0p0to0p2/W")
    hW23jet_u=fW_jfru.Get("et_vbf_D0_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVUp")
    hW23jet_d=fW_jfrd.Get("et_vbf_D0_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVDown")
    hW23jet_u.Scale(hW23jet.Integral()/hW23jet_u.Integral())
    hW23jet_d.Scale(hW23jet.Integral()/hW23jet_d.Integral())

    hW24jet=fW.Get("et_vbf_D0_0p2to0p4/W")
    hW24jet_u=fW_jfru.Get("et_vbf_D0_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVUp")
    hW24jet_d=fW_jfrd.Get("et_vbf_D0_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVDown")
    hW24jet_u.Scale(hW24jet.Integral()/hW24jet_u.Integral())
    hW24jet_d.Scale(hW24jet.Integral()/hW24jet_d.Integral())

    hW25jet=fW.Get("et_vbf_D0_0p4to0p8/W")
    hW25jet_u=fW_jfru.Get("et_vbf_D0_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVUp")
    hW25jet_d=fW_jfrd.Get("et_vbf_D0_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVDown")
    hW25jet_u.Scale(hW25jet.Integral()/hW25jet_u.Integral())
    hW25jet_d.Scale(hW25jet.Integral()/hW25jet_d.Integral())

    hW27jet=fW.Get("et_vbf_D0_0p8to1p0/W")
    hW27jet_u=fW_jfru.Get("et_vbf_D0_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVUp")
    hW27jet_d=fW_jfrd.Get("et_vbf_D0_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVDown")
    hW27jet_u.Scale(hW27jet.Integral()/hW27jet_u.Integral())
    hW27jet_d.Scale(hW27jet.Integral()/hW27jet_d.Integral())
    ##ggH start
    hW23jetggH=fW.Get("et_vbf_D0_0p0to0p2_ggH/W")
    hW23jet_uggH=fW_jfru.Get("et_vbf_D0_0p0to0p2_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW23jet_dggH=fW_jfrd.Get("et_vbf_D0_0p0to0p2_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW23jet_uggH.Scale(hW23jetggH.Integral()/hW23jet_uggH.Integral())
    hW23jet_dggH.Scale(hW23jetggH.Integral()/hW23jet_dggH.Integral())

    hW24jetggH=fW.Get("et_vbf_D0_0p2to0p4_ggH/W")
    hW24jet_uggH=fW_jfru.Get("et_vbf_D0_0p2to0p4_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW24jet_dggH=fW_jfrd.Get("et_vbf_D0_0p2to0p4_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW24jet_uggH.Scale(hW24jetggH.Integral()/hW24jet_uggH.Integral())
    hW24jet_dggH.Scale(hW24jetggH.Integral()/hW24jet_dggH.Integral())

    hW25jetggH=fW.Get("et_vbf_D0_0p4to0p8_ggH/W")
    hW25jet_uggH=fW_jfru.Get("et_vbf_D0_0p4to0p8_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW25jet_dggH=fW_jfrd.Get("et_vbf_D0_0p4to0p8_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW25jet_uggH.Scale(hW25jetggH.Integral()/hW25jet_uggH.Integral())
    hW25jet_dggH.Scale(hW25jetggH.Integral()/hW25jet_dggH.Integral())

    hW27jetggH=fW.Get("et_vbf_D0_0p8to1p0_ggH/W")
    hW27jet_uggH=fW_jfru.Get("et_vbf_D0_0p8to1p0_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW27jet_dggH=fW_jfrd.Get("et_vbf_D0_0p8to1p0_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW27jet_uggH.Scale(hW27jetggH.Integral()/hW27jet_uggH.Integral())
    hW27jet_dggH.Scale(hW27jetggH.Integral()/hW27jet_dggH.Integral())

    hW33jetggH=fW.Get("et_vbf_D0_0p0to0p2_DCPm_ggH/W")
    hW33jet_uggH=fW_jfru.Get("et_vbf_D0_0p0to0p2_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW33jet_dggH=fW_jfrd.Get("et_vbf_D0_0p0to0p2_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW33jet_uggH.Scale(hW33jetggH.Integral()/hW33jet_uggH.Integral())
    hW33jet_dggH.Scale(hW33jetggH.Integral()/hW33jet_dggH.Integral())

    hW34jetggH=fW.Get("et_vbf_D0_0p2to0p4_DCPm_ggH/W")
    hW34jet_uggH=fW_jfru.Get("et_vbf_D0_0p2to0p4_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW34jet_dggH=fW_jfrd.Get("et_vbf_D0_0p2to0p4_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW34jet_uggH.Scale(hW34jetggH.Integral()/hW34jet_uggH.Integral())
    hW34jet_dggH.Scale(hW34jetggH.Integral()/hW34jet_dggH.Integral())

    hW35jetggH=fW.Get("et_vbf_D0_0p4to0p8_DCPm_ggH/W")
    hW35jet_uggH=fW_jfru.Get("et_vbf_D0_0p4to0p8_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW35jet_dggH=fW_jfrd.Get("et_vbf_D0_0p4to0p8_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW35jet_uggH.Scale(hW35jetggH.Integral()/hW35jet_uggH.Integral())
    hW35jet_dggH.Scale(hW35jetggH.Integral()/hW35jet_dggH.Integral())

    hW37jetggH=fW.Get("et_vbf_D0_0p8to1p0_DCPm_ggH/W")
    hW37jet_uggH=fW_jfru.Get("et_vbf_D0_0p8to1p0_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW37jet_dggH=fW_jfrd.Get("et_vbf_D0_0p8to1p0_DCPm_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW37jet_uggH.Scale(hW37jetggH.Integral()/hW37jet_uggH.Integral())
    hW37jet_dggH.Scale(hW37jetggH.Integral()/hW37jet_dggH.Integral())

    hW43jetggH=fW.Get("et_vbf_D0_Pito1p5m_ggH/W")
    hW43jet_uggH=fW_jfru.Get("et_vbf_D0_Pito1p5m_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW43jet_dggH=fW_jfrd.Get("et_vbf_D0_Pito1p5m_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW43jet_uggH.Scale(hW43jetggH.Integral()/hW43jet_uggH.Integral())
    hW43jet_dggH.Scale(hW43jetggH.Integral()/hW43jet_dggH.Integral())

    hW44jetggH=fW.Get("et_vbf_D0_1p5to0_ggH/W")
    hW44jet_uggH=fW_jfru.Get("et_vbf_D0_1p5to0_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW44jet_dggH=fW_jfrd.Get("et_vbf_D0_1p5to0_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW44jet_uggH.Scale(hW44jetggH.Integral()/hW44jet_uggH.Integral())
    hW44jet_dggH.Scale(hW44jetggH.Integral()/hW44jet_dggH.Integral())


    hW45jetggH=fW.Get("et_vbf_D0_Pito1p5m_ggH/W")
    hW45jet_uggH=fW_jfru.Get("et_vbf_D0_Pito1p5m_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW45jet_dggH=fW_jfrd.Get("et_vbf_D0_Pito1p5m_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW45jet_uggH.Scale(hW45jetggH.Integral()/hW45jet_uggH.Integral())
    hW45jet_dggH.Scale(hW45jetggH.Integral()/hW45jet_dggH.Integral())

    hW47jetggH=fW.Get("et_vbf_D0_1p5toPi_ggH/W")
    hW47jet_uggH=fW_jfru.Get("et_vbf_D0_1p5toPi_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW47jet_dggH=fW_jfrd.Get("et_vbf_D0_1p5toPi_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW47jet_uggH.Scale(hW47jetggH.Integral()/hW47jet_uggH.Integral())
    hW47jet_dggH.Scale(hW47jetggH.Integral()/hW47jet_dggH.Integral())


    hW53jetggH=fW.Get("et_vbf_Pito1p6m_ggH/W")
    hW53jet_uggH=fW_jfru.Get("et_vbf_Pito1p6m_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW53jet_dggH=fW_jfrd.Get("et_vbf_Pito1p6m_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW53jet_uggH.Scale(hW53jetggH.Integral()/hW53jet_uggH.Integral())
    hW53jet_dggH.Scale(hW53jetggH.Integral()/hW53jet_dggH.Integral())

    hW54jetggH=fW.Get("et_vbf_1p6to0_ggH/W")
    hW54jet_uggH=fW_jfru.Get("et_vbf_1p6to0_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW54jet_dggH=fW_jfrd.Get("et_vbf_1p6to0_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW54jet_uggH.Scale(hW54jetggH.Integral()/hW54jet_uggH.Integral())
    hW54jet_dggH.Scale(hW54jetggH.Integral()/hW54jet_dggH.Integral())


    hW55jetggH=fW.Get("et_vbf_0to1p6p_ggH/W")
    hW55jet_uggH=fW_jfru.Get("et_vbf_0to1p6p_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW55jet_dggH=fW_jfrd.Get("et_vbf_0to1p6p_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW55jet_uggH.Scale(hW55jetggH.Integral()/hW55jet_uggH.Integral())
    hW55jet_dggH.Scale(hW55jetggH.Integral()/hW55jet_dggH.Integral())

    hW57jetggH=fW.Get("et_vbf_1p6toPi_ggH/W")
    hW57jet_uggH=fW_jfru.Get("et_vbf_1p6toPi_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW57jet_dggH=fW_jfrd.Get("et_vbf_1p6toPi_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW57jet_uggH.Scale(hW57jetggH.Integral()/hW57jet_uggH.Integral())
    hW57jet_dggH.Scale(hW57jetggH.Integral()/hW57jet_dggH.Integral())


    hW63jetggH=fW.Get("et_vbf_Pito1p6m_ggH_Uns/W")
    hW63jet_uggH=fW_jfru.Get("et_vbf_Pito1p6m_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVUp")
    hW63jet_dggH=fW_jfrd.Get("et_vbf_Pito1p6m_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVDown")
    hW63jet_uggH.Scale(hW63jetggH.Integral()/hW63jet_uggH.Integral())
    hW63jet_dggH.Scale(hW63jetggH.Integral()/hW63jet_dggH.Integral())


    hW64jetggH=fW.Get("et_vbf_1p6to0_ggH_Uns/W")
    hW64jet_uggH=fW_jfru.Get("et_vbf_1p6to0_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVUp")
    hW64jet_dggH=fW_jfrd.Get("et_vbf_1p6to0_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVDown")
    hW64jet_uggH.Scale(hW63jetggH.Integral()/hW64jet_uggH.Integral())
    hW64jet_dggH.Scale(hW63jetggH.Integral()/hW64jet_dggH.Integral())


    hW65jetggH=fW.Get("et_vbf_0to1p6p_ggH_Uns/W")
    hW65jet_uggH=fW_jfru.Get("et_vbf_0to1p6p_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVUp")
    hW65jet_dggH=fW_jfrd.Get("et_vbf_0to1p6p_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVDown")
    hW65jet_uggH.Scale(hW63jetggH.Integral()/hW65jet_uggH.Integral())
    hW65jet_dggH.Scale(hW63jetggH.Integral()/hW65jet_dggH.Integral())


    hW67jetggH=fW.Get("et_vbf_1p6toPi_ggH_Uns/W")
    hW67jet_uggH=fW_jfru.Get("et_vbf_1p6toPi_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVUp")
    hW67jet_dggH=fW_jfrd.Get("et_vbf_1p6toPi_ggH_Uns/W_CMS_htt_jetToTauFake_13TeVDown")
    hW67jet_uggH.Scale(hW63jetggH.Integral()/hW67jet_uggH.Integral())
    hW67jet_dggH.Scale(hW63jetggH.Integral()/hW67jet_dggH.Integral())


    hW73jetggH=fW.Get("et_vbf_dPhia_ggH/W")
    hW73jet_uggH=fW_jfru.Get("et_vbf_dPhia_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW73jet_dggH=fW_jfrd.Get("et_vbf_dPhia_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW73jet_uggH.Scale(hW73jetggH.Integral()/hW73jet_uggH.Integral())
    hW73jet_dggH.Scale(hW73jetggH.Integral()/hW73jet_dggH.Integral())


    hW74jetggH=fW.Get("et_vbf_dPhib_ggH/W")
    hW74jet_uggH=fW_jfru.Get("et_vbf_dPhib_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW74jet_dggH=fW_jfrd.Get("et_vbf_dPhib_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW74jet_uggH.Scale(hW73jetggH.Integral()/hW74jet_uggH.Integral())
    hW74jet_dggH.Scale(hW73jetggH.Integral()/hW74jet_dggH.Integral())


    hW75jetggH=fW.Get("et_vbf_dPhic_ggH/W")
    hW75jet_uggH=fW_jfru.Get("et_vbf_dPhic_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW75jet_dggH=fW_jfrd.Get("et_vbf_dPhic_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW75jet_uggH.Scale(hW73jetggH.Integral()/hW75jet_uggH.Integral())
    hW75jet_dggH.Scale(hW73jetggH.Integral()/hW75jet_dggH.Integral())


    hW77jetggH=fW.Get("et_vbf_dPhid_ggH/W")
    hW77jet_uggH=fW_jfru.Get("et_vbf_dPhid_ggH/W_CMS_htt_jetToTauFake_13TeVUp")
    hW77jet_dggH=fW_jfrd.Get("et_vbf_dPhid_ggH/W_CMS_htt_jetToTauFake_13TeVDown")
    hW77jet_uggH.Scale(hW73jetggH.Integral()/hW77jet_uggH.Integral())
    hW77jet_dggH.Scale(hW73jetggH.Integral()/hW77jet_dggH.Integral())


    #ggH end

    hW523jet=fW.Get("et_vbf_D0hplus_0p0to0p2/W")
    hW523jet_u=fW_jfru.Get("et_vbf_D0hplus_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVUp")
    hW523jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVDown")
    hW523jet_u.Scale(hW523jet.Integral()/hW523jet_u.Integral())
    hW523jet_d.Scale(hW523jet.Integral()/hW523jet_d.Integral())

    hW524jet=fW.Get("et_vbf_D0hplus_0p2to0p4/W")
    hW524jet_u=fW_jfru.Get("et_vbf_D0hplus_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVUp")
    hW524jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVDown")
    hW524jet_u.Scale(hW524jet.Integral()/hW524jet_u.Integral())
    hW524jet_d.Scale(hW524jet.Integral()/hW524jet_d.Integral())

    hW525jet=fW.Get("et_vbf_D0hplus_0p4to0p8/W")
    hW525jet_u=fW_jfru.Get("et_vbf_D0hplus_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVUp")
    hW525jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVDown")
    hW525jet_u.Scale(hW525jet.Integral()/hW525jet_u.Integral())
    hW525jet_d.Scale(hW525jet.Integral()/hW525jet_d.Integral())

    hW527jet=fW.Get("et_vbf_D0hplus_0p8to1p0/W")
    hW527jet_u=fW_jfru.Get("et_vbf_D0hplus_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVUp")
    hW527jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVDown")
    hW527jet_u.Scale(hW527jet.Integral()/hW527jet_u.Integral())
    hW527jet_d.Scale(hW527jet.Integral()/hW527jet_d.Integral())

    hW623jet=fW.Get("et_vbf_DL1_0p0to0p2/W")
    hW623jet_u=fW_jfru.Get("et_vbf_DL1_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVUp")
    hW623jet_d=fW_jfrd.Get("et_vbf_DL1_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVDown")
    hW623jet_u.Scale(hW623jet.Integral()/hW623jet_u.Integral())
    hW623jet_d.Scale(hW623jet.Integral()/hW623jet_d.Integral())

    hW624jet=fW.Get("et_vbf_DL1_0p2to0p4/W")
    hW624jet_u=fW_jfru.Get("et_vbf_DL1_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVUp")
    hW624jet_d=fW_jfrd.Get("et_vbf_DL1_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVDown")
    hW624jet_u.Scale(hW624jet.Integral()/hW624jet_u.Integral())
    hW624jet_d.Scale(hW624jet.Integral()/hW624jet_d.Integral())

    hW625jet=fW.Get("et_vbf_DL1_0p4to0p8/W")
    hW625jet_u=fW_jfru.Get("et_vbf_DL1_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVUp")
    hW625jet_d=fW_jfrd.Get("et_vbf_DL1_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVDown")
    hW625jet_u.Scale(hW625jet.Integral()/hW625jet_u.Integral())
    hW625jet_d.Scale(hW625jet.Integral()/hW625jet_d.Integral())

    hW627jet=fW.Get("et_vbf_DL1_0p8to1p0/W")
    hW627jet_u=fW_jfru.Get("et_vbf_DL1_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVUp")
    hW627jet_d=fW_jfrd.Get("et_vbf_DL1_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVDown")
    hW627jet_u.Scale(hW627jet.Integral()/hW627jet_u.Integral())
    hW627jet_d.Scale(hW627jet.Integral()/hW627jet_d.Integral())

    hW723jet=fW.Get("et_vbf_DL1Zg_0p0to0p2/W")
    hW723jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVUp")
    hW723jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p0to0p2/W_CMS_htt_jetToTauFake_13TeVDown")
    hW723jet_u.Scale(hW723jet.Integral()/hW723jet_u.Integral())
    hW723jet_d.Scale(hW723jet.Integral()/hW723jet_d.Integral())

    hW724jet=fW.Get("et_vbf_DL1Zg_0p2to0p4/W")
    hW724jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVUp")
    hW724jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p2to0p4/W_CMS_htt_jetToTauFake_13TeVDown")
    hW724jet_u.Scale(hW724jet.Integral()/hW724jet_u.Integral())
    hW724jet_d.Scale(hW724jet.Integral()/hW724jet_d.Integral())

    hW725jet=fW.Get("et_vbf_DL1Zg_0p4to0p8/W")
    hW725jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVUp")
    hW725jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p4to0p8/W_CMS_htt_jetToTauFake_13TeVDown")
    hW725jet_u.Scale(hW725jet.Integral()/hW725jet_u.Integral())
    hW725jet_d.Scale(hW725jet.Integral()/hW725jet_d.Integral())

    hW727jet=fW.Get("et_vbf_DL1Zg_0p8to1p0/W")
    hW727jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVUp")
    hW727jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p8to1p0/W_CMS_htt_jetToTauFake_13TeVDown")
    hW727jet_u.Scale(hW727jet.Integral()/hW727jet_u.Integral())
    hW727jet_d.Scale(hW727jet.Integral()/hW727jet_d.Integral())

    hW3jet=fW.Get("et_antiiso_0jet_cr/W")
    hW3jet_u=fW_jfru.Get("et_antiiso_0jet_cr/W_CMS_htt_jetToTauFake_13TeVUp")
    hW3jet_d=fW_jfrd.Get("et_antiiso_0jet_cr/W_CMS_htt_jetToTauFake_13TeVDown")
    hW3jet_u.Scale(hW3jet.Integral()/hW3jet_u.Integral())
    hW3jet_d.Scale(hW3jet.Integral()/hW3jet_d.Integral())

    hW4jet=fW.Get("et_antiiso_boosted_cr/W")
    hW4jet_u=fW_jfru.Get("et_antiiso_boosted_cr/W_CMS_htt_jetToTauFake_13TeVUp")
    hW4jet_d=fW_jfrd.Get("et_antiiso_boosted_cr/W_CMS_htt_jetToTauFake_13TeVDown")
    hW4jet_u.Scale(hW4jet.Integral()/hW4jet_u.Integral())
    hW4jet_d.Scale(hW4jet.Integral()/hW4jet_d.Integral())

    hW5jet=fW.Get("et_antiiso_vbf_cr/W")
    hW5jet_u=fW_jfru.Get("et_antiiso_vbf_cr/W_CMS_htt_jetToTauFake_13TeVUp")
    hW5jet_d=fW_jfrd.Get("et_antiiso_vbf_cr/W_CMS_htt_jetToTauFake_13TeVDown")
    hW5jet_u.Scale(hW5jet.Integral()/hW5jet_u.Integral())
    hW5jet_d.Scale(hW5jet.Integral()/hW5jet_d.Integral())

    fout_jfru.cd()
    dir0OS=fout_jfru.mkdir("et_0jet")
    dir0OS.cd()
    hW0jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW0jet_u.Write()
    hW0jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW0jet_d.Write()
    dir1OS=fout_jfru.mkdir("et_boosted")
    dir1OS.cd()
    hW1jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW1jet_u.Write()
    hW1jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW1jet_d.Write()
    dir2OS=fout_jfru.mkdir("et_vbf")
    dir2OS.cd()
    hW3jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW3jet_u.Write()
    hW3jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW3jet_d.Write()

    dir23OS=fout_jfru.mkdir("et_vbf_D0_0p0to0p2")
    dir23OS.cd()
    hW23jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW23jet_u.Write()
    hW23jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW23jet_d.Write()

    dir24OS=fout_jfru.mkdir("et_vbf_D0_0p2to0p4")
    dir24OS.cd()
    hW24jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW24jet_u.Write()
    hW24jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW24jet_d.Write()

    dir25OS=fout_jfru.mkdir("et_vbf_D0_0p4to0p8")
    dir25OS.cd()
    hW25jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW25jet_u.Write()
    hW25jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW25jet_d.Write()

    dir27OS=fout_jfru.mkdir("et_vbf_D0_0p8to1p0")
    dir27OS.cd()
    hW27jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW27jet_u.Write()
    hW27jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW27jet_d.Write()
    ###ggH start
    dir23OSggH=fout_jfru.mkdir("et_vbf_D0_0p0to0p2_ggH")
    dir23OSggH.cd()
    hW33jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW23jet_uggH.Write()
    hW23jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW23jet_dggH.Write()

    dir24OSggH=fout_jfru.mkdir("et_vbf_D0_0p2to0p4_ggH")
    dir24OSggH.cd()
    hW24jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW24jet_uggH.Write()
    hW24jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW24jet_dggH.Write()

    dir25OSggH=fout_jfru.mkdir("et_vbf_D0_0p4to0p8_ggH")
    dir25OSggH.cd()
    hW25jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW25jet_uggH.Write()
    hW25jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW25jet_dggH.Write()

    dir27OSggH=fout_jfru.mkdir("et_vbf_D0_0p8to1p0_ggH")
    dir27OSggH.cd()
    hW27jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW27jet_uggH.Write()
    hW27jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW27jet_dggH.Write()

#########

    dir33OSggH=fout_jfru.mkdir("et_vbf_D0_0p0to0p2_DCPm_ggH")
    dir33OSggH.cd()
    hW33jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW33jet_uggH.Write()
    hW33jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW33jet_dggH.Write()

    dir34OSggH=fout_jfru.mkdir("et_vbf_0p2to0p4_DCPm_ggH")
    dir34OSggH.cd()
    hW34jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW34jet_uggH.Write()
    hW34jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW34jet_dggH.Write()

    dir35OSggH=fout_jfru.mkdir("et_vbf_D0_0p4to0p8_DCPm_ggH")
    dir35OSggH.cd()
    hW35jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW35jet_uggH.Write()
    hW35jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW35jet_dggH.Write()

    dir37OSggH=fout_jfru.mkdir("et_vbf_0p8to1p0_DCPm_ggH")
    dir37OSggH.cd()
    hW37jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW37jet_uggH.Write()
    hW37jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW37jet_dggH.Write()

    dir43OSggH=fout_jfru.mkdir("et_vbf_D0_Pito1p5m_ggH")
    dir43OSggH.cd()
    hW43jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW43jet_uggH.Write()
    hW43jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW43jet_dggH.Write()

    dir44OSggH=fout_jfru.mkdir("et_vbf_D0_1p5to0_ggH")
    dir44OSggH.cd()
    hW44jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW44jet_uggH.Write()
    hW44jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW44jet_dggH.Write()

    dir45OSggH=fout_jfru.mkdir("et_vbf_D0_0to1p5p_ggH")
    dir45OSggH.cd()
    hW45jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW45jet_uggH.Write()
    hW45jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW45jet_dggH.Write()

    dir47OSggH=fout_jfru.mkdir("et_vbf_D0_1p5toPi_ggH")
    dir47OSggH.cd()
    hW47jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW47jet_uggH.Write()
    hW47jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW47jet_dggH.Write()


    dir53OSggH=fout_jfru.mkdir("et_vbf_Pito1p6m_ggH")
    dir53OSggH.cd()
    hW53jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW53jet_uggH.Write()
    hW53jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW53jet_dggH.Write()

    dir54OSggH=fout_jfru.mkdir("et_vbf_1p6to0_ggH")
    dir54OSggH.cd()
    hW54jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW54jet_uggH.Write()
    hW54jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW54jet_dggH.Write()

    dir55OSggH=fout_jfru.mkdir("et_vbf_0to1p6p_ggH")
    dir55OSggH.cd()
    hW55jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW55jet_uggH.Write()
    hW55jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW55jet_dggH.Write()

    dir57OSggH=fout_jfru.mkdir("et_vbf_1p6toPi_ggH")
    dir57OSggH.cd()
    hW57jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW57jet_uggH.Write()
    hW57jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW57jet_dggH.Write()


    dir63OSggH=fout_jfru.mkdir("et_vbf_Pito1p6m_ggH_Uns")
    dir63OSggH.cd()
    hW63jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW63jet_uggH.Write()
    hW63jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW63jet_dggH.Write()

    dir64OSggH=fout_jfru.mkdir("et_vbf_1p6to0_ggH_Uns")
    dir64OSggH.cd()
    hW64jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW64jet_uggH.Write()
    hW64jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW64jet_dggH.Write()

    dir65OSggH=fout_jfru.mkdir("et_vbf_0to1p6p_ggH_Uns")
    dir65OSggH.cd()
    hW65jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW65jet_uggH.Write()
    hW65jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW65jet_dggH.Write()

    dir67OSggH=fout_jfru.mkdir("et_vbf_1p6toPi_ggH_Uns")
    dir67OSggH.cd()
    hW67jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW67jet_uggH.Write()
    hW67jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW67jet_dggH.Write()


    dir73OSggH=fout_jfru.mkdir("et_vbf_dPhia_ggH")
    dir73OSggH.cd()
    hW73jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW73jet_uggH.Write()
    hW73jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW73jet_dggH.Write()

    dir74OSggH=fout_jfru.mkdir("et_vbf_dPhib_ggH")
    dir74OSggH.cd()
    hW74jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW74jet_uggH.Write()
    hW74jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW74jet_dggH.Write()

    dir75OSggH=fout_jfru.mkdir("et_vbf_dPhic_ggH")
    dir75OSggH.cd()
    hW75jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW75jet_uggH.Write()
    hW75jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW75jet_dggH.Write()

    dir77OSggH=fout_jfru.mkdir("et_vbf_dPhid_ggH")
    dir77OSggH.cd()
    hW77jet_uggH.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW77jet_uggH.Write()
    hW77jet_dggH.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW77jet_dggH.Write()


    #ggH enddd


    dir523OS=fout_jfru.mkdir("et_vbf_D0hplus_0p0to0p2")
    dir523OS.cd()
    hW523jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW523jet_u.Write()
    hW523jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW523jet_d.Write()

    dir524OS=fout_jfru.mkdir("et_vbf_D0hplus_0p2to0p4")
    dir524OS.cd()
    hW524jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW524jet_u.Write()
    hW524jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW524jet_d.Write()

    dir525OS=fout_jfru.mkdir("et_vbf_D0hplus_0p4to0p8")
    dir525OS.cd()
    hW525jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW525jet_u.Write()
    hW525jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW525jet_d.Write()

    dir527OS=fout_jfru.mkdir("et_vbf_D0hplus_0p8to1p0")
    dir527OS.cd()
    hW527jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW527jet_u.Write()
    hW527jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW527jet_d.Write()

    dir623OS=fout_jfru.mkdir("et_vbf_DL1_0p0to0p2")
    dir623OS.cd()
    hW623jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW623jet_u.Write()
    hW623jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW623jet_d.Write()

    dir624OS=fout_jfru.mkdir("et_vbf_DL1_0p2to0p4")
    dir624OS.cd()
    hW624jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW624jet_u.Write()
    hW624jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW624jet_d.Write()

    dir625OS=fout_jfru.mkdir("et_vbf_DL1_0p4to0p8")
    dir625OS.cd()
    hW625jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW625jet_u.Write()
    hW625jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW625jet_d.Write()

    dir627OS=fout_jfru.mkdir("et_vbf_DL1_0p8to1p0")
    dir627OS.cd()
    hW627jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW627jet_u.Write()
    hW627jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW627jet_d.Write()

    dir723OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p0to0p2")
    dir723OS.cd()
    hW723jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW723jet_u.Write()
    hW723jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW723jet_d.Write()

    dir724OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p2to0p4")
    dir724OS.cd()
    hW724jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW724jet_u.Write()
    hW724jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW724jet_d.Write()

    dir725OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p4to0p8")
    dir725OS.cd()
    hW725jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW725jet_u.Write()
    hW725jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW725jet_d.Write()

    dir727OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p8to1p0")
    dir727OS.cd()
    hW727jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW727jet_u.Write()
    hW727jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW727jet_d.Write()


    dir3OS=fout_jfru.mkdir("et_antiiso_0jet_cr")
    dir3OS.cd()
    hW3jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW3jet_u.Write()
    hW3jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW3jet_d.Write()
    dir4OS=fout_jfru.mkdir("et_antiiso_boosted_cr")
    dir4OS.cd()
    hW4jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW4jet_u.Write()
    hW4jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW4jet_d.Write()
    dir5OS=fout_jfru.mkdir("et_antiiso_vbf_cr")
    dir5OS.cd()
    hW5jet_u.SetName("W_CMS_htt_jetToTauFake_13TeVUp")
    hW5jet_u.Write()
    hW5jet_d.SetName("W_CMS_htt_jetToTauFake_13TeVDown")
    hW5jet_d.Write()


