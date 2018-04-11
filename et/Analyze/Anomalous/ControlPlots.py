#!/usr/bin/env python
import ROOT
import re
from array import array
import sys
import math
#from ROOT import *
from ROOT import TCanvas, TPad, TFile, TPaveText, TColor, TLine, TObject
from ROOT import gBenchmark, gStyle, gROOT, TStyle

def add_lumi():
    lowX=0.58
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.06)
    lumi.SetTextFont (   42 )
    lumi.AddText("2016, 35.9 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.21
    lowY=0.70
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.08)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.21
    lowY=0.63
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.06)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend():
        output = ROOT.TLegend(0.50, 0.53, 0.92, 0.85, "", "brNDC")
        #output = ROOT.TLegend(0.2, 0.1, 0.47, 0.65, "", "brNDC")
   	output.SetNColumns(2)
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        output.SetFillStyle(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output

ROOT.gStyle.SetFrameLineWidth(3)
ROOT.gStyle.SetLineWidth(3)
ROOT.gStyle.SetOptStat(0)

c=ROOT.TCanvas("canvas","",0,0,600,600)
c.cd()

file=ROOT.TFile("control_out.root","r")

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

categories=["OS_control"] 
#categories=["et_vbf"] 
ncat=1

name_="hmelaDCP_OS_boosted_"

#hmelaDCP_OS_boosted_
for i in range (0,ncat):
   Data=file.Get(categories[i]).Get(name_+"data_obs")
   QCD=file.Get(categories[i]).Get(name_+"qqH_htt125")
   W=file.Get(categories[i]).Get(name_+"W") 
   #QCD.Scale(0.000001)
   TT=file.Get(categories[i]).Get(name_+"TTT")
   TT.Add(file.Get(categories[i]).Get(name_+"TTJ"))
   VV=file.Get(categories[i]).Get(name_+"VV")
   DYB=file.Get(categories[i]).Get(name_+"ZL")
   DYB.Add(file.Get(categories[i]).Get(name_+"ZJ"))
   DYS=file.Get(categories[i]).Get(name_+"ZTT")#_CMS_htt_zmumuShape_VBF_13TeVDown")
   #DYS.Scale(0.93)
   DYS.Add(file.Get(categories[i]).Get(name_+"EWKZ"))
   qqH=file.Get(categories[i]).Get(name_+"qqH_htt125")
   ggh=file.Get(categories[i]).Get(name_+"ggH_htt125")
   vh=file.Get(categories[i]).Get(name_+"WH_htt125")
   vh.Add(file.Get(categories[i]).Get(name_+"ZH_htt125"))
   ps=file.Get(categories[i]).Get("qqH_htt_0M125")
   #ps=file.Get(categories[i]).Get(name_+"qqH_htt125")

   Data.GetXaxis().SetTitle("")
   Data.GetXaxis().SetTitleSize(0)
   Data.GetXaxis().SetNdivisions(505)
   Data.GetYaxis().SetLabelFont(42)
   Data.GetYaxis().SetLabelOffset(0.01)
   Data.GetYaxis().SetLabelSize(0.06)
   Data.GetYaxis().SetTitleSize(0.075)
   Data.GetYaxis().SetTitleOffset(1.04)
   Data.SetTitle("")
   Data.GetYaxis().SetTitle("Events/bin")

   QCD.SetFillColor(ROOT.TColor.GetColor("#ffccff"))
   VV.SetFillColor(ROOT.TColor.GetColor("#12cadd"))
   W.SetFillColor(ROOT.TColor.GetColor("#de5a6a"))
   TT.SetFillColor(ROOT.TColor.GetColor("#9999cc"))
   DYB.SetFillColor(ROOT.TColor.GetColor("#4496c8"))
   DYS.SetFillColor(ROOT.TColor.GetColor("#ffcc66"))
   ggh.SetLineColor(ROOT.TColor.GetColor("#811aff"))
   qqH.SetLineColor(2)
   vh.SetLineColor(3)
   ps.SetLineColor(4)
   ggh.SetLineWidth(4)
   qqH.SetLineWidth(4)
   vh.SetLineWidth(4)
   ps.SetLineWidth(4)

   Data.SetMarkerStyle(20)
   Data.SetMarkerSize(1)
   QCD.SetLineColor(1)
   W.SetLineColor(1)
   TT.SetLineColor(1)
   DYS.SetLineColor(1)
   DYB.SetLineColor(1)
   VV.SetLineColor(1)
   Data.SetLineColor(1)
   Data.SetLineWidth(2)

   errorBand=file.Get(categories[i]).Get(name_+"W").Clone()
   errorBand.Add(VV)
   errorBand.Add(QCD)
   errorBand.Add(DYB)
   errorBand.Add(DYS)
   errorBand.Add(TT)

   stack=ROOT.THStack("stack","stack")
   stack.Add(QCD)
   stack.Add(W)
   stack.Add(VV)
   stack.Add(TT)
   stack.Add(DYB)
   stack.Add(DYS)

   errorBand.SetMarkerSize(0)
   errorBand.SetFillColor(new_idx)
   errorBand.SetFillStyle(3001)
   errorBand.SetLineWidth(1)

   pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
   pad1.Draw()
   pad1.cd()
   pad1.SetFillColor(0)
   pad1.SetBorderMode(0)
   pad1.SetBorderSize(10)
   pad1.SetTickx(1)
   pad1.SetTicky(1)
   pad1.SetLeftMargin(0.18)
   pad1.SetRightMargin(0.05)
   pad1.SetTopMargin(0.122)
   pad1.SetBottomMargin(0.026)
   pad1.SetFrameFillStyle(0)
   pad1.SetFrameLineStyle(0)
   pad1.SetFrameLineWidth(3)
   pad1.SetFrameBorderMode(0)
   pad1.SetFrameBorderSize(10)

   Data.GetXaxis().SetLabelSize(0)
   Data.SetMaximum(Data.GetMaximum()*1.8)
   for k in range(1,Data.GetSize()-1):
        s=max(qqH.GetBinContent(k),ps.GetBinContent(k)*qqH.Integral()/ps.Integral())
        b=VV.GetBinContent(k)+DYS.GetBinContent(k)+DYB.GetBinContent(k)+W.GetBinContent(k)+TT.GetBinContent(k)+0.0000001
        if (b<0):
            b=0.000001
        #if (s/((b+0.09*b*0.09*b)**0.5) > 0.15):
        #    Data.SetBinContent(k,-1)
        #    Data.SetBinError(k,-1)
   Data.SetMinimum(0)
   Data.Draw("e")
   stack.Draw("histsame")
   errorBand.Draw("e2same")
   qqH.Scale(10)
   ggh.Scale(10)
   vh.Scale(10)
   ps.Scale(10)
   qqH.Draw("histsame")
   ggh.Draw("histsame")
   vh.Draw("histsame")
   ps.Draw("histsame")
   Data.Draw("esame")

   legende=make_legend()
   legende.AddEntry(Data,"Observed","elp")
   legende.AddEntry(DYS,"Z#rightarrow#tau_{#mu}#tau_{h}","f")
   legende.AddEntry(DYB,"DY others","f")
   legende.AddEntry(TT,"t#bar{t}+jets","f")
   legende.AddEntry(VV,"Diboson","f")
   legende.AddEntry(W,"Electroweak","f")
#   legende.AddEntry(QCD,"QCD multijet","f")
   legende.AddEntry(qqH,"qqH, SM(125) x 10","l")
   legende.AddEntry(ggh,"ggH, SM(125) x 10","l")
   legende.AddEntry(vh,"VH, SM(125) x 10","l")
   legende.AddEntry(ps,"qqH, BSM-M(125) x 10","l")
   legende.AddEntry(errorBand,"Uncertainty","f")
   legende.Draw()

   l1=add_lumi()
   l1.Draw("same")
   l2=add_CMS()
   l2.Draw("same")
   l3=add_Preliminary()
   l3.Draw("same")
 
   pad1.RedrawAxis()

   categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.43, 0.70+0.155, "NDC")
   categ.SetBorderSize(   0 )
   categ.SetFillStyle(    0 )
   categ.SetTextAlign(   12 )
   categ.SetTextSize ( 0.06 )
   categ.SetTextColor(    1 )
   categ.SetTextFont (   41 )
   if i==0 or i==1: 
    categ.AddText("VBF")
   elif i==2 or i==3 :
    categ.AddText("1-jet")
   elif i==4 or i==5 :
    categ.AddText("2-jet")
   categ.Draw("same")

   c.cd()
   pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
   pad2.SetTopMargin(0.05);
   pad2.SetBottomMargin(0.35);
   pad2.SetLeftMargin(0.18);
   pad2.SetRightMargin(0.05);
   pad2.SetTickx(1)
   pad2.SetTicky(1)
   pad2.SetFrameLineWidth(3)
   pad2.SetGridx()
   pad2.SetGridy()
   pad2.Draw()
   pad2.cd()
   h1=Data.Clone()
   h1.SetMaximum(1.5)#FIXME(1.5)
   h1.SetMinimum(0.5)#FIXME(0.5)
   h1.SetMarkerStyle(20)
   h3=errorBand.Clone()
   hwoE=errorBand.Clone()
   for iii in range (1,hwoE.GetSize()-2):
     hwoE.SetBinError(iii,0)
   h3.Sumw2()
   h1.Sumw2()
   h1.SetStats(0)
   h1.Divide(hwoE)
   h3.Divide(hwoE)
   #h1.GetXaxis().SetTitle("|#Delta#eta(j_{1},j_{2})|")
   #h1.GetXaxis().SetTitle("|#Delta#phi(j_{1},j_{2})|")
   #h1.GetXaxis().SetTitle("m_{jj} (GeV)")
   #h1.GetXaxis().SetTitle("D0hplus")
   #h1.GetXaxis().SetTitle("D0minus")
   #h1.GetXaxis().SetTitle("DCP")
   #h1.GetXaxis().SetTitle("DL1")
   #h1.GetXaxis().SetTitle("DL1Zg")
   #h1.GetXaxis().SetTitle("p_{T}(j_{1}) (GeV)")
   #h1.GetXaxis().SetTitle("p_{T}(j_{2}) (GeV)")
   title="TITLEHERE"
   if "jpt1" in name_ : title="P_{T}(J_{0}) (GeV)"
   if "jpt2" in name_ : title="P_{T}(J_{1}) (GeV)"
   if "eta1" in name_ : title="#eta(J_{0})"
   if "eta2" in name_ : title="#eta(J_{1})"
   if "phi1" in name_ : title="#Phi(J_{0}) (rad)"
   if "phi2" in name_ : title="#Phi(J_{1}) (rad)"
   if "mjj_" in name_ : title="M(jj) (GeV)"

   if "met_" in name_ : title="#it{p}_{T}^{miss} (GeV)"

   h1.GetXaxis().SetTitle(title)
   #h1.GetXaxis().SetTitle("m_{vis} (GeV)")
   #h1.GetXaxis().SetTitle("m_{#tau#tau} (GeV)")
   h1.GetXaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetTitle("Obs./Exp.")
   h1.GetXaxis().SetNdivisions(505)
   h1.GetYaxis().SetNdivisions(5)

   h1.GetXaxis().SetTitleSize(0.15)
   h1.GetYaxis().SetTitleSize(0.15)
   h1.GetYaxis().SetTitleOffset(0.56)
   h1.GetXaxis().SetTitleOffset(1.04)
   h1.GetXaxis().SetLabelSize(0.11)
   h1.GetYaxis().SetLabelSize(0.11)
   h1.GetXaxis().SetTitleFont(42)
   h1.GetYaxis().SetTitleFont(42)

   h1.Draw("ep")
   h3.Draw("e2same")

   c.cd()
   pad1.Draw()

   ROOT.gPad.RedrawAxis()

   c.Modified()
   c.SaveAs("new_control_et/hmelaDCP_OS_boosted.pdf")
   #c.SaveAs("new_control_et/hmelaDPhiUnsignedjj_OS_VBF.png")


