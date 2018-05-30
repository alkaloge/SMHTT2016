#!/usr/bin/env python
import ROOT
from ROOT import *
import re
from array import array

islog=1
unrollSV=1

file=ROOT.TFile("reweighted.root","r")
file1=ROOT.TFile("scaled_reweighted.root","recreate")


file.cd()
dirList = gDirectory.GetListOfKeys()

norm_VBF0M=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0M125").Integral()
norm_jhuVBF0M=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0M125").Integral()
SF_VBF0M=norm_VBF0M/norm_jhuVBF0M
norm_VBF0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0PHf05ph0125").Integral()
norm_jhuVBF0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()
SF_VBF0PHf05ph=norm_VBF0PHf05ph/norm_jhuVBF0PHf05ph
norm_VBF0Mf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0Mf05ph0125").Integral()
norm_jhuVBF0Mf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0Mf05ph0125").Integral()
SF_VBF0Mf05ph=norm_VBF0Mf05ph/norm_jhuVBF0Mf05ph
norm_VBF0L1f05ph=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0L1f05ph0125").Integral()
norm_jhuVBF0L1f05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0L1f05ph0125").Integral()
SF_VBF0L1f05ph=norm_VBF0L1f05ph/norm_jhuVBF0L1f05ph
norm_VBF0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0PHf05ph0125").Integral()
norm_jhuVBF0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0PHf05ph0125").Integral()
SF_VBF0PHf05ph=norm_VBF0PHf05ph/norm_jhuVBF0PHf05ph
norm_VBF0PH=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0PH125").Integral()
norm_jhuVBF0PH=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0PH125").Integral()
SF_VBF0PH=norm_VBF0PH/norm_jhuVBF0PH
norm_VBF0L1=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0L1125").Integral()
norm_jhuVBF0L1=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0L1125").Integral()
SF_VBF0L1=norm_VBF0L1/norm_jhuVBF0L1
norm_VBF0PH=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0PH125").Integral()
norm_jhuVBF0PH=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0PH125").Integral()
SF_VBF0PH=norm_VBF0PH/norm_jhuVBF0PH
norm_VBF0PM=file.Get("et_vbf_D0_0p0to0p2").Get("qqH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("qqH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("qqH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("qqH_htt_0PM125").Integral()
norm_jhuVBF0PM=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_qqH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_qqH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_qqH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_qqH_htt_0PM125").Integral()
SF_VBF0PM=norm_VBF0PM/norm_jhuVBF0PM
print norm_VBF0M,norm_jhuVBF0M,SF_VBF0M

norm_WH0M=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0M125").Integral()
norm_jhuWH0M=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0M125").Integral()
SF_WH0M=norm_WH0M/norm_jhuWH0M
norm_WH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0PHf05ph0125").Integral()
norm_jhuWH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0PHf05ph0125").Integral()
SF_WH0PHf05ph=norm_WH0PHf05ph/norm_jhuWH0PHf05ph
norm_WH0Mf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0Mf05ph0125").Integral()
norm_jhuWH0Mf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0Mf05ph0125").Integral()
SF_WH0Mf05ph=norm_WH0Mf05ph/norm_jhuWH0Mf05ph
norm_WH0L1f05ph=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0L1f05ph0125").Integral()
norm_jhuWH0L1f05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0L1f05ph0125").Integral()
SF_WH0L1f05ph=norm_WH0L1f05ph/norm_jhuWH0L1f05ph
norm_WH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0PHf05ph0125").Integral()
norm_jhuWH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0PHf05ph0125").Integral()
SF_WH0PHf05ph=norm_WH0PHf05ph/norm_jhuWH0PHf05ph
norm_WH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0PH125").Integral()
norm_jhuWH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0PH125").Integral()
SF_WH0PH=norm_WH0PH/norm_jhuWH0PH
norm_WH0L1=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0L1125").Integral()
norm_jhuWH0L1=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0L1125").Integral()
SF_WH0L1=norm_WH0L1/norm_jhuWH0L1
norm_WH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0PH125").Integral()
norm_jhuWH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0PH125").Integral()
SF_WH0PH=norm_WH0PH/norm_jhuWH0PH
norm_WH0PM=file.Get("et_vbf_D0_0p0to0p2").Get("WH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("WH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("WH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("WH_htt_0PM125").Integral()
norm_jhuWH0PM=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_WH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_WH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_WH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_WH_htt_0PM125").Integral()
SF_WH0PM=norm_WH0PM/norm_jhuWH0PM

norm_ZH0M=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0M125").Integral()
norm_jhuZH0M=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0M125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0M125").Integral()
SF_ZH0M=norm_ZH0M/norm_jhuZH0M
norm_ZH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0PHf05ph0125").Integral()
norm_jhuZH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()
SF_ZH0PHf05ph=norm_ZH0PHf05ph/norm_jhuZH0PHf05ph
norm_ZH0Mf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0Mf05ph0125").Integral()
norm_jhuZH0Mf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0Mf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0Mf05ph0125").Integral()
SF_ZH0Mf05ph=norm_ZH0Mf05ph/norm_jhuZH0Mf05ph
norm_ZH0L1f05ph=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0L1f05ph0125").Integral()
norm_jhuZH0L1f05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0L1f05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0L1f05ph0125").Integral()
SF_ZH0L1f05ph=norm_ZH0L1f05ph/norm_jhuZH0L1f05ph
norm_ZH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0PHf05ph0125").Integral()
norm_jhuZH0PHf05ph=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0PHf05ph0125").Integral()
SF_ZH0PHf05ph=norm_ZH0PHf05ph/norm_jhuZH0PHf05ph
norm_ZH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0PH125").Integral()
norm_jhuZH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0PH125").Integral()
SF_ZH0PH=norm_ZH0PH/norm_jhuZH0PH
norm_ZH0L1=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0L1125").Integral()
norm_jhuZH0L1=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0L1125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0L1125").Integral()
SF_ZH0L1=norm_ZH0L1/norm_jhuZH0L1
norm_ZH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0PH125").Integral()
norm_jhuZH0PH=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0PH125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0PH125").Integral()
SF_ZH0PH=norm_ZH0PH/norm_jhuZH0PH
norm_ZH0PM=file.Get("et_vbf_D0_0p0to0p2").Get("ZH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("ZH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("ZH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("ZH_htt_0PM125").Integral()
norm_jhuZH0PM=file.Get("et_vbf_D0_0p0to0p2").Get("reweighted_ZH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p2to0p4").Get("reweighted_ZH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p4to0p8").Get("reweighted_ZH_htt_0PM125").Integral()+file.Get("et_vbf_D0_0p8to1p0").Get("reweighted_ZH_htt_0PM125").Integral()
SF_ZH0PM=norm_ZH0PM/norm_jhuZH0PM


for k1 in dirList:
    h1 = k1.ReadObj()
    nom=k1.GetName()
    if "et_" in nom and "70" not in nom:
       print nom
       file1.mkdir(nom)
       h1.cd()
       dirList2 = gDirectory.GetListOfKeys()
       for k2 in dirList2:
          h2 = k2.ReadObj()
          if "reweighted_" in h2.GetName():
               h3=h2.Clone()
               file1.cd(nom)
               if "0M125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0M)
               if "0PM125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0PM)
               if "0PH125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0PH)
               if "0L1125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0L1)
               if "0L1Zg125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0M)
               if "0Mf05ph0125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0Mf05ph)
               if "0PHf05ph0125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0PHf05ph)
               if "0L1f05ph0125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0L1f05ph)
               if "0L1Zgf05ph0125" in h2.GetName() and "qqH" in h2.GetName():
                  h3.Scale(SF_VBF0M)

               if "0M125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0M)
               if "0PM125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0PM)
               if "0PH125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0PH)
               if "0L1125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0L1)
               if "0L1Zg125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0M)
               if "0Mf05ph0125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0Mf05ph)
               if "0PHf05ph0125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0PHf05ph)
               if "0L1f05ph0125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0L1f05ph)
               if "0L1Zgf05ph0125" in h2.GetName() and "WH" in h2.GetName():
                  h3.Scale(SF_WH0M)

               if "0M125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0M)
               if "0PM125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0PM)
               if "0PH125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0PH)
               if "0L1125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0L1)
               if "0L1Zg125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0M)
               if "0Mf05ph0125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0Mf05ph)
               if "0PHf05ph0125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0PHf05ph)
               if "0L1f05ph0125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0L1f05ph)
               if "0L1Zgf05ph0125" in h2.GetName() and "ZH" in h2.GetName():
                  h3.Scale(SF_ZH0M)

               h3.Write()


