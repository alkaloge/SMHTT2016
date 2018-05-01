if __name__ == "__main__":

    import ROOT
    import argparse

    fW=ROOT.TFile("files_nominal/QCD.root","r")
    fW_jfru=ROOT.TFile("files_nominal/QCD_wup.root","r")
    fW_jfrd=ROOT.TFile("files_nominal/QCD_wdown.root","r")
    fout_jfru=ROOT.TFile("files_nominal/QCD_wup_norm.root","recreate")
    fout_jfrd=ROOT.TFile("files_nominal/QCD_wdown_norm.root","recreate")

    hW0jet=fW.Get("et_0jet/QCD")
    hW0jet_u=fW_jfru.Get("et_0jet/QCD_WSFUncert_et_0jet_13TeVUp")
    hW0jet_d=fW_jfrd.Get("et_0jet/QCD_WSFUncert_et_0jet_13TeVDown")
    hW0jet_u.Scale(hW0jet.Integral()/hW0jet_u.Integral())
    hW0jet_d.Scale(hW0jet.Integral()/hW0jet_d.Integral())

    hW1jet=fW.Get("et_boosted/QCD")
    hW1jet_u=fW_jfru.Get("et_boosted/QCD_WSFUncert_et_boosted_13TeVUp")
    hW1jet_d=fW_jfrd.Get("et_boosted/QCD_WSFUncert_et_boosted_13TeVDown")
    hW1jet_u.Scale(hW1jet.Integral()/hW1jet_u.Integral())
    hW1jet_d.Scale(hW1jet.Integral()/hW1jet_d.Integral())

    hW2jet=fW.Get("et_vbf/QCD")
    hW2jet_u=fW_jfru.Get("et_vbf/QCD_WSFUncert_et_vbf_13TeVUp")
    hW2jet_d=fW_jfrd.Get("et_vbf/QCD_WSFUncert_et_vbf_13TeVDown")
    hW2jet_u.Scale(hW2jet.Integral()/hW2jet_u.Integral())
    hW2jet_d.Scale(hW2jet.Integral()/hW2jet_d.Integral())

    hW3jet=fW.Get("et_vbf_D0_0p0to0p2/QCD")
    hW3jet_u=fW_jfru.Get("et_vbf_D0_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVUp")
    hW3jet_d=fW_jfrd.Get("et_vbf_D0_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVDown")
    hW3jet_u.Scale(hW3jet.Integral()/hW3jet_u.Integral())
    hW3jet_d.Scale(hW3jet.Integral()/hW3jet_d.Integral())

    hW4jet=fW.Get("et_vbf_D0_0p2to0p4/QCD")
    hW4jet_u=fW_jfru.Get("et_vbf_D0_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVUp")
    hW4jet_d=fW_jfrd.Get("et_vbf_D0_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVDown")
    hW4jet_u.Scale(hW4jet.Integral()/hW4jet_u.Integral())
    hW4jet_d.Scale(hW4jet.Integral()/hW4jet_d.Integral())

    hW5jet=fW.Get("et_vbf_D0_0p4to0p8/QCD")
    hW5jet_u=fW_jfru.Get("et_vbf_D0_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVUp")
    hW5jet_d=fW_jfrd.Get("et_vbf_D0_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVDown")
    hW5jet_u.Scale((0.0001+hW5jet.Integral())/(0.0001+hW5jet_u.Integral()))
    hW5jet_d.Scale((0.0001+hW5jet.Integral())/(0.0001+hW5jet_d.Integral()))

    hW7jet=fW.Get("et_vbf_D0_0p8to1p0/QCD")
    hW7jet_u=fW_jfru.Get("et_vbf_D0_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVUp")
    hW7jet_d=fW_jfrd.Get("et_vbf_D0_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVDown")
    hW7jet_u.Scale(hW7jet.Integral()/hW7jet_u.Integral())
    hW7jet_d.Scale(hW7jet.Integral()/hW7jet_d.Integral())
    ########## ggH start
    hW3jetggH=fW.Get("et_vbf_D0_0p0to0p2_ggH/QCD")
    hW3jet_uggH=fW_jfru.Get("et_vbf_D0_0p0to0p2_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW3jet_dggH=fW_jfrd.Get("et_vbf_D0_0p0to0p2_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW3jet_uggH.Scale(hW3jetggH.Integral()/hW3jet_uggH.Integral())
    hW3jet_dggH.Scale(hW3jetggH.Integral()/hW3jet_dggH.Integral())

    hW4jetggH=fW.Get("et_vbf_D0_0p2to0p4_ggH/QCD")
    hW4jet_uggH=fW_jfru.Get("et_vbf_D0_0p2to0p4_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW4jet_dggH=fW_jfrd.Get("et_vbf_D0_0p2to0p4_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW4jet_uggH.Scale(hW4jetggH.Integral()/hW4jet_uggH.Integral())
    hW4jet_dggH.Scale(hW4jetggH.Integral()/hW4jet_dggH.Integral())

    hW5jetggH=fW.Get("et_vbf_D0_0p4to0p8_ggH/QCD")
    hW5jet_uggH=fW_jfru.Get("et_vbf_D0_0p4to0p8_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW5jet_dggH=fW_jfrd.Get("et_vbf_D0_0p4to0p8_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW5jet_uggH.Scale((0.0001+hW5jetggH.Integral())/(0.0001+hW5jet_uggH.Integral()))
    hW5jet_dggH.Scale((0.0001+hW5jetggH.Integral())/(0.0001+hW5jet_dggH.Integral()))

    hW7jetggH=fW.Get("et_vbf_D0_0p8to1p0_ggH/QCD")
    hW7jet_uggH=fW_jfru.Get("et_vbf_D0_0p8to1p0_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW7jet_dggH=fW_jfrd.Get("et_vbf_D0_0p8to1p0_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW7jet_u.Scale(hW7jetggH.Integral()/hW7jet_uggH.Integral())
    hW7jet_d.Scale(hW7jetggH.Integral()/hW7jet_dggH.Integral())

    hW33jetggH=fW.Get("et_vbf_D0_0p0to0p2_DCPm_ggH/QCD")
    hW33jet_uggH=fW_jfru.Get("et_vbf_D0_0p0to0p2_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW33jet_dggH=fW_jfrd.Get("et_vbf_D0_0p0to0p2_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW33jet_uggH.Scale(hW33jetggH.Integral()/hW33jet_uggH.Integral())
    hW33jet_dggH.Scale(hW33jetggH.Integral()/hW33jet_dggH.Integral())

    hW34jetggH=fW.Get("et_vbf_D0_0p2to0p4_DCPm_ggH/QCD")
    hW34jet_uggH=fW_jfru.Get("et_vbf_D0_0p2to0p4_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW34jet_dggH=fW_jfrd.Get("et_vbf_D0_0p2to0p4_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW34jet_uggH.Scale(hW34jetggH.Integral()/hW34jet_uggH.Integral())
    hW34jet_dggH.Scale(hW34jetggH.Integral()/hW34jet_dggH.Integral())

    hW35jetggH=fW.Get("et_vbf_D0_0p4to0p8_DCPm_ggH/QCD")
    hW35jet_uggH=fW_jfru.Get("et_vbf_D0_0p4to0p8_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW35jet_dggH=fW_jfrd.Get("et_vbf_D0_0p4to0p8_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW35jet_uggH.Scale(hW35jetggH.Integral()/hW35jet_uggH.Integral())
    hW35jet_dggH.Scale(hW35jetggH.Integral()/hW35jet_dggH.Integral())

    hW37jetggH=fW.Get("et_vbf_D0_0p8to1p0_DCPm_ggH/QCD")
    hW37jet_uggH=fW_jfru.Get("et_vbf_D0_0p8to1p0_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW37jet_dggH=fW_jfrd.Get("et_vbf_D0_0p8to1p0_DCPm_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW37jet_uggH.Scale(hW37jetggH.Integral()/hW37jet_uggH.Integral())
    hW37jet_dggH.Scale(hW37jetggH.Integral()/hW37jet_dggH.Integral())

    hW43jetggH=fW.Get("et_vbf_D0_Pito1p5m_ggH/QCD")
    hW43jet_uggH=fW_jfru.Get("et_vbf_D0_Pito1p5m_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW43jet_dggH=fW_jfrd.Get("et_vbf_D0_Pito1p5m_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW43jet_uggH.Scale(hW43jetggH.Integral()/hW43jet_uggH.Integral())
    hW43jet_dggH.Scale(hW43jetggH.Integral()/hW43jet_dggH.Integral())

    hW44jetggH=fW.Get("et_vbf_D0_1p5to0_ggH/QCD")
    hW44jet_uggH=fW_jfru.Get("et_vbf_D0_1p5to0_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW44jet_dggH=fW_jfrd.Get("et_vbf_D0_1p5to0_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW44jet_uggH.Scale(hW44jetggH.Integral()/hW44jet_uggH.Integral())
    hW44jet_dggH.Scale(hW44jetggH.Integral()/hW44jet_dggH.Integral())


    hW45jetggH=fW.Get("et_vbf_D0_Pito1p5m_ggH/QCD")
    hW45jet_uggH=fW_jfru.Get("et_vbf_D0_Pito1p5m_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW45jet_dggH=fW_jfrd.Get("et_vbf_D0_Pito1p5m_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW45jet_uggH.Scale(hW45jetggH.Integral()/hW45jet_uggH.Integral())
    hW45jet_dggH.Scale(hW45jetggH.Integral()/hW45jet_dggH.Integral())

    hW47jetggH=fW.Get("et_vbf_D0_1p5toPi_ggH/QCD")
    hW47jet_uggH=fW_jfru.Get("et_vbf_D0_1p5toPi_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW47jet_dggH=fW_jfrd.Get("et_vbf_D0_1p5toPi_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW47jet_uggH.Scale(hW47jetggH.Integral()/hW47jet_uggH.Integral())
    hW47jet_dggH.Scale(hW47jetggH.Integral()/hW47jet_dggH.Integral())


    hW53jetggH=fW.Get("et_vbf_Pito1p6m_ggH/QCD")
    hW53jet_uggH=fW_jfru.Get("et_vbf_Pito1p6m_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW53jet_dggH=fW_jfrd.Get("et_vbf_Pito1p6m_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW53jet_uggH.Scale(hW53jetggH.Integral()/hW53jet_uggH.Integral())
    hW53jet_dggH.Scale(hW53jetggH.Integral()/hW53jet_dggH.Integral())

    hW54jetggH=fW.Get("et_vbf_1p6to0_ggH/QCD")
    hW54jet_uggH=fW_jfru.Get("et_vbf_1p6to0_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW54jet_dggH=fW_jfrd.Get("et_vbf_1p6to0_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW54jet_uggH.Scale(hW54jetggH.Integral()/hW54jet_uggH.Integral())
    hW54jet_dggH.Scale(hW54jetggH.Integral()/hW54jet_dggH.Integral())


    hW55jetggH=fW.Get("et_vbf_0to1p6p_ggH/QCD")
    hW55jet_uggH=fW_jfru.Get("et_vbf_0to1p6p_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW55jet_dggH=fW_jfrd.Get("et_vbf_0to1p6p_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW55jet_uggH.Scale(hW55jetggH.Integral()/hW55jet_uggH.Integral())
    hW55jet_dggH.Scale(hW55jetggH.Integral()/hW55jet_dggH.Integral())

    hW57jetggH=fW.Get("et_vbf_1p6toPi_ggH/QCD")
    hW57jet_uggH=fW_jfru.Get("et_vbf_1p6toPi_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW57jet_dggH=fW_jfrd.Get("et_vbf_1p6toPi_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW57jet_uggH.Scale(hW57jetggH.Integral()/hW57jet_uggH.Integral())
    hW57jet_dggH.Scale(hW57jetggH.Integral()/hW57jet_dggH.Integral())


    hW63jetggH=fW.Get("et_vbf_Pito1p6m_ggH_Uns/QCD")
    hW63jet_uggH=fW_jfru.Get("et_vbf_Pito1p6m_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVUp")
    hW63jet_dggH=fW_jfrd.Get("et_vbf_Pito1p6m_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVDown")
    hW63jet_uggH.Scale(hW63jetggH.Integral()/hW63jet_uggH.Integral())
    hW63jet_dggH.Scale(hW63jetggH.Integral()/hW63jet_dggH.Integral())


    hW64jetggH=fW.Get("et_vbf_1p6to0_ggH_Uns/QCD")
    hW64jet_uggH=fW_jfru.Get("et_vbf_1p6to0_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVUp")
    hW64jet_dggH=fW_jfrd.Get("et_vbf_1p6to0_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVDown")
    hW64jet_uggH.Scale(hW63jetggH.Integral()/hW64jet_uggH.Integral())
    hW64jet_dggH.Scale(hW63jetggH.Integral()/hW64jet_dggH.Integral())


    hW65jetggH=fW.Get("et_vbf_0to1p6p_ggH_Uns/QCD")
    hW65jet_uggH=fW_jfru.Get("et_vbf_0to1p6p_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVUp")
    hW65jet_dggH=fW_jfrd.Get("et_vbf_0to1p6p_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVDown")
    hW65jet_uggH.Scale(hW63jetggH.Integral()/hW65jet_uggH.Integral())
    hW65jet_dggH.Scale(hW63jetggH.Integral()/hW65jet_dggH.Integral())


    hW67jetggH=fW.Get("et_vbf_1p6toPi_ggH_Uns/QCD")
    hW67jet_uggH=fW_jfru.Get("et_vbf_1p6toPi_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVUp")
    hW67jet_dggH=fW_jfrd.Get("et_vbf_1p6toPi_ggH_Uns/QCD_WSFUncert_et_vbf_13TeVDown")
    hW67jet_uggH.Scale(hW63jetggH.Integral()/hW67jet_uggH.Integral())
    hW67jet_dggH.Scale(hW63jetggH.Integral()/hW67jet_dggH.Integral())


    hW73jetggH=fW.Get("et_vbf_dPhia_ggH/QCD")
    hW73jet_uggH=fW_jfru.Get("et_vbf_dPhia_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW73jet_dggH=fW_jfrd.Get("et_vbf_dPhia_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW73jet_uggH.Scale(hW73jetggH.Integral()/hW73jet_uggH.Integral())
    hW73jet_dggH.Scale(hW73jetggH.Integral()/hW73jet_dggH.Integral())


    hW74jetggH=fW.Get("et_vbf_dPhib_ggH/QCD")
    hW74jet_uggH=fW_jfru.Get("et_vbf_dPhib_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW74jet_dggH=fW_jfrd.Get("et_vbf_dPhib_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW74jet_uggH.Scale(hW73jetggH.Integral()/hW74jet_uggH.Integral())
    hW74jet_dggH.Scale(hW73jetggH.Integral()/hW74jet_dggH.Integral())


    hW75jetggH=fW.Get("et_vbf_dPhic_ggH/QCD")
    hW75jet_uggH=fW_jfru.Get("et_vbf_dPhic_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW75jet_dggH=fW_jfrd.Get("et_vbf_dPhic_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW75jet_uggH.Scale(hW73jetggH.Integral()/hW75jet_uggH.Integral())
    hW75jet_dggH.Scale(hW73jetggH.Integral()/hW75jet_dggH.Integral())


    hW77jetggH=fW.Get("et_vbf_dPhid_ggH/QCD")
    hW77jet_uggH=fW_jfru.Get("et_vbf_dPhid_ggH/QCD_WSFUncert_et_vbf_13TeVUp")
    hW77jet_dggH=fW_jfrd.Get("et_vbf_dPhid_ggH/QCD_WSFUncert_et_vbf_13TeVDown")
    hW77jet_uggH.Scale(hW73jetggH.Integral()/hW77jet_uggH.Integral())
    hW77jet_dggH.Scale(hW73jetggH.Integral()/hW77jet_dggH.Integral())



    ########ggH block

    hW53jet=fW.Get("et_vbf_D0hplus_0p0to0p2/QCD")
    hW53jet_u=fW_jfru.Get("et_vbf_D0hplus_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVUp")
    hW53jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVDown")
    hW53jet_u.Scale(hW53jet.Integral()/hW53jet_u.Integral())
    hW53jet_d.Scale(hW53jet.Integral()/hW53jet_d.Integral())

    hW54jet=fW.Get("et_vbf_D0hplus_0p2to0p4/QCD")
    hW54jet_u=fW_jfru.Get("et_vbf_D0hplus_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVUp")
    hW54jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVDown")
    hW54jet_u.Scale(hW54jet.Integral()/hW54jet_u.Integral())
    hW54jet_d.Scale(hW54jet.Integral()/hW54jet_d.Integral())

    hW55jet=fW.Get("et_vbf_D0hplus_0p4to0p8/QCD")
    hW55jet_u=fW_jfru.Get("et_vbf_D0hplus_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVUp")
    hW55jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVDown")
    hW55jet_u.Scale((0.0001+hW55jet.Integral())/(0.0001+hW55jet_u.Integral()))
    hW55jet_d.Scale((0.0001+hW55jet.Integral())/(0.0001+hW55jet_d.Integral()))

    hW57jet=fW.Get("et_vbf_D0hplus_0p8to1p0/QCD")
    hW57jet_u=fW_jfru.Get("et_vbf_D0hplus_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVUp")
    hW57jet_d=fW_jfrd.Get("et_vbf_D0hplus_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVDown")
    hW57jet_u.Scale(hW57jet.Integral()/hW57jet_u.Integral())
    hW57jet_d.Scale(hW57jet.Integral()/hW57jet_d.Integral())

    hW63jet=fW.Get("et_vbf_DL1_0p0to0p2/QCD")
    hW63jet_u=fW_jfru.Get("et_vbf_DL1_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVUp")
    hW63jet_d=fW_jfrd.Get("et_vbf_DL1_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVDown")
    hW63jet_u.Scale(hW63jet.Integral()/hW63jet_u.Integral())
    hW63jet_d.Scale(hW63jet.Integral()/hW63jet_d.Integral())

    hW64jet=fW.Get("et_vbf_DL1_0p2to0p4/QCD")
    hW64jet_u=fW_jfru.Get("et_vbf_DL1_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVUp")
    hW64jet_d=fW_jfrd.Get("et_vbf_DL1_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVDown")
    hW64jet_u.Scale(hW64jet.Integral()/hW64jet_u.Integral())
    hW64jet_d.Scale(hW64jet.Integral()/hW64jet_d.Integral())

    hW65jet=fW.Get("et_vbf_DL1_0p4to0p8/QCD")
    hW65jet_u=fW_jfru.Get("et_vbf_DL1_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVUp")
    hW65jet_d=fW_jfrd.Get("et_vbf_DL1_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVDown")
    hW65jet_u.Scale((0.0001+hW65jet.Integral())/(0.0001+hW65jet_u.Integral()))
    hW65jet_d.Scale((0.0001+hW65jet.Integral())/(0.0001+hW65jet_d.Integral()))

    hW67jet=fW.Get("et_vbf_DL1_0p8to1p0/QCD")
    hW67jet_u=fW_jfru.Get("et_vbf_DL1_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVUp")
    hW67jet_d=fW_jfrd.Get("et_vbf_DL1_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVDown")
    hW67jet_u.Scale(hW67jet.Integral()/hW67jet_u.Integral())
    hW67jet_d.Scale(hW67jet.Integral()/hW67jet_d.Integral())

    hW73jet=fW.Get("et_vbf_DL1Zg_0p0to0p2/QCD")
    hW73jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVUp")
    hW73jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p0to0p2/QCD_WSFUncert_et_vbf_13TeVDown")
    hW73jet_u.Scale(hW73jet.Integral()/hW73jet_u.Integral())
    hW73jet_d.Scale(hW73jet.Integral()/hW73jet_d.Integral())

    hW74jet=fW.Get("et_vbf_DL1Zg_0p2to0p4/QCD")
    hW74jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVUp")
    hW74jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p2to0p4/QCD_WSFUncert_et_vbf_13TeVDown")
    hW74jet_u.Scale(hW74jet.Integral()/hW74jet_u.Integral())
    hW74jet_d.Scale(hW74jet.Integral()/hW74jet_d.Integral())

    hW75jet=fW.Get("et_vbf_DL1Zg_0p4to0p8/QCD")
    hW75jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVUp")
    hW75jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p4to0p8/QCD_WSFUncert_et_vbf_13TeVDown")
    hW75jet_u.Scale((0.0001+hW75jet.Integral())/(0.0001+hW75jet_u.Integral()))
    hW75jet_d.Scale((0.0001+hW75jet.Integral())/(0.0001+hW75jet_d.Integral()))

    hW77jet=fW.Get("et_vbf_DL1Zg_0p8to1p0/QCD")
    hW77jet_u=fW_jfru.Get("et_vbf_DL1Zg_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVUp")
    hW77jet_d=fW_jfrd.Get("et_vbf_DL1Zg_0p8to1p0/QCD_WSFUncert_et_vbf_13TeVDown")
    hW77jet_u.Scale(hW77jet.Integral()/hW77jet_u.Integral())
    hW77jet_d.Scale(hW77jet.Integral()/hW77jet_d.Integral())


    fout_jfru.cd()
    dir0OS=fout_jfru.mkdir("et_0jet")
    dir0OS.cd()
    hW0jet_u.SetName("QCD_WSFUncert_et_0jet_13TeVUp")
    hW0jet_u.Write()
    hW0jet_d.SetName("QCD_WSFUncert_et_0jet_13TeVDown")
    hW0jet_d.Write()
    dir1OS=fout_jfru.mkdir("et_boosted")
    dir1OS.cd()
    hW1jet_u.SetName("QCD_WSFUncert_et_boosted_13TeVUp")
    hW1jet_u.Write()
    hW1jet_d.SetName("QCD_WSFUncert_et_boosted_13TeVDown")
    hW1jet_d.Write()
    dir2OS=fout_jfru.mkdir("et_vbf")
    dir2OS.cd()
    hW2jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW2jet_u.Write()
    hW2jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW2jet_d.Write()
    dir3OS=fout_jfru.mkdir("et_vbf_D0_0p0to0p2")
    dir3OS.cd()
    hW3jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW3jet_u.Write()
    hW3jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW3jet_d.Write()
    dir4OS=fout_jfru.mkdir("et_vbf_D0_0p2to0p4")
    dir4OS.cd()
    hW4jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW4jet_u.Write()
    hW4jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW4jet_d.Write()
    dir5OS=fout_jfru.mkdir("et_vbf_D0_0p4to0p8")
    dir5OS.cd()
    hW5jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW5jet_u.Write()
    hW5jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW5jet_d.Write()
    dir7OS=fout_jfru.mkdir("et_vbf_D0_0p8to1p0")
    dir7OS.cd()
    hW7jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW7jet_u.Write()
    hW7jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW7jet_d.Write()
	
    #ggH block
    dir3OSggH=fout_jfru.mkdir("et_vbf_D0_0p0to0p2_ggH")
    dir3OSggH.cd()
    hW3jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW3jet_uggH.Write()
    hW3jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW3jet_dggH.Write()
    dir4OSggH=fout_jfru.mkdir("et_vbf_D0_0p2to0p4_ggH")
    dir4OSggH.cd()
    hW4jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW4jet_uggH.Write()
    hW4jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW4jet_dggH.Write()
    dir5OSggH=fout_jfru.mkdir("et_vbf_D0_0p4to0p8_ggH")
    dir5OSggH.cd()
    hW5jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW5jet_uggH.Write()
    hW5jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW5jet_dggH.Write()
    dir7OSggH=fout_jfru.mkdir("et_vbf_D0_0p8to1p0_ggH")
    dir7OSggH.cd()
    hW7jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW7jet_uggH.Write()
    hW7jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW7jet_dggH.Write()

    dir33OSggH=fout_jfru.mkdir("et_vbf_D0_0p0to0p2_DCPm_ggH")
    dir33OSggH.cd()
    hW33jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW33jet_uggH.Write()
    hW33jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW33jet_dggH.Write()

    dir34OSggH=fout_jfru.mkdir("et_vbf_0p2to0p4_DCPm_ggH")
    dir34OSggH.cd()
    hW34jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW34jet_uggH.Write()
    hW34jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW34jet_dggH.Write()

    dir35OSggH=fout_jfru.mkdir("et_vbf_D0_0p4to0p8_DCPm_ggH")
    dir35OSggH.cd()
    hW35jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW35jet_uggH.Write()
    hW35jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW35jet_dggH.Write()

    dir37OSggH=fout_jfru.mkdir("et_vbf_0p8to1p0_DCPm_ggH")
    dir37OSggH.cd()
    hW37jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW37jet_uggH.Write()
    hW37jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW37jet_dggH.Write()

    dir43OSggH=fout_jfru.mkdir("et_vbf_D0_Pito1p5m_ggH")
    dir43OSggH.cd()
    hW43jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW43jet_uggH.Write()
    hW43jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW43jet_dggH.Write()

    dir44OSggH=fout_jfru.mkdir("et_vbf_D0_1p5to0_ggH")
    dir44OSggH.cd()
    hW44jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW44jet_uggH.Write()
    hW44jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW44jet_dggH.Write()

    dir45OSggH=fout_jfru.mkdir("et_vbf_D0_0to1p5p_ggH")
    dir45OSggH.cd()
    hW45jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW45jet_uggH.Write()
    hW45jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW45jet_dggH.Write()

    dir47OSggH=fout_jfru.mkdir("et_vbf_D0_1p5toPi_ggH")
    dir47OSggH.cd()
    hW47jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW47jet_uggH.Write()
    hW47jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW47jet_dggH.Write()


    dir53OSggH=fout_jfru.mkdir("et_vbf_Pito1p6m_ggH")
    dir53OSggH.cd()
    hW53jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW53jet_uggH.Write()
    hW53jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW53jet_dggH.Write()

    dir54OSggH=fout_jfru.mkdir("et_vbf_1p6to0_ggH")
    dir54OSggH.cd()
    hW54jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW54jet_uggH.Write()
    hW54jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW54jet_dggH.Write()

    dir55OSggH=fout_jfru.mkdir("et_vbf_0to1p6p_ggH")
    dir55OSggH.cd()
    hW55jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW55jet_uggH.Write()
    hW55jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW55jet_dggH.Write()

    dir57OSggH=fout_jfru.mkdir("et_vbf_1p6toPi_ggH")
    dir57OSggH.cd()
    hW57jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW57jet_uggH.Write()
    hW57jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW57jet_dggH.Write()


    dir63OSggH=fout_jfru.mkdir("et_vbf_Pito1p6m_ggH_Uns")
    dir63OSggH.cd()
    hW63jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW63jet_uggH.Write()
    hW63jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW63jet_dggH.Write()

    dir64OSggH=fout_jfru.mkdir("et_vbf_1p6to0_ggH_Uns")
    dir64OSggH.cd()
    hW64jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW64jet_uggH.Write()
    hW64jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW64jet_dggH.Write()

    dir65OSggH=fout_jfru.mkdir("et_vbf_0to1p6p_ggH_Uns")
    dir65OSggH.cd()
    hW65jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW65jet_uggH.Write()
    hW65jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW65jet_dggH.Write()

    dir67OSggH=fout_jfru.mkdir("et_vbf_1p6toPi_ggH_Uns")
    dir67OSggH.cd()
    hW67jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW67jet_uggH.Write()
    hW67jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW67jet_dggH.Write()


    dir73OSggH=fout_jfru.mkdir("et_vbf_dPhia_ggH")
    dir73OSggH.cd()
    hW73jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW73jet_uggH.Write()
    hW73jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW73jet_dggH.Write()

    dir74OSggH=fout_jfru.mkdir("et_vbf_dPhib_ggH")
    dir74OSggH.cd()
    hW74jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW74jet_uggH.Write()
    hW74jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW74jet_dggH.Write()

    dir75OSggH=fout_jfru.mkdir("et_vbf_dPhic_ggH")
    dir75OSggH.cd()
    hW75jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW75jet_uggH.Write()
    hW75jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW75jet_dggH.Write()

    dir77OSggH=fout_jfru.mkdir("et_vbf_dPhid_ggH")
    dir77OSggH.cd()
    hW77jet_uggH.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW77jet_uggH.Write()
    hW77jet_dggH.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW77jet_dggH.Write()


    #ggH enddd



    dir53OS=fout_jfru.mkdir("et_vbf_D0hplus_0p0to0p2")
    dir53OS.cd()
    hW53jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW53jet_u.Write()
    hW53jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW53jet_d.Write()
    dir54OS=fout_jfru.mkdir("et_vbf_D0hplus_0p2to0p4")
    dir54OS.cd()
    hW54jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW54jet_u.Write()
    hW54jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW54jet_d.Write()
    dir55OS=fout_jfru.mkdir("et_vbf_D0hplus_0p4to0p8")
    dir55OS.cd()
    hW55jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW55jet_u.Write()
    hW55jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW55jet_d.Write()
    dir57OS=fout_jfru.mkdir("et_vbf_D0hplus_0p8to1p0")
    dir57OS.cd()
    hW57jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW57jet_u.Write()
    hW57jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW57jet_d.Write()

    dir63OS=fout_jfru.mkdir("et_vbf_DL1_0p0to0p2")
    dir63OS.cd()
    hW63jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW63jet_u.Write()
    hW63jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW63jet_d.Write()
    dir64OS=fout_jfru.mkdir("et_vbf_DL1_0p2to0p4")
    dir64OS.cd()
    hW64jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW64jet_u.Write()
    hW64jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW64jet_d.Write()
    dir65OS=fout_jfru.mkdir("et_vbf_DL1_0p4to0p8")
    dir65OS.cd()
    hW65jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW65jet_u.Write()
    hW65jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW65jet_d.Write()
    dir67OS=fout_jfru.mkdir("et_vbf_DL1_0p8to1p0")
    dir67OS.cd()
    hW67jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW67jet_u.Write()
    hW67jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW67jet_d.Write()

    dir73OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p0to0p2")
    dir73OS.cd()
    hW73jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW73jet_u.Write()
    hW73jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW73jet_d.Write()
    dir74OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p2to0p4")
    dir74OS.cd()
    hW74jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW74jet_u.Write()
    hW74jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW74jet_d.Write()
    dir75OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p4to0p8")
    dir75OS.cd()
    hW75jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW75jet_u.Write()
    hW75jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW75jet_d.Write()
    dir77OS=fout_jfru.mkdir("et_vbf_DL1Zg_0p8to1p0")
    dir77OS.cd()
    hW77jet_u.SetName("QCD_WSFUncert_et_vbf_13TeVUp")
    hW77jet_u.Write()
    hW77jet_d.SetName("QCD_WSFUncert_et_vbf_13TeVDown")
    hW77jet_d.Write()

